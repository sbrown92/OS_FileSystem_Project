//Project Name: CISC3595_team10_atos-fs
//File name: FileControlBlock.h
//Lead Author: Frank Antolino
//Contributing Authors: Sam Brown, Timmy Moran, Catherine Gallagher

#include <iostream>
#include <string>
#include "FileControlBlock.h"

using namespace std;

	FileControlBlock::FileControlBlock(){

	}

	//Directory would call this on create
	FileControlBlock::FileControlBlock(string name){
		fileName = name;
		startBlock = 0;
		endBlock = 0;
		size = 0;
	}

	string FileControlBlock::getFileName(){
		return fileName;
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
