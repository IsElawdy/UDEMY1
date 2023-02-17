// strops2.cpp -- Demonstrate member operator overloading

#include <iostream>
#include <cstdlib>
#include <cstring>

class strop {
   private:
      char value[12];
   public:
      strop() { value[0] = 0; }
      strop(const char *s);

      long operator+(strop b);
      long operator-(strop b);
};

main()
{
   strop a = "1234";
   strop b = "4321";

   cout << "\na + b == " << a + b + 6;
   cout << "\na - b == " << a - b + 10;
}

strop::strop(const char *s)
{
   strncpy(value, s, 11);
   value[11] = 0;
}

long strop::operator+(strop b)
{
   return (atol(value) + atol(b.value));
}

long strop::operator-(strop b)
{
   return (atol(value) - atol(b.value));
}


// Copyright (c) 1990 by Tom Swan. All rights reserved
// Revision 1.00    Date: 11/23/1990   Time: 08:00 am
// Changed to the new Standard 07/24/2004 Andreas Mueller
