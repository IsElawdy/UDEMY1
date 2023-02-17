#include <iostream>

using namespace std;

struct calentry{
  char dat[7];
  char tex[50];
  calentry * next;
  calentry * last;
};

void calprint(calentry * root)
{
  calentry * help = root;
  while (help != NULL) {
     cout << help->dat << " : " << help->tex << endl;
     help = help->next;
  }
}

void calget(calentry * & root)
{
  if (root){
     cout << root->dat << " : " << root->tex << endl;
     root = root-> next;
     if (root)  // nicht nur ein Eintrag
       root -> last = NULL;
   }
  else
    cout << "Leerer Kalender \n";
}

int calput(const char wann[], const char was[], calentry * & root)
{
  calentry * neu, * help;
  if (!root) {  //bisher ist Liste leer
     root = new calentry;
     root -> next = root -> last = NULL;
     strcpy(root->dat,wann);
     strcpy(root->tex,was);
     return 1;  //o.k.
   }
  if (strcmp(wann,root->dat) < 0){   //vor erstem Eintrag
    neu = new calentry;
    neu->next = root;
    neu->last = NULL;
    root->last = neu;
    root = neu;
    strcpy(root->dat,wann);
    strcpy(root->tex,was);
    return 1;  //o.k.
   }
  for(help=root;help->next;help=help->next)
    {
      if(strcmp(wann,help->dat) < 0) 
        break;
    }
   if (strcmp(wann,help->dat) < 0){ //Einfuegestelle inmitten der Liste
     neu = new calentry;
     strcpy(neu->dat,wann);
     strcpy(neu->tex,was);
     neu -> next = help;
     neu -> last = help -> last;
     help -> last -> next = neu;
     help -> last = neu;
     return 1;
   }
   else {            //Einfuegestelle am Ende
     neu = new calentry;
     strcpy(neu->dat,wann);
     strcpy(neu->tex,was);
     neu -> next = NULL;
     neu -> last = help;
     help -> next = neu;
     return 1;
   }
}

int caldel(const char wann[], calentry * & root)
{
  calentry * help = root;
  if (!root)
    return 0;
  if (strcmp(root->dat,wann) == 0){   //erstes Element Löschen
     root = root -> next;
     if (root)  // nicht nur ein Eintrag
       root -> last = NULL;
     delete help;
     return 1;
   }
   for(;help;help=help->next)
     if (strcmp(help->dat,wann) == 0) // Eintrag gefunden
       break;
   if(!help)             // kein Element gefunden
      return 0;
   help -> last -> next = help -> next;  
   if (help -> next)
     help -> next -> last = help -> last;
   delete help;
   return 1;
}

main()
{
  char command;
  char dat[7];
  char tex[50];
  calentry * anchor = NULL;
  do
  {
    cout << "e - entry, n - next, p - print, d - delete, q - quit, \n";
    cin >> command;
    switch(command)
    {
      case 'e':
        cout << " date: "; cin >> dat;
        cout << " text: "; cin >> tex;
        if(calput(dat,tex,anchor) == 0)
          cout << "sorry, calendar full\n";
        break;
      case 'n': calget(anchor); break;
      case 'p': calprint(anchor); break;
      case 'd': 
         cout << " date: "; cin >> dat;
         if (caldel(dat,anchor) == 0)
           cout << "sorry, no such entry\n";
         break;
      case 'q': break;
      default:
        cout << "illegal comand\n";
    }
  }
  while(command != 'q');
}
