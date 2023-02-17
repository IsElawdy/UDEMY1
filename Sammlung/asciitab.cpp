#include <iostream>
#include <iomanip>
#include <cctype>

using namespace std;

main()
{
   int i,j;
   for (i=0; i < 4; i++) 
      cout << "|dec hex char ";
   cout << endl;
   for (i=0; i < 128 / 4; i++)
       {
         cout << endl <<"| ";
         for (j=0; j < 128; j+=128/4)
             {
               cout << dec << setw(3) << i+j << " " << setw(3) << hex << i+j ;
               
               if (isprint(j)) cout << "  " << char(i+j) <<  " |";
                        else cout << "  . |  ";
             }
        }
   cout << endl;
}
        


