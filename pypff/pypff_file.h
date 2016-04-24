/*
 * Python object definition of the libpff file
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

#if !defined( _PYPFF_FILE_H )
#define _PYPFF_FILE_H

#include <common.h>
#include <types.h>

#include "pypff_libbfio.h"
#include "pypff_libcerror.h"
#include "pypff_libpff.h"
#include "pypff_python.h"

#if defined( __cplusplus )
extern "C" {
#endif

typedef struct pypff_file pypff_file_t;

struct pypff_file
{
	/* Python object initialization
	 */
	PyObject_HEAD

	/* The libpff file
	 */
	libpff_file_t *file;

	/* The libbfio file IO handle
	 */
	libbfio_handle_t *file_io_handle;
};

extern PyMethodDef pypff_file_object_methods[];
extern PyTypeObject pypff_file_type_object;

PyObject *pypff_file_new(
           void );

PyObject *pypff_file_new_open(
           PyObject *self,
           PyObject *arguments,
           PyObject *keywords );

PyObject *pypff_file_new_open_file_object(
           PyObject *self,
           PyObject *arguments,
           PyObject *keywords );

int pypff_file_init(
     pypff_file_t *pypff_file );

void pypff_file_free(
      pypff_file_t *pypff_file );

PyObject *pypff_file_signal_abort(
           pypff_file_t *pypff_file,
           PyObject *arguments );

PyObject *pypff_file_open(
           pypff_file_t *pypff_file,
           PyObject *arguments,
           PyObject *keywords );

PyObject *pypff_file_open_file_object(
           pypff_file_t *pypff_file,
           PyObject *arguments,
           PyObject *keywords );

PyObject *pypff_file_close(
           pypff_file_t *pypff_file,
           PyObject *arguments );

PyObject *pypff_file_get_size(
           pypff_file_t *pypff_file,
           PyObject *arguments );

PyObject *pypff_file_get_ascii_codepage(
           pypff_file_t *pypff_file,
           PyObject *arguments );

int pypff_file_set_ascii_codepage_from_string(
     pypff_file_t *pypff_file,
     const char *codepage_string );

PyObject *pypff_file_set_ascii_codepage(
           pypff_file_t *pypff_file,
           PyObject *arguments,
           PyObject *keywords );

int pypff_file_set_ascii_codepage_setter(
     pypff_file_t *pypff_file,
     PyObject *string_object,
     void *closure );

PyObject *pypff_file_recover_items(
           pypff_file_t *pypff_file,
           PyObject *arguments );

PyObject *pypff_file_get_root_folder(
           pypff_file_t *pypff_file,
           PyObject *arguments );

PyObject *pypff_file_get_number_of_recovered_items(
           pypff_file_t *pypff_file,
           PyObject *arguments );

#if defined( __cplusplus )
}
#endif

#endif

