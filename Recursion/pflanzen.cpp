#include <iostream>
using namespace std;
int anz_pflanzen(int tag, int init)
{
    if (tag >= 22)
        return 0;
    if (tag == 1)
        return init;

    int anz_p = (anz_pflanzen(tag - 1, init) * 1.2) - 5;

    if (anz_p <= 0)
        return 0;
    if (anz_p > 400)
        return anz_p * .62;

    return anz_p;
}
int main()
{
    int anz_p_init;
    cout << "Anzahl Pflanzen am Tag 1: ";
    cin >> anz_p_init;
    int max = anz_pflanzen(1, anz_p_init), d = 1;
    for (int tag = 1; tag <= 22; tag++)
    {
        cout << "Anzahl derder Pflanzen am Tag " << tag
             << ": " << anz_pflanzen(tag, anz_p_init) << endl;

        int anz_pf_heute = anz_pflanzen(tag, anz_p_init);

        if (anz_pf_heute > max)
        {
            max = anz_pf_heute;
            d = tag;
        }
    }
    cout << "Die meisten Pflanzen(" << max << ") mit " << anz_p_init << " Pflanzen am Tag 1 gab es an Tag " << d << endl;
    // doppelte Anzahl
    anz_p_init *= 2;
    int max_2 = anz_pflanzen(1, anz_p_init), d_2 = 1;

    for (int tag = 1; tag <= 22; tag++)
    {
        cout << "Anzahl derder Pflanzen am Tag " << tag
             << ": " << anz_pflanzen(tag, anz_p_init) << endl;
        int anz_pf_heute = anz_pflanzen(tag, anz_p_init);
        if (anz_pf_heute > max_2)
        {
            max_2 = anz_pf_heute;
            d_2 = tag;
        }
    }
    cout << "Die meisten Pflanzen(" << max_2 << ") mit " << anz_p_init << " Pflanzen am Tag 1 gab es an Tag " << d_2 << endl;
    if (max_2 > max)
        cout << "Es ist besser mit der doppelten Anzahl Pflanzen zu starten" << endl;
    else
        cout << "Es ist NICHT besser mit der doppelten Anzahl Pflanzen zu starten" << endl;

    return 0;
}