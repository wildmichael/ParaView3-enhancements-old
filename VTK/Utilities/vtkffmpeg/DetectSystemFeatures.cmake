# helper macro
MACRO(__set_variable_undef_or_1 __variable)
  IF(${__variable})
    SET(${__variable} 1)
  ELSE(${__variable})
    SET(${__variable})
  ENDIF(${__variable})
ENDMACRO(__set_variable_undef_or_1)

# processor architecture
SET(ARCH_X86)
SET(ARCH_X86_64)
SET(ARCH_ARMV4L)
SET(ARCH_ALPHA)
SET(ARCH_SPARC64)
SET(ARCH_SPARC)
SET(ARCH_POWERPC)
SET(ARCH_MIPS)
SET(ARCH_SH4)
SET(ARCH_PARISC)
SET(ARCH_S390)
SET(ARCH_M68K)
SET(ARCH_IA64)
SET(ARCH_BFIN)
IF(CMAKE_SYSTEM_PROCESSOR MATCHES "((i3|x)86(_64)?|athlon|i86pc|BePC|amd64)")
  IF(CMAKE_SIZEOF_VOID_P EQUAL 4)
    SET(ARCH_X86 1)
  ELSEIF(CMAKE_SIZEOF_VOID_P EQUAL 8)
    SET(ARCH_X86_64 1)
  ELSE(CMAKE_SIZEOF_VOID_P EQUAL 4)
    MESSAGE(FATAL_ERROR "Failed to determine whether the system is x86 or x86_64")
  ENDIF(CMAKE_SIZEOF_VOID_P EQUAL 4)
ELSEIF(CMAKE_SYSTEM_PROCESSOR MATCHES "arm(v4l|v5tel)?")
  SET(ARCH_ARMV4L 1)
ELSEIF(CMAKE_SYSTEM_PROCESSOR STREQUAL alpha)
  SET(ARCH_ALPHA 1)
ELSEIF(CMAKE_SYSTEM_PROCESSOR MATCHES "Power Macintosh|ppc(64)?|powerpc")
  SET(ARCH_POWERPC 1)
  SET(POWERPC_MODE_32BITS 1)
ELSEIF(CMAKE_SYSTEM_PROCESSOR MATCHES "sun4u|sparc64")
  SET(ARCH_SPARC64 1)
ELSEIF(CMAKE_SYSTEM_PROCESSOR STREQUAL sparc)
  SET(ARCH_SPARC 1)
ELSEIF(CMAKE_SYSTEM_PROCESSOR STREQUAL sh4)
  SET(ARCH_SH4 1)
ELSEIF(CMAKE_SYSTEM_PROCESSOR MATCHES "parisc(64)?")
  SET(ARCH_PARISC 1)
ELSEIF(CMAKE_SYSTEM_PROCESSOR MATCHES "s390x?")
  SET(ARCH_S390 1)
ELSEIF(CMAKE_SYSTEM_PROCESSOR STREQUAL m68k)
  SET(ARCH_M68K 1)
ELSEIF(CMAKE_SYSTEM_PROCESSOR STREQUAL ia64)
  SET(ARCH_IA64 1)
ELSEIF(CMAKE_SYSTEM_PROCESSOR STREQUAL bfin)
  SET(ARCH_BFIN 1)
ENDIF(CMAKE_SYSTEM_PROCESSOR MATCHES "((i3|x)86(_64)?|athlon|i86pc|BePC|amd64)")

INCLUDE(TestBigEndian)
TEST_BIG_ENDIAN(WORDS_BIGENDIAN)
__set_variable_undef_or_1(WORDS_BIGENDIAN)

# operating system checks
SET(CONFIG_DARWIN)
SET(CONFIG_OS2)
SET(CONFIG_SUNOS)
IF(APPLE)
  SET(CONFIG_DARWIN 1)
ELSEIF(CMAKE_SYSTEM_NAME STREQUAL OS/2)
  SET(CONFIG_OS2)
ELSEIF(CMAKE_SYSTEM_NAME STREQUAL SunOS)
  SET(CONFIG_SUNOS 1)
ENDIF(APPLE)

# inttypes checks
INCLUDE(CheckIncludeFile)
CHECK_INCLUDE_FILE(inttypes.h FOUND_INTTYPES)
IF(NOT FOUND_INTTYPES)
  SET(EMULATE_INTTYPES 1)
