#include <iostream>
#include <cstring>

using namespace std;

int naiv(char * text, char * patt)
{
 int textlenght = strlen(text)-1;
 int pattlenght = strlen(patt)-1;
 int textpos = 0;
 int pattpos = 0;
  while ((pattpos < pattlenght) && 
         (textpos + pattlenght <= textlenght))
           {
              pattpos = 0;
              while ((pattpos < pattlenght) &&
                     (patt[pattpos] == text [textpos+pattpos]))
                     pattpos++;
              textpos++;
           }
 if (pattpos >= pattlenght) 
     return textpos-1;    //Index gemaess c++
    else return 0;
}

main()
{
 char a[256];
 char b[10];
 char puffer[256];
 cout << "Eingabe Text \n";
 cin >> a;
 cout << "eingegebener Text " << a << endl;
 cout << "Eingabe Muster \n";
 cin >> b;
 cout << "eingegebenes Muster " << b << endl;
 if (naiv(a,b))
   cout << " Muster enthalten ab Position " << naiv(a,b) << endl;
  else 
   cout << " Muster nicht enthalten \n";
}
