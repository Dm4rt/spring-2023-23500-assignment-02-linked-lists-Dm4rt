#include <iostream>
#include "Node.h"
#include <string>
#include "OList.h"

OList::OList(){
  head = nullptr;
  length=0;
}

OList::~OList(){
  std::cerr << "Calling the destructor\n";
  Node *walker = head;
  Node *trailer = nullptr;
  while (walker != nullptr){
    trailer=  walker;
    walker = walker->getNext();
    std::cerr << "Deleting " << trailer->getData() << ", ";
    delete trailer;
  }
  std::cerr << "\n";
  
  
}
void OList::insert(std::string data){
  int loc=length;
  for(int x=0;x<length;x++){
  	if(stoi(data)<stoi(get(x))){
  		loc=x;
  		break;
  	}
  }
  Node *walker, *trailer;
  walker = this->head; // start of the list
  trailer = nullptr; // one behind
  
  while(loc>0 && walker != nullptr){
    loc=loc-1;

    /* trailer will always be one node
       behind walker */
    trailer=walker;
    walker = walker->getNext();
    
  }
  
  //Make sure no out of bounds
  if (loc > 0){
    throw std::out_of_range("Our insert is out of range");
  }

  Node *newNode = new Node(data);
  //If at loc 0, or trailer = 0;
  if (trailer == nullptr){
    newNode->setNext(head);
    head = newNode;
  } else {
    newNode->setNext(walker);
    trailer->setNext(newNode);
  }
  
  //make sure to increment length
  length++;
}

bool OList::contains(std::string item){
  Node *walker = head;
  while (walker != nullptr && walker->getData() != item){
    walker = walker->getNext();
  }
  if (walker == nullptr){
    return false;
  } else {
    return true;
  }
}
std::string OList::get(int loc){
  Node *walker = head;
  int curLoc=0;
  while (walker != nullptr && curLoc!=loc){
    walker = walker->getNext();
    curLoc++;
  }
  if (walker == nullptr){
    return "";
  } else {
    return walker->getData();
  }
  
}

void OList::remove(int loc){
  Node *walker, *trailer;
  walker = this->head; // start of the list
  trailer = nullptr; // one behind
  
  while(loc>0 && walker != nullptr){
    loc=loc-1;
    trailer=walker;
    walker = walker->getNext();
  }

  if (walker == nullptr){
    throw std::out_of_range("Tried to remove out of range");
  }

  if (trailer == nullptr){
    // we're removing the first item in the list
    head = walker->getNext();
    delete walker;
  } else {
    // general case of having a node before the
    // node to delete
    trailer->setNext(walker->getNext());
    delete walker;
  }
  

}


std::string OList::toString(){
  Node *tmp = this->head;
  std::string result = "";
  while (tmp != nullptr){
    result = result + tmp->getData();
    result = result + "-->";
    tmp = tmp->getNext();
  }
  result = result + "nullptr";
  return result;
}

int OList::getLength(){
	return this->length;
}
void OList::reverse(){
	Node *walker, *trailer;
	  walker = this->head; // start of the list
	  trailer = nullptr; // one behind
	  int curInd=length-1;
	  
	  while(walker != nullptr&&curInd>length/2){
	    
	    trailer=walker;
	    Node *newNode = new Node(get(curInd));
		    newNode->setNext(walker);
		    trailer->setNext(newNode);
	    walker = walker->getNext();
	    curInd++;
		    
	  }
	delete walker;
	delete trailer;
}
