#include "/Efisource/Headers/EfiKernelA.HH";

// Efi application entry

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

/* efisetjmp.h */
/* efidevp.h */

/* Std input */
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


// This is the main structure provied to the applciation by UEFI
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


class CApplicationPointers {
  CEfiSystemTable *efi;
  U8 *imageHandle;
  U8 *appPointer; // hopefully the entry to the application
  U8 *stackPointer; // hopefully the entry to the application
};

public CApplicationPointers appPtrs;
public extern U64 AppEntry();



