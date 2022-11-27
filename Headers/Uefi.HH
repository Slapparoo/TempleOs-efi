/*
 * Adpated from uefi.h https://gitlab.com/bztsrc/posix-uefi
 *
 * Copyright (C) 2021 bzt (bztsrc@gitlab)
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * This file is part of the POSIX-UEFI package.
 * @brief Main (and only) header file
 *
 */

class EfiGuid {
    U32 Data1;
    U16 Data2;
    U16 Data3;
    U8 Data4[8];
};

class EfiDevicePath {
    U8 Type;
    U8 SubType;
    U8 Length[2];
};

class EfiMemoryDescriptor {
    U32 Type;
    U32 Pad;
    U8 * PhysicalStart;
    U8 * VirtualStart;
    U64 NumberOfPages;
    U64 Attribute;
};

class EfiTableHeader {
    U64 Signature;
    U32 Revision;
    U32 HeaderSize;
    U32 CRC32;
    U32 Reserved;
};

/*** definitions only needed when efi.h (either from EDK II or gnu-efi) is NOT included ***/


/* efibind.h */
#define EFIERR(a)           (0x8000000000000000 | (U32)(a))
#define EFI_ERROR_MASK      0x8000000000000000
#define EFIERR_OEM(a)       (0xc000000000000000 | (U32)(a))

#define BAD_POINTER         0xFBFBFBFBFBFBFBFB
#define MAX_ADDRESS         0xFFFFFFFFFFFFFFFF

#define EFI_SIGNATURE_16(A,B)             ((A) | (B<<8))
#define EFI_SIGNATURE_32(A,B,C,D)         (EFI_SIGNATURE_16(A,B)     | (EFI_SIGNATURE_16(C,D)     << 16))
#define EFI_SIGNATURE_64(A,B,C,D,E,F,G,H) (EFI_SIGNATURE_32(A,B,C,D) | ((U64)(EFI_SIGNATURE_32(E,F,G,H)) << 32))


/* efistdarg.h */
/*
typedef __builtin_va_list va_list;
#define va_start(v,l)   __builtin_va_start(v,l)
#define va_end(v)       __builtin_va_end(v)
#define va_arg(v,l)     __builtin_va_arg(v,l)
#define va_copy(d,s)    __builtin_va_copy(d,s)
*/
/* efierr.h */
#define EFIWARN(a)                            (a)
#define EFI_ERROR(a)           (((I64) a) < 0)
#define EFI_SUCCESS                            0
#define EFI_LOAD_ERROR                  EFIERR(1)
#define EFI_INVALID_PARAMETER           EFIERR(2)
#define EFI_UNSUPPORTED                 EFIERR(3)
#define EFI_BAD_BUFFER_SIZE             EFIERR(4)
#define EFI_BUFFER_TOO_SMALL            EFIERR(5)
#define EFI_NOT_READY                   EFIERR(6)
#define EFI_DEVICE_ERROR                EFIERR(7)
#define EFI_WRITE_PROTECTED             EFIERR(8)
#define EFI_OUT_OF_RESOURCES            EFIERR(9)
#define EFI_VOLUME_CORRUPTED            EFIERR(10)
#define EFI_VOLUME_FULL                 EFIERR(11)
#define EFI_NO_MEDIA                    EFIERR(12)
#define EFI_MEDIA_CHANGED               EFIERR(13)
#define EFI_NOT_FOUND                   EFIERR(14)
#define EFI_ACCESS_DENIED               EFIERR(15)
#define EFI_NO_RESPONSE                 EFIERR(16)
#define EFI_NO_MAPPING                  EFIERR(17)
#define EFI_TIMEOUT                     EFIERR(18)
#define EFI_NOT_STARTED                 EFIERR(19)
#define EFI_ALREADY_STARTED             EFIERR(20)
#define EFI_ABORTED                     EFIERR(21)
#define EFI_ICMP_ERROR                  EFIERR(22)
#define EFI_TFTP_ERROR                  EFIERR(23)
#define EFI_PROTOCOL_ERROR              EFIERR(24)
#define EFI_INCOMPATIBLE_VERSION        EFIERR(25)
#define EFI_SECURITY_VIOLATION          EFIERR(26)
#define EFI_CRC_ERROR                   EFIERR(27)
#define EFI_END_OF_MEDIA                EFIERR(28)
#define EFI_END_OF_FILE                 EFIERR(31)
#define EFI_INVALID_LANGUAGE            EFIERR(32)
#define EFI_COMPROMISED_DATA            EFIERR(33)

#define EFI_WARN_UNKOWN_GLYPH           EFIWARN(1)
#define EFI_WARN_UNKNOWN_GLYPH          EFIWARN(1)
#define EFI_WARN_DELETE_FAILURE         EFIWARN(2)
#define EFI_WARN_WRITE_FAILURE          EFIWARN(3)
#define EFI_WARN_BUFFER_TOO_SMALL       EFIWARN(4)

/* efisetjmp.h */
/*
#ifdef __x86_64__
class __attribute__((aligned(8))) jmp_buf[1] {
    U64    Rbx;
    U64    Rsp;
    U64    Rbp;
    U64    Rdi;
    U64    Rsi;
    U64    R12;
    U64    R13;
    U64    R14;
    U64    R15;
    U64    Rip;
    U64    MxCsr;
    U8     XmmBuffer[160];
};
#endif
#ifdef __aarch64__
class __attribute__((aligned(8))) jmp_buf[1] {
    U64    X19;
    U64    X20;
    U64    X21;
    U64    X22;
    U64    X23;
    U64    X24;
    U64    X25;
    U64    X26;
    U64    X27;
    U64    X28;
    U64    FP;
    U64    LR;
    U64    IP0;
    U64    reserved;
    U64    D8;
    U64    D9;
    U64    D10;
    U64    D11;
    U64    D12;
    U64    D13;
    U64    D14;
    U64    D15;
};
#endif
extern U64 setjmp(jmp_buf env) __attribute__((returns_twice));
extern void longjmp(jmp_buf env, U64 value) __attribute__((noreturn));
*/

