/**

Use a simple ASM Jump to redirect to an actual implementation
When used in combination with default parameters, diffent
method signatures can be used to provide differnt behaviors
from the same method call
*/
Trace;

U64 Destination(U64 a, U64 b, U64 c, U64 d) {
  "a %d, b %d, c %d, d %d\n", a, b, c, d; 
  return 1;
}

// Direct call
Destination(1, 2, 3, 4);

asm {
_SPRING_BOARD::
   MOV  RBX, &Destination
   JMP RBX
};



_extern _SPRING_BOARD U64 aa(U64 a, U64 b, U64 c, U64 d = 10);
_extern _SPRING_BOARD U64 bb(U64 a, U64 b, U64 c = 20, U64 d = 30);

U64 myValue = 40;
_extern _SPRING_BOARD U64 cc(U64 a, U64 b = myValue, U64 c = 20, U64 d = 30);

// Indirect calls using differnt default parameters
aa(5, 6, 7);
bb(8, 9);
cc(39);