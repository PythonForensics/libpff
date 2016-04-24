/*
 * Python object definition of the libpff record entry
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

#if !defined( _PYPFF_RECORD_ENTRY_H )
#define _PYPFF_RECORD_ENTRY_H

#include <common.h>
#include <types.h>

#include "pypff_libcerror.h"
#include "pypff_libpff.h"
#include "pypff_python.h"
#include "pypff_record_set.h"

#if defined( __cplusplus )
extern "C" {
#endif

typedef struct pypff_record_entry pypff_record_entry_t;

struct pypff_record_entry
{
	/* Python object initialization
	 */
	PyObject_HEAD

	/* The libpff record entry
	 */
	libpff_record_entry_t *record_entry;

	/* The record set object
	 */
	pypff_record_set_t *record_set_object;
};

extern PyMethodDef pypff_record_entry_object_methods[];
extern PyTypeObject pypff_record_entry_type_object;

PyObject *pypff_record_entry_new(
           PyTypeObject *type_object,
           libpff_record_entry_t *record_entry,
           pypff_record_set_t *record_set_object );

int pypff_record_entry_init(
     pypff_record_entry_t *pypff_record_entry );

void pypff_record_entry_free(
      pypff_record_entry_t *pypff_record_entry );

PyObject *pypff_record_entry_get_entry_type(
           pypff_record_entry_t *pypff_record_entry,
           PyObject *arguments );

PyObject *pypff_record_entry_get_value_type(
           pypff_record_entry_t *pypff_record_entry,
           PyObject *arguments );

PyObject *pypff_record_entry_get_value_data(
           pypff_record_entry_t *pypff_record_entry,
           PyObject *arguments );

PyObject *pypff_record_entry_get_value_data_as_integer(
           pypff_record_entry_t *pypff_record_entry,
           PyObject *arguments );

PyObject *pypff_record_entry_get_value_data_as_string(
           pypff_record_entry_t *pypff_record_entry,
           PyObject *arguments );

#if defined( __cplusplus )
}
#endif

#endif

