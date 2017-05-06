#include <iostream>
#include "Directory.h"
using namespace std;

  Directory::Directory(){
    dir = new vector<FileControlBlock>();
  }

  bool Directory::createFile(string name){

    if(!hasFreeSpace()){
      return(false);
    }
    dir[counter] = new FileControlBlock(name);
    counter++;
    return(true);
  }

  bool Directory::nameExists(string name){
    bool exists = false;
    for (int i = 0; i < counter; i++){
      if(dir[i] == name){
        exists = true;
      }
    }
    return(exists);
  }

  string Directory::getFileName(int file){
    return(dir[file].getFile());
  }

  int Directory::getFileSize(int file){
    return(dir[file].getSize());
  }

  FileControlBlock Directory::getFCB(string name){
    for(int i = 0; i < counter; i++){
      if(dir[i].getFileName() == name)
        return(dir[i]);
    }
  }
  bool Directory::deleteFile(string name){
    return(deleteFileFromDisk(getFCB(name).getStart(), getFCB(name).getEnd()));
  }
