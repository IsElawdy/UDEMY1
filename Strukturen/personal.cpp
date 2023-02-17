#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

// Struktur fuer die Daten eines Mitarbeiters
struct Mitarbeiter
{
    char name[31];
    int alter;
    float gehalt;
};

int main()
{
    fstream input("mitarbeiter.txt", fstream::in);

    if (!input)
    {
        cout << "Datei nicht geoeffnet" << endl;
        return 0;
    }
    // Anzahl der Mitarbeiter
    int anzahl = 0;

    // Feld das die Daten von bis zu 30 Mitarbeitern speichern kann
    // Hinweis: wenn der Betrieb weniger als 30 Mitarbeiter hat,
    // ist nur ein Teil des Feldes mit sinnvollen Daten gefuellt
    Mitarbeiter personal[30];

    while (!input.eof())
    {
        char name[31];
        input >> name;
        if (!input.eof())
        {
            strcpy(personal[anzahl].name, name);
            input >> personal[anzahl].alter;
            input >> personal[anzahl].gehalt;
            personal[anzahl].gehalt *= 12;
            anzahl++;
        }
    }

    input.close();

    // Schleife die solange laeuft bis der Nutzer 'x' eingibt
    char eingabe = '0';
    while (eingabe != 'x')
    {
        // Menue ausgeben
        cout << "\n";
        cout << "1: Mitarbeiter anzeigen " << endl;
        cout << "2: Altersdurchschnitt anzeigen " << endl;
        cout << "3: Mitarbeiter einstellen " << endl;
        cout << "4: Gehaltserhoehung " << endl;
        cout << "5: Topverdiener anzeigen " << endl;
        cout << "6: Mitarbeiter entlassen " << endl;
        cout << "x: Programm beenden " << endl;

        // Befehl von Nutzer einlesen
        cin >> eingabe;
        cout << endl;
        anzahl = 30; // das habe ich geschrieben, ich denke, Anzahl in cases war nicht richtig definiert
        // Bearbeiten des Befehls
        switch (eingabe)
        {
        case '1':
        {
            if (anzahl)
                for (int i = 0; i < anzahl; i++)
                {
                    cout << personal[i].name;
                    cout << " Alter:" << personal[i].alter;
                    cout << " Gehalt:" << personal[i].gehalt << endl;
                }
            else
                cout << "Keine MA eingestellt" << endl;
        }
        break;

        case '2':
        {
            if (anzahl)
            {
                float sum = 0;
                for (int i = 0; i < anzahl; i++)
                {
                    sum += personal[i].alter;
                }

                cout << "durchschnittliches Alter: " << sum / anzahl << endl;
            }
            else
                cout << "Keine MA eingestellt" << endl;
        }
        break;
        case '3':
        {
            // Mitarbeiter einstellen
            // pruefen, dass Maximalanzahl noch nicht erreicht
            if (anzahl < 30)
            {
                // die erste Position im Feld an der noch keine Daten stehen hat gerade den Index anzahl
                cout << "Name des neuen MA eingeben:" << endl;
                cin >> personal[anzahl].name;
                cout << "Alter des neuen MA eingeben:" << endl;
                cin >> personal[anzahl].alter;
                cout << "Gehalt des neuen MA eingeben:" << endl;
                cin >> personal[anzahl].gehalt;

                // Anzahl Mitarbeiter aktualisieren
                anzahl++;
            }
            else
                cout << "Maximale Anzahl Mitarbeiter bereits erreicht!" << endl;
        }
        break;

        case '4':
        {
            if (anzahl)
            {
                for (int i = 0; i < anzahl; i++)
                {
                    personal[i].gehalt *= 1.1;
                }
                cout << "Gehaelter wurden erhoeht." << endl;
            }
            else
                cout << "Keine MA eingestellt" << endl;
        }
        break;

        case '5':
        {
            if (anzahl)
            {
                float dgehalt = 0;
                for (int i = 0; i < anzahl; i++)
                    dgehalt += personal[i].gehalt;

                dgehalt /= anzahl;

                // alle Mitarbeiter ausgeben, die mehr als 120% des Durchschnittsgehaltes verdienen
                for (int i = 0; i < anzahl; i++)
                {
                    if (personal[i].gehalt > 1.2 * dgehalt)
                    {
                        cout << personal[i].name;
                        cout << " Alter:" << personal[i].alter;
                        cout << " Gehalt:" << personal[i].gehalt << endl;
                    }
                }
                cout << "Durchschnittsgehalt: " << dgehalt << endl;
            }
            else
                cout << "Keine MA eingestellt" << endl;
        }
        break;

        case '6':
        {
            if (anzahl)
            {
                char del[31];
                cout << "Name des MA: ";
                cin >> del;
                int del_index = -1;
                for (int i = 0; i < anzahl; i++)
                    if (strcmp(del, personal[i].name) == 0)
                        del_index = i;

                if (del_index != -1)
                {
                    if (del_index < anzahl - 1)
                    {
                        strcpy(personal[del_index].name, personal[anzahl - 1].name);
                        personal[del_index].alter = personal[anzahl - 1].alter;
                        personal[del_index].gehalt = personal[anzahl - 1].gehalt;
                    }
                    anzahl--;
                    cout << "MA entlassen." << endl;
                }
                else
                    cout << "Keinen MA mit diesem Namen gefunden!" << endl;
            }
            else
                cout << "Keine MA eingestellt." << endl;
        }
        case 'x':
            cout << "Programm wird beendet." << endl;
            break;
        default:
            cout << "Fehleingabe! Bitte Auswahl widerholen." << endl;
        }
    }
    return 0;
}