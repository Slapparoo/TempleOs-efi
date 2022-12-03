#include "/Efisource/Headers/Uefi.HH"

CEfiSystemTable st;


U64 st_ = &st;
U64 conout_ = &st.ConOut;
U64 firmwareVendor_ = &st.FirmwareVendor; 


"%x \n", sizeof(CEfiSystemTable);
"%x \n", sizeof(CEfiTableHeader);

"ConOut %x \n", conout_ - st_;


"FW Vender %x \n", firmwareVendor_ - st_ ;

CEfiGuid guid = EFI_PCI_OPTION_ROM_TABLE_GUID ;

"Guid {%08x-%04x-%04x-%016x}\n", guid.Data1, guid.Data2, guid.Data3, guid.Data4;