ENDIF(NOT FOUND_INTTYPES)

INCLUDE(CheckCSourceCompiles)
CHECK_C_SOURCE_COMPILES("#include <inttypes.h>
int main(int argc, char ** argv){
  volatile uint_fast64_t i=0x01234567;
  return 0;
}"
  FAST_INT_WORKS)
SET(EMULATE_FAST_INT)
IF(NOT FAST_INT_WORKS)
  SET(EMULATE_FAST_INT 1)
ENDIF(NOT FAST_INT_WORKS)

# check for MMX
IF(NOT APPLE)
  #does not work with Mac OS X
  SET(CMAKE_REQUIRED_FLAGS -mmmx)
  CHECK_C_SOURCE_COMPILES("#include <mmintrin.h>
  int main(void) {
  #if __GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 2)
  return 0;
  #else
  #error no MMX
  #endif
  }"
  HAVE_MMX)
ENDIF(NOT APPLE)
__set_variable_undef_or_1(HAVE_MMX)

# check for SSE vector builtins
SET(CMAKE_REQUIRED_FLAGS -msse)
CHECK_C_SOURCE_COMPILES("#include <xmmintrin.h>
int main(void) {
#if __GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 2)
  return 0;
#else
#error no vector builtins
#endif
  }"
  HAVE_BUILTIN_VECTOR)
__set_variable_undef_or_1(HAVE_BUILTIN_VECTOR)

# check for 3Dnow
SET(CMAKE_REQUIRED_FLAGS -m3dnow)
CHECK_C_SOURCE_COMPILES("#include <mm3dnow.h>
int main(void) {
#if __GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 2)
  return 0;
#else
#error no vector builtins
#endif
}"
  HAVE_MM3DNOW)
__set_variable_undef_or_1(HAVE_MM3DNOW)

# check for armv5te and iwmmxt
IF(ARCH_ARM4L)
  CHECK_C_SOURCE_COMPILES("int main(void) {
  __asm__ __volatile__ (\"qadd r0, r0, r0\");
}"
    HAVE_ARMV5TE)

  CHECK_C_SOURCE_COMPILES("int main(void) {
  __asm__ __volatile__ (\"wunpckelub wr6, wr4\");
}"
    HAVE_IWMMXT)
ENDIF(ARCH_ARM4L)
__set_variable_undef_or_1(HAVE_ARMV5TE)
__set_variable_undef_or_1(HAVE_IWMMXT)

# check for mmi
IF(ARCH_MIPS)
  SET(CMAKE_REQUIRED_FLAGS)
  CHECK_C_SOURCE_COMPILES("int main(void) {
  __asm__ (\"lq \$2, 0(\$2)\");
  return 0;
  }"
  HAVE_MMI)
ENDIF(ARCH_MIPS)
__set_variable_undef_or_1(HAVE_MMI)

# check for altivec
SET(__altivec_flags)
IF(APPLE)
  LIST(FIND CMAKE_OSX_ARCHITECTURES ppc __have_ppc)
  IF( NOT __have_ppc EQUAL -1 )
    SET(__altivec_flags -faltivec)
  ENDIF( NOT __have_ppc EQUAL -1 )
ELSEIF(ARCH_POWERPC)
  SET( __altivec_flags -maltivec -mabi=altivec)
ENDIF(APPLE)
IF(__altivec_flags)
  SET(VTK_FFMPEG_ALTIVEC_FLAGS ${__altivec_flags} CACHE STRING "Altivec flags for vtkffmpeg")
  MARK_AS_ADVANCED(VTK_FFMPEG_ALTIVEC_FLAGS)
ENDIF(__altivec_flags)
IF(ARCH_POWERPC AND NOT APPLE)
  SET(CMAKE_REQUIRED_FLAGS ${VTK_FFMPEG_ALTIVEC_FLAGS})
  CHECK_INCLUDE_FILE(altivec.h HAVE_ALTIVEC_H)
  SET(__inc_altivec)
  IF(HAVE_ALTIVEC_H)
    SET(__inc_altivec "#include <altivec.h>")
  ENDIF(HAVE_ALTIVEC_H)
  CHECK_C_SOURCE_COMPILES("${inc_altivec_h}
int main(void) {
  vector signed int v1, v2, v3;
  v1 = vec_add(v2,v3);
  return 0;
}"
    HAVE_ALTIVEC)
  SET(CMAKE_REQUIRED_FLAGS)
