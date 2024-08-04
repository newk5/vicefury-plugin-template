#pragma once
#include "common/Transform.h"

class Registry;

class Zone : public VFEntity
{
public:
    Zone(int32_t id, std::shared_ptr<Registry> registry) : Id(id), Registry(registry)
    {
    }

    ~Zone() override
    {
    }

    GameEntity GetType() override
    {
        return GameEntity_Zone;
    }

    int32_t GetId() override
    {
        return Id;
    }

    void SetTransform(Vec Pos, Rotation Rot);
    Transform GetTransform();
    bool IsVisible();
    void SetVisible(bool Status);
    void Destroy();
    void SetColor(int32_t Color);
    void SetHeight(double Height);
    void SetSize(double SizeX, double SizeY);
    Vec GetZoneSize();
    bool IsPointInsideZone(double X, double Y, double Z);
    void SetStyle(int32_t Style);
    int32_t GetStyle();
    bool OverlapEventsEnabled();
    void SetOverlapEventsEnabled(bool Status);
    bool IsPointInsideZoneSphere(Vec Pos);
    AttachResult AttachZoneToEntity(GameEntity EntityType, int32_t EntityId, std::string SocketName);
    std::shared_ptr<VFEntity> GetAttachedEntity(GameEntity GameEntityType, int32_t* EntityId);
    bool IsAttached();
    void Detach();
    void SetCircleShape(bool Status);
    bool IsCircleShaped();

private:
    int32_t Id;
    std::weak_ptr<Registry> Registry;
};
