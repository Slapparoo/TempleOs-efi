#include "/Efisource/Headers/EfiKernelA.HH";
#include "/Efisource/Headers/Uefi.HH";

/**
class definitions
*/

class CApplicationPointers {
  CEfiSystemTable *efi;
  U8 *imageHandle;
  U8 *stackPointer; // hopefully the entry to the application
};

/**
Helper methods 
*/
public extern U64 AppEntry();
public extern U64 EfiCallWrapper(U64 p2, U64 p3, U64 p4, U64 this, U64 dest);
public extern U64 EfiCallWrapperOrdered(U64 P1, U64 p2, U64 p3, U64 p4, U64 dest) {

public extern U8* FixPtr(U8 *ptr);

public extern U0 printHexU8(U8 key);
public extern U0 printHexU16(U16 key);
public extern U0 printHexU32(U32 key);
public extern U0 printHexU64(U64 key);
public extern U0 PrintGuid(CEfiGuid * guid);

/**
Data
*/

public CApplicationPointers appPtrs;
public CEfiSimpleTextOutputInterface *ConOut;// = appPtrs.efi->ConOut;
public CEfiBootServices *BS; // appPtrs.efi->BootServices
public CEfiRuntimeServices *RT; // appPtrs.efi->BootServices
public CEfiSystemTable *ST;
public CEfiLoadedImageProtocol * LoadedImageProtocol;
public CEfiGop * GOP; // = FixPtr(&gop);


/**
GUID's
*/

public CEfiGuid *GraphicsGuid;


public extern U64 efi_handle_protocol_t(U8 * Handle, CEfiGuid *Protocol, U8 **Interface);
public extern U64 efi_locate_protocol_t(CEfiGuid *Protocol, U8 *Registration, U8 **Interface);
