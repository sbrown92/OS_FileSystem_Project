#include <iostream>
#include "Directory.h"
using namespace std;

  bool createFile(string name){

    if(!hasFreeSpace()){
      return(false);
    }
    dir[counter] = new FileControlBlock(name);
    counter++;
    return(true);
  }

  bool nameExists(string name){
    bool exists = false;
    for (int i = 0; i < counter; i++){
      if(dir[i] == name){
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
    for(int i = 0; i < counter; i++){
      if(dir[i].getFileName() == name)
        return(dir[i]);
    }
  }
  bool deleteFile(string name){
    return(deleteFileFromDisk(getFCB(name).getStart(), getFCB(name).getEnd()));
  }
