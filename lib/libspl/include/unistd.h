/*
 * CDDL HEADER START
 *
 * The contents of this file are subject to the terms of the
 * Common Development and Distribution License, Version 1.0 only
 * (the "License").  You may not use this file except in compliance
 * with the License.
 *
 * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE
 * or http://www.opensolaris.org/os/licensing.
 * See the License for the specific language governing permissions
 * and limitations under the License.
 *
 * When distributing Covered Code, include this CDDL HEADER in each
 * file and include the License file at usr/src/OPENSOLARIS.LICENSE.
 * If applicable, add the following below this CDDL HEADER, with the
 * fields enclosed by brackets "[]" replaced with your own identifying
 * information: Portions Copyright [yyyy] [name of copyright owner]
 *
 * CDDL HEADER END
 */
/*
 * Copyright 2008 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#include_next <unistd.h>

#ifndef _LIBSPL_UNISTD_H
#define _LIBSPL_UNISTD_H

#include <zfs_config.h>

#if !defined(HAVE_IOCTL_IN_UNISTD_H)
# if defined(HAVE_IOCTL_IN_SYS_IOCTL_H)
#  include <sys/ioctl.h>
# elif defined(HAVE_IOCTL_IN_STROPTS_H)
#  include <stropts.h>
# else
#  error "System call ioctl() unavailable"
# endif
#endif

#if !defined(HAVE_ISSETUGID)
# include <sys/types.h>
# define issetugid() (geteuid() == 0 || getegid() == 0)
#endif

#if !defined(__sun__) && !defined(__sun)
/* It seems Solaris only returns positive host ids */
static inline long fake_gethostid(void)
{
	long id = gethostid();
	return id >= 0 ? id : -id;
}
#define gethostid() fake_gethostid()
#endif

#endif /* _LIBSPL_UNISTD_H */
