#include <iostream>
#include <set>
#include "showseq.h"

using namespace std;

int main()
{
   int a[3] = {1,2,3};
   set <int> S, S1;
   S.insert(a,a+3);
   copy(S.begin(), S.end(), ostream_iterator<int>(cout, " "));
   cout << '\n';
   S1.insert(S.begin(),S.end());
   showSequence(S1);
}
