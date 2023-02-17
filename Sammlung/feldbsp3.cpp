#include <iostream>
using namespace std;
main ()
{
	int matrix [6][9];
	int vektor [9];
	int i,j;
	for (i = 0; i < 9; i++)
	    vektor[i] = i;
	for (i = 0; i < 9; i++)
	    cout << vektor[i] << " "; // Hier werden die Elemente des
				      // Vektors ausgegeben
	cout << "\n";
	cout << vektor << "\n";       // Hier wird die Anfangsadresse
				      // des Vektors ausgegeben
	for (i = 0; i < 6; i++)
	    for (j = 0; j < 9; j++)
	    matrix[i][j] = vektor[j];
	for (i = 0; i < 6; i++)       // Ausgabe aller Matrixelemente
	     {
	      for (j = 0; j < 9; j++)
		cout << matrix[i][j];
		cout << "\n";
	     }
	for (i = 0; i < 6; i++)       // Ausgabe aller Anfangsadressen
				      // der Zeilenvektoren
	     {
		cout << matrix[i];
		cout << "\n";
	     }

}
