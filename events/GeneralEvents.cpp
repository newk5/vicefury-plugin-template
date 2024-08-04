#include "pch.h"
#include "GeneralEvents.h"
#include "entities/Server.h"
#include "Registry.h"


std::shared_ptr<Registry> GeneralEvents::Registry;
std::shared_ptr<Server> GeneralEvents::Server;


void GeneralEvents::OnLowTPS(int32_t Limit, int32_t Current)
{
}

void GeneralEvents::OnServerStart()
{
  
}

void GeneralEvents::OnServerShutdown()
{
}

void GeneralEvents::OnTick()
{
    Registry->ProcessTimers();
    Registry->ProcessQueue();
}

void GeneralEvents::OnDataReceived(int32_t PlayerID, const char* Channel, const char* Message)
{
    std::shared_ptr<Player> Player = Registry->GetPlayer(PlayerID);
    std::string channel(Channel);
    std::string msg(Message);
}
