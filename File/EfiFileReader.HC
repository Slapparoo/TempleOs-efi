#include "/Efisource/File/EfiFile.HH"

U8 * efiDataString;

#exe{Option(OPTf_NO_REG_VAR, OFF);}
U0 hexy(U8 *data, I64 sz)
{
    "offset: 0x%08x\n", data - efiDataString;
    U64 i = 0, y = 0;
    for (; i < sz; i += 16)
    {
        for (y = 0; y < 16; y++)
        {
            U8 c = *data++ & 0xFF;
            if (c < 32 || c > 100)
              "%02x . ", c;
            else if (c == 36) // dollar
              "%02x . ", c;
            else 
              "%02x %c ", c, c;
        }
        "\n";
    }
}
#exe{Option(OPTf_NO_REG_VAR, ON);}


U0 printCharacteristics(CPeSectionHeader *peSectionHeader)
{
    U64 Characteristics = peSectionHeader->Characteristics;
    if (Characteristics & IMAGE_SCN_TYPE_NO_PAD)
        IMAGE_SCN_TYPE_NO_PAD_tx " ";
    if (Characteristics & IMAGE_SCN_CNT_CODE)
        IMAGE_SCN_CNT_CODE_tx " ";
    if (Characteristics & IMAGE_SCN_CNT_INITIALIZED_DATA)
        IMAGE_SCN_CNT_INITIALIZED_DATA_tx " ";
    if (Characteristics & IMAGE_SCN_CNT_UNINITIALIZED_DATA)
        IMAGE_SCN_CNT_UNINITIALIZED_DATA_tx " ";
    if (Characteristics & IMAGE_SCN_LNK_INFO)
        IMAGE_SCN_LNK_INFO_tx " ";
    if (Characteristics & IMAGE_SCN_LNK_REMOVE)
        IMAGE_SCN_LNK_REMOVE_tx " ";
    if (Characteristics & IMAGE_SCN_LNK_COMDAT)
        IMAGE_SCN_LNK_COMDAT_tx " ";
    if (Characteristics & IMAGE_SCN_GPREL)
        IMAGE_SCN_GPREL_tx " ";
    if (Characteristics & IMAGE_SCN_ALIGN_1BYTES)
        IMAGE_SCN_ALIGN_1BYTES_tx " ";
    if (Characteristics & IMAGE_SCN_ALIGN_2BYTES)
        IMAGE_SCN_ALIGN_2BYTES_tx " ";
    if (Characteristics & IMAGE_SCN_ALIGN_4BYTES)
        IMAGE_SCN_ALIGN_4BYTES_tx " ";
    if (Characteristics & IMAGE_SCN_ALIGN_8BYTES)
        IMAGE_SCN_ALIGN_8BYTES_tx " ";
    if (Characteristics & IMAGE_SCN_ALIGN_16BYTES)
        IMAGE_SCN_ALIGN_16BYTES_tx " ";
    if (Characteristics & IMAGE_SCN_ALIGN_32BYTES)
        IMAGE_SCN_ALIGN_32BYTES_tx " ";
    if (Characteristics & IMAGE_SCN_ALIGN_64BYTES)
        IMAGE_SCN_ALIGN_64BYTES_tx " ";
    if (Characteristics & IMAGE_SCN_ALIGN_128BYTES)
        IMAGE_SCN_ALIGN_128BYTES_tx " ";
    if (Characteristics & IMAGE_SCN_ALIGN_256BYTES)
        IMAGE_SCN_ALIGN_256BYTES_tx " ";
    if (Characteristics & IMAGE_SCN_ALIGN_512BYTES)
        IMAGE_SCN_ALIGN_512BYTES_tx " ";
    if (Characteristics & IMAGE_SCN_ALIGN_1024BYTES)
        IMAGE_SCN_ALIGN_1024BYTES_tx " ";
    if (Characteristics & IMAGE_SCN_ALIGN_2048BYTES)
        IMAGE_SCN_ALIGN_2048BYTES_tx " ";
    if (Characteristics & IMAGE_SCN_ALIGN_4096BYTES)
        IMAGE_SCN_ALIGN_4096BYTES_tx " ";
    if (Characteristics & IMAGE_SCN_ALIGN_8192BYTES)
        IMAGE_SCN_ALIGN_8192BYTES_tx " ";
    if (Characteristics & IMAGE_SCN_LNK_NRELOC_OVFL)
        IMAGE_SCN_LNK_NRELOC_OVFL_tx " ";
    if (Characteristics & IMAGE_SCN_MEM_DISCARDABLE)
        IMAGE_SCN_MEM_DISCARDABLE_tx " ";
    if (Characteristics & IMAGE_SCN_MEM_NOT_CACHED)
        IMAGE_SCN_MEM_NOT_CACHED_tx " ";
    if (Characteristics & IMAGE_SCN_MEM_NOT_PAGED)
        IMAGE_SCN_MEM_NOT_PAGED_tx " ";
    if (Characteristics & IMAGE_SCN_MEM_SHARED)
        IMAGE_SCN_MEM_SHARED_tx " ";
    if (Characteristics & IMAGE_SCN_MEM_EXECUTE)
        IMAGE_SCN_MEM_EXECUTE_tx " ";
    if (Characteristics & IMAGE_SCN_MEM_READ)
        IMAGE_SCN_MEM_READ_tx " ";
    if (Characteristics & IMAGE_SCN_MEM_WRITE)
        IMAGE_SCN_MEM_WRITE_tx " ";
}

