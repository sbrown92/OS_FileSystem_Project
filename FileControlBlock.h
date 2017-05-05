

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

		int getStart();
		int getEnd();
		int getSize();
		void setStart(int s);
		void setEnd(int e);
		void increaseSize(int sz);
		void decreaseSize(int sz);

};

#endif
