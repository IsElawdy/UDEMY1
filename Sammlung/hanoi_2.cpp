/* Tuerme von Hanoi laut Algorithmus
   anmu 14.1.2005
*/
#include <iostream>

using namespace std;

void hanoi(int anz, int von, int nach, int ueber)
{
  if (anz > 0)
   {
    hanoi(anz-1,von,ueber,nach);
    cout << "Bewege " << von << " nach " << nach << endl;
    hanoi(anz-1,ueber,nach,von);
   }
}

int main()
{
  int scheiben;
  cout << "Wieviele Scheiben ?\n";
  cin >> scheiben;
  if ((scheiben >0) && (scheiben < 10))
     hanoi(scheiben,1,2,3);
    else
     cout << "Eingabe unzulaessig oder nicht sinnvoll\n";
}
