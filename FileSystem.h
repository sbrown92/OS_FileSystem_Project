

#ifndef _FILESYSTEM
#define _FILESYSTEM

class FileSystem{

	private:
		int remainingBlocks;
		int blocksInUse;

		//Search for next free block, linearly through vector? or keep track of nextFree somewhere else
		//Can check remainingBlocks first to save time, exit if none left
		int getNextFree();

	public:
		

		//Call getNextFree()
		//Write str into diskBlockType buffer
		//Call  int write(int bnum, DiskBlockType *buffer);
		//Increment size
		bool writeNewBlocks(string str);

		//Write str into diskBlockType buffer
		//int write(int bnum, DiskBlockType *buffer);
		//Increment size if needed
		bool writeExistingBlocks(int blockNum, string str);

		//Call int read(int bnum, DiskBlockType *buffer);
		string readBlocks(int startBlock, int endBlock);
		
		//Decrement size
		bool freeBlocks(int startBlock, int endBlock);



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