v := 31mm;

def square(expr x, y, s) =
    pickup pencircle scaled 0.5pt;
%    defaultscale := 0.9;
    u := v / h;
    draw (x*u, y*u)--((x + s)*u, y*u)--((x + s)*u, (y + s)*u)--(x*u, (y + s)*u)--cycle;
    label(decimal(s), ((x+s/2)*u, (y+s/2)*u));
enddef;

beginfig(1)
    h := 3;
    square(0, 0, 3);
    square(3, 0, 2);
    square(3, 2, 1);
    square(4, 2, 1);
endfig;

beginfig(2)
    h := 6;
    square(0, 0, 2);
    square(0, 2, 2);
    square(0, 4, 2);
    square(2, 0, 3);
    square(2, 3, 3);
endfig;

beginfig(3)
    h := 4;
    square(0, 0, 4);
endfig;

beginfig(4)
    h := 11;
    square(0, 0, 7);
    square(7, 0, 6);
    square(0, 7, 4);
    square(4, 7, 4);
    square(8, 6, 5);
    square(7, 6, 1);
endfig;

beginfig(5)
    h := 7;
    square(0, 0, 2);
    square(2, 0, 2);
    square(4, 0, 2);
    square(6, 0, 3);
    square(0, 2, 5);
    square(5, 2, 1);
    square(5, 3, 4);
endfig;

end.
