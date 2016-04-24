/*
 * The value data definitions of a Personal Folder File
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

#if !defined( _PFF_VALUE_DATA_H )
#define _PFF_VALUE_DATA_H

#include <common.h>
#include <types.h>

#if defined( __cplusplus )
extern "C" {
#endif

typedef struct pff_folder_information_reference pff_folder_information_reference_t;

struct pff_folder_information_reference
{
	/* Padding
	 * Consists of 4 bytes
	 */
	uint8_t padding[ 4 ];

	/* The GUID
	 * Consists of 16 bytes
	 */
	uint8_t guid[ 16 ];

	/* The folder information data identifier
	 * Refers to a descriptor index identifier refering to a folder information table
	 * Consists of 4 bytes
	 */
	uint8_t data_identifier[ 4 ];
};

typedef struct pff_name_to_id_map_entry pff_name_to_id_map_entry_t;

struct pff_name_to_id_map_entry
{
	/* The entry value or value reference
	 * Consists of 4 bytes
	 */
	uint8_t entry_value[ 4 ];

	/* The entry type
	 * Consists of 2 bytes
	 */
	uint8_t entry_type[ 2 ];

	/* The entry number
	 * Consists of 2 bytes
	 */
	uint8_t entry_number[ 2 ];
};

#if defined( __cplusplus )
}
#endif

#endif

