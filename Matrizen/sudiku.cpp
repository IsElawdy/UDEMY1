#include <iostream>
using namespace std;

int main()
{
    int i, j;
    bool stimmt = true;
    int sudoku[9][9] = {7, 6, 5, 4, 1, 2, 9, 3, 8, // richtig geloest!
                        1, 8, 2, 9, 5, 3, 4, 7, 6,
                        3, 9, 4, 7, 6, 8, 1, 5, 2,

                        8, 1, 6, 3, 2, 9, 5, 4, 7,
                        9, 4, 3, 8, 7, 5, 6, 2, 1,
                        2, 5, 7, 6, 4, 1, 8, 9, 3,

                        4, 2, 9, 1, 8, 7, 3, 6, 5,
                        5, 3, 8, 2, 9, 6, 7, 1, 4,
                        6, 7, 1, 5, 3, 4, 2, 8, 9};

    /** Taktik: Fuer jede Zeile im Sudoku wird ein Feld vom Typ bool angelegt und mit 0 (false) beschrieben.
     *  Steht im Sudoku nun eine 8 wird die im Kontrollfeld als vorhanden gekennzeichnet, indem das Element
     *  mit diesem Index (8-1, da Indexzaehlung bei 0 beginnt) auf true gesetzt wird.
     *
     *  Der Index soll nur mit dem Wert true belegt werden, wenn er vorher false war! Andernfalls ist das
     *  Sudoku falsch geloest. Die Kontrollvariable "stimmt" verhindert die weitere Ausfuehrung der Schleifen
     *  in Fehlerfall. Der Index der Fehlerstelle wird festgehalten.*/

    for (i = 0; i < 9 && stimmt; i++) // Zeilen testen
    {
        bool kontrolle[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

        for (j = 0; j < 9 && stimmt; j++)
        {
            if (kontrolle[(sudoku[i][j]) - 1] == 0)
            {
                kontrolle[(sudoku[i][j]) - 1] = 1;
                cout << sudoku[i][j] << "\t";
            }
            else
                stimmt = false;
        }
        cout << endl;
    }
    cout << i << " " << j << endl;

    if (stimmt)
    {
        for (j = 0; j < 9 && stimmt; j++) // Spalten testen
        {
            bool kontrolle[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

            for (i = 0; i < 9 && stimmt; i++)
            {
                if (kontrolle[(sudoku[i][j]) - 1] == 0)
                {
                    kontrolle[(sudoku[i][j]) - 1] = 1;
                }
                else
                    stimmt = false;
            }
        }
    }

    cout << i << " " << j << endl;

    if (stimmt)
    {
        for (i = 0; i < 9 && stimmt; i = i + 3)
        {
            for (j = 0; j < 9 && stimmt; j = j + 3)
            {
                for (int ii = i; ii < i + 3 && stimmt; ii++) // Kasten testen
                {
                    bool kontrolle[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

                    for (int jj = j; jj < j + 3 && stimmt; jj++)
                    {
                        if (kontrolle[(sudoku[ii][jj]) - 1] == 0)
                        {
                            kontrolle[(sudoku[ii][jj]) - 1] = 1;
                        }
                        else
                            stimmt = false;
                    }
                }
            }
        }
    }

    cout << i << " " << j << endl;
    /** Auswertung der Kontrollvariable "stimmt" */
    if (stimmt)
    {
        cout << "\\o/ Sudoku ist richtig!" << endl;
    }
    else
        cout << ":( Sudoku ist falsch!" << endl
             << "fehlerhaft ist die Zahl an Stelle [" << i + 1 << "][" << j + 1 << "]" << endl;

    return 0;
}