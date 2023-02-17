#include <dos.h>
#include "graph.h"

void tree(int xbeg, int ybeg, int rlen, int dir)
{
 int xend, yend, rlen23;

 rlen23 = rlen * 2 /3; // VerkÅrzung der 45-Grad-Linien
 switch (dir){
  case 0: xend = xbeg + rlen; yend = ybeg; break;   //waagerecht nach rechts
  case 1: xend = xbeg + rlen23; yend = ybeg - rlen23; break;  //rechts oben
  case 2: xend = xbeg; yend = ybeg - rlen; break;   //senkrecht
  case 3: xend = xbeg - rlen23; yend = ybeg - rlen23; break;  //links oben
  case 4: xend = xbeg - rlen; yend = ybeg; break;  //waagerecht nach links
 }

 if ( xend < 0 || xend > Gr_maxx() || yend < 0 || yend > Gr_maxy()
     || dir < 0 || dir > 4)
     return;

  Gr_line(xbeg,ybeg,xend,yend);
  delay(100);
  rlen = rlen * 70 / 100;  // relative Astlaenge
  if (rlen>1) {
     tree(xend, yend,rlen, ((dir+1) % 8));
     tree(xend, yend,rlen, ((dir+7) % 8));
  }
}


main (int ac, char * av[])
{
   const int stamm = 200;
   Gr_on();
	tree(Gr_maxx()/2, Gr_maxy(), stamm, 3);
   Gr_off();
}


