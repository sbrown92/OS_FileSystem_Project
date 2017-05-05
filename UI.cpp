
#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <locale>

using namespace std;

#include "UI.h"


int main() {
    string command;
    string filename;
    string input; 

    istringstream iss;
    cout << "$$ ";

    while (1) {
        getline(cin, input);
        iss.str(input);
        cout << input <<endl;
        iss >> skipws >> command >> filename;       

        if (command == "CREATE") {
            create_file(filename);
        }
        else if (command == "DELETE") {
            delete_file(filename);
        }
        else if (command == "DIR") {
            dir();
        }
        else if (command == "EDIT") {
            edit(filename);
        }
        else if (cin.eof())
        {
            
        }

        // else if command == "TYPE" {
            // check file exists
        //     type(); 
        // }
        // else if command == "EXIT" {
        //     exit();
            // check for successful deletion of everything
        // }

        iss.clear();
        cin.clear();
        command = "";
        filename = "";
        cout << "$$ ";

    }

    return 0;
}
UI.cpp
Open with Code Your Cloud
Displaying UI.h.