/*
 * Python object definition of the items sequence and iterator
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

#include <common.h>
#include <types.h>

#if defined( HAVE_STDLIB_H ) || defined( HAVE_WINAPI )
#include <stdlib.h>
#endif

#include "pypff_item.h"
#include "pypff_libcerror.h"
#include "pypff_libpff.h"
#include "pypff_python.h"
#include "pypff_items.h"

PySequenceMethods pypff_items_sequence_methods = {
	/* sq_length */
	(lenfunc) pypff_items_len,
	/* sq_concat */
	0,
	/* sq_repeat */
	0,
	/* sq_item */
	(ssizeargfunc) pypff_items_getitem,
	/* sq_slice */
	0,
	/* sq_ass_item */
	0,
	/* sq_ass_slice */
	0,
	/* sq_contains */
	0,
	/* sq_inplace_concat */
	0,
	/* sq_inplace_repeat */
	0
};

PyTypeObject pypff_items_type_object = {
	PyVarObject_HEAD_INIT( NULL, 0 )

	/* tp_name */
	"pypff._items",
	/* tp_basicsize */
	sizeof( pypff_items_t ),
	/* tp_itemsize */
	0,
	/* tp_dealloc */
	(destructor) pypff_items_free,
	/* tp_print */
	0,
	/* tp_getattr */
	0,
	/* tp_setattr */
	0,
	/* tp_compare */
	0,
	/* tp_repr */
	0,
	/* tp_as_number */
	0,
	/* tp_as_sequence */
	&pypff_items_sequence_methods,
	/* tp_as_mapping */
	0,
	/* tp_hash */
	0,
	/* tp_call */
	0,
	/* tp_str */
	0,
	/* tp_getattro */
	0,
	/* tp_setattro */
	0,
	/* tp_as_buffer */
	0,
	/* tp_flags */
	Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HAVE_ITER,
	/* tp_doc */
	"internal pypff items sequence and iterator object",
	/* tp_traverse */
	0,
	/* tp_clear */
	0,
	/* tp_richcompare */
	0,
	/* tp_weaklistoffset */
	0,
	/* tp_iter */
	(getiterfunc) pypff_items_iter,
	/* tp_iternext */
	(iternextfunc) pypff_items_iternext,
	/* tp_methods */
	0,
	/* tp_members */
	0,
	/* tp_getset */
	0,
	/* tp_base */
	0,
	/* tp_dict */
	0,
	/* tp_descr_get */
	0,
	/* tp_descr_set */
	0,
	/* tp_dictoffset */
	0,
	/* tp_init */
	(initproc) pypff_items_init,
	/* tp_alloc */
	0,
	/* tp_new */
	0,
	/* tp_free */
	0,
	/* tp_is_gc */
	0,
	/* tp_bases */
	NULL,
	/* tp_mro */
	NULL,
	/* tp_cache */
	NULL,
	/* tp_subclasses */
	NULL,
	/* tp_weaklist */
	NULL,
	/* tp_del */
	0
};

/* Creates a new items object
 * Returns a Python object if successful or NULL on error
 */
PyObject *pypff_items_new(
           pypff_item_t *item_object,
           PyObject* (*get_item_by_index)(
                        pypff_item_t *item_object,
                        int item_index ),
           int number_of_items )
{
	pypff_items_t *pypff_items = NULL;
	static char *function      = "pypff_items_new";

	if( item_object == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid item object.",
		 function );

		return( NULL );
	}
	if( get_item_by_index == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid get item by index function.",
		 function );

		return( NULL );
	}
	/* Make sure the items values are initialized
	 */
	pypff_items = PyObject_New(
	               struct pypff_items,
	               &pypff_items_type_object );

	if( pypff_items == NULL )
	{
		PyErr_Format(
		 PyExc_MemoryError,
		 "%s: unable to initialize items.",
		 function );

		goto on_error;
	}
	if( pypff_items_init(
	     pypff_items ) != 0 )
	{
		PyErr_Format(
		 PyExc_MemoryError,
		 "%s: unable to initialize items.",
		 function );

		goto on_error;
	}
	pypff_items->item_object       = item_object;
	pypff_items->get_item_by_index = get_item_by_index;
	pypff_items->number_of_items   = number_of_items;

	Py_IncRef(
	 (PyObject *) pypff_items->item_object );

	return( (PyObject *) pypff_items );

