#ifndef __LILIUM_USI_INTTYPES_H_2025_05_24_14_48_37
#define __LILIUM_USI_INTTYPES_H_2025_05_24_14_48_37

#include <bits/lang-version.h>

#if !(__USE_C99 || __USE_CXX11)
#error "Requires C99 or C++11 to compile"
#endif

#include <stdint.h>

#define PRId8 "hhd"
#define PRIi8 "hhi"
#define PRIu8 "hhu"
#define PRIo8 "hho"
#define PRIx8 "hhx"
#define PRIX8 "hhX"

#define PRId16 "hd"
#define PRIi16 "hi"
#define PRIu16 "hu"
#define PRIo16 "ho"
#define PRIx16 "hx"
#define PRIX16 "hX"

#define PRId32 "d"
#define PRIi32 "i"
#define PRIu32 "u"
#define PRIo32 "o"
#define PRIx32 "x"
#define PRIX32 "X"

#define PRId64 "lld"
#define PRIi64 "lli"
#define PRIu64 "llu"
#define PRIo64 "llo"
#define PRIx64 "llx"
#define PRIX64 "llX"

#define SCNd8 "hhd"
#define SCNi8 "hhi"
#define SCNu8 "hhu"
#define SCNo8 "hho"
#define SCNx8 "hhx"
#define SCNX8 "hhX"

#define SCNd16 "hd"
#define SCNi16 "hi"
#define SCNu16 "hu"
#define SCNo16 "ho"
#define SCNx16 "hx"
#define SCNX16 "hX"

#define SCNd32 "d"
#define SCNi32 "i"
#define SCNu32 "u"
#define SCNo32 "o"
#define SCNx32 "x"
#define SCNX32 "X"

#define SCNd64 "lld"
#define SCNi64 "lli"
#define SCNu64 "llu"
#define SCNo64 "llo"
#define SCNx64 "llx"
#define SCNX64 "llX"

#define PRIdLEAST8 PRId8
#define PRIiLEAST8 PRIi8
#define PRIuLEAST8 PRIu8
#define PRIoLEAST8 PRIo8
#define PRIxLEAST8 PRIx8
#define PRIXLEAST8 PRIX8

#define SCNdLEAST8 SCNd8
#define SCNiLEAST8 SCNi8
#define SCNuLEAST8 SCNu8
#define SCNoLEAST8 SCNo8
#define SCNxLEAST8 SCNx8
#define SCNXLEAST8 SCNX8

#define PRIdFAST8 PRId8
#define PRIiFAST8 PRIi8
#define PRIuFAST8 PRIu8
#define PRIoFAST8 PRIo8
#define PRIxFAST8 PRIx8
#define PRIXFAST8 PRIX8

#define SCNdFAST8 SCNd8
#define SCNiFAST8 SCNi8
#define SCNuFAST8 SCNu8
#define SCNoFAST8 SCNo8
#define SCNxFAST8 SCNx8
#define SCNXFAST8 SCNX8

#define PRIdLEAST16 PRId16
#define PRIiLEAST16 PRIi16
#define PRIuLEAST16 PRIu16
#define PRIoLEAST16 PRIo16
#define PRIxLEAST16 PRIx16
#define PRIXLEAST16 PRIX16

#define SCNdLEAST16 SCNd16
#define SCNiLEAST16 SCNi16
#define SCNuLEAST16 SCNu16
#define SCNoLEAST16 SCNo16
#define SCNxLEAST16 SCNx16
#define SCNXLEAST16 SCNX16

#define PRIdFAST16 PRId16
#define PRIiFAST16 PRIi16
#define PRIuFAST16 PRIu16
#define PRIoFAST16 PRIo16
#define PRIxFAST16 PRIx16
#define PRIXFAST16 PRIX16

#define SCNdFAST16 SCNd16
#define SCNiFAST16 SCNi16
#define SCNuFAST16 SCNu16
#define SCNoFAST16 SCNo16
#define SCNxFAST16 SCNx16
#define SCNXFAST16 SCNX16

#define PRIdLEAST32 PRId32
#define PRIiLEAST32 PRIi32
#define PRIuLEAST32 PRIu32
#define PRIoLEAST32 PRIo32
#define PRIxLEAST32 PRIx32
#define PRIXLEAST32 PRIX32

