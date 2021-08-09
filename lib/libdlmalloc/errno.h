/* string.h stdc header
   Copyright (C) 2000, 2003 Free Software Foundation, Inc.
   Written by Stephane Carrez (stcarrez@nerim.fr)       

This file is free software; you can redistribute it and/or modify it
under the terms of the GNU General Public License as published by the
Free Software Foundation; either version 2, or (at your option) any
later version.

In addition to the permissions in the GNU General Public License, the
Free Software Foundation gives you unlimited permission to link the
compiled version of this file with other programs, and to distribute
those programs without any restriction coming from the use of this
file.  (The General Public License restrictions do apply in other
respects; for example, they cover modification of the file, and
distribution when not linked into another program.)

This file is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; see the file COPYING.  If not, write to
the Free Software Foundation, 59 Temple Place - Suite 330,
Boston, MA 02111-1307, USA.  */

#ifndef _ERRNO_H
#define _ERRNO_H


#ifdef __cplusplus
extern "C" {
#endif

#define EPERM           1               /* Operation not permitted */
#define ENOENT          2               /* No such file or directory */
#define ESRCH           3               /* No such process */
#define EINTR           4               /* Interrupted system call */
#define EIO             5               /* Input/output error */
#define ENXIO           6               /* Device not configured */
#define E2BIG           7               /* Argument list too long */
#define ENOEXEC         8               /* Exec format error */
#define EBADF           9               /* Bad file descriptor */
#define ECHILD          10              /* No child processes */
#define EDEADLK         11              /* Resource deadlock avoided */
                                        /* 11 was EAGAIN */
#define ENOMEM          12              /* Cannot allocate memory */
#define EACCES          13              /* Permission denied */
#define EFAULT          14              /* Bad address */
#ifndef _POSIX_SOURCE
#define ENOTBLK         15              /* Block device required */
#endif
#define EBUSY           16              /* Device busy */
#define EEXIST          17              /* File exists */
#define EXDEV           18              /* Cross-device link */
#define ENODEV          19              /* Operation not supported by device */
#define ENOTDIR         20              /* Not a directory */
#define EISDIR          21              /* Is a directory */
#define EINVAL          22              /* Invalid argument */
#define ENFILE          23              /* Too many open files in system */
#define EMFILE          24              /* Too many open files */
#define ENOTTY          25              /* Inappropriate ioctl for device */
#ifndef _POSIX_SOURCE
#define ETXTBSY         26              /* Text file busy */
#endif
#define EFBIG           27              /* File too large */
#define ENOSPC          28              /* No space left on device */
#define ESPIPE          29              /* Illegal seek */
#define EROFS           30              /* Read-only filesystem */
#define EMLINK          31              /* Too many links */
#define EPIPE           32              /* Broken pipe */

/* math software */
#define EDOM            33              /* Numerical argument out of domain */
#define ERANGE          34              /* Result too large */

/* non-blocking and interrupt i/o */
#define EAGAIN          35              /* Resource temporarily unavailable */
#ifndef _POSIX_SOURCE
#define EWOULDBLOCK     EAGAIN          /* Operation would block */
#define EINPROGRESS     36              /* Operation now in progress */
#define EALREADY        37              /* Operation already in progress */

/* ipc/network software -- argument errors */
#define ENOTSOCK        38              /* Socket operation on non-socket */
#define EDESTADDRREQ    39              /* Destination address required */
#define EMSGSIZE        40              /* Message too long */
#define EPROTOTYPE      41              /* Protocol wrong type for socket */
#define ENOPROTOOPT     42              /* Protocol not available */
#define EPROTONOSUPPORT 43              /* Protocol not supported */
#define ESOCKTNOSUPPORT 44              /* Socket type not supported */
#define EOPNOTSUPP      45              /* Operation not supported */
#define ENOTSUP         EOPNOTSUPP      /* Operation not supported */
#define EPFNOSUPPORT    46              /* Protocol family not supported */
#define EAFNOSUPPORT    47              /* Address family not supported by protocol family */
#define EADDRINUSE      48              /* Address already in use */
#define EADDRNOTAVAIL   49              /* Can't assign requested address */

/* ipc/network software -- operational errors */
#define ENETDOWN        50              /* Network is down */
#define ENETUNREACH     51              /* Network is unreachable */
#define ENETRESET       52              /* Network dropped connection on reset */
#define ECONNABORTED    53              /* Software caused connection abort */
#define ECONNRESET      54              /* Connection reset by peer */
#define ENOBUFS         55              /* No buffer space available */
#define EISCONN         56              /* Socket is already connected */
#define ENOTCONN        57              /* Socket is not connected */
#define ESHUTDOWN       58              /* Can't send after socket shutdown */
#define ETOOMANYREFS    59              /* Too many references: can't splice */
#define ETIMEDOUT       60              /* Operation timed out */
#define ECONNREFUSED    61              /* Connection refused */

#define ELOOP           62              /* Too many levels of symbolic links */
#endif /* _POSIX_SOURCE */
#define ENAMETOOLONG    63              /* File name too long */

/* should be rearranged */
#ifndef _POSIX_SOURCE
#define EHOSTDOWN       64              /* Host is down */
#define EHOSTUNREACH    65              /* No route to host */
#endif /* _POSIX_SOURCE */
#define ENOTEMPTY       66              /* Directory not empty */

/* quotas & mush */
#ifndef _POSIX_SOURCE
#define EPROCLIM        67              /* Too many processes */
#define EUSERS          68              /* Too many users */
#define EDQUOT          69              /* Disc quota exceeded */

/* Network File System */
#define ESTALE          70              /* Stale NFS file handle */
#define EREMOTE         71              /* Too many levels of remote in path */
#define EBADRPC         72              /* RPC struct is bad */
#define ERPCMISMATCH    73              /* RPC version wrong */
#define EPROGUNAVAIL    74              /* RPC prog. not avail */
#define EPROGMISMATCH   75              /* Program version wrong */
#define EPROCUNAVAIL    76              /* Bad procedure for program */
#endif /* _POSIX_SOURCE */

#define ENOLCK          77              /* No locks available */
#define ENOSYS          78              /* Function not implemented */

#ifndef _POSIX_SOURCE
#define EFTYPE          79              /* Inappropriate file type or format */
#define EAUTH           80              /* Authentication error */
#define ENEEDAUTH       81              /* Need authenticator */
#define EIDRM           82              /* Identifier removed */
#define ENOMSG          83              /* No message of desired type */
#define EOVERFLOW       84              /* Value too large to be stored in data type */
#define ECANCELED       85              /* Operation canceled */
#define EILSEQ          86              /* Illegal byte sequence */
#define ENOATTR         87              /* Attribute not found */

#define EDOOFUS         88              /* Programming error */

#define ELAST           88              /* Must be equal largest errno */

#endif /* _POSIX_SOURCE */

#ifdef _KERNEL
/* pseudo-errors returned inside kernel to modify return to process */
#define ERESTART        (-1)            /* restart syscall */
#define EJUSTRETURN     (-2)            /* don't modify regs, just return */
#define ENOIOCTL        (-3)            /* ioctl not handled by this layer */
#define EDIRIOCTL       (-4)            /* do direct ioctl in GEOM */
#endif

extern int errno;
  
#ifdef __cplusplus
}
#endif

#endif