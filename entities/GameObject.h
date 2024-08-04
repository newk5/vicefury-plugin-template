#pragma once

class Registry;

class GameObject : public VFEntity
{
public:
    GameObject(int32_t id, std::shared_ptr<Registry> registry) : Id(id), Registry(registry)
    {
    }

    ~GameObject() override
    {
    }

    GameEntity GetType() override
    {
        return GameEntity_Object;
    }

    int32_t GetId() override
    {
        return Id;
    }

    bool IsDamageable();
    bool HasCollision();
    bool HasTouchEventsEnabled();
    double GetHealth();
    std::string GetName();
    void SetTouchEventsEnabled(bool Value);
    void SetHealth(double Value);
    int32_t GetModelId();
    Vec GetPosition();
    void SetPosition(Vec Pos);
    Rotation GetRotation();
    void SetRotation(Rotation Rot);
    void SetTransform(Vec Pos, Rotation Rot);
    AttachResult AttachToEntity(GameEntity EntityType, int32_t EntityId, std::string SocketName);
    bool IsAttached();
    std::shared_ptr<VFEntity> GetAttachedEntity();
    void Detach();
    void Destroy();
    void SetCollisionEnabled(bool Value);
    bool IsBroken();
    void Restore();
    void SetRestoreAfterBreaking(bool Value);
    void SetRestoreAfterBreakingDelay(float Value);
    bool IsBreakable();
    void SetShowHealthBarWhenDamaged(bool Value);
    void SetDamageable(bool Value);
    void SetVisible(bool Value);
    bool IsVisible();
    void SetOverlapEventsEnabled(bool Value);
    bool HasOverlapEventsEnabled();
    bool IsOverlapping(GameEntity GameEntityTypeType, int32_t EntityId);

private:
    int32_t Id;
    std::weak_ptr<Registry> Registry;
};
