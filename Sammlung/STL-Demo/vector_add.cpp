// readwr.cpp: Reading and writing a variable number of
//   nonzero integers (followed in the input by 0).
// From: Ammeraal, L. (1997) STL for C++ Programmers,
//       Chichester: John Wiley.
#include <iostream>
#include <vector>

using namespace std;
int dimension (const vector<int> &L)
{
  int x = 0;
  vector<int>::const_iterator i;
  for ( i = L.begin(); i != L.end(); i++)
      x++;
  return x;
}

vector<int>   addition (const vector<int> &L, const vector<int> &R)
{
  vector<int>::const_iterator i;
  vector<int>::const_iterator j;
  vector<int>::iterator k;
  int x = 0;
  for (i=L.begin(); i != L.end(); ++i) 
     x++;
  vector<int> E(x);
  j = R.begin();
  k = E.begin();
  for (i=L.begin(); i != L.end(); ++i) 
            {
              *k = *i + * j;
              k++;
              j++;
            }
  return E;
}

int main()
{  vector<int> v;
   vector<int> w;
   vector<int> u;
   int x,y,z;
   cout << "Enter positive integers, followed by 0:\n";
   while (cin >> x, x != 0)
      v.push_back(x);
   cout << "Enter positive integers, followed by 0:\n";
   while (cin >> x, x != 0)
      w.push_back(x);
   y = dimension(v);  
   z = dimension(w);  
   if ( y != z)
      cout << "Addition nicht möglich \n";
    else 
      {
         u = addition(v,w);
         vector<int>::iterator i;
         for (i=u.begin(); i != u.end(); ++i) 
             cout << *i << " ";
       }
   cout << endl;
   return 0;
}
