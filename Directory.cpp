#include <iostream>
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
    for (vector<FileControlBlock>::iterator it = dir.begin() ; it != dir.end(); ++it){
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
  bool deleteFile(string name){
    return(freeSpace(getFCB(name).getFirstPointer(), getFCB(name).getLastPointer()));
  }
  FileControlBlock getFCB(string name){
    for (vector<FileControlBlock>::iterator it = dir.begin() ; it != dir.end(); ++it){
      if(dir[i] == name)
        return(dir[i]);
    }
  }
