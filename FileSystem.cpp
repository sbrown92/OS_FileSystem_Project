

#include <iostream>
#include "diskprocess.h"
#include "FileControlBlock.h"

using namespace std;
	

	int getNextFree(){

		
	}


	//Call getNextFree()
	//Write str into diskBlockType buffer
	//Call  int write(int bnum, DiskBlockType *buffer);
	//Increment size, call getNumBlocks, getBlockSize, do some math with str.length
	bool FileSystem::writeNewBlocks(string str){

		DiskBlockType *buffer;
		//Fill buffer with str			
		for (int i=0; i<str.length(); i++){ 
			buffer->data[i]=str[i];
		}
			if( DiskProcessType::write(getNextFree() , buffer) == 0)
			return true; //Successful write
		else
			return false;//Error
	
	}

	//Write str into diskBlockType buffer
	//int write(int bnum, DiskBlockType *buffer);
	//Increment size if needed
	bool FileSystem::writeExistingBlocks(int blockNum, string str){

		DiskBlockType *buffer;
		//Fill buffer with str			
		for (int i=0; i<str.length(); i++){ 
			buffer->data[i]=str[i];
		}
		if( DiskProcessType::write(blockNum, buffer) == 0)
			return true; //Successful write
		else
			return false;//Error
	}

	//Call int read(int bnum, DiskBlockType *buffer);
	string FileSystem::readBlocks(int startBlock, int endBlock){

		string result;
		DiskBlockType *buffer;
		DiskProcessType::read(startBlock, *buffer);
		
		for(int i=0; i<buffer->data.length(); i++){
			result[i] = buffer->data[i];
		}

		return result;
	}
	
	//Decrement size
	bool FileSystem::freeBlocks(int startBlock, int endBlock){


	}
