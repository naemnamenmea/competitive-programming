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
  a:=0;
  read(w,h,w1,h1);
  if(w1 > w) and (w1 > h) then write(-1)
  else
    if(h1 > w) and (h1 > h) then write(-1)
    else
    begin
      q := w;
      w := Max(w, h);
      h := min(q, h);

      q := w1;
      w1 := max(w1, h1);
      h1 := min(q, h1);

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
