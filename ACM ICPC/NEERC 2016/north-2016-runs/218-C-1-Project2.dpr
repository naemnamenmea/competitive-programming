program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
  i, n, k, b,c:integer;
  a:array of integer;
begin
  { TODO -oUser -cConsole Main : Insert code here }
  assign(input,'codecoder.in');reset(input);
  assign(output,'codecoder.out');rewrite(output);
  read(i);
  SetLength(a,i-1);
  for i := 0 to Length(a) do
  begin
    read(b);
    read(c);
    a[i] := b + c;
  end;
  for i := 0 to Length(a) do
  begin
    k := 0;
    for n := 0 to Length(a) do
    begin
      if (a[i] >= a[n]) and (i <> n) then
        k := k + 1;
    end;
    writeln(k);
  end;
end.
 