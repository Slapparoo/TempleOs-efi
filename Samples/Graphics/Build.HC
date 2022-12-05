#include "/Efisource/File/EfiFiles.PRJ.Z"

Cd(__DIR__);

// Standard HolyC Compile produces Graphics.BIN.Z
Cmp("Graphics");

// Produce InfoDump.efi file from the Graphics.BIN.Z 
EfiFromBin("Graphics");