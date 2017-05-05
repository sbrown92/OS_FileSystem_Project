

#include <iostream>
#include <string>
#include "FileControlBlock.h"

using namespace std;


	//UI would call this on create
	FileControlBlock::FileControlBlock(string name){
		fileName = name;
		startBlock = -1;
		endBlock = -1;
		size = 0;
	}

	int FileControlBlock::getStart(){
		return startBlock;
	}
	
	int FileControlBlock::getEnd(){
		return endBlock;
	}
	
	int FileControlBlock::getSize(){
		return size;
	}

	void FileControlBlock::setStart(int s){
		startBlock = s;
	}
	void FileControlBlock::setEnd(int e){
		endBlock = e;
	}

	void FileControlBlock::increaseSize(int sz){
		size+=sz;	
	}
	
	void FileControlBlock::decreaseSize(int sz){
		size-=sz;
	}

	string FileControlBlock::getData(){
		//Calls fileSystem function, pass in startBlock as param
	}

