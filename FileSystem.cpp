


#include "FileSystem.h"


using namespace std;
	
FileSystem::FileSystem(){
	int bsize
	proc = new DiskProcessType(14, 100);	//Disk Process
	freeBlocks = new vector<int>();
	numBlocksUsed = 0;                      //Number of blocks currently in use. 



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


bool FileSystem::hasFreeSpace(int fileSize){
    int numRequired = fileSize/proc->getBlockSize();
    if(fileSize % proc->getBlockSize() != 0)
        numRequired += 1;
                
	if((proc->getNumBlocks() - numBlocksUsed) < numRequired)
		return false;
	else
		return true;
}
    
        
// TODO: Add in checks to see if file does not save correctly. 
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

// Description: Called by Directory when a file is to be deleted
// Parameters: startBlock: An int representing pointer to the first block.
//	       endBlock: An int representing a pointer to the last block.
//Returns true if successful, false otherwise
bool FileSystem::deleteFileFromDisk(int startBlock, int endBlock) {
    DiskBlockType *buffer = new DiskBlockType(bsize);
    
    int currentBlock = startBlock;
        
            do{
                string next = "";
                if (proc->read(currentBlock, buffer) != -1){
                    std::cout<<std::strlen(buffer->data)<<std::endl;
                    for(int i = 0; i < std::strlen(buffer->data); i++){
                        if(i < 3){
                            next += buffer->data[i];
                        }
                        buffer->data[i] = '.';

                    }
                    if(proc->write(currentBlock, buffer) == -1){
                    	std::cout<<"ERROR: Couldn't write blank file at block: " << std::endl;
                    	return false;
                    }
                    freeBlocks.push_back(currentBlock);
                    numBlocksUsed--;
                    currentBlock = std::atoi(next.c_str());
                } else {
                	std::cout<<"ERROR: Counldn't open file at block: " + currentBlock << std::endl;
                	return false;
                }
    }while(currentBlock != 0);
    
    return true;
        
}	
        

	int FileSystem::getNextFree(){
		return freeBlocks.back();
	}

	// Description: Called by Directory to read data in a file
	// Parameters: startBlock: An int representing pointer to the first block. 
	//	       endBlock: An int representing a pointer to the last block. 
	// Calls DiskProcessType::read(int bnum, DiskBlockType *buffer);
	// Returns a string of the data in file
	string FileSystem::readBlocks(int startBlock, int endBlock){
    string result = "";
    DiskBlockType* buffer = new DiskBlockType(bsize);
    int currentBlock = startBlock;
    do{
        string next = "";
        if(proc->read(currentBlock, buffer) != -1){
            for(int i = 0; i < std::strlen(buffer->data); i++){
                if(i < 3){
                    next += buffer->data[i];
                } else {
                    result += buffer->data[i];
                }
            }
        } else {
            std::cout<<"ERROR: Failed to open file at: " << currentBlock << std::endl;
        }
        currentBlock = std::atoi(next.c_str());
    }while(currentBlock != 0);
    
    return result;
}
