#pragma once


//std
#include <stdint.h>
#include <stdlib.h>
#include <string>
#include <memory> 
#include <iostream>
#include <functional>
#include <chrono>
#include <thread>
#include <source_location>

//external
#include "ext/easylogging++.h"

//internal
#include "common/Rotation.h"
#include "common/Vec.h"
#include "common/VecWithAngle.h"
#include "common/VFEntity.h"
#include "common/Transform.h"
#include "common/GameTimer.h"
#include "common/MPSCLambdaQueue.h"