#include <fstream>
#include <libc.h>      // fuer exit()
using namespace std;

struct lelem {
    int d;
    lelem * next;
};

void error(char *s)
{
  cerr << s << endl;
  exit(1);
}

main()
{
    lelem * anchor, * last, * neu;
    lelem * anchor1, * last1, * neu1;
    int i;
    int input;
    anchor = new lelem;
    anchor -> d = 0;
    anchor -> next = NULL;
    last = anchor;
    for (i = 1; i < 10; i++)
      {
        neu = new lelem;
        last -> next = neu;
        last = neu;
        last -> d = i;
        last -> next = NULL;
      };
    cout << " Inhalt Liste nach Erzeugen \n";
    neu = anchor;
    while (neu)
      {
        cout << neu -> d << ' ';
        neu = neu -> next;
      }
    
    cout << endl;
   
   ofstream fout ("test");
 
    if(!fout)
  {
    error("Fehler beim Oeffnen des Ziels");
  }
  
  last = anchor;
  
  while (last)
    {
      fout << last -> d << ' ';
      last = last -> next;
    }

  fout.close(); 
   
        
  ifstream fin("test");
                      
    if(!fin)
      error("Fehler beim Oeffnen der Quelle");

    anchor1 = new lelem;
    fin >> anchor1->d;
    anchor1 -> next = NULL;
    last1 = anchor1;
    while(!fin.eof())    // solange ohne Fehler
      {
        neu1 = new lelem;
        fin >> neu1 -> d;
        last1 -> next = neu1;
        last1 = neu1;
        last1 -> next = NULL;
      }
    cout << endl;
    neu1 = anchor1;
    cout << " Inhalt der kopierten Liste \n";
    while (neu1)
      {
        cout << neu1 -> d << ' ';
        neu1 = neu1 -> next;
      };
    cout << endl;

    fin.close();
    return(0);
   }

