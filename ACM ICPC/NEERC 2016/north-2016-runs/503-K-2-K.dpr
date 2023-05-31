program K;

{$APPTYPE CONSOLE}

uses
  SysUtils;

type son=record
  dd,mm,yy,nom:longint;
  end;

var d0,m0,y0,n,i:longint;
f:boolean;
ans,last:son;
a:array[1..100] of son;

  function mla(x1,x2:son):boolean;
  begin
      If x1.yy>x2.yy then mla:=true else
      If x1.yy=x2.yy then
      begin
        If x1.mm>x2.mm then mla:=true else
        If x1.mm=x2.mm then    begin
          If x1.dd>x2.dd then mla:=true else  mla:=false;
          end else mla:=false;
      end else mla:=false;
  end;

begin
  { TODO -oUser -cConsole Main : Insert code here }
  assign(input,'king.in');
  assign(output,'king.out');
  reset(input);
  rewrite(output);
  ReadLN(d0,m0,y0);
  ReadLN(N);
  for i:=1 to n do
    with a[i] do
    begin
      ReadLN(dd,mm,yy);
      a[i].nom:=i;
    end;
   repeat
    f:=true;
    for i:=1 to n-1 do
      If mla(a[i],a[i+1]) then
        begin ans:=a[i];a[i]:=a[i+1];a[i+1]:=ans; f:=false; end;
   until f;
   last.dd:=d0; last.mm:=m0; last.yy:=y0-18;
   If mla(a[1],last) then ans.nom:=-1 else
   ans:=a[1];
   i:=2;
   while i<=n do
   If mla(a[i],last) then break else
    begin
    ans:=a[i];
    inc(i);

    end;
   WriteLN(ans.nom);
   close(input);
   close(output);
end.
