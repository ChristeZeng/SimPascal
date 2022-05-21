program Test;
  const
    MaxN = 100;
  var
    crediet : array[0..99] of integer;
    grade : array[0..99] of char;
    require : array[0..99] of array[0..99] of integer;
    n : integer;
    c : char;


begin
  readln(c);
  readln(n);
  readln(c);
  writeln(c);
  writeln(n);
end.

    while c = 'c' do
    begin
      readln(n);
      write(n);
      readln(ch);
      write(ch);
      readln(num);
      crediet[n] := num;
      write(crediet[n]);
      readln(ch);
      write(ch);
      readln(ch);
      idx := 0;
      while ch <> '|' do
      begin
        readln(num);
        write(num);
        require[n][idx] := num;
        idx := idx + 1;
        readln(ch);
        write(ch);
      end; 
      require[n][idx] := -2;
      readln(ch);
      write(ch);
      if ch <> '|' then grade[n] := ch;
      readln(ch);
      write(ch);
      readln(c);
      if ch <> 'c' then writeln('e');
    end;