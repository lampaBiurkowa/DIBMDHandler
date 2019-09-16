#pragma once

#include <string>
#include <vector>

using namespace std;

#ifdef DIBMDHANDLER_EXPORTS
#define DIBMDHANDLER_API __declspec(dllexport)
#else
#define DIBMDHANDLER_API __declspec(dllimport)
#endif

class IDIBMDHandler
{
public:
	virtual void Initialize(string path) = 0;

	virtual string GetAuthor() = 0;
	virtual void SetAuthor(string author) = 0;

	virtual string GetCreationDate() = 0;
	virtual void SetCreationDate(string creationDate) = 0;

	virtual string GetName() = 0;
	virtual void SetName(string name) = 0;

	virtual string GetUpdateDate() = 0;
	virtual void SetUpdateDate(string updateDate) = 0;

	virtual string GetVersion() = 0;
	virtual void SetVersion(string version) = 0;
};

class DIBMDHandler : public IDIBMDHandler
{
public:
	void Initialize(string path);

	string GetAuthor();
	void SetAuthor(string author);

	string GetCreationDate();
	void SetCreationDate(string date);

	string GetName();
	void SetName(string name);

	string GetUpdateDate();
	void SetUpdateDate(string date);

	string GetVersion();
	void SetVersion(string version);

private:
	const string AUTHOR_KEYWORD = "author";
	const string CREATION_DATE_KEYWORD = "creationDate";
	const string NAME_KEYWORD = "name";
	const string UPDATE_DATE_KEYWORD = "updateDate";
	const string VERSION_KEYWORD = "version";

	const char SEPARATOR = ':';

	string path;

	void createDIBMDFile();
	bool keywordEquals(string line, string keyword);
	void rewriteFile(vector<string>& data);
	string getValue(string keyword);
	void setValue(string keyword, string value);
};

__declspec(dllexport) IDIBMDHandler *CreateNewDIBMDHandler()
{
	return new DIBMDHandler();
}