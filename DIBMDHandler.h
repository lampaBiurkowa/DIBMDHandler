#pragma once

#include <string>
#include <vector>

using namespace std;

class DIBMDHandler
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

	int GetVersion();
	void SetVersion(int version);

private:
	static const string AUTHOR_KEYWORD;
	static const string CREATION_DATE_KEYWORD;
	static const string NAME_KEYWORD;
	static const string PORT_KEYWORD;
	static const string REMOTE_ADDRESS_KEYWORD;
	static const string UPDATE_DATE_KEYWORD;
	static const string VERSION_KEYWORD;

	static const char SEPARATOR = ':';

	string path;

	void createDIBMDFile();
	bool keywordEquals(string line, string keyword);
	void rewriteFile(vector<string>& data);
	string getValue(string keyword);
	void setValue(string keyword, string value);
};