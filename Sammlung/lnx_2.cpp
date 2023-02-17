#include <iostream>
#include <cmath>

using namespace std;

main()
{
  float x, erg, glied, glied_alt, zaehler, eps;
  int nenner, vz;

  do
   {
  	cout << "Bitte x eingeben ( 0 <= x < 2 )\n";
  	cin >> x;
   }
  while ((x<=0) || (x>2));
  erg = glied = x-1;
  zaehler = x-1;
  nenner = 1;
  vz = 1;
  eps = 0.00000001;
  do
    {
      glied_alt = glied;
      zaehler = zaehler * (x -1);
      nenner++;
      vz = vz * -1;
      glied = vz * zaehler / nenner;
      if (fabs(glied - glied_alt) > eps)
         erg = erg + glied;
     }
  while (fabs(glied - glied_alt) > eps);
  cout << "Ergebnis " << erg << " Vergleich " << log(x) << endl;
}