/* efidevp.h */
#define EFI_DEVICE_PATH_PROTOCOL_GUID { 0x9576e91, 0x6d3f, 0x11d2, {0x8e, 0x39, 0x0, 0xa0, 0xc9, 0x69, 0x72, 0x3b} }
#define EFI_DP_TYPE_MASK                    0x7F
#define EFI_DP_TYPE_UNPACKED                0x80
#define END_DEVICE_PATH_TYPE                0x7f
#define END_ENTIRE_DEVICE_PATH_SUBTYPE      0xff
#define END_INSTANCE_DEVICE_PATH_SUBTYPE    0x01
#define END_DEVICE_PATH_LENGTH              (sizeof(EfiDevicePath))
#define DP_IS_END_TYPE(a)
#define DP_IS_END_SUBTYPE(a)        ( ((a)->SubType == END_ENTIRE_DEVICE_PATH_SUBTYPE )
#define DevicePathType(a)           ( ((a)->Type) & EFI_DP_TYPE_MASK )
#define DevicePathSubType(a)        ( (a)->SubType )
#define DevicePathNodeLength(a)     ( ((a)->Length[0]) | ((a)->Length[1] << 8) )
#define NextDevicePathNode(a)       ( (EfiDevicePath *) ( ((U8 *) (a)) + DevicePathNodeLength(a)))
#define IsDevicePathEndType(a)      ( DevicePathType(a) == END_DEVICE_PATH_TYPE )
#define IsDevicePathEndSubType(a)   ( (a)->SubType == END_ENTIRE_DEVICE_PATH_SUBTYPE )
#define IsDevicePathEnd(a)          ( IsDevicePathEndType(a) && IsDevicePathEndSubType(a) )
#define IsDevicePathUnpacked(a)     ( (a)->Type & EFI_DP_TYPE_UNPACKED )
#define SetDevicePathNodeLength(a,l) {                  \
            (a)->Length[0] = (U8) (l);               \
            (a)->Length[1] = (U8) ((l) >> 8);        \
            }
#define SetDevicePathEndNode(a)  {                      \
            (a)->Type = END_DEVICE_PATH_TYPE;           \
            (a)->SubType = END_ENTIRE_DEVICE_PATH_SUBTYPE;     \
            (a)->Length[0] = sizeof(EfiDevicePath); \
            (a)->Length[1] = 0;                         \
            }

/* efiapi.h */
#define EFI_SPECIFICATION_MAJOR_REVISION 1
#define EFI_SPECIFICATION_MINOR_REVISION 02

#define TPL_APPLICATION      4
#define TPL_CALLBACK         8
#define TPL_NOTIFY          16
#define TPL_HIGH_LEVEL      31
#define EFI_TPL_APPLICATION TPL_APPLICATION
#define EFI_TPL_CALLBACK    TPL_CALLBACK
#define EFI_TPL_NOTIFY      TPL_NOTIFY
#define EFI_TPL_HIGH_LEVEL  TPL_HIGH_LEVEL

#define NextMemoryDescriptor(Ptr,Size)  ((EfiMemoryDescriptor *) (((U8 *) Ptr) + Size))

#define EFI_PAGE_SIZE           4096
#define EFI_PAGE_MASK           0xFFF
#define EFI_PAGE_SHIFT          12

#define EFI_SIZE_TO_PAGES(a)    ( ((a) >> EFI_PAGE_SHIFT) + ((a) & EFI_PAGE_MASK ? 1 : 0) )

#define EFI_MEMORY_UC           0x0000000000000001
#define EFI_MEMORY_WC           0x0000000000000002
#define EFI_MEMORY_WT           0x0000000000000004
#define EFI_MEMORY_WB           0x0000000000000008
#define EFI_MEMORY_UCE          0x0000000000000010
#define EFI_MEMORY_WP           0x0000000000001000
#define EFI_MEMORY_RP           0x0000000000002000
#define EFI_MEMORY_XP           0x0000000000004000
#define EFI_MEMORY_RUNTIME      0x8000000000000000
#define EFI_MEMORY_DESCRIPTOR_VERSION  1

#define EVT_TIMER                           0x80000000
#define EVT_RUNTIME                         0x40000000
#define EVT_RUNTIME_CONTEXT                 0x20000000

#define EVT_NOTIFY_WAIT                     0x00000100
#define EVT_NOTIFY_SIGNAL                   0x00000200

#define EVT_SIGNAL_EXIT_BOOT_SERVICES       0x00000201
#define EVT_SIGNAL_VIRTUAL_ADDRESS_CHANGE   0x60000202

#define EVT_EFI_SIGNAL_MASK                 0x000000FF
#define EVT_EFI_SIGNAL_MAX                  4

#define EFI_EVENT_TIMER                         EVT_TIMER
#define EFI_EVENT_RUNTIME                       EVT_RUNTIME
#define EFI_EVENT_RUNTIME_CONTEXT               EVT_RUNTIME_CONTEXT
#define EFI_EVENT_NOTIFY_WAIT                   EVT_NOTIFY_WAIT
#define EFI_EVENT_NOTIFY_SIGNAL                 EVT_NOTIFY_SIGNAL
#define EFI_EVENT_SIGNAL_EXIT_BOOT_SERVICES     EVT_SIGNAL_EXIT_BOOT_SERVICES
#define EFI_EVENT_SIGNAL_VIRTUAL_ADDRESS_CHANGE EVT_SIGNAL_VIRTUAL_ADDRESS_CHANGE
#define EFI_EVENT_EFI_SIGNAL_MASK               EVT_EFI_SIGNAL_MASK
#define EFI_EVENT_EFI_SIGNAL_MAX                EVT_EFI_SIGNAL_MAX

#define EFI_OPEN_PROTOCOL_BY_HANDLE_PROTOCOL  0x00000001
#define EFI_OPEN_PROTOCOL_GET_PROTOCOL        0x00000002
#define EFI_OPEN_PROTOCOL_TEST_PROTOCOL       0x00000004
#define EFI_OPEN_PROTOCOL_BY_CHILD_CONTROLLER 0x00000008
#define EFI_OPEN_PROTOCOL_BY_DRIVER           0x00000010
#define EFI_OPEN_PROTOCOL_EXCLUSIVE           0x00000020

#define EFI_OPTIONAL_PTR            0x00000001
#define EFI_INTERNAL_FNC            0x00000002
#define EFI_INTERNAL_PTR            0x00000004

#define EFI_GLOBAL_VARIABLE             { 0x8BE4DF61, 0x93CA, 0x11d2, {0xAA, 0x0D, 0x00, 0xE0, 0x98, 0x03, 0x2B, 0x8C} }
#define EFI_VARIABLE_NON_VOLATILE                          0x00000001
#define EFI_VARIABLE_BOOTSERVICE_ACCESS                    0x00000002
#define EFI_VARIABLE_RUNTIME_ACCESS                        0x00000004
#define EFI_VARIABLE_HARDWARE_ERROR_RECORD                 0x00000008
#define EFI_VARIABLE_AUTHENTICATED_WRITE_ACCESS            0x00000010
#define EFI_VARIABLE_TIME_BASED_AUTHENTICATED_WRITE_ACCESS 0x00000020
#define EFI_VARIABLE_APPEND_WRITE                          0x00000040
#define EFI_MAXIMUM_VARIABLE_SIZE           1024

#define CAPSULE_FLAGS_PERSIST_ACROSS_RESET    0x00010000
#define CAPSULE_FLAGS_POPULATE_SYSTEM_TABLE   0x00020000
#define CAPSULE_FLAGS_INITIATE_RESET          0x00040000

