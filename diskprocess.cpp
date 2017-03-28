/*
 File: diskprocess.cpp
 This source file defines  a disk emulation process that
 will serve as the lowest level of a file system.
 In the include file, there is one class DiskBlockType 
 which defines what a block is, and  one class DiskProcess that defines 
 the disk and operations on the disk. Constructors and destructors are
 defined in the include file. The remaining function implementations
 are in this file.


 Author: D.M. Lyons dlyons@fordham.edu
 Most recent revision: Spring 2016
 
 If you use this program or any part of it you need to incude this entire
 comment. No warranty or support implied.
 
 c dmlyons 2012- 2017 Fordham CIS.
*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#include "diskprocess.h"

 // private member function to create a block if it has
 // never been accessed before
bool DiskProcessType::createBlock(int blockNumber) {
  if (blockNumber<numBlocks)  {
    disk[blockNumber] = new DiskBlockType(blockSize);
    numCreated++;
    return true;
  }
  else {
      cerr<<"DISK: Tried to create a block beyond the disk size\n";
      return false;
  }
}


  // read a block from the disk. Will create the block data
  // if it did not exist yet
int DiskProcessType::read(int bnum, DiskBlockType *buffer){
  if (bnum<0 || bnum>=numBlocks) {
    cerr<<"DISK: Block number is outside bounds\n";
    return ERROR_RETURN;
  }
  if (buffer->blockSize != blockSize) {
    cerr<<"DISK: Bad block size sent to read.\n";
    return -1;
  }
  if (disk[bnum]==NULL) // not ceated yet
    if (!createBlock(bnum)) // is it possible to create?
      return ERROR_RETURN; // bad block number create request

  // do the data write
  if (buffer->data!=NULL && disk[bnum]->data!=NULL) {
    for (int i=0; i<blockSize; i++)
      buffer->data[i] = disk[bnum]->data[i]; 
    numReads++;
  }
  else cerr<<"DISK: Bad buffer pointers sent to read\n";
  
  // do logging if enabled
  if (logging) 
    logfile<<"DISK: Read to block "<<bnum<<"\n";
  return 0;
}
  
  // write a block to the disk. Will create the block data
  // if it did not exist yet.
int DiskProcessType::write(int bnum, DiskBlockType *buffer){
  if (bnum<0 || bnum>=numBlocks) {
    cerr<<"DISK: Block number is outside bounds\n";
    return ERROR_RETURN;
  }
  if (buffer->blockSize != blockSize) {
    cerr<<"DISK: bad block size sent to write.\n";
    return ERROR_RETURN;
  }
  if (disk[bnum]==NULL) // not ceated yet
    if (!createBlock(bnum)) // is it possible to create?
      return ERROR_RETURN; // bad block number create request

  // do the data write
  if (buffer->data!=NULL && disk[bnum]->data!=NULL) {
    for (int i=0; i<blockSize; i++)
      disk[bnum]->data[i] = buffer->data[i];
    numWrites++;
  }
  else cerr<<"DISK: Bad buffer pointers sent to write\n";
  
  // do logging if enabled
  if (logging) 
    logfile<<"DISK: Write to block "<<bnum<<"\n";
  return 0;
}

  // enable logging for the disk to a named file
bool DiskProcessType::enableLogging(string logfileName){
  logfile.open(logfileName);
  if (logfile.is_open()) { // did the file open?
    logging = true;
    logfile<<"DISK: Logging enabled to "<<logfileName<<"\n";
    logfile<<"DISK: block size "<<blockSize
	  <<" number of blocks "<<numBlocks<<"\n"; 
  } else cerr<<"DISK: Could not open "<<logfileName<<"\n";
  return logging;
}

  // write out any disk stats collected. Goes to log if logging enabled
  // otherwise no output.
void DiskProcessType::writeStats() {
    logfile<< "DISK: block size "<<blockSize
	   << " number of blocks "<<numBlocks<<"\n";
    logfile << "DISK: Num reads "<<numReads
	    << " Num writes "<<numWrites<<"\n";
    logfile << "DISK: Blocks created were "<<numCreated<<" of total "
	    << numBlocks<<" which is "
	    << 100*float(numCreated)/float(numBlocks)<<" %\n";
  
    return;
}


/* END OF FILE */
