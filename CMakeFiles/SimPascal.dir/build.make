# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/bcct/code/Test/SimPascal

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bcct/code/Test/SimPascal

# Include any dependencies generated for this target.
include CMakeFiles/SimPascal.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SimPascal.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SimPascal.dir/flags.make

token.cpp: SimPascal.l
token.cpp: parser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/bcct/code/Test/SimPascal/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating token.cpp"
	lex -o token.cpp /home/bcct/code/Test/SimPascal/SimPascal.l

parser.hpp: SimPascal.y
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/bcct/code/Test/SimPascal/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Generating parser.hpp, parser.cpp"
	yacc -d -o parser.cpp /home/bcct/code/Test/SimPascal/SimPascal.y

parser.cpp: parser.hpp
	@$(CMAKE_COMMAND) -E touch_nocreate parser.cpp

CMakeFiles/SimPascal.dir/main.cpp.o: CMakeFiles/SimPascal.dir/flags.make
CMakeFiles/SimPascal.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bcct/code/Test/SimPascal/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/SimPascal.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SimPascal.dir/main.cpp.o -c /home/bcct/code/Test/SimPascal/main.cpp

CMakeFiles/SimPascal.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SimPascal.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bcct/code/Test/SimPascal/main.cpp > CMakeFiles/SimPascal.dir/main.cpp.i

CMakeFiles/SimPascal.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SimPascal.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bcct/code/Test/SimPascal/main.cpp -o CMakeFiles/SimPascal.dir/main.cpp.s

CMakeFiles/SimPascal.dir/generator/CodeGenerator.cpp.o: CMakeFiles/SimPascal.dir/flags.make
CMakeFiles/SimPascal.dir/generator/CodeGenerator.cpp.o: generator/CodeGenerator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bcct/code/Test/SimPascal/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/SimPascal.dir/generator/CodeGenerator.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SimPascal.dir/generator/CodeGenerator.cpp.o -c /home/bcct/code/Test/SimPascal/generator/CodeGenerator.cpp

CMakeFiles/SimPascal.dir/generator/CodeGenerator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SimPascal.dir/generator/CodeGenerator.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bcct/code/Test/SimPascal/generator/CodeGenerator.cpp > CMakeFiles/SimPascal.dir/generator/CodeGenerator.cpp.i

CMakeFiles/SimPascal.dir/generator/CodeGenerator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SimPascal.dir/generator/CodeGenerator.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bcct/code/Test/SimPascal/generator/CodeGenerator.cpp -o CMakeFiles/SimPascal.dir/generator/CodeGenerator.cpp.s

CMakeFiles/SimPascal.dir/generator/genConstType.cpp.o: CMakeFiles/SimPascal.dir/flags.make
CMakeFiles/SimPascal.dir/generator/genConstType.cpp.o: generator/genConstType.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bcct/code/Test/SimPascal/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/SimPascal.dir/generator/genConstType.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SimPascal.dir/generator/genConstType.cpp.o -c /home/bcct/code/Test/SimPascal/generator/genConstType.cpp

CMakeFiles/SimPascal.dir/generator/genConstType.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SimPascal.dir/generator/genConstType.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bcct/code/Test/SimPascal/generator/genConstType.cpp > CMakeFiles/SimPascal.dir/generator/genConstType.cpp.i

CMakeFiles/SimPascal.dir/generator/genConstType.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SimPascal.dir/generator/genConstType.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bcct/code/Test/SimPascal/generator/genConstType.cpp -o CMakeFiles/SimPascal.dir/generator/genConstType.cpp.s

CMakeFiles/SimPascal.dir/generator/genExp.cpp.o: CMakeFiles/SimPascal.dir/flags.make
CMakeFiles/SimPascal.dir/generator/genExp.cpp.o: generator/genExp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bcct/code/Test/SimPascal/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/SimPascal.dir/generator/genExp.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SimPascal.dir/generator/genExp.cpp.o -c /home/bcct/code/Test/SimPascal/generator/genExp.cpp

CMakeFiles/SimPascal.dir/generator/genExp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SimPascal.dir/generator/genExp.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bcct/code/Test/SimPascal/generator/genExp.cpp > CMakeFiles/SimPascal.dir/generator/genExp.cpp.i

CMakeFiles/SimPascal.dir/generator/genExp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SimPascal.dir/generator/genExp.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bcct/code/Test/SimPascal/generator/genExp.cpp -o CMakeFiles/SimPascal.dir/generator/genExp.cpp.s

