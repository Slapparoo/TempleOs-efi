#include "/Efisource/File/EfiFiles.PRJ"

Cd(__DIR__);

//#include "/Efisource/Headers/Uefi.HH"
//CEfiSimpleTextOutputInterface  ConOut_;
//CEfiSimpleTextOutputInterface  *ConOut = &ConOut_;
Cmp("FunctionPtrs");

EfiFromBin("FunctionPtrs"); 