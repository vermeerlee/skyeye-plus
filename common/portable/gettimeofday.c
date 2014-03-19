/*
	gettimeofday.c - portable gettimeofday function for skyeye
	Copyright (C) 2007 Skyeye Develop Group
	for help please send mail to <skyeye-developer@lists.gro.clinux.org>

	This program is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; either version 2 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program; if not, write to the Free Software
	Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA 
*/

/*
 * 03/03/2007   initial version by Anthony Lee
 */

#include "portable/gettimeofday.h"

#ifndef HAVE_GETTIMEOFDAY

#ifdef __MINGW32__
#include "./win32/gettimeofday.c"
#endif /* __MINGW32__ */

#endif /* !HAVE_GETTIMEOFDAY */

