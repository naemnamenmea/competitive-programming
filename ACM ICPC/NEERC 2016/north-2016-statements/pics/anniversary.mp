u := 12mm;
s := 0.12;
a := 0.05;

def cell(expr x, y, lx, ly) =
  path box;
  box := ((0, 0)--(0, ly)--(lx, ly)--(lx, 0)--cycle) shifted (x, y) scaled u;
  fill box withcolor white;
  draw box;
enddef;

def candle(expr x, y) =
  pickup pencircle scaled 6pt;
  draw (x, y) scaled u;
enddef;

def field(expr x, y, lx, ly) =
  pickup pensquare scaled 2pt;
  cell(x, y, lx, ly);
  pickup pencircle scaled 1pt;
  for i = 1 upto lx - 1:
    draw ((i, y)--(i, y + ly)) scaled u dashed evenly;
  endfor;
  for i = 1 upto ly - 1:
    draw ((x, i)--(x + lx, i)) scaled u dashed evenly;
  endfor;
%  for i = 1 upto lx - 1:
%    for j = 0 upto ly - 1:
%      cell(x + i, y + j, 1, 1);
%    endfor;
%  endfor;
enddef;

beginfig(1)
  field(0, 0, 7, 3);
  candle(2, 2);
  candle(3, 2);
  pickup pencircle scaled 1.5pt;
  draw ((0, 0)--(4, 3)) scaled u;
%  garage(1.2, 1.4, 3, 2);
%  garage(6.5, 1.6, 3, 2);
endfig;
end.
