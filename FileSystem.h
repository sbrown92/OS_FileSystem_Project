


#ifndef _FILESYSTEM
#define _FILESYSTEM
#include <vector>
#include "DiskProcess.h"

class FileSystem{

	private:
		DiskProcessType* proc;
        	int numBlocksUsed;
		std::vector<int>freeBlocks;
                
		//Description: Function to get the next free block from the disk process. 
		//Return: A pointer to the next free block. 
		int getNextFree();


	public:
		

		//Class Constructor. 
		FileSystem();											// <---- Sam

		//Description: Check whether or not the system has free blocks.
		//Return: True if there are free blocks, False if not. 
		bool hasFreeSpace();									


		//Description: Called by the directory when a new file is added to 
		// 			   they system. 
		//Returnn: The pointer to the new file's first block. 
		int createFile();									
	
		// Description: Called By the UI when EDITing a file.
		// Parameters: startblock - The first block of the file. Value will
		//							only be changed if this is the first time
		//							the file is being written too.  
		//			   endblock: The variable which will store the end block 
		//						  of the file. Passed by reference because it
		//						  is stored along with the return value. 
		//			  data: The data to be appended to the end of the file. 
		// Return: The first block of the file. 
		bool saveFileToDisk(int& startBlock, int& endBlock, std::string data); 		// <---  Sam


		// Description: Called by the Directory when a file is being deleted. 
		// Parameters: startBlock: An int representing pointer to the first block. 
		//			   endBlock: An int representing a pointer to the last block. 
		// Return: True if file was successfully deleted, False if an error occured. 
		bool deleteFileFromDisk(int startBlock, int endBlock);                          // <---  Sam



		//Call int read(int bnum, DiskBlockType *buffer);
		std::string readBlocks(int startBlock, int endBlock);
		

};

#endif