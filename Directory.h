//Project Name: CISC3595_team10_atos-fs
//File name: Directory.h
//Lead Author: Timmy Moran
//Contributing Authors: Frank Antolino, Sam Brown, Catherine Gallagher

#ifndef _DIRECTORY
#define _DIRECTORY

#include <iostream>
#include "FileControlBlock.h"
#include "FileSystem.h"
using namespace std;

class Directory {
public:
  Directory();

  bool createFile(string);

  bool nameExists(string);

  string getName(int);

  int getFileSize(string);

  bool deleteFile(string);

  FileControlBlock getFCB(string);

  vector<string> getFileNameList();

  int search(string);

  bool setContents(string, string);

  bool deleteDir();

  string getContents(string name);

private:
  int counter = 0;
  FileControlBlock dirArray[1000];
  FileSystem fs;
};

#endif
