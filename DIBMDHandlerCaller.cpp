#include "pch.h"
#include "DIBMDHandlerCaller.h"

DIBMDHandler* CreateDIBMDHandlerClass(char* path)
{
	DIBMDHandler* handler = new DIBMDHandler();
	handler -> Initialize(path);
	return handler;
}

char* GetAuthor(DIBMDHandler* handler)
{
	return &(handler -> GetAuthor())[0];
}

char* GetCreationDate(DIBMDHandler* handler)
{
	return &(handler -> GetCreationDate())[0];
}

char* GetName(DIBMDHandler* handler)
{
	return &(handler -> GetName())[0];
}

int GetPort(DIBMDHandler* handler)
{
	return handler -> GetPort();
}

char* GetRemoteAddress(DIBMDHandler* handler)
{
	return &(handler -> GetRemoteAddress())[0];
}

char* GetUpdateDate(DIBMDHandler* handler)
{
	return &(handler -> GetUpdateDate())[0];
}

int GetRepoVersion(DIBMDHandler* handler)
{
	return handler -> GetVersion();
}

void SetAuthor(DIBMDHandler* handler, char* author)
{
	handler -> SetAuthor(string(author));
}

void SetCreationDate(DIBMDHandler* handler, char* creationDate)
{
	handler -> SetCreationDate(string(creationDate));
}

void SetName(DIBMDHandler* handler, char* name)
{
	handler -> SetName(string(name));
}

void SetPort(DIBMDHandler* handler, int port)
{
	handler -> SetPort(port);
}

void SetRemoteAddress(DIBMDHandler* handler, char* remoteAddress)
{
	handler -> SetRemoteAddress(string(remoteAddress));
}

void SetUpdateDate(DIBMDHandler* handler, char* updateDate)
{
	handler -> SetUpdateDate(string(updateDate));
}

void SetRepoVersion(DIBMDHandler* handler, int version)
{
	handler -> SetVersion(version);
}