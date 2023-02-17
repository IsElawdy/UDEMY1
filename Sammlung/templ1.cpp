#include <iostream>
using namespace std;

template <class X> void swap(X &a, X &b)
{
	X temp;
	temp = a;
	a = b;
	b = temp;
}

int main()
{
	int i = 10, j = 20;
	float x = 10.5, y = 20.9;

	cout << i << " " << j << endl;
	cout << x << " " << y << endl;
	swap(i,j);
	swap(x,y);
   cout << i << " " << j << endl;
	cout << x << " " << y << endl;
	return 0;
}
