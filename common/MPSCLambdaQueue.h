#pragma once
#include <queue>

class MPSCLambdaQueue
{
public:
    void Enqueue(std::function<void()> func);
    std::vector<std::function<void()>> GetAll();
    std::function<void()> Dequeue();
    MPSCLambdaQueue()
    {
        
    }
    ~MPSCLambdaQueue()
    {
        
    }

private:
    std::queue<std::function<void()>> queue;
    std::mutex mtx;
    std::vector<std::function<void()>> tasks;
  

};
