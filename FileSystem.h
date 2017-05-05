


#ifndef _FILESYSTEM
#define _FILESYSTEM
#include <vector>;
#include "DiskProcessType.h"

class FileSystem{

	private:
		int remainingBlocks;
		int blocksInUse;
		vector<bool> freeSpace = new vector();
		DiskProcessType proc;




		//Description: Function to get the next free block from the disk process. 
		//Return: A pointer to the next free block. 
		int getNextFree();


	public:
		

		//Class Constructor. 
		FileSystem();											// <---- Sam

		//Description: Check whether or not the system has free blocks.
		//Return: True if there are free blocks, False if not. 
		bool hasFreeSpace();									// <---  Sam 


		//Description: Called by the directory when a new file is added to 
		// 			   they system. 
		//Returnn: The pointer to the new file's first block. 
		int createFile();										// <---- Sam
	
		// Description: Called By the UI when EDITing a file.
		// Parameters: startblock - The first block of the file. Value will
		//							only be changed if this is the first time
		//							the file is being written too.  
		//			   endblock: The variable which will store the end block 
		//						  of the file. Passed by reference because it
		//						  is stored along with the return value. 
		//			  data: The data to be appended to the end of the file. 
		// Return: The first block of the file. 
		bool saveFileToDisk(int& startBlock, int& endBlock, string data); 		// <---  Sam




		//Call int read(int bnum, DiskBlockType *buffer);
		string readBlocks(int startBlock, int endBlock);
		
		//Decrement size
		bool freeBlocks(int startBlock, int endBlock);

		string getData(int startBlock, int endBlock);

}

/*Use this for getNextFree function?

int FileSystem::getFreeBlock(){
	int blockIndex = 0;
	if (freespace->getBlockSize() != 0){
		blockIndex = freespace->getBlockPointer();//save block location
		freespace->setBlockSize(freespace->getBlockSize()-1);//decrement freespace size
		freespace->setBlockPointer(freespace->getBlockPointer()+1);//move freespace pointer forward
	}
	else{
		blockIndex = -1;
	}
	cout << "freespace blocks left = " << freespace->getBlockSize() << "/" << DISK_SIZE << endl;
	return blockIndex;
}

*/
