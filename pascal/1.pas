program hello;
var
  a: array[0..2] of integer;
  b: integer;

begin
  writeln(a[0]);
  a[0] := 1;  
  b := a[0];
  writeln(b);
end.