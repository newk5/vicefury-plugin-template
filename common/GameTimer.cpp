#include "pch.h"
#include "GameTimer.h"



void GameTimer::Cancel()
{
    this->PendingCancellation = true;
}

bool GameTimer::ShouldRun()
{
    if (LastTick == 0)
    {
        LastTick = currentTimeMillis();
    }
    int64_t Current = currentTimeMillis();
    int64_t Delta = Current - LastTick;
    return  Delta >= Interval;
}

void GameTimer::Process()
{
    LastTick = currentTimeMillis();
    HasRun = true;
    codeToRun(*this);
}

int64_t GameTimer::currentTimeMillis()
{
    auto now = std::chrono::system_clock::now();
    auto duration = now.time_since_epoch();
    return std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
}
