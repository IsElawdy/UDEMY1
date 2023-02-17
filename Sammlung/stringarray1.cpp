#include "string1.h"

main()
{
  int i;
  String strings[5] = {"mo","di","mi","do"};
  /* oder
  strings[0].set("Montag");
   ...
  strings[4].set("Freitag");
  */
  for (i = 0; i < 5; i++)
    strings[i].print();
}
