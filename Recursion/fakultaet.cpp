#include <iostream>
using namespace std;
int fak(int n)
{
    if (n <= 0) // 0!=1
        return 1;
    return n * fak(n - 1);
}
int main()
{
    int zahl;
    int erg;

    cout << "Geben Sie eine Zahl ein:";
    cin >> zahl;
    erg = fak(zahl);
    cout << "Fakultaet von " << zahl << " ist:" << erg << endl;
    return 0;
}
