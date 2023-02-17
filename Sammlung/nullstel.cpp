#include <iostream>
#include <cmath>
using namespace std;
/*
Nullstellen fuer stetige Funktionen mit Intervallhalbierung
Quelle fuer den Algorithmus:
Kowalk, W.P.: System-Modell-Programm, Vom Goto zur objektorientierten
Programmierung; Heidelberg, Berlin, Oxford: Spektrum Aklademischer Verlag, 1996
*/

float funktion(float x)
{
	return sin(x);
}

main()
{
  float  wertlinks, wertrechts, wertmitte, mitte, links, rechts;
  float eps = 0.00001;
  float verglwert;
  cout << " Eingabe Anfangsintervallgrenzen \n";
  cin >> links >> rechts;
  wertlinks = funktion(links);
  wertrechts = funktion(rechts);
  do
  {
	 mitte = (links+rechts) / 2;
	 wertmitte = funktion(mitte);
	 if ((wertmitte*wertlinks) > 0.0)
	  {
		 links = mitte;
		 wertlinks = wertmitte;
	  }
	  else
	  {
		  rechts = mitte;
		  wertrechts = wertmitte;
	  }
	  if (wertmitte < 0.0)
		 verglwert = -wertmitte;
		else verglwert = wertmitte;
  }
  while (verglwert > eps);
  cout << " Nullstelle " << mitte << "\n";
}
