#pragma once

#include <string>
#include <vector>
#include "DIBMDHandler.h"

using namespace std;

#ifdef DIBMDHANDLERCALLER_EXPORTS
#define DIBMDHANDLERCALLER_API __declspec(dllexport)
#else
#define DIBMDHANDLERCALLER_API __declspec(dllimport)
#endif

extern "C" __declspec(dllexport) DIBMDHandler* CreateDIBMDHandlerClass(char* path);

extern "C" __declspec(dllexport) char* GetAuthor(DIBMDHandler* object);
extern "C" __declspec(dllexport) char* GetCreationDate(DIBMDHandler* object);
extern "C" __declspec(dllexport) char* GetName(DIBMDHandler* object);
extern "C" __declspec(dllexport) int GetPort(DIBMDHandler* object);
extern "C" __declspec(dllexport) char* GetRemoteAddress(DIBMDHandler* object);
extern "C" __declspec(dllexport) char* GetUpdateDate(DIBMDHandler* object);
extern "C" __declspec(dllexport) int GetRepoVersion(DIBMDHandler* object);
extern "C" __declspec(dllexport) void SetAuthor(DIBMDHandler* object, char* author);
extern "C" __declspec(dllexport) void SetCreationDate(DIBMDHandler* object, char* creationDate);
extern "C" __declspec(dllexport) void SetName(DIBMDHandler* object, char* name);
extern "C" __declspec(dllexport) void SetPort(DIBMDHandler* object, int port);
extern "C" __declspec(dllexport) void SetRemoteAddress(DIBMDHandler* object, char* remoteAddress);
extern "C" __declspec(dllexport) void SetUpdateDate(DIBMDHandler* object, char* updateDate);
extern "C" __declspec(dllexport) void SetRepoVersion(DIBMDHandler* object, int version);