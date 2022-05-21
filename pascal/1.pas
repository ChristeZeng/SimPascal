program QSort;
  const
    MaxN = 100;
  var
    crediet : array[0..99] of integer;
    grade : array[0..99] of char;
    require : array[0..99] of array[0..99] of integer;
    n : integer;
    num : integer;
    idx : integer;
    c : char;
    ch : char;
    binary : char;
    totalCrediet : integer;
    attemptCrediet : integer;
    getCrediet : integer;
    remainCredite : integer;
    gradeTmp : integer;

  begin
    totalCrediet := 0;
    attemptCrediet := 0;
    getCrediet := 0;
    remainCredite := 0;
    gradeTmp := 0;
    readln(c);
    while c = 'c' do
    begin
      readln(n);
      readln(ch);
      readln(num);
      crediet[n] := num;
      readln(ch);
      readln(ch);
      write(ch);
      idx := 0;
      while ch <> '|' do
      begin
        readln(num);
        write(num);
        require[n][idx] := num;
        idx := idx + 1;
        readln(ch);
        write(ch);
        if ch = ',' then
        begin
          readln(ch);
          write(ch);
        end;
        if ch = ';' then
        begin
          require[n][idx] := -1;
          idx := idx + 1;
          readln(ch);
          write(ch);
        end;
      end; 
      require[n][idx] := -2;
      if ch = '|' then 
      begin
        readln(ch);
        write(ch);
        if ch <> '|' then 
        begin
          grade[n] := ch;
          readln(c);
          write(c);
        end;
      end;
      
      readln(c);
      if c <> 'c' then writeln('e');
    end;
  end.