#include <iostream>
using namespace std;
// N ueber K
// Dreieck mittels bino(n,k)
int bino(int n, int k)
{
    if (k == 0 || k == n)
    {
        return 1;
    }
    else
    {
        return bino(n - 1, k - 1) + bino(n - 1, k);
    }
}
int main()
{
    int n, k, i;
    // Dreieck mittels bino(n,k)
    cout << "n = ";
    cin >> n;
    cout.width(1);
    for (i = 0; i <= n; i++)
    {
        for (k = i; k < n; k++)
            cout << " ";
        for (k = 0; k <= i; k++)
            cout << bino(i, k) << " ";
        cout << endl;
    }
    cout << "**************************" << endl;
    cout << "Bitte die n-Wert und k-Wert eingeben" << endl;
    cin >> n;
    cin >> k;
    cout << "Das Ergebnis der Berechnung: " << bino(n, k) << endl;
    return 0;
}
