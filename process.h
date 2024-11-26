#ifndef PROCESS_H
#define PROCESS_H

#include <iostream>
#include <string>
using namespace std;

class Process {
    string name ;
    int pid ;
    size_t memUsage ;
    string sessionName ;
    int sessionNum ;

    public:

    Process(string n="", int p =0, int m=0, string sName="", int sNum=0) {
        name = n;
        pid = p;
        memUsage = m;
        sessionName = sName;
        sessionNum = sNum;
    };

    string getName();

    int getPid();

    size_t getMemUsage();

    string getSessionName();

    int getSessionNum();



};

#endif //PROCESS_H
