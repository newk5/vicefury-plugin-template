#pragma once


#include "plugin.h"

#ifdef _WIN32
#define EXPORT __declspec(dllexport)
#else
#define EXPORT
#endif

extern ServerFunctions* functions;
extern ServerCallbacks* events;
extern ServerInfo* info;

void BindEvents(ServerCallbacks* functions);
