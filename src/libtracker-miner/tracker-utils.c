/*
 * Copyright (C) 2009, Nokia <ivan.frade@nokia.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA  02110-1301, USA.
 */

#include "config-miners.h"

#include "tracker-utils.h"

gboolean
tracker_accumulator_check_file (GSignalInvocationHint *hint,
                                GValue                *return_accumulator,
                                const GValue          *handler_return,
                                gpointer               accumulator_data)
{
	gboolean use;

	use = g_value_get_boolean (handler_return);
	g_value_set_boolean (return_accumulator, use);

	return (use == TRUE);
}
