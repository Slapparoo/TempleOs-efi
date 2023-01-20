/*

https://learn.microsoft.com/en-us/windows/win32/debug/pe-format#section-flags
 
$LK,"Efi File Overview",A="FI:EfiFile.DD"$

*/


#define IMAGE_SCN_TYPE_NO_PAD 0x00000008 //The section should not be padded to the next boundary. This flag is obsolete and is replaced by IMAGE_SCN_ALIGN_1BYTES. This is valid only for object files.
#define IMAGE_SCN_CNT_CODE 0x00000020 //The section contains executable code.
#define IMAGE_SCN_CNT_INITIALIZED_DATA 0x00000040 //The section contains initialized data.
#define IMAGE_SCN_CNT_UNINITIALIZED_DATA 0x00000080 //The section contains uninitialized data.
#define IMAGE_SCN_LNK_INFO 0x00000200 // The section contains comments or other information. The .drectve section has this type. This is valid for object files only.
#define IMAGE_SCN_LNK_REMOVE 0x00000800 //The section will not become part of the image. This is valid only for object files.
#define IMAGE_SCN_LNK_COMDAT 0x00001000 //The section contains COMDAT data. For more information, see COMDAT Sections (Object Only). This is valid only for object files.
#define IMAGE_SCN_GPREL 0x00008000 //The section contains data referenced through the global pointer (GP).
#define IMAGE_SCN_ALIGN_1BYTES 0x00100000 //Align data on a 1-byte boundary. Valid only for object files.
#define IMAGE_SCN_ALIGN_2BYTES 0x00200000 //Align data on a 2-byte boundary. Valid only for object files.
#define IMAGE_SCN_ALIGN_4BYTES 0x00300000 // Align data on a 4-byte boundary. Valid only for object files.
#define IMAGE_SCN_ALIGN_8BYTES 0x00400000 // Align data on an 8-byte boundary. Valid only for object files.
#define IMAGE_SCN_ALIGN_16BYTES 0x00500000 // Align data on a 16-byte boundary. Valid only for object files.
#define IMAGE_SCN_ALIGN_32BYTES 0x00600000 //Align data on a 32-byte boundary. Valid only for object files.
#define IMAGE_SCN_ALIGN_64BYTES 0x00700000 // Align data on a 64-byte boundary. Valid only for object files.
#define IMAGE_SCN_ALIGN_128BYTES 0x00800000 // Align data on a 128-byte boundary. Valid only for object files.
#define IMAGE_SCN_ALIGN_256BYTES 0x00900000 // Align data on a 256-byte boundary. Valid only for object files.
#define IMAGE_SCN_ALIGN_512BYTES 0x00A00000 // Align data on a 512-byte boundary. Valid only for object files.
#define IMAGE_SCN_ALIGN_1024BYTES 0x00B00000 // Align data on a 1024-byte boundary. Valid only for object files.
#define IMAGE_SCN_ALIGN_2048BYTES 0x00C00000 // Align data on a 2048-byte boundary. Valid only for object files.
#define IMAGE_SCN_ALIGN_4096BYTES 0x00D00000 // Align data on a 4096-byte boundary. Valid only for object files.
#define IMAGE_SCN_ALIGN_8192BYTES 0x00E00000 // Align data on an 8192-byte boundary. Valid only for object files.
#define IMAGE_SCN_LNK_NRELOC_OVFL 0x01000000 //The section contains extended relocations.
#define IMAGE_SCN_MEM_DISCARDABLE 0x02000000 // IMAGE_SCN_MEM_DISCARDABLE The section can be discarded as needed.
#define IMAGE_SCN_MEM_NOT_CACHED 0x04000000 /// The section cannot be cached.
#define IMAGE_SCN_MEM_NOT_PAGED 0x08000000 // The section is not pageable.
#define IMAGE_SCN_MEM_SHARED 0x10000000 // The section can be shared in memory.
#define IMAGE_SCN_MEM_EXECUTE 0x20000000 // The section can be executed as code.
#define IMAGE_SCN_MEM_READ 0x40000000 // The section can be read.
#define IMAGE_SCN_MEM_WRITE 0x80000000 //The section can be written to.

