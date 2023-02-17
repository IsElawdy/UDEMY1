#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct car
{
    char marke[20];
    int km, alter, ps;
    bool unfall;
};

int main(void)
{

    ifstream einlesen("autos.txt"); // oeffnen einer Datei zum Lesen ihrer Inhalte
    if (!einlesen)
    {
        cout << "Datei konnte nicht geoeffnet werden" << endl;
        return 0;
    }

    car pkws[10];

    for (int i = 0; i < 10; i++)
    {
        einlesen >> pkws[i].marke; // Einfuegen der Variable, die die Information speichern soll
        einlesen >> pkws[i].km;
        einlesen >> pkws[i].alter;
        einlesen >> pkws[i].ps;
        einlesen >> pkws[i].unfall;
    }
    einlesen.close();

    int age = 0;
    while (age < 200)
    {
        for (int i = 0; i < 10; i++)
        {
            if (age == pkws[i].alter)
            {
                cout.width(15);
                cout << pkws[i].marke << " | ";
                cout.width(6);
                cout << pkws[i].km << " | ";
                cout.width(8);
                if (!pkws[i].alter)
                    cout << pkws[i].km << " | ";
                else
                    cout << (float)pkws[i].km / pkws[i].alter << " | ";
                cout.width(3);
                cout << pkws[i].alter << " | ";
                cout.width(4);
                cout << pkws[i].ps << " | ";
                if (pkws[i].unfall)
                    cout << "Unfallwagen" << endl;
                else
                    cout << "kein Unfallwagen" << endl;
            }
        }

        age++;
    }

    char l_marke[20];
    bool check = false;
    cout << "Bitte geben Sie Ihre Lieblingsmarke ein (max. 20 Zeichen): ";
    cin >> l_marke;

    for (i = 0; i < 10; i++)
    {
        if (strcmp(pkws[i].marke, l_marke) == 0)
            check = true;
    }

    if (check)
        cout << "Ihre Lieblingsmarke ist dabei :)" << endl;
    else
        cout << "Ihre Lieblingsmarke ist NICHT dabei" << endl;

    return 0;
}