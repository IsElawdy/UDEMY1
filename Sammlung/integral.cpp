#include <iostream>
#include <cmath>
using namespace std;

float func (float x)
{
	return sin(x);
}

float intrect (float a, float b, int n)
{
	int i;
	float w, r;
	r = 0;
	w = (b - a) / n;
	for (i=1; i <= n; i++)
	  r = r + w * func (a -w/2 + i*w);
	return r;
}

main()
{
	float a, b;
	int N;
	cout << "Eingabe Intervallgrenzen fuer die Intergration : \n";
	cin >> a >> b;
	cout << "Eingabe Anzahl Rechtecke zur Aproximation : \n";
	cin >> N;
	cout << " Integral ist : " << intrect(a,b,N) << endl;
}

