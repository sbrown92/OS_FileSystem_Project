/*
 File: diskprocess.h
 This include file defines the class for a disk emulation process that
 will serve as the lowest level of a file system.
 There is one class DiskBlockType which defines what a block is, and
 one class DiskProcess that defines the disk and operations on the disk. 
 The constructor can be parameterized by
 the size of the disk blocks and the number of disk blocks on the disk.
 The class provides routines for reading and writing blocks to the disk.
 Some statistics are kept on disk usage and can be printed as a log,
 and disk accesses can be logged -for debugging pruposes.

 Author: D.M. Lyons dlyons@fordham.edu
 Most recent revision: Spring 2016
 
 If you use this program or any part of it you need to incude this entire
 comment. No warranty or support implied.
 
 c dmlyons 2012- 2016 Fordham CIS.
*/

#ifndef _DISKPROCESS
#define _DISKPROCESS

#define ERROR_RETURN -1
#define SUCCESS_RETURN 0

// This class define what a bock on a disk is

class DiskBlockType {
 public:
  int blockSize;
  char *data;        //pointer to the data on the disk
  DiskBlockType(int bsize) { // constructor makes the block
    blockSize=bsize;
    data = new char[bsize];
    for (int i; i<bsize; i++) data[i]='.';
  }
  ~DiskBlockType(){ // destructor frees the block
    delete data;
  }
};

// this class defines what a disk is and has some member functions for
// interacting with the disk

class DiskProcessType {
 private:
  int blockSize;      // the size of a single block on disk
  int numBlocks;      // the number of this on the disk
  int numCreated;     // how blocks were actually used so far
  int numReads;       // how many read operations performaed
  int numWrites;      // how many write oeprations peformed
  int currentBlock;   // the block use din last write/write
  bool logging;       // is debug logging enabled
  ofstream logfile;   // the file to log debug info to if logging
  vector<DiskBlockType*> disk; // this is the data for the disk

  bool createBlock(int blockNumber); // ceate a bock where none was before
  
 public:

  DiskProcessType(int bsize, int bnum) {// mke the disk
    blockSize=bsize;
    numBlocks=bnum;
    numCreated=numReads=numWrites=currentBlock=0;
    for (int i=0; i<numBlocks; i++)
      disk.push_back(NULL); // initialize block ptrs
  };

  ~DiskProcessType() { // clean up the disk nicely
    for (int i=0; i<numBlocks; i++)
      if (disk[i]!=NULL) // block was used
	delete disk[i]; // so free it up
    if (logging) {
      logfile << "DISK: Terminating.\n";
      logfile << "DISK: Blocks created were "<<numCreated<<" of total "
	      <<numBlocks<<" which is "
	      <<100*float(numCreated)/float(numBlocks)<<" %\n";
      logfile.close();
    }
  }

  int getBlockSize() { return blockSize; }
  int getNumBlocks() { return numBlocks; }
  
  // read a block from the disk. Will create the block data
  // if it did not exist yet
  int read(int bnum, DiskBlockType *buffer);
  
  // write a block to the disk. Will create the block data
  // if it did not exist yet.
  int write(int bnum, DiskBlockType *buffer);

  // enable logging for the disk to a named file
  bool enableLogging(string logfileName);

  // write out any disk stats collected. Goes to log if logging enabled
  // otherwise no output.
  void writeStats();
};

/* END OF FILE */
#endif
