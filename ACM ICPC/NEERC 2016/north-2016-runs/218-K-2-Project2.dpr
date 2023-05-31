program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  i,d,m,y,n:integer;
  d1,m1,y1,a:integer;
begin
  { TODO -oUser -cConsole Main : Insert code here }
  assign(input,'king.in');reset(input);
  assign(output,'king.out');rewrite(output);
  readln(d,m,y);//Date smerti
  readln(n);//kolichestvo sinov
  a:=0;
  for i:=0 to n-1 do begin
    read(d1,m1,y1);
    if(y1<y-18) then a:=a+1
    else if(y1=y)and(m<m1) then a:=a+1
    else if(m=m1)and(d<=d1) then a:=a+1;
  end;
    if(a=0) then a:=-1;
    write(a);
end.
