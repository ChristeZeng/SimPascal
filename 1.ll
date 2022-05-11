; ModuleID = 'main'
source_filename = "main"

@e = global i8 0
@0 = private unnamed_addr constant [3 x i8] c"%c\00", align 1
@.str = constant [4 x i8] c"%c\0A\00"

define internal void @main() {
entrypoint:
  %tmp = load i8, i8* @e
  %read = call i32 (...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @0, i32 0, i32 0), i8* @e)
  %tmp1 = load i8, i8* @e
  %write = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str, i32 0, i32 0), i8 %tmp1)
  ret void
}

declare i32 @printf(i8*, ...)

declare i32 @scanf(...)
