

#include <iostream>
#include "diskprocess.h"
#include "FileControlBlock.h"

using namespace std;
	
	FileSystem::FileSystem(){
		proc  = new DiskProcessType();
		//Initialize freeSpace vector to all true
		for(int i=0; i<proc.getNumBlocks(); i++){
			freeSpace[i] = true;
		}
	}

	int FileSystem::getNextFree(){
		int i=0;
		while(freeSpace[i] != true){
			i++;
		}
		return i;
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
		if( DiskProcessType::write(getNextFree() , buffer) == 0 )
			//Check if string is bigger than block size? split it up
			//Update freeSpace vector
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
			//Check if string is bigger than block size? split it up
			//Update freeSpace vector
			return true; //Successful write
		else
			return false;//Error
	}

	//Dont really need endBlock
	//Call int read(int bnum, DiskBlockType *buffer);
	string FileSystem::readBlocks(int startBlock, int endBlock){

		string result;
		int curBlock = startBlock;
		while(curBlock!=0){
			DiskBlockType *buffer;
			DiskProcessType::read(curBlock, *buffer);
			for(int i=3; i<buffer->data.length(); i++){
				result[i] = buffer->data[i];
			}
			int curBlock = ((int)buffer->data[0] + (int)buffer->data[1] + (int)buffer->data[2]) -1;
		}
		
		return result;
	}
	
	//Decrement size
	//Change corresponding freeSpace indeces to true
	bool FileSystem::freeBlocks(int startBlock, int endBlock){


	}

	string FileSystem::getData(int startBlock, int endBlock){
	
	}
