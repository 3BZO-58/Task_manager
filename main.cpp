#include "process.h"
#include "processList.h"
using namespace std;

int main() {

    ProcessList processList;

    processList.loadProcesses();
    while (true) {
        int choice ;

        cout << "\nwelcome to the process list" << endl;
        cout << "1. display by name\n2. display by PID\n3. display by memory usage\n4. EXIT :" ;
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1: {
                processList.displayByName();
                break;

            }
            case 2: {
                processList.displayByPID();
                break;
            }
            case 3: {
                processList.displayByMemUsage();
                break;
            }
            case 4: {
                cout << "thank you for using the process list" << endl;
                break;

            }
            default: {
                cout << "Invalid choice" << endl;
            }
        }
        if (choice == 4) {
            break;
        }
}


    return 0;
}