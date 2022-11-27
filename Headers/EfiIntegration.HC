//#include "/Efisource/Headers/Efi.HH";
//PassTrace;
public CApplicationPointers appPtrs;


// very basic char to wchar (probably alpha letters only)
U0 ToWChar(U8 * src, U16 *dst) {
  for (; *src != 0; src++, dst++) {
    *dst = *src(U16) & 0xFF;
  }
  dst++ ;
  *dst = 0;
}


/**
Efi methods expect the first 4 parameters in the registers RCX, RDX, R8, R9
they also expect 4 * U64 Bytes of space available in the callers local variable space

The U64 reg RCX p1 indicates to the compiler you want that variable in that register

This isn't really ment to be called directly create a spring board method and use that instead

*/
#exe{
  Option(OPTf_WARN_UNUSED_VAR, OFF); 
  Option(OPTf_WARN_DUP_TYPES, OFF);
}
U64 EfiCallWrapper(U64 reg RDX p2, U64 reg R8 p3, U64 reg R9 p4, U64 reg RCX this, U64 reg RBX dest) {
// Create 4 * U64 in the methods stack
//  AND  RSP, 0xFFFFFFFFFFFFFFF0 

  U64 reg RAX res = 0;
  U64 pad[4];
  
  XOR  RAX, RAX
  CALL RBX

  MOV  RSP, RBP
  return res;
}
#exe{Option(OPTf_WARN_DUP_TYPES, ON);}
#exe{Option(OPTf_WARN_UNUSED_VAR, ON);}

// calls U64 EfiCallWrapper(U64 p1, U64 p2, U64 p3, U64 this, U64 dest) {
/*
asm {
_EFI_SPRING_BOARD::
   MOV  RBX, &EfiCallWrapper
   JMP RBX
};
*/

//public _extern _EFI_SPRING_BOARD U64 EfiPrint(U16 * string, U64 b = 0, U64 c = 0, U64 this = efiSimpleTextOutputInterface, U64 function = efiSimpleTextOutputInterface->OutputString);

public U64 EfiPrint(U16 *wString) {
  return EfiCallWrapper(wString, 0, 0, appPtrs.efi->ConOut, appPtrs.efi->ConOut->OutputString);
}

U16 wchar[STR_LEN]; 


/**
Most things are passing relative pointers which is no good it needs full address pointers, Virtual pointers
*/
U8* FixPtr(U8 *ptr) {
  if (ptr > appPtrs.appPointer) {
    return ptr;
  } else {
    return ptr + appPtrs.appPointer;
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

  ToWChar(fmt, wchar + appPtrs.appPointer);

  EfiPrint(wchar + appPtrs.appPointer); 
}


U0 PutChars(U64 ch) {
  "%c", ch;
}

// This gets called by the initial ASM bootstrapper
#exe{Option(OPTf_WARN_HEADER_MISMATCH, OFF);}
U64 EfiEntry(U64 efiSystemTable, U64 imageHandle, U64 appPtr, U64 stackPtr) {

  if (!efiSystemTable) {
    return 0xBABB0020;
  }

  if (!imageHandle) {
    return 0xBABB0021;
  }

  if (!appPtr) {
    return 0xBABB0022;
  }

  appPtrs.efi = efiSystemTable;
  appPtrs.imageHandle = imageHandle;
  appPtrs.appPointer = appPtr;
  appPtrs.stackPointer = stackPtr; 

  return AppEntry();
}
#exe{Option(OPTf_WARN_HEADER_MISMATCH, ON);}
