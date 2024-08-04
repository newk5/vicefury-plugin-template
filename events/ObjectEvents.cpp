#include "pch.h"
#include "ObjectEvents.h"
#include "entities/Server.h"
#include "Registry.h"

std::shared_ptr<Registry> ObjectEvents::Registry;
std::shared_ptr<Server> ObjectEvents::Server;

void ObjectEvents::OnObjectCreated(int32_t id)
{
    Registry->RegisterNewObject(id);
    std::shared_ptr<GameObject> Object = Registry->GetGameObject(id);
}

void ObjectEvents::OnObjectDestroyed(int32_t id)
{
    Registry->UnregisterObject(id);
}

float ObjectEvents::OnObjectReceiveDamage(int32_t ObjectId, DamageEvent Event)
{
    std::shared_ptr<GameObject> Object = Registry->GetGameObject(ObjectId);
    return Event.DamageToApply;
}

void ObjectEvents::OnObjectTouched(int32_t ObjectId, GameEntity GameEntityType, int32_t GameEntityID)
{
    std::shared_ptr<GameObject> Object = Registry->GetGameObject(ObjectId);
}

void ObjectEvents::OnObjectBroken(int32_t ObjectId)
{
    std::shared_ptr<GameObject> Object = Registry->GetGameObject(ObjectId);
}

void ObjectEvents::OnObjectOverlapped(int32_t ObjectId, GameEntity GameEntityType, int32_t GameEntityID)
{
    std::shared_ptr<GameObject> Object = Registry->GetGameObject(ObjectId);
    std::shared_ptr<VFEntity> Entity = Registry->GetEntity(GameEntityType,GameEntityID);
}

void ObjectEvents::OnObjectStoppedOverlapping(int32_t ObjectId, GameEntity GameEntityType, int32_t GameEntityID)
{
    std::shared_ptr<GameObject> Object = Registry->GetGameObject(ObjectId);
    std::shared_ptr<VFEntity> Entity = Registry->GetEntity(GameEntityType,GameEntityID);
}
