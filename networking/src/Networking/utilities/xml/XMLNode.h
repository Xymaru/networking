#pragma once

#include "Networking/Core.h"

#include "XMLAttribute.h"

namespace pugi {
	class xml_node;
}

namespace EM {
	class EM_API XMLNode {
	private:
		
	protected:
		pugi::xml_node* m_Node;
	public:
		XMLNode();
		XMLNode(const XMLNode& node);
		~XMLNode();

		XMLNode first_child() const;
		XMLNode child(const char* name);

		XMLNode append_child(const char* name);

		XMLNode next_sibling();
		XMLNode next_sibling(const char* name);

		XMLAttribute append_attribute(const char* name);
		XMLAttribute attribute(const char* name);

		operator bool();
	};
}