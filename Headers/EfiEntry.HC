// This needs to be the EFi entry point to capture the pointer values passed in
public extern U64 EfiEntry(U64 efiSystemTable, U64 imageHandle, U64 appPtr, U64 stackPtr) {


#exe{Option(OPTf_WARN_DUP_TYPES, OFF);}
asm {
  USE64
// get the entry address
    CALL &@@01
@@01:
    POP  RAX
    // Align to 16 bytes   
    AND  RAX, 0xFFFFFFFFFFFFFFF0
}

// fall through
U64 _Entry() {
  // 16 byte align the stack
  // capture the values passed in by Efi
  AND RSP, 0xFFFFFFFFFFFFFFF0

  U64 reg RCX imageHandle;
  U64 reg RDX efiPtr;
  U64 reg RAX appPtr;
  U64 reg RBP stackPtr;

  return EfiEntry(efiPtr, imageHandle, appPtr, stackPtr);
}
#exe{Option(OPTf_WARN_DUP_TYPES, ON);}



/*
This is identical to the HolyC Implementation
*/
/*
asm {
  USE64
    // capture application pointer
    CALL &@@01
@@01:
    POP  RAX
    // Align to 16 bytes   
    AND  RAX, 0xFFFFFFFFFFFFFFF0

    PUSH	RBP
    MOV	        RBP, RSP
    // Align the stack to 16 bytes
    AND         RSP, 0xFFFFFFFFFFFFFFF0
    
    PUSH        RBP  // initial stack pointer
    PUSH	RAX  // application pointer
    PUSH	RCX  // Image handle
    PUSH	RDX  // System table Pointer

  CALL &EfiEntry
    
  MOV RSP, RBP
  POP RBP
  RET
};
*/

