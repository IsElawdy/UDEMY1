#include <fstream>
#include <libc.h>      // fuer exit()
using namespace std;

void error(char *s)
{
  cerr << s << endl;
  exit(1);
}

main()
{
    ifstream von("test");  // Anlegen eines Objektes der
                             // Klasse ifstream
    if(!von)
      error("Fehler beim Oeffnen der Quelle");
    ofstream nach("ziel");   // Anlegen eines Objektes der
                             // Klasse ofstream
    if(!nach)
      error("Fehler beim Oeffnen des Ziels");
    char c;
    while(von.get(c))    // solange ohne Fehler
      nach.put(c);       // zeichenweise kopieren
   if(!von.eof())
      error("Fehler beim Kopieren Quelle ");
   von.close();
   nach.close();
    return(0);
   }

