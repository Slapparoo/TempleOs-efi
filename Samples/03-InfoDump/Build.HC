#include "/Efisource/File/EfiFiles.PRJ"

Cd(__DIR__);

// Standard HolyC Compile produces InfoDump.BIN.Z
Cmp("InfoDump");

// Produce InfoDump.efi file from the InfoDump.BIN.Z 
EfiFromBin("InfoDump");