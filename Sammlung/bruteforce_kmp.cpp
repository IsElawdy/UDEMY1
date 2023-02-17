#include <iostream>
#include <string>


using namespace std;

int bruteforce(string text, string pattern)
{
  int n = text.length();
  int m = pattern.length();
  int i, j;
  for (i=0; i <= n -m; i++)
     {
       j=0;
       while ((j < m) && (pattern[j] == text[i+j]))
          j++;
       if ( j >= m)
          return i;
      }
   return -1;
}

int* initNext(string pattern)
{
  int * next = new int [pattern.length()];
  int i = 0, j = -1;
  next[0] = -1;
  while ( i < pattern.length() -1) 
   {
      while (( j >= 0) && (pattern.at(i) != pattern.at(j)))
         j = next [j];
      i++;
      j++;
      next[i] = j;
    }
   return next;
}

int kmp(string text, string pattern)
{
  int * next = initNext(pattern);
  int i = 0, j = 0;
  while (i < text.length())
  {
    while ((j >= 0) && (pattern.at(j) != text.at(i)))
      j = next[j];
    i++;
    j++;
    if (j == pattern.length())
       return i - pattern.length();
  }
  return -1;
} 

int main()
{
  string test;
  string suchmuster;
  int erg;
  cout << "Eingabe Text und Suchmuster \n";
  cin >> test >> suchmuster;
  erg = bruteforce(test,suchmuster);
  if (erg==-1)
    cout << "Suchmuster nicht enthalten\n";
  else
    cout << "Suchmuster ab Position " << erg << " enthalten \n";
  erg = kmp(test,suchmuster);
  if (erg==-1)
    cout << "Ergebnis Knuth-Morris-Pratt: Suchmuster nicht enthalten\n";
  else
    cout << "Ergebnis Knuth-Morris-Pratt: Suchmuster ab Position " << erg << " enthalten \n";
}


