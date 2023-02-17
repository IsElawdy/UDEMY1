#include <iostream>
using namespace std;

class X {
private:
	int i;
	X* next;
public:
	X();
	X(int);
	~X();
	void set(int);
	void print ();
	X& kette();
};

X::X()
{
 i = 0;
 next = 0;
}

X::X(int x)
{
 i = x;
 next = 0;
}

X::~X()
{
 cout << "Destructor \n";
}

void X::set(int y)
{
 i = y;
}

void X::print()
{
 cout << i << "  " << next << "\n";
}

X& X::kette()
{
 next = this;
 return *this;
}

main()
{
 X a(10);
 X ap;
 a.print();
 a.set(20);
 ap = a.kette();
 ap.print();
}




