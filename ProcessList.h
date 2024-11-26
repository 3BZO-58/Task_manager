#ifndef PROCESSLIST_H
#define PROCESSLIST_H
#include <vector>
#include <algorithm>
#include <iostream>
#include "Process.h"
using namespace std;
class ProcessList {
    vector<Process> processes;
    public:
    void addProcess(Process process);
    void loadProcesses();
    void displayProcesses();
    void displayByName();
    void displayByPID();
    void displayByMemUsage();
};

#endif //PROCESSLIST_H
