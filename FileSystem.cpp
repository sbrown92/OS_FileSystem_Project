

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "DiskProcess.h"
#include "FileSystem.h"


using namespace std;
	
	FileSystem::FileSystem(){
		proc = new DiskProcessType(14, 100);	//Disk Process
		numBlocksUsed = 0;                      //Number of blocks currently in use. 

                //proc->enableLogging("log.txt");


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


	bool FileSystem::hasFreeSpace(){
		if(numBlocksUsed == proc->getNumBlocks())
			return false;
		else
			return true;
	}
        
        
        //TODO: Add in checks to see if file does not save correctly. 
        bool FileSystem::saveFileToDisk(int startBlock, int& endBlock, std::string data){
            DiskBlockType *buffer = new DiskBlockType(this->proc->getBlockSize());
            int temp = (data.length() / (proc->getBlockSize() - 3));
            if(data.length() % (proc->getBlockSize() - 3) != 0)
                temp++;
                
            
            int indexBlock = startBlock;
            int currentBlock = getFreeBlock();
            for(int i = 0; i < temp; i++){
                std::string test = "";
                
                if(std::to_string(currentBlock).length() == 2)
                    test += "0";
                else if(std::to_string(currentBlock).length() == 1)
                    test += "00";
                
                test += std::to_string(currentBlock);
                test += data.substr((i * (proc->getBlockSize() - 3)), proc->getBlockSize() - 3);

                strcpy(buffer->data, test.c_str());
                if(proc->write(indexBlock, buffer) == -1)
                        return false;
                
                indexBlock = currentBlock;
                if(i + 2 == temp){
                    endBlock = currentBlock;
                    currentBlock = 0;
                }else
                    currentBlock = this->getFreeBlock();
            }
            
            
            return true;
            
        }
        

/*
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
		int blocksNeeded = (str.length()/proc.getNumBlocks()) +1;
		int blockSize = proc.getBlockSize();
		int j=0;
		int nextFreeBlock = 0;
		//Fill buffer with str			
		for (int i=0; i<str.length(); i++){ 
			tbuffer->data[i]=str[i];
		}
		while(blocksNeeded>0){
			DiskBlockType *buffer;
			int i=3;
			while(i<blockSize && j<str.length()){
				buffer->data[i]=str[j];
				i++;
				j++;
			}
			if( DiskProcessType::write(getNextFree() , buffer) == 0 )
				//Inc size
				//Update freeSpace vector
				//Store next block in first 3 chars of data
				FileControlBlock::increaseSize(1);
				nextFreeBlock = getNextFree();
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