//Sortieralgorithmen

#include <iostream>
#include <cstdlib>
using namespace std;

const int max = 99;
int sortfeld[max+1];

// Hilfsfunktionen
void menue()
{
	cout << "Direktes Aussuchen: 	A \n";
	cout << "Direktes Einfuegen: 	E \n";
	cout << "Binaeres Einfuegen: 	B \n";
	cout << "Bubble-Sort:	        S \n";
	cout << "Shell-Sort:	 	O \n";
	cout << "Quick-Sort:	 	I \n";
	cout << " \n";
	cout << "Ende:	 		Q \n";
}

void ausgabe ( void)
{ 
int i;
char c;
for ( i = 0; i <= max; i++)
	{ 
		cout << sortfeld[i] << "\n";
		if ((i % 25 == 0 ) && (i != 0))
			{
				cout << " weiter ==> Zeichen + ET \n";
				cin >> c;
			}
	}
}

void tausch(int i, int j)
// Tauscht die Feldelemente mit den Indizes i und j
{ 
int help;
	help = sortfeld[i];
	sortfeld[i] = sortfeld[j];
	sortfeld[j] = help;
}
 
 
void generate()
// Feld sortfeld mit Zufallszahlen initialisieren
{
int i;
for ( i = 0; i <= max; i++)
	sortfeld[i] = rand();
}

// Sortieralgorithmen
void Direct_Search(void)
{
int i, j, k; // Laufvariablen
for ( i = 0; i < max; i++)
	{
		k = i;
		for ( j = i + 1; j <= max; j++)
			if (sortfeld[j] < sortfeld[k])
				k = j;
		tausch( k, i);
	}
}

void Direct_Insert(void)
/* Direct-Insert sucht fuer jedes Element 1 <= i <= n diejenige Stelle j
im zu sortierenden Feld, fuer die gilt:
sortfeld [j-1] < sortfeld[j] <= others
d.h. fuer jedes Element wird versucht, es "soweit wie moeglich noch
vorn" zu schieben. 
Abbruchkriterium: Elemente "davor kleiner oder Feld zu Ende"
*/
{
int i, j;
int help;
for ( i = 1; i <= max; i++)
	{
		help = sortfeld[i];
		j = i;
		while (( help < sortfeld [j-1]) && (j >= 1))
			{
				sortfeld[j] = sortfeld[j-1];
				j--; 
			} 
		sortfeld[j] = help;
	}
}

void Binary_Insert(void)
{
int i, j, middle, l, r; // Indexvariablen
int help; // Elementzwischenspeicher
for ( i = 1; i <= max; i++)
	{
		help = sortfeld[i];
		l = 0;
		r = i;
		while (l < r)
			{
				middle = (l + r) / 2;
				if (sortfeld[middle] <= help)
					l = middle + 1;
				else 
					r = middle;
			}
		for ( j = i; j >= r+1; j --)
			sortfeld[j] = sortfeld[j-1];
		sortfeld[r] = help;
	} 
}

void Bubble_Sort(void)
{
int i, j; // Indexvariablen
for ( i = 1; i <= max; i++)
	for ( j = max; j >= i; j--)
		if ( sortfeld[j-1] > sortfeld[j])
			tausch(j-1,j);
}
 
void Shell_Sort(void)
/* Hier wird versucht, Austauschoperationen ueber Distancen,
zu vollziehen, die so "gross" wie moeglich sind.
Guenstig sind Werte von h = h * 5 + 1 (fuer h(1) = 1)
*/
{
int i, j, delta; // Indexvariablen 
int help; // Elementvariablen 
delta = 1; // Berechnen der Teilfelder 
do
	{
		delta = 5 * delta + 1;
	}
while ( delta < max);
do
	{
		delta = delta / 5;
		for ( i = delta; i < max; ++i)
			{
				j = i;
				help = sortfeld[j] ;
				while (( j >= delta ) && (help < sortfeld[j - delta]))
					{
						sortfeld[j] = sortfeld [j - delta];
						j -= delta; 
					} 
				sortfeld[j] = help; 
			}
	}
while ( delta > 1); 
}

void Quick_Sort(int L, int R)
{
int left, right; // Indexvariablen
int help;
left = L;
right = R;
help = sortfeld [ ( left + right) / 2];
do
	{
		while (sortfeld [left] < help)
			left++;
		while (sortfeld [right] > help)
			right--;
		if ( left <= right )
			{ 
				if ( left < right )
					tausch (left, right);
				left++;
				right--;
			}
	}
while (left <= right);
if ( L < right ) 
	Quick_Sort ( L, right);
if ( R > left )
	Quick_Sort ( left, R);
}



main()
{
char auswahl; // Auswahl des Suchalgorithmus 
int suche; // zu suchende Zahl
char weiter = 1; // Weiter Suchen?
int i;
generate();
cout << " Folge vor Sortieren \n";
ausgabe();
while (weiter)
	{
		menue(); 
		cin >> auswahl;
		if (auswahl != 'Q')
			{
				switch (auswahl)
					{
						case 'A' : Direct_Search();
								break;
						case 'E' : Direct_Insert();
								break;
						case 'B' : Binary_Insert();
								break; 
						case 'S' : Bubble_Sort();
								break; 
						case 'O' : Shell_Sort();
								break;
						case 'I' : Quick_Sort(0,max);
								break; 
					} 
			}
		else weiter = 0;
	} 
cout << "Folge nach Sortieren \n";
ausgabe(); 
}
