/**
Diese Zusammenfassung soll eine Hilfestellung f�r die Informatik-Pr�fung darstellen.
Sie erhebt weder Anspruch auf Vollst�ndigkeit, noch ist sie eine Garantie zum Bestehen.
Der Code l�sst sich NICHT kompilieren, er ist nur zur besseren Lesbarkeit als cpp-Datei verf�gbar!
*/

//Das ist ein einzeiliges Kommentar
/*
Das ist
ein mehrzeiliges
Kommentar
*/

/**Was man immer braucht:*/
#include <iostream> //Bibliothek f�r die Ein- und Ausgabe �ber die Bildschirmkonsole
//hier werden eventuell weitere Bibliotheken eingebunden --> W�hrend der Pr�fung nur dann, wenn explizit erlaubt!

using namespace std;

//hierher geh�ren Struktur- und Funktions-Definitionen
//sowie global verf�gbare Variablen, diese wollte man jedoch meiden!

int main()  //hier beginnt jedes Programm!
{
    /**Variablen m�ssen als erstes deklariert werden*/
    unsigned int natuerlicheZahl;
    int ganzeZahl;
    float Kommazahl;
    bool WahrOderFalsch;    //kann nur true oder false annehmen
    char einzelnesZeichen;

    /**Variablen k�nnen einfach �berschrieben und miteinander verrechnet werden*/
    int a,b;
    int c=5;
    b=c;    //b=5
    a=b*c;  //a=25
    b=a%10; //der Modulo-Opperator ist nur auf ganze Zahlen definiert, er gibt den Rest einer ganzzahligen Dision.
            //hier: b=a%10=5, denn 25/10=2 Rest 5
            //Tipp: %10 kann z.B. verwendet werden, um Dezimalzahlen zu zerlegen

    //bekannterweise rechnet der Computer mit Bin�rzahlen
    //mit 0b wird gekennzeichnet, dass eine Zahl als Bin�rzahl angegeben wird
    //folgende Operationen werden Bitweise ausgef�hrt:
    int bin1,bin2,bin3;
    bin1=bin2 & bin3;   //Bitweises AND
    bin1=bin2 | bin3;   //Bitweises OR
    bin1=bin2 & 0b1;    //bin1 wird eins, falls bin2 an letzter Stelle 1, sonst 0
    bin1=bin2 & 0b10;   //bin1 wird 2 (0b10) , falls bin2 an vorletzter Stelle 1, sonst 0
    bin1 = bin1 << 2;   //bin1 wird um zwei Stellen nach links geschoben, das entspricht einer Multiplikation mit 2^2=4
    bin2 = bin2 >> 1;   //bin2 wird um eine Stelle nach rechts geschoben, das entspricht einer Division mit 2^1=2

    if(a)   //alle Variablen ungleich 0 haben den Wahrheitswert true, alle gleich 0 den Wert false.
            //Also haben auch integer,float,char usw. einen Wahrheitswert!
        b=c;
    //Vereinfachungen
    a++;    //a=a+1;
    b--;    //b=b-1;
    a*=b;   //a=a*b; auch a/=b;a+=b;a-=b;

    /**Ein und Ausgabe*/
    //Man beachte die Richtung der Pfeile!

    //Einlesen
    cin>>a; //hier wartet das Programm, bis der Nutzer einen Wert f�r a eingegeben hat und �berschreibt die Variable entsprechend
    //Ausgeben
    cout<<"Gibt diesen Text in der Konsole aus!";
    cout<<"Man kann auch Variablen ausgeben: "<<a<<endl;
    cout<<"Und Rechnungen: "<<a+b<<endl;    //statt "a+b" wird das Ergebnis der Rechnung ausgegeben!
    cout<<endl; //gibt einen Zeilenumbruch aus
    cout<<'\n'; //gibt auch einen Zeilenumbruch aus
    cout<<'\t'; //setzt einen Tab

    /**Ausgabemanipulatoren*/
    cout.width(10);     //setzt die breite der n�chsten Ausgabe (und nur der n�chsten) auf 10
    cout.precision(5);  //Ist die n�chste Ausgabe eine Zahl, so wird sie mit 5-stelliger Genauigkeit angegeben
    cout.fill('/');     //f�llt bei der n�chsten Ausgabe Leerstellen mit /

    //mit #include <iomanip> (Einbinde unter #include <iostream>) geht es auch
    //dabei werden sogenannte Flags gesetzt, die solange gelten, bis sie zur�ckgesetzt werden,
    //also f�r alle darauffolgenden Ausgaben.
    //(Im Gegensatz zu den anderen Ausgabemanipulatoren, die immer nur f�r die unmittelbar n�chste Ausgabe gelten)
    //Die Flags werden innerhalb der normalen Ausgabe gesetzt

    cout<<a<<setprecision(1)<<a<<endl;  //in der zweiten Ausgabe ist die Genauigkeit auf 1 gesetzt
    cout<<"Ausgabe: "<<setw(5)<<setfill('x');   //breite der Ausgabe auf 5, F�llzeichen x

    /**Bedingungen*/
    if(a==b)
    {
        //wird ausgef�hrt, wenn Bedingung (a=b)
    }
    else
    {
        //wird ausgef�hrt, falls Bedingung f�r if nicht erf�llt
        //ein else-Zweig muss nicht vorhanden sein!
    }
    //andere Bedingungen:
    a<b;    //kleiner
    a<=b;   //kleiner-gleich
    a!=b;   //ungleich

    //Switch-Funktion --> Test auf mehrere einzelne Werte
    int parameter;  //Diese Variable soll getestet werden
    switch (parameter)
    {
    case 1:                         //Falls parameter==1 wird alles bis zum break ausgef�hrt, also Augabe "Wert ist 1"
        cout<<"Wert ist 1"<<endl;
        break;                      //hier wird die switch verlassen, falls parameter==1
    case 2:
        cout<<"Wert ist 2"<<endl;   //Falls parameter==2 Ausgabe von "Wert ist 2" und "Wert ist 3", da kein break dazwischen kommt!
    case 3:
        cout<<"Wert ist 3"<<endl;
        break;                      //hier wird die Switch verlassen, falls parameter==2 oder parameter==3
    default:                        //default wird ausgef�hrt, falls keiner der anderen F�lle eintritt
        cout<<"Sollte nicht passieren!";
    }
    //nat�rlich kann man auch float und chars testen! Bei chars die '' nicht vergessen, z.B. case 'a':

    /**Schleifen*/
    //wenn bekannt ist, wie oft etwas wiederholt wird
    for(int i=0;i<n;i++)
    {
        //Beim Schleifenaufruf wird i=0 gesetzt, dann in jedem Schleifendurchlauf i inkrementiert
        //Zu Beginn jedes Durchlaufs wird die Bedingung (hier i<n) �berpr�ft und abgebrochen,
        //falls diese nicht mehr erf�llt ist
        //diese Schleife wird also n-mal durchlaufen
        //Die Abbruchbedingung muss aber nichts mit i zu tun haben

        //Falls i wir hier im Schleifenkopf definiert wurde, ist diese Variable
        //au�erhalb der Schleife nicht mehr bekannt
        if(a<=0) break; //mit break; wird eine Schleife abgebrochen
    }

    //wenn noch nicht klar ist, wie oft etwas wiederholt wird
    while(b!=c) //solange b ungleich c
    {
        //Zu Beginn jedes Schleifendurchlaufes wird die Bedingung �berpr�ft und abgebrochen,
        //falls diese nicht mehr erf�llt ist
    }

    do
    {
        //Hier wird die Bedingung am Ende jedes Durchganges gepr�ft, der Inhalt also
        //mindestens einmal ausgef�hrt!
    }
    while(b)    //b!=0

    /**Felder --> gemeinsames Speichern von gleichartigen Variablen*/
    const int feldgr��e=9;  //eine Konstante (const) kann w�hrend des Programmablaufs nicht ge�ndert werden und darf daher
                            //genutzt werden um Feldgr��en festzulegen. Die Definition
    int zahlen[feldgr��e];
    float kommazahlen[10];
    //Um mit Feldern zu arbeiten muss immer die Feldadresse mit angegeben werden, sie beginnt bei 0 und endet beii feldgr��e-1!
    //Beim Arbeiten mit Feldern braucht man for-Schleifen
    //Bsp. Einlesen
    for(int i=0;i<feldgr��e;i++)
    {
        cin>>zahlen[i];
    }
    //Mit den einzelnen Elementen kann ganz normal gerechnet werden
    zahlen[0]=zahlen[feldgr��e-1]+1;

    //Matrizen --> mehrdimensionale Felder
    //zweidimensionale Matrizen kann man sich als Tabellen vorstellen
    const int zeilen=5,spalten=5;
    int noch_mehr_Zahlen[zeilen][spalten];  //Es m�ssen soviele Dimensionen definiert werden, wie man hat
    //Beim Bearbeiten wird pro Dimension eine for-Schleife gebraucht
    //Die Handhabung ist wie bei Schleifen, nur eben mit mehr Dimensionen
    //Bsp. "zeilenweises" Einlesen
    for(int i=0;i<zeilen;i++)
    {
        for(int j=0;j<spalten;j++)
        {
            cin<<noch_mehr_Zahlen[i][j];
        }
    }

    /**Strukturen*/
    //Strukturen bieten die M�glichkeit einen festen Satz unterschiedlicher Variablen gemeinsam zu speichern
    //man sollte sie oberhalb der main() definieren, um sie global verf�gbar zu machen
    struct Person{
        //hier k�nnen beliebig viele Eigenschaften eines Elementes der Art "Person" definiert werden
        int  Alter;
        char Geschlecht;
    };  //Das ; am Ende niciht vergessen!

    //Erstellen eines solchen Elementes erfolgt wie bei einfachen Variablen
    Person Student1;
    //Die Zuweisung von Werten erfolgt �ber den Punktoperator
    Student1.Alter=23;
    Student1.Geschlecht='d';
    //oft werden aus Strukturelementen Felder gemacht
    Person Studierende[100];    //Feld aus 100 Elementen des Typs Person
    Studierende[0].Alter=25;    //Beim Zugriff wird wieder die Feldadresse ben�tigt!

    /**Arbeit mit c-strings*/
    //f�r c-Zeichenketten gibt es ein paar Vereinfachungen
    char Name[10];  //Das Wort "Name" kann 9 oder weniger Buchstaben enthalten, da das letzte Zeichen eines Wortes immer '\0' ist!
    cin>>Name;      //ganz einfach...
    //Nat�rlich kann man auch Wort-Felder bilden
    char worte[19][5]; //Feld mit 19 W�rtern der maximalen L�nge 4 (Endekennzeichnung beachten)
    cin>>worte[0];     //Einlesen des ersten Wortes
    //Wortl�nge ermitteln --> Wort endet bei \0!
    int len=0;
    while(Name[len]!='\0')
    {
        len++;
    }
    //Einzelne chars k�nnen wie Zahlen verglichen werden, da jedem Zeichen ein ASCII-Wert zugeordnet ist.
    //Man unterscheidet Gro�- und Kleinbuchstaben!
    if('a'=='a');   //wahre Aussage
    if('a'=='A');   //falsche Aussage

    /**Arbeit mit Strings*/
    //F�r strings wird #include <cstring> ben�tigt --> Einbinden erfolgt ganz oben unter #include <iostream>!
    #include <cstring>
    //mehr auf http://www.cplusplus.com/reference/cstring/
    //damit stehen einem Funtionen zur Verf�gung, die einem das Leben enorm erleichtern
    char wort1[10],wort2[10];
    strcpy(wort1,"Hallo");  //�berschreibt wort1 mit "Hallo"
    strcpy(wort2,wort1);    //wort1 wird in wort2 kopiert

    if (strcmp(wort1,wort2))    //Diese Funktion wird bei Gleichheit der strings  und bei Ungleichheit 1!!!
    {
        cout<<"Worte sind ungleich"<<endl;
    }
    else
        cout<<"Worte sind ungleich"<<endl;

    /**Dateiarbeit*/
    //F�r das Arbeiten mit Textdateien wird die Bibliothek fstream ben�tigt --> Einbinden erfolgt ganz oben unter #include <iostream>!
    #include <fstream>

    //Einlesen aus Datei
    ifstream bloedeEingabe ("text.txt");    //Der Name f�r den Eingabestrom kann frei gew�hlt werden!
                                            //auch m�glich: ifstream fin("datei.txt");
                                            //Die angegebene Textdatei muss sich im gleichen Ordner befinden, wie das Programm!
	if (!bloedeEingabe )    //�berpr�fung der Eingabe, Fehlermeldung
	{
		cout << "Fehler in Dateiarbeit!" << endl;
		return 0;
	}

	int i=0;
	while (bloedeEingabe)   //Das eigentliche Einlesen
	{
		bloedeEingabe>> zahl[i];
		i++;
	}
	bloedeEingabe.close(); //Datei schlie�en

    //Ausgeben in Datei
    ofstream fout("textraus.txt");   //Auch der Name des Ausgabestroms kann frei gew�hlt werden!
    //Die Datei wird im Programmordner erzeugt, ein �berpr�fen ist nicht n�tig
    for(i=0;i<10;i++)
    {
        fout<<i+2<<endl;
    }

    /**Funktionen*/
    //auch Funktionen werden in der Regel au�erhalb der main global definiert!
    //Sie bestehen aus vier Elementen: R�ckgabedatentyp Funktionsname(�bergabeparameter){Funktionsdefinition}
    int Funktion(int a,int b)   //Diese Funktion bekommt zwei Integer �bergeben, a und b, und gibt einen Integer zur�ck: c
    {
        int c;      //irgendwelche Berechnungen
        c=a+b;
        //hier ist alles m�glich, was auch in der main m�glich ist!
        return c;   //Der Wert von c wird zur�ckgegeben
    }

    bool Funktion2(float a,float b=0)   //diese Funktion muss ein bool zur�ckgeben. b ist per default auf 0 gesetzt
    {
        if(a-b) return true;
        return false;                   //ein else ist nicht n�tig, da beim ersten return die Funktion verlassen wird
    }

    void Funktion3(int a)               //Diese Funktion gibt nichts zur�ck (void)
    {
        if(a) cout<<a<<endl;
        return;
    }

    //man kann auch strukturelemente an funktionen �bergeben:
    bool volljaehrig(Person Mensch)
    {
        if(Person.Alter>=18) return true;
        return false;
    }

    /**Referenzen --> werden gebraucht, falls mehr als ein Wert zur�ckgegeben werden soll*/
    int ReferenzFunk(int a,float b,int &c)  //c ist eine Referenz. Wird c in der Funktion ver�ndert, �ndert c sich auch in der main!
    //die �bergabe an die Funktion erfolgt ohne &
    {
        if(a<0)
        {
            c=0;        //falls a<0 wird c auch in der main 0!
            return b;
        }
        c=1;
        while(a)
        {
            b*=b;
            a--;
        }
        return b;   //der Wert von b wird zur�ckgegeben, die in der rufenden Funktion an b �bergebene Variable bleibt unver�ndert
    }
    //Eine Funktion aufrufen
    int c,d,g=5;
    float f;
    c=Funktion(c,d);                    //c wird der Wert der Funktion �bergeben
    bool t;
    t=Funktion2(c,d);                   //Funktion2 arbeitet mit den Werten c und d
    t=Funktion2(c);                     //Funktion2 arbeitet mit den Werten c und 0 (Default-Wert)
    Funktion3(d);                       //Da Funktion3 keine R�ckgabe generiert muss sie auch an keine Variable �bergeben werden
    d=ReferenzFunk(c,f,g);              //nach dieser Funktion ist g 0 oder 1, d bekommt den R�ckgabewert zugewiesen!
    //Man kann eine Funktion auch in einer Ausgabe, einem if ... aufrufen
    cout<<"Ergebnis: "<<Funktion(d,c)<<endl;

    /**Rekursion*/
    //spezielle Art von Funktionen, die sich selber aufrufen
    //wichtig ist die Abbruchbedingung!
    int rekursiveFunktion (int feld[],int len)  //dieser Funktion wird ein Feld �bergeben, die Feldgr��e geh�rt IMMER dazu!
    //feld[] ist ein Zeiger auf das erste Feldelement --> mehr dazu in Info 2
    {
        //Diese Funktion bildet die Summe aller Elemente eines Feldes

        //Abbruchbedingung --> ohne wird das Programm nie odnungsgem�� beendet
        if(len==0) return 0;
        //Rekursion
        return feld[len-1]+rekursiveFunktion(feld,len-1);   //Das Feld wird der Funktion ohne [] �bergeben!
    }

    return 0;   //die main l�uft auch ohne, ist aber praktisch zum Debuggen, also zur Fehlersuche
}
