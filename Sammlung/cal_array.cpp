#include <iostream>

using namespace std;

struct calentry{
  char dat[7];    // jjmmtt fuer bequemen Vergleich^M
  char tex[50]; // beliebiger Text^M
  int next;        // Index des Nachfolgers^M
  int used;        // 0 - Eintrag nicht benutzt^M
};

const int CALMAX = 4;
calentry caldat[CALMAX];
int root = -1; // Liste leer^M

void calprint() // Ausgabe in zeitlicher Reihenfolge^M
{
  int i;
  for(i=root;i!=-1;i=caldat[i].next)
    cout << " " << caldat[i].dat << ": " << caldat[i].tex << "\n";
}

void calget() // Ausgabe und Entfernen des aktuellsten Termins^M
{
  if(root == -1)
    cout << "no entries\n";
  else{
    cout << " " << caldat[root].dat << ": "
     << caldat[root].tex << "\n";
    caldat[root].used = 0;
    root = caldat[root].next;
  }
}
// Testausgabe^M
void caltest()
{
  int i;
  cout << root << "\n";
  for(i=0;i<CALMAX;i++)
    cout << " " << caldat[i].next << " " << caldat[i].used << " " << caldat[i].dat << " " << caldat[i].tex << "\n";
}

int calput(const char wann[], const char was[])
{
  int f, i, iold;
  // freien Eintrag suchen^M
  f = 0;
  while(caldat[f].used != 0)
    if(++f >= CALMAX) return 0; // Misserfolg^M
  strcpy(caldat[f].dat,wann);
  strcpy(caldat[f].tex,was);
  caldat[f].used = 1;
  // Einfuegestelle suchen^M
  iold = -1;
  for(i=root;i!=-1;i=caldat[i].next){
    if(strcmp(wann,caldat[i].dat) < 0) break; // Einfuegestelle^M
    iold = i;
  }
  if(iold == -1){ // vor ersten Eintrag^M
    caldat[f].next = root;
    root = f;
  }else{
    caldat[f].next = caldat[iold].next;
    caldat[iold].next = f;
  }
  return 1; // in Ordnung^M
}
main()
{
  char command;
  char dat[7];
  char tex[50];

  do
  {
    cout << "e - entry, n - next, p - print, q - quit, t - test\n";
    cin >> command;
    switch(command)
    {
      case 'e':
        cout << " date: "; cin >> dat;
        cout << " text: "; cin >> tex;
        if(calput(dat,tex) == 0)
          cout << "sorry, calendar full\n";
        break;
      case 'n': calget(); break;
      case 'p': calprint(); break;
      case 'q': break;
      case 't': caltest(); break;
      default:
        cout << "illegal comand\n";
    }
  }
  while(command != 'q');
}


