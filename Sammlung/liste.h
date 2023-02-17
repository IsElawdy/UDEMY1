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
  void print();
};
