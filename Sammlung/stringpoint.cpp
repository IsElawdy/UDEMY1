#include "string1.h"

String * f (const char * str)
{
  return new String(str);
}

main()
{
  String * ps = f("Objekt");
  ps -> print();
  cout << f("im Freispeicher")->length() << endl;
  delete ps;
}
