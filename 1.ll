; ModuleID = 'main'
source_filename = "main"

@.str = constant [4 x i8] c"%d\0A\00"

define internal void @main() {
entry:
  %write = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str, i32 0, i32 0), i32 1)
  ret void
}

declare i32 @printf(i8*, ...)

declare i32 @scanf(...)
