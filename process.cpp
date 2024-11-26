#include "process.h"

string Process::getName() {
    return name;
}

int Process::getPid() {
    return pid;
}

size_t Process::getMemUsage() {
    return memUsage;
}

string Process::getSessionName() {
    return sessionName;
}

int Process::getSessionNum() {
    return sessionNum;
}

