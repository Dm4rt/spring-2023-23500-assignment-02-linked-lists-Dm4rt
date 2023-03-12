#pragma once
#include <iostream>
#include "Node.h"

class OList{
 private:
  Node *head;
  int length;
 public:
  OList();
  ~OList();
  void insert(std::string data);
  std::string toString();
  bool contains(std::string item);
  std::string get(int loc);
  int getLength();
  void remove(int loc);
  void reverse();
  /*
    
    
  */
  
  

};
