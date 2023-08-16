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

#if !defined __glibc_has_attribute
/* Older glibc on host might be missing __glibc_has_attribute added in glibc-2.34 with:
   https://sourceware.org/git/?p=glibc.git;a=blobdiff;f=misc/sys/cdefs.h;h=8e244a77cf6271f09cbd26d18b1e07b1d1641404;hp=57ca262bdfb642bf4a945645532f2319ec1ff437;hb=c8ba52ab3350c334d6e34b1439a4c0c1431351f3;hpb=7dd416491e080456fc7742d884c520526509413e
*/
/* Compilers that lack __has_attribute may object to
       #if defined __has_attribute && __has_attribute (...)
   even though they do not need to evaluate the right-hand side of the &&.
   Similarly for __has_builtin, etc.  */
#if (defined __has_attribute \
     && (!defined __clang_minor__ \
         || 3 < __clang_major__ + (5 <= __clang_minor__)))
# define __glibc_has_attribute(attr) __has_attribute (attr)
#else
# define __glibc_has_attribute(attr) 0
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

#if __GNUC_PREREQ (4, 3) || __glibc_has_attribute (__cold__)
# define __COLD	__attribute__ ((__cold__))
#else
# define __COLD
#endif

/* All functions, except those with callbacks or those that
   synchronize memory, are leaf functions.  */
#if __GNUC_PREREQ (4, 6) && !defined _LIBC
# define __LEAF , __leaf__
# define __LEAF_ATTR __attribute__ ((__leaf__))
#else
# define __LEAF
# define __LEAF_ATTR
#endif

