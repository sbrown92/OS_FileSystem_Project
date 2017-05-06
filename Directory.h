#ifndef _DIRECTORY
#define _DIRECTORY

#include <iostream>
#include "FileControlBlock.h"
#include "FileSystem.h"
using namespace std;

class Directory {
public:
  bool createFile(string);

  bool nameExists(string);

  string getFileName(int);

  int getFileSize(int);

  bool deleteFile(string);

  FileControlBlock getFCB(string);

private:
  vector<FileControlBlock*> dir;
  static int counter = 0;
};

#endif
