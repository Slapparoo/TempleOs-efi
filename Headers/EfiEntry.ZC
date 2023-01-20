// This needs to be the EFi entry point to capture the pointer values passed in
public extern U64 EfiEntry(U64 efiSystemTable, U64 imageHandle, U64 stackPtr) {


#exe{Option(OPTf_WARN_DUP_TYPES, OFF);}

// fall through
U64 _Entry() {
  // 16 byte align the stack
  // capture the values passed in by Efi
  AND RSP, 0xFFFFFFFFFFFFFFF0

  U64 reg RCX imageHandle;
  U64 reg RDX efiPtr;
  U64 reg RBP stackPtr;

  return EfiEntry(efiPtr, imageHandle, stackPtr);
}

#exe{Option(OPTf_WARN_DUP_TYPES, ON);}
