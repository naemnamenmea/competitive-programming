program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
w,h,x1,y1,x2,y2,xu,yu,i:longint;//dannie dlya raschetov
k1,b1,k2,b2,xt1,xt2,minx,maxx,miny,maxy,yt1,yt2:real;
xo,yo,xk,yk:longint;//otvet

begin
  assign(input,'anniversary.in');
  assign(output,'anniversary.out');
  reset(input);
  read(input,w);
  read(input,h);
  read(input,x1);
  read(input,y1);
  read(input,x2);
  read(input,y2);
  close(input);

  //schitali vse

  for i:=1 to 4 do
      begin
      if i=1 then
        begin
          xu:=0;
          yu:=0;
          if ((x1=0)and(x2=0)) then
          continue;
          k1:=(y1-yu)/(x1-xu);
          b1:=y1-k1*x1;
          k2:=(y2-yu)/(x2-xu);
          b2:=y2-k2*x2;
          //if ((k1=k2)and(b1=b2)) then continue;

          if (y1=0) then
            begin
             xt1:=w;
             yt1:=0;
            end else
          begin
          xt1:=(h-b1)/k1;
          yt1:=h;
          end;
          if (xt1>w) then
          begin
          xt1:=w;
          yt1:=k1*xt1+b1;
          end;
          if (y2=0) then
            begin
             xt2:=w;
             yt2:=0;
            end else
          begin
          xt2:=(h-b2)/k2;
          yt2:=h;
          end;
          if (xt2>w) then
          begin
          xt2:=w;
          yt2:=k2*xt2+b2;
          end;
          if ((xt1<w)and(xt2<w)) then
          begin
          if (xt1>xt2) then
            begin
              minx:=xt2;
              maxx:=xt1;
            end
            else
            begin
              minx:=xt1;
              maxx:=xt2;
            end;
          if ((minx+(1-frac(minx)))<maxx) then
            begin
              xo:=xu;
              yo:=yu;
              xk:=round(minx+(1-frac(minx)));
              yk:=h;
              write(output,xo,' ',yo,' ',xk,' ',yk);
              close(output);
              break;
            end;
          end;

          if (((xt1=w)and(xt2=w))and(yt1<>yt2)) then
          begin
          if (yt1>yt2) then
            begin
              miny:=yt2;
              maxy:=yt1;
            end
            else
            begin
              miny:=yt1;
              maxy:=yt2;
            end;
          if ((miny+(1-frac(miny)))<maxy) then
            begin
              xo:=xu;
              yo:=yu;
              yk:=round(miny+(1-frac(miny)));
              xk:=w;
              write(output,xo,' ',yo,' ',xk,' ',yk);
              close(output);
              break;
            end;
            end;
            end;
        //pervii sluchai

        if i=2 then
        begin
          xu:=0;
          yu:=h;
          if ((x1=0)and(x2=0)) then continue;
          k1:=(y1-yu)/(x1-xu);
          b1:=y1-k1*x1;
          k2:=(y2-yu)/(x2-xu);
          b2:=y2-k2*x2;
       //  if ((k1=k2)and(b1=b2)) then continue;

          if (y1=h) then
            begin
             xt1:=w;
             yt1:=h;
            end else
            begin
          xt1:=(0-b1)/k1;
          yt1:=0;
          end;
          if (xt1>w) then
          begin
          xt1:=w;
          yt1:=k1*xt1+b1;
          end;
          if (y2=h) then
            begin
             xt2:=w;
             yt2:=h;
            end else
            begin
          xt2:=(0-b2)/k2;
          yt2:=0;
          end;
          if (xt2>w) then
          begin
          xt2:=w;
          yt2:=k2*xt2+b2;
          end;
          if ((xt1<w)and(xt2<w)) then
          begin
          if (xt1>xt2) then
            begin
              minx:=xt2;
              maxx:=xt1;
            end
            else
            begin
              minx:=xt1;
              maxx:=xt2;
            end;
          if ((minx+(1-frac(minx)))<maxx) then
            begin
              xo:=xu;
              yo:=yu;
              xk:=round(minx+(1-frac(minx)));
              yk:=0;
              write(output,xo,' ',yo,' ',xk,' ',yk);
              close(output);
              break;
            end;
          end;
          if (((xt1=w)and(xt2=w))and(yt1<>yt2)) then
          begin
          if (yt1>yt2) then
            begin
              miny:=yt2;
              maxy:=yt1;
            end
            else
            begin
              miny:=yt1;
              maxy:=yt2;
            end;
          if ((miny+(1-frac(miny)))<maxy) then
            begin
              xo:=xu;
              yo:=yu;
              yk:=round(miny+(1-frac(miny)));
              xk:=w;
              write(output,xo,' ',yo,' ',xk,' ',yk);
              close(output);
              break;
            end;
        end;
        end;

      //2 sluchai
      if i=3 then
        begin
          xu:=w;
          yu:=h;
          if ((x1=w)and(x2=w)) then continue;
          k1:=(y1-yu)/(x1-xu);
          b1:=y1-k1*x1;
          k2:=(y2-yu)/(x2-xu);
          b2:=y2-k2*x2;
    //   if ((k1=k2)and(b1=b2)) then continue;

          if (y1=h) then
            begin
             xt1:=0;
             yt1:=h;
            end else
            begin
          xt1:=(0-b1)/k1;
          yt1:=0;
          end;
          if (xt1<0) then
          begin
          xt1:=0;
          yt1:=k1*xt1+b1;
          end;
          if (y2=h) then
            begin
             xt2:=w;
             yt2:=0;
            end else
            begin
          xt2:=(0-b2)/k2;
          yt2:=0;
          end;
          if (xt2<0) then
          begin
          xt2:=0;
          yt2:=k2*xt2+b2;
          end;
          if ((xt1>0)and(xt2>0)) then
          begin
          if (xt1>xt2) then
            begin
              minx:=xt2;
              maxx:=xt1;
            end
            else
            begin
              minx:=xt1;
              maxx:=xt2;
            end;
          if ((minx+(1-frac(minx)))<maxx) then
            begin
              xo:=xu;
              yo:=yu;
              xk:=round(minx+(1-frac(minx)));
              yk:=0;
              write(output,xo,' ',yo,' ',xk,' ',yk);
              close(output);
              break;
            end;
          end;
          if (((xt1=0)and(xt2=0))and(yt1<>yt2))    then
          begin
          if (yt1>yt2) then
            begin
              miny:=yt2;
              maxy:=yt1;
            end
            else
            begin
              miny:=yt1;
              maxy:=yt2;
            end;
          if ((miny+(1-frac(miny)))<maxy) then
            begin
              xo:=xu;
              yo:=yu;
              yk:=round(miny+(1-frac(miny)));
              xk:=0;
              write(output,xo,' ',yo,' ',xk,' ',yk);
              close(output);
              break;
            end;
        end;
        end;
      //3 sl
      if i=4 then
        begin
          xu:=w;
          yu:=0;
          if ((x1=w)and(x2=w)) then continue;
          k1:=(y1-yu)/(x1-xu);
          b1:=y1-k1*x1;
          k2:=(y2-yu)/(x2-xu);
          b2:=y2-k2*x2;
    //  if ((k1=k2)and(b1=b2)) then continue;

          if (y1=0) then
            begin
             xt1:=0;
             yt1:=0;
            end else
            begin
          xt1:=(h-b1)/k1;
          yt1:=h;
          end;
          if (xt1<0) then
          begin
          xt1:=0;
          yt1:=k1*xt1+b1;
          end;
          if (y2=0) then
            begin
             xt2:=w;
             yt2:=0;
            end else
            begin
          xt2:=(h-b2)/k2;
          yt2:=h;
          end;
          if (xt2<0) then
          begin
          xt2:=0;
          yt2:=k2*xt2+b2;
          end;
          if ((xt1>0)and(xt2>0)) then
          begin
          if (xt1>xt2) then
            begin
              minx:=xt2;
              maxx:=xt1;
            end
            else
            begin
              minx:=xt1;
              maxx:=xt2;
            end;
          if ((minx+(1-frac(minx)))<maxx) then
            begin
              xo:=xu;
              yo:=yu;
              xk:=round(minx+(1-frac(minx)));
              yk:=h;
              write(output,xo,' ',yo,' ',xk,' ',yk);
              close(output);
              break;
            end;
          end;
          if (((xt1=0)and(xt2=0))and(yt1<>yt2)) then
          begin
          if (yt1>yt2) then
            begin
              miny:=yt2;
              maxy:=yt1;
            end
            else
            begin
              miny:=yt1;
              maxy:=yt2;
            end;
          if ((miny+(1-frac(miny)))<maxy) then
            begin
              xo:=xu;
              yo:=yu;
              yk:=round(miny+(1-frac(miny)));
              xk:=0;
              write(output,xo,' ',yo,' ',xk,' ',yk);
              close(output);
              break;
            end;
            end;
            end;

      //4   sl
   end;
end.

