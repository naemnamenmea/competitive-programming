program Project1;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
 a,b,c,d,e:longint;
 count:integer;
 a1: array[1..2] of longint;
 b1: array[1..2] of longint;
begin
  assign(input,'folding.in');
  assign(output,'folding.out');
   reset(input);
   read(input,a1[1]);
   readln(input,a1[2]);
   read(input, b1[1]);
   readln(input,b1[2]);
   count:=0;
   rewrite(output);

   if a1[1]>a1[2] then
   begin
   a:=a1[1]; b:=a1[2]
   end
   else
   begin
   a:=a1[2]; b:=a1[1];
    end;

     if b1[1]>b1[2] then
     begin
   c:=b1[1]; d:=b1[2]
   end
   else
   begin
   c:=b1[2]; d:=b1[1];
   end  ;

    if (a<c) or (b<d) then
    write(output,-1)
    else
    if (a = c) and (b = d) then
    write(output, 0)
    else
    begin
      while (a > c) do
        begin
         if (a mod c = 0) and (a > c) then
         if a - ((a div c) *2) = 0 then
         a := a div c
         else
          a:= a - ((a div c)*2);
         if c = 1 then
         begin
         Inc(count, a-1)    ;
         break;
         end
         else
           a := a - (a mod c);
         inc(count);
        end;
         //

       while (b > d) do
        begin
         if ( b mod d = 0) and (b > d) then
          if    b-((b div d)*2) = 0 then
           b:=b div 2
           else
           b:= b-((b div d)*2);
         if d = 1 then
         begin
         Inc(count,b-1)    ;
         break;
         end
         else
         begin
          b := b - b mod d;
         inc(count);
         end;
        end;
        write(output, count);
    end;

end.
