#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Task {
    string name;
    int priority;
    int executionTime;
};

bool compare(Task a, Task b) {
    return a.priority > b.priority; // higher priority first
}

class Scheduler {
private:
    vector<Task> tasks;

public:
    void addTask(string name, int priority, int time) {
        tasks.push_back({name, priority, time});
    }

    void run() {
        sort(tasks.begin(), tasks.end(), compare);

        cout << "Running Tasks in Priority Order:\n\n";

        for (auto &task : tasks) {
            cout << "Executing: " << task.name << endl;
            cout << "Priority: " << task.priority << endl;
            cout << "Time: " << task.executionTime << "ms\n\n";
        }

        cout << "All tasks completed.\n";
    }
};

int main() {
    Scheduler scheduler;

    scheduler.addTask("Load UI", 2, 150);
    scheduler.addTask("Authenticate User", 5, 300);
    scheduler.addTask("Fetch Data", 4, 200);
    scheduler.addTask("Render Dashboard", 3, 250);

    scheduler.run();

    return 0;
}