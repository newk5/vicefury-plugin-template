#pragma once
#include "common/Transform.h"

class Registry;

class Vehicle : public VFEntity
{
public:
    Vehicle(int32_t id, std::shared_ptr<Registry> registry) : Id(id), Registry(registry)
    {
    }

    ~Vehicle() override
    {
    }

    GameEntity GetType() override
    {
        return GameEntity_Vehicle;
    }

    int32_t GetId() override
    {
        return Id;
    }


    std::shared_ptr<class Player> GetDriver();
    void Destroy();
    float GetHealth();
    void SetHealth(float Health);
    Vec GetPosition();
    void SetPosition(Vec Pos);
    bool IsPassenger(GameEntity EntType, int32_t EntId);
    bool IsPassenger(std::shared_ptr<VFEntity> PlayerOrNpc);
    bool VehicleIsExploded();
    Transform GetSpawnpoint();
    void SetSpawnPoint(Vec Pos, Rotation Rot);
    Rotation GetRotation();
    void SetRotation(Rotation Rot);
    void SetTransform(Vec Pos, Rotation Rot);
    void DetachAllObjects();
    std::string GetBoneNames();
    double GetMoveDirection();
    bool HasObjectAttached(int32_t ObjectId);
    void DetachObject(int32_t ObjectId);

private:
    int32_t Id;
    std::weak_ptr<Registry> Registry;
};
