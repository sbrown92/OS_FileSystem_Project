#include <iostream>
using namespace std;

class Directory {
public:
  //Constructor
  Directory(string name){
    createNode(name);
  }
  //Create New Node
  bool createNode(string name){
    bool success = true;
    listNode * newNode = new listNode;
    newNode->name = name;
    newNode->fcb = FileControlBlock(name);
    newNode->next = NULL;
    if(head == NULL){
      head = newNode;
      tail = head;
    }
    else{
      tail->next = newNode;
      tail = newNode;
    }
    if(!hasFreeSpace())
      success = false;
    return(success);
  }
void printList(){
  listNode *ptr = head;
  while (ptr != NULL){
    cout << ptr->name  << " -> ";
    ptr = ptr->next;
  }
}
bool nameExists(string name){
  listNode *ptr = head;
  bool exists = false;
  while (ptr != NULL){
    if(ptr->name == name)
      isValid = true;
    ptr = ptr->next;
  }
  return(exists);
}


private:

  struct listNode {
    string name;
    FileControlBlock fcb;
    listNode *next;
  }

  listNode *head = NULL;
  listNode *tail = NULL;



};
