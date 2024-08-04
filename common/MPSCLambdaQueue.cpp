#include "pch.h"
#include "MPSCLambdaQueue.h"

void MPSCLambdaQueue::Enqueue(std::function<void()> func)
{
    {
        std::lock_guard<std::mutex> lock(mtx);
        queue.emplace(std::move(func));
    }
}

std::vector<std::function<void()>> MPSCLambdaQueue::GetAll()
{
    {
        std::lock_guard<std::mutex> lock(mtx);
        tasks.clear();

        while (!queue.empty()) {
            tasks.push_back(std::move(queue.front()));
            queue.pop();
        }
    }
    return tasks;
}
