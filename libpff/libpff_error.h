/*
 * Error functions
 *
 * Copyright (C) 2008-2015, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this software.  If not, see <http://www.gnu.org/licenses/>.
 */

#if !defined( _LIBPFF_INTERNAL_ERROR_H )
#define _LIBPFF_INTERNAL_ERROR_H

#include <common.h>
#include <file_stream.h>
#include <types.h>

#if !defined( HAVE_LOCAL_LIBPFF )
#include <libpff/error.h>
#endif

#include "libpff_extern.h"

#if defined( __cplusplus )
extern "C" {
#endif

#if !defined( HAVE_LOCAL_LIBPFF )

LIBPFF_EXTERN \
void libpff_error_free(
      libpff_error_t **error );

LIBPFF_EXTERN \
int libpff_error_fprint(
     libpff_error_t *error,
     FILE *stream );

LIBPFF_EXTERN \
int libpff_error_sprint(
     libpff_error_t *error,
     char *string,
     size_t size );

LIBPFF_EXTERN \
int libpff_error_backtrace_fprint(
     libpff_error_t *error,
     FILE *stream );

LIBPFF_EXTERN \
int libpff_error_backtrace_sprint(
     libpff_error_t *error,
     char *string,
     size_t size );

#endif

#if defined( __cplusplus )
}
#endif

#endif

