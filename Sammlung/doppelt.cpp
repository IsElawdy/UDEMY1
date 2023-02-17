#include <iostream>

using namespace std;

struct lelem {
    int data;
    lelem * next, *prev;
};

main()
{
  lelem * anchor, * lastitem, * newitem;
  int i;

  // Erzeugen

  anchor = new lelem;
  lastitem = anchor;
  cin >> lastitem -> data;
  lastitem -> prev = lastitem ->next = NULL;

  for (i=0; i<10;i++)
    {
      newitem = new lelem;
      newitem -> next = NULL;
      newitem -> prev = lastitem;
      lastitem -> next = newitem;
      cin >> newitem -> data;
      lastitem = newitem;
    }  
 
  // Ausgabe
  lastitem = anchor;
  while (lastitem)
   {
     cout << lastitem -> data << " ";
     lastitem = lastitem -> next;
   }
  cout << endl;

  // Suchen und Loeschen Element

  cin >> i;
  lastitem = anchor;
  while (lastitem)
    {
      if (lastitem->data == i)
          break;
      lastitem = lastitem -> next;
    }
  if (!lastitem)
    cout << "Element " << i << "nicht enthalten \n";
   else
    {
     lastitem -> prev -> next = lastitem -> next;
     lastitem -> next -> prev = lastitem -> prev;
     delete lastitem;
    }
  lastitem = anchor;
  while (lastitem)
    {
      cout << lastitem -> data << " ";
      lastitem = lastitem -> next;
    }
  cout << endl;

}
