#include <iostream>

using namespace std;

int * initNext(char pat[])
{
  int * next = new int[strlen(pat)+1];
  int i = 0; 
  int j = -1;
  next[0] = -1;
  while (i < strlen(pat)+1)
   {
     while ((j  >= 0) && (pat[i] != pat[j]))
        j = next[j];
     i++;
     j++;
     next[i] = j;
   }
  return next;
} 

int kpmsearch(char text[], char pat[])
{
  int * next = initNext(pat);
  int i = 0, j = 0;
  while ( i <= strlen(text))
     {
       while ((j >= 0) && (pat[j] != text[i]))
          j = next[j];
       i++;
       j++;
       if (j == strlen(pat))
            return i - strlen(pat);
     }
  return -1;
}

main()
{
  char pattern[80];
  char text[80];
  int i,pos;
  int * fehlerfeld;
  cout << "Eingabe Muster\n";
  cin >> pattern;
  cout << "Eingabe Text\n";
  cin >> text;
  fehlerfeld = initNext(pattern);
  for (i = 0; i < strlen(pattern)+1 ; i++)
    cout << fehlerfeld[i] << '\t';
  cout << '\n'; 
  pos = kpmsearch(text,pattern);
  if (pos == -1)
     cout << "Text nicht enthalten\n";
    else
     cout << "Muster " << pattern << " in Text " << text << " ab Position " << pos << " enthalten\n";
}
