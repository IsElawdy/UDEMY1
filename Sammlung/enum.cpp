// enum.cpp -- Demonstrate enumerated types
#include <iostream>
using namespace std;
enum LANGUAGE {ASSEMBLY, BASIC, C, CPP, FORTRAN, PASCAL};
enum scale {DO, RE, MI, FA, SOL, LA, TI};
enum {FALSE, TRUE};

main()
{
   scale tone = LA;
   int timeFlies = TRUE;
   LANGUAGE language1, language2;

   language1 = CPP;
   language2 = ASSEMBLY;
   cout << "language1 = " << (int)language1 << '\n';
   cout << "language2 = " << (int)language2 << '\n';
   cout << "lang2 + lang2 = " << (int)(language1+language2) << '\n';
   cout << "tone = " << (int)tone << '\n';
   cout << "timeFlies = " << timeFlies << '\n';
}


// Copyright (c) 1990 by Tom Swan. All rights reserved
// Revision 1.00    Date: 07/14/1990   Time: 05:17 pm
// Changed to the New Standard: 07/24/2004 Andreas Mueller

