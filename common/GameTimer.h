#pragma once


class GameTimer
{
public:
    GameTimer() = default;

    void Cancel();
    bool ShouldRun();
    void Process();

    GameTimer(bool recurring, int64_t interval,const std::function<void(GameTimer& Timer)>& code_to_run)
        : codeToRun(code_to_run),
          Recurring(recurring),
          Interval(interval)
    {
    }
    bool IsPendingCancellation() const
    {
        return PendingCancellation;
    }

    bool IsRecurring() const
    {
        return Recurring;
    }
  
    bool HasRunOnce() const
    {
        return HasRun;
    }

    //a timer is considered expired if it's not recurring and has already ran once 
    bool HasExpired()
    {
        return !IsRecurring() && HasRunOnce();
    }

private:
    std::function<void(GameTimer& Timer)> codeToRun;
    bool Recurring = false;
    bool PendingCancellation = false;
    bool HasRun = false;
    int64_t LastTick = 0;
    int64_t Interval = 0;
    int64_t currentTimeMillis();
};
