EfiConOutClearScreen();
EfiConOutSetMode(4);

"Info Dump\r\n\r\n";


"appPtrs              0x"; printHexU64(appPtrs); "\r\n";
"appPtrs.efi          0x"; printHexU64(appPtrs.efi); "\r\n";
"appPtrs.imageHandle  0x"; printHexU64(appPtrs.imageHandle); "\r\n";
"appPtrs.stackPointer 0x"; printHexU64(appPtrs.stackPointer); "\r\n";


"Header signature     0x"; printHexU64(appPtrs.efi->Signature); "\r\n";
"Header Revision      0x"; printHexU32(appPtrs.efi->Revision); "\r\n";
"Header HeaderSize    0x"; printHexU32(appPtrs.efi->HeaderSize); "\r\n";
"Header CRC           0x"; printHexU32(appPtrs.efi->CRC32); "\r\n";

"EfiCallWrapper          0x"; printHexU64(APPLICATION_ADDRESS + &EfiCallWrapper); "\r\n";

"ConOut->Reset           0x"; printHexU64(ConOut->Reset); "\r\n";
"ConOut->Mode            0x"; printHexU64(ConOut->Mode); "\r\n";


"ConOut->Mode->MaxMode   0x"; printHexU32(ConOut->Mode->MaxMode); "\r\n";
"ConOut->Mode->Mode      0x"; printHexU32(ConOut->Mode->Mode); "\r\n";

"BootServices->RaiseTPL  0x"; printHexU64(BootServices->RaiseTPL); "\r\n";

"ConOut->Mode->Attribute 0x"; printHexU32(ConOut->Mode->Attribute); "\r\n";
"ConOut->Mode->Col       0x"; printHexU32(ConOut->Mode->CursorColumn); "\r\n";
"ConOut->Mode->Row       0x"; printHexU32(ConOut->Mode->CursorRow); "\r\n";
"ConOut->Mode->Visible   0x"; printHexU8(ConOut->Mode->CursorVisible); "\r\n";


EfiConOutSetCursor(ConOut->Mode->CursorColumn+3, ConOut->Mode->CursorRow+3);

"BootServices            0x"; printHexU64(BootServices); "\r\n";
