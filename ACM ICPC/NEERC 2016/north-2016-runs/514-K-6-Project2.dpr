program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
 d, m, y, n, dmin, mmin, ymin, i, dt, mt,yt,k: integer;
begin
 assignfile(input, 'king.in');
 assignfile(output, 'king.out');
 reset(input);
 readln(input, d, m, y);
 readln(input, n);
 dmin:=31;
    mmin:=12;
    ymin:=9999;
     {dmin:=0;
    mmin:=0;
    ymin:=0;  }
 for i:=1 to n do
  begin
   readln(input, dt, mt, yt);
   if (y-yt>18) then
    begin
       if (yt-ymin>0)  then
         begin
             dmin:=dt;
             mmin:=mt;
             ymin:=yt;
             k:=i;
         end
        else
         if (yt-ymin=0) then
          if (mt<mmin) then
             begin
             dmin:=dt;
             mmin:=mt;
             ymin:=yt;
             k:=i;
             end
           else
           if (mt=mmin) then
            if (dt<dmin) then
             begin
              dmin:=dt;
              mmin:=mt;
              ymin:=yt;
             k:=i;
             end;
    end
                else
   if (y-yt=18) then
    begin
      if (mt<mmin) then
             begin
             dmin:=dt;
             mmin:=mt;
             ymin:=yt;
             k:=i;
             end
           else
          if (yt-ymin=0) then
           if (mt=mmin) then
            if (dt<dmin) then
             begin
              dmin:=dt;
              mmin:=mt;
              ymin:=yt;
             k:=i;
             end;
    end;


  end;




 if ((dmin=31) and (mmin=12) and (ymin=9999)) then
   write(output, '-1')
  else
   write(output, k);


  { TODO -oUser -cConsole Main : Insert code here }
end.

