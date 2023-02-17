#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

main(int argc, char * argv[])
{
  if(argc != 4) {
     cout << "Usage : change <filename> <byte> <char> \n";
     return 1;
  }

  fstream out(argv[1], ios::in|ios::out);
  if(!out){
     cout << "Cannot open file \n";
     return 1;
  }

  out.seekp(atoi(argv[2]), ios::beg);

  out.put(*argv[3]);
  out.close();
  
  return 0;
}


   
