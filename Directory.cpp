#include <iostream>
#include "Directory.h"
using namespace std;

  bool Directory::createFile(string name){

    if(!fs.hasFreeSpace()){
      return(false);
    }
    FileControlBlock f(name);
    dirArray[counter] = f;
    counter++;
    return(true);
  }

  bool Directory::nameExists(string name){
    bool exists = false;
    for (int i = 0; i < counter; i++){
      if(dirArray[i].getFileName() == name){
        exists = true;
      }
    }
    return(exists);
  }

  string Directory::getName(int file){
    return(dirArray[file].getFileName());
  }

  int Directory::getFileSize(int file){
    return(dirArray[file].getSize());
  }

  FileControlBlock Directory::getFCB(string name){
    for(int i = 0; i < counter; i++){
      if(dirArray[i].getFileName() == name)
        return(dirArray[i]);
    }
  }
  bool Directory::deleteFile(string name){
    return(fs.deleteFileFromDisk(getFCB(name).getStart(), getFCB(name).getEnd()));
  }
