#include "pch.h"
#include "DIBMDHandler.h"
#include <fstream>
#include <iterator>

using namespace std;

void DIBMDHandler::Initialize(string path)
{
	this -> path = path;
}

string DIBMDHandler::GetAuthor()
{
	return getValue(AUTHOR_KEYWORD);
}

string DIBMDHandler::getValue(string keyword)
{
	fstream file(path.c_str(), ios::in);

	while (!file.eof())
	{
		string line;
		getline(file, line);
		if (keywordEquals(line, keyword))
		{
			file.close();
			int separatorPos = line.find(SEPARATOR);
			return line.substr(separatorPos + 1, line.length() - separatorPos - 1);
		}
	}

	file.close();
	return "\0";
}

bool DIBMDHandler::keywordEquals(string line, string keyword)
{
	const int NOT_FOUND_CODE = -1;
	int separatorPos = line.find(SEPARATOR);

	if (separatorPos == NOT_FOUND_CODE)
		return false;

	string currentKeyword = line.substr(0, separatorPos);
	return currentKeyword == keyword;
}

void DIBMDHandler::SetAuthor(string author)
{
	setValue(AUTHOR_KEYWORD, author);
}

void DIBMDHandler::setValue(string keyword, string value)
{

	fstream file(path.c_str(), ios::in);
	if (!file.good())
	{
		createDIBMDFile();
		file.open(path.c_str(), ios::in);
	}

	vector<string> lines;
	bool found = false;

	while (!file.eof())
	{
		string line;
		getline(file, line);
		if (line.length() == 0)
			continue;

		if (keywordEquals(line, keyword))
		{
			line = keyword + SEPARATOR + value;
			found = true;
		}

		lines.push_back(line);
	}

	if (!found)
		lines.push_back(keyword + SEPARATOR + value);

	file.close();
	rewriteFile(lines);
}

void DIBMDHandler::createDIBMDFile()
{
	fstream file (path.c_str(), ios::out);
	file.close();
}

void DIBMDHandler::rewriteFile(vector<string>& data)
{
	ofstream rewriteFile(path.c_str());
	ostream_iterator<string> output_iterator(rewriteFile, "\n");
	copy(data.begin(), data.end(), output_iterator);
	rewriteFile.close();
}

string DIBMDHandler::GetCreationDate()
{
	return getValue(CREATION_DATE_KEYWORD);
}

void DIBMDHandler::SetCreationDate(string date)
{
	setValue(CREATION_DATE_KEYWORD, date);
}

string DIBMDHandler::GetName()
{
	return getValue(NAME_KEYWORD);
}

void DIBMDHandler::SetName(string name)
{
	setValue(NAME_KEYWORD, name);
}

string DIBMDHandler::GetUpdateDate()
{
	return getValue(UPDATE_DATE_KEYWORD);
}

void DIBMDHandler::SetUpdateDate(string date)
{
	setValue(UPDATE_DATE_KEYWORD, date);
}

string DIBMDHandler::GetVersion()
{
	return getValue(VERSION_KEYWORD);
}

void DIBMDHandler::SetVersion(string version)
{
	setValue(VERSION_KEYWORD, version);
}