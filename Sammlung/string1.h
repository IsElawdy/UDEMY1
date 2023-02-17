#include <iostream>
#include <cstring>

using namespace std;

class String {
private:
      char *s;
      int size;
public:
      String();
      String(const char*);
      String(const String&);   // Copy-Konstruktor
      ~String();
      void set(const char*);
      int length() const;
      void print() const;
      String& operator = (const String&);
      friend int operator == (const String&, const String&);
      friend ostream& operator << (ostream&, const String&);
      friend istream& operator >> (istream&, String&);
};

int operator != (const String&, const String&);



