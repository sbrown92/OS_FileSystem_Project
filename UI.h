
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

/* ------------------------------------
DEBUG PURPOSES ONLY:
--------------------------------------- */
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
/* --------------------------------------- */

bool nameExists (string filename) {
    vector <string> fileList = getFileNameList();
    bool found = false;
    for (vector<string>::iterator it = fileList.begin() ; it != fileList.end(); ++it){
           if (*it == filename) {
                found = true;
           }
    }
    return found;
}

void create_file(string filename) {

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

void delete_file(string filename) {

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

void dir() {
        vector <string> fileList = getFileNameList();

        cout << "ATOS-FS Directory Listing" << endl;
        cout << "	" << "FILENAME" << "			" << "SIZE (blks)" << endl;
        for (vector<string>::iterator it = fileList.begin() ; it != fileList.end(); ++it){
           cout << "	" << *it << "			" << getSize(*it) << endl;
        }
        // free_space = getFreeSpace();
        // cout << "FREE SPACE " << free_space << " blks"
}

void edit(string filename) {
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
    while (getline(cin, input) && !input.eof()){

    }
    cin.clear();

    return;

}

void type(string filename) {
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

    //string contents = getContents(filename);
    // cout << contents;
    return;
}

// bool exit() {
//     bool success;
//     success = deleteList();
//     return success;
// }
