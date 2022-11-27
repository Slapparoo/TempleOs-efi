#include "/Efisource/File/EfiFiles.PRJ.Z"

Cd(__DIR__);

// Standard HolyC Compile produces EfiBasic.BIN.Z
Cmp("EfiBasic");

// Produce EfiAsm.efi file from the EfiBasic.BIN.Z 
EfiFromBin("EfiBasic");