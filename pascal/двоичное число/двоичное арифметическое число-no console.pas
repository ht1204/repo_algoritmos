program Binary;
var numberA,numberB,numberC:string;
    binaryArrayA,binaryArrayB,binaryArrayC:array[byte] of byte;
    binaryBase,binaryLengthA,binaryLengthB,i,j,n,p:byte;
    t,k:integer;
    flag,flagMenu:boolean;
    option:char;
    
    
(*validator input number function *)
function inputValidator(inputNumber: string; binaryBase: Byte): boolean;
begin
   i:=1; {counter}
   while (i<=length(inputNumber)) and flag do
      if not(ord(inputNumber[i])-48 in [0..binaryBase-1])then 
        flag:=false
      else i:=i+1;
      if not flag then 
          writeln('This is not a binary number, please repeat input');
   inputValidator:=flag; {return boolean value}
end;{end function}

(*Function for binary addition and substraction*)
function arithmeticBinaryProcessor(numberA,numberB:string; option:integer;binaryBase:byte): string;
var i,j:byte;
begin
  binaryLengthA:=length(numberA);
  binaryLengthB:=length(numberB);
  i:=1;
  for i:=1 to binaryLengthA do
    begin
      val(numberA[i],t,k);
      binaryArrayA[i]:=t;
    end;
  for i:=1 to binaryLengthB do
    begin
      val(numberB[i],t,k);
      binaryArrayB[i]:=t;
    end;
  if binaryLengthA>binaryLengthB then
  begin
    n:=binaryLengthA;
    for i:=1 to binaryLengthA-binaryLengthB do
      begin
        binaryLengthB:=binaryLengthB+1;
        for j:=binaryLengthB downto 2 do
        binaryArrayB[j]:=binaryArrayB[j-1];
        binaryArrayB[1]:=0;
      end;
   end
  else if binaryLengthB>binaryLengthA then
   begin
     n:=binaryLengthB;
     for i:=1 to binaryLengthB-binaryLengthA do
       begin
         binaryLengthA:=binaryLengthA+1;
         for j:=binaryLengthA downto 2 do
         binaryArrayA[j]:=binaryArrayA[j-1];
         binaryArrayA[1]:=0;
       end;
    end
  else if binaryLengthB=binaryLengthA then n:=binaryLengthA;
  p:=0;
for i:=n downto 1 do
  begin
    if option=2 then
      begin
        binaryArrayC[i]:=binaryArrayA[i]+binaryArrayB[i]+p;
      end
    else
      begin
        binaryArrayC[i]:=binaryArrayA[i]-binaryArrayB[i]-p;
      end;
   if (binaryArrayC[i]>binaryBase-1) and (i>1) then
      begin
       binaryArrayC[i]:=binaryArrayC[i] mod binaryBase;
       p:=1;
      end
    else p:=0;
  end;
if binaryArrayC[1]>binaryBase-1 then
  begin
    binaryArrayC[i]:=binaryArrayC[i] mod binaryBase;
    n:=n+1;
    for j:=n downto 2 do
    binaryArrayC[j]:=binaryArrayC[j-1];
    binaryArrayC[1]:=1;
  end;
  numberC:=' ';
  for i:=1 to n do
    begin
    numberC:=numberC+binaryArrayC[i];
    end;
    arithmeticBinaryProcessor:=numberC;{return value}
 
end;{end function}
    
    
begin
  binaryBase:=2; {binary base is defined}
  flagMenu:=true; {control menu loop}
  numberA:=' ';
  numberB:=' ';
  repeat
  writeln('---------------Menu options/Опции меню----------------------' );
  writeln('1-Input binary Numbers/Ввод двоичных чисел' );
  writeln('2-Binary addition/Бинарное сложение' );
  writeln('3-Binary subtraction/Бинарное вычитание' );
  writeln('4-Exit/Программа выхода' );
  readln(option);
  
  if option='1' then
    begin
     repeat
       repeat
          write('Input number A/Введите число A:  ');
          readln(numberA);
       until trim(numberA) <> '';
        flag:=true;
        flag:= inputValidator(numberA,binaryBase);
     until flag;
     repeat
        repeat
          write('Input number B/Введите число A:  ');
          readln(numberB);
        until trim(numberB) <> '';
        flag:=true;
        flag:= inputValidator(numberB,binaryBase);{get boolean value}
     until flag;
     end
   else if option='2' then {addition}
   begin 
     if (trim(numberA) = '') and (trim(numberB) = '') then
       begin
          writeln('Please, input binary numbers/Пожалуйста, введите двоичные числа ');
          readln
       end
      else
      begin
        if length(numberA)>length(numberB) then
         begin
            writeln(numberA,' + ',numberB);
         end
        else
        begin
          writeln(numberB,' + ',numberA);
        end;
        writeln('Number C/Число С:  ');
        numberC:=arithmeticBinaryProcessor(numberA,numberB,2,binaryBase);{call function to addition}
        writeln(numberC);
        readln
      end;
  end
  else if option='3' then {substraction}
  begin
    if (trim(numberA) = '') and (trim(numberB) = '') then
       begin
          writeln('Please, input binary numbers/Пожалуйста, введите двоичные числа');
          readln
       end
      else
      begin
        if length(numberA)>length(numberB) then
         begin
            writeln(numberA,' - ',numberB);
         end
        else
        begin
          writeln(numberB,' - ',numberA);
        end;
        writeln('Number C/Число С:  ');
        if length(numberA)>length(numberB) then
        begin
          numberC:=arithmeticBinaryProcessor(numberA,numberB,3,binaryBase);{call function to substraction}
        end
        else
        begin
          numberC:=arithmeticBinaryProcessor(numberB,numberA,3,binaryBase);{call function to substraction}
        end;        
        writeln(numberC);
        readln
      end;
  end
 else if option='4' then {exit program}
    begin 
      write('--------------------');
      write('Good Bye!/До свидания!');
      write('--------------------');
      flagMenu:=false;
      readln
    end  
until flagMenu=false;
  
end.