#include <iostream>
using namespace std;
struct p{
        int a;p * pNext;
        };
int insert (int b, int a, p * pAnker1);

main()
{
   p * pAnker, * pNeu, *pLast;
   int i = 0;
   int erg;
   int zaehler;
   pAnker = new p;
   cin >> pAnker -> a;
   pAnker -> pNext = NULL;
   pLast = pAnker;
    while (i < 6)
      {
         pNeu = new p; 
         cin >> pNeu -> a;
         pNeu -> pNext = NULL;
         pLast -> pNext = pNeu;
         pLast = pNeu;
         i++;
      }
   erg = insert (3,4,pAnker);  // 3 nach Element mit 4 einfuegen
   erg = insert (5,10,pAnker);
   // eventuell erg auswerten
   // 3.
   pLast = pAnker;
   zaehler = 0;
   while (pLast)
    {
      cout << pLast -> a << '\t';
      zaehler++;
      if ((zaehler % 4) == 0)
         cout << '\n';
      pLast = pLast -> pNext;
    }
    cout << '\n';
}

int insert (int b, int a, p * pAnker1)
{
   p * pHelp = pAnker1;
   p * pNew;
   while (pHelp)
    {
       if (pHelp -> a == a)
          //Element gefunden
          {
             pNew = new p;
             if (pNew == NULL)    // Einfuegen nicht gelungen
                return -1;
             pNew -> a = b;
             pNew -> pNext = pHelp -> pNext;
             pHelp -> pNext = pNew;
                return 0;
          }
         else
            pHelp = pHelp -> pNext;
    }
    // nun nicht gefunden:
    return 1;
}
