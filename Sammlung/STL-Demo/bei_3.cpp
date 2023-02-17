// readwr.cpp: Reading and writing a variable number of
//   nonzero integers (followed in the input by 0).
// From: Ammeraal, L. (1997) STL for C++ Programmers,
//       Chichester: John Wiley.
#include <iostream>
#include <deque>

using namespace std;

int main()
{  deque<int> v;
   int x;
   cout << "Enter positive integers, followed by 0:\n";
   while (cin >> x, x != 0)
      v.push_back(x);
   deque<int>::iterator i;
   for (i=v.begin(); i != v.end(); ++i) 
      cout << *i << " ";
   cout << endl;
   return 0;
}
