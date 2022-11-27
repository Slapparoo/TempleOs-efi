#include "/Efisource/File/EfiFile.HH";

/**
Basically takes an Exisintg .efi file and outputs it as hex
*/

//U8 *string;
U8* string = FileRead("/Efisource/File/VeryBasic.efi");


U0 printValues(U8 *obj, U64 sz) {
  U64 i = 0;
  for (; i < sz; i++) {
    "0x%02x, ", *obj++ &0xFF;
    if (i % 12 == 0) {
       "\n";
    }
  }
}

if (*string(U32*) != 0x805a4d) {
  "Wrong signature 0x%x \n", *string(U32*);
}


CPeFrontMatter *frontMatter = string;


U64 offset = 0;

offset += peFrontMatter->HeaderOffset;
CPeHeader *peHeader = &string[offset];

offset += sizeof(CPeHeader); 
CPe32OptionalHeader *pe32OptionalHeader = &string[offset];

offset += sizeof(CPe32OptionalHeader); 
CPeImageDataDirectory *peImageDataDirectorys = &string[offset];

offset += sizeof(CPeImageDataDirectory) * 16; 
CPeSectionHeader *peSectionHeader = &string[offset];

U8* headerEnd = peSectionHeader(U8*) + sizeof(CPeSectionHeader);


"\n\nU8 efiSimpleTemplate[0x%x] = {", headerEnd - string;
printValues(string, headerEnd - string);
"};\n\n";