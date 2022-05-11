; ModuleID = 'main'
source_filename = "main"

@e = global i8 0
@.str = constant [4 x i8] c"%c\0A\00"

define internal void @main() {
entrypoint:
  store i8 101, i8* @e
  %tmp = load i8, i8* @e
  %write = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str, i32 0, i32 0), i8 %tmp)
  ret void
}

declare i32 @printf(i8*, ...)

declare i32 @scanf(...)
