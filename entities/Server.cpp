#include "pch.h"
#include "Server.h"

#include "Registry.h"
#include "common/GameTimer.h"

void Server::SendChatMessageToAll(std::string Msg, uint32_t Color)
{
    THREAD_CHECK();
    API->SendChatMessageToAll(Color, Msg.c_str());
}

void Server::SendChatMessageToAll(std::string Msg)
{
    THREAD_CHECK();
    uint32_t White = 0xFFFFFFFF;
    API->SendChatMessageToAll(White, Msg.c_str());
}

void Server::SendChatMessageToPlayer(int32_t PlayerId, std::string Msg, uint32_t Color)
{
    THREAD_CHECK();
    API->SendChatMessageToPlayer(PlayerId, Msg.c_str(), Color);
}

bool Server::PlayerExists(int32_t PlayerId)
{
    THREAD_CHECK_RETURN(false);
    return API->PlayerExists(PlayerId);
}

bool Server::NPCExists(int32_t NpcId)
{
    THREAD_CHECK_RETURN(false);
    return API->NPCExists(NpcId);
}

bool Server::VehicleExists(int32_t VehicleId)
{
    THREAD_CHECK_RETURN(false);
    return API->VehicleExists(VehicleId);
}


void Server::SpawnNPC(NPCSpawnProperties& Props)
{
    THREAD_CHECK();
    API->SpawnNPC(Props);
}

void Server::SendData(int32_t PlayerId, std::string Channel, std::string Data)
{
    THREAD_CHECK();
    API->SendData(PlayerId, Channel.c_str(), Data.c_str());
}

Vec Server::GetRandomPoint(Vec Origin, double Radius)
{
    THREAD_CHECK_RETURN(Vec());
    double xResult = -1;
    double yResult = -1;
    double zResult = -1;
    bool foundPoint = API->GetRandomPoint(Origin.X, Origin.Y, Origin.Z, Radius, &xResult, &yResult, &zResult);
    if (!foundPoint)
    {
        LOG(WARNING) << "Failed to find random point";
    }
    return Vec(xResult, yResult, zResult);
}

Rotation Server::FindRotationLookingAt(Vec FromPos, Vec ToPos)
{
    THREAD_CHECK_RETURN(Rotation());
    double outYaw = -1;
    double outPitch = -1;
    double outRoll = -1;
    API->FindRotationLookingAt(FromPos.X, FromPos.Y, FromPos.Z, ToPos.X, ToPos.Y, ToPos.Z, &outYaw, &outPitch,
                               &outRoll);

    return Rotation(outYaw, outPitch, outRoll);
}

Vec Server::FindDirectionLookingAt(Vec FromPos, Vec ToPos)
{
    THREAD_CHECK_RETURN(Vec());
    double x = -1;
    double y = -1;
    double z = -1;
    API->FindDirectionLookingAt(FromPos.X, FromPos.Y, FromPos.Z, ToPos.X, ToPos.Y, ToPos.Z, &x, &y, &z);

    return Vec(x, y, z);
}

void Server::SetSpawnScreenLocation(Vec Pos, double YawLookAt)
{
    THREAD_CHECK();
    API->SetSpawnScreenLocation(Pos.X, Pos.Y, Pos.Z, YawLookAt);
}

void Server::SpawnObject(ObjectSpawnProperties& Props)
{
    THREAD_CHECK();
    API->SpawnObject(Props);
}

void Server::CreateEntitySocket(GameEntity EntityType, EntitySocket Socket)
{
    THREAD_CHECK();
    API->CreateEntitySocket(EntityType, Socket);
}

void Server::SetTime(float Time)
{
    THREAD_CHECK();
    API->SetTime(Time);
}

float Server::GetTime()
{
    THREAD_CHECK_RETURN(0.f);
    return API->GetTime();
}

void Server::SpawnZone(ZoneSpawnProperties& Props)
{
    THREAD_CHECK();
    API->SpawnZone(Props);
}

void Server::SetLowTPSWarningLimit(int32_t Limit)
{
    THREAD_CHECK();
    API->SetLowTPSWarningLimit(Limit);
}

int32_t Server::GetServerTPS()
{
    THREAD_CHECK_RETURN(0);
    return API->GetServerTPS();
}

