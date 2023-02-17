program barbar;
var Barbaren, Griechen, Personen, i: integer;

begin
Personen := 0;
for Barbaren := 1 to 6 do
    begin
        Griechen := Barbaren * 2;
        if (Barbaren+Griechen) MOD 4 = 0
           then
              begin
                Personen := Barbaren + Griechen;
                writeln('Anzahl der Personen: ',Personen);
                writeln('Anzahl der Barbaren: ',Barbaren);
                writeln('Anzahl der Griechen: ',Griechen);
                readln(i);
               end;
    end;
if Personen = 0
   then
      writeln('Keine Loesung moeglich');
readln(i);
end.
