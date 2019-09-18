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

	virtual int GetPort() = 0;
	virtual void SetPort(int port) = 0;

	virtual string GetRemoteAddress() = 0;
	virtual void SetRemoteAddress(string updateDate) = 0;

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

	int GetPort();
	void SetPort(int port);

	string GetRemoteAddress();
	void SetRemoteAddress(string updateDate);

	string GetUpdateDate();
	void SetUpdateDate(string date);

	string GetVersion();
	void SetVersion(string version);

private:
	static const string AUTHOR_KEYWORD;
	static const string CREATION_DATE_KEYWORD;
	static const string NAME_KEYWORD;
	static const string PORT_KEYWORD;
	static const string REMOTE_ADDRESS_KEYWORD;
	static const string UPDATE_DATE_KEYWORD;
	static const string VERSION_KEYWORD;

	const char SEPARATOR = ':';

	string path;

	void createDIBMDFile();
	bool keywordEquals(string line, string keyword);
	void rewriteFile(vector<string>& data);
	string getValue(string keyword);
	void setValue(string keyword, string value);
};

__declspec(dllexport) inline IDIBMDHandler *CreateNewDIBMDHandler()
{
	return new DIBMDHandler();
}