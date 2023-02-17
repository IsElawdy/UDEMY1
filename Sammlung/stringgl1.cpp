#include "string1.h"

String global1;             // Definition
String global2("Hallo");    // Definition

void printg1()              // Definition
{
   cout << "global1 = ";
   global1.print();
}


main()
{
  printg1();
  cout << " global2 = ";
  global2.print();
  global1.set("Bye");
  printg1();
}
