program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils,Math;

var
  w,h,w1,h1,q:longint;
  a:longint;
begin
  { TODO -oUser -cConsole Main : Insert code here }
  assign(input,'folding.in');reset(input);
  assign(output,'folding.out');rewrite(output);
  read(w,h,w1,h1);
   q := w;
   w := Max(w, h);
   h := min(q, h);

   q := w1;
   w1 := max(w1, h1);
   h1 := min(q, h1);
   if(w = 0) or (w1 = 0) or (h = 0) or (h1 = 0) then write(-1)
   else
    if (w1 > w) or (h1 > h) then write(-1)
    else if(w1=w) and(h1=h) then write(0)
    else
    begin

      a := 0;
      while w > w1 do
      begin
        if(w mod 2  <> 0) then w := w + 1;
        w := w div 2;
        a := a + 1;
      end;

      while h > h1 do
      begin
        if(h mod 2  <> 0) then h := h + 1;
        h := h div 2;
        a := a + 1;
      end;
      write(a);
    end;
end.