U0 printPeHeader(CPeHeader *peHeader)
{
    "header->magic                0x%04x %c%c\n", peHeader->Magic, &peHeader->Magic(U8*)[0], &peHeader->Magic(U8*)[1];
    "header->Machine              0x%04x\n", peHeader->Machine;
    "header->NumberOfSections     %x\n", peHeader->NumberOfSections;
    "header->TimeDateStamp        %x\n", peHeader->TimeDateStamp;
    "header->PointerToSymbolTable %x\n", peHeader->PointerToSymbolTable;
    "header->NumberOfSymbols      %x\n", peHeader->NumberOfSymbols;
    "header->SizeOfOptionalHeader %x\n", peHeader->SizeOfOptionalHeader;
    "header->Characteristics      %x\n", peHeader->Characteristics;
    hexy(peHeader, sizeof(CPeHeader));
}

U0 printPeFrontMatter(CPeFrontMatter *peFrontMatter)
{
    "fm 0x%x 0x%x\n", peFrontMatter, *efiDataString(U16*);
    "peFrontMatter->id            0x%04x\n", peFrontMatter->id;
    "peFrontMatter->HeaderOffset  0x%04x, %d \n", peFrontMatter->HeaderOffset, peFrontMatter->HeaderOffset;
    " %d\n", sizeof(CPeFrontMatter);
    hexy(peFrontMatter, sizeof(CPeFrontMatter));
}

U0 printCPeSectionHeader(CPeSectionHeader *peSectionHeader)
{
    if (peSectionHeader->Name == 0)
        return;
    U8 *name = &peSectionHeader->Name;
    "PPeSectionHeader->Name                     %c%c%c%c%c%c%c%c\n", name[0], name[1], name[2], name[3], name[4], name[5], name[6], name[7];
    "PPeSectionHeader->VirtualSize              0x%08x\n", peSectionHeader->VirtualSize;
    "PPeSectionHeader->VirtualAddress           0x%08x\n", peSectionHeader->VirtualAddress;
    "PPeSectionHeader->SizeOfRawData            0x%08x\n", peSectionHeader->SizeOfRawData;
    "PPeSectionHeader->PointerToRawData         0x%08x\n", peSectionHeader->PointerToRawData;
    "PPeSectionHeader->PointerToRelocations     0x%08x\n", peSectionHeader->PointerToRelocations;
    "PPeSectionHeader->PointerToLinenumbers     0x%08x\n", peSectionHeader->PointerToLinenumbers;
    "PPeSectionHeader->NumberOfRelocations      0x%04x\n", peSectionHeader->NumberOfRelocations;
    "PPeSectionHeader->NumberOfLinenumbers      0x%04x\n", peSectionHeader->NumberOfLinenumbers;
    "PPeSectionHeader->Characteristics          0x%08x ", peSectionHeader->Characteristics;
    printCharacteristics(peSectionHeader);
    "\n";

    if (peSectionHeader->Characteristics & IMAGE_SCN_MEM_EXECUTE)
      Un(&efiDataString[peSectionHeader->PointerToRawData], peSectionHeader->VirtualSize);
}

