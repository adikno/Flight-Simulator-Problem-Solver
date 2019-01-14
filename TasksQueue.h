//
// Created by adi on 14/01/19.
//

#ifndef UNTITLED14_TASKSQUEUE_H
#define UNTITLED14_TASKSQUEUE_H


#include <atomic>
#include <condition_variable>
#include "Task.h"
#include <queue>

class TasksQueue
{
    std::atomic<bool> stop_queue;
    std::queue<Task*> tasks;
    mutable std::condition_variable queue_cond_var;
    mutable std::mutex mut;
public:
    TasksQueue() {
        stop_queue = false;
    }
    Task* pop();

    bool empty() const;

    void push(Task* task);

    void wait() const;

    bool stop() const;

    void exit();
};


#endif //UNTITLED14_TASKSQUEUE_H
