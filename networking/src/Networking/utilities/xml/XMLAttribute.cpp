#include <empch.h>
#include "Empathy/utilities/xml/XMLAttribute.h"
#include "pugixml/src/pugixml.hpp"

namespace EM {

	XMLAttribute::XMLAttribute() :
		m_Attr(nullptr)
	{
		m_Attr = new pugi::xml_attribute;
	}

	XMLAttribute::XMLAttribute(const XMLAttribute& attr)
	{
		m_Attr = new pugi::xml_attribute;

		*m_Attr = *attr.m_Attr;
	}

	XMLAttribute::~XMLAttribute()
	{
		delete m_Attr;
	}

	const char* XMLAttribute::as_string() const
	{
		return m_Attr->as_string();
	}

	bool XMLAttribute::set_value(const char* value)
	{
		return m_Attr->set_value(value);
	}

	XMLAttribute& EM::XMLAttribute::operator=(const char* value)
	{
		*m_Attr = value;

		return *this;
	}

	XMLAttribute& EM::XMLAttribute::operator=(int value)
	{
		*m_Attr = value;

		return *this;
	}
}