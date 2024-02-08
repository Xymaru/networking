#include "JSONDocument.h"

#include <rapidjson/writer.h>
#include <rapidjson/filereadstream.h>
#include <rapidjson/filewritestream.h>
#include <rapidjson/istreamwrapper.h>
#include <rapidjson/ostreamwrapper.h>

#include <Networking/Debug.h>
#include <Networking/filesystem/FileSystem.h>

namespace EM {

	JSONDocument::JSONDocument(const char* path)
	{
		if (!load_file(path)) {
			std::string msg = "Couldn't load json file: ";
			msg += path;

			Debug::Log("Empathy", msg.c_str());
		}
	}

	JSONDocument::JSONDocument()
	{
		m_Document.SetObject();
	}

	JSONDocument::~JSONDocument()
	{
	}

	void JSONDocument::Parse(const char* string)
	{
		m_Document.Parse(string);
	}

	const char* JSONDocument::getString()
	{
		m_Buffer.Clear();
		rapidjson::Writer<rapidjson::StringBuffer> writer(m_Buffer);

		m_Document.Accept(writer);

		return m_Buffer.GetString();
	}

	JSONValue JSONDocument::AddMemberObject(const char* mem)
	{
		rapidjson::Value key(mem, m_Document.GetAllocator());
		rapidjson::Value v(rapidjson::kObjectType);

		m_Document.AddMember(key, v, m_Document.GetAllocator());

		rapidjson::Value& jval = m_Document[mem];

		return JSONValue(&jval, &m_Document.GetAllocator());
	}

	JSONValue JSONDocument::AddMemberArray(const char* mem)
	{
		rapidjson::Value key(mem, m_Document.GetAllocator());
		rapidjson::Value v(rapidjson::kArrayType);

		m_Document.AddMember(key, v, m_Document.GetAllocator());

		rapidjson::Value& jval = m_Document[mem];

		return JSONValue(&jval, &m_Document.GetAllocator());
	}

	bool JSONDocument::HasMember(const char* mem)
	{
		return m_Document.HasMember(mem);
	}

	bool JSONDocument::IsObject()
	{
		return m_Document.IsObject();
	}

	bool JSONDocument::load_file(const char* path)
	{
		std::ifstream file(path);

		if (!file.is_open()) return false;

		rapidjson::IStreamWrapper isw(file);

		m_Document.ParseStream(isw);

		file.close();

		return true;
	}

	bool JSONDocument::save_file(const char* path)
	{
		std::ofstream file(path);

		if (!file.is_open()) return false;

		rapidjson::OStreamWrapper osw(file);

		rapidjson::Writer<rapidjson::OStreamWrapper> writer(osw);

		m_Document.Accept(writer);

		file.close();

		return true;
	}

	JSONValue JSONDocument::operator[](const char* key)
	{
		return JSONValue(&m_Document[key], &m_Document.GetAllocator());
	}
}