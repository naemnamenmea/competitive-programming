u := 5mm;
w := 0.12;
d := 0.05;

path segment;
segment := (d, 0)--(w + d, w)--(1 - d - w, w)--(1 - d, 0)--(1 - d - w, -w)--(w + d, -w)--cycle;

def hsegment(expr x, y, r, v) =
    pickup pencircle scaled 0.5pt;

    path box;
    box := segment;
    if r = "+":
        box := segment rotated 90;
    else:
        box := segment;
    fi
    box := box shifted (x, y) scaled u;

    if v = "+":
        fill box;
    fi
    draw box withcolor 0.5white;
enddef;

string digits[];
digits[0] := "+++ +++";
digits[1] := "  +  + ";
digits[2] := "+ +++ +";
digits[3] := "+ ++ ++";
digits[4] := " +++ + ";
digits[5] := "++ + ++";
digits[6] := "++ ++++";
digits[7] := "+ +  + ";
digits[8] := "+++++++";
digits[9] := "++++ ++";

def digit(expr x, y, no) =
    hsegment(x + 0, y + 2, " ", substring (0, 1) of digits[no]);
    hsegment(x + 0, y + 1, "+", substring (1, 2) of digits[no]);
    hsegment(x + 1, y + 1, "+", substring (2, 3) of digits[no]);
    hsegment(x + 0, y + 1, " ", substring (3, 4) of digits[no]);
    hsegment(x + 0, y + 0, "+", substring (4, 5) of digits[no]);
    hsegment(x + 1, y + 0, "+", substring (5, 6) of digits[no]);
    hsegment(x + 0, y + 0, " ", substring (6, 7) of digits[no]);
enddef;

beginfig(1)
    for i := 0 upto 9:
        digit(i * 2, 0, i);
    endfor
endfig;

beginfig(2)
    digit(   0, 2.5 + 2.5, 3);
    digit(1.5,  2.5 + 2.5, 7);
    digit(  0,    0 + 2.5, 3);
    digit(1.5,    0 + 2.5, 4);
    digit(  0, -2.5 + 2.5, 7);
    digit(1.5, -2.5 + 2.5, 1);
    digit(  6,    1 + 2.5, 3);
    digit(  7,    1 + 2.5, 7);
    digit(  6,    0 + 2.5, 3);
    digit(  7,    0 + 2.5, 4);
    digit(  6,   -1 + 2.5, 7);
    digit(  7,   -1 + 2.5, 1);
    pickup pencircle scaled 0.5pt;
    drawarrow ((3.5, 1 + 2.5)--(5, 1 + 2.5)) scaled u;
endfig;

end.
