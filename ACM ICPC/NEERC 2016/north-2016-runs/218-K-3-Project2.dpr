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
  SetLength(ar,11);
  ar[0]:=31;
  ar[1]:=28;
  ar[2]:=31;
  ar[3]:=30;
  ar[4]:=31;
  ar[5]:=30;
  ar[6]:=31;
  ar[7]:=31;
  ar[8]:=30;
  ar[9]:=31;
  ar[10]:=30;
  ar[11]:=31;

  h := 17 * 365;
  for i1 := 0 to m - 2 do h := h + ar[i1];
  h := h + d;

  a := 0;
  for i := 0 to n - 1 do
  begin
    read(d1, m1, y1);
    h1 := (y - y1-1) * 365;
    for i1 := 0 to m1 - 2 do h1 := h1 + ar[i1];
    h1 := h1 + d1+1;

    if (h1 >= h) then a := a + 1;

  end;

  if(a=0) then a:=-1;
  write(a);
end.
