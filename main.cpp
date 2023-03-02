#include <iostream>
#include "List.h"

int main()
{
  List *l = new List();
  std::cout << l->toString() << " " << l->length() << "\n";
  l->insert(0,"a");
  std::cout << l->toString() << " " << l->length() << "\n";
  l->insert(1,"b");
  l->insert(2,"c");
  l->insert(3,"d");
  l->insert(4,"f");
  std::cout << l->toString() << " " << l->length() << "\n";
  try {
    l->insert(10,"x");
  } catch (std::exception e){
    std::cout <<"Insert x didn't work\n";
  }
 std::cout<<"1 is true and 0 is false \n Contains c ="<<l->contains("c")<<std::endl;
  std::cout<<"Contains f ="<<l->contains("f")<<std::endl;
  l->remove(4);
  std::cout<<"removing f"<<std::endl;
 std::cout<<"Contains f ="<<l->contains("f")<<std::endl;
  delete l;


  return 0;
}
