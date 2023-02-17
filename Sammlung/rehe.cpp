#include <iostream>
#include <cmath>

using namespace std;

int rehe_i (int n)
{
  int jahre;
  int rehe = 15;
  for (jahre = 0; jahre < n; jahre++)
    {
      rehe = rehe * 2; // Vermehrung
      rehe = rehe - 8; // Silvesterbraten
      if (rehe > 40)   // Schutzmassnahme
         rehe = rehe - int(ceil(rehe * 0.7)) ;
    }
   return rehe;
}

int rehe_r (int n)
{
  int rehe;
  if (n == 0)
    return 15;
  rehe = rehe_r(n-1) * 2;
  rehe = rehe - 8;
  if (rehe > 40)
         rehe = rehe - int(ceil(rehe * 0.7));
        // ceil(x) liefert kleinste ganze Zahl >=  x
        // alternativ floor(x) liefert größte ganze Zahl <=  x
  return rehe;
}

main()
{
  int anz;
  cin >> anz;
  cout << " Rehe nach " << anz << " Jahren " << rehe_i(anz) << endl;
  cout << " Rehe nach " << anz << " Jahren " << rehe_r(anz) << endl;
}
