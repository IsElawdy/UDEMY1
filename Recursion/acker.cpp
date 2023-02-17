
// Implementierung der Ackermann-Funktion (Rekursive Funktion)
#include <iostream>
using namespace std;

int ackermann(int m, int n)
{
    if (m == 0)
        return n + 1;
    else if (n == 0)
        return ackermann(m - 1, 1);
    else
        return ackermann(m - 1, ackermann(m, n - 1));
}

int main(void)
{
    int k, l, erg;
    char weiter, prob;
    weiter = 1; // 1 ist in while immer true
    while (weiter)
    {
        cout << "Eingabe Parameter fuer Ackermannfunktion \n";
        cin >> k >> l;
        erg = ackermann(k, l);
        cout << erg << "\n";
        // wenn probe = n -> n ist nicht gleich n --> d.h. false, weiter ist dann false->d.h. 0
        cout << "Weiter (n/j)? \n";
        cin >> prob;
        // if (prob = 'n')
        // {
        //     weiter == '0';
        // } //funktioniert nicht mit if, er kommt überhaupt nicht rein obwohl prob = n ist !!
        weiter = (prob == 'j');
    }

    return 0;
}