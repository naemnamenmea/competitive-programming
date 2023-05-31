program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var x1,x2,y1,y2,w,h,ox1,ox2,oy1,oy2:integer;
k,k1,k2,k3: real;
label l1;

begin
assignfile(input, 'anniversary.in');
assignfile(output, 'anniversary.out');
reset(input);
rewrite(output);
readln(input,w,h,x1,y1,x2,y2);
close(input);
oy2:=h;
oy1:=0;
for ox1:=0 to w do
begin
k1:=(y1)/(x1-ox1);
k2:=(y2)/(x2-ox1);
if (k1>k2) then
begin
k3:=k1;
k1:=k2;
k2:=k3;
end;
for ox2:=1 to w do
begin
if ((ox2-ox1)<>0) then
k:=(oy2-oy1)/(ox2-ox1);
if ((k1<k) and (k<k2)) then
begin
write(output,ox1,' ',oy1,' ',ox2,' ',oy2);
goto l1;
end;

end;
end;
l1: close(output);
end.
