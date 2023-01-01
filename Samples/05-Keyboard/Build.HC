#include "/Efisource/File/EfiFiles.PRJ"

Cd(__DIR__);

// Standard HolyC Compile produces Keyboard.BIN.Z
Cmp("Keyboard");

// Produce Keyboard.efi file from the Keyboard.BIN.Z 
EfiFromBin("Keyboard");