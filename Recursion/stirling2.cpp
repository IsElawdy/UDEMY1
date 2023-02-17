#include <iostream>
using namespace std;
int stirling(int n, int k)
{
    if (k > n)
        return 0;
    if (k == 1 || k == n)
        return 1;
    // vorsicht hier wenn ein return gemacht wird, kommt es nich auf den nächsten return, sondern function bekommt ein Wert zurück.
    return stirling(n - 1, k - 1) + k * stirling(n - 1, k);
}
int main()
{
    for (int n = 1; n < 10; n++)
    {
        for (int r = 1; r <= n; r++)
        {
            cout << "Es gibt " << stirling(n, r) << " Moeglichkeiten " << n << " Elemente in " << r << "-er Gruppen anzuordnen" << endl;
        }
    }
    return 0;
}
