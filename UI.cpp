/*
 File: UI.cpp
 This source file defines the User Interface of the ATOS-FS System.
 It allows the user to choose from the following actions:
 CREATE - Creates a new file with the given name in directory with zero size.
 DELETE - deletes the file specified and deallocates the space associated with it.
 DIR - displays the directory with all files with sizes to the user along with the
    remaining free space.
 TYPE - prints contents of file to user
 EXIT - ends program and deallocates all space. It is a volatile system; files do not
    persist after the run.

 It does error checking and validation to ensure that filenames are valid and 
 prints error messages to users if file operations return errors. 

 For more information on each function, see UI.h.
 
 Lead Author: Cat Gallagher cgallagher28@fordham.edu
 Contributing Authors: Frank Antolino, Timmy Moran, Sam Brown (Group 10)
 Most recent revision: Spring 2017

*/
#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <locale>

using namespace std;

#include "UI.h"

/* ------------------------------------
DEBUG PURPOSES ONLY: 
--------------------------------------- 
vector <string> getFileNameList() {
    vector <string> myvector;
    myvector.push_back("cat");
    myvector.push_back("dog");
    myvector.push_back("fish");
    return myvector;
}

bool createFile(string filename) {
    cout << "I CREATED A FILE: " << filename << endl;
    return true;
}

bool deleteFile(string filename) {
    cout << "I DELETED A FILE: " << filename << endl;
    return true;
}

int getSize(string filename) {
    return 1;
}
bool deleteDir() {
        cout << "DELETED ALL FILES" << endl;
        return true;
}

string getContents (string filename) {
        return "THE CONTENTS!";
}

bool setContents (string filename, string newContents) {
	cout << "NEW CONTENTS:" << endl;
	cout << newContents << endl;
	return true;	
}
 --------------------------------------- */


bool UI::nameExists (string filename) {
    vector <string> fileList = getFileNameList();
    bool found = false;
    for (vector<string>::iterator it = fileList.begin() ; it != fileList.end(); ++it){
           if (*it == filename) {
                found = true;
           }
    }
    return found;
}

void UI::create_file_helper(string filename) {

    /* user must enter a name for it to be created */
    if (filename == "") {
        cerr << "ERROR: Please enter a filename." << endl;
        return;
    }

    /* check for uniqueness */
    if (nameExists(filename)) {
        cerr << "ERROR: DIRECTORY -- Duplicate file name: " << filename << endl;
        return;
    }

    /* check for invalid special characters */
    bool valid = true;
    int num_periods = 0;
    for (int i = 0; i < filename.length(); i++) {
        char c = filename[i];

        if (!(isalnum(c) || c == '-' || c == '_' || c == '.'))
            cerr << "ERROR: DIRECTORY -- Invalid character in file name: " << filename << endl;
            return;
        if (c == '.')
            num_periods++;
    }

    /* number of periods needs to be exactly one */
    if (num_periods == 0) {
        cerr << "ERROR: DIRECTORY -- file names must end with an extension using '.': " << filename << endl;
        return;
    }
    else if (num_periods > 1) {
        cerr << "ERROR: DIRECTORY -- file must not contain more than one period ('.'): " << filename << endl;
        return;
    }


    bool created = createFile(filename);
    if (created == false) {
        cerr << "ERROR: FILESYS -- Blocks could not be allocated: " << filename << endl;
        return;
    }


    return;
}

void UI::delete_file_helper(string filename) {

    /* user must enter a name for it to be deleted */
    if (filename == "") {
        cerr << "ERROR: Please enter a filename." << endl;
        return;
    }

    /* check for uniqueness */
    if (!nameExists(filename)) {
        cerr << "ERROR: DIRECTORY -- File not found: " << filename << endl;
        return;
    }

    bool deleted = deleteFile(filename);
    if (deleted == false) {
        cerr << "ERROR: FILESYS -- Blocks could not be deallocated: " << filename << endl;
        return;
    }

    return;

}

void UI::dir_helper() {
        vector <string> fileList = getFileNameList();

        cout << "ATOS-FS Directory Listing" << endl;
        cout << "       " << "FILENAME" << "            " << "SIZE (blks)" << endl;
        for (vector<string>::iterator it = fileList.begin() ; it != fileList.end(); ++it){
           cout << "    " << *it << "                   " << getSize(*it) << endl;
        }
        
        // free_space = getFreeSpace();
        // cout << "FREE SPACE " << free_space << " blks"
}

void UI::edit_helper(string filename) {
    /* user must enter a name for it to be edited */
    if (filename == "") {
        cerr << "ERROR: Please enter a filename." << endl;
        return;
    }

    /* check for existence */
    if (!nameExists(filename)) {
        cerr << "ERROR: DIRECTORY -- File not found: " << filename << endl;
        return;
    }

    string input = "";
    string contents = "";

    /* get each line of input and append to one string to pass to directory */ 
    while (getline(cin, input)){
        contents += input;
    }
    setContents(filename, contents);
    cin.clear();
    cin.ignore();

    return;

}

void UI::type_helper(string filename) {
    /* user must enter a name for it to be read */
    if (filename == "") {
        cerr << "ERROR: Please enter a filename." << endl;
        return;
    }

    /* check for existence */
    if (!nameExists(filename)) {
        cerr << "ERROR: DIRECTORY -- File not found: " << filename << endl;
        return;
    }

    string contents = getContents(filename);
    cout << contents;
    return;
}

bool UI::exit_helper() {
        bool success;
        success = deleteDir();
        return success;
}


void UI::input() {
    string command;
    string filename;
    string input; 

    istringstream iss;
    cout << "$$ ";

    bool run = true;
    while (run) {
        getline(cin, input);
        iss.str(input);
        iss >> skipws >> command >> filename;       

        if (command == "EXIT"){
                run = false; 
         }
        else {
                if (command == "CREATE") {
                    create_file_helper(filename);
                }
                else if (command == "DELETE") {
                    delete_file_helper(filename);
                }
                else if (command == "DIR") {
                     dir_helper();
                }
                else if (command == "EDIT") {
                        edit_helper(filename);
                }
                else if (command == "TYPE") {
                        type_helper(filename);
                }

                iss.clear();
                cin.clear();

                command = "";
                filename = "";
                cout << "$$ ";
        }
    }
}

