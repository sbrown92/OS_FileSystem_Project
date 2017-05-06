/*
 File: UI.h

 This file details the functions used by the UI to execute the commands
 given by the user.

 Lead Author: Cat Gallagher cgallagher28@fordham.edu
 Contributing Authors: Frank Antolino, Timmy Moran, Sam Brown (Group 10)
 Most recent revision: Spring 2017

*/
#ifndef UI_H
#define UI_H

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "Directory.h"

using namespace std;

class UI {
    public:

    UI(); // default constructor
    Directory d; //creates directory on construction
    /*
    Description: Checks that a file with the given name exists in directory.
    Parameters: filename - name to be checked
    Returns: true if file exists, false if not
     */
    bool nameExists (string filename);

    /*
    Description: Creates a file with the given name in directory.
    Parameters: filename - name of file to be made
     */
    void create_file_helper(string filename);

    /*
    Description: Deletes the file with the given name exists in directory.
    Parameters: filename - name to be deleted
     */
    void delete_file_helper(string filename);

    /*
    Description: Displays all file names, their sizes, and amount of remaining free space.
     */
    void dir_helper();

    /*
    Description: Edits the given file by allowing the user to enter text to append to the file.
    Parameters: filename - file to be edited
     */
    void edit_helper(string filename);

    /*
    Description: Reads the given file and outputs its contents to the user.
    Parameters: filename - file to be read
     */
    void type_helper(string filename);

    /*
    Description: Deletes all files and deallocates their space.
    Returns: true if successful, false if not
    */
    bool exit_helper();

    /*
    Description: Sets up commandline prompt to allow users to input commands.
     */
    void input();

};

#endif
