/**
class definitions
*/

class CApplicationPointers {
  CEfiSystemTable *efi;
  U8 *imageHandle;
  U8 *stackPointer; // hopefully the entry to the application
};

class CProtocol {
  U64 Name;  // Readable name we provide
  U8* Pointer;  // Pointer the the Protocol class, populated by the call to locate protocol
  CEfiGuid Guid; // GUID of the protocol we want to locate
  U64 Required;  // error on fail if required
  U64 Loaded;  // only valid if not required, and it doesn't load
};

#define LOAD_PROTOCOLS_SIZE 3


/**
Helper methods 
*/
public extern U64 AppEntry();
public extern U64 WireEfiMethods();
public extern U64 EfiStartup();


public extern U64 EfiCallWrapper(U64 p2, U64 p3, U64 p4, U64 this, U64 dest);
public extern U64 EfiCallWrapper5(U64 p2, U64 p3, U64 p4, U64 p5, U64 this, U64 dest) {

public extern U64 EfiCallWrapperOrdered(U64 P1, U64 p2, U64 p3, U64 p4, U64 dest);
public extern U64 EfiOOCall4(U64 p2, U64 p3, U64 p4, U64 this, U64 dest);
/** Ment for static resolution of this and dest where pointer values are not known at compile time */
public extern U64 EfiCall4(U64 p1, U64 p2, U64 p3, U64 p4, U64 this, U64 dest);
/** Ment for static resolution of this and dest where pointer values are not known at compile time */
public extern U64 EfiCall5(U64 p1, U64 p2, U64 p3, U64 p4, U64 p5, U64 this, U64 dest) {

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
public CEfiSimplePointerProtocol *SimplePointer;
public CEfiBootServices *BS; // appPtrs.efi->BootServices
public CEfiRuntimeServices *RT; // appPtrs.efi->BootServices
public CEfiSystemTable *ST;
public CEfiLoadedImageProtocol * LoadedImageProtocol;
public CEfiGop * GOP; // = FixPtr(&gop);
public CEfiSimpleInputInterface *ConIn;
public CProtocol Protocols[LOAD_PROTOCOLS_SIZE]; 
public CEfiSimpleFileSystemProtocol *SimpleFileSystem;
public U8* SMBios;
public U8* Acpi;
public U8* Acpi20;
public U8* Mps;
public U8* SMBios3;

/**
GUID's
*/

 