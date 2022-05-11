program hello;
const
  a = 1;
var
  b: integer;
  c: real;
  d: boolen;
  e: char;

begin
  b := 1;
  repeat 
    b := b + 1;
  until b > 10;
  writeln(b);
  while b < 20 do
    begin
      b := b + 1;
    end;
  writeln(b);
  if b >= 20 then
    begin
      writeln(b);
    end
  else
    begin
      writeln(1);
    end;
  for b := 1 to 10 do
    begin
      writeln(b);
    end;
  b := 2;
  case b of
    1: writeln(1);
    2: writeln(2);
    3: writeln(3);
  end;
  c := 1.0;
  d := true;
  e := 'a';
end.