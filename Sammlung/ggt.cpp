#include <iostream>
using namespace std;

int ggt_1 (int A, int B)
{
 if (!B || A == B)
	return A;
 if (!A)
	return B;
 return ggt_1(B, A % B);
}
int ggt_2 (int A, int B)
{
  if (!B || A==B)
      return A;
  if (!A)
     return B;
  if ( A > B  ) return ggt_2(B,A);
  return ggt_2( A, B - A );
}
int ggt_3 (int A, int B)
{
  while(A != B)
    if (A > B) A -= B;
    else B-=A;
  return A;
}
int ggt_4 (int A, int B)
{               // Iterative Variante von 1.
  int rest;
  while (B>0)
   { 
      rest = A % B;
      A = B;
      B = rest;
   }
 return A;
}  
main()
{
  int a,b;
  char w = 'j';
  while (w == 'j')
   {
     cout << "Eingabe a und b\n";
     cin >> a >> b;
     cout << "GGT    " << ggt_1(a,b) << " 2. Variante " << ggt_2(a,b)<< endl;
     cout << "GGT 3. " << ggt_3(a,b) << " 4. Variante " << ggt_4(a,b)<< endl;
     cout << "Weiter?\n";
     cin >> w;
   }
}
