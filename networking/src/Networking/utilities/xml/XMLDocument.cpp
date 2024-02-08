#include <empch.h>
#include "Empathy/utilities/xml/XMLDocument.h"
#include "pugixml/src/pugixml.hpp"

namespace EM {
	XMLDocument::XMLDocument()
	{
		m_Doc = new pugi::xml_document();
	}

	XMLDocument::XMLDocument(const char* path)
	{
		m_Doc = new pugi::xml_document();

		Load(path);
	}

	XMLDocument::~XMLDocument()
	{
		delete m_Doc;
	}

	void XMLDocument::Load(const char* path)
	{
		pugi::xml_parse_result result = m_Doc->load_file(path);

		if (result != NULL) {
			*m_Node = *m_Doc;
		}
	}

	void XMLDocument::Save(const char* path)
	{
		m_Doc->save_file(path);
	}
}