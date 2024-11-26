#ifndef PROCESS_H
#define PROCESS_H
#include <iostream>
#include <string>
using namespace std;

class Process {
    string name ;
    int pid ;
    size_t memUsage ;
    public:

    Process(string n="", int p =0, int m=0) {
        name = n;
        pid = p;
        memUsage = m;
    };

    string getName();

    int getPid();

    size_t getMemUsage();



};

#endif //PROCESS_H
