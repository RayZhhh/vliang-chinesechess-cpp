# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.21

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Derek\Desktop\vliang-chinesechess-cpp-feature-rl

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Derek\Desktop\vliang-chinesechess-cpp-feature-rl\cmake-build-release

# Include any dependencies generated for this target.
include CMakeFiles/yoll_chinese_chess.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/yoll_chinese_chess.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/yoll_chinese_chess.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/yoll_chinese_chess.dir/flags.make

CMakeFiles/yoll_chinese_chess.dir/main.cpp.obj: CMakeFiles/yoll_chinese_chess.dir/flags.make
CMakeFiles/yoll_chinese_chess.dir/main.cpp.obj: ../main.cpp
CMakeFiles/yoll_chinese_chess.dir/main.cpp.obj: CMakeFiles/yoll_chinese_chess.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Derek\Desktop\vliang-chinesechess-cpp-feature-rl\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/yoll_chinese_chess.dir/main.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/yoll_chinese_chess.dir/main.cpp.obj -MF CMakeFiles\yoll_chinese_chess.dir\main.cpp.obj.d -o CMakeFiles\yoll_chinese_chess.dir\main.cpp.obj -c C:\Users\Derek\Desktop\vliang-chinesechess-cpp-feature-rl\main.cpp

CMakeFiles/yoll_chinese_chess.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/yoll_chinese_chess.dir/main.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Derek\Desktop\vliang-chinesechess-cpp-feature-rl\main.cpp > CMakeFiles\yoll_chinese_chess.dir\main.cpp.i

CMakeFiles/yoll_chinese_chess.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/yoll_chinese_chess.dir/main.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Derek\Desktop\vliang-chinesechess-cpp-feature-rl\main.cpp -o CMakeFiles\yoll_chinese_chess.dir\main.cpp.s

CMakeFiles/yoll_chinese_chess.dir/cpp/source/chessboard.cpp.obj: CMakeFiles/yoll_chinese_chess.dir/flags.make
CMakeFiles/yoll_chinese_chess.dir/cpp/source/chessboard.cpp.obj: ../cpp/source/chessboard.cpp
CMakeFiles/yoll_chinese_chess.dir/cpp/source/chessboard.cpp.obj: CMakeFiles/yoll_chinese_chess.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Derek\Desktop\vliang-chinesechess-cpp-feature-rl\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/yoll_chinese_chess.dir/cpp/source/chessboard.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/yoll_chinese_chess.dir/cpp/source/chessboard.cpp.obj -MF CMakeFiles\yoll_chinese_chess.dir\cpp\source\chessboard.cpp.obj.d -o CMakeFiles\yoll_chinese_chess.dir\cpp\source\chessboard.cpp.obj -c C:\Users\Derek\Desktop\vliang-chinesechess-cpp-feature-rl\cpp\source\chessboard.cpp

CMakeFiles/yoll_chinese_chess.dir/cpp/source/chessboard.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/yoll_chinese_chess.dir/cpp/source/chessboard.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Derek\Desktop\vliang-chinesechess-cpp-feature-rl\cpp\source\chessboard.cpp > CMakeFiles\yoll_chinese_chess.dir\cpp\source\chessboard.cpp.i

CMakeFiles/yoll_chinese_chess.dir/cpp/source/chessboard.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/yoll_chinese_chess.dir/cpp/source/chessboard.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Derek\Desktop\vliang-chinesechess-cpp-feature-rl\cpp\source\chessboard.cpp -o CMakeFiles\yoll_chinese_chess.dir\cpp\source\chessboard.cpp.s

CMakeFiles/yoll_chinese_chess.dir/cpp/source/tree_search.cpp.obj: CMakeFiles/yoll_chinese_chess.dir/flags.make
CMakeFiles/yoll_chinese_chess.dir/cpp/source/tree_search.cpp.obj: ../cpp/source/tree_search.cpp
CMakeFiles/yoll_chinese_chess.dir/cpp/source/tree_search.cpp.obj: CMakeFiles/yoll_chinese_chess.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Derek\Desktop\vliang-chinesechess-cpp-feature-rl\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/yoll_chinese_chess.dir/cpp/source/tree_search.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/yoll_chinese_chess.dir/cpp/source/tree_search.cpp.obj -MF CMakeFiles\yoll_chinese_chess.dir\cpp\source\tree_search.cpp.obj.d -o CMakeFiles\yoll_chinese_chess.dir\cpp\source\tree_search.cpp.obj -c C:\Users\Derek\Desktop\vliang-chinesechess-cpp-feature-rl\cpp\source\tree_search.cpp