#define MPS_TABLE_GUID                  { 0xeb9d2d2f, 0x2d88, 0x11d3, {0x9a, 0x16, 0x0, 0x90, 0x27, 0x3f, 0xc1, 0x4d} }
#define ACPI_TABLE_GUID                 { 0xeb9d2d30, 0x2d88, 0x11d3, {0x9a, 0x16, 0x0, 0x90, 0x27, 0x3f, 0xc1, 0x4d} }
#define ACPI_20_TABLE_GUID              { 0x8868e871, 0xe4f1, 0x11d3, {0xbc, 0x22, 0x0, 0x80, 0xc7, 0x3c, 0x88, 0x81} }
#define SMBIOS_TABLE_GUID               { 0xeb9d2d31, 0x2d88, 0x11d3, {0x9a, 0x16, 0x0, 0x90, 0x27, 0x3f, 0xc1, 0x4d} }
#define SMBIOS3_TABLE_GUID              { 0xf2fd1544, 0x9794, 0x4a2c, {0x99, 0x2e,0xe5, 0xbb, 0xcf, 0x20, 0xe3, 0x94} }
#define SAL_SYSTEM_TABLE_GUID           { 0xeb9d2d32, 0x2d88, 0x11d3, {0x9a, 0x16, 0x0, 0x90, 0x27, 0x3f, 0xc1, 0x4d} }

#define EFI_RUNTIME_SERVICES_SIGNATURE  0x56524553544e5552
#define EFI_RUNTIME_SERVICES_REVISION   (EFI_SPECIFICATION_MAJOR_REVISION<<16) | (EFI_SPECIFICATION_MINOR_REVISION)

#define EFI_BOOT_SERVICES_SIGNATURE     0x56524553544f4f42
#define EFI_BOOT_SERVICES_REVISION      (EFI_SPECIFICATION_MAJOR_REVISION<<16) | (EFI_SPECIFICATION_MINOR_REVISION)

#define EFI_SYSTEM_TABLE_SIGNATURE      0x5453595320494249
#define EFI_SYSTEM_TABLE_REVISION       (EFI_SPECIFICATION_MAJOR_REVISION<<16) | (EFI_SPECIFICATION_MINOR_REVISION)

/* eficon.h */
#define EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL_GUID { 0x387477c2, 0x69c7, 0x11d2, {0x8e, 0x39, 0x0, 0xa0, 0xc9, 0x69, 0x72, 0x3b} }
#define EFI_BLACK   0x00
#define EFI_BLUE    0x01
#define EFI_GREEN   0x02
#define EFI_CYAN            (EFI_BLUE | EFI_GREEN)
#define EFI_RED     0x04
#define EFI_MAGENTA         (EFI_BLUE | EFI_RED)
#define EFI_BROWN           (EFI_GREEN | EFI_RED)
#define EFI_LIGHTGRAY       (EFI_BLUE | EFI_GREEN | EFI_RED)
#define EFI_BRIGHT  0x08
#define EFI_DARKGRAY        (EFI_BRIGHT)
#define EFI_LIGHTBLUE       (EFI_BLUE | EFI_BRIGHT)
#define EFI_LIGHTGREEN      (EFI_GREEN | EFI_BRIGHT)
#define EFI_LIGHTCYAN       (EFI_CYAN | EFI_BRIGHT)
#define EFI_LIGHTRED        (EFI_RED | EFI_BRIGHT)
#define EFI_LIGHTMAGENTA    (EFI_MAGENTA | EFI_BRIGHT)
#define EFI_YELLOW          (EFI_BROWN | EFI_BRIGHT)
#define EFI_WHITE           (EFI_BLUE | EFI_GREEN | EFI_RED | EFI_BRIGHT)
#define EFI_TEXT_ATTR(f,b)  ((f) | ((b) << 4))
#define EFI_BACKGROUND_BLACK        0x00
#define EFI_BACKGROUND_BLUE         0x10
#define EFI_BACKGROUND_GREEN        0x20
#define EFI_BACKGROUND_CYAN         (EFI_BACKGROUND_BLUE | EFI_BACKGROUND_GREEN)
#define EFI_BACKGROUND_RED          0x40
#define EFI_BACKGROUND_MAGENTA      (EFI_BACKGROUND_BLUE | EFI_BACKGROUND_RED)
#define EFI_BACKGROUND_BROWN        (EFI_BACKGROUND_GREEN | EFI_BACKGROUND_RED)
#define EFI_BACKGROUND_LIGHTGRAY    (EFI_BACKGROUND_BLUE | EFI_BACKGROUND_GREEN | EFI_BACKGROUND_RED)
#define BOXDRAW_HORIZONTAL                  0x2500
#define BOXDRAW_VERTICAL                    0x2502
#define BOXDRAW_DOWN_RIGHT                  0x250c
#define BOXDRAW_DOWN_LEFT                   0x2510
#define BOXDRAW_UP_RIGHT                    0x2514
#define BOXDRAW_UP_LEFT                     0x2518
#define BOXDRAW_VERTICAL_RIGHT              0x251c
#define BOXDRAW_VERTICAL_LEFT               0x2524
#define BOXDRAW_DOWN_HORIZONTAL             0x252c
#define BOXDRAW_UP_HORIZONTAL               0x2534
#define BOXDRAW_VERTICAL_HORIZONTAL         0x253c
#define BOXDRAW_DOUBLE_HORIZONTAL           0x2550
#define BOXDRAW_DOUBLE_VERTICAL             0x2551
#define BOXDRAW_DOWN_RIGHT_DOUBLE           0x2552
#define BOXDRAW_DOWN_DOUBLE_RIGHT           0x2553
#define BOXDRAW_DOUBLE_DOWN_RIGHT           0x2554
#define BOXDRAW_DOWN_LEFT_DOUBLE            0x2555
#define BOXDRAW_DOWN_DOUBLE_LEFT            0x2556
#define BOXDRAW_DOUBLE_DOWN_LEFT            0x2557
#define BOXDRAW_UP_RIGHT_DOUBLE             0x2558
#define BOXDRAW_UP_DOUBLE_RIGHT             0x2559
#define BOXDRAW_DOUBLE_UP_RIGHT             0x255a
#define BOXDRAW_UP_LEFT_DOUBLE              0x255b
#define BOXDRAW_UP_DOUBLE_LEFT              0x255c
#define BOXDRAW_DOUBLE_UP_LEFT              0x255d
#define BOXDRAW_VERTICAL_RIGHT_DOUBLE       0x255e
#define BOXDRAW_VERTICAL_DOUBLE_RIGHT       0x255f
#define BOXDRAW_DOUBLE_VERTICAL_RIGHT       0x2560
#define BOXDRAW_VERTICAL_LEFT_DOUBLE        0x2561
#define BOXDRAW_VERTICAL_DOUBLE_LEFT        0x2562
#define BOXDRAW_DOUBLE_VERTICAL_LEFT        0x2563
#define BOXDRAW_DOWN_HORIZONTAL_DOUBLE      0x2564
#define BOXDRAW_DOWN_DOUBLE_HORIZONTAL      0x2565
#define BOXDRAW_DOUBLE_DOWN_HORIZONTAL      0x2566
#define BOXDRAW_UP_HORIZONTAL_DOUBLE        0x2567
#define BOXDRAW_UP_DOUBLE_HORIZONTAL        0x2568
#define BOXDRAW_DOUBLE_UP_HORIZONTAL        0x2569
#define BOXDRAW_VERTICAL_HORIZONTAL_DOUBLE  0x256a
#define BOXDRAW_VERTICAL_DOUBLE_HORIZONTAL  0x256b
#define BOXDRAW_DOUBLE_VERTICAL_HORIZONTAL  0x256c
#define BLOCKELEMENT_FULL_BLOCK             0x2588
#define BLOCKELEMENT_LIGHT_SHADE            0x2591
#define GEOMETRICSHAPE_UP_TRIANGLE          0x25b2
#define GEOMETRICSHAPE_RIGHT_TRIANGLE       0x25ba
#define GEOMETRICSHAPE_DOWN_TRIANGLE        0x25bc
#define GEOMETRICSHAPE_LEFT_TRIANGLE        0x25c4
#define ARROW_UP                            0x2191
#define ARROW_DOWN                          0x2193

