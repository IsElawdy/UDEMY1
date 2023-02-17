#include "string1.h"

void f(const char * st)
{
   static String s1(st);
   s1.print();
}

main()
{
  f("Automatisches");
  f("Objekt");
}
