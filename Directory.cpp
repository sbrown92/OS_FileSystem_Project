#include <iostream>
#include "Directory.h"
using namespace std;

  bool createFile(string name){

    if(!hasFreeSpace()){
      return(false);
    }
    FileControlBlock f(name);
    dirArray[counter] = f;
    counter++;
    return(true);
  }

  bool nameExists(string name){
    bool exists = false;
    for (int i = 0; i < counter; i++){
      if(dirArray[i].getFileName() == name){
        exists = true;
      }
    }
    return(exists);
  }

  string getFileName(int file){
    return(dirArray[file].getFile());
  }

  int getFileSize(int file){
    return(dirArray[file].getSize());
  }

  FileControlBlock getFCB(string name){
    for(int i = 0; i < counter; i++){
      if(dirArray[i].getFileName() == name)
        return(dirArray[i]);
    }
  }
  bool deleteFile(string name){
    return(deleteFileFromDisk(getFCB(name).getStart(), getFCB(name).getEnd()));
  }