CMakeFiles/yoll_chinese_chess.dir/cpp/source/tree_search.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/yoll_chinese_chess.dir/cpp/source/tree_search.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Derek\Desktop\vliang-chinesechess-cpp-feature-rl\cpp\source\tree_search.cpp > CMakeFiles\yoll_chinese_chess.dir\cpp\source\tree_search.cpp.i

CMakeFiles/yoll_chinese_chess.dir/cpp/source/tree_search.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/yoll_chinese_chess.dir/cpp/source/tree_search.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Derek\Desktop\vliang-chinesechess-cpp-feature-rl\cpp\source\tree_search.cpp -o CMakeFiles\yoll_chinese_chess.dir\cpp\source\tree_search.cpp.s

CMakeFiles/yoll_chinese_chess.dir/cpp/source/alpha_beta.cpp.obj: CMakeFiles/yoll_chinese_chess.dir/flags.make
CMakeFiles/yoll_chinese_chess.dir/cpp/source/alpha_beta.cpp.obj: ../cpp/source/alpha_beta.cpp
CMakeFiles/yoll_chinese_chess.dir/cpp/source/alpha_beta.cpp.obj: CMakeFiles/yoll_chinese_chess.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Derek\Desktop\vliang-chinesechess-cpp-feature-rl\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/yoll_chinese_chess.dir/cpp/source/alpha_beta.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/yoll_chinese_chess.dir/cpp/source/alpha_beta.cpp.obj -MF CMakeFiles\yoll_chinese_chess.dir\cpp\source\alpha_beta.cpp.obj.d -o CMakeFiles\yoll_chinese_chess.dir\cpp\source\alpha_beta.cpp.obj -c C:\Users\Derek\Desktop\vliang-chinesechess-cpp-feature-rl\cpp\source\alpha_beta.cpp

CMakeFiles/yoll_chinese_chess.dir/cpp/source/alpha_beta.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/yoll_chinese_chess.dir/cpp/source/alpha_beta.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Derek\Desktop\vliang-chinesechess-cpp-feature-rl\cpp\source\alpha_beta.cpp > CMakeFiles\yoll_chinese_chess.dir\cpp\source\alpha_beta.cpp.i

CMakeFiles/yoll_chinese_chess.dir/cpp/source/alpha_beta.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/yoll_chinese_chess.dir/cpp/source/alpha_beta.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Derek\Desktop\vliang-chinesechess-cpp-feature-rl\cpp\source\alpha_beta.cpp -o CMakeFiles\yoll_chinese_chess.dir\cpp\source\alpha_beta.cpp.s

CMakeFiles/yoll_chinese_chess.dir/cpp/source/quiescence.cpp.obj: CMakeFiles/yoll_chinese_chess.dir/flags.make
CMakeFiles/yoll_chinese_chess.dir/cpp/source/quiescence.cpp.obj: ../cpp/source/quiescence.cpp
CMakeFiles/yoll_chinese_chess.dir/cpp/source/quiescence.cpp.obj: CMakeFiles/yoll_chinese_chess.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Derek\Desktop\vliang-chinesechess-cpp-feature-rl\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/yoll_chinese_chess.dir/cpp/source/quiescence.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/yoll_chinese_chess.dir/cpp/source/quiescence.cpp.obj -MF CMakeFiles\yoll_chinese_chess.dir\cpp\source\quiescence.cpp.obj.d -o CMakeFiles\yoll_chinese_chess.dir\cpp\source\quiescence.cpp.obj -c C:\Users\Derek\Desktop\vliang-chinesechess-cpp-feature-rl\cpp\source\quiescence.cpp

CMakeFiles/yoll_chinese_chess.dir/cpp/source/quiescence.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/yoll_chinese_chess.dir/cpp/source/quiescence.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Derek\Desktop\vliang-chinesechess-cpp-feature-rl\cpp\source\quiescence.cpp > CMakeFiles\yoll_chinese_chess.dir\cpp\source\quiescence.cpp.i

