

#ifndef _FILECONTROLBLOCK
#define _FILECONTROLBLOCK

#include <string>
using namespace std;


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
		int getSize();
		void setStart(int s);
		void setEnd(int e);
		void increaseSize(int sz);
		void decreaseSize(int sz);
		//Calls fileSystem function, pass in startBlock as param
		string getData();

};

#endif
