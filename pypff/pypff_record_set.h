/*
 * Python object definition of the libpff record set
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

#if !defined( _PYPFF_RECORD_SET_H )
#define _PYPFF_RECORD_SET_H

#include <common.h>
#include <types.h>

#include "pypff_item.h"
#include "pypff_libcerror.h"
#include "pypff_libpff.h"
#include "pypff_python.h"

#if defined( __cplusplus )
extern "C" {
#endif

typedef struct pypff_record_set pypff_record_set_t;

struct pypff_record_set
{
	/* Python object initialization
	 */
	PyObject_HEAD

	/* The libpff record set
	 */
	libpff_record_set_t *record_set;

	/* The item object
	 */
	pypff_item_t *item_object;
};

extern PyMethodDef pypff_record_set_object_methods[];
extern PyTypeObject pypff_record_set_type_object;

PyObject *pypff_record_set_new(
           PyTypeObject *type_object,
           libpff_record_set_t *record_set,
           pypff_item_t *item_object );

int pypff_record_set_init(
     pypff_record_set_t *pypff_record_set );

void pypff_record_set_free(
      pypff_record_set_t *pypff_record_set );

PyObject *pypff_record_set_get_number_of_record_entries(
           pypff_record_set_t *pypff_record_set,
           PyObject *arguments );

PyObject *pypff_record_set_get_record_entry_by_index(
           pypff_record_set_t *pypff_record_set,
           int record_entry_index );

PyObject *pypff_record_set_get_record_entry(
           pypff_record_set_t *pypff_record_set,
           PyObject *arguments,
           PyObject *keywords );

PyObject *pypff_record_set_get_record_entries(
           pypff_record_set_t *pypff_record_set,
           PyObject *arguments );

#if defined( __cplusplus )
}
#endif

#endif

