#include <iostream>
using namespace std;
int main()
{
 cout << "start \n";
 try
 {
	cout << "inside try-block \n";
	int j,k,l;
	cin >> j >> k;
	if (k==0)
	  throw 50;
	 else
	  l = j / k;
	 cout << l << endl;
		throw "kein Fehler";
  }

  catch (int i)
  {
		cout << " Caugth one ! number is : ";
		cout << i << endl;
  }
  catch (char *  str)
  {
		cout << "Caugth no error ! ";
		cout << str << endl;
  }

  cout << "end \n";
  return 0;
}
