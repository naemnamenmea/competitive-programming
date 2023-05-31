program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  i,i1,d,m,y,n,h,h1:integer;
  d1,m1,y1,a:integer;
  ar:array of integer;
begin
  { TODO -oUser -cConsole Main : Insert code here }
  assign(input,'king.in');reset(input);
  assign(output,'king.out');rewrite(output);
  readln(d,m,y);//Date smerti
  readln(n);//kolichestvo sinov

  a := 0;
  d := d+1;
  for i1 := 0 to n - 1 do
  begin
    read(d1, m1, y1);
    d1 := d - d1;
    y1 := y - y1;
    m1 := m - m1;
    if (y1 > 18) then a := a + 1
    else
    if (y1 = 18) then
      begin
        if (m1 >0) then a := a+1
        else
        if (m1 = 0) then if(d1 >=0) then a := a+1;
      end;

  end;
  if (a = 0) then a := -1;
  write(a);
end.
