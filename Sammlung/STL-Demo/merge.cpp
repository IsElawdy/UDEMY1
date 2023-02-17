// merge.cpp: Merging a vector and an array into a list.
// From: Ammeraal, L. (1997) STL for C++ Programmers,
//       Chichester: John Wiley.

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int main()
{  vector<int> a(5);
   int n;
   cin >> n;
   a[0] = 2; a[1] = 3; a[2] = 8; 
   a[3] = 20; a[4] = 25;
   int b[6] = {7, 9, 23, 28, 30, 33};
   list<int> c(n); // List c is initially empty
   //merge(a.begin(), a.end(), b, b+6, 
   //   inserter(c, c.begin()));
   merge(a.begin(), a.end(), b, b+6, c.begin());
   list<int>::iterator i;
   for (i=c.begin(); i != c.end(); ++i)
      cout << *i << " ";
   cout << endl;
   return 0;
}