#define EFI_SIMPLE_TEXT_INPUT_PROTOCOL_GUID { 0x387477c1, 0x69c7, 0x11d2, {0x8e, 0x39, 0x0, 0xa0, 0xc9, 0x69, 0x72, 0x3b} }
#define CHAR_NULL                       0x0000
#define CHAR_BACKSPACE                  0x0008
#define CHAR_TAB                        0x0009
#define CHAR_LINEFEED                   0x000A
#define CHAR_CARRIAGE_RETURN            0x000D
#define SCAN_NULL                       0x0000
#define SCAN_UP                         0x0001
#define SCAN_DOWN                       0x0002
#define SCAN_RIGHT                      0x0003
#define SCAN_LEFT                       0x0004
#define SCAN_HOME                       0x0005
#define SCAN_END                        0x0006
#define SCAN_INSERT                     0x0007
#define SCAN_DELETE                     0x0008
#define SCAN_PAGE_UP                    0x0009
#define SCAN_PAGE_DOWN                  0x000A
#define SCAN_F1                         0x000B
#define SCAN_F2                         0x000C
#define SCAN_F3                         0x000D
#define SCAN_F4                         0x000E
#define SCAN_F5                         0x000F
#define SCAN_F6                         0x0010
#define SCAN_F7                         0x0011
#define SCAN_F8                         0x0012
#define SCAN_F9                         0x0013
#define SCAN_F10                        0x0014
#define SCAN_F11                        0x0015
#define SCAN_F12                        0x0016
#define SCAN_ESC                        0x0017

/* efigpt.h */
#define PRIMARY_PART_HEADER_LBA         1
#define EFI_PTAB_HEADER_ID  "EFI PART"
#define EFI_PART_USED_BY_EFI            0x0000000000000001
#define EFI_PART_REQUIRED_TO_FUNCTION   0x0000000000000002
#define EFI_PART_USED_BY_OS             0x0000000000000004
#define EFI_PART_REQUIRED_BY_OS         0x0000000000000008
#define EFI_PART_BACKUP_REQUIRED        0x0000000000000010
#define EFI_PART_USER_DATA              0x0000000000000020
#define EFI_PART_CRITICAL_USER_DATA     0x0000000000000040
#define EFI_PART_REDUNDANT_PARTITION    0x0000000000000080
#define EFI_PART_TYPE_UNUSED_GUID           { 0x00000000, 0x0000, 0x0000, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00} }
#define EFI_PART_TYPE_EFI_SYSTEM_PART_GUID  { 0xc12a7328, 0xf81f, 0x11d2, {0xba, 0x4b, 0x00, 0xa0, 0xc9, 0x3e, 0xc9, 0x3b} }
#define EFI_PART_TYPE_LEGACY_MBR_GUID       { 0x024dee41, 0x33e7, 0x11d3, {0x9d, 0x69, 0x00, 0x08, 0xc7, 0x81, 0xf3, 0x9f} }

/* Protocol GUIDs */
#define INTERNAL_SHELL_GUID         { 0xd65a6b8c, 0x71e5, 0x4df0, {0xa9, 0x09, 0xf0, 0xd2, 0x99, 0x2b, 0x5a, 0xa9} }

// EfiAllocateType
#define AllocateAnyPages 0
#define AllocateMaxAddress 1
#define AllocateAddress 2
#define MaxAllocateType 3

// efi_memory_type_t
#define EfiReservedMemoryType 0
#define EfiLoaderCode 1
#define EfiLoaderData 2
#define EfiBootServicesCode 3
#define EfiBootServicesData 4
#define EfiRuntimeServicesCode 5
#define EfiRuntimeServicesData 6 
#define EfiConventionalMemory 7 
#define EfiUnusableMemory 8
#define EfiACPIReclaimMemory 9
#define EfiACPIMemoryNVS 10
#define EfiMemoryMappedIO 11
#define EfiMemoryMappedIOPortSpace 12
#define EfiPalCode 13
#define EfiPersistentMemory 14
#define EfiUnacceptedMemoryType 15
#define EfiMaxMemoryType 16

// efi_timer_delay_t;
#define TimerCancel 0
#define TimerPeriodic 1
#define TimerRelative 2
#define TimerTypeMax 3

// efi_locate_search_type_t;
#define AllHandles 0
#define ByRegisterNotify 1
#define ByProtocol 2

// EfiResetType;
#define EfiResetCold 0
#define EfiResetWarm 1
#define EfiResetShutdown 2


/*** standard input, output and error streams via ConIn, ConOut and StdErr ***/
class EfiInputType {
    U16 ScanCode;
    U16 UnicodeChar;
};

public _extern U64 efi_input_reset_t(U8 *This, Bool ExtendedVerification);
public _extern U64 efi_input_read_key_t(U8 *This, EfiInputType *Key);

class EfiSimpleInputInterface {
    U64 (*Reset)();
    U64 (*ReadKeyStroke)();
    U8 * WaitForKey;
};

public _extern U64 efi_text_reset_t(U8 *This, Bool ExtendedVerification);
public _extern U64 efi_text_output_string_t(U8 *This, U16 *String);
public _extern U64 efi_text_test_string_t(U8 *This, U16 *String);
public _extern U64 efi_text_query_mode_t(U8 *This, U64 ModeNumber, U64 *Column, U64 *Row);
public _extern U64 efi_text_set_mode_t(U8 *This, U64 ModeNumber);
public _extern U64 efi_text_set_attribute_t(U8 *This, U64 Attribute);
public _extern U64 efi_text_clear_screen_t(U8 *This);
public _extern U64 efi_text_set_cursor_t(U8 *This, U64 Column, U64 Row);
public _extern U64 efi_text_enable_cursor_t(U8 *This,  Bool Enable);

