#include "string1.h"

int main()
{
   String * strings = new String[5];
   int i;
   
   strings[0].set("mo");
   strings[1].set("di");
   strings[2].set("mi");
   strings[3].set("do");
   strings[4].set("fr");
  
   for (i=0; i < 5; i++)
      strings[i].print();
  
   delete[]strings;
}
  
