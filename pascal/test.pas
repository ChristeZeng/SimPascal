program QSort;
  const
    MaxN = 100;
  type
    TArray = array[1..100] of integer;
  var
    a : TArray;
    
procedure Sort(l, r: integer);
var i, j, x, y: integer;
begin
  i := l;
  j := r;
  x := a[(l + r) div 2];
  repeat
    while a[i] < x do i := i + 1;
    while a[j] > x do j := j - 1;
    if i <= j then
    begin
      y := a[i];
      a[i] := a[j];
      a[j] := y;
      i := i + 1;
      j := j - 1;
    end;
  until i > j;
  if l < j then Sort(l, j);
  if i < r then Sort(i, r);
end;

begin
  readln(n);
  for i := 1 to n do readln(a[i]);
  Sort(1, n);
  for i := 1 to n do write(a[i]);
end.