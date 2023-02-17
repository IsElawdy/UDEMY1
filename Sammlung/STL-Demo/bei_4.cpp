// insdel.cpp: Insertions and deletions in a list.
// From: Ammeraal, L. (1997) STL for C++ Programmers,
//       Chichester: John Wiley.
#include <iostream>
#include <list>          

using namespace std;

void showlist(const char *str, const list<int> & L)
{  list<int>::const_iterator i;
   cout << str << endl << "  ";
   for (i=L.begin(); i != L.end(); ++i)
      cout << *i << " ";
   cout << endl;
}          

int main()
{  list<int> L;                
   int x;
   cout << "Enter positive integers, followed by 0:\n";
   while (cin >> x, x != 0)
      L.push_back(x);
   showlist("Initial list:", L);
   L.push_front(123);
   showlist("After inserting 123 at the beginning:", L);
   list<int>::iterator i = L.begin();
   L.insert(++i, 456);
   showlist(
      "After inserting 456 at the second position:", L);
   i = L.end(); 
   L.insert(--i, 999);
   showlist(
      "After inserting 999 just before the end:", L);
   i = L.begin(); x = *i;
   L.pop_front(); 
   cout << "Deleted at the beginning: " << x << endl;
   showlist("After this deletion:", L);
   i = L.end(); x = *--i;
   L.pop_back();
   cout << "Deleted at the end: " << x << endl;
   showlist("After this deletion:", L);
   i = L.begin();
   x = *++i; cout << "To be deleted: " << x << endl;
   L.erase(i);
   showlist("After this deletion (of second element):", 
      L);
   return 0;
}
