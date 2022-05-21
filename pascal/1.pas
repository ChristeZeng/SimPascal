program QSort;
  const
    MaxN = 100;
  var
    validCourse : array[0..99] of integer;
    crediet : array[0..99] of integer;
    grade : array[0..99] of char;
    require : array[0..99] of array[0..99] of integer;
    pass : array[0..99] of integer;
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
    flag : integer;
    ok : integer;

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
            pass[n] := 1;
          end;
          if ch = 'B' then
          begin
            getCrediet := getCrediet + num;
            gradeTmp := gradeTmp + 3 * num;
            pass[n] := 1;
          end;
          if ch = 'C' then
          begin
            getCrediet := getCrediet + num;
            gradeTmp := gradeTmp + 2 * num;
            pass[n] := 1;
          end;
          if ch = 'D' then
          begin
            getCrediet := getCrediet + num;
            gradeTmp := gradeTmp + 1 * num;
            pass[n] := 1;
          end;
          grade[n] := ch;
          readln(ch);
        end;
      
      readln(c);
    end;
  validCourse[validIdx] := -1;

  write('G','P','A',':',' ');
  writeln(gradeTmp);
  write('H','o','u','r','s',' ','A','t','t','e','m','p','t','e','d',':',' ');
  writeln(attemptCrediet);
  write('H','o','u','r','s',' ','C','o','m','p','l','e','t','e','d',':',' ');
  writeln(getCrediet);
  write('C','r','e','d','i','t','s',' ','R','e','m','a','i','n','i','n','g',':',' ');
  writeln(totalCrediet - getCrediet);
  write('\n');


  write('P','o','s','s','i','b','l','e',' ','C','o','u','r','s','e','s',' ','t','o',' ','T','a','k','e',' ','N','e','x','t');
  write('\n');
  validIdx := 0;
  if totalCrediet = getCrediet then write(' ',' ','N','o','n','e',' ','-',' ','C','o','n','g','r','a','t','u','l','a','t','i','o','n','s','!','\n');
  if totalCrediet <> getCrediet then
  begin
    while validCourse[validIdx] <> -1 do 
    begin
      n := validCourse[validIdx];
      idx := 0;
      flag := 1;
      ok := 0;
      if pass[n] = 1 then flag := 0;
      while flag <> 0 do
      begin
        if require[n][idx] = -2 then 
        begin
          if flag = 1 then ok := 1;
          flag := 0;
        end;
        if require[n][idx] = -1 then 
        begin
          if flag = 1 then ok := 1;
          flag := 1;
        end;
        if require[n][idx] >= 0 then 
        begin
          if pass[require[n][idx]] = 0 then flag := -1;
        end;
        idx := idx + 1;
      end;
      if ok = 1 then write(' ',' ','c', n, '\n');
      validIdx := validIdx + 1;
    end;
  end;

  end.