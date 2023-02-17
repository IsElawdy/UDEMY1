#include <iostream>
#include <cstdio>

// wegen rand, srand

using namespace std;

int main()
{
  int A[10][10];
  int B[10][10];
  int C[10][10];
  int spaltensumme[10];
  int i, j;
  int minspalte, minwert;
  int maxwert;

  srand(1); //initialisieren Zufallsgenerator

  for (i=0; i < 10; i++)
   {
    for (j = 0; j < 10; j++)
     {
       A[i][j] = (rand() % 30)-15; // Zahlen im "ueberschaubaren" Bereich
       B[i][j] = (rand() % 30)-15; // und normiert neg. und positiv
       C[i][j] = A[i][j] + B[i][j];
       cout << C[i][j] << '\t';
     }
    cout << endl;
   }
  for (j = 0; j < 10; j++)
   {
     spaltensumme[j] = 0;
     for (i = 0; i < 10; i++)
       spaltensumme[j] = spaltensumme[j] + C[i][j];
   }
   minwert = spaltensumme[0];
   minspalte = 0;
   for ( j = 1; j < 10; j++ )
     if (spaltensumme[j] < minwert)
       {
          minwert = spaltensumme[j];
          minspalte = j;
       }  
   cout << "Spalte mit minimaler ("<<minwert<<") Spaltensumme: " << minspalte<<'\n';
   maxwert = C[0][minspalte];
   cout << maxwert << endl;
   for (i = 1; i < 10; i++)
     if (C[i][minspalte] > maxwert)
         maxwert = C[i][minspalte];
   cout << "Daraus der groesste Wert: " << maxwert << '\n';
}
