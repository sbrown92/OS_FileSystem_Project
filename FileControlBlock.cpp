

#include <iostream>
#include "FileControlBlock.h"

using namespace std;


	//UI would call this on create
	FileControlBlock::FileControlBlock(string name){
		fileName = name;
		startBlock = NULL;
		endBlock = NULL;
		size = 0;
	}

	string FileControlBlock::writeData(string str){
		//Calls fileSystem function, pass in startBlock as param
		FileSystem::writeExistingBlocks(startBlock, str);
		//Updates blocks
		//Update size
	}
	
	int FileControlBlock::getStart(){
		return startBlock;
	}
	
	int FileControlBlock::getEnd(){
		return endBlock;
	}

	string FileControlBlock::getData(){
		//Calls fileSystem function, pass in startBlock as param
	}








class Directory{

//Array of FileControlBlocks





}