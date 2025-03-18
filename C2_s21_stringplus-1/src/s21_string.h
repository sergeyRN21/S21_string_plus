#ifndef S21_STRING_H
#define S21_STRING_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#define s21_NULL ((void *)0)
typedef unsigned long s21_size_t;

typedef struct modifier {
  int minus, space, width, h, l, point;
  int accuracy;
  char plus;
  char part[50000];
} modifier;

// sergey
void *s21_memchr(const void *str, int c, s21_size_t n);
char *s21_strchr(const char *str, int c);
char *s21_strrchr(const char *str, int c);

// maksim
s21_size_t s21_strcspn(
    const char *str1,
    const char *str2);  // сделано, удалить функции из оригинальной string.h
char *s21_strstr(
    const char *haystack,
    const char *needle);  // сделано, удалить функции из оригинальной string.h
char *s21_strtok(
    char *str,
    const char *delim);  // сделано, удалить функции из оригинальной string.h

// arina
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);

// ashot
int s21_memcmp(char *s1, char *s2, s21_size_t n);
int s21_strncmp(char *s1, char *s2, s21_size_t n);
char *s21_strerror(int errnum);

// rinat
char *s21_strncat(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strlen(const char *str);
char *s21_strpbrk(const char *str1, const char *str2);

// s21_sprintf arina
int s21_sprintf(char *str, const char *format, ...);
int s21_flags(const char *format, s21_size_t *i, modifier *format_mod);
int s21_take_width(const char *format, s21_size_t *i);
void s21_specifier_parser(char *str, const char *format, va_list str_parametr,
                          s21_size_t *i, int *count_smbl, modifier *format_mod);
wchar_t s21_c_value(modifier *format_mod, va_list str_parametr);
int s21_s_value(modifier *format_mod, va_list str_parametr, wchar_t **s,
                char **s1);
void s21_s_per_str(modifier *format_mod, char *str, int len, wchar_t *s,
                   char *s1, int *count_smbls);
void s21_width(char *str, int *count_smbls, int width);
long int s21_d_value(modifier *format_mod, va_list str_parametr);
void s21_d_flag(long int d, char *str, int *count_smbls, int *count_pointer,
                modifier *format_mod);
void s21_f_flag(double f, char *str, int *count_smbls, int *count_pointer,
                modifier *format_mod);
unsigned long s21_u_value(modifier *format_mod, va_list str_parametr);
void s21_num_per_str(unsigned long num, char *str, int *count_smbls,
                     int *count_pointer, modifier format_mod);
void s21_input_num(unsigned long num, char *str, int *count_smbls,
                   int *count_pointer, modifier format_mod, int diff_tochnost);
void s21_sign(char *str, int *count_smbls, modifier format_mod);
int s21_len_num(unsigned long num);
void s21_accuracy(char *str, int *count_smbls, int accuracy);
void s21_reverse(char *str, int start, int end);
void s21_freee_struct(modifier *format_mod);

void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);

