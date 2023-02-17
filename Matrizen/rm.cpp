#include <iostream>
using namespace std;
int main()
{
    int rm[6][15];
    int i, j;
    // erste spalte einlesen
    for (i = 0; i < 6; i++)
    {
        cout << "erste spalte [" << i << "][0] = ";
        cin >> rm[i][0];
    }
    // restliche Matrix fuellen
    for (j = 1; j < 15; j++) // spalte
    {
        for (i = 0; i < 6; i++) // Reihe
        {
            switch (i)
            {
            case 0: // in der Aufgabe Zeile 1, hier ist 0
                rm[i][j] = rm[i][j - 1] + rm[i + 1][j - 1];
                break;
            case 5:
                rm[i][j] = rm[i][j - 1] + rm[i - 1][j - 1];
                break;
            default:
                rm[i][j] = rm[i - 1][j - 1] - rm[i][j - 1] - rm[i + 1][j - 1];
            }
        }
    }
    // Kontrollausgabe
    cout << "################# Rechteckmatrix #################" << endl;
    for (i = 0; i < 6; i++)
    {
        for (j = 0; j < 15; j++)
        {
            cout.width(8);
            cout.fill(' ');
            cout << rm[i][j];
        }
        cout << endl;
    }
    cout << "##################################################" << endl
         << endl;
    // spaltensummen
    int max = 0, sum = 0, index = 0;
    for (i = 0; i < 6; i++) // 1. potentielles Maximum festlegen
    {
        max += rm[i][0];
    }
    for (j = 1; j < 15; j++)
    {
        sum = 0;
        for (i = 0; i < 6; i++)
        {
            sum += rm[i][j];
        }

        if (sum > max)
        {
            max = sum;
            index = j;
        }
    }

    cout << "groesste Spaltensumme: " << max << " an Stelle " << index + 1 << endl;

    return 0;
}