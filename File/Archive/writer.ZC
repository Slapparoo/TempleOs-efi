#include "/efi-reader/reader.HH"

/**
 * write a efi file using VeryBasic.efi as a template
 * the idea is the only stuff that will be changing is the size of the sections
 *
 * the size must be a multiple of FileAlignment from the optional header
 * roundUp(size bytes / OptionalHeader->FileAlignment) * OptionalHeader->FileAlignment
 *
 */

U8 *template = FileRead("/efi-reader/VeryBasic.efi");


// so I can do an initial reconstruct from blobbys
U0 writeToFile(CPeSectionHeader *peSectionHeader, CPeHeader *peHeader)
{
    U64 i = 0;
    for (; i < peHeader->NumberOfSections; i++) {
        CPeSectionHeader *whichSectionHeader = &peSectionHeader[i];
        U8* fName;
        switch (i) {
            case 0: fName = "/efi-reader/blobby0.bin"; break;
            case 1: fName = "/efi-reader/blobby1.bin"; break;
            case 2: fName = "/efi-reader/blobby2.bin"; break;
        } 
        "write %s size %d\n", fName, whichSectionHeader->SizeOfRawData;
        FileWrite(fName, &template[whichSectionHeader->PointerToRawData], whichSectionHeader->SizeOfRawData);
    }
}



    CPeFrontMatter *frontMatter = template;
    "peFrontMatter->id            0x%04x\n", frontMatter->id;
    "peFrontMatter->HeaderOffset  0x%04x, %d \n", frontMatter->HeaderOffset, frontMatter->HeaderOffset;


    CPeHeader *peHeader = &template[frontMatter->HeaderOffset];
    "header->magic                0x%04x %c%c\n", peHeader->Magic, &peHeader->Magic(U8*)[0], &peHeader->Magic(U8*)[1];

    CPe32OptionalHeader *pe32OptionalHeader = &template[frontMatter->HeaderOffset + sizeof(CPeHeader)];
    "OptionalHeader->Magic                    0x%08x\n", pe32OptionalHeader->Magic;

    CPeImageDataDirectory *pPeImageDataDirectorys = &template[frontMatter->HeaderOffset + sizeof(CPeHeader) + sizeof(CPe32OptionalHeader)];
    CPeSectionHeader *peSectionHeader = &template[frontMatter->HeaderOffset + sizeof(CPeHeader) + sizeof(CPe32OptionalHeader) + (sizeof(CPeImageDataDirectory) * 16)];

    // calculate the end of the headers this should ~= the first section (its align so it will be the next section)
    U64 sz = peSectionHeader - template + (sizeof(CPeSectionHeader) * peHeader->NumberOfSections);


    writeToFile(peSectionHeader, peHeader);


/*

    long double x = (long double)sz / (long double)pe32OptionalHeader->FileAlignment;
    // this is where the blocks start
    long blocks = ceill(x) * pe32OptionalHeader->FileAlignment;
    // "%.2Lf  %.2Lf %lu \n", x, ceill( x), pe32OptionalHeader->FileAlignment);
    // "0x%016Lx 0x%08lx 0x%08lx \n", sz, peSectionHeader->PointerToRawData, blocks);

    // ** code entry point **
    // OptionalHeader->AddressOfEntryPoint
    // OptionalHeader->BaseOfCode
    // PPeSectionHeader->VirtualAddress




    // char * newcontent = malloc();

*/
