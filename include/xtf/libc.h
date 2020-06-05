#ifndef XTF_LIBC_H
#define XTF_LIBC_H

#include <xtf/types.h>
#include <xtf/compiler.h>

/*
 * Local declaration of bits of libc
 *
 * Use __builtin_???() wherever possible, to allow gcc to perform certain
 * optimisations (e.g. constant folding) otherwise prevented by -fno-builtin.
 *
 * Where optimisations are not possible, the __builtin_???() varient will emit
 * a call to ???(), which needs implementing in common/libc/
 */

size_t strlen(const char *str);
#define strlen(s)                   __builtin_strlen(s)

char *strcpy(char *dst, const char *src);
#define strcpy(d, s)                __builtin_strcpy(d, s)

char *strncpy(char *dst, const char *src, size_t n);
#define strncpy(d, s, n)            __builtin_strncpy(d, s, n)

int strcmp(const char *s1, const char *s2);
#define strcmp(s1, s2)              __builtin_strcmp(s1, s2)

int strncmp(const char *s1, const char *s2, size_t n);
#define strncmp(s1, s2, n)          __builtin_strncmp(s1, s2, n)

void *memset(void *s, int c, size_t n);
#define memset(d, c, n)             __builtin_memset(d, c, n)

void *memcpy(void *dst, const void *src, size_t n);
#define memcpy(d, s, n)             __builtin_memcpy(d, s, n)

int memcmp(const void *s1, const void *s2, size_t n);
#define memcmp(s1, s2, n)           __builtin_memcmp(s1, s2, n)

size_t strnlen(const char *str, size_t max);

/*
 * Internal version of vsnprintf(), taking extra control flags.
 *
 * LF_TO_CRLF causes "\n" to be expanded to "\r\n" in the output buffer.
 */
#define LF_TO_CRLF (1u << 7)
int __printf(3, 0)
    vsnprintf_internal(char *buf, size_t size, const char *fmt, va_list args,
                       unsigned int flags);

static inline int __printf(3, 0)
    vsnprintf(char *buf, size_t size, const char *fmt, va_list args)
{
    return vsnprintf_internal(buf, size, fmt, args, 0);
}

int __printf(3, 4)
    snprintf(char *buf, size_t size, const char *fmt, ...);

/* Internal helpers of vsnprintf(), for custom arch formatting. */
char *fmt_number(char *str, char *end, long long val, unsigned int base,
                 int width, int precision, unsigned int flags);
char *fmt_string(char *str, char *end, const char *val,
                 int width, int precision, unsigned int flags);

/* Arch hook for vsnprintf() custom %p handling. */
bool arch_fmt_pointer(
    char **str, char *end, const char **fmt_ptr, const void *arg,
    int width, int precision, unsigned int flags);

#endif /* XTF_LIBC_H */

/*
 * Local variables:
 * mode: C
 * c-file-style: "BSD"
 * c-basic-offset: 4
 * tab-width: 4
 * indent-tabs-mode: nil
 * End:
 */
