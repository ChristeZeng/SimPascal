program RecordTest;
  var
    i : integer;
    rec : record
      a: integer;
      b : real;
      c : integer;
    end;

  begin
    i := 1;
    i := rec.c;
    writeln(i);
  end.