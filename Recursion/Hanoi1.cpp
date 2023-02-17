// Hanoi.cpp
#include <iostream>
using namespace std;

void TOH(int n, int start, int hilfe, int ziel)
{
    if (n > 0)
    {
        TOH(n - 1, start, ziel, hilfe);
        cout << start << ziel << endl;
        TOH(n - 1, hilfe, start, ziel);
    }
}

int main(void)
{
    TOH(3, 1, 2, 3);

    return 0;
}