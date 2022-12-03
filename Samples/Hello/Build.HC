//#include "/Efisource/Samples/EfiBasic.PRJ.Z"

Cd(__DIR__);

// Standard HolyC Compile produces EfiBasic.BIN.Z
Cmp("EfiBasic");

// Produce EfiAsm.efi file from the EfiBasic.BIN.Z 
EfiFromBin("EfiBasic");