class EfiSimpleTextOutputMode {
    I32 MaxMode;
    I32 Mode;
    I32 Attribute;
    I32 CursorColumn;
    I32 CursorRow;
    Bool CursorVisible;
};

class EfiSimpleTextOutputInterface {
    U64 (*Reset)();
    U64 (*OutputString)();
    U64 (*TestString)();
    U64 (*QueryMode)();
    U64 (*SetMode)();
    U64 (*SetAttribute)();
    U64 (*ClearScreen)();
    U64 (*SetCursorPosition)();
    U64 (*EnableCursor)();
    EfiSimpleTextOutputMode   *Mode;
};

/*** Runtime Services ***/
class EfiTime {
    U16 Year;       /* 1998 - 2XXX */
    U8 Month;      /* 1 - 12 */
    U8 Day;        /* 1 - 31 */
    U8 Hour;       /* 0 - 23 */
    U8 Minute;     /* 0 - 59 */
    U8 Second;     /* 0 - 59 */
    U8 Pad1;
    U32 Nanosecond; /* 0 - 999,999,999 */
    I16 TimeZone;   /* -1440 to 1440 or 2047 */
    U8 Daylight;
    U8 Pad2;
};

class EfiTimeCapabilities {
    U32 Resolution;
    U32 Accuracy;
    Bool SetsToZero;
};

class EfiCapsuleHeader {
    EfiGuid  CapsuleGuid;
    U32 HeaderSize;
    U32 Flags;
    U32 CapsuleImageSize;
};

class EfiCapsuleBlockDescriptor {
    U64 Length;
    U8 *  ContinuationPointer;
};

public _extern U64 efi_get_time_t(EfiTime *Time, EfiTimeCapabilities *Capabilities);
public _extern U64 efi_set_time_t(EfiTime *Time);
public _extern U64 efi_get_wakeup_time_t(Bool *Enable, Bool *Pending, EfiTime *Time);
public _extern U64 efi_set_wakeup_time_t(Bool Enable, EfiTime *Time);
public _extern U64 efi_set_virtual_address_map_t(U64 MemoryMapSize, U64 DescriptorSize,
    U32 DescriptorVersion, EfiMemoryDescriptor *VirtualMap);
public _extern U64 efi_convert_pointer_t(U64 DebugDisposition, U8 **Address);
public _extern U64 efi_get_variable_t(U16 *VariableName, EfiGuid *VendorGuid, U32 *Attributes,
    U64 *DataSize, U8 *Data);
public _extern U64 efi_get_next_variable_name_t(U64 *VariableNameSize, U16 *VariableName,
    EfiGuid *VendorGuid);
public _extern U64 efi_set_variable_t(U16 *VariableName, EfiGuid *VendorGuid, U32 Attributes,
    U64 DataSize, U8 *Data);
public _extern U64 efi_get_next_high_mono_t(U64 *Count);
public _extern U64 efi_reset_system_t(/* EfiResetType */ U32 ResetType, U64 ResetStatus, U64 DataSize,
    U16 *ResetData);
public _extern U64 efi_update_capsule_t(EfiCapsuleHeader **CapsuleHeaderArray, U64 CapsuleCount,
    U8 * ScatterGatherList);
public _extern U64 efi_query_capsule_capabilities_t(EfiCapsuleHeader **CapsuleHeaderArray, U64 CapsuleCount,
    U64 *MaximumCapsuleSize, /*EfiResetType */ U32 *ResetType);
public _extern U64 efi_query_variable_info_t(U32 Attributes, U64 *MaximumVariableStorageSize,
    U64 *RemainingVariableStorageSize, U64 *MaximumVariableSize);

class EfiRuntimeServices {
    EfiTableHeader Hdr;

    U64 (*GetTime)();
    U64 (*SetTime)();
    U64 (*GetWakeupTime)();
    U64 (*SetWakeupTime)();

    U64 (*SetVirtualAddressMap)();
    U64 (*ConvertPointer)();

    U64 (*GetVariable)();
    U64 (*GetNextVariableName)();
    U64 (*SetVariable)();

    U64 (*GetNextHighMonotonicCount)();
    U64 (*ResetSystem)();

    U64 (*UpdateCapsule)();
    U64 (*QueryCapsuleCapabilities)();
    U64 (*QueryVariableInfo)();
};

extern EfiRuntimeServices *RT;

/** Boot Services ***/
class EfiOpenProtocolInfoEntry {
    U8 * AgentHandle;
    U8 * ControllerHandle;
    U32 Attributes;
    U32 OpenCount;
};

public _extern U64 efi_raise_tpl_t(U64 NewTpl);
public _extern U64 efi_restore_tpl_t(U64 OldTpl);
public _extern U64 efi_allocate_pages_t(EfiAllocateType Type, /*efi_memory_type_t*/ U32 MemoryType,
    U64 NoPages, U8 * *Memory);
public _extern U64 efi_free_pages_t(U8 * Memory, U64 NoPages);
public _extern U64 efi_get_memory_map_t(U64 *MemoryMapSize, EfiMemoryDescriptor *MemoryMap,
    U64 *MapKey, U64 *DescriptorSize, U32 *DescriptorVersion);
public _extern U64 efi_allocate_pool_t(/*efi_memory_type_t*/ U32 PoolType, U64 Size, U8 **Buffer);
public _extern U64 efi_free_pool_t(U8 *Buffer);
U0 (*efi_event_notify_t)(U8 * Event, U8 *Context);
public _extern U64 efi_create_event_t(U32 Type, U64 NotifyTpl, /*efi_event_notify_t*/ U32 NotifyFunction,
    U8 *NextContext, U8 * *Event);
public _extern U64 efi_set_timer_t(U8 * Event, /*efi_timer_delay_t*/ U32 Type, U64 TriggerTime);
public _extern U64 efi_wait_for_event_t(U64 NumberOfEvents, U8 * *Event, U64 *Index);
public _extern U64 efi_signal_event_t(U8 * Event);
public _extern U64 efi_close_event_t(U8 * Event);
public _extern U64 efi_check_event_t(U8 * Event);
public _extern U64 efi_handle_protocol_t(U8 * Handle, EfiGuid *Protocol, U8 **Interface);
public _extern U64 efi_register_protocol_notify_t(EfiGuid *Protocol, U8 * Event, U8 **Registration);
public _extern U64 efi_locate_handle_t(/*efi_locate_search_type_t*/ U32 SearchType, EfiGuid *Protocol,
    U8 *SearchKey, U64 *BufferSize, U8 * *Buffer);
public _extern U64 efi_locate_device_path_t(EfiGuid *Protocol, EfiDevicePath **DevicePath,
    U8 * *Device);
