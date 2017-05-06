#include <iostream>
#include "Directory.h"
using namespace std;

  bool createFile(string name){
    if(!fs.hasFreeSpace()){
      return(false);
    }
    dir[counter] = new FileControlBlock(name);
    counter++;
    return(true);
  }

  bool nameExists(string name){
    bool exists = false;
    for (vector<FileControlBlock>::iterator it = dir.begin() ; it != dir.end(); ++it){
      if(it.getFileName() == name){
        exists = true;
      }
    }
    return(exists);
  }

  string getFileName(int file){
    return(dir[file].getFile());
  }

  int getFileSize(int file){
    return(dir[file].getSize());
  }

  FileControlBlock getFCB(string name){
    for (vector<FileControlBlock>::iterator it = dir.begin() ; it != dir.end(); ++it){
      if(*it->getFileName() == name)
        return(*it);
    }
  }
  bool deleteFile(string name){
    return(fs.deleteFileFromDisk(getFCB(name).getStart(), getFCB(name).getEnd()));
  }
