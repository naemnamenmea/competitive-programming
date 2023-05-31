program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
 d, m, y, n, i, dt, mt,yt,s,min,k: integer;
 month: array [0..12] of integer;
begin
  month[0]:= 0;
  month[1]:= 31;
  month[2]:= 31+28;
  month[3]:= 31+28+31;
  month[4]:= 31+28+31+30;
  month[5]:= 31+28+31+30+31;
  month[6]:= 31+28+31+30+31+30;
  month[7]:= 31+28+31+30+31+30+31;
  month[8]:= 31+28+31+30+31+30+31+31;
  month[9]:= 31+28+31+30+31+30+31+31+30;
  month[10]:= 31+28+31+30+31+30+31+31+30+31;
  month[11]:=  31+28+31+30+31+30+31+31+30+31+30;
  month[12]:= 31+28+31+30+31+30+31+31+30+31+30+31;


 assignfile(input, 'king.in');
 assignfile(output, 'king.out');
 reset(input);
 readln(input, d, m, y);
 readln(input, n);
 rewrite(output);
 min:=9999999;
 k:=0;
 for i:=1 to n do
 begin
  readln(dt, mt, yt);
   s:=(y-yt-1)*365+month[m-1]+d+(month[12]-month[mt0-1])-dt;
  if (s>=18*365) then
  begin
   //s:=(y-yt-1)*365+month[mt-1]+d+(month[12]-month[mt-1])-dt;
     // writeln(output, s);
        if (s<min) then
       begin
        k:=i;
        min:=s;
       end;
       end;
   end;








   if (k<>0) then
   writeln (output, k)
   else
   writeln (output, '-1');

  { TODO -oUser -cConsole Main : Insert code here }
end.

