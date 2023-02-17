#include <iostream>
#include <cstdlib>

using namespace std;

struct item {
	int data;     // Datenelement 
	item *pNext;  // Zeiger auf Nachfolger
       };

main ()
{
  item *pAnchor;
  item *pLast;
  item *pNew;
  item *pDelete;
  item *pInsert;
  int i;
  int d;

  i = 1;
  d = 0;
  pNew = new item;          // 2.
  pAnchor  = pNew;          // pAnchor bleibt "konstant"
  pLast = pNew;             // 3.
  pLast -> data = d;        // 4. irgendein Wert
  pLast -> pNext = NULL;  // Nachfolger ist NUL
  while ( d != -1)          // Beliebige Anzahl wird erzeugt
    {
     cout << "Liste erstellen, mindestens ein Element, Abschluß mit -1\n";
     cout << i << ".tes Datum\n";
     i++;
     cin  >> d;
     if (d != -1)
	{
	  pNew = new item;    //5.
	  pLast -> pNext = pNew; //6.
	  pLast = pNew;
	  pNew -> data = d;   //7.
	  pNew -> pNext = NULL;
	  pLast = pNew;  // 8.
	}
     }
  cout << "Ausgabe der Liste\n";
  pLast = pAnchor;      //wieder auf Anfang
  while (pLast != NULL)
    {
     cout << pLast -> data << " ";
     pLast = pLast -> pNext;
    };

  cout << "Listenelement löschen\n";
  cout << "Welches Datum ?\n";
  cin >> i;
  pLast = pAnchor;
  while ((pLast -> pNext != NULL) && (pLast -> pNext -> data != i))
      pLast = pLast -> pNext;  // Suchen des zu loeschenden Elements
  // Variante : Nachfolger des "aktuellen" Elementes wird untersucht
  if (pLast -> pNext == NULL)
    cout << "Element nicht enthalten\n";
   else {
          pDelete  = pLast -> pNext;   // 1.
          pLast-> pNext = pDelete -> pNext;  // 2.
          delete pDelete; //3.
        }
  cout << "Ausgabe der Liste\n";
  pLast = pAnchor;
  while (pLast != NULL)
    {
     cout << pLast -> data << " ";
     pLast = pLast -> pNext;
    };
  cout << "Element einfügen \n";
  cout << "Nach welchem Datum ?\n";
  cin >> i;
  pLast = pAnchor;
  while ((pLast != NULL) && (pLast -> data != i))
     pLast = pLast -> pNext;
  if (pLast == NULL)
     cout << "Element nicht enthalten\n";
  else {
         pInsert = new item;          // 1.
         cout << "Datum \n";
         cin >> pInsert -> data;
         pInsert -> pNext = pLast -> pNext; // 2.
         pLast -> pNext = pInsert;         // 3.
        }
  cout << "Ausgabe der Liste\n";
  pLast = pAnchor;
  while (pLast != NULL)
    {
     cout << pLast -> data << " ";
     pLast = pLast -> pNext;
    }
}


