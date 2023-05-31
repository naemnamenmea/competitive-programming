program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
   f,x:text;
   i:integer;
   a,s:string;
   mass:array[1..8] of integer;


begin
  { TODO -oUser -cConsole Main : Insert code here }
  Assign(f,'king.in');
  reset(f);
  readln(a);
  for i:=1 to length(a) do
  begin
  if s[i]= ' ' then read(a);
  close(f);
  end;
  Assign(x,'king.out');
  rewrite(x);
  writeln(x,a);
  close(x);

  


end.
 