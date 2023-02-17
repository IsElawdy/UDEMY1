#include <iostream>
using namespace std;
class count {
private:
  static int counter;
public:
  count() {counter++;};
  ~count() {counter--;};
  static void prc()
  {
    cout << counter << "\n";
  }
};

int count::counter=0;

void main()
{
 count::prc();
 count *pa = new count;
 {
  count b;
  count c;
  c.prc();
 }
 delete pa;
 count::prc();
}
