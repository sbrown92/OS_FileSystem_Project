#ifndef _DIRECTORY
#define _DIRECTORY


#include <iostream>
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
  vector<FileControlBlock> dir = new vector();
  counter = 0;
};

#endif
