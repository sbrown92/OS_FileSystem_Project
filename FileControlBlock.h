//Project Name: CISC3595_team10_atos-fs
//File name: FileControlBlock.h
//Lead Author: Frank Antolino
//Contributing Authors: Sam Brown, Timmy Moran, Catherine Gallagher

#ifndef _FILECONTROLBLOCK
#define _FILECONTROLBLOCK

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "diskprocess.h"

using namespace std;


class FileControlBlock{

	private:
		string fileName;
		int startBlock;
		int endBlock;
		int size;

	public:
		//Directory would call this on create
		FileControlBlock();
		FileControlBlock(string name);
		//Getters
		string getFileName();
		int getStart();
		int getEnd();
		int getSize();
		//Setters
		void setStart(int s);
		void setEnd(int e);
		void increaseSize(int sz);
		void decreaseSize(int sz);

};

#endif
