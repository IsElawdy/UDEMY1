#include <iostream>

using namespace std;

int main()
{

  int vektor[1000];
  int i = 0, j;
  int x;
  cout << "Enter positive integers, followed by 0:\n";
  while (cin >> x, x != 0)
    {
      vektor[i] = x;
      i++;
    }
  cout << endl;  
  for ( j = 0; j < i; j++)
    cout << vektor[j] << " ";
  cout << endl;
  return 0;
}
