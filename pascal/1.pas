program hello;
var
  a: array[0..2] of integer;
  b: integer;

begin
  read(a[0]);
  b := a[0];
  writeln(a[0]);
  b := a[0];
  writeln(b);
end.