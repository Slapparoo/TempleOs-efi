#include "/Efisource/File/EfiFiles.PRJ"

Cd(__DIR__);

// Standard HolyC Compile produces Mouse.BIN.Z
Cmp("Mouse");

// Produce Mouse.efi file from the Mouse.BIN.Z 
EfiFromBin("Mouse");