CMakeFiles/yoll_chinese_chess.dir/cpp/source/quiescence.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/yoll_chinese_chess.dir/cpp/source/quiescence.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Derek\Desktop\vliang-chinesechess-cpp-feature-rl\cpp\source\quiescence.cpp -o CMakeFiles\yoll_chinese_chess.dir\cpp\source\quiescence.cpp.s

CMakeFiles/yoll_chinese_chess.dir/cpp/source/evaluator.cpp.obj: CMakeFiles/yoll_chinese_chess.dir/flags.make
CMakeFiles/yoll_chinese_chess.dir/cpp/source/evaluator.cpp.obj: ../cpp/source/evaluator.cpp
CMakeFiles/yoll_chinese_chess.dir/cpp/source/evaluator.cpp.obj: CMakeFiles/yoll_chinese_chess.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Derek\Desktop\vliang-chinesechess-cpp-feature-rl\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/yoll_chinese_chess.dir/cpp/source/evaluator.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/yoll_chinese_chess.dir/cpp/source/evaluator.cpp.obj -MF CMakeFiles\yoll_chinese_chess.dir\cpp\source\evaluator.cpp.obj.d -o CMakeFiles\yoll_chinese_chess.dir\cpp\source\evaluator.cpp.obj -c C:\Users\Derek\Desktop\vliang-chinesechess-cpp-feature-rl\cpp\source\evaluator.cpp

CMakeFiles/yoll_chinese_chess.dir/cpp/source/evaluator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/yoll_chinese_chess.dir/cpp/source/evaluator.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Derek\Desktop\vliang-chinesechess-cpp-feature-rl\cpp\source\evaluator.cpp > CMakeFiles\yoll_chinese_chess.dir\cpp\source\evaluator.cpp.i

CMakeFiles/yoll_chinese_chess.dir/cpp/source/evaluator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/yoll_chinese_chess.dir/cpp/source/evaluator.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Derek\Desktop\vliang-chinesechess-cpp-feature-rl\cpp\source\evaluator.cpp -o CMakeFiles\yoll_chinese_chess.dir\cpp\source\evaluator.cpp.s

CMakeFiles/yoll_chinese_chess.dir/py_interface.cpp.obj: CMakeFiles/yoll_chinese_chess.dir/flags.make
CMakeFiles/yoll_chinese_chess.dir/py_interface.cpp.obj: ../py_interface.cpp
CMakeFiles/yoll_chinese_chess.dir/py_interface.cpp.obj: CMakeFiles/yoll_chinese_chess.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Derek\Desktop\vliang-chinesechess-cpp-feature-rl\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/yoll_chinese_chess.dir/py_interface.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/yoll_chinese_chess.dir/py_interface.cpp.obj -MF CMakeFiles\yoll_chinese_chess.dir\py_interface.cpp.obj.d -o CMakeFiles\yoll_chinese_chess.dir\py_interface.cpp.obj -c C:\Users\Derek\Desktop\vliang-chinesechess-cpp-feature-rl\py_interface.cpp

CMakeFiles/yoll_chinese_chess.dir/py_interface.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/yoll_chinese_chess.dir/py_interface.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Derek\Desktop\vliang-chinesechess-cpp-feature-rl\py_interface.cpp > CMakeFiles\yoll_chinese_chess.dir\py_interface.cpp.i

CMakeFiles/yoll_chinese_chess.dir/py_interface.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/yoll_chinese_chess.dir/py_interface.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Derek\Desktop\vliang-chinesechess-cpp-feature-rl\py_interface.cpp -o CMakeFiles\yoll_chinese_chess.dir\py_interface.cpp.s

CMakeFiles/yoll_chinese_chess.dir/cpp/source/mtdf.cpp.obj: CMakeFiles/yoll_chinese_chess.dir/flags.make
CMakeFiles/yoll_chinese_chess.dir/cpp/source/mtdf.cpp.obj: ../cpp/source/mtdf.cpp
CMakeFiles/yoll_chinese_chess.dir/cpp/source/mtdf.cpp.obj: CMakeFiles/yoll_chinese_chess.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Derek\Desktop\vliang-chinesechess-cpp-feature-rl\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/yoll_chinese_chess.dir/cpp/source/mtdf.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/yoll_chinese_chess.dir/cpp/source/mtdf.cpp.obj -MF CMakeFiles\yoll_chinese_chess.dir\cpp\source\mtdf.cpp.obj.d -o CMakeFiles\yoll_chinese_chess.dir\cpp\source\mtdf.cpp.obj -c C:\Users\Derek\Desktop\vliang-chinesechess-cpp-feature-rl\cpp\source\mtdf.cpp

