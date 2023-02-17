#include <iostream>
#include <limits>

using namespace std;

main()
{
 cout << "Integer : \t" << sizeof(int) << endl;
 cout << "Long : \t\t" << sizeof(long) << endl;
 cout << "Short : \t" << sizeof(short) << endl;
 cout << "Float : \t" << sizeof(float) << endl;
 cout << "Double : \t" << sizeof(double) << endl;
 cout << "Long Double : \t" << sizeof(long double) << endl;
 cout << "Zahlenbereich von long double : " << numeric_limits<long double>::min()
      << '\t' << numeric_limits<long double>::max() << endl;
 cout << "Char : \t\t" << sizeof(char) << endl;
 cout << "Bool : \t\t" << sizeof(bool) << endl;
}
