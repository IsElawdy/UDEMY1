#include <iostream>
#include "string1.h"

using namespace std;

int main()
{
      String s1;
      String s2("High");

      s1.print();
      s1.set("Hallo");
      s1.print();
      s2.print();
      s2.set("Bye");
      s2.print();
} 
