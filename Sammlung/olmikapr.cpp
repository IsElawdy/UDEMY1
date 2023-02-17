#include <iostream>
using namespace std;
/*
Quelle fuer Algorithmus:
Appelrath, H.-J.,Ludewig,J.: Skriptum Informatik-eine konventionelle Einfuehrung",
Zürich:Verlag der Fachvereine und Stuttgart:B.G.Teubner, 1992
*/

int E = 0;
int K = 0;
int VE, VK, Soll;

/* Pruefung Zulaessigkeit der Eingaben
	Es muss gelten :
	Soll = n * ggt (VE, Vk)
	n = 0,1,2,...
*/

int ggt (int A, int B)
{
 if (!B || A == B)
	return A;
 if (!A)
	return B;
 return ggt(B, A % B);
}

void Aus (char s[])
{
  cout << s << "\n";
}

void fuelleE()
{
  E = VE;
  Aus("fuelle E");
}

void fuelleK()
{
	K = VK;
	Aus("fuelle K");
}

void leereK()
{
	 K = 0;
	 Aus("leere K");
}

void schuetteEnachK()
{
	 while (( E > 0) && (K < VK))
		{
			E--;
			K++;
		}
	 Aus("schuette E nach K ");
}

void GibAnleitung()
{
 if (Soll == VK)
  {
	fuelleK();
  }
  else
	 while ( K != Soll)
	  {
		 fuelleE();
		  while ( E != 0)
			{
				schuetteEnachK();
				if ( K == VK)
					leereK();
			}
	  }
}

void vorbereitung()
{
  Aus("Programm Oldenburger Milchkannanproblem");
  cout << "Volumen E und K, gewuenschte Menge: ";
  cin >> VE >> VK >> Soll;
  cout << "\n";
  cout << "\n";
}

main()
{
  int ggtv;
  vorbereitung();
  ggtv = ggt (VE,VK);
  if (Soll % ggtv == 0)
	  GibAnleitung();
	 else cout << "Keine Loesung \n";
}
