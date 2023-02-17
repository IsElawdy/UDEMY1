// readwr.cpp: Reading and writing a variable number of
//   nonzero integers (followed in the input by 0).
// From: Ammeraal, L. (1997) STL for C++ Programmers,
//       Chichester: John Wiley.
#include <iostream>
#include <vector>

using namespace std;

int main()
{  vector<int> v;
   int x;
   cout << "Enter positive integers, followed by 0:\n";
   while (cin >> x, x != 0)
      v.push_back(x);
   vector<int>::iterator i;
   for (i=v.begin(); i != v.end(); ++i) 
      cout << *i << " ";
   cout << endl;
   cout << "Ausgabe des letzten Elementes \n";
   i = v.end();
   i--;
   cout << *i << endl;
   return 0;
}