void Server::SpawnWeapon(int32_t WeaponId, Vec Pos, int32_t Ammo)
{
    THREAD_CHECK();
    API->SpawnWeapon(WeaponId, Pos.X, Pos.Y, Pos.Z, Ammo);
}

void Server::GiveWeaponToPlayer(int32_t PlayerId, int32_t WeaponId, int32_t Ammo)
{
    THREAD_CHECK();
    API->GiveWeaponToPlayer(WeaponId, PlayerId, Ammo);
}

void Server::GiveWeaponToShooterNPC(int32_t NpcId, int32_t WeaponId, int32_t Ammo)
{
    THREAD_CHECK();
    API->GiveWeaponToShooterNPC(NpcId, WeaponId, Ammo);
}

void Server::PutNpcInVehicle(int32_t NpcId, int32_t VehicleId)
{
    THREAD_CHECK();
    API->PutNpcInVehicle(NpcId, VehicleId);
}

double Server::GetWaterLevel()
{
    THREAD_CHECK_RETURN(0);
    double out = -1;
    API->GetWaterLevel(&out);
    return out;
}

void Server::SetWaterLevel(double Level)
{
    THREAD_CHECK();
    API->SetWaterLevel(Level);
}

std::string Server::GetConfigProperty(std::string Section, std::string Property)
{
    THREAD_CHECK_RETURN("");
    char* out = nullptr;
    API->GetConfigProperty(Section.c_str(), Property.c_str(), &out);
    return std::string(out);
}

void Server::SpawnVehicle(VehicleSpawnProperties& Props)
{
    THREAD_CHECK();
    API->SpawnVehicle(Props);
}

void Server::SetServerName(std::string Name)
{
    THREAD_CHECK();
    API->SetServerName(Name.c_str());
}

std::string Server::GetServerName()
{
    THREAD_CHECK_RETURN("");
    const char* n = API->GetServerName();
    return std::string(n);
}

std::string Server::GetServerPassword()
{
    THREAD_CHECK_RETURN("");
    const char* n = API->GetServerPassword();
    return std::string(n);
}

void Server::SetServerPassword(std::string Password)
{
    THREAD_CHECK();
    API->SetServerPassword(Password.c_str());
  
}

std::string Server::GetServerVersion()
{
    THREAD_CHECK_RETURN("");
   
    const char* n = API->GetServerVersion();
    return std::string(n);
}

Rotation Server::CreateRotationFromAxes(Vec FwdDirection, Vec RightDirection, Vec UpDirection)
{
    THREAD_CHECK_RETURN(Rotation());
    double OutYaw = -1;
    double OutPitch = -1;
    double OutRoll = -1;
    API->CreateRotationFromAxes(
        FwdDirection.X, FwdDirection.Y, FwdDirection.Z,
        RightDirection.X, RightDirection.Y, RightDirection.Z,
        UpDirection.X, UpDirection.Y, UpDirection.Z, &OutYaw, &OutPitch, &OutRoll);

    return Rotation(OutYaw, OutPitch, OutRoll);
}

std::shared_ptr<GameTimer> Server::CreateTimer(int64_t IntervalMs, bool IsRecurring,
                                               std::function<void(GameTimer& Timer)> codeToRun)
{
  
    std::shared_ptr<GameTimer> Timer = std::make_shared<GameTimer>(IsRecurring, IntervalMs, codeToRun);
    if (REGISTRY->IsOnMainThread())
    {
        REGISTRY->AddTimer(Timer);
    }else
    {
        this->MainThread([this,Timer]
        {
            REGISTRY->AddTimer(Timer);
        });
    }
   
    return Timer;
}

std::shared_ptr<GameTimer> Server::Every(int64_t IntervalMs, std::function<void(GameTimer& Timer)> codeToRun)
{
    return CreateTimer(IntervalMs, true, codeToRun);
}

std::shared_ptr<GameTimer> Server::Delay(int64_t IntervalMs, std::function<void(GameTimer& Timer)> codeToRun)
{
    return CreateTimer(IntervalMs, false, codeToRun);
}

void Server::MainThread(std::function<void()> codeToRun)
{
    REGISTRY->AddToQueue(std::move(codeToRun));
}
