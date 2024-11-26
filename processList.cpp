#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include "process.h"
#include "processList.h"
void ProcessList::loadProcesses() {
    processes.clear();

    FILE* F = popen("tasklist", "r");
    if (!F) {
        cout << "Error opening tasklist" << endl;
        return;;
    }

    char buffer[256];
    bool hSkipped = false;
    while (fgets(buffer, sizeof(buffer), F)) {
        string line = buffer;
        if (!hSkipped) {
            if (line.find("===") != string::npos) {
                hSkipped = true;
            }
            continue;
        }
        if (line.length() > 0) {
            string name = line.substr(0, 25);
            string pidStr = line.substr(26, 8);
            string sessionName = line.substr(35, 15);
            string sessionNumStr = line.substr(53, 10);
            string memStr = line.substr(65, 12);

            name = name.substr(0, name.find_last_not_of(" \t\n\r") + 1);
            pidStr = pidStr.substr(0, pidStr.find_last_not_of(" \t\n\r") + 1);
            sessionName = sessionName.substr(0, sessionName.find_last_not_of(" \t\n\r") + 1);
            sessionNumStr = sessionNumStr.substr(0, sessionNumStr.find_last_not_of(" \t\n\r") + 1);
            memStr = memStr.substr(0, memStr.find_last_not_of(" \t\n\r") + 1);

            memStr.erase(remove(memStr.begin(), memStr.end(), ','), memStr.end());
            memStr.erase(remove(memStr.begin(), memStr.end(), 'K'), memStr.end());

            int pid = atoi(pidStr.c_str());
            int sessionNum = atoi(sessionNumStr.c_str());
            size_t memUsage = atoi(memStr.c_str());

            processes.emplace_back(name, pid, memUsage,sessionName, sessionNum);
        }
    }
    pclose(F);
}

void ProcessList::addProcess(Process process) {
    processes.push_back(process);
}

void ProcessList::displayProcesses() {
    cout << left << setw(25) << "Process Name"
         << setw(8) << "PID"
         << setw(20) << "Session Name"
         << setw(12) << "Session #"
         << setw(15) << "Memory Usage (KB)" << endl;
    cout << string(80, '-') << endl;

    for (Process& process : processes) {
        cout << left << setw(25) << process.getName()
             << setw(8) << process.getPid()
             << setw(20) << process.getSessionName()
             << setw(12) << process.getSessionNum()
             << setw(15) << process.getMemUsage() << endl;
    }
}

void ProcessList::displayByName() {
    sort(processes.begin(), processes.end(), [](Process &p1, Process &p2)
        {return p1.getName() < p2.getName();});

    displayProcesses();
}

void ProcessList::displayByPID() {
    sort(processes.begin(), processes.end(), [](Process &p1, Process &p2)
        {return p1.getPid() > p2.getPid();});

    displayProcesses();

}

void ProcessList::displayByMemUsage() {
    sort(processes.begin(), processes.end(), [](Process &p1, Process &p2)
        {return p1.getMemUsage() > p2.getMemUsage();});

    displayProcesses();
}

