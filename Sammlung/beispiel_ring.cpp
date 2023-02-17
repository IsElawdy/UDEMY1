#include <iostream>
using namespace std;

// Achtung: Ausgabe der Datenelemente als Funktion realisiert

struct p{
        int a;p * pNext;
        };

void print (p * pAnker1)
{
  p * pHelp = pAnker1;
  do
     {
       cout << pHelp->a << "\t";
       pHelp = pHelp ->pNext;
     }
  while (pHelp != pAnker1);
  cout << endl;
}

int insert (int b, int a, p * pAnker1)
{
  p * pHelp = pAnker1;
  p * pNew;
  while ((pHelp->a != a) && (pHelp -> pNext != pAnker1))
     pHelp = pHelp -> pNext;
  if (pHelp -> a != a)
     return 1;
  // Loesungsidee : einfuegen danach, Daten tauschen.
  pNew = new p;
  if (!pNew)   // Nicht gelungen!
    return -1;
  pNew->a = pHelp->a;
  pHelp->a = b;
  pNew->pNext  = pHelp->pNext;
  pHelp->pNext = pNew;
  return 0;
} 

main()
{
   p * pAnker, * pNeu;
   int i = 0;
   int a,b,c;
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
 print(pAnker);
 cout << "Welches Datum vor welchem Element einfuegen? \n";
 cin >> b >> a;
 c = insert (b,a,pAnker);
 switch (c)
  {
   case -1 : cout << "Zuwenig Speicherplatz \n"; break; 
   case 0  : cout << "Einfuegen gelungen \n"; print(pAnker); break;
   case 1 : cout << "Element " << a << " nicht enthalten \n"; break; 
  }
}
