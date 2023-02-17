// static.cpp -- Demonstrate static variables

#include <iostreampp>
using namespace std;
int next1(void);
int next2(void);

main()
{
   int i;

   cout << "\nCalling next1():\n";
   for (i = 1; i <= 10; i++)
      cout << " " << next1();
   cout << "\nCalling next2():\n";
   for (i = 1; i <= 10; i++)
      cout << " " << next2();
}

int next1(void)
{
   static int value = 1;      // Static variable

   return value++;
}

int next2(void)
{
   int value = 1;             // Normal local variable

   return value++;
}


// Copyright (c) 1990 by Tom Swan. All rights reserved
// Revision 1.00    Date: 07/14/1990   Time: 12:00 am
// Changed to the new Standard 07/24/2004 Andreas Mueller


