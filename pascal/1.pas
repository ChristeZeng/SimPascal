program quicksort;
var
  N, i: integer;
  arr: array [0..10000] of integer;

procedure sort(front: integer; back: integer);
var
    p: integer;
    index: integer;
    pos: integer;
    temp: integer;

begin
    if front < back then
    begin
        p := arr[front];
        index := front;
        for pos := front + 1 to back do
            begin
                if arr[pos] < p then
                begin
                    temp := arr[pos];
                    arr[pos] := arr[index + 1];
                    arr[index + 1] := temp;
                    
                    temp := arr[index + 1];
                    arr[index + 1] := arr[index];
                    arr[index] := temp;

                    index := index + 1;
                end; 
            end;
        sort(front, index - 1);
        sort(index + 1, back);
    end;
end;

begin
    readln(N);
    for i := 0 to N - 1 do
        readln(arr[i]);
    sort(0, N - 1);

    for i := 0 to N - 1 do
        writeln(arr[i]);
end.