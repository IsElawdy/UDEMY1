#include "liste.h"

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
