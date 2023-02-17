#include <iostream>
using namespace std;

int main()
{
    int A[5][3], B[5][3];
    int i, j; // i ist Reihe, j ist Spalte

    for (i = 0; i < 5; i++) // I A einlesen
        for (j = 0; j < 3; j++)
        {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
        }

    for (i = 0; i < 5; i++) // Kontrollausgabe A
    {
        for (j = 0; j < 3; j++)
        {
            cout << A[i][j] << " \t";
        }
        cout << endl;
    }
    cout << endl
         << "########################################" << endl;

    int sum = 0;
    for (j = 0; j < 3; j++) // II Spaltensummen in A ermitteln
    {
        sum = 0;
        for (i = 0; i < 5; i++)
        {
            sum = sum + A[i][j];
        }
        cout << "Summe Spalte: " << j + 1 << " Summe = " << sum << endl;
    }
    cout << endl
         << "########################################" << endl;

    for (i = 0; i < 5; i++) // III A quadrieren, speichern in B
        for (j = 0; j < 3; j++)
        {
            B[i][j] = A[i][j] * A[i][j];
        }
    for (i = 0; i < 5; i++) // Kontrollausgabe B
    {
        for (j = 0; j < 3; j++)
        {
            cout << B[i][j] << " \t";
        }
        cout << endl;
    }

    cout << endl
         << "########################################" << endl;

    int C[5][3];
    for (i = 0; i < 5; i++) // VI C = A + B
    {
        for (j = 0; j < 3; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    cout << "Matrix C: " << endl;
    for (i = 0; i < 5; i++) // V C ausgeben
    {
        for (j = 0; j < 3; j++)
        {
            cout << C[i][j] << " \t";
        }
        cout << endl;
    }

    return 0;
}
