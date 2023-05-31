program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;
  var
  j,i,a1,b1,c,d,e,h,x,y:integer;
   f,tt:textfile;
  a: array[1..3] of integer ; //король
  b: array[1..300] of integer ;      //сыновья

begin
e:=0;
 assign (f,'king.in');
 reset(f);
 for i:=1 to 3 do
 begin
 read(f, a[i]);
 end;
 readln(f,c);



  for i:=1 to c*3 do
  begin
  read(f, b[i]);
  end;

  for i:=3 to c do
   begin
   d:=a[3]-b[i+3];
   if (d>18) then e:=e+1;
   end;

   if (e=0) then e:=-1;




   assignfile(tt,'king.out');
   rewrite (tt);
   writeln (tt,e);
   closefile(tt);



end.
