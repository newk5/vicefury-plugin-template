#include "pch.h"
#include "ZoneEvents.h"
#include "entities/Server.h"
#include "Registry.h"

std::shared_ptr<Registry> ZoneEvents::Registry;
std::shared_ptr<Server> ZoneEvents::Server;

void ZoneEvents::OnZoneCreated(int32_t ZoneId, ZoneType type)
{
    Registry->RegisterNewZone(ZoneId);

    std::shared_ptr<Zone> Zone = Registry->GetZone(ZoneId);
}

void ZoneEvents::OnZoneDestroyed(int32_t ZoneId)
{
    std::shared_ptr<Zone> Zone = Registry->GetZone(ZoneId);


    Registry->UnregisterZone(ZoneId);
}

void ZoneEvents::OnZoneEnter(int32_t ZoneId, GameEntity GameEntityType, int32_t GameEntityID)
{
    std::shared_ptr<Zone> Zone = Registry->GetZone(ZoneId);
    std::shared_ptr<VFEntity> Entity = Registry->GetEntity(GameEntityType,GameEntityID);
}

void ZoneEvents::OnZoneLeave(int32_t ZoneId, GameEntity GameEntityType, int32_t GameEntityID)
{
    std::shared_ptr<Zone> Zone = Registry->GetZone(ZoneId);
    std::shared_ptr<VFEntity> Entity = Registry->GetEntity(GameEntityType,GameEntityID);
}