CMakeFiles/yoll_chinese_chess.dir/cpp/source/mtdf.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/yoll_chinese_chess.dir/cpp/source/mtdf.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Derek\Desktop\vliang-chinesechess-cpp-feature-rl\cpp\source\mtdf.cpp > CMakeFiles\yoll_chinese_chess.dir\cpp\source\mtdf.cpp.i

CMakeFiles/yoll_chinese_chess.dir/cpp/source/mtdf.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/yoll_chinese_chess.dir/cpp/source/mtdf.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Derek\Desktop\vliang-chinesechess-cpp-feature-rl\cpp\source\mtdf.cpp -o CMakeFiles\yoll_chinese_chess.dir\cpp\source\mtdf.cpp.s

CMakeFiles/yoll_chinese_chess.dir/test/evaluator_so.cpp.obj: CMakeFiles/yoll_chinese_chess.dir/flags.make
CMakeFiles/yoll_chinese_chess.dir/test/evaluator_so.cpp.obj: ../test/evaluator_so.cpp
CMakeFiles/yoll_chinese_chess.dir/test/evaluator_so.cpp.obj: CMakeFiles/yoll_chinese_chess.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Derek\Desktop\vliang-chinesechess-cpp-feature-rl\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/yoll_chinese_chess.dir/test/evaluator_so.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/yoll_chinese_chess.dir/test/evaluator_so.cpp.obj -MF CMakeFiles\yoll_chinese_chess.dir\test\evaluator_so.cpp.obj.d -o CMakeFiles\yoll_chinese_chess.dir\test\evaluator_so.cpp.obj -c C:\Users\Derek\Desktop\vliang-chinesechess-cpp-feature-rl\test\evaluator_so.cpp

CMakeFiles/yoll_chinese_chess.dir/test/evaluator_so.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/yoll_chinese_chess.dir/test/evaluator_so.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Derek\Desktop\vliang-chinesechess-cpp-feature-rl\test\evaluator_so.cpp > CMakeFiles\yoll_chinese_chess.dir\test\evaluator_so.cpp.i

CMakeFiles/yoll_chinese_chess.dir/test/evaluator_so.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/yoll_chinese_chess.dir/test/evaluator_so.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Derek\Desktop\vliang-chinesechess-cpp-feature-rl\test\evaluator_so.cpp -o CMakeFiles\yoll_chinese_chess.dir\test\evaluator_so.cpp.s

CMakeFiles/yoll_chinese_chess.dir/gen_datasets.cpp.obj: CMakeFiles/yoll_chinese_chess.dir/flags.make
CMakeFiles/yoll_chinese_chess.dir/gen_datasets.cpp.obj: ../gen_datasets.cpp
CMakeFiles/yoll_chinese_chess.dir/gen_datasets.cpp.obj: CMakeFiles/yoll_chinese_chess.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Derek\Desktop\vliang-chinesechess-cpp-feature-rl\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/yoll_chinese_chess.dir/gen_datasets.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/yoll_chinese_chess.dir/gen_datasets.cpp.obj -MF CMakeFiles\yoll_chinese_chess.dir\gen_datasets.cpp.obj.d -o CMakeFiles\yoll_chinese_chess.dir\gen_datasets.cpp.obj -c C:\Users\Derek\Desktop\vliang-chinesechess-cpp-feature-rl\gen_datasets.cpp

CMakeFiles/yoll_chinese_chess.dir/gen_datasets.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/yoll_chinese_chess.dir/gen_datasets.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Derek\Desktop\vliang-chinesechess-cpp-feature-rl\gen_datasets.cpp > CMakeFiles\yoll_chinese_chess.dir\gen_datasets.cpp.i

