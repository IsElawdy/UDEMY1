#include <iostream>
#include <cassert>
using namespace std;

class list
{
  struct node
  {
    int val;
    node *next;
  } *anchor;

  public:

  list();
  list(list &);
  ~list();
  int insert(int);
  int remove(int);
  void list::print();
};

list::list()
{
  anchor = 0;
}

list::list(list &l)
{
  node *old = l.anchor, *tmp, *last;

  anchor = 0;
  while (old)
  {
    tmp = new node;
    assert(tmp);
    tmp->val = old->val;
    tmp->next = 0;
    if (anchor)
    {
      last = last->next = tmp;
    }
    else
    {
      anchor = last = tmp;
    }
    old = old->next;
  }
}

list::~list()
{
  node *tmp;
  while (anchor)
  {
    tmp = anchor;
    anchor = anchor->next;
    delete tmp;
  }
}

int list::insert(int i)
{
  node *help, *tmp, *pred = 0;

  tmp = new node;
  if (!tmp)
  {
    return 0;
  }

  // Suchen Wert > i
  for (help = anchor; help; help = help->next)
  {
    if (help->val > i)
    {
      break;
    }
    pred = help;
  }

  tmp->val = i;
  tmp->next = help;
  if (pred)
  {
    pred->next = tmp;
  }
  else
  {
    anchor = tmp;
  }
  return 1;
}

int list::remove(int i)
{
  node *help, *tmp, *pred = 0;

  // Suchen Wert == i
  for (help = anchor; help; help = help->next)
  {
    if (help->val == i)
    {
      break;
    }
    pred = help;
  }

  if (!help)
  {
    return 0;
  }

  do
  {
    if (pred)
    {
      pred->next = help->next;
      delete help;
      help = pred->next;
    }
    else
    {
      anchor = help->next;
      delete help;
      help = anchor;
    }
  } while (help && help->val == i);

  return 1;
}

void list::print()
{
  node *help = anchor;

  while (help)
  {
    cout << help->val << " " << endl;
    help = help->next;
  }
}

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