CMakeFiles/SimPascal.dir/generator/genFunc.cpp.o: CMakeFiles/SimPascal.dir/flags.make
CMakeFiles/SimPascal.dir/generator/genFunc.cpp.o: generator/genFunc.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bcct/code/Test/SimPascal/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/SimPascal.dir/generator/genFunc.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SimPascal.dir/generator/genFunc.cpp.o -c /home/bcct/code/Test/SimPascal/generator/genFunc.cpp

CMakeFiles/SimPascal.dir/generator/genFunc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SimPascal.dir/generator/genFunc.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bcct/code/Test/SimPascal/generator/genFunc.cpp > CMakeFiles/SimPascal.dir/generator/genFunc.cpp.i

CMakeFiles/SimPascal.dir/generator/genFunc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SimPascal.dir/generator/genFunc.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bcct/code/Test/SimPascal/generator/genFunc.cpp -o CMakeFiles/SimPascal.dir/generator/genFunc.cpp.s

CMakeFiles/SimPascal.dir/generator/genProgram.cpp.o: CMakeFiles/SimPascal.dir/flags.make
CMakeFiles/SimPascal.dir/generator/genProgram.cpp.o: generator/genProgram.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bcct/code/Test/SimPascal/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/SimPascal.dir/generator/genProgram.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SimPascal.dir/generator/genProgram.cpp.o -c /home/bcct/code/Test/SimPascal/generator/genProgram.cpp

CMakeFiles/SimPascal.dir/generator/genProgram.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SimPascal.dir/generator/genProgram.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bcct/code/Test/SimPascal/generator/genProgram.cpp > CMakeFiles/SimPascal.dir/generator/genProgram.cpp.i

CMakeFiles/SimPascal.dir/generator/genProgram.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SimPascal.dir/generator/genProgram.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bcct/code/Test/SimPascal/generator/genProgram.cpp -o CMakeFiles/SimPascal.dir/generator/genProgram.cpp.s

CMakeFiles/SimPascal.dir/generator/genStmt.cpp.o: CMakeFiles/SimPascal.dir/flags.make
CMakeFiles/SimPascal.dir/generator/genStmt.cpp.o: generator/genStmt.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bcct/code/Test/SimPascal/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/SimPascal.dir/generator/genStmt.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SimPascal.dir/generator/genStmt.cpp.o -c /home/bcct/code/Test/SimPascal/generator/genStmt.cpp

CMakeFiles/SimPascal.dir/generator/genStmt.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SimPascal.dir/generator/genStmt.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bcct/code/Test/SimPascal/generator/genStmt.cpp > CMakeFiles/SimPascal.dir/generator/genStmt.cpp.i

CMakeFiles/SimPascal.dir/generator/genStmt.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SimPascal.dir/generator/genStmt.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bcct/code/Test/SimPascal/generator/genStmt.cpp -o CMakeFiles/SimPascal.dir/generator/genStmt.cpp.s

CMakeFiles/SimPascal.dir/VIS/ConstVis.cpp.o: CMakeFiles/SimPascal.dir/flags.make
CMakeFiles/SimPascal.dir/VIS/ConstVis.cpp.o: VIS/ConstVis.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bcct/code/Test/SimPascal/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/SimPascal.dir/VIS/ConstVis.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SimPascal.dir/VIS/ConstVis.cpp.o -c /home/bcct/code/Test/SimPascal/VIS/ConstVis.cpp

CMakeFiles/SimPascal.dir/VIS/ConstVis.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SimPascal.dir/VIS/ConstVis.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bcct/code/Test/SimPascal/VIS/ConstVis.cpp > CMakeFiles/SimPascal.dir/VIS/ConstVis.cpp.i

CMakeFiles/SimPascal.dir/VIS/ConstVis.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SimPascal.dir/VIS/ConstVis.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bcct/code/Test/SimPascal/VIS/ConstVis.cpp -o CMakeFiles/SimPascal.dir/VIS/ConstVis.cpp.s

CMakeFiles/SimPascal.dir/VIS/NodeVis.cpp.o: CMakeFiles/SimPascal.dir/flags.make
CMakeFiles/SimPascal.dir/VIS/NodeVis.cpp.o: VIS/NodeVis.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bcct/code/Test/SimPascal/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/SimPascal.dir/VIS/NodeVis.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SimPascal.dir/VIS/NodeVis.cpp.o -c /home/bcct/code/Test/SimPascal/VIS/NodeVis.cpp

