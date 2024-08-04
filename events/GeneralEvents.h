#pragma once


#include "plugin.h"


class GeneralEvents
{
public:
	static void Setup(std::shared_ptr<class Registry> registry, std::shared_ptr<class Server> server)
	{
		Registry = registry;
		Server = server;
	}

	static void OnLowTPS(int32_t Limit, int32_t Current);
	static void OnServerStart();
	static void OnServerShutdown();
	static void OnTick();
	static void OnDataReceived(int32_t PlayerID, const char* Channel, const char* Message);
private:
	static std::shared_ptr<Registry> Registry;
	static std::shared_ptr<Server> Server;
};

