#include "process.h"
#include "processList.h"
using namespace std;

int main() {

    ProcessList processList;

    processList.loadProcesses();
    while (true) {
        int choice ;

        cout << "\nwelcome to the process list" << endl;
        cout << "1. display by name\n2. display by PID\n3. display by memory usage :" ;
        cin >> choice;
        switch (choice) {
            case 1: {
                processList.displayByName();

            }
            case 2: {
                processList.displayByPID();
            }
            case 3: {
                processList.displayByMemUsage();
            }
            default: {
                cout << "Invalid choice" << endl;
            }
        }
}


    return 0;
}