#include "pch.h"
#include "GameObject.h"
#include "Server.h"
#include "Registry.h"


bool GameObject::IsDamageable()
{
    EXTRACT_BOOL(GameObjectIsDamageable, OBJECT)
    return result;
}

bool GameObject::HasCollision()
{
    EXTRACT_BOOL(GameObjectHasCollision, OBJECT)
    return result;
}

bool GameObject::HasTouchEventsEnabled()
{
    EXTRACT_BOOL(GameObjectHasTouchEventsEnabled, OBJECT)
    return result;
}

double GameObject::GetHealth()
{
    EXTRACT_DOUBLE(GetGameObjectHealth, OBJECT)
    return result;
}

std::string GameObject::GetName()
{
    EXTRACT_STRING(GetGameObjectName, OBJECT)
    return result;
}

void GameObject::SetTouchEventsEnabled(bool Value)
{
    THREAD_CHECK();
    API->SetGameObjectTouchEventsEnabled(this->Id, Value);
}

void GameObject::SetHealth(double Value)
{
    THREAD_CHECK();
    API->SetGameObjectHealth(this->Id, Value);
}

int32_t GameObject::GetModelId()
{
    EXTRACT_INT(GetGameObjectModelId, OBJECT)
    return result;
}

Vec GameObject::GetPosition()
{
    EXTRACT_VEC(GetGameObjectPosition, OBJECT)
    return result;
}

void GameObject::SetPosition(Vec Pos)
{
    THREAD_CHECK();
    API->SetGameObjectPosition(this->Id, Pos.X, Pos.Y, Pos.Z);
}

Rotation GameObject::GetRotation()
{
    EXTRACT_ROT(GetGameObjectRotation, OBJECT)
    return result;
}

void GameObject::SetRotation(Rotation Rot)
{
    THREAD_CHECK();
    API->SetGameObjectRotation(this->Id, Rot.Yaw, Rot.Pitch, Rot.Roll);
}

void GameObject::SetTransform(Vec Pos, Rotation Rot)
{
    THREAD_CHECK();
    API->SetGameObjectTransform(this->Id, Pos.X, Pos.Y, Pos.Z, Rot.Yaw, Rot.Pitch, Rot.Roll);
}

AttachResult GameObject::AttachToEntity(GameEntity EntityType, int32_t EntityId, std::string SocketName)
{
    THREAD_CHECK_RETURN(AttachResult_Error_CannotAttach);
    AttachResult Res = API->AttachGameObjectToEntity(Id, EntityType, EntityId, SocketName.c_str());
    if (Res != AttachResult_Success)
    {
        LOG(WARNING) << "Failed to attach Object to entity, ErrorCode: " << Res;
    }
    return Res;
}

bool GameObject::IsAttached()
{
    EXTRACT_BOOL(GameObjectIsAttached, OBJECT)
    return result;
}

std::shared_ptr<VFEntity> GameObject::GetAttachedEntity()
{
    THREAD_CHECK_RETURN(nullptr);
    GameEntity type = GameEntity_Undefined;
    int32_t id = -1;
    ViceFuryExitCode ExitCode = API->GameObjectGetAttachedEntity(Id, &type, &id);
    if (ExitCode != ViceFuryExitCode::ViceFuryExitCode_Success)
    {
        LOG(WARNING) << "Error Calling GetAttachedEntity - non Existent GAMEOBJECT entity for ID: " << this->Id;
    }
    return REGISTRY->GetEntity(type, id);
}

void GameObject::Detach()
{
    THREAD_CHECK();
    API->GameObjectDetach(this->Id);
}

void GameObject::Destroy()
{
    THREAD_CHECK();
    API->DestroyGameObject(this->Id);
}

void GameObject::SetCollisionEnabled(bool Value)
{
    THREAD_CHECK();
    API->SetGameObjectCollisionEnabled(this->Id, Value);
}

bool GameObject::IsBroken()
{
    EXTRACT_BOOL(GameObjectIsBroken, OBJECT)
    return result;
}

void GameObject::Restore()
{
    THREAD_CHECK();
    API->GameObjectRestore(this->Id);
}

void GameObject::SetRestoreAfterBreaking(bool Value)
{
    THREAD_CHECK();
    API->SetGameObjectRestoreAfterBreaking(this->Id, Value);
}

void GameObject::SetRestoreAfterBreakingDelay(float Value)
{
    THREAD_CHECK();
    API->SetGameObjectRestoreAfterBreakingDelay(this->Id, Value);
}

bool GameObject::IsBreakable()
{
    EXTRACT_BOOL(GameObjectIsBreakable, OBJECT)
    return result;
}

void GameObject::SetShowHealthBarWhenDamaged(bool Value)
{
    THREAD_CHECK();
    API->SetGameObjectShowHealthBarWhenDamaged(this->Id, Value);
}

void GameObject::SetDamageable(bool Value)
{
    THREAD_CHECK();
    API->SetGameObjectDamageable(this->Id, Value);
}

void GameObject::SetVisible(bool Value)
{
    THREAD_CHECK();
    API->SetGameObjectVisible(this->Id, Value);
}

bool GameObject::IsVisible()
{
    EXTRACT_BOOL(GameObjectIsVisible, OBJECT)
    return result;
}

void GameObject::SetOverlapEventsEnabled(bool Value)
{
    THREAD_CHECK();
    API->SetGameObjectOverlapEventsEnabled(this->Id, Value);
}

bool GameObject::HasOverlapEventsEnabled()
{
    EXTRACT_BOOL(GameObjectHasOverlapEventsEnabled, OBJECT)
    return result;
}

bool GameObject::IsOverlapping(GameEntity GameEntityTypeType, int32_t EntityId)
{
    EXTRACT_BOOL_TWO_PARAM(GameObjectIsOverlapping, GameEntityTypeType, EntityId, OBJECT)
    return result;
}
