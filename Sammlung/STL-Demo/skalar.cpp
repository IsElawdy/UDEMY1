// readwr.cpp: Reading and writing a variable number of
//   nonzero integers (followed in the input by 0).
// From: Ammeraal, L. (1997) STL for C++ Programmers,
//       Chichester: John Wiley.
#include <iostream>
#include <vector>

using namespace std;

int skalarprodukt(vector<double>L,vector<double>R,double &skalprod);

int main()
{  vector<double> u;
   vector<double> v;
   int x;
   double sp;
   cout << "Enter positive integers, followed by 0:\n";
   while (cin >> x, x != 0)
      u.push_back(x);
   cout << "Enter positive integers, followed by 0:\n";
   while (cin >> x, x != 0)
      v.push_back(x);
   vector<double>::iterator i;
   cout << "\n Vektor u \n";
   for (i=u.begin(); i != u.end(); ++i) 
      cout << *i << " ";
   cout << "\n Vektor v \n";
   for (i=v.begin(); i != v.end(); ++i) 
      cout << *i << " ";
   cout << endl;
   if (skalarprodukt(u,v,sp))
      cout << "Skalarprodukt: " << sp<< endl;
    else cout << "Skalarprduktberechnung nicht moeglich\n";
   return 0;
}


int skalarprodukt(vector<double>L,vector<double>R,double &skalprod)
{
  int zL, zR;
  skalprod = 0.0;
  vector<double>::iterator iL;
  vector<double>::iterator iR;
  zL = zR = 0;
  for (iL = L.begin(); iL != L.end(); iL++)
    zL++;
  for (iR = R.begin(); iR != R.end(); iR++)
    zR++;
  if (zL != zR)
    return 0;   
  for (iL=L.begin(), iR=R.begin(); iL != L.end();  iL++, iR++)
    skalprod = skalprod + *iL * *iR;
  return 1;
}
  
