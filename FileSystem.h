


#ifndef _FILESYSTEM
#define _FILESYSTEM
#include <vector>
#include <string>
#include "diskprocess.h"

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
		//Return: The pointer to the new file's first block.
		int getFreeBlock();

		// Description: Called By the UI when EDITing a file.
		// Parameters: startblock - The first block of the file.
                //	       endblock: The variable which will store the end block
                //			of the file. Passed by reference because it
                //			is stored along with the return value.
                //             data: The data to be appended to the end of the file.
		// Return: The first block of the file.
		bool saveFileToDisk(int startBlock, int& endBlock, std::string data); 		// <---  Sam


		// Description: Called by the Directory when a file is being deleted.
		// Parameters: startBlock: An int representing pointer to the first block.
		//			   endBlock: An int representing a pointer to the last block.
		// Return: True if file was successfully deleted, False if an error occured.
		bool deleteFileFromDisk(int startBlock, int endBlock);                          // <---  Sam


		//Description: Called by Directory to read data in a file
		// Parameters: startBlock: An int representing pointer to the first block.
		//	       endBlock: An int representing a pointer to the last block.
		//Calls DiskProcessType::read(int bnum, DiskBlockType *buffer);
		//Returns a string of the data in file
		std::string readBlocks(int startBlock, int endBlock);

};

#endif
