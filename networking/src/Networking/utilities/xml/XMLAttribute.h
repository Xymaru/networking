#pragma once

#include "Empathy/Core.h"

namespace pugi {
	class xml_attribute;
}

namespace EM {
	class EM_API XMLAttribute {
		friend class XMLNode;
	private:
		pugi::xml_attribute* m_Attr;
	public:
		XMLAttribute();
		XMLAttribute(const XMLAttribute& attr);
		~XMLAttribute();

		const char* as_string() const;

		bool set_value(const char* value);

		XMLAttribute& operator=(const char* value);
		XMLAttribute& operator=(int value);
	};
}