

#include <iostream>
using namespace std;


class FileControlBlock{

	private:

		string fileName;
		int startBlock;
		int endBlock;
		int size;

	public:

		//UI would call this on create
		FileControlBlock(string name){
			fileName = name;
			startBlock = NULL;
			endBlock = NULL;
			size = 0;
		}


		string writeData(string str){
			//Calls fileSystem function, pass in startBlock as param
			FileSystem::writeExistingBlocks(startBlock, str);
			//Updates blocks
			//Update size
		}

		int getStart(){
			return startBlock;
		}
		
		int getEnd(){
			return endBlock;
		}
		string getData(){
			//Calls fileSystem function, pass in startBlock as param
		}

}






class Directory{

//Array of FileControlBlocks





}