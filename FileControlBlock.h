

#ifndef _FILECONTROLBLOCK
#define _FILECONTROLBLOCK

class FileControlBlock{

	private:
		string fileName;
		int startBlock;
		int endBlock;
		int size;

	public:
		//UI would call this on create
		FileControlBlock(string name);

		//Calls fileSystem function, pass in startBlock as param
		//Updates blocks
		//Update size
		string writeData(string str);
		
		int getStart();
		
		int getEnd();
		void increaseSize(int sz);
		void decreaseSize(int sz);
		//Calls fileSystem function, pass in startBlock as param
		string getData();

}

#endif