ENDIF(ARCH_POWERPC AND NOT APPLE)
__set_variable_undef_or_1(HAVE_ALTIVEC)
__set_variable_undef_or_1(HAVE_ALTIVEC_H)

# check for localtime_r and lrintf
INCLUDE(CheckFunctionExists)
CHECK_FUNCTION_EXISTS(localtime_r HAVE_LOCALTIME_R)
__set_variable_undef_or_1(HAVE_LOCALTIME_R)
SET(CMAKE_REQUIRED_LIBRARIES m)
CHECK_FUNCTION_EXISTS(lrintf HAVE_LRINTF)
__set_variable_undef_or_1(HAVE_LRINTF)
SET(CMAKE_REQUIRED_LIBRARIES)

# check for threading
FIND_PACKAGE(Threads)
IF(Threads_FOUND)
  IF(CMAKE_USE_WIN32_THREADS_INIT)
    SET(HAVE_W32THREADS 1)
    SET(HAVE_THREADS 1)
  ELSEIF(CMAKE_USE_PTHREADS_INIT OR CMAKE_HP_PTHREADS_INIT)
    SET(HAVE_PTHREADS 1)
    SET(HAVE_THREADS 1)
  ENDIF(CMAKE_USE_WIN32_THREADS_INIT)
ENDIF(Threads_FOUND)
__set_variable_undef_or_1(HAVE_THREADS)
__set_variable_undef_or_1(HAVE_W32THREADS)
__set_variable_undef_or_1(HAVE_PTHREADS)

SET(CMAKE_REQUIRED_FLAGS)

# check for dlopen and dlfcn
IF(CMAKE_DL_LIBS)
  SET(CMAKE_REQUIRED_LIBRARIES ${CMAKE_DL_LIBS})
  CHECK_INCLUDE_FILE(dlfcn.h CONFIG_HAVE_DLFCN)
  IF(CONFIG_HAVE_DLFCN)
    CHECK_FUNCTION_EXISTS(dlopen CONFIG_HAVE_DLOPEN)
  ENDIF(CONFIG_HAVE_DLFCN)
  SET(CMAKE_REQUIRED_LIBRARIES)
ENDIF(CMAKE_DL_LIBS)
__set_variable_undef_or_1(CONFIG_HAVE_DLOPEN)
__set_variable_undef_or_1(CONFIG_HAVE_DLFCN)

# check for malloc.h and memalign
FIND_PATH(MALLOC_H_DIR malloc.h PATH_SUFFIXES malloc)
IF(MALLOC_H_DIR)
  SET(HAVE_MALLOC_H 1)
  INCLUDE_DIRECTORIES(MALLOC_H_DIR)
  CHECK_FUNCTION_EXISTS(memalign HAVE_MEMALIGN)
ENDIF(MALLOC_H_DIR)
# if there is no memalign, disable mmx
IF(HAVE_MMX AND NOT HAVE_MEMALIGN)
  SET(HAVE_MMX)
ENDIF(HAVE_MMX AND NOT HAVE_MEMALIGN)
__set_variable_undef_or_1(HAVE_MALLOC_H)
__set_variable_undef_or_1(HAVE_MEMALIGN)

# check the restrict keyword
SET(FFMPEG_RESTRICT_KEYWORD)
FOREACH(restrict_keyword restrict __restrict__ __restrict)
  CHECK_C_SOURCE_COMPILES("void foo(char * ${restrict_keyword} p);
int main(){return 0;}"
    ${restrict_keyword}_KEYWORD)
  IF(${restrict_keyword}_KEYWORD)
    STRING(STRIP ${restrict_keyword} FFMPEG_RESTRICT_KEYWORD)
    BREAK()
  ENDIF(${restrict_keyword}_KEYWORD)
ENDFOREACH(restrict_keyword)

# is .align arg power of two?
CHECK_C_SOURCE_COMPILES("asm (\".align 3\"); int main(){return 0;}" ASMALIGN_POT)
IF(ASMALIGN_POT)
  SET(FFMPEG_ASMALIGN_MACRO "\".align \" #ZEROBITS \"\\n\\t\"")
ELSE(ASMALIGN_POT)
  SET(FFMPEG_ASMALIGN_MACRO "\".align 1<<\" #ZEROBITS \"\\n\\t\"")
ENDIF(ASMALIGN_POT)
