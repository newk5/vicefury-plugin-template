#include "pch.h"
#include "Vehicle.h"

#include "Registry.h"
#include "Server.h"
#include "common/Transform.h"


std::shared_ptr<Player> Vehicle::GetDriver()
{
    EXTRACT_INT_RETURN_PLAYER(GetVehicleDriver, VEHICLE)
}

void Vehicle::Destroy()
{
    THREAD_CHECK();
    API->DestroyVehicle(this->Id);
}

float Vehicle::GetHealth()
{
    EXTRACT_FLOAT(GetVehicleHealth, VEHICLE)
    return result;
}

void Vehicle::SetHealth(float Health)
{
    THREAD_CHECK();
    API->SetVehicleHealth(this->Id, Health);
}

Vec Vehicle::GetPosition()
{
    EXTRACT_VEC(GetVehiclePosition, VEHICLE)
    return result;
}

void Vehicle::SetPosition(Vec Pos)
{
    THREAD_CHECK();
    API->SetVehiclePosition(this->Id, Pos.X, Pos.Y, Pos.Z);
}

bool Vehicle::IsPassenger(GameEntity EntType, int32_t EntId)
{
    EXTRACT_BOOL_TWO_PARAM(VehicleIsPassenger, EntType, EntId, VEHICLE)
    return result;
}

bool Vehicle::IsPassenger(std::shared_ptr<VFEntity> PlayerOrNpc)
{
    return IsPassenger(PlayerOrNpc->GetType(), PlayerOrNpc->GetId());
}

bool Vehicle::VehicleIsExploded()
{
    EXTRACT_BOOL(VehicleIsExploded, VEHICLE)
    return result;
}

Transform Vehicle::GetSpawnpoint()
{
    THREAD_CHECK_RETURN(Transform());
    double x = -1;
    double y = -1;
    double z = -1;
    double yaw = -1;
    double pitch = -1;
    double roll = -1;
    ViceFuryExitCode ExitCode = API->GetVehicleSpawnpoint(this->Id, &x, &y, &z, &yaw, &pitch, &roll);
    if (ExitCode != ViceFuryExitCode::ViceFuryExitCode_Success)
    {
        LOG(WARNING) << "Error Calling GetVehicleSpawnpoint - non Existent VEHICLE entity for ID: " << this->Id;
    }
    Vec Pos(x, y, z);
    Rotation Rot(yaw, pitch, roll);
    return Transform(Pos, Rot);
}

void Vehicle::SetSpawnPoint(Vec Pos, Rotation Rot)
{
    THREAD_CHECK();
    API->SetVehicleSpawnPoint(this->Id, Pos.X, Pos.Y, Pos.Z, Rot.Yaw, Rot.Pitch, Rot.Roll);
}

Rotation Vehicle::GetRotation()
{
    EXTRACT_ROT(GetVehicleRotation, VEHICLE)
    return result;
}

void Vehicle::SetRotation(Rotation Rot)
{
    THREAD_CHECK();
    API->SetVehicleRotation(this->Id, Rot.Yaw, Rot.Pitch, Rot.Roll);
}

void Vehicle::SetTransform(Vec Pos, Rotation Rot)
{
    THREAD_CHECK();
    API->SetVehicleTransform(this->Id, Pos.X, Pos.Y, Pos.Z, Rot.Yaw, Rot.Pitch, Rot.Roll);
}


void Vehicle::DetachAllObjects()
{
    THREAD_CHECK();
    API->VehicleDetachAllObjects(this->Id);
}

std::string Vehicle::GetBoneNames()
{
    EXTRACT_STRING(GetVehicleBoneNames, VEHICLE)
    return result;
}

double Vehicle::GetMoveDirection()
{
    EXTRACT_DOUBLE(GetVehicleMoveDirection, VEHICLE)
    return result;
}

bool Vehicle::HasObjectAttached(int32_t ObjectId)
{
    EXTRACT_BOOL_ONE_PARAM(VehicleHasObjectAttached, ObjectId, VEHICLE)
    return result;
}

void Vehicle::DetachObject(int32_t ObjectId)
{
    THREAD_CHECK();
    API->VehicleDetachObject(this->Id, ObjectId);
}
