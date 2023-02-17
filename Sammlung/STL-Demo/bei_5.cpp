// sort1.c: Sorting a vector.
// From: Ammeraal, L. (1997) STL for C++ Programmers,
//       Chichester: John Wiley.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{  vector<int> v;
   int x;
   cout << "Enter positive integers, followed by 0:\n";
   while (cin >> x, x != 0) v.push_back(x);
   vector<int>::iterator i;
   cout << "Before sorting :\n";
   for (i=v.begin(); i != v.end(); ++i)
      cout << *i << " ";
   cout << endl;
   sort(v.begin(), v.end());
   cout << "After sorting: \n";
   for (i=v.begin(); i != v.end(); ++i) 
      cout << *i << " ";
   cout << endl;
   return 0;
}
