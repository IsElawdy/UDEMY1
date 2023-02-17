#include <iostream>
using namespace std;

class behaelter{
   int MAX;
   int INH;
 public:
    behaelter(int max);
    void fuellen();
    void leeren();
    void umschuetten(behaelter *);
    int akt_inh();
    void set_inh(int);
    int get_max();
};

class steuerung{
   int soll;
   behaelter * b1, *b2;
  public:
   steuerung(int s, int a, int b);
   void umfuellen();
};

behaelter::behaelter(int max)
{
  MAX = max;
  INH = 0;
}

void behaelter:: fuellen()
{
  INH = MAX;
}

void behaelter::leeren()
{
  INH = 0;
}

int behaelter::akt_inh()
{
  return INH;
}

void behaelter::set_inh(int wert)
{
  INH = wert;
}

void behaelter::umschuetten(behaelter * b1)
{
  int b1inh;
  b1inh = b1->akt_inh();
  if (b1inh > (MAX - INH))
     { 
      b1->set_inh(b1inh-MAX+INH);
      INH = MAX;
     }
   else
    {
      INH = INH + b1inh;
      b1->set_inh(0);
    }
}

int behaelter::get_max()
{
 return MAX;
}

steuerung::steuerung(int s, int a, int b)
{
     soll = s;
     b1 = new behaelter(a);
     b2 = new behaelter(b);
}

void steuerung::umfuellen()
{
   if(b1->akt_inh() == soll)
      {
        b1->fuellen();
        cout << "Eimer gefuellt \n";
        cout << "E : " << b1->akt_inh() << " K : " << b2->akt_inh() << endl;
      }
      else
            while(b1->akt_inh() != soll)
                {
                    if (b1->akt_inh() == b1->get_max())
                          {
                            b1->leeren();
                            cout << "Eimer leeren\n";
                            cout << "E : " << b1->akt_inh() << " K : " << b2->akt_inh() << endl;
                           }
                         else
                           if (b2->akt_inh() == 0)
                               {
                                 b2->fuellen();
                                 cout << "Gefaess fuellen \n";
                                 cout << "E : " << b1->akt_inh() << " K : " << b2->akt_inh() << endl;
                               }
                               else 
                                  {
                                     b1->umschuetten(b2);
                                     cout << "Schuette Gefaess nach Eimer\n";
                                     cout << "E : " << b1->akt_inh() << " K : " << b2->akt_inh() << endl;
                                   }
                 }
}


main()
{
   int vk, vg, vs;
   cout << "Eingabe Volumen Soll, Volumen Eimer, Volumen Gefaess \n";
   cin >> vs >> vk >> vg;
   steuerung knecht(vs,vk,vg);
   knecht.umfuellen();
}

