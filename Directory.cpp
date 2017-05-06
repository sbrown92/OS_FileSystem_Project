#include <iostream>
#include "Directory.h"
using namespace std;

  Directory::Directory(){
    
  }

  bool Directory::createFile(string name){


    FileControlBlock f(name);
    dirArray[counter] = f;
    counter++;
    if(!fs.hasFreeSpace(dirArray[counter].getSize())){
      return(false);
    }
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

  int Directory::getFileSize(string name){
    int tmp = search(name);
    return(dirArray[tmp].getSize());
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

  vector<string> Directory::getFileNameList(){
    vector<string> nameList;
    for(int i = 0; i < counter; i++){
      nameList.push_back(dirArray[i].getFileName());
    }
    return(nameList);
  }

  int Directory::search(string name){
    for(int i = 0; i < counter; i++){
      if(dirArray[i].getFileName() == name){
        return(i);
      }
    }
  }

  bool Directory::setContents(string name, string contents){
    int tmp = (fs.saveFileToDisk(getFCB(name).getStart(), (getFCB(name).getEnd()), contents));
    if(tmp = -999)
      return false;
    else{
      getFCB(name).setEnd(tmp);
      return true;
    }
  }

  bool Directory::deleteDir(){
    bool success = false;
    int numDeleted = 0;
    for(int i =0; i < counter; i++){
      deleteFile(dirArray[i].getFileName());
      numDeleted++;
    }
    if(numDeleted == counter)
      success = true;
    return(success);
  }

  string Directory::getContents(string name){
    return(readBlocks(getFCB(name).getStart(), (getFCB(name).getEnd())));
  }