#define IMAGE_SCN_TYPE_NO_PAD_tx "TYPE_NO_PAD"
#define IMAGE_SCN_CNT_CODE_tx "CNT_CODE"
#define IMAGE_SCN_CNT_INITIALIZED_DATA_tx "CNT_INITIALIZED_DATA"
#define IMAGE_SCN_CNT_UNINITIALIZED_DATA_tx "CNT_UNINITIALIZED_DATA"
#define IMAGE_SCN_LNK_INFO_tx "LNK_INFO"
#define IMAGE_SCN_LNK_REMOVE_tx "LNK_REMOVE"
#define IMAGE_SCN_LNK_COMDAT_tx "LNK_COMDAT"
#define IMAGE_SCN_GPREL_tx "GPREL"
#define IMAGE_SCN_ALIGN_1BYTES_tx "ALIGN_1BYTES"
#define IMAGE_SCN_ALIGN_2BYTES_tx "ALIGN_2BYTES"
#define IMAGE_SCN_ALIGN_4BYTES_tx "ALIGN_4BYTES"
#define IMAGE_SCN_ALIGN_8BYTES_tx "ALIGN_8BYTES"
#define IMAGE_SCN_ALIGN_16BYTES_tx "ALIGN_16BYTES"
#define IMAGE_SCN_ALIGN_32BYTES_tx "ALIGN_32BYTES"
#define IMAGE_SCN_ALIGN_64BYTES_tx "ALIGN_64BYTES"
#define IMAGE_SCN_ALIGN_128BYTES_tx "ALIGN_128BYTES"
#define IMAGE_SCN_ALIGN_256BYTES_tx "ALIGN_256BYTES"
#define IMAGE_SCN_ALIGN_512BYTES_tx "ALIGN_512BYTES"
#define IMAGE_SCN_ALIGN_1024BYTES_tx "ALIGN_1024BYTES"
#define IMAGE_SCN_ALIGN_2048BYTES_tx "ALIGN_2048BYTES"
#define IMAGE_SCN_ALIGN_4096BYTES_tx "ALIGN_4096BYTES"
#define IMAGE_SCN_ALIGN_8192BYTES_tx "ALIGN_8192BYTES"
#define IMAGE_SCN_LNK_NRELOC_OVFL_tx "LNK_NRELOC_OVFL"
#define IMAGE_SCN_MEM_DISCARDABLE_tx "MEM_DISCARDABLE"
#define IMAGE_SCN_MEM_NOT_CACHED_tx "MEM_NOT_CACHED"
#define IMAGE_SCN_MEM_NOT_PAGED_tx "MEM_NOT_PAGED"
#define IMAGE_SCN_MEM_SHARED_tx "MEM_SHARED"
#define IMAGE_SCN_MEM_EXECUTE_tx "MEM_EXECUTE"
#define IMAGE_SCN_MEM_READ_tx "MEM_READ"
#define IMAGE_SCN_MEM_WRITE_tx "MEM_WRITE"



/**
 * https://learn.microsoft.com/en-us/windows/win32/debug/pe-format#section-flags
 */

class CPeImageDataDirectory
{
    U32 VirtualAddress;
    U32 Size;
};

class CPeSectionHeader
{
    U64 Name;
    U32 VirtualSize;
    U32 VirtualAddress;
    U32 SizeOfRawData;
    U32 PointerToRawData;
    U32 PointerToRelocations;
    U32 PointerToLinenumbers;
    U16 NumberOfRelocations;
    U16 NumberOfLinenumbers;
    U32 Characteristics;
};

class CPeFrontMatter
{
    U16 id; // MZ
    U16 SomeNUmber;
    U16 pad[28];
    U16 HeaderOffset;
    U16 pad[8];
    U8 sometext[50];
};

// 1 byte aligned
class CPeHeader
{                     // offset specified at 0xc3
    U32 Magic;   // PE\0\0 or 0x00004550
    U16 Machine; // 0x8664
    U16 NumberOfSections;
    U32 TimeDateStamp;
    U32 PointerToSymbolTable;
    U32 NumberOfSymbols;
    U16 SizeOfOptionalHeader;
    U16 Characteristics;
};

// PE32+ header != PE32 header
class CPe32OptionalHeader
{
    U16 Magic; // 0x010b - PE32, 0x020b - PE32+ (64 bit)
    U8 MajorLinkerVersion;
    U8 MinorLinkerVersion;
    U32 SizeOfCode;
    U32 SizeOfInitializedData;
    U32 SizeOfUninitializedData;
    U32 AddressOfEntryPoint;
    U32 BaseOfCode;
    U64 ImageBase;
    U32 SectionAlignment;
    U32 FileAlignment;
    U16 MajorOperatingSystemVersion;
    U16 MinorOperatingSystemVersion;
    U16 MajorImageVersion;
    U16 MinorImageVersion;
    U16 MajorSubsystemVersion;
    U16 MinorSubsystemVersion;
    U32 Win32VersionValue;
    U32 SizeOfImage;
    U32 SizeOfHeaders;
    U32 CheckSum;
    U16 Subsystem;
    U16 DllCharacteristics;
    U64 SizeOfStackReserve;
    U64 SizeOfStackCommit;
    U64 SizeOfHeapReserve;
    U64 SizeOfHeapCommit;
    U32 LoaderFlags;
    U32 NumberOfRvaAndSizes;
    // U16 peImageDataDirectoryList; // this is an array with 16 entries
};

class CPeImageSectionHeader
{                  // size 40 bytes
    U64 Name; // is char[8]
    U32 VirtualSize;
    U32 VirtualAddress;
    U32 SizeOfRawData;
    U32 PointerToRawData;
    U32 PointerToRelocations;
    U32 PointerToLinenumbers;
    U16 NumberOfRelocations;
    U16 NumberOfLinenumbers;
    U32 Characteristics;
};


