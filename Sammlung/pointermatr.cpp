#include <iostream>
using namespace std;

main()
{
  int i,j;
  int x,y;
  int ** m;        //Zeiger auf int-Zeiger
  cout << "Eingabe x und y \n";
  cin >> x >> y;
  m = new int*[x]; //Feld von x int-Pointern
  for (i=0; i < x; i++)
     m[i] = new int[y]; //Feld von y int

  for (i = 0; i < x; i++)
     for (j = 0 ; j < y; j++)
         cin >> m[i][j];
  
  for (i = 0; i < x ; i++)
    {
     for (j = 0 ; j < y; j++)
         cout <<  m[i][j]<< ' ';
     cout << endl;
    }
}
