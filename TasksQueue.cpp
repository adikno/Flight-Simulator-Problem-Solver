//
// Created by adi on 14/01/19.
//

#include "TasksQueue.h"

Task* TasksQueue::pop() {
    std::lock_guard<std::mutex> g(mut);
    if (tasks.empty()) {
        return nullptr;
    }
    auto task = tasks.front();
    tasks.pop();
    return task;
}

bool TasksQueue::empty() const {
    std::lock_guard<std::mutex> g(mut);
    return tasks.empty();
}

void TasksQueue::push(Task* task) {
    if (task == nullptr) {
        throw std::invalid_argument("Task should not be null");
    }
    std::lock_guard<std::mutex> g(mut);
    tasks.push(task);
    queue_cond_var.notify_one();
}

void TasksQueue::wait() const {
    std::unique_lock<std::mutex> ul(mut);
    if (stop_queue) return;
    queue_cond_var.wait(ul);
}

bool TasksQueue::stop() const {
    return stop_queue;
}

void TasksQueue::exit() {
    std::lock_guard<std::mutex> g(mut);
    stop_queue = true;
    queue_cond_var.notify_all();
}