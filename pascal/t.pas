program QSort;
  const
    MaxN = 100;
  var
    validCourse : array[0..99] of integer;
    crediet : array[0..99] of integer;
    grade : array[0..99] of char;
    require : array[0..99] of array[0..99] of integer;
    n : integer;
    num : integer;
    cNum : integer;
    idx : integer;
    validIdx : integer;
    c : char;
    ch : char;
    binary : char;
    totalCrediet : integer;
    attemptCrediet : integer;
    getCrediet : integer;
    remainCredite : integer;
    gradeTmp : integer;
    GPA : real;

  begin
    totalCrediet := 0;
    attemptCrediet := 0;
    getCrediet := 0;
    remainCredite := 0;
    gradeTmp := 0;
    validIdx := 0;
    readln(c);
    while c = 'c' do
    begin
      readln(n);
      validCourse[validIdx] := n;
      validIdx := validIdx + 1;
      readln(ch);
      readln(num);
      crediet[n] := num;
      totalCrediet := totalCrediet + num;
      readln(ch);
      readln(ch);
      idx := 0;
      while ch <> '|' do
      begin
        readln(cNum);
        require[n][idx] := cNum;
        idx := idx + 1;
        readln(ch);
        if ch = ',' then
        begin
          readln(ch);
        end;
        if ch = ';' then
        begin
          require[n][idx] := -1;
          idx := idx + 1;
          readln(ch);
        end;
      end; 
      require[n][idx] := -2;
        readln(ch);
        if ch <> '\n' then 
        begin
          attemptCrediet := attemptCrediet + num;
          if ch = 'A' then
          begin
            getCrediet := getCrediet + num;
            gradeTmp := gradeTmp + 4 * num;
          end;
          if ch = 'B' then
          begin
            getCrediet := getCrediet + num;
            gradeTmp := gradeTmp + 3 * num;
          end;
          if ch = 'C' then
          begin
            getCrediet := getCrediet + num;
            gradeTmp := gradeTmp + 2 * num;
          end;
          if ch = 'D' then
          begin
            getCrediet := getCrediet + num;
            gradeTmp := gradeTmp + 1 * num;
          end;
          grade[n] := ch;
          readln(ch);
        end;
      
      readln(c);
      if c <> 'c' then writeln('e');
    end;
  validCourse[validIdx] := -1;

  GPA := gradeTmp / getCrediet;
  write('G','P','A',':',' ');
  writeln(GPA);
  write('H','o','u','r','s',' ','A','t','t','e','m','p','t','e','d',':',' ');
  writeln(attemptCrediet);
  write('H','o','u','r','s',' ','C','o','m','p','l','e','t','e','d',':',' ');
  writeln(getCrediet);
  write('C','r','e','d','i','t','s',' ','R','e','m','a','i','n','i','n','g',':',' ');
  writeln(totalCrediet - getCrediet);
  

  end.

  validIdx := 0;
  if totalCrediet <> getCrediet then
  begin
    while validCourse[validIdx] <> -1 do 
    begin
      n := validCourse[validIdx];
      idx := 0;
      while require[n][idx] <> -2 do
      begin

      end;
      validIdx := validIdx + 1;
    end;
  end;
  

  end.