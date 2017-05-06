#include <iostream>
#include "Directory.h"
using namespace std;

  Directry::Directory(){
    dir = new vector<FileControlBlock*>();
  }

  bool Directry::createFile(string name){

    if(!hasFreeSpace()){
      return(false);
    }
    dir[counter] = new FileControlBlock(name);
    counter++;
    return(true);
  }

  bool Directry::nameExists(string name){
    bool exists = false;
    for (int i = 0; i < counter; i++){
      if(dir[i] == name){
        exists = true;
      }
    }
    return(exists);
  }

  string Directry::getFileName(int file){
    return(dir[file].getFile());
  }

  int Directry::getFileSize(int file){
    return(dir[file].getSize());
  }

  FileControlBlock Directry::getFCB(string name){
    for(int i = 0; i < counter; i++){
      if(dir[i].getFileName() == name)
        return(dir[i]);
    }
  }
  bool Directry::deleteFile(string name){
    return(deleteFileFromDisk(getFCB(name).getStart(), getFCB(name).getEnd()));
  }
