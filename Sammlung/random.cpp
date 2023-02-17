#include <cmath>
#include <iostream>
using namespace std;
/* Erzeugen von Zufallszahlen
	- Gleichverteilte
	- Gleichverteilte Reell
	- Gleichverteilte im Intervall
	- Poissonverteilte
	- negativ exponential verteilte
	Quelle:
	Weiss, M.A.: Algorithms, Data Structures and Problemsolving with C++;
	Menlo Park,...: Addison Wesley Publishing Company, Inc., (1996)
*/

static const long A = 48271L;
static const long M = 2147483647L;
static const long Q = M / A;
static const long R = M % A;
unsigned long Seed = 13L;

// RandomLong returns the next random number and updates Seed

unsigned long RandomLong()
{
long TmpSeed = A * ( Seed % Q ) - R * ( Seed / Q );
	 if( TmpSeed >= 0 )
		  Seed = TmpSeed;
	 else
		  Seed = TmpSeed + M;

	 return Seed;
}

double RandomReal( )
{
	 return RandomLong( ) / 2147483647.0;
}

// Not best algorithm for linear congruential generators
long RandLong( long Low, long High )
{
	 return RandomLong( ) % ( High - Low + 1 ) + Low;
}



unsigned Poisson( double ExpectedValue )
{
	 double Limit = exp( -ExpectedValue );
	 double Product = RandomReal( );

	 int Count;
	 for( Count = 0; Product > Limit; Count++ )
		  Product *= RandomReal( );

	 return Count;
}

double NegExp( double ExpectedValue )
{
	 return - ExpectedValue * log( RandomReal( ) );
}





main()
{
  /*
  double retnegexp, retrandreal;
  unsigned retpoiss;
  long retranlong, retrandomlong;
	  Rueckgabewerte der einzelnen Funktionen
  double expvalue;
  long lo, hi;
	  Parameter fuer Funktionen
  */
  int i;
  char c;
  cout << "Gleichverteilte Zuf.zahl (long)\n";
  for (i=0; i < 10; i++)
	 cout << RandomLong() << "\n";
  cin >> c;
  cout << "Gleichverteilte Zuf.zahl (double) \n";
  for (i=0; i < 10; i++)
	 cout << RandomReal() << "\n";
  cin >> c;
  cout << "Gleichverteilte Zuf.zahl (long) im Bereich low, high)\n";
  for (i=0; i < 10; i++)
	 cout << RandLong(1,10) << "\n";
  cin >> c;
  cout << "Poissonverteilte Zuf.zahl (unsigned)\n";
  for (i=0; i < 10; i++)
	  cout << Poisson(100.0) << "\n";
  cin >> c;
  cout << "Negativ exponentialverteilte Zuf.zahl (double)\n";
  for (i=0; i < 10; i++)
	  cout << NegExp(0.5) << "\n";
}
