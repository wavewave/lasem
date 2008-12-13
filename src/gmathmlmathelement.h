/* gmathmlmathelement.h
 *
 * Copyright © 2007-2008  Emmanuel Pacaud
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

#ifndef GMATHML_MATH_ELEMENT_H
#define GMATHML_MATH_ELEMENT_H

#include <gmathml.h>
#include <gmathmlelement.h>

G_BEGIN_DECLS

#define GMATHML_FONT_SERIF		"Serif"
#define GMATHML_FONT_SANS		"Sans"
#define GMATHML_FONT_MONOSPACE		"Monospace"
#define GMATHML_FONT_FRAKTUR		"Serif"
#define GMATHML_FONT_SCRIPT		"cmsy10"
#define GMATHML_FONT_DOUBLE_STRUCK	"msbm10"

#define GMATHML_TYPE_MATH_ELEMENT             (gmathml_math_element_get_type ())
#define GMATHML_MATH_ELEMENT(obj)             (G_TYPE_CHECK_INSTANCE_CAST ((obj), GMATHML_TYPE_MATH_ELEMENT, GMathmlMathElement))
#define GMATHML_MATH_ELEMENT_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST ((klass), GMATHML_TYPE_MATH_ELEMENT, GMathmlMathElementClass))
#define GMATHML_IS_MATH_ELEMENT(obj)          (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GMATHML_TYPE_MATH_ELEMENT))
#define GMATHML_IS_MATH_ELEMENT_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE ((klass), GMATHML_TYPE_MATH_ELEMENT))
#define GMATHML_MATH_ELEMENT_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS((obj), GMATHML_TYPE_MATH_ELEMENT, GMathmlMathElementClass))

typedef struct _GMathmlMathElementClass GMathmlMathElementClass;

struct _GMathmlMathElement {
	GMathmlElement	element;

	GMathmlStyle *default_style;

	GMathmlAttributeNamed mode;
	GMathmlAttributeNamed display;
};

struct _GMathmlMathElementClass {
	GMathmlElementClass  parent_class;
};

GType gmathml_math_element_get_type (void);

GDomNode *		gmathml_math_element_new 		(void);
GMathmlStyle * 		gmathml_math_element_get_default_style 	(GMathmlMathElement *math_element);
void 			gmathml_math_element_set_default_style 	(GMathmlMathElement *math_element,
								 GMathmlStyle *style);

void 			gmathml_math_element_update 		(GMathmlMathElement *math_element);
const GMathmlBbox * 	gmathml_math_element_measure 		(GMathmlMathElement *math_element,
								 GMathmlView *view);
void 			gmathml_math_element_layout 		(GMathmlMathElement *math_element,
								 GMathmlView *view,
								 const GMathmlBbox *bbox);
void 			gmathml_math_element_render 		(GMathmlMathElement *math_element,
								 GMathmlView *view);


G_END_DECLS

#endif
