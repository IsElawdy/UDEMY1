#include "stringgl.h"

main()
{
  printg1();
  cout << " global2 = ";
  global2.print();
  global1.set("Bye");
  printg1();
}
