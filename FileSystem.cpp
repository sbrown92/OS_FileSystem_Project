

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "DiskProcess.h"
#include "FileSystem.h"


using namespace std;
	
	FileSystem::FileSystem(){
		proc = new DiskProcessType(10, 100);	//Disk Process
		numBlocksUsed = 0;			//Number of blocks currently in use. 

		for(int i = 0; i < proc->getNumBlocks(); i++){
                    freeBlocks.push_back(i);
		}
	}

        
        int FileSystem::getFreeBlock(){
            int newBlock = freeBlocks.back();
            freeBlocks.pop_back();
            numBlocksUsed++;
            
            return newBlock;
            
        }	

    	//Description: Check whether or not the system has free blocks.
	//Return: True if there are free blocks, False if not. 
	bool FileSystem::hasFreeSpace(){
		if(numBlocksUsed == proc->getNumBlocks())
			return false;
		else
			return true;
	}
        
        
        bool FileSystem::saveFileToDisk(int startBlock, int& endBlock, std::string data){
            int temp = (data.length() / (proc->getBlockSize() - 3));
            if(data.length() % (proc->getBlockSize() - 3) != 0)
                temp++;
            
            int currentBlock = this->getFreeBlock();
            for(int i = 0; i < temp; i++){
                std::string test = "";
                
                if(std::to_string(currentBlock).length() == 2)
                    test += "0";
                else if(std::to_string(currentBlock).length() == 1)
                    test += "00";
                
                test += std::to_string(currentBlock);
                test+= data.substr((i * (proc->getBlockSize() - 3)), proc->getBlockSize() - 3);
                
                std::cout<<test<<std::endl;
                
                
                if(i + 2 == temp){
                    endBlock = currentBlock;
                    currentBlock = 0;
                }else
                    currentBlock = this->getFreeBlock();
                
                
            }
            
            
            
            
            
            
        }
        

/*
=======


>>>>>>> d68bc9b4d0b98302f7b5a3d31b24a679f51e91d0
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
	
	//Find how many blocks will be needed
	//Write string into buffer, reserving first three chars for 'next block pointer index'
	//Write to disk on next available block
	//Update this blocks
	bool FileSystem::writeNewBlocks(string str){
		int blocksNeeded = (str.length()/proc.getNumBlocks()) +1;
		int blockSize = proc.getBlockSize();
		int j=0;
		int nextFreeBlock = 0;
		while(blocksNeeded>0){
			DiskBlockType *buffer;
			int i=3;
			while(i<blockSize && j<str.length()){
				buffer->data[i]=str[j];
				i++;
				j++;
			}
			nextFreeBlock = getNextFree();
			if( DiskProcessType::write(nextFreeBlock , buffer) == 0 )
				//Inc size
				//Update freeSpace vector
				//Store next block in first 3 chars of data
				FileControlBlock::increaseSize(1);
				freeSpace[nextFreeBlock] = false;
				buffer->data[2] = (char)nextFreeBlock;
				nextFreeBlock = nextFreeBlock%10;
				buffer->data[1] = (char)nextFreeBlock;
				nextFreeBlock = nextFreeBlock%10;	
				buffer->data[0] = (char)nextFreeBlock;
				blocksNeeded--;
			else
				return false;//Error
		}
		return true; //Successful write
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
*/