#define EPERM 1               /* Operation not permitted */
#define ENOENT 2              /* No such file or directory */
#define ESRCH 3               /* No such process */
#define EINTR 4               /* Interrupted system call */
#define EIO 5                 /* I/O error */
#define ENXIO 6               /* No such device or address */
#define E2BIG 7               /* Argument list too long */
#define ENOEXEC 8             /* Exec format error */
#define EBADF 9               /* Bad file number */
#define ECHILD 10             /* No child processes */
#define EAGAIN 11             /* Try again */
#define ENOMEM 12             /* Out of memory */
#define EACCES 13             /* Permission denied */
#define EFAULT 14             /* Bad address */
#define ENOTBLK 15            /* Block device required */
#define EBUSY 16              /* Device or resource busy */
#define EEXIST 17             /* File exists */
#define EXDEV 18              /* Cross-device link */
#define ENODEV 19             /* No such device */
#define ENOTDIR 20            /* Not a directory */
#define EISDIR 21             /* Is a directory */
#define EINVAL 22             /* Invalid argument */
#define ENFILE 23             /* File table overflow */
#define EMFILE 24             /* Too many open files */
#define ENOTTY 25             /* Not a typewriter */
#define ETXTBSY 26            /* Text file busy */
#define EFBIG 27              /* File too large */
#define ENOSPC 28             /* No space left on device */
#define ESPIPE 29             /* Illegal seek */
#define EROFS 30              /* Read-only file system */
#define EMLINK 31             /* Too many links */
#define EPIPE 32              /* Broken pipe */
#define EDOM 33               /* Math argument out of domain of func */
#define ERANGE 34             /* Math result not representable */
#define EDEADLK 35            /* Resource deadlock would occur */
#define ENAMETOOLONG 36       /* File name too long */
#define ENOLCK 37             /* No record locks available */
#define ENOSYS 38             /* Function not implemented */
#define ENOTEMPTY 39          /* Directory not empty */
#define ELOOP 40              /* Too many symbolic links encountered */
#define EWOULDBLOCK EAGAIN 41 /* Operation would block */
#define ENOMSG 42             /* No message of desired type */
#define EIDRM 43              /* Identifier removed */
#define ECHRNG 44             /* Channel number out of range */
#define EL2NSYNC 45           /* Level 2 not synchronized */
#define EL3HLT 46             /* Level 3 halted */
#define EL3RST 47             /* Level 3 reset */
#define ELNRNG 48             /* Link number out of range */
#define EUNATCH 49            /* Protocol driver not attached */
#define ENOCSI 50             /* No CSI structure available */
#define EL2HLT 51             /* Level 2 halted */
#define EBADE 52              /* Invalid exchange */
#define EBADR 53              /* Invalid request descriptor */
#define EXFULL 54             /* Exchange full */
#define ENOANO 55             /* No anode */
#define EBADRQC 56            /* Invalid request code */
#define EBADSLT 57            /* Invalid slot */
#define EDEADLOCK EDEADLK 58
#define EBFONT 59          /* Bad font file format */
#define ENOSTR 60          /* Device not a stream */
#define ENODATA 61         /* No data available */
#define ETIME 62           /* Timer expired */
#define ENOSR 63           /* Out of streams resources */
#define ENONET 64          /* Machine is not on the network */
#define ENOPKG 65          /* Package not installed */
#define EREMOTE 66         /* Object is remote */
#define ENOLINK 67         /* Link has been severed */
#define EADV 68            /* Advertise error */
#define ESRMNT 69          /* Srmount error */
#define ECOMM 70           /* Communication error on send */
#define EPROTO 71          /* Protocol error */
#define EMULTIHOP 72       /* Multihop attempted */
#define EDOTDOT 73         /* RFS specific error */
#define EBADMSG 74         /* Not a data message */
#define EOVERFLOW 75       /* Value too large for defined data type */
#define ENOTUNIQ 76        /* Name not unique on network */
#define EBADFD 77          /* File descriptor in bad state */
#define EREMCHG 78         /* Remote address changed */
#define ELIBACC 79         /* Can not access a needed shared library */
#define ELIBBAD 80         /* Accessing a corrupted shared library */
#define ELIBSCN 81         /* .lib section in a.out corrupted */
#define ELIBMAX 82         /* Attempting to link in too many shared libraries */
#define ELIBEXEC 83        /* Cannot exec a shared library directly */
#define EILSEQ 84          /* Illegal byte sequence */
#define ERESTART 85        /* Interrupted system call should be restarted */
#define ESTRPIPE 86        /* Streams pipe error */
#define EUSERS 87          /* Too many users */
#define ENOTSOCK 88        /* Socket operation on non-socket */
#define EDESTADDRREQ 89    /* Destination address required */
#define EMSGSIZE 90        /* Message too long */
#define EPROTOTYPE 91      /* Protocol wrong type for socket */
#define ENOPROTOOPT 92     /* Protocol not available */
#define EPROTONOSUPPORT 93 /* Protocol not supported */
#define ESOCKTNOSUPPORT 94 /* Socket type not supported */
#define EOPNOTSUPP 95      /* Operation not supported on transport endpoint */
#define EPFNOSUPPORT 96    /* Protocol family not supported */
#define EAFNOSUPPORT 97    /* Address family not supported by protocol */
#define EADDRINUSE 98      /* Address already in use */
#define EADDRNOTAVAIL 99   /* Cannot assign requested address */
#define ENETDOWN 100       /* Network is down */
#define ENETUNREACH 101    /* Network is unreachable */
#define ENETRESET 102      /* Network dropped connection because of reset */
#define ECONNABORTED 103   /* Software caused connection abort */
#define ECONNRESET 104     /* Connection reset by peer */
#define ENOBUFS 105        /* No buffer space available */
#define EISCONN 106        /* Transport endpoint is already connected */
#define ENOTCONN 107       /* Transport endpoint is not connected */
#define ESHUTDOWN 108      /* Cannot send after transport endpoint shutdown */
#define ETOOMANYREFS 109   /* Too many references: cannot splice */
#define ETIMEDOUT 110      /* Connection timed out */
#define ECONNREFUSED 111   /* Connection refused */
#define EHOSTDOWN 112      /* Host is down */
#define EHOSTUNREACH 113   /* No route to host */
#define EALREADY 114       /* Operation already in progress */
#define EINPROGRESS 115    /* Operation now in progress */
#define ESTALE 116         /* Stale file handle */
#define EUCLEAN 117        /* Structure needs cleaning */
#define ENOTNAM 118        /* Not a XENIX named type file */
#define ENAVAIL 119        /* No XENIX semaphores available */
#define EISNAM 120         /* Is a named type file */
#define EREMOTEIO 121      /* Remote I/O error */
#define EDQUOT 122         /* Quota exceeded */
#define ENOMEDIUM 123      /* No medium found */
#define EMEDIUMTYPE 124    /* Wrong medium type */
#define ECANCELED 125      /* Operation Canceled */
#define ENOKEY 126         /* Required key not available */
#define EKEYEXPIRED 127    /* Key has expired */
#define EKEYREVOKED 128    /* Key has been revoked */
#define EKEYREJECTED 129   /* Key was rejected by service */
#define EOWNERDEAD 130     /* Owner died */
#define ENOTRECOVERABLE 131 /* State not recoverable */
#define ERFKILL 132         /* Operation not possible due to RF-kill */
#define EHWPOISON 133       /* Memory page has hardware error */
#if defined(__APPLE__) && defined(__MACH__)
#define ERROR_MESSAGES                    \
  {"No error",                            \
   "Operation not permitted",             \
   "No such file or directory",           \
   "No such process",                     \
   "Interrupted system call",             \
   "Input/output error",                  \
   "No such device or address",           \
   "Argument list too long",              \
   "Exec format error",                   \
   "Bad file descriptor",                 \
   "No child processes",                  \
   "Resource temporarily unavailable",    \
   "Out of memory",                       \
   "Permission denied",                   \
   "Bad address",                         \
   "Block device required",               \
   "File exists",                         \
   "Invalid cross-device link",           \
   "No such device",                      \
   "Not a directory",                     \
   "Is a directory",                      \
   "Invalid argument",                    \
   "File table overflow",                 \
   "Too many open files",                 \
   "Not a typewriter",                    \
   "Text file busy",                      \
   "File too large",                      \
   "No space left on device",             \
   "Illegal seek",                        \
   "Read-only file system",               \
   "Too many links",                      \
   "Broken pipe",                         \
   "Math argument out of domain of func", \
   "Math result not representable"}
