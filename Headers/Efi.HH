#include "/Efisource/Headers/EfiKernelA.HH";
#include "/Efisource/Headers/Uefi.HH";


// Efi application entry
/*
class CEfiGuid {
  U32 Data1;
  U16 Data2;
  U16 Data3;
  U8 Data4[8];
};

class CEfiDevicePath {
  U8 Type;
  U8 SubType;
  U8 Length[2];
};


class CEfiMemoryDescriptor {
  U32 Type;
  U32 Pad;
  U8* PhysicalStart;
  U8* VirtualStart;
  U64 NumberOfPages;
  U64 Attribute;  
};
*/
/* efisetjmp.h */
/* efidevp.h */

/* Std input */
/*
class CEfiInputKey {
  U16 ScanCode;
  U16 UnicodeChar;
}

class CEfiSimpleInputInterface {
  U64 (*Reset)(U8* this, U8 ExtendedVerification);
  U64 (*ReadKeyStroke)(U8* this, CEfiInputKey Key); 
  U64 WaitForKey;  
}


// uefi.org/specs/UEFI/2.10/04_EFI_System_Table
class CEfiTableHeader {
  U64 Signature;
  U32 Revision;
  U32 HeaderSize;
  U32 CRC32;
  U32 Reserved;
};


// All function calls
class CEfiSimpleTextOutputInterface { 
  U64 (*Reset)();
  U64 (*OutputString)();
  U64 (*TestString)();
  U64 (*QueryMode)();
  U64 (*SetMode)();
  U64 (*SetAttribute)();
  U64 (*ClearScreen)();
  U64 (*SetCursorPosition)();
  U64 (*EnableCursor)();
  U64 (*Mode)();
}



// This should always be loaded to a memeoty address of 0x20494249
class CEfiSystemTable:CEfiTableHeader {
//  CEfiTableHeader Hdr;
  U32;  // some opadding to line things up? Maybe the extends dosen't line up the same 32bit align?
  U16 *FirmwareVender;
  U32 FirmwareRevision;
  U64 ConsoleHandle;
  U8 *ConIn;
  U64 ConsoleHandleOut;
  CEfiSimpleTextOutputInterface *ConOut;
  U64 StandardErrorHandle;
  U8 *StdErr;
  U8 *RuntimeServices;
  U8 *BootServices;
  U64 NumberOfTableEntries;
  U8 *ConfigurationTable;
};


#assert sizeof(CEfiTableHeader)==0x18
#assert sizeof(CEfiSystemTable)==0x74  
#assert sizeof(CEfiSimpleTextOutputInterface)==0x50
*/

class CApplicationPointers {
  CEfiSystemTable *efi;
  U8 *imageHandle;
//  U8 *appPointer; // hopefully the entry to the application
  U8 *stackPointer; // hopefully the entry to the application
};

public CApplicationPointers appPtrs;
public extern U64 AppEntry();
public extern U64 EfiCallWrapper(U64 p2, U64 p3, U64 p4, U64 this, U64 dest);


U0 printHexU8(U8 key);
U0 printHexU16(U16 key);
U0 printHexU32(U32 key);
U0 printHexU64(U64 key);

public CEfiSimpleTextOutputInterface *ConOut;// = appPtrs.efi->ConOut;
public CEfiBootServices *BootServices; // appPtrs.efi->BootServices


/*
U64 (*efi_text_reset_t)(Bool ExtendedVerification, U64 p2 = NULL, U64 p3 = NULL, 
      CEfiSimpleTextOutputInterface *This = ConOut, U8* fctn = ConOut->Reset);
*/

