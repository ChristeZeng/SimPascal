; ModuleID = 'main'
source_filename = "main"

@a = constant i32 1
@b = global i32 0
@0 = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@.str = constant [4 x i8] c"%d\0A\00"

define internal void @main() {
entrypoint:
  %tmp = load i32, i32* @b
  %read = call i32 (...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @0, i32 0, i32 0), i32* @b)
  %tmp1 = load i32, i32* @b
  %write = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str, i32 0, i32 0), i32 %tmp1)
  ret void
}

declare i32 @printf(i8*, ...)

declare i32 @scanf(...)
