program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;
   type
    Rating = record
    c,b: longint;
    num:integer;
   end;
var
n,i,j:integer;
a:array of Rating;
begin
  { TODO -oUser -cConsole Main : Insert code here }
  assign(input,'codecoder.in');
  reset(input);
  readln(input,n);
  setlength(a,n);
  for i:=0 to n-1 do
  begin
   read(input,a[i].c);
   readln(input,a[i].b);
   a[i].num:=0;
  end;

  for i:=0 to n-1 do
   for j:=0 to n-1 do
    begin
     if (a[i].c>a[j].c) or (a[i].b>a[j].b) then
      a[i].num:=a[i].num+1;
    end;
      assign(output,'codecoder.out');
  rewrite(output);
   for i:=0 to n-2 do
     writeln(output,a[i].num);
   write(output,a[n-1].num);
   close(input);
   close(output);
end.
