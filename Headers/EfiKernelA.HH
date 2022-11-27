
U16i union U16
{
  I8i	i8[2];
  U8i	u8[2];
};

I16i union I16
{
  I8i	i8[2];
  U8i	u8[2];
};

U32i union U32
{
  I8i	i8[4];
  U8i	u8[4];
  I16	i16[2];
  U16	u16[2];
};

I32i union I32
{
  I8i	i8[4];
  U8i	u8[4];
  I16	i16[2];
  U16	u16[2];
};

U64i union U64
{
  I8i	i8[8];
  U8i	u8[8];
  I16	i16[4];
  U16	u16[4];
  I32	i32[2];
  U32	u32[2];
};

I64i union I64
{
  I8i	i8[8];
  U8i	u8[8];
  I16	i16[4];
  U16	u16[4];
  I32	i32[2];
  U32	u32[2];
};
#define NULL	0
#define TRUE	1
#define FALSE	0
#define ON	1
#define OFF	0
#define I8_MIN (-0x80)
#define I8_MAX 0x7F
#define U8_MIN 0
#define U8_MAX 0xFF
#define I16_MIN (-0x8000)
#define I16_MAX 0x7FFF
#define U16_MIN 0
#define U16_MAX 0xFFFF
#define I32_MIN (-0x80000000)
#define I32_MAX 0x7FFFFFFF
#define U32_MIN 0
#define U32_MAX 0xFFFFFFFF
#define I64_MIN (-0x8000000000000000)
#define I64_MAX 0x7FFFFFFFFFFFFFFF
#define U64_MIN 0
#define U64_MAX 0xFFFFFFFFFFFFFFFF
#define INVALID_PTR	I64_MAX
#define STR_LEN 144