public _extern U64 efi_install_configuration_table_t(EfiGuid *Guid, U8 *Table);
public _extern U64 efi_image_load_t(Bool BootPolicy, U8 * ParentImageHandle, EfiDevicePath *FilePath,
    U8 *SourceBuffer, U64 SourceSize, U8 * *ImageHandle);
public _extern U64 efi_image_start_t(U8 * ImageHandle, U64 *ExitDataSize, U16 **ExitData);
public _extern U64 efi_exit_t(U8 * ImageHandle, U64 ExitStatus, U64 ExitDataSize,
    U16 *ExitData);
public _extern U64 efi_exit_boot_services_t(U8 * ImageHandle, U64 MapKey);
public _extern U64 efi_get_next_monotonic_t(U64 *Count);
public _extern U64 efi_stall_t(U64 Microseconds);
public _extern U64 efi_set_watchdog_timer_t(U64 Timeout, U64 WatchdogCode, U64 DataSize,
    U16 *WatchdogData);
public _extern U64 efi_connect_controller_t(U8 * ControllerHandle, U8 * *DriverImageHandle,
    EfiDevicePath *RemainingDevicePath, Bool Recursive);
public _extern U64 efi_disconnect_controller_t(U8 * ControllerHandle, U8 * DriverImageHandle,
    U8 * ChildHandle);
public _extern U64 efi_open_protocol_t(U8 * Handle, EfiGuid *Protocol, U8 **Interface,
    U8 * AgentHandle, U8 * ControllerHandle, U32 Attributes);
public _extern U64 efi_close_protocol_t(U8 * Handle, EfiGuid *Protocol, U8 * AgentHandle,
    U8 * ControllerHandle);
public _extern U64 efi_open_protocol_information_t(U8 * Handle, EfiGuid *Protocol,
    EfiOpenProtocolInfoEntry**EntryBuffer, U64 *EntryCount);
public _extern U64 efi_protocols_per_handle_t(U8 * Handle, EfiGuid ***ProtocolBuffer,
    U64 *ProtocolBufferCount);
public _extern U64 efi_locate_handle_buffer_t(/*efi_locate_search_type_t*/ U32 SearchType, EfiGuid *Protocol,
    U8 *SearchKey, U64 *NoHandles, U8 * **Handles);
public _extern U64 efi_locate_protocol_t(EfiGuid *Protocol, U8 *Registration, U8 **Interface);
public _extern U64 efi_calculate_crc32_t(U8 *Data, U64 DataSize, U32 *Crc32);

class EfiBootServices {
    EfiTableHeader          Hdr;

    U64 (*RaiseTPL)();
    U64 (*RestoreTPL)();

    U64 (*AllocatePages)();
    U64 (*FreePages)();
    U64 (*GetMemoryMap)();
    U64 (*AllocatePool)();
    U64 (*FreePool)();

    U64 (*CreateEvent)();
    U64 (*SetTimer)();
    U64 (*WaitForEvent)();
    U64 (*SignalEvent)();
    U64 (*CloseEvent)();
    U64 (*CheckEvent)();

    U8 *InstallProtocolInterface;       /* not defined yet */
    U8 *ReinstallProtocolInterface;
    U8 *UninstallProtocolInterface;
    U64 (*HandleProtocol)();
    U64 (*PCHandleProtocol)();
    U64 (*RegisterProtocolNotify)();
    U64 (*LocateHandle)();
    U64 (*LocateDevicePath)();
    U64 (*InstallConfigurationTable)();

    U64 (*LoadImage)();
    U64 (*StartImage)();
    U64 (*Exit)();
    U8 *UnloadImage;                    /* not defined in gnu-efi either */
    U64 (*ExitBootServices)();

    U64 (*GetNextHighMonotonicCount)();
    U64 (*Stall)();
    U64 (*SetWatchdogTimer)();

    U64 (*ConnectController)();
    U64 (*DisconnectController)();

    U64 (*OpenProtocol)();
    U64 (*CloseProtocol)();
    U64 (*OpenProtocolInformation)();

    U64 (*ProtocolsPerHandle)();
    U64 (*LocateHandleBuffer)();
    U64 (*LocateProtocol)();
    U8 *InstallMultipleProtocolInterfaces;
    U8 *UninstallMultipleProtocolInterfaces;

    U64 (*CalculateCrc32)();
};
extern EfiBootServices *BS;

/*** Loaded Image Protocol ***/
#define EFI_LOADED_IMAGE_PROTOCOL_GUID { 0x5B1B31A1, 0x9562, 0x11d2, {0x8E, 0x3F, 0x00, 0xA0, 0xC9, 0x69, 0x72, 0x3B} }
#define LOADED_IMAGE_PROTOCOL EFI_LOADED_IMAGE_PROTOCOL_GUID

#define EFI_LOADED_IMAGE_PROTOCOL_REVISION  0x1000
#define EFI_IMAGE_INFORMATION_REVISION  EFI_LOADED_IMAGE_PROTOCOL_REVISION

class EfiLoadedImageProtocol {
    U32 Revision;
    U8 * ParentHandle;
    U8 * SystemTable;
    U8 * DeviceHandle;
    EfiDevicePath *FilePath;
    U8 * Reserved;
    U32 LoadOptionsSize;
    U8 * LoadOptions;
    U8 * ImageBase;
    U64 ImageSize;
    //efi_memory_type_t       
    U32 ImageCodeType;
    //efi_memory_type_t       
    U32 ImageDataType;
};

extern EfiLoadedImageProtocol *LIP;
extern U8 * IM;

/*** System Table ***/
class EfiConfigurationTable {
    EfiGuid  VendorGuid;
    U8 * VendorTable;
};

class EfiSystemTable {
    EfiTableHeader Hdr;

    U16 *FirmwareVendor;
    U32 FirmwareRevision;

    U8 * ConsoleInHandle;
    EfiSimpleInputInterface *ConIn;

    U8 * ConsoleOutHandle;
    EfiSimpleTextOutputInterface  *ConOut;

    U8 * ConsoleErrorHandle;
    EfiSimpleTextOutputInterface  *StdErr;

    EfiRuntimeServices *RuntimeServices;
    EfiBootServices *BootServices;

    U64 NumberOfTableEntries;
    EfiConfigurationTable *ConfigurationTable;
};
extern EfiSystemTable *ST;
#define gST ST

/*** Simple File System Protocol ***/
#define EFI_SIMPLE_FILE_SYSTEM_PROTOCOL_GUID { 0x964e5b22, 0x6459, 0x11d2, {0x8e, 0x39, 0x0, 0xa0, 0xc9, 0x69, 0x72, 0x3b} }

#define EFI_SIMPLE_FILE_SYSTEM_PROTOCOL_REVISION  0x00010000

#define EFI_FILE_MODE_READ      0x0000000000000001
#define EFI_FILE_MODE_WRITE     0x0000000000000002
#define EFI_FILE_MODE_CREATE    0x8000000000000000

