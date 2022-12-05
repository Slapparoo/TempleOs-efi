#include "/Efisource/Headers/Efi.HH";


CApplicationPointers appPtrs;
CEfiSimpleTextOutputInterface *ConOut;// = appPtrs.efi->ConOut;
CEfiBootServices *BS; // appPtrs.efi->BootServices
CEfiRuntimeServices *RT; // appPtrs.efi->BootServices
CEfiSystemTable *ST;
CEfiLoadedImageProtocol LoadedImageProtocol_;
CEfiLoadedImageProtocol * LoadedImageProtocol;
CEfiGop * GOP;// = FixPtr(&gop);


CEfiGuid GraphicsGuid_ = EFI_GRAPHICS_OUTPUT_PROTOCOL_GUID;
CEfiGuid *GraphicsGuid;

CEfiGuid LoadedImageGuid_ = EFI_LOADED_IMAGE_PROTOCOL_GUID;
CEfiGuid *LoadedImageGuid;


U16 wchar[STR_LEN]; 
U16 * lWchar;
U8* hexChars = "0123456789ABCDEF";


// very basic char to wchar (probably alpha letters only)
U0 ToWChar(U8 * src, U16 *dst) {
  for (; *src != 0; src++, dst++) {
    *dst = (*src & 0xFF)(U16);
  }
//  dst++ ;
  *dst++ = 0;
}


/**
Efi methods expect the first 4 parameters in teh registers RCX, RDX, R8, R9
they also expec 4 * 8 Bytes of space available in the callers local variable space

The U64 reg RCX p1 indicates to teh compiler you want that variable in that register

This isn't really ment to be called directly usedefine spring board method and use that instead

*/
#exe{Option(OPTf_WARN_DUP_TYPES, OFF);}
#exe{Option(OPTf_WARN_UNUSED_VAR, OFF);}


U64 EfiCallWrapperOrdered(U64 reg RCX P1, U64 reg RDX p2, U64 reg R8 p3, U64 reg R9 p4, U64 reg RBX dest) {
// Create 4 * U64 in the methods stack
  U64 pad[4];

  // 16 byte align
  AND  RSP, 0xFFFFFFFFFFFFFFF0
  
  XOR  RAX, RAX
  CALL RBX

  MOV  RSP, RBP
}


U64 EfiCallWrapper(U64 reg RDX p2, U64 reg R8 p3, U64 reg R9 p4, U64 reg RCX this, U64 reg RBX dest) {
// Create 4 * U64 in the methods stack
  U64 pad[4];

  // 16 byte align
  AND  RSP, 0xFFFFFFFFFFFFFFF0
  
  XOR  RAX, RAX
  CALL RBX

  MOV  RSP, RBP
}

/*
U64 EfiCallWrapper(U64 reg RDX p2, U64 reg R8 p3, U64 reg R9 p4, U64 reg RCX this, U64 reg RBX dest) {
// Create 4 * U64 in the methods stack
  U64 pad[4];
  
  XOR  RAX, RAX
  CALL RBX

  MOV  RSP, RBP
}
*/

public U64 EfiPrint(U16 *wString) {
//  return EfiCallWrapper(wString, 0, 0, appPtrs.efi->ConOut, appPtrs.efi->ConOut->OutputString);
  return EfiCallWrapper(wString, 0, 0, ConOut, ConOut->OutputString);
}

#exe{Option(OPTf_WARN_DUP_TYPES, ON);}
#exe{Option(OPTf_WARN_UNUSED_VAR, ON);}


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

  ToWChar(fmt, lWchar);

  EfiPrint(lWchar);
}

U0 PrintGuid(CEfiGuid * guid) {
  U64 i = 0;

  "{"; printHexU32(guid->Data1); 
  "-";  printHexU16(guid->Data2); 
  "-"; printHexU16(guid->Data3); 
  "-"; 
  for (; i < 8; printHexU8(guid->Data4[i++]));
  "} "; 

  i = 0;
  for (; i < 16; printHexU8(guid(U8*)[i++]));

}

public U0 printHexU8(U8 key) {
  U8* hChar = FixPtr(hexChars);

  lWchar[0] = hChar[(key >> 4) & 0xF];
  lWchar[1] = hChar[key & 0xF];
  lWchar[2] = 0;

  EfiPrint(lWchar);
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
  ST = efiSystemTable;
  appPtrs.efi = ST;
  appPtrs.imageHandle = imageHandle;
  appPtrs.stackPointer = stackPtr; 

  ConOut = ST->ConOut;
  BS = ST->BootServices;
  RT = ST->RuntimeServices;

  lWchar = (APPLICATION_ADDRESS + &wchar(U8*)) & 0xFFFFFFFFFFFFFFF0; 

  LoadedImageProtocol = NULL;
  LoadedImageGuid = FixPtr(&LoadedImageGuid_);
  GraphicsGuid = FixPtr(&GraphicsGuid_);

  U64 res = efi_handle_protocol_t(imageHandle, LoadedImageGuid, FixPtr(&LoadedImageProtocol));
  if (res) {
    "Loaded Image Protocol error\r\n";
    return res;
  }

  res = efi_locate_protocol_t(GraphicsGuid, NULL, FixPtr(&GOP));
  if (res) {
    "Graphics Protocol\r\n";
    return res;
  }

  return AppEntry();
}

#exe{Option(OPTf_WARN_HEADER_MISMATCH, ON);}



