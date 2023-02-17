// Suchalgorithmen

#include <iostream>
using namespace std;
int max = 9;
int suchfeld[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
void menue()
{
	cout << "Lineare Suche: 	L \n";
	cout << "Binaere Suche: 	B \n";
	cout << "Ende: 		Q \n";
}

int linear_search( int search)
// gibt Index zurueck, wenn gefunden, sonst -1
{
int index = -1;
int i = 0;
while ((i <= max) && (suchfeld[i] != search)) 
	i++;
if (i <= max)
	index = i;
return (index);
}

int binary_search( int search)
{
int Left = 0; // linker Index 
int Right = max; // rechter Index
int index = -1; // Index: Pos, wenn gefunden,
// -1 , sonst 
char found = 0; // gefunden ??
int i; // Laufvariable
while ((Left <= Right) && (!found))
	{
		i = ( Left + Right) / 2;
		if (suchfeld[i] > search)
			Right = i - 1;
		else if (suchfeld[i] < search)
			Left = i + 1;
			else found = 1; 
}
if (found)
index = i;
return (index);
}

main()
{
char auswahl; // Auswahl des Suchalgorithmus 
int suche; // zu suchende Zahl
char weiter = 1; // Weiter Suchen?
int found_index; // Index der gefundenen Zahl
while ( weiter == 1 )
	{
		menue();
		cin >> auswahl;
		if (auswahl != 'Q')
			{
				cout << " Welchen Wert suchen \n";
				cin >> suche;
				switch (auswahl)
					{
						case 'L' : found_index = linear_search(suche);
								break;
						case 'B' : found_index = binary_search(suche);
								break; 
					} 
				cout << "Suchindex : " << found_index << "\n";
			}
		else weiter = 0;
	} 
}
