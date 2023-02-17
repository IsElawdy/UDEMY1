// strops.cpp -- Demonstrate operator overloading

#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
class strop {
   private:
      char value[12];
   public:
      strop() { value[0] = 0; }
      strop(const char *s);

      friend long operator+(strop a, strop b);
      friend long operator-(strop a, strop b);
};

main()
{
   strop a = "1234";
   strop b = "4321";

   cout << "\na + b +  6 == " << a + b + 6;
   cout << "\na - b + 10 == " << a - b + 10;
}

strop::strop(const char *s)
{
   strncpy(value, s, 11);
   value[11] = 0;
}

long operator+(strop a, strop b)
{
   return (atol(a.value) + atol(b.value));
}

long operator-(strop a, strop b)
{
   return (atol(a.value) - atol(b.value));
}


// Copyright (c) 1990 by Tom Swan. All rights reserved
// Revision 1.00    Date: 11/23/1990   Time: 08:00 am
// Changed to the new Standard 07/24/2004 Andreas Mueller