CMakeFiles/SimPascal.dir/VIS/NodeVis.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SimPascal.dir/VIS/NodeVis.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bcct/code/Test/SimPascal/VIS/NodeVis.cpp > CMakeFiles/SimPascal.dir/VIS/NodeVis.cpp.i

CMakeFiles/SimPascal.dir/VIS/NodeVis.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SimPascal.dir/VIS/NodeVis.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bcct/code/Test/SimPascal/VIS/NodeVis.cpp -o CMakeFiles/SimPascal.dir/VIS/NodeVis.cpp.s

CMakeFiles/SimPascal.dir/VIS/ProgramVis.cpp.o: CMakeFiles/SimPascal.dir/flags.make
CMakeFiles/SimPascal.dir/VIS/ProgramVis.cpp.o: VIS/ProgramVis.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bcct/code/Test/SimPascal/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/SimPascal.dir/VIS/ProgramVis.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SimPascal.dir/VIS/ProgramVis.cpp.o -c /home/bcct/code/Test/SimPascal/VIS/ProgramVis.cpp

CMakeFiles/SimPascal.dir/VIS/ProgramVis.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SimPascal.dir/VIS/ProgramVis.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bcct/code/Test/SimPascal/VIS/ProgramVis.cpp > CMakeFiles/SimPascal.dir/VIS/ProgramVis.cpp.i

CMakeFiles/SimPascal.dir/VIS/ProgramVis.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SimPascal.dir/VIS/ProgramVis.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bcct/code/Test/SimPascal/VIS/ProgramVis.cpp -o CMakeFiles/SimPascal.dir/VIS/ProgramVis.cpp.s

CMakeFiles/SimPascal.dir/VIS/StmtVis.cpp.o: CMakeFiles/SimPascal.dir/flags.make
CMakeFiles/SimPascal.dir/VIS/StmtVis.cpp.o: VIS/StmtVis.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bcct/code/Test/SimPascal/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/SimPascal.dir/VIS/StmtVis.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SimPascal.dir/VIS/StmtVis.cpp.o -c /home/bcct/code/Test/SimPascal/VIS/StmtVis.cpp

CMakeFiles/SimPascal.dir/VIS/StmtVis.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SimPascal.dir/VIS/StmtVis.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bcct/code/Test/SimPascal/VIS/StmtVis.cpp > CMakeFiles/SimPascal.dir/VIS/StmtVis.cpp.i

CMakeFiles/SimPascal.dir/VIS/StmtVis.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SimPascal.dir/VIS/StmtVis.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bcct/code/Test/SimPascal/VIS/StmtVis.cpp -o CMakeFiles/SimPascal.dir/VIS/StmtVis.cpp.s

CMakeFiles/SimPascal.dir/VIS/TypeVis.cpp.o: CMakeFiles/SimPascal.dir/flags.make
CMakeFiles/SimPascal.dir/VIS/TypeVis.cpp.o: VIS/TypeVis.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bcct/code/Test/SimPascal/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/SimPascal.dir/VIS/TypeVis.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SimPascal.dir/VIS/TypeVis.cpp.o -c /home/bcct/code/Test/SimPascal/VIS/TypeVis.cpp

CMakeFiles/SimPascal.dir/VIS/TypeVis.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SimPascal.dir/VIS/TypeVis.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bcct/code/Test/SimPascal/VIS/TypeVis.cpp > CMakeFiles/SimPascal.dir/VIS/TypeVis.cpp.i

CMakeFiles/SimPascal.dir/VIS/TypeVis.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SimPascal.dir/VIS/TypeVis.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bcct/code/Test/SimPascal/VIS/TypeVis.cpp -o CMakeFiles/SimPascal.dir/VIS/TypeVis.cpp.s

CMakeFiles/SimPascal.dir/token.cpp.o: CMakeFiles/SimPascal.dir/flags.make
CMakeFiles/SimPascal.dir/token.cpp.o: token.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bcct/code/Test/SimPascal/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/SimPascal.dir/token.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SimPascal.dir/token.cpp.o -c /home/bcct/code/Test/SimPascal/token.cpp

CMakeFiles/SimPascal.dir/token.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SimPascal.dir/token.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bcct/code/Test/SimPascal/token.cpp > CMakeFiles/SimPascal.dir/token.cpp.i

CMakeFiles/SimPascal.dir/token.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SimPascal.dir/token.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bcct/code/Test/SimPascal/token.cpp -o CMakeFiles/SimPascal.dir/token.cpp.s

