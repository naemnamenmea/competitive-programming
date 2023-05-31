u := 4.5mm;

def axes(expr x, y) =
    pickup pencircle scaled 0.5pt;

    label.llft("0", (0, 0) scaled u);

    drawarrow ((0, 0)--(x + 1, 0)) scaled u;
    label.bot(btex $x$ etex, (x + 1, 0) scaled u);
    for i := 1 upto x:
        draw ((i, 0.1)--(i, -0.1)) scaled u;
        label.bot(decimal(i), (i, 0) scaled u);
    endfor

    drawarrow ((0, 0)--(0, y + 1)) scaled u;
    label.lft(btex $y$ etex, (0, y + 1) scaled u);
    for i := 1 upto y:
        draw ((0.1, i)--(-0.1, i)) scaled u;
        label.lft(decimal(i), (0, i) scaled u);
    endfor
enddef;

beginfig(1)
    axes(8, 5);
    draw ((1, 4)--(7, 3)) scaled u;
    draw ((5, 0)--(1, 4)) scaled u;
    draw ((5, 0)--(3, 5)) scaled u;
    pickup pencircle scaled 2pt;
    draw ((7, 3)--(3, 5)--(1, 4)--(2, 1)--(5, 0)--cycle) scaled u;
endfig;

beginfig(2)
    axes(5, 5);
    draw ((1, 1)--(5, 5)) scaled u;
    draw ((3, 1)--(1, 3)) scaled u;
    pickup pencircle scaled 2pt;
    draw ((1, 1)--(3, 1)--(5, 5)--(1, 3)--cycle) scaled u;
endfig;

end.
