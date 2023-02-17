// Fibonacci-Zahlen  rekursiv

#include <iostream>
using namespace std;

long fib(long fibo);

main()

{
  int zahl;
  long erg;
  do
   {
    cout << "Fibonacci-Zahl welcher Zahl ? (Abschluss mit -1)\n";
    cin  >> zahl;
    if (zahl > 2)
	erg = fib(zahl);
       else   if (zahl > 0)
		  erg = 1;
		 else erg = -1;
    if (erg > -1)
	cout << "Fibonacci-Zahl ist : " << erg << "\n";
       else  cout << "Fibonacci-Zahlen sind nur fuer positive ganze Zahlen definiert. \n";
   }
  while (erg > -1);
}

long fib(long fibo)
{
 if (fibo <= 2)
    return (1);
    else return(fib(fibo-1)+fib(fibo-2));
}
