#include "pch.h"
#include "Zone.h"
#include "Server.h"
#include "Registry.h"


void Zone::SetTransform(Vec Pos, Rotation Rot)
{
    THREAD_CHECK();
    API->SetZoneTransform(this->Id, Pos.X, Pos.Y, Pos.Z, Rot.Yaw, Rot.Pitch, Rot.Roll);
}

Transform Zone::GetTransform()
{
    THREAD_CHECK_RETURN(Transform());
    double x = -1;
    double y = -1;
    double z = -1;
    double yaw = -1;
    double pitch = -1;
    double roll = -1;
    ViceFuryExitCode ExitCode =API->GetZoneTransform(this->Id, &x, &y, &z, &yaw, &pitch, &roll);
    if (ExitCode != ViceFuryExitCode::ViceFuryExitCode_Success)
    {
        LOG(WARNING) << "Error Calling GetZoneTransform - non Existent ZONE entity for ID: " << this->Id;
    }
    Vec Pos(x, y, z);
    Rotation Rot(yaw, pitch, roll);
    return Transform(Pos, Rot);
}

bool Zone::IsVisible()
{
    EXTRACT_BOOL(ZoneIsVisible, ZONE)
    return result;
}

void Zone::SetVisible(bool Status)
{
    THREAD_CHECK();
    API->SetZoneVisible(this->Id, Status);
}

void Zone::Destroy()
{
    THREAD_CHECK();
    API->DestroyZone(this->Id);
}

void Zone::SetColor(int32_t Color)
{
    THREAD_CHECK();
    API->SetZoneColor(this->Id, Color);
}

void Zone::SetHeight(double Height)
{
    THREAD_CHECK();
    API->SetZoneHeight(this->Id, Height);
}

void Zone::SetSize(double SizeX, double SizeY)
{
    THREAD_CHECK();
    API->SetZoneSize(this->Id, SizeX, SizeY);
}

Vec Zone::GetZoneSize()
{
    EXTRACT_VEC2(GetZoneSize, Zone)
    return result;
}

bool Zone::IsPointInsideZone(double X, double Y, double Z)
{
    EXTRACT_BOOL_THREE_PARAM(IsPointInsideZoneSphere, X, Y, Z, ZONE);
    return result;
}


void Zone::SetStyle(int32_t Style)
{
    THREAD_CHECK();
    API->SetZoneStyle(this->Id, Style);
}

int32_t Zone::GetStyle()
{
    EXTRACT_INT(GetZoneStyle, ZONE)
    return result;
}

bool Zone::OverlapEventsEnabled()
{
    EXTRACT_BOOL(ZoneOverlapEventsEnabled, ZONE)
    return result;
}

void Zone::SetOverlapEventsEnabled(bool Status)
{
    THREAD_CHECK();
    API->SetZoneOverlapEventsEnabled(this->Id, Status);
}

bool Zone::IsPointInsideZoneSphere(Vec Pos)
{
    EXTRACT_BOOL_THREE_PARAM(IsPointInsideZoneSphere, Pos.X, Pos.Y, Pos.Z, ZONE);
    return result;
}

AttachResult Zone::AttachZoneToEntity(GameEntity EntityType, int32_t EntityId, std::string SocketName)
{
    THREAD_CHECK_RETURN(AttachResult_Error_CannotAttach);
    AttachResult Res = API->AttachZoneToEntity(Id, EntityType, EntityId, SocketName.c_str());
    return Res;
}

std::shared_ptr<VFEntity> Zone::GetAttachedEntity(GameEntity GameEntityType, int32_t* EntityId)
{
    GameEntity type = GameEntity_Undefined;
    THREAD_CHECK_RETURN(nullptr);
    int32_t id = -1;
    ViceFuryExitCode ExitCode = API->ZoneGetAttachedEntity(Id, &type, &id);
    if (ExitCode != ViceFuryExitCode::ViceFuryExitCode_Success)
    {
        LOG(WARNING) << "Error Calling GetAttachedEntity - non Existent ZONE entity for ID: " << this->Id;
    }
    return REGISTRY->GetEntity(type, id);
}

bool Zone::IsAttached()
{
    EXTRACT_BOOL(ZoneIsAttached, ZONE)
    return result;
}

void Zone::Detach()
{
    THREAD_CHECK();
    API->DetachZone(this->Id);
}

void Zone::SetCircleShape(bool Status)
{
    THREAD_CHECK();
    API->SetZoneCircleShape(this->Id, Status);
}

bool Zone::IsCircleShaped()
{
    EXTRACT_BOOL(ZoneIsCircleShaped, ZONE)
    return result;
}