CMakeFiles/yoll_chinese_chess.dir/gen_datasets.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/yoll_chinese_chess.dir/gen_datasets.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Derek\Desktop\vliang-chinesechess-cpp-feature-rl\gen_datasets.cpp -o CMakeFiles\yoll_chinese_chess.dir\gen_datasets.cpp.s

# Object files for target yoll_chinese_chess
yoll_chinese_chess_OBJECTS = \
"CMakeFiles/yoll_chinese_chess.dir/main.cpp.obj" \
"CMakeFiles/yoll_chinese_chess.dir/cpp/source/chessboard.cpp.obj" \
"CMakeFiles/yoll_chinese_chess.dir/cpp/source/tree_search.cpp.obj" \
"CMakeFiles/yoll_chinese_chess.dir/cpp/source/alpha_beta.cpp.obj" \
"CMakeFiles/yoll_chinese_chess.dir/cpp/source/quiescence.cpp.obj" \
"CMakeFiles/yoll_chinese_chess.dir/cpp/source/evaluator.cpp.obj" \
"CMakeFiles/yoll_chinese_chess.dir/py_interface.cpp.obj" \
"CMakeFiles/yoll_chinese_chess.dir/cpp/source/mtdf.cpp.obj" \
"CMakeFiles/yoll_chinese_chess.dir/test/evaluator_so.cpp.obj" \
"CMakeFiles/yoll_chinese_chess.dir/gen_datasets.cpp.obj"

# External object files for target yoll_chinese_chess
yoll_chinese_chess_EXTERNAL_OBJECTS =

yoll_chinese_chess.exe: CMakeFiles/yoll_chinese_chess.dir/main.cpp.obj
yoll_chinese_chess.exe: CMakeFiles/yoll_chinese_chess.dir/cpp/source/chessboard.cpp.obj
yoll_chinese_chess.exe: CMakeFiles/yoll_chinese_chess.dir/cpp/source/tree_search.cpp.obj
yoll_chinese_chess.exe: CMakeFiles/yoll_chinese_chess.dir/cpp/source/alpha_beta.cpp.obj
yoll_chinese_chess.exe: CMakeFiles/yoll_chinese_chess.dir/cpp/source/quiescence.cpp.obj
yoll_chinese_chess.exe: CMakeFiles/yoll_chinese_chess.dir/cpp/source/evaluator.cpp.obj
yoll_chinese_chess.exe: CMakeFiles/yoll_chinese_chess.dir/py_interface.cpp.obj
yoll_chinese_chess.exe: CMakeFiles/yoll_chinese_chess.dir/cpp/source/mtdf.cpp.obj
yoll_chinese_chess.exe: CMakeFiles/yoll_chinese_chess.dir/test/evaluator_so.cpp.obj
yoll_chinese_chess.exe: CMakeFiles/yoll_chinese_chess.dir/gen_datasets.cpp.obj
yoll_chinese_chess.exe: CMakeFiles/yoll_chinese_chess.dir/build.make
yoll_chinese_chess.exe: CMakeFiles/yoll_chinese_chess.dir/linklibs.rsp
yoll_chinese_chess.exe: CMakeFiles/yoll_chinese_chess.dir/objects1.rsp
yoll_chinese_chess.exe: CMakeFiles/yoll_chinese_chess.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Derek\Desktop\vliang-chinesechess-cpp-feature-rl\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX executable yoll_chinese_chess.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\yoll_chinese_chess.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/yoll_chinese_chess.dir/build: yoll_chinese_chess.exe
.PHONY : CMakeFiles/yoll_chinese_chess.dir/build

CMakeFiles/yoll_chinese_chess.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\yoll_chinese_chess.dir\cmake_clean.cmake
.PHONY : CMakeFiles/yoll_chinese_chess.dir/clean

CMakeFiles/yoll_chinese_chess.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Derek\Desktop\vliang-chinesechess-cpp-feature-rl C:\Users\Derek\Desktop\vliang-chinesechess-cpp-feature-rl C:\Users\Derek\Desktop\vliang-chinesechess-cpp-feature-rl\cmake-build-release C:\Users\Derek\Desktop\vliang-chinesechess-cpp-feature-rl\cmake-build-release C:\Users\Derek\Desktop\vliang-chinesechess-cpp-feature-rl\cmake-build-release\CMakeFiles\yoll_chinese_chess.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/yoll_chinese_chess.dir/depend

