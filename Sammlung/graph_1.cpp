#include "graph.h"
#include <iostream>
using namespace std;

main()
{
 int nullx, nully;
 long x,y,d;
 char c;

 Gr_on();
 nullx = Gr_maxx()/2; nully = Gr_maxy();
 // Koordinatenkreuz:
 Gr_line(0,nully,Gr_maxx(),nully);
 Gr_line(nullx,0,nullx,Gr_maxy());
 for (d=1; d<3000;d*=2)
	for (x=(-nullx); x<=nullx;x++){
	  y = (x * x)/d;
	  if ((y < nully) && ( y > 0))
	Gr_point(nullx+x,nully-y);
	}
 Gr_text(nullx/2,nully/2,"Kurvenschar y = 1/d x**2");
 Gr_off();
 cin >> c;
}