U0 printPeOptionalheader(CPe32OptionalHeader *pe32OptionalHeader, CPeImageDataDirectory *pPeImageDataDirectorys, 
          CPeSectionHeader *peSectionHeader, CPeHeader *peHeader)
{
    "OptionalHeader->Magic                    0x%08x\n", pe32OptionalHeader->Magic;
    "OptionalHeader->SizeOfCode               0x%08x, %d \n", pe32OptionalHeader->SizeOfCode, pe32OptionalHeader->SizeOfCode;

    "OptionalHeader->MajorLinkerVersion       0x%08x\n", pe32OptionalHeader->MajorLinkerVersion;
    "OptionalHeader->MinorLinkerVersion       0x%08x\n", pe32OptionalHeader->MinorLinkerVersion;
    "OptionalHeader->SizeOfCode               0x%08x\n", pe32OptionalHeader->SizeOfCode;
    "OptionalHeader->SizeOfInitializedData    0x%08x\n", pe32OptionalHeader->SizeOfInitializedData;
    "OptionalHeader->SizeOfUninitializedData  0x%08x\n", pe32OptionalHeader->SizeOfUninitializedData;
    "OptionalHeader->AddressOfEntryPoint      0x%08x\n", pe32OptionalHeader->AddressOfEntryPoint;
    "OptionalHeader->BaseOfCode               0x%08x\n", pe32OptionalHeader->BaseOfCode;
    "OptionalHeader->ImageBase                0x%08lx\n", pe32OptionalHeader->ImageBase;
    "OptionalHeader->SectionAlignment         0x%08x\n", pe32OptionalHeader->SectionAlignment;
    "OptionalHeader->FileAlignment            0x%08x\n", pe32OptionalHeader->FileAlignment;
    "OptionalHeader->MajorOSVersion           0x%08x\n", pe32OptionalHeader->MajorOperatingSystemVersion;
    "OptionalHeader->MinorOSVersion           0x%08x\n", pe32OptionalHeader->MinorOperatingSystemVersion;
    "OptionalHeader->MajorImageVersion        0x%08x\n", pe32OptionalHeader->MajorImageVersion;
    "OptionalHeader->MinorImageVersion        0x%08x\n", pe32OptionalHeader->MinorImageVersion;
    "OptionalHeader->MajorSubsystemVersion    0x%08x\n", pe32OptionalHeader->MajorSubsystemVersion;
    "OptionalHeader->MinorSubsystemVersion    0x%08x\n", pe32OptionalHeader->MinorSubsystemVersion;
    "OptionalHeader->Win32VersionValue        0x%08x\n", pe32OptionalHeader->Win32VersionValue;
    "OptionalHeader->SizeOfImage              0x%08x\n", pe32OptionalHeader->SizeOfImage;
    "OptionalHeader->SizeOfHeaders            0x%08x\n", pe32OptionalHeader->SizeOfHeaders;
    "OptionalHeader->CheckSum                 0x%08x\n", pe32OptionalHeader->CheckSum;
    "OptionalHeader->Subsystem                0x%08x\n", pe32OptionalHeader->Subsystem;
    "OptionalHeader->DllCharacteristics       0x%08x\n", pe32OptionalHeader->DllCharacteristics;
    "OptionalHeader->SizeOfStackReserve       0x%08lx\n", pe32OptionalHeader->SizeOfStackReserve;
    "OptionalHeader->SizeOfStackCommit        0x%08lx %Lu\n", pe32OptionalHeader->SizeOfStackCommit, &pe32OptionalHeader->SizeOfStackCommit - pe32OptionalHeader;
    "OptionalHeader->SizeOfHeapReserve        0x%08lx %Lu\n", pe32OptionalHeader->SizeOfHeapReserve, &pe32OptionalHeader->SizeOfHeapReserve - pe32OptionalHeader;
    "OptionalHeader->SizeOfHeapCommit         0x%08lx %Lu\n", pe32OptionalHeader->SizeOfHeapCommit, &pe32OptionalHeader->SizeOfHeapCommit - pe32OptionalHeader;
    "OptionalHeader->LoaderFlags              0x%08x %Lu\n", pe32OptionalHeader->LoaderFlags, &pe32OptionalHeader->LoaderFlags - pe32OptionalHeader;
    "OptionalHeader->NumberOfRvaAndSizes      0x%08x %Lu\n", pe32OptionalHeader->NumberOfRvaAndSizes, &pe32OptionalHeader->NumberOfRvaAndSizes - pe32OptionalHeader;

    hexy(pe32OptionalHeader, sizeof(CPe32OptionalHeader));

    CPeImageDataDirectory *pPeImageDataDirectorysTmp = pPeImageDataDirectorys; // this is an array with 16 entries

    "pPeImageDataDirectorys %p %p %Lu\n", pPeImageDataDirectorysTmp, pPeImageDataDirectorys, pPeImageDataDirectorys - pe32OptionalHeader;

    I64 i = 0;
    for (; i < 16; i++)
    {
        if (pPeImageDataDirectorysTmp->Size != 0)
            "%Ld OptionalHeader->peImageDataDirectory %2d size, VirtualAddress   0x%08x, 0x%08x\n", pPeImageDataDirectorysTmp - pe32OptionalHeader, i, pPeImageDataDirectorysTmp->Size, pPeImageDataDirectorysTmp->VirtualAddress;
        pPeImageDataDirectorysTmp++;
    }
    hexy(pPeImageDataDirectorys, sizeof(CPeImageDataDirectory) * 16);

    CPeSectionHeader *peSectionHeaderTmp = peSectionHeader;
    for (i = 0; i < peHeader->NumberOfSections; i++)
    {
        printCPeSectionHeader(peSectionHeaderTmp);
        peSectionHeaderTmp++;
    }
}


