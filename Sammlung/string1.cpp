#include <cstring>
#include "string1.h"

using namespace std;

String::String()
{ s = 0;
  size = 0;
}

String::String(const char * st)
{
  s = new char [size = strlen(st) + 1];
  strcpy(s, st);
}

String::String(const String& s1)
{
   s = new char[size = s1.size];
   strcpy(s, s1.s);
}


String::~String()
{
  cout << "Destruktor Called \n";	
  delete s;
}

void String::set(const char * st)
{
  delete s;
  s = new char[size = strlen(st) +1];
  strcpy(s, st);
}

int String::length() const
{
  if (size !=0)
     return size-1;
   else
     return 0;
}

void String::print() const
{
  cout << "[" << length() << "]";
  if (s) cout << s;
     else cout << "(NULL)";
  cout << "\n";
}

String& String::operator =(const String& s1)
{
   if (this != &s1)   // verhindert string1 = string1
         set(s1.s);
   return *this;
}

int operator == (const String& s1, const String& s2)
{
    return strcmp(s1.s, s2.s) == 0;
}

int operator != (const String& s1, const String& s2)
{
    return !(s1 == s2);
}

ostream& operator << (ostream& os, const String& s1)
{
    os << "[" << s1.length() << "] ";
    if(s1.s)  os << s1.s; else os << "(NULL)";
    os << "\n";
    return os;
}

istream& operator >> (istream& is, String& s1)
{
    char buffer[256];
    is >> buffer;
    s1 = buffer;
    return is;
}

