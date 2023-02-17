#include <iostream>
using namespace std;

int rehe(int jahr)
{
    if (jahr == 1)
        return 12;

    int anz = rehe(jahr - 1);
    anz = anz * 3 - 10;

    if (anz > 40)
        anz *= 0.3;

    return anz;
}

int main()
{
    for (int i = 1; i <= 10; i++)
        cout << i << ". Jahr | " << rehe(i) << " Rehe" << endl;
    return 0;
}