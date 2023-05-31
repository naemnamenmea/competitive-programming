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
n,i,j,c,t,tk,ck:integer;
a:array of integer;
begin
  { TODO -oUser -cConsole Main : Insert code here }
  assign(input,'codecoder.in');
  reset(input);
  readln(input,n);
  {setlength(a,n);
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
   {assign(output,'p.txt');
   rewrite(output);
   for i:=1 to 100000 do
    writeln (output,1000000,' ',1000000);
    close(output); }
     setlength(a,n);
     i:=0;
     while not eof do
      begin
       read(input,c);
       read(input,t);
       reset(input);
       readln(input);
       while not eof do
        begin
         read(input,ck);
         readln(input,tk);
         if (c>ck) or (t>tk) then
          a[i]:=a[i]+1;
        end;
        reset(input);
        for j:=0 to i+1 do
         readln(input);
        i:=i+1;
     end;
     assign(output,'codecoder.out');
     rewrite(output);
     for i:=0 to n-1 do
      writeln(a[i]);
     close(input);
     close(output);
end.