#define SCNdLEAST32 SCNd32
#define SCNiLEAST32 SCNi32
#define SCNuLEAST32 SCNu32
#define SCNoLEAST32 SCNo32
#define SCNxLEAST32 SCNx32
#define SCNXLEAST32 SCNX32

#define PRIdFAST32 PRId32
#define PRIiFAST32 PRIi32
#define PRIuFAST32 PRIu32
#define PRIoFAST32 PRIo32
#define PRIxFAST32 PRIx32
#define PRIXFAST32 PRIX32

#define SCNdFAST32 SCNd32
#define SCNiFAST32 SCNi32
#define SCNuFAST32 SCNu32
#define SCNoFAST32 SCNo32
#define SCNxFAST32 SCNx32
#define SCNXFAST32 SCNX32

#define PRIdLEAST64 PRId64
#define PRIiLEAST64 PRIi64
#define PRIuLEAST64 PRIu64
#define PRIoLEAST64 PRIo64
#define PRIxLEAST64 PRIx64
#define PRIXLEAST64 PRIX64

#define SCNdLEAST64 SCNd64
#define SCNiLEAST64 SCNi64
#define SCNuLEAST64 SCNu64
#define SCNoLEAST64 SCNo64
#define SCNxLEAST64 SCNx64
#define SCNXLEAST64 SCNX64

#define PRIdFAST64 PRId64
#define PRIiFAST64 PRIi64
#define PRIuFAST64 PRIu64
#define PRIoFAST64 PRIo64
#define PRIxFAST64 PRIx64
#define PRIXFAST64 PRIX64

#define SCNdFAST64 SCNd64
#define SCNiFAST64 SCNi64
#define SCNuFAST64 SCNu64
#define SCNoFAST64 SCNo64
#define SCNxFAST64 SCNx64
#define SCNXFAST64 SCNX64

#define PRIdMAX "lld"
#define PRIiMAX "lli"
#define PRIuMAX "llu"
#define PRIoMAX "llo"
#define PRIxMAX "llx"
#define PRIXMAX "llX"

#define SCNdMAX "lld"
#define SCNiMAX "lli"
#define SCNuMAX "llu"
#define SCNoMAX "llo"
#define SCNxMAX "llx"
#define SCNXMAX "llX"

#define PRIdPTR "ld"
#define PRIiPTR "li"
#define PRIuPTR "lu"
#define PRIoPTR "lo"
#define PRIxPTR "lx"
#define PRIXPTR "lX"

#define SCNdPTR "ld"
#define SCNiPTR "li"
#define SCNuPTR "lu"
#define SCNoPTR "lo"
#define SCNxPTR "lx"
#define SCNXPTR "lX"

#ifdef __USE_C23 || __USE_CXX23
#define PRId128 "Ld"
#define PRIi128 "Li"
#define PRIu128 "Lu"
#define PRIo128 "Lo"
#define PRIx128 "Lx"
#define PRIX128 "LX"

#define SCNd128 "Ld"
#define SCNi128 "Li"
#define SCNu128 "Lu"
#define SCNo128 "Lo"
#define SCNx128 "Lx"
#define SCNX128 "LX"

#define PRIdLEAST128 PRId128
#define PRIiLEAST128 PRIi128
#define PRIuLEAST128 PRIu128
#define PRIoLEAST128 PRIo128
#define PRIxLEAST128 PRIx128
#define PRIXLEAST128 PRIX128

#define SCNdLEAST128 SCNd128
#define SCNiLEAST128 SCNi128
#define SCNuLEAST128 SCNu128
#define SCNoLEAST128 SCNo128
#define SCNxLEAST128 SCNx128
#define SCNXLEAST128 SCNX128

#define PRIdFAST128 PRId128
#define PRIiFAST128 PRIi128
#define PRIuFAST128 PRIu128
#define PRIoFAST128 PRIo128
#define PRIxFAST128 PRIx128
#define PRIXFAST128 PRIX128

#define SCNdFAST128 SCNd128
#define SCNiFAST128 SCNi128
#define SCNuFAST128 SCNu128
#define SCNoFAST128 SCNo128
#define SCNxFAST128 SCNx128
#define SCNXFAST128 SCNX128
#endif

__LILIUM_USI_BEGIN_CDECLS

#include <bits/div.h>

__LILIUM_USI_DEF_DIV(imax, intmax_t);

__LILIUM_USI_END_CDECLS

#endif /* __LILIUM_USI_INTTYPES_H_2025_05_24_14_48_37 */