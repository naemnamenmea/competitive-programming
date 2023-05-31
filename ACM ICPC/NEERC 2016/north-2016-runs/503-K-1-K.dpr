program K;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var d0,m0,y0,n,i,ans,dd,mm,yy:longint;

begin
  { TODO -oUser -cConsole Main : Insert code here }
  assign(input,'king.in');
  assign(output,'king.out');
  reset(input);
  rewrite(output);
  ReadLN(d0,m0,y0);
  ReadLN(N);
  ans:=-1;
  for i:=1 to n do
    begin
      ReadLN(dd,mm,yy);
      If y0-yy>18 then ans:=i;
      If y0-yy=18 then
         If mm<m0 then ans:=i else
          If m0=mm then
            If dd<=d0 then ans:=i;

    end;
   WriteLN(ans);
   close(input);
   close(output);
end.
