; ModuleID = 'main'
source_filename = "main"

@MaxN = constant i32 100
@crediet = global [100 x i32] zeroinitializer
@grade = global [100 x i8] zeroinitializer
@require = global [100 x [100 x i32]] zeroinitializer
@n = global i32 0
@num = global i32 0
@idx = global i32 0
@c = global i8 0
@ch = global i8 0
@binary = global i8 0
@totalCrediet = global i32 0
@attemptCrediet = global i32 0
@getCrediet = global i32 0
@remainCredite = global i32 0
@gradeTmp = global i32 0
@0 = private unnamed_addr constant [3 x i8] c"%c\00", align 1
@1 = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@2 = private unnamed_addr constant [3 x i8] c"%c\00", align 1
@3 = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@4 = private unnamed_addr constant [3 x i8] c"%c\00", align 1
@5 = private unnamed_addr constant [3 x i8] c"%c\00", align 1
@.str = constant [3 x i8] c"%c\00"
@6 = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@.str.1 = constant [3 x i8] c"%d\00"
@7 = private unnamed_addr constant [3 x i8] c"%c\00", align 1
@.str.2 = constant [3 x i8] c"%c\00"
@8 = private unnamed_addr constant [3 x i8] c"%c\00", align 1
@.str.3 = constant [3 x i8] c"%c\00"
@9 = private unnamed_addr constant [3 x i8] c"%c\00", align 1
@.str.4 = constant [3 x i8] c"%c\00"
@10 = private unnamed_addr constant [3 x i8] c"%c\00", align 1
@.str.5 = constant [3 x i8] c"%c\00"
@11 = private unnamed_addr constant [3 x i8] c"%c\00", align 1
@.str.6 = constant [3 x i8] c"%c\00"
@12 = private unnamed_addr constant [3 x i8] c"%c\00", align 1
@.str.7 = constant [4 x i8] c"%c\0A\00"

define i32 @main() {
entrypoint:
  store i32 0, i32* @totalCrediet
  store i32 0, i32* @attemptCrediet
  store i32 0, i32* @getCrediet
  store i32 0, i32* @remainCredite
  store i32 0, i32* @gradeTmp
  %tmp = load i8, i8* @c
  %read = call i32 (...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @0, i32 0, i32 0), i8* @c)
  br label %cond

whilecont:                                        ; preds = %cond
  ret i32 0

body:                                             ; preds = %cond
  %tmp2 = load i32, i32* @n
  %read3 = call i32 (...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @1, i32 0, i32 0), i32* @n)
  %tmp4 = load i8, i8* @ch
  %read5 = call i32 (...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @2, i32 0, i32 0), i8* @ch)
  %tmp6 = load i32, i32* @num
  %read7 = call i32 (...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @3, i32 0, i32 0), i32* @num)
  %tmp8 = load i32, i32* @num
  %tmp9 = load i32, i32* @n
  %subtmp = sub i32 %tmp9, 0
  %0 = getelementptr inbounds [100 x i32], [100 x i32]* @crediet, i32 0, i32 %subtmp
  store i32 %tmp8, i32* %0
  %tmp10 = load i8, i8* @ch
  %read11 = call i32 (...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @4, i32 0, i32 0), i8* @ch)
  %tmp12 = load i8, i8* @ch
  %read13 = call i32 (...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @5, i32 0, i32 0), i8* @ch)
  %tmp14 = load i8, i8* @ch
  %write = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str, i32 0, i32 0), i8 %tmp14)
  store i32 0, i32* @idx
  br label %cond17

cond:                                             ; preds = %ifcont88, %entrypoint
  %tmp1 = load i8, i8* @c
  %eqtmp = icmp eq i8 %tmp1, 99
  %whilecond = icmp ne i1 %eqtmp, false
  br i1 %whilecond, label %body, label %whilecont

whilecont15:                                      ; preds = %cond17
  %tmp56 = load i32, i32* @n
  %subtmp57 = sub i32 %tmp56, 0
  %1 = getelementptr inbounds [100 x [100 x i32]], [100 x [100 x i32]]* @require, i32 0, i32 %subtmp57
  %tmp58 = load i32, i32* @idx
  %subtmp59 = sub i32 %tmp58, 0
  %2 = getelementptr inbounds [100 x i32], [100 x i32]* %1, i32 0, i32 %subtmp59
  store i32 -2, i32* %2
  %tmp60 = load i8, i8* @ch
  %eqtmp61 = icmp eq i8 %tmp60, 124
  %ifcond62 = icmp ne i1 %eqtmp61, false
  br i1 %ifcond62, label %then64, label %else65

