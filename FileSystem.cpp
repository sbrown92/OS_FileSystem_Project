

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
        

	int FileSystem::getNextFree(){
		int i=0;
		while(freeSpace[i] != true){
			i++;
		}
		return i;
	}

	string FileSystem::readBlocks(int startBlock, int endBlock){
		string result;
		int curBlock = startBlock;
		int j=0;
		while(curBlock!=0){
			DiskBlockType *buffer;
			DiskProcessType::read(curBlock, *buffer);
			for(int i=3; i<buffer->data.length(); i++){
				result[j] = buffer->data[i];
				j++;
			}
			int curBlock = ((((int)buffer->data[0])*100) + (((int)buffer->data[1])*10) + (int)buffer->data[2]) - 1;
		}
		
		return result;
	}

	//Decrement size
	//Change corresponding freeSpace indeces to true
	bool FileSystem::freeBlocks(int startBlock, int endBlock){
		int curBlock = startBlock;
		int tmp = 0;
		while(curBlock!=endBlock){//Go through list of blocks for file
			tmp = curBlock; //Hold block position
			//Move to next block in file's position
			curBlock = ((((int)buffer->data[0])*100) + (((int)buffer->data[1])*10) + (int)buffer->data[2]) - 1;
			//Set data in block to NULL
			proc[tmp]->data = NULL;
			//tmp block is now free again
            freeBlocks.push_back(tmp);
		}
		
	}
