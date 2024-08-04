#include "pch.h"
#include "VehicleEvents.h"
#include "entities/Server.h"
#include "Registry.h"

std::shared_ptr<Registry> VehicleEvents::Registry;
std::shared_ptr<Server> VehicleEvents::Server;

float VehicleEvents::OnVehicleReceiveDamage(int32_t VehicleId, DamageEvent ev)
{
    std::shared_ptr<Vehicle> Vehicle = Registry->GetVehicle(VehicleId);
    
    return ev.DamageToApply;
}

void VehicleEvents::OnVehicleExploded(int32_t VehicleId)
{
    std::shared_ptr<Vehicle> Vehicle = Registry->GetVehicle(VehicleId);
}

void VehicleEvents::OnVehicleCreated(int32_t VehicleId)
{
    Registry->RegisterNewVehicle(VehicleId);
    std::shared_ptr<Vehicle> Vehicle = Registry->GetVehicle(VehicleId);
}

void VehicleEvents::OnVehicleDestroyed(int32_t VehicleId)
{
    std::shared_ptr<Vehicle> Vehicle = Registry->GetVehicle(VehicleId);

    
    Registry->UnregisterVehicle(VehicleId);
}