body16:                                           ; preds = %cond17
  %tmp20 = load i32, i32* @num
  %read21 = call i32 (...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @6, i32 0, i32 0), i32* @num)
  %tmp22 = load i32, i32* @num
  %write23 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str.1, i32 0, i32 0), i32 %tmp22)
  %tmp24 = load i32, i32* @num
  %tmp25 = load i32, i32* @n
  %subtmp26 = sub i32 %tmp25, 0
  %3 = getelementptr inbounds [100 x [100 x i32]], [100 x [100 x i32]]* @require, i32 0, i32 %subtmp26
  %tmp27 = load i32, i32* @idx
  %subtmp28 = sub i32 %tmp27, 0
  %4 = getelementptr inbounds [100 x i32], [100 x i32]* %3, i32 0, i32 %subtmp28
  store i32 %tmp24, i32* %4
  %tmp29 = load i32, i32* @idx
  %addtmp = add i32 %tmp29, 1
  store i32 %addtmp, i32* @idx
  %tmp30 = load i8, i8* @ch
  %read31 = call i32 (...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @7, i32 0, i32 0), i8* @ch)
  %tmp32 = load i8, i8* @ch
  %write33 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str.2, i32 0, i32 0), i8 %tmp32)
  %tmp34 = load i8, i8* @ch
  %eqtmp35 = icmp eq i8 %tmp34, 44
  %ifcond = icmp ne i1 %eqtmp35, false
  br i1 %ifcond, label %then, label %else

cond17:                                           ; preds = %ifcont43, %body
  %tmp18 = load i8, i8* @ch
  %netmp = icmp ne i8 %tmp18, 124
  %whilecond19 = icmp ne i1 %netmp, false
  br i1 %whilecond19, label %body16, label %whilecont15

ifcont:                                           ; preds = %else, %then
  %tmp40 = load i8, i8* @ch
  %eqtmp41 = icmp eq i8 %tmp40, 59
  %ifcond42 = icmp ne i1 %eqtmp41, false
  br i1 %ifcond42, label %then44, label %else45

then:                                             ; preds = %body16
  %tmp36 = load i8, i8* @ch
  %read37 = call i32 (...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @8, i32 0, i32 0), i8* @ch)
  %tmp38 = load i8, i8* @ch
  %write39 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str.3, i32 0, i32 0), i8 %tmp38)
  br label %ifcont

else:                                             ; preds = %body16
  br label %ifcont

ifcont43:                                         ; preds = %else45, %then44
  br label %cond17

then44:                                           ; preds = %ifcont
  %tmp46 = load i32, i32* @n
  %subtmp47 = sub i32 %tmp46, 0
  %5 = getelementptr inbounds [100 x [100 x i32]], [100 x [100 x i32]]* @require, i32 0, i32 %subtmp47
  %tmp48 = load i32, i32* @idx
  %subtmp49 = sub i32 %tmp48, 0
  %6 = getelementptr inbounds [100 x i32], [100 x i32]* %5, i32 0, i32 %subtmp49
  store i32 -1, i32* %6
  %tmp50 = load i32, i32* @idx
  %addtmp51 = add i32 %tmp50, 1
  store i32 %addtmp51, i32* @idx
  %tmp52 = load i8, i8* @ch
  %read53 = call i32 (...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @9, i32 0, i32 0), i8* @ch)
  %tmp54 = load i8, i8* @ch
  %write55 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str.4, i32 0, i32 0), i8 %tmp54)
  br label %ifcont43

else45:                                           ; preds = %ifcont
  br label %ifcont43

ifcont63:                                         ; preds = %else65, %ifcont73
  %tmp83 = load i8, i8* @c
  %read84 = call i32 (...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @12, i32 0, i32 0), i8* @c)
  %tmp85 = load i8, i8* @c
  %netmp86 = icmp ne i8 %tmp85, 99
  %ifcond87 = icmp ne i1 %netmp86, false
  br i1 %ifcond87, label %then89, label %else90

then64:                                           ; preds = %whilecont15
  %tmp66 = load i8, i8* @ch
  %read67 = call i32 (...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @10, i32 0, i32 0), i8* @ch)
  %tmp68 = load i8, i8* @ch
  %write69 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str.5, i32 0, i32 0), i8 %tmp68)
  %tmp70 = load i8, i8* @ch
  %netmp71 = icmp ne i8 %tmp70, 124
  %ifcond72 = icmp ne i1 %netmp71, false
  br i1 %ifcond72, label %then74, label %else75

else65:                                           ; preds = %whilecont15
  br label %ifcont63

ifcont73:                                         ; preds = %else75, %then74
  br label %ifcont63

then74:                                           ; preds = %then64
  %tmp76 = load i8, i8* @ch
  %tmp77 = load i32, i32* @n
  %subtmp78 = sub i32 %tmp77, 0
  %7 = getelementptr inbounds [100 x i8], [100 x i8]* @grade, i32 0, i32 %subtmp78
  store i8 %tmp76, i8* %7
  %tmp79 = load i8, i8* @c
  %read80 = call i32 (...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @11, i32 0, i32 0), i8* @c)
  %tmp81 = load i8, i8* @c
  %write82 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str.6, i32 0, i32 0), i8 %tmp81)
  br label %ifcont73

else75:                                           ; preds = %then64
  br label %ifcont73

ifcont88:                                         ; preds = %else90, %then89
  br label %cond

then89:                                           ; preds = %ifcont63
  %write91 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.7, i32 0, i32 0), i8 101)
  br label %ifcont88

else90:                                           ; preds = %ifcont63
  br label %ifcont88
}

declare i32 @printf(i8*, ...)

declare i32 @scanf(...)
