#ifdef HAVE_SYS_CDEFS_H
#include_next <sys/cdefs.h>
#endif

#ifndef __THROW
#define __THROW
#endif

#ifndef __BEGIN_DECLS
#define __BEGIN_DECLS
#endif

#ifndef __END_DECLS
#define __END_DECLS
#endif

#ifndef __BEGIN_NAMESPACE_STD
#define __BEGIN_NAMESPACE_STD
#endif

#ifndef __END_NAMESPACE_STD
#define __END_NAMESPACE_STD
#endif

#ifndef __flexarr
#define __flexarr [0]
#endif

#ifndef __extern_inline
#ifdef __GNUC_STDC_INLINE__
# define __extern_inline extern __inline __attribute__ ((__gnu_inline__))
# define __extern_always_inline \
  extern __always_inline __attribute__ ((__gnu_inline__))
#else
# define __extern_inline extern __inline
# define __extern_always_inline extern __always_inline
#endif
#endif

#if !defined(__REDIRECT_NTH) && defined(__GNUC__) && __GNUC__ >= 2
# ifdef __cplusplus
#  define __REDIRECT_NTH(name, proto, alias) \
     name proto __THROW __asm__ (__ASMNAME (#alias))
# else
#  define __REDIRECT_NTH(name, proto, alias) \
     name proto __asm__ (__ASMNAME (#alias)) __THROW
# endif
#endif

#ifndef __attribute_malloc__
# if defined(__GNUC__) \
    && (__GNUC__ > 2 || (__GNUC__ == 2 && __GNUC_MINOR__ >= 96))
#  define __attribute_malloc__ __attribute__ ((__malloc__))
# else
#  define __attribute_malloc__ /* Ignore */
# endif
#endif

#ifndef __attribute_alloc_size__
# if defined(__GNUC__) \
    && (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 3))
#  define __attribute_alloc_size__(...) __attribute__ ((alloc_size (__VA_ARGS__)))
# else
#  define __attribute_alloc_size__(...)
# endif
#endif

#if __GNUC_PREREQ (10, 0)
/* Designates a 1-based positional argument ref-index of pointer type
   that can be used to access size-index elements of the pointed-to
   array according to access mode, or at least one element when
   size-index is not provided:
     access (access-mode, <ref-index> [, <size-index>])  */
#  define __attr_access(x) __attribute__ ((__access__ x))
#  if __GNUC_PREREQ (11, 0)
#    define __attr_access_none(argno) __attribute__ ((__access__ (__none__, argno)))
#  else
#    define __attr_access_none(argno)
#  endif
#else
#  define __attr_access(x)
#  define __attr_access_none(argno)
#endif