#elif defined(__linux__)
#define ERROR_MESSAGES                                  \
  {"Success",                                           \
   "Operation not permitted",                           \
   "No such file or directory",                         \
   "No such process",                                   \
   "Interrupted system call",                           \
   "Input/output error",                                \
   "No such device or address",                         \
   "Argument list too long",                            \
   "Exec format error",                                 \
   "Bad file descriptor",                               \
   "No child processes",                                \
   "Resource temporarily unavailable",                  \
   "Cannot allocate memory",                            \
   "Permission denied",                                 \
   "Bad address",                                       \
   "Block device required",                             \
   "Device or resource busy",                           \
   "File exists",                                       \
   "Invalid cross-device link",                         \
   "No such device",                                    \
   "Not a directory",                                   \
   "Is a directory",                                    \
   "Invalid argument",                                  \
   "Too many open files in system",                     \
   "Too many open files",                               \
   "Inappropriate ioctl for device",                    \
   "Text file busy",                                    \
   "File too large",                                    \
   "No space left on device",                           \
   "Illegal seek",                                      \
   "Read-only file system",                             \
   "Too many links",                                    \
   "Broken pipe",                                       \
   "Numerical argument out of domain",                  \
   "Numerical result out of range",                     \
   "Resource deadlock avoided",                         \
   "File name too long",                                \
   "No locks available",                                \
   "Function not implemented",                          \
   "Directory not empty",                               \
   "Too many levels of symbolic links",                 \
   "Unknown error 41",                                  \
   "No message of desired type",                        \
   "Identifier removed",                                \
   "Channel number out of range",                       \
   "Level 2 not synchronized",                          \
   "Level 3 halted",                                    \
   "Level 3 reset",                                     \
   "Link number out of range",                          \
   "Protocol driver not attached",                      \
   "No CSI structure available",                        \
   "Level 2 halted",                                    \
   "Invalid exchange",                                  \
   "Invalid request descriptor",                        \
   "Exchange full",                                     \
   "No anode",                                          \
   "Invalid request code",                              \
   "Invalid slot",                                      \
   "Unknown error 58",                                  \
   "Bad font file format",                              \
   "Device not a stream",                               \
   "No data available",                                 \
   "Timer expired",                                     \
   "Out of streams resources",                          \
   "Machine is not on the network",                     \
   "Package not installed",                             \
   "Object is remote",                                  \
   "Link has been severed",                             \
   "Advertise error",                                   \
   "Srmount error",                                     \
   "Communication error on send",                       \
   "Protocol error",                                    \
   "Multihop attempted",                                \
   "RFS specific error",                                \
   "Bad message",                                       \
   "Value too large for defined data type",             \
   "Name not unique on network",                        \
   "File descriptor in bad state",                      \
   "Remote address changed",                            \
   "Can not access a needed shared library",            \
   "Accessing a corrupted shared library",              \
   ".lib section in a.out corrupted",                   \
   "Attempting to link in too many shared libraries",   \
   "Cannot exec a shared library directly",             \
   "Invalid or incomplete multibyte or wide character", \
   "Interrupted system call should be restarted",       \
   "Streams pipe error",                                \
   "Too many users",                                    \
   "Socket operation on non-socket",                    \
   "Destination address required",                      \
   "Message too long",                                  \
   "Protocol wrong type for socket",                    \
   "Protocol not available",                            \
   "Protocol not supported",                            \
   "Socket type not supported",                         \
   "Operation not supported",                           \
   "Protocol family not supported",                     \
   "Address family not supported by protocol",          \
   "Address already in use",                            \
   "Cannot assign requested address",                   \
   "Network is down",                                   \
   "Network is unreachable",                            \
   "Network dropped connection on reset",               \
   "Software caused connection abort",                  \
   "Connection reset by peer",                          \
   "No buffer space available",                         \
   "Transport endpoint is already connected",           \
   "Transport endpoint is not connected",               \
   "Cannot send after transport endpoint shutdown",     \
   "Too many references: cannot splice",                \
   "Connection timed out",                              \
   "Connection refused",                                \
   "Host is down",                                      \
   "No route to host",                                  \
   "Operation already in progress",                     \
   "Operation now in progress",                         \
   "Stale file handle",                                 \
   "Structure needs cleaning",                          \
   "Not a XENIX named type file",                       \
   "No XENIX semaphores available",                     \
   "Is a named type file",                              \
   "Remote I/O error",                                  \
   "Disk quota exceeded",                               \
   "No medium found",                                   \
   "Wrong medium type",                                 \
   "Operation canceled",                                \
   "Required key not available",                        \
   "Key has expired",                                   \
   "Key has been revoked",                              \
   "Key was rejected by service",                       \
   "Owner died",                                        \
   "State not recoverable",                             \
   "Operation not possible due to RF-kill",             \
   "Memory page has hardware error"}

#endif

#endif