#define EFI_FILE_READ_ONLY      0x0000000000000001
#define EFI_FILE_HIDDEN         0x0000000000000002
#define EFI_FILE_SYSTEM         0x0000000000000004
#define EFI_FILE_RESERVED       0x0000000000000008
#define EFI_FILE_DIRECTORY      0x0000000000000010
#define EFI_FILE_ARCHIVE        0x0000000000000020
#define EFI_FILE_VALID_ATTR     0x0000000000000037

#define EFI_FILE_PROTOCOL_REVISION         0x00010000
#define EFI_FILE_HANDLE_REVISION           EFI_FILE_PROTOCOL_REVISION

#define EFI_FILE_INFO_GUID  { 0x9576e92, 0x6d3f, 0x11d2, {0x8e, 0x39, 0x0, 0xa0, 0xc9, 0x69, 0x72, 0x3b} }

#define FILENAME_MAX 262    /* from FAT spec */

class EfiFileInfo {
    U64 Size;
    U64 FileSize;
    U64 PhysicalSize;
    EfiTime CreateTime;
    EfiTime LastAccessTime;
    EfiTime ModificationTime;
    U64 Attribute;
    U16 FileName[FILENAME_MAX];
};

Class EfiFileHandle {
    U64 Revision;
    U64 (*Open)();
    U64 (*Close)();
    U64 (*Delete)();
    U64 (*Read)();
    U64 (*Write)();
    U64 (*GetPosition)();
    U64 (*SetPosition)();
    U64 (*GetInfo)();
    U64 (*SetInfo)();
    U64 (*Flush)();
};


public _extern U64 efi_volume_open_t(U8 *This, EfiFileHandle **Root);
class EfiSimpleFileSystemProtocol {
    U64 Revision;
    U64 (*OpenVolume)();
};

public _extern U64 efi_file_open_t(EfiFileHandle *File, EfiFileHandle **NewHandle, U16 *FileName,
    U64 OpenMode, U64 Attributes);
public _extern U64 efi_file_close_t(EfiFileHandle *File);
public _extern U64 efi_file_delete_t(EfiFileHandle *File);
public _extern U64 efi_file_read_t(EfiFileHandle *File, U64 *BufferSize, U8 *Buffer);
public _extern U64 efi_file_write_t(EfiFileHandle *File, U64 *BufferSize, U8 *Buffer);
public _extern U64 efi_file_get_pos_t(EfiFileHandle *File, U64 *Position);
public _extern U64 efi_file_set_pos_t(EfiFileHandle *File, U64 Position);
public _extern U64 efi_file_get_info_t(EfiFileHandle *File, EfiGuid *InformationType, U64 *BufferSize,
    U8 *Buffer);
public _extern U64 efi_file_set_info_t(EfiFileHandle *File, EfiGuid *InformationType, U64 BufferSize,
    U8 *Buffer);
public _extern U64 efi_file_flush_t(EfiFileHandle *File);


/*** Shell Parameter Protocols ***/
#define EFI_SHELL_PARAMETERS_PROTOCOL_GUID  { 0x752f3136, 0x4e16, 0x4fdc, {0xa2, 0x2a, 0xe5, 0xf4, 0x68, 0x12, 0xf4, 0xca} }

class EfiShellParametersProtocol {
    U16 **Argv;
    U64 Argc;
    U8 * StdIn;
    U8 * StdOut;
    U8 * StdErr;
};

#define SHELL_INTERFACE_PROTOCOL_GUID       { 0x47c7b223, 0xc42a, 0x11d2, {0x8e, 0x57, 0x00, 0xa0, 0xc9, 0x69, 0x72, 0x3b} }

class EfiShellInterfaceProtocol {
    U8 * ImageHandle;
    U8 * *Info;
    U16 **Argv;
    U64 Argc;
    U16 **RedirArgv;
    U64 RedirArgc;
    U8 * StdIn;
    U8 * StdOut;
    U8 * StdErr;
};

/*** Random Number Generator ***/
#define EFI_RNG_PROTOCOL_GUID               { 0x3152bca5, 0xeade, 0x433d, {0x86, 0x2e, 0xc0, 0x1c, 0xdc, 0x29, 0x1f, 0x44} }

public _extern U64 efi_rng_get_info_t(U8 *This, U64 *RNGAlgorithmListSize, EfiGuid *RNGAlgorithmList);
public _extern U64 efi_rng_get_rng_t(U8 *This, EfiGuid *RNGAlgorithm, U64 RNGValueLength, U8 *RNGValue);

class EfiRngProtocol {
    U64 (*GetInfo)();
    U64 (*GetRNG)();
};

/*** Serial IO Protocol ***/
#define EFI_SERIAL_IO_PROTOCOL_GUID { 0xBB25CF6F, 0xF1D4, 0x11D2, {0x9A, 0x0C, 0x00, 0x90, 0x27, 0x3F, 0xC1, 0xFD} }

#define SERIAL_IO_INTERFACE_REVISION                0x00010000
#define EFI_SERIAL_CLEAR_TO_SEND                    0x0010
#define EFI_SERIAL_DATA_SET_READY                   0x0020
#define EFI_SERIAL_RING_INDICATE                    0x0040
#define EFI_SERIAL_CARRIER_DETECT                   0x0080
#define EFI_SERIAL_REQUEST_TO_SEND                  0x0002
#define EFI_SERIAL_DATA_TERMINAL_READY              0x0001
#define EFI_SERIAL_INPUT_BUFFER_EMPTY               0x0100
#define EFI_SERIAL_OUTPUT_BUFFER_EMPTY              0x0200
#define EFI_SERIAL_HARDWARE_LOOPBACK_ENABLE         0x1000
#define EFI_SERIAL_SOFTWARE_LOOPBACK_ENABLE         0x2000
#define EFI_SERIAL_HARDWARE_FLOW_CONTROL_ENABLE     0x4000

//EfiParityType
#define DefaultParity 0
#define NoParity 1
#define EvenParity 2
#define OddParity 3
#define MarkParity 4
#define SpaceParity 5

// efi_stop_bits_type_t
#define DefaultStopBits 0
#define OneStopBit 1
#define OneFiveStopBits 2
#define TwoStopBits 3


class EfiSerialIoMode {
    U32 ControlMask;
    U32 Timeout;
    U64 BaudRate;
    U32 ReceiveFifoDepth;
    U32 DataBits;
    U32 Parity;
    U32 StopBits;
};

public _extern U64 efi_serial_reset_t(U8 *This);
public _extern U64 efi_serial_set_attributes_t(U8 *This, U64 BaudRate, U32 ReceiveFifoDepth,
    U32 Timeout, EfiParityType Parity, U8 DataBits, /*efi_stop_bits_type_t*/ U32 StopBits);
public _extern U64 efi_serial_set_control_bits_t(U8 *This, U32 Control);
public _extern U64 efi_serial_get_control_bits_t(U8 *This, U32 *Control);
public _extern U64 efi_serial_write_t(U8 *This, U64 *BufferSize, U8 *Buffer);
public _extern U64 efi_serial_read_t(U8 *This, U64 *BufferSize, U8 *Buffer);

