Program knopka;
Const N=5;
var A: array[1..N,1..N] of char;
i,j,l, k: integer; 
s: char;

begin
Writeln('"Press W - Up');  
Writeln('Press S - Down');
Writeln('Press D - Right');
Writeln('Press A - Left');
Writeln('Press X - Exit');
Writeln();

L:= N div 2 + 1;
k:=L;

for i:=1 to N do
  for j:=1 to N do
    A[i,j]:='0';
    A[L,k]:='*';

for i:=1 to N do
  for j:=1 to N do
  begin
    if j<N then write(A[i,j]:5);
    if j=N then writeln(A[i,j]:5);
  end;
  repeat
    readln(s);
    for i:=1 to N do
      for j:=1 to N do
        A[i,j]:='0';
        if s='s' then
        begin
          L:=L+1;
          if L=6 then L:=1;
        end;
        if s='w' then
        begin
          L:=L-1;
          if L=0 then L:=5;
        end;
        if s='d' then
        begin
          k:=k+1;
          if k=6 then k:=1;
        end;
        if s='a' then
        begin
          k:=k-1;
          if k=0 then k:=5;
        end;
        A[L,k]:='*';
  for i:=1 to N do
    for j:=1 to N do      
    begin
      if j<N then write(A[i,j]:5);
      if j=N then writeln(A[i,j]:5);
    end;
  until s='x';
  
end.


