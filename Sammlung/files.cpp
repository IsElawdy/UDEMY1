#include <iostream>
#include <fstream>
using namespace std;
main()
{
 ofstream fout ("test");
 
 if(!fout)
  {
   cout << "Outputfile nicht zu oeffnen \n";
   return 1;
  }

fout << "Hello\n";
fout << 100 << ' ' << hex << 100 << endl;

fout.close();

ifstream fin("test");

if(!fin)
  {
   cout << "Inputfile nicht zu oeffnen\n";
   return 1;
  }

char str[80];
int i,j;

fin >> str >> i >> j;
cout << str << ' ' << i << ' ' << j << endl;

fin.close();

return 0;

}