// so I can do an initial reconstruct from blobbys
U0 dumpSectionBlobsToFile(CPeSectionHeader *peSectionHeader, CPeHeader *peHeader)
{
    I64 i = 0;
    for (; i < peHeader->NumberOfSections; i++) {
        CPeSectionHeader *whichSectionHeader = &peSectionHeader[i];
        U8* fName;
        switch (i) {
            case 0: fName = "blobby0.bin"; break;
            case 1: fName = "blobby1.bin"; break;
            case 2: fName = "blobby2.bin"; break;
        } 
        FileWrite(fName, &efiDataString[whichSectionHeader->PointerToRawData], whichSectionHeader->SizeOfRawData);
    }
}

U0 EfiFileDump(U8 * filename) {
  U8 efiFName =ExtDft(filename, "efi");
  U64 sz = 0;

  efiDataString = FileRead(efiFName, &sz);


  if (*efiDataString(U32*) != 0x805a4d) {
    "Wrong signature 0x%x, expecting the file to start with 0x805a4d \n", *efiDataString(U32*);
    return;
  }

  CPeFrontMatter *frontMatter = efiDataString;

  "%s 0x%x, 0x%x %d %d \n", filename, frontMatter, efiDataString, sizeof(CPeFrontMatter), 0x80- sizeof(CPeFrontMatter);

  printPeFrontMatter(frontMatter);

  U64 offset = 0;

  offset += frontMatter->HeaderOffset;
  CPeHeader *peHeader = &efiDataString[offset];

  offset += sizeof(CPeHeader); 
  CPe32OptionalHeader *pe32OptionalHeader = &efiDataString[offset];

  offset += sizeof(CPe32OptionalHeader); 
  CPeImageDataDirectory *peImageDataDirectorys = &efiDataString[offset];

  offset += sizeof(CPeImageDataDirectory) * 16; 
  CPeSectionHeader *peSectionHeader = &efiDataString [offset];

  "peHeader               %p %d\n", peHeader, peHeader -&efiDataString;
  "pe32OptionalHeader     %p %d\n", pe32OptionalHeader, pe32OptionalHeader - efiDataString;
  "peImageDataDirectorys  %p %d\n", peImageDataDirectorys, peImageDataDirectorys - efiDataString;
  "peSectionHeader        %p %d\n", peSectionHeader, peSectionHeader - efiDataString;

    printPeHeader(peHeader);

    printPeOptionalheader(pe32OptionalHeader, peImageDataDirectorys, peSectionHeader, peHeader);

    Free(efiFName);
    Free(efiDataString);
}
