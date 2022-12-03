#include "/Efisource/File/EfiFiles.PRJ.Z"
Cd(__DIR__);

// Standard HolyC Compile produces EfiAsm.BIN.Z
Cmp("EfiAsm");

// Produce EfiAsm.efi file from the EfiAsm.BIN.Z 
EfiFromBin("EfiAsm");