#ifdef __GNUC__
#include <grx.h>
#include <pc.h>

// Uebersetzen mit Optionen -lpc -lgrx
// Grafikmodus einschalten
inline void Gr_on()
   { GrSetMode(Gr_default_graphics); }

// Maximalwerte fuer x- und y-Koordinate ermitteln
inline int Gr_maxx()
   { return GrMaxX(); }

inline int Gr_maxy()
   { return GrMaxY(); }

// Grafikmodus wieder ausschalten, am Ende nicht vergessen!
inline void Gr_off()
   {
    (void)getkey(); //warten auf Tastenbetaetigung
    GrSetMode(Gr_default_text);
   }

// Punkt setzen
inline void Gr_point(int x, int y)
   { GrPlot(x,y,GrWhite());}

// Linie vom Anfangs- zum Endpunkt zeichnen
inline void Gr_point(int x1, int y1, int x2, int y2)
   { GrLine(x1,y1,x2,y2,GrWhite());}

// Textausgabe
inline void Gr_text(int x, int y, char s[])
   { GrTextXY(x,y,GrWhite(), GrBlack());}

#else
#include <graphics.h>
#include <conio.h>
// Uebersetzen: tcc/bcc ... graphics.lib

inline void Gr_on()
   {
    int grdriver, grmode;
    grdriver = DETECT;
    // der letzte Parameter ist der Pfad zu den .BGI-Dateien
    // oder: .BGI im aktuellen Verzeichnis, ""-Parameter
    initgraph(&grdriver,&grmode,"c:\\bc4\\bgi\\");
   }

inline int Gr_maxx()
   { return getmaxx(); }

inline int Gr_maxy()
   { return getmaxy(); }

// Grafikmodus wieder ausschalten, am Ende nicht vergessen!
inline void Gr_off()
   {
    (void)getch(); //warten auf Tastenbetaetigung
    closegraph();
   }

inline void Gr_point(int x, int y)
   {putpixel(x,y,WHITE); }

inline void Gr_line(int x1, int y1,int x2, int y2)
   {line(x1,y1,x2,y2); }

inline void Gr_text(int x, int y, char s[])
   {outtextxy(x,y,s); }

#endif






