// void.cpp -- Type-cast demonstration

#include <ciostream>
#include <dos.h>
using namespace std;
void disp_pointer(void *p);

main()
{
   int value;
   int *vptr;

   vptr = &value;
   value = 1234;
   cout << "Value = " << value << "\n";
   cout << "vptr  = " << *vptr << "\n";

   cout << "address of value = ";
   disp_pointer (&value);

   cout << "address where vptr points = ";
   disp_pointer (vptr);
}


void disp_pointer(void *p)
{
   cout << FP_SEG(p) << ":" << FP_OFF(p) << '\n';
}


// Copyright (c) 1990 by Tom Swan. All rights reserved
// Revision 1.00    Date: 08/27/1990   Time: 03:12 pm
// Changed to the new Standard 07/24/2004 Andreas Mueller
