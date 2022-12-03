#include "/Efisource/Headers/Efi.HH";
//PassTrace;
CApplicationPointers appPtrs;
CEfiSimpleTextOutputInterface *ConOut;// = appPtrs.efi->ConOut;
CEfiBootServices *BootServices; // appPtrs.efi->BootServices


// very basic char to wchar (probably alpha letters only)
U0 ToWChar(U8 * src, U16 *dst) {
  for (; *src != 0; src++, dst++) {
    *dst = *src(U16) & 0xFF;
  }
  dst++ ;
  *dst = 0;
}


/**
Efi methods expect the first 4 parameters in teh registers RCX, RDX, R8, R9
they also expec 4 * 8 Bytes of space available in the callers local variable space

The U64 reg RCX p1 indicates to teh compiler you want that variable in that register

This isn't really ment to be called directly usedefine spring board method and use that instead

*/
#exe{
  Option(OPTf_WARN_UNUSED_VAR, OFF); 
  Option(OPTf_WARN_DUP_TYPES, OFF);
}

U64 EfiCallWrapper(U64 reg RDX p2, U64 reg R8 p3, U64 reg R9 p4, U64 reg RCX this, U64 reg RBX dest) {
// Create 4 * U64 in the methods stack
//  U64 reg RAX res = 0;
  U64 pad[4];
  
  XOR  RAX, RAX
  CALL RBX

  MOV  RSP, RBP
//  return res;
}
#exe{Option(OPTf_WARN_DUP_TYPES, ON);}
#exe{Option(OPTf_WARN_UNUSED_VAR, ON);}


public U64 EfiPrint(U16 *wString) {
  return EfiCallWrapper(wString, 0, 0, appPtrs.efi->ConOut, appPtrs.efi->ConOut->OutputString);
}

U16 wchar[STR_LEN]; 
U8* hexChars = "0123456789ABCDEF";


/**
Most things are passing relitive pointers with is no good it needs full address pointers
*/
U8* FixPtr(U8 *ptr) {
  if (ptr > APPLICATION_ADDRESS) {
    return ptr;
  } else {
    return ptr + APPLICATION_ADDRESS;
  }
}

U0 Print(U8 *fmt,...) {
//{//\dLK,"Print(\"\") Fmt Strings",A="FI:::/Doc/Print.DD"\d.  See \dLK,"StrPrintJoin",A="MN:StrPrintJoin"\d().
//Don't use this.  \dLK,"See Print() shortcut.",A="FF:::/Doc/HolyC.DD,DemoHolyC"\d

// @TODO - implement

/*  U8 *buf=StrPrintJoin(NULL,fmt,argc,argv);
  I64 len=StrLen(buf),i;
  for(i=0;i!=len;i++) {
    if (Bt(&(Fs->task_flags),TASKf_INPUT_FILTER_TASK))
      Msg(MSG_KEY_DOWN,buf[i],0,1<<JOBf_DONT_FILTER);
  }
  if(!Bt(&(Fs->display_flags),DISPLAYf_SILENT)&&!Bt(&(Fs->task_flags),TASKf_INPUT_FILTER_TASK))
    (*fp_puts2)(buf);
  Free(buf);
*/

  // only prints the str not parameters so dont do anything fancy


  fmt = FixPtr(fmt);
  U16 wChr = FixPtr(wchar);  

  ToWChar(fmt, wChr);

  EfiPrint(wChr);
}

U0 printHexU8(U8 key) {
  U16* wChr = FixPtr(wchar);  
  U8* hChar = FixPtr(hexChars);

  wChr[0] = hChar[(key >> 4) & 0xF] ;
  wChr[1] = hChar[key & 0xF];
  wChr[2] = 0;

  EfiPrint(wChr);
}

U0 printHexU16(U16 key) {
    printHexU8((key >> 8) & 0xFF);
    printHexU8( key & 0xFF);
}

U0 printHexU32(U32 key) {
    printHexU16((key >> 16) & 0xFFFF);
    printHexU16( key & 0xFFFF);
}

U0 printHexU64(U64 key) {
    printHexU32((key >> 32) & 0xFFFFFFFF);
    printHexU32(key & 0xFFFFFFFF);
}

U0 PutChars(U64 ch) {
  "%c", ch;
}
public extern U64 (*efi_print)(U16 *string, U64 p2 = 0, U64 p3 = 0, U8* this, U8* funct);
U64 (*efi_print)(U16 *string, U64 p2 = 0, U64 p3 = 0, U8* this = ConOut, U8* funct = ConOut->OutputString);


// This gets called by the initial ASM bootstrapper
#exe{Option(OPTf_WARN_HEADER_MISMATCH, OFF);}
U64 EfiEntry(U64 efiSystemTable, U64 imageHandle, U64 stackPtr) {

  if (!efiSystemTable) {
    return 0xBABB0020;
  }

  if (!imageHandle) {
    return 0xBABB0021;
  }

  // Set the application pointers
  appPtrs.efi = efiSystemTable;
  appPtrs.imageHandle = imageHandle;
//  appPtrs.appPointer = appPtr;
  appPtrs.stackPointer = stackPtr; 

  ConOut = appPtrs.efi->ConOut;
  BootServices = appPtrs.efi->BootServices;

//  MapEfiMethods;
  
  efi_print = (&EfiCallWrapper + APPLICATION_ADDRESS);

  return AppEntry();
}
#exe{Option(OPTf_WARN_HEADER_MISMATCH, ON);}