CMakeFiles/SimPascal.dir/parser.cpp.o: CMakeFiles/SimPascal.dir/flags.make
CMakeFiles/SimPascal.dir/parser.cpp.o: parser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bcct/code/Test/SimPascal/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/SimPascal.dir/parser.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SimPascal.dir/parser.cpp.o -c /home/bcct/code/Test/SimPascal/parser.cpp

CMakeFiles/SimPascal.dir/parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SimPascal.dir/parser.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bcct/code/Test/SimPascal/parser.cpp > CMakeFiles/SimPascal.dir/parser.cpp.i

CMakeFiles/SimPascal.dir/parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SimPascal.dir/parser.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bcct/code/Test/SimPascal/parser.cpp -o CMakeFiles/SimPascal.dir/parser.cpp.s

# Object files for target SimPascal
SimPascal_OBJECTS = \
"CMakeFiles/SimPascal.dir/main.cpp.o" \
"CMakeFiles/SimPascal.dir/generator/CodeGenerator.cpp.o" \
"CMakeFiles/SimPascal.dir/generator/genConstType.cpp.o" \
"CMakeFiles/SimPascal.dir/generator/genExp.cpp.o" \
"CMakeFiles/SimPascal.dir/generator/genFunc.cpp.o" \
"CMakeFiles/SimPascal.dir/generator/genProgram.cpp.o" \
"CMakeFiles/SimPascal.dir/generator/genStmt.cpp.o" \
"CMakeFiles/SimPascal.dir/VIS/ConstVis.cpp.o" \
"CMakeFiles/SimPascal.dir/VIS/NodeVis.cpp.o" \
"CMakeFiles/SimPascal.dir/VIS/ProgramVis.cpp.o" \
"CMakeFiles/SimPascal.dir/VIS/StmtVis.cpp.o" \
"CMakeFiles/SimPascal.dir/VIS/TypeVis.cpp.o" \
"CMakeFiles/SimPascal.dir/token.cpp.o" \
"CMakeFiles/SimPascal.dir/parser.cpp.o"

# External object files for target SimPascal
SimPascal_EXTERNAL_OBJECTS =

SimPascal: CMakeFiles/SimPascal.dir/main.cpp.o
SimPascal: CMakeFiles/SimPascal.dir/generator/CodeGenerator.cpp.o
SimPascal: CMakeFiles/SimPascal.dir/generator/genConstType.cpp.o
SimPascal: CMakeFiles/SimPascal.dir/generator/genExp.cpp.o
SimPascal: CMakeFiles/SimPascal.dir/generator/genFunc.cpp.o
SimPascal: CMakeFiles/SimPascal.dir/generator/genProgram.cpp.o
SimPascal: CMakeFiles/SimPascal.dir/generator/genStmt.cpp.o
SimPascal: CMakeFiles/SimPascal.dir/VIS/ConstVis.cpp.o
SimPascal: CMakeFiles/SimPascal.dir/VIS/NodeVis.cpp.o
SimPascal: CMakeFiles/SimPascal.dir/VIS/ProgramVis.cpp.o
SimPascal: CMakeFiles/SimPascal.dir/VIS/StmtVis.cpp.o
SimPascal: CMakeFiles/SimPascal.dir/VIS/TypeVis.cpp.o
SimPascal: CMakeFiles/SimPascal.dir/token.cpp.o
SimPascal: CMakeFiles/SimPascal.dir/parser.cpp.o
SimPascal: CMakeFiles/SimPascal.dir/build.make
SimPascal: CMakeFiles/SimPascal.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bcct/code/Test/SimPascal/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Linking CXX executable SimPascal"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SimPascal.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SimPascal.dir/build: SimPascal

.PHONY : CMakeFiles/SimPascal.dir/build

CMakeFiles/SimPascal.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SimPascal.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SimPascal.dir/clean

CMakeFiles/SimPascal.dir/depend: token.cpp
CMakeFiles/SimPascal.dir/depend: parser.hpp
CMakeFiles/SimPascal.dir/depend: parser.cpp
	cd /home/bcct/code/Test/SimPascal && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bcct/code/Test/SimPascal /home/bcct/code/Test/SimPascal /home/bcct/code/Test/SimPascal /home/bcct/code/Test/SimPascal /home/bcct/code/Test/SimPascal/CMakeFiles/SimPascal.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SimPascal.dir/depend

