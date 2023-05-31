program Project1;

{$APPTYPE CONSOLE}

uses
  SysUtils;
Var
 w,h,w1,h1,w2,h2,t,x,x1:integer;
label l1,l2;

begin
  assignfile(input,'folding.in');
  assignfile(output,'folding.out');
  reset(input);
  readln(input,w1,h1);
  readln(input,w2,h2);
  close(input);
  rewrite(output);
  t:=0;
  repeat
   if (w2>w1) and (w2>h1) then goto l1;
   if (h2>w1) and (h2>h1) then goto l1;
   if w1<w2 then
    begin
     w:=w1;
     w1:=h1;
     h1:=w;
    end;
   if h1<h2 then
    begin
     h:=h1;
     h1:=w1;
     w1:=h;
    end;
   if w1>w2 then
    begin
     x:=w1 div 2;
     x1:=w1 mod 2;
     w:=x1+x;
     if w<w2 then w1:=w1-(w1-w2) else w1:=w;
     t:=t+1;
    end;
   if h1>h2 then
    begin
     x:=h1 div 2;
     x1:=h1 mod 2;
     h:=x1+x;
     if h<h2 then h1:=h1-(h1-h2) else h1:=h;
     t:=t+1;
    end;
 until (w1=w2) and (h1=h2);
 writeln(output,t);
 goto l2;
 l1: writeln(output,'-1');
 l2: close(output);
end.
