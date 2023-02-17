// fncount.cpp -- Function demonstration

#include <iostream>
using namespace std;
void countup(int value);
void countdown(int value);

main()
{
   countup(20);
   countdown(10);
}

void countup(int value)
{
   int i;

   cout << "\n\nCounting up\n";
   for (i = 1; i <= value; i++)
      cout << dec(i, 8);
}

void countdown(int value)
{
   int i;

   cout << "\n\nCounting down\n";
   for (i = value; i >= 1; i--)
      cout << dec(i, 8);
}


// Copyright (c) 1990 by Tom Swan. All rights reserved
// Revision 1.00    Date: 08/22/1990   Time: 08:39 am
// Changed to the New Standard 07/24/2004 Andreas Mueller