class EfiSerialIoProtocol {
    U32 Revision;
    U64 (*Reset)();
    U64 (*SetAttributes)();
    U64 (*SetControl)();
    U64 (*GetControl)();
    U64 (*Write)();
    U64 (*Read)();
    EfiSerialIoMode *Mode;
};

/*** Block IO Protocol ***/
#define EFI_BLOCK_IO_PROTOCOL_GUID { 0x964e5b21, 0x6459, 0x11d2, {0x8e, 0x39, 0x0, 0xa0, 0xc9, 0x69, 0x72, 0x3b} }
#define EFI_BLOCK_IO_PROTOCOL_REVISION    0x00010000
#define EFI_BLOCK_IO_INTERFACE_REVISION   EFI_BLOCK_IO_PROTOCOL_REVISION

class EfiBlockIoMedia {
    U32MediaId;
    Bool RemovableMedia;
    Bool MediaPresent;
    Bool LogicalPartition;
    Bool ReadOnly;
    Bool WriteCaching;
    U32 BlockSize;
    U32 IoAlign;
    U64 LastBlock;
};

public _extern U64 efi_block_reset_t(U8 *This, Bool ExtendedVerification);
public _extern U64 efi_block_read_t(U8 *This, U32 MediaId, U64 LBA, U64 BufferSize, U8 *Buffer);
public _extern U64 efi_block_write_t(U8 *This, U32 MediaId, U64 LBA, U64 BufferSize, U8 *Buffer);
public _extern U64 efi_block_flush_t(U8 *This);

class EfiBlockIo {
    U64 Revision;
    EfiBlockIoMedia *Media;
    U64 (*Reset)();
    U64 (*ReadBlocks)();
    U64 (*WriteBlocks)();
    U64 (*FlushBlocks)();
};

class EfiBlockFile {
    U64 offset;
    EfiBlockIo *bio;
};

/*** Graphics Output Protocol (not used, but could be useful to have) ***/
#define EFI_GRAPHICS_OUTPUT_PROTOCOL_GUID { 0x9042a9de, 0x23dc, 0x4a38, {0x96, 0xfb, 0x7a, 0xde, 0xd0, 0x80, 0x51, 0x6a } }

// efi_gop_pixel_format_t
#define PixelRedGreenBlueReserved8BitPerColor 0
#define PixelBlueGreenRedReserved8BitPerColor 1
#define PixelBitMask 2
#define PixelBltOnly 3
#define PixelFormatMax 4

// efi_gop_blt_operation_t;
#define EfiBltVideoFill 0
#define EfiBltVideoToBltBuffer 1
#define EfiBltBufferToVideo 2
#define EfiBltVideoToVideo 3
#define EfiGraphicsOutputBltOperationMax 4
 

class EfiGopPixelBitmask {
  U32 RedMask;
  U32 GreenMask;
  U32 BlueMask;
  U32 ReservedMask;
};

class EfiGopModeInfo {
    U32 Version;
    U32 HorizontalResolution;
    U32 VerticalResolution;
    //efi_gop_pixel_format_t  
    u32 PixelFormat;
    EfiGopPixelBitmask PixelInformation;
    U32 PixelsPerScanLine;
};

class EfiGopMode {
    U32 MaxMode;
    U32 Mode;
    EfiGopModeInfo *Information;
    U64 SizeOfInfo;
    U8 * FrameBufferBase;
    U64 FrameBufferSize;
};

public _extern U64 efi_gop_query_mode_t(U8 *This, U32 ModeNumber, U64 *SizeOfInfo,
    EfiGopModeInfo **Info);
public _extern U64 efi_gop_set_mode_t(U8 *This, U32 ModeNumber);
public _extern U64 efi_gop_blt_t(U8 *This, U32 *BltBuffer, /*efi_gop_blt_operation_t*/ U32 BltOperation,
    U64 SourceX, U64 SourceY, U64 DestinationX, U64 DestionationY, U64 Width, U64 Height, U64 Delta);

class efi_gop_t {
    U64 (*QueryMode)();
    U64 (*SetMode)();
    U64 (*Blt)();
    EfiGopMode *Mode;
};

/*** Simple Pointer Protocol (not used, but could be useful to have) ***/
#define EFI_SIMPLE_POINTER_PROTOCOL_GUID { 0x31878c87, 0xb75, 0x11d5, { 0x9a, 0x4f, 0x0, 0x90, 0x27, 0x3f, 0xc1, 0x4d } }

class EfiSimplePointerState {
    I32 RelativeMovementX;
    I32 RelativeMovementY;
    I32 RelativeMovementZ;
    Bool LeftButton;
    Bool RightButton;
};

class EfiSimplePointerMode {
    U64 ResolutionX;
    U64 ResolutionY;
    U64 ResolutionZ;
    Bool LeftButton;
    Bool RightButton;
};

public _extern U64 efi_simple_pointer_reset_t (U8 *This, Bool ExtendedVerification);
public _extern U64 efi_simple_pointer_get_state_t (U8 *This, EfiSimplePointerState *State);

class EfiSimplePointerProtocol {
    U64 (*Reset)();
    U64 (*GetState)();
    U8 * WaitForInput;
    EfiSimplePointerMode *Mode;
};

/*** Option ROM Protocol (not used, but could be useful to have) ***/
#define EFI_PCI_OPTION_ROM_TABLE_GUID { 0x7462660f, 0x1cbd, 0x48da, {0xad, 0x11, 0x91, 0x71, 0x79, 0x13, 0x83, 0x1c} }

class EfiPciOptionRomDescriptor {
  U8 * RomAddress;
  //efi_memory_type_t                 
  U32 MemoryType;
  U32 RomLength;
  U32 Seg;
  U8 Bus;
  U8 Dev;
  U8 Func;
  Bool ExecutedLegacyBiosImage;
  Bool DontLoadEfiRom;
};

class EfiPciOptionRomTable {
  U64 PciOptionRomCount;
  EfiPciOptionRomDescriptor   *PciOptionRomDescriptors;
};

/*** GPT partitioning table (not used, but could be useful to have) ***/
class EfiPartitionTableHeader {
    EfiTableHeader  Header;
    U64 MyLBA;
    U64 AlternateLBA;
    U64 FirstUsableLBA;
    U64 LastUsableLBA;
    EfiGuid DiskGUID;
    U64 PartitionEntryLBA;
    U32 NumberOfPartitionEntries;
    U32 SizeOfPartitionEntry;
    U32 PartitionEntryArrayCRC32;
};

class EfiPartitionEntry {
    EfiGuid PartitionTypeGUID;
    EfiGuid UniquePartitionGUID;
    U64 StartingLBA;
    U64 EndingLBA;
    U64 Attributes;
    U16 PartitionName[36];
};
