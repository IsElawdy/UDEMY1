// Loesungsvorschlag Teilaufgabe 1. siehe Vorlesung
// Loesungsvorschlag Teilaufgaben 2. und 3.
// anmu 12.5.2006
#include <iostream>

using namespace std;

struct p{
        int a;p * pNext;
        };

// Teilaufgabe 2
int insert (int b, int a, p * pAnker1)
{
  p * pHelp, * pNew;
  pHelp = pAnker1;
  if (pHelp == NULL)  return 1;  // leere Liste, nichts ist drin
  do
    {
      if (pHelp -> a == a)  //gefunden ???
        {
          pNew = new p;
          if(pNew == NULL)  // kein Speicher da
            return -1;
          pNew -> a = b;
          pNew -> pNext = pHelp -> pNext;
          pHelp -> pNext = pNew;
          return 0;         // alles o.k.
        }
       pHelp = pHelp -> pNext;  
    }
  while (pHelp != pAnker1);
  return 1;                  // nicht enthalten 
}

main()
{
   p * pAnker, * pNeu;
   p * pPrint;        // Hilfszeiger Teilaufgabe 3
   int i = 0;
   int zaehler = 0;   // zaehler Teilaufgabe 3.
   int erg;   // Ergebnis Teilaufgabe 2.
   pAnker = new p;
   cin >> pAnker -> a;
   pAnker -> pNext = pAnker;
    while (i < 6)
      {
         pNeu = new p; cin >> pNeu -> a;
         pNeu -> pNext = pAnker -> pNext;
         pAnker -> pNext = pNeu;
         i++;
      }
   
// Teilaufgabe 3
  pPrint = pAnker;
  do
   {
     cout << pPrint -> a << '\t';
     zaehler++;
     if (zaehler % 4 == 0)
         cout << '\n';
     pPrint = pPrint -> pNext;
   }
  while (pPrint != pAnker);
  cout << '\n';
  erg = insert(3,4,pAnker);
  cout << erg << '\n';
  // Teilaufgabe 3 (nochmal zur Demonstration Wirkung Teilaufgabe 2)
  zaehler = 0;
  pPrint = pAnker;
  do
   {
     cout << pPrint -> a << '\t';
     zaehler++;
     if (zaehler % 4 == 0)
         cout << '\n';
     pPrint = pPrint -> pNext;
   }
  while (pPrint != pAnker);
  cout << '\n';
  
}