on_error:
	if( pypff_items != NULL )
	{
		Py_DecRef(
		 (PyObject *) pypff_items );
	}
	return( NULL );
}

/* Intializes an items object
 * Returns 0 if successful or -1 on error
 */
int pypff_items_init(
     pypff_items_t *pypff_items )
{
	static char *function = "pypff_items_init";

	if( pypff_items == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid items.",
		 function );

		return( -1 );
	}
	/* Make sure the items values are initialized
	 */
	pypff_items->item_object       = NULL;
	pypff_items->get_item_by_index = NULL;
	pypff_items->item_index        = 0;
	pypff_items->number_of_items   = 0;

	return( 0 );
}

/* Frees an items object
 */
void pypff_items_free(
      pypff_items_t *pypff_items )
{
	struct _typeobject *ob_type = NULL;
	static char *function       = "pypff_items_free";

	if( pypff_items == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid items.",
		 function );

		return;
	}
	ob_type = Py_TYPE(
	           pypff_items );

	if( ob_type == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: missing ob_type.",
		 function );

		return;
	}
	if( ob_type->tp_free == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid ob_type - missing tp_free.",
		 function );

		return;
	}
	if( pypff_items->item_object != NULL )
	{
		Py_DecRef(
		 (PyObject *) pypff_items->item_object );
	}
	ob_type->tp_free(
	 (PyObject*) pypff_items );
}

/* The items len() function
 */
Py_ssize_t pypff_items_len(
            pypff_items_t *pypff_items )
{
	static char *function = "pypff_items_len";

	if( pypff_items == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid items.",
		 function );

		return( -1 );
	}
	return( (Py_ssize_t) pypff_items->number_of_items );
}

/* The items getitem() function
 */
PyObject *pypff_items_getitem(
           pypff_items_t *pypff_items,
           Py_ssize_t item_index )
{
	PyObject *item_object = NULL;
	static char *function = "pypff_items_getitem";

	if( pypff_items == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid items.",
		 function );

		return( NULL );
	}
	if( pypff_items->get_item_by_index == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid items - missing get item by index function.",
		 function );

		return( NULL );
	}
	if( pypff_items->number_of_items < 0 )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid items - invalid number of items.",
		 function );

		return( NULL );
	}
	if( ( item_index < 0 )
	 || ( item_index >= (Py_ssize_t) pypff_items->number_of_items ) )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid invalid item index value out of bounds.",
		 function );

		return( NULL );
	}
	item_object = pypff_items->get_item_by_index(
	               pypff_items->item_object,
	               (int) item_index );

	return( item_object );
}

/* The items iter() function
 */
PyObject *pypff_items_iter(
           pypff_items_t *pypff_items )
{
	static char *function = "pypff_items_iter";

	if( pypff_items == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid items.",
		 function );

		return( NULL );
	}
	Py_IncRef(
	 (PyObject *) pypff_items );

	return( (PyObject *) pypff_items );
}

/* The items iternext() function
 */
PyObject *pypff_items_iternext(
           pypff_items_t *pypff_items )
{
	PyObject *item_object = NULL;
	static char *function = "pypff_items_iternext";

	if( pypff_items == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid items.",
		 function );

		return( NULL );
	}
	if( pypff_items->get_item_by_index == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid items - missing get item by index function.",
		 function );

		return( NULL );
	}
	if( pypff_items->item_index < 0 )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid items - invalid item index.",
		 function );

		return( NULL );
	}
	if( pypff_items->number_of_items < 0 )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid items - invalid number of items.",
		 function );

		return( NULL );
	}
	if( pypff_items->item_index >= pypff_items->number_of_items )
	{
		PyErr_SetNone(
		 PyExc_StopIteration );

		return( NULL );
	}
	item_object = pypff_items->get_item_by_index(
	               pypff_items->item_object,
	               pypff_items->item_index );

	if( item_object != NULL )
	{
		pypff_items->item_index++;
	}
	return( item_object );
}

