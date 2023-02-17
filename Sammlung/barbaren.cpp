#include <iostream>
using namespace std;

main()
{
int Barbaren, Griechen, Personen, i;

Personen = 0;
for (Barbaren = 1; Barbaren < 7 ; Barbaren++)
	 {
		Griechen = Barbaren * 2;
		  if ((Barbaren+Griechen) % 4 == 0)
			  {
					 Personen = Barbaren + Griechen;
					 cout << "Anzahl der Personen: " << Personen << endl;
					 cout << "Anzahl der Barbaren: " << Barbaren << endl;
					 cout << "Anzahl der Griechen: " << Griechen << endl;
					 cin >>i;
				}
	  }
if (Personen == 0)
	cout << "Keine Loesung moeglich\n";

	cin >> i;
}
