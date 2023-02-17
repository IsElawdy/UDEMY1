/**
Diese Zusammenfassung soll eine Hilfestellung für die Informatik-Prüfung darstellen.
Sie erhebt weder Anspruch auf Vollständigkeit, noch ist sie eine Garantie zum Bestehen.
Der Code lässt sich NICHT kompilieren, er ist nur zur besseren Lesbarkeit als cpp-Datei verfügbar!
*/

//Das ist ein einzeiliges Kommentar
/*
Das ist
ein mehrzeiliges
Kommentar
*/

/**Was man immer braucht:*/
#include <iostream> //Bibliothek für die Ein- und Ausgabe über die Bildschirmkonsole
//hier werden eventuell weitere Bibliotheken eingebunden --> Während der Prüfung nur dann, wenn explizit erlaubt!

using namespace std;

//hierher gehören Struktur- und Funktions-Definitionen
//sowie global verfügbare Variablen, diese wollte man jedoch meiden!

int main()  //hier beginnt jedes Programm!
{
    /**Variablen müssen als erstes deklariert werden*/
    unsigned int natuerlicheZahl;
    int ganzeZahl;
    float Kommazahl;
    bool WahrOderFalsch;    //kann nur true oder false annehmen
    char einzelnesZeichen;

    /**Variablen können einfach überschrieben und miteinander verrechnet werden*/
    int a,b;
    int c=5;
    b=c;    //b=5
    a=b*c;  //a=25
    b=a%10; //der Modulo-Opperator ist nur auf ganze Zahlen definiert, er gibt den Rest einer ganzzahligen Dision.
            //hier: b=a%10=5, denn 25/10=2 Rest 5
            //Tipp: %10 kann z.B. verwendet werden, um Dezimalzahlen zu zerlegen

    //bekannterweise rechnet der Computer mit Binärzahlen
    //mit 0b wird gekennzeichnet, dass eine Zahl als Binärzahl angegeben wird
    //folgende Operationen werden Bitweise ausgeführt:
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
    cin>>a; //hier wartet das Programm, bis der Nutzer einen Wert für a eingegeben hat und überschreibt die Variable entsprechend
    //Ausgeben
    cout<<"Gibt diesen Text in der Konsole aus!";
    cout<<"Man kann auch Variablen ausgeben: "<<a<<endl;
    cout<<"Und Rechnungen: "<<a+b<<endl;    //statt "a+b" wird das Ergebnis der Rechnung ausgegeben!
    cout<<endl; //gibt einen Zeilenumbruch aus
    cout<<'\n'; //gibt auch einen Zeilenumbruch aus
    cout<<'\t'; //setzt einen Tab

    /**Ausgabemanipulatoren*/
    cout.width(10);     //setzt die breite der nächsten Ausgabe (und nur der nächsten) auf 10
    cout.precision(5);  //Ist die nächste Ausgabe eine Zahl, so wird sie mit 5-stelliger Genauigkeit angegeben
    cout.fill('/');     //füllt bei der nächsten Ausgabe Leerstellen mit /

    //mit #include <iomanip> (Einbinde unter #include <iostream>) geht es auch
    //dabei werden sogenannte Flags gesetzt, die solange gelten, bis sie zurückgesetzt werden,
    //also für alle darauffolgenden Ausgaben.
    //(Im Gegensatz zu den anderen Ausgabemanipulatoren, die immer nur für die unmittelbar nächste Ausgabe gelten)
    //Die Flags werden innerhalb der normalen Ausgabe gesetzt

    cout<<a<<setprecision(1)<<a<<endl;  //in der zweiten Ausgabe ist die Genauigkeit auf 1 gesetzt
    cout<<"Ausgabe: "<<setw(5)<<setfill('x');   //breite der Ausgabe auf 5, Füllzeichen x

    /**Bedingungen*/
    if(a==b)
    {
        //wird ausgeführt, wenn Bedingung (a=b)
    }
    else
    {
        //wird ausgeführt, falls Bedingung für if nicht erfüllt
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
    case 1:                         //Falls parameter==1 wird alles bis zum break ausgeführt, also Augabe "Wert ist 1"
        cout<<"Wert ist 1"<<endl;
        break;                      //hier wird die switch verlassen, falls parameter==1
    case 2:
        cout<<"Wert ist 2"<<endl;   //Falls parameter==2 Ausgabe von "Wert ist 2" und "Wert ist 3", da kein break dazwischen kommt!
    case 3:
        cout<<"Wert ist 3"<<endl;
        break;                      //hier wird die Switch verlassen, falls parameter==2 oder parameter==3
    default:                        //default wird ausgeführt, falls keiner der anderen Fälle eintritt
        cout<<"Sollte nicht passieren!";
    }
    //natürlich kann man auch float und chars testen! Bei chars die '' nicht vergessen, z.B. case 'a':

    /**Schleifen*/
    //wenn bekannt ist, wie oft etwas wiederholt wird
    for(int i=0;i<n;i++)
    {
        //Beim Schleifenaufruf wird i=0 gesetzt, dann in jedem Schleifendurchlauf i inkrementiert
        //Zu Beginn jedes Durchlaufs wird die Bedingung (hier i<n) überprüft und abgebrochen,
        //falls diese nicht mehr erfüllt ist
        //diese Schleife wird also n-mal durchlaufen
        //Die Abbruchbedingung muss aber nichts mit i zu tun haben

        //Falls i wir hier im Schleifenkopf definiert wurde, ist diese Variable
        //außerhalb der Schleife nicht mehr bekannt
        if(a<=0) break; //mit break; wird eine Schleife abgebrochen
    }

    //wenn noch nicht klar ist, wie oft etwas wiederholt wird
    while(b!=c) //solange b ungleich c
    {
        //Zu Beginn jedes Schleifendurchlaufes wird die Bedingung überprüft und abgebrochen,
        //falls diese nicht mehr erfüllt ist
    }

    do
    {
        //Hier wird die Bedingung am Ende jedes Durchganges geprüft, der Inhalt also
        //mindestens einmal ausgeführt!
    }
    while(b)    //b!=0

    /**Felder --> gemeinsames Speichern von gleichartigen Variablen*/
    const int feldgröße=9;  //eine Konstante (const) kann während des Programmablaufs nicht geändert werden und darf daher
                            //genutzt werden um Feldgrößen festzulegen. Die Definition
    int zahlen[feldgröße];
    float kommazahlen[10];
    //Um mit Feldern zu arbeiten muss immer die Feldadresse mit angegeben werden, sie beginnt bei 0 und endet beii feldgröße-1!
    //Beim Arbeiten mit Feldern braucht man for-Schleifen
    //Bsp. Einlesen
    for(int i=0;i<feldgröße;i++)
    {
        cin>>zahlen[i];
    }
    //Mit den einzelnen Elementen kann ganz normal gerechnet werden
    zahlen[0]=zahlen[feldgröße-1]+1;

    //Matrizen --> mehrdimensionale Felder
    //zweidimensionale Matrizen kann man sich als Tabellen vorstellen
    const int zeilen=5,spalten=5;
    int noch_mehr_Zahlen[zeilen][spalten];  //Es müssen soviele Dimensionen definiert werden, wie man hat
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
    //Strukturen bieten die Möglichkeit einen festen Satz unterschiedlicher Variablen gemeinsam zu speichern
    //man sollte sie oberhalb der main() definieren, um sie global verfügbar zu machen
    struct Person{
        //hier können beliebig viele Eigenschaften eines Elementes der Art "Person" definiert werden
        int  Alter;
        char Geschlecht;
    };  //Das ; am Ende niciht vergessen!

    //Erstellen eines solchen Elementes erfolgt wie bei einfachen Variablen
    Person Student1;
    //Die Zuweisung von Werten erfolgt über den Punktoperator
    Student1.Alter=23;
    Student1.Geschlecht='d';
    //oft werden aus Strukturelementen Felder gemacht
    Person Studierende[100];    //Feld aus 100 Elementen des Typs Person
    Studierende[0].Alter=25;    //Beim Zugriff wird wieder die Feldadresse benötigt!

    /**Arbeit mit c-strings*/
    //für c-Zeichenketten gibt es ein paar Vereinfachungen
    char Name[10];  //Das Wort "Name" kann 9 oder weniger Buchstaben enthalten, da das letzte Zeichen eines Wortes immer '\0' ist!
    cin>>Name;      //ganz einfach...
    //Natürlich kann man auch Wort-Felder bilden
    char worte[19][5]; //Feld mit 19 Wörtern der maximalen Länge 4 (Endekennzeichnung beachten)
    cin>>worte[0];     //Einlesen des ersten Wortes
    //Wortlänge ermitteln --> Wort endet bei \0!
    int len=0;
    while(Name[len]!='\0')
    {
        len++;
    }
    //Einzelne chars können wie Zahlen verglichen werden, da jedem Zeichen ein ASCII-Wert zugeordnet ist.
    //Man unterscheidet Groß- und Kleinbuchstaben!
    if('a'=='a');   //wahre Aussage
    if('a'=='A');   //falsche Aussage

    /**Arbeit mit Strings*/
    //Für strings wird #include <cstring> benötigt --> Einbinden erfolgt ganz oben unter #include <iostream>!
    #include <cstring>
    //mehr auf http://www.cplusplus.com/reference/cstring/
    //damit stehen einem Funtionen zur Verfügung, die einem das Leben enorm erleichtern
    char wort1[10],wort2[10];
    strcpy(wort1,"Hallo");  //Überschreibt wort1 mit "Hallo"
    strcpy(wort2,wort1);    //wort1 wird in wort2 kopiert

    if (strcmp(wort1,wort2))    //Diese Funktion wird bei Gleichheit der strings  und bei Ungleichheit 1!!!
    {
        cout<<"Worte sind ungleich"<<endl;
    }
    else
        cout<<"Worte sind ungleich"<<endl;

    /**Dateiarbeit*/
    //Für das Arbeiten mit Textdateien wird die Bibliothek fstream benötigt --> Einbinden erfolgt ganz oben unter #include <iostream>!
    #include <fstream>

    //Einlesen aus Datei
    ifstream bloedeEingabe ("text.txt");    //Der Name für den Eingabestrom kann frei gewählt werden!
                                            //auch möglich: ifstream fin("datei.txt");
                                            //Die angegebene Textdatei muss sich im gleichen Ordner befinden, wie das Programm!
	if (!bloedeEingabe )    //Überprüfung der Eingabe, Fehlermeldung
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
	bloedeEingabe.close(); //Datei schließen

    //Ausgeben in Datei
    ofstream fout("textraus.txt");   //Auch der Name des Ausgabestroms kann frei gewählt werden!
    //Die Datei wird im Programmordner erzeugt, ein Überprüfen ist nicht nötig
    for(i=0;i<10;i++)
    {
        fout<<i+2<<endl;
    }

    /**Funktionen*/
    //auch Funktionen werden in der Regel außerhalb der main global definiert!
    //Sie bestehen aus vier Elementen: Rückgabedatentyp Funktionsname(Übergabeparameter){Funktionsdefinition}
    int Funktion(int a,int b)   //Diese Funktion bekommt zwei Integer übergeben, a und b, und gibt einen Integer zurück: c
    {
        int c;      //irgendwelche Berechnungen
        c=a+b;
        //hier ist alles möglich, was auch in der main möglich ist!
        return c;   //Der Wert von c wird zurückgegeben
    }

    bool Funktion2(float a,float b=0)   //diese Funktion muss ein bool zurückgeben. b ist per default auf 0 gesetzt
    {
        if(a-b) return true;
        return false;                   //ein else ist nicht nötig, da beim ersten return die Funktion verlassen wird
    }

    void Funktion3(int a)               //Diese Funktion gibt nichts zurück (void)
    {
        if(a) cout<<a<<endl;
        return;
    }

    //man kann auch strukturelemente an funktionen übergeben:
    bool volljaehrig(Person Mensch)
    {
        if(Person.Alter>=18) return true;
        return false;
    }

    /**Referenzen --> werden gebraucht, falls mehr als ein Wert zurückgegeben werden soll*/
    int ReferenzFunk(int a,float b,int &c)  //c ist eine Referenz. Wird c in der Funktion verändert, ändert c sich auch in der main!
    //die Übergabe an die Funktion erfolgt ohne &
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
        return b;   //der Wert von b wird zurückgegeben, die in der rufenden Funktion an b übergebene Variable bleibt unverändert
    }
    //Eine Funktion aufrufen
    int c,d,g=5;
    float f;
    c=Funktion(c,d);                    //c wird der Wert der Funktion übergeben
    bool t;
    t=Funktion2(c,d);                   //Funktion2 arbeitet mit den Werten c und d
    t=Funktion2(c);                     //Funktion2 arbeitet mit den Werten c und 0 (Default-Wert)
    Funktion3(d);                       //Da Funktion3 keine Rückgabe generiert muss sie auch an keine Variable übergeben werden
    d=ReferenzFunk(c,f,g);              //nach dieser Funktion ist g 0 oder 1, d bekommt den Rückgabewert zugewiesen!
    //Man kann eine Funktion auch in einer Ausgabe, einem if ... aufrufen
    cout<<"Ergebnis: "<<Funktion(d,c)<<endl;

    /**Rekursion*/
    //spezielle Art von Funktionen, die sich selber aufrufen
    //wichtig ist die Abbruchbedingung!
    int rekursiveFunktion (int feld[],int len)  //dieser Funktion wird ein Feld übergeben, die Feldgröße gehört IMMER dazu!
    //feld[] ist ein Zeiger auf das erste Feldelement --> mehr dazu in Info 2
    {
        //Diese Funktion bildet die Summe aller Elemente eines Feldes

        //Abbruchbedingung --> ohne wird das Programm nie odnungsgemäß beendet
        if(len==0) return 0;
        //Rekursion
        return feld[len-1]+rekursiveFunktion(feld,len-1);   //Das Feld wird der Funktion ohne [] übergeben!
    }

    return 0;   //die main läuft auch ohne, ist aber praktisch zum Debuggen, also zur Fehlersuche
}
