#include "liste.h"

main()
{
  list L;
  char func;
  int val;

  do
  {
    cout << endl << endl;
    cout << "e - end" << endl
         << "i - insert" << endl
         << "r - remove" << endl
         << "p - print" << endl
         << "c - copy" << endl
         << endl;
    cout << ": ";
    cin >> func;
    switch(func)
    {
      case 'i': cout << "val: ";
                cin >> val;
                cout << L.insert(val) << endl;
                break;
      case 'r': cout << "val: ";
                cin >> val;
                cout << L.remove(val) << endl;
                break;
      case 'p': L.print();
                break;
      case 'c': {
                  list L1(L);
                  L1.print();
                }
                break;
    }
  } while(func != 'e');
}
