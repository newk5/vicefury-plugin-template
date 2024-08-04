#pragma once
#include "plugin.h"

class VFEntity
{
public:
    
    virtual ~VFEntity() = default;
    virtual GameEntity GetType();
    virtual int32_t GetId();
};
