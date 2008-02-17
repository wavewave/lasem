/* gmathmltablerowelement.c
 *
 * Copyright (C) 2007  Emmanuel Pacaud
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
 *
 * Author:
 * 	Emmanuel Pacaud <emmanuel@gnome.org>
 */

#include <gmathmltablerowelement.h>
#include <gmathmltablecellelement.h>

static GObjectClass *parent_class;

/* GdomNode implementation */

static const char *
gmathml_table_row_get_node_name (GDomNode *node)
{
	return "mtr";
}

static gboolean
gmathml_table_row_can_append_child (GDomNode *self, GDomNode *child)
{
	return GMATHML_IS_TABLE_CELL_ELEMENT (child);
}

/* GMathmlElement implementation */

static const GMathmlBbox *
gmathml_table_row_element_measure (GMathmlElement *self, GMathmlView *view, const GMathmlBbox *bbox)
{
	GMATHML_ELEMENT_CLASS (parent_class)->measure (self, view, bbox);

	return &self->bbox;
}

static void
gmathml_table_row_element_layout (GMathmlElement *self, GMathmlView *view,
				double x, double y, const GMathmlBbox *bbox)
{
	GMATHML_ELEMENT_CLASS (parent_class)->layout (self, view, x, y, bbox);
}

/* GMathmlTableRowElement implementation */

GDomNode *
gmathml_table_row_element_new (void)
{
	return g_object_new (GMATHML_TYPE_TABLE_ROW_ELEMENT, NULL);
}

static void
gmathml_table_row_element_init (GMathmlTableRowElement *self)
{
}

/* GMathmlTableRowElement class */

static void
gmathml_table_row_element_class_init (GMathmlTableRowElementClass *table_row_class)
{
	GDomNodeClass *d_node_class = GDOM_NODE_CLASS (table_row_class);
	GMathmlElementClass *m_element_class = GMATHML_ELEMENT_CLASS (table_row_class);

	parent_class = g_type_class_peek_parent (table_row_class);

	d_node_class->get_node_name = gmathml_table_row_get_node_name;
	d_node_class->can_append_child = gmathml_table_row_can_append_child;

	m_element_class->measure = gmathml_table_row_element_measure;
	m_element_class->layout = gmathml_table_row_element_layout;
}

G_DEFINE_TYPE (GMathmlTableRowElement, gmathml_table_row_element, GMATHML_TYPE_ELEMENT)
