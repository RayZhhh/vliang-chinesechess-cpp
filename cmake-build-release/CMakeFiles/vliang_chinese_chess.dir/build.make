# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/zhangrui/Developer/vliang-chinesechess-cpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/zhangrui/Developer/vliang-chinesechess-cpp/cmake-build-release

# Include any dependencies generated for this target.
include CMakeFiles/vliang_chinese_chess.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/vliang_chinese_chess.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/vliang_chinese_chess.dir/flags.make

CMakeFiles/vliang_chinese_chess.dir/main.cpp.o: CMakeFiles/vliang_chinese_chess.dir/flags.make
CMakeFiles/vliang_chinese_chess.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zhangrui/Developer/vliang-chinesechess-cpp/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/vliang_chinese_chess.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/vliang_chinese_chess.dir/main.cpp.o -c /Users/zhangrui/Developer/vliang-chinesechess-cpp/main.cpp

CMakeFiles/vliang_chinese_chess.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vliang_chinese_chess.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zhangrui/Developer/vliang-chinesechess-cpp/main.cpp > CMakeFiles/vliang_chinese_chess.dir/main.cpp.i

CMakeFiles/vliang_chinese_chess.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vliang_chinese_chess.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zhangrui/Developer/vliang-chinesechess-cpp/main.cpp -o CMakeFiles/vliang_chinese_chess.dir/main.cpp.s

CMakeFiles/vliang_chinese_chess.dir/cpp/sourse/chessboard.cpp.o: CMakeFiles/vliang_chinese_chess.dir/flags.make
CMakeFiles/vliang_chinese_chess.dir/cpp/sourse/chessboard.cpp.o: ../cpp/sourse/chessboard.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zhangrui/Developer/vliang-chinesechess-cpp/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/vliang_chinese_chess.dir/cpp/sourse/chessboard.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/vliang_chinese_chess.dir/cpp/sourse/chessboard.cpp.o -c /Users/zhangrui/Developer/vliang-chinesechess-cpp/cpp/sourse/chessboard.cpp

CMakeFiles/vliang_chinese_chess.dir/cpp/sourse/chessboard.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vliang_chinese_chess.dir/cpp/sourse/chessboard.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zhangrui/Developer/vliang-chinesechess-cpp/cpp/sourse/chessboard.cpp > CMakeFiles/vliang_chinese_chess.dir/cpp/sourse/chessboard.cpp.i

CMakeFiles/vliang_chinese_chess.dir/cpp/sourse/chessboard.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vliang_chinese_chess.dir/cpp/sourse/chessboard.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zhangrui/Developer/vliang-chinesechess-cpp/cpp/sourse/chessboard.cpp -o CMakeFiles/vliang_chinese_chess.dir/cpp/sourse/chessboard.cpp.s

CMakeFiles/vliang_chinese_chess.dir/cpp/sourse/tree_search.cpp.o: CMakeFiles/vliang_chinese_chess.dir/flags.make
CMakeFiles/vliang_chinese_chess.dir/cpp/sourse/tree_search.cpp.o: ../cpp/sourse/tree_search.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zhangrui/Developer/vliang-chinesechess-cpp/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/vliang_chinese_chess.dir/cpp/sourse/tree_search.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/vliang_chinese_chess.dir/cpp/sourse/tree_search.cpp.o -c /Users/zhangrui/Developer/vliang-chinesechess-cpp/cpp/sourse/tree_search.cpp

CMakeFiles/vliang_chinese_chess.dir/cpp/sourse/tree_search.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vliang_chinese_chess.dir/cpp/sourse/tree_search.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zhangrui/Developer/vliang-chinesechess-cpp/cpp/sourse/tree_search.cpp > CMakeFiles/vliang_chinese_chess.dir/cpp/sourse/tree_search.cpp.i

CMakeFiles/vliang_chinese_chess.dir/cpp/sourse/tree_search.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vliang_chinese_chess.dir/cpp/sourse/tree_search.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zhangrui/Developer/vliang-chinesechess-cpp/cpp/sourse/tree_search.cpp -o CMakeFiles/vliang_chinese_chess.dir/cpp/sourse/tree_search.cpp.s

CMakeFiles/vliang_chinese_chess.dir/cpp/sourse/alpha_beta.cpp.o: CMakeFiles/vliang_chinese_chess.dir/flags.make
CMakeFiles/vliang_chinese_chess.dir/cpp/sourse/alpha_beta.cpp.o: ../cpp/sourse/alpha_beta.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zhangrui/Developer/vliang-chinesechess-cpp/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/vliang_chinese_chess.dir/cpp/sourse/alpha_beta.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/vliang_chinese_chess.dir/cpp/sourse/alpha_beta.cpp.o -c /Users/zhangrui/Developer/vliang-chinesechess-cpp/cpp/sourse/alpha_beta.cpp

CMakeFiles/vliang_chinese_chess.dir/cpp/sourse/alpha_beta.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vliang_chinese_chess.dir/cpp/sourse/alpha_beta.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zhangrui/Developer/vliang-chinesechess-cpp/cpp/sourse/alpha_beta.cpp > CMakeFiles/vliang_chinese_chess.dir/cpp/sourse/alpha_beta.cpp.i

CMakeFiles/vliang_chinese_chess.dir/cpp/sourse/alpha_beta.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vliang_chinese_chess.dir/cpp/sourse/alpha_beta.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zhangrui/Developer/vliang-chinesechess-cpp/cpp/sourse/alpha_beta.cpp -o CMakeFiles/vliang_chinese_chess.dir/cpp/sourse/alpha_beta.cpp.s

CMakeFiles/vliang_chinese_chess.dir/cpp/sourse/quiescence.cpp.o: CMakeFiles/vliang_chinese_chess.dir/flags.make
CMakeFiles/vliang_chinese_chess.dir/cpp/sourse/quiescence.cpp.o: ../cpp/sourse/quiescence.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zhangrui/Developer/vliang-chinesechess-cpp/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/vliang_chinese_chess.dir/cpp/sourse/quiescence.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/vliang_chinese_chess.dir/cpp/sourse/quiescence.cpp.o -c /Users/zhangrui/Developer/vliang-chinesechess-cpp/cpp/sourse/quiescence.cpp

CMakeFiles/vliang_chinese_chess.dir/cpp/sourse/quiescence.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vliang_chinese_chess.dir/cpp/sourse/quiescence.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zhangrui/Developer/vliang-chinesechess-cpp/cpp/sourse/quiescence.cpp > CMakeFiles/vliang_chinese_chess.dir/cpp/sourse/quiescence.cpp.i

CMakeFiles/vliang_chinese_chess.dir/cpp/sourse/quiescence.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vliang_chinese_chess.dir/cpp/sourse/quiescence.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zhangrui/Developer/vliang-chinesechess-cpp/cpp/sourse/quiescence.cpp -o CMakeFiles/vliang_chinese_chess.dir/cpp/sourse/quiescence.cpp.s

CMakeFiles/vliang_chinese_chess.dir/cpp/sourse/multi_thread_evaluator.cpp.o: CMakeFiles/vliang_chinese_chess.dir/flags.make
CMakeFiles/vliang_chinese_chess.dir/cpp/sourse/multi_thread_evaluator.cpp.o: ../cpp/sourse/multi_thread_evaluator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zhangrui/Developer/vliang-chinesechess-cpp/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/vliang_chinese_chess.dir/cpp/sourse/multi_thread_evaluator.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/vliang_chinese_chess.dir/cpp/sourse/multi_thread_evaluator.cpp.o -c /Users/zhangrui/Developer/vliang-chinesechess-cpp/cpp/sourse/multi_thread_evaluator.cpp

CMakeFiles/vliang_chinese_chess.dir/cpp/sourse/multi_thread_evaluator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vliang_chinese_chess.dir/cpp/sourse/multi_thread_evaluator.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zhangrui/Developer/vliang-chinesechess-cpp/cpp/sourse/multi_thread_evaluator.cpp > CMakeFiles/vliang_chinese_chess.dir/cpp/sourse/multi_thread_evaluator.cpp.i

CMakeFiles/vliang_chinese_chess.dir/cpp/sourse/multi_thread_evaluator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vliang_chinese_chess.dir/cpp/sourse/multi_thread_evaluator.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zhangrui/Developer/vliang-chinesechess-cpp/cpp/sourse/multi_thread_evaluator.cpp -o CMakeFiles/vliang_chinese_chess.dir/cpp/sourse/multi_thread_evaluator.cpp.s

CMakeFiles/vliang_chinese_chess.dir/ai_self_match.cpp.o: CMakeFiles/vliang_chinese_chess.dir/flags.make
CMakeFiles/vliang_chinese_chess.dir/ai_self_match.cpp.o: ../ai_self_match.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zhangrui/Developer/vliang-chinesechess-cpp/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/vliang_chinese_chess.dir/ai_self_match.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/vliang_chinese_chess.dir/ai_self_match.cpp.o -c /Users/zhangrui/Developer/vliang-chinesechess-cpp/ai_self_match.cpp

CMakeFiles/vliang_chinese_chess.dir/ai_self_match.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vliang_chinese_chess.dir/ai_self_match.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zhangrui/Developer/vliang-chinesechess-cpp/ai_self_match.cpp > CMakeFiles/vliang_chinese_chess.dir/ai_self_match.cpp.i

CMakeFiles/vliang_chinese_chess.dir/ai_self_match.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vliang_chinese_chess.dir/ai_self_match.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zhangrui/Developer/vliang-chinesechess-cpp/ai_self_match.cpp -o CMakeFiles/vliang_chinese_chess.dir/ai_self_match.cpp.s

# Object files for target vliang_chinese_chess
vliang_chinese_chess_OBJECTS = \
"CMakeFiles/vliang_chinese_chess.dir/main.cpp.o" \
"CMakeFiles/vliang_chinese_chess.dir/cpp/sourse/chessboard.cpp.o" \
"CMakeFiles/vliang_chinese_chess.dir/cpp/sourse/tree_search.cpp.o" \
"CMakeFiles/vliang_chinese_chess.dir/cpp/sourse/alpha_beta.cpp.o" \
"CMakeFiles/vliang_chinese_chess.dir/cpp/sourse/quiescence.cpp.o" \
"CMakeFiles/vliang_chinese_chess.dir/cpp/sourse/multi_thread_evaluator.cpp.o" \
"CMakeFiles/vliang_chinese_chess.dir/ai_self_match.cpp.o"

# External object files for target vliang_chinese_chess
vliang_chinese_chess_EXTERNAL_OBJECTS =

vliang_chinese_chess: CMakeFiles/vliang_chinese_chess.dir/main.cpp.o
vliang_chinese_chess: CMakeFiles/vliang_chinese_chess.dir/cpp/sourse/chessboard.cpp.o
vliang_chinese_chess: CMakeFiles/vliang_chinese_chess.dir/cpp/sourse/tree_search.cpp.o
vliang_chinese_chess: CMakeFiles/vliang_chinese_chess.dir/cpp/sourse/alpha_beta.cpp.o
vliang_chinese_chess: CMakeFiles/vliang_chinese_chess.dir/cpp/sourse/quiescence.cpp.o
vliang_chinese_chess: CMakeFiles/vliang_chinese_chess.dir/cpp/sourse/multi_thread_evaluator.cpp.o
vliang_chinese_chess: CMakeFiles/vliang_chinese_chess.dir/ai_self_match.cpp.o
vliang_chinese_chess: CMakeFiles/vliang_chinese_chess.dir/build.make
vliang_chinese_chess: CMakeFiles/vliang_chinese_chess.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/zhangrui/Developer/vliang-chinesechess-cpp/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable vliang_chinese_chess"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/vliang_chinese_chess.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/vliang_chinese_chess.dir/build: vliang_chinese_chess
.PHONY : CMakeFiles/vliang_chinese_chess.dir/build

CMakeFiles/vliang_chinese_chess.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/vliang_chinese_chess.dir/cmake_clean.cmake
.PHONY : CMakeFiles/vliang_chinese_chess.dir/clean

CMakeFiles/vliang_chinese_chess.dir/depend:
	cd /Users/zhangrui/Developer/vliang-chinesechess-cpp/cmake-build-release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/zhangrui/Developer/vliang-chinesechess-cpp /Users/zhangrui/Developer/vliang-chinesechess-cpp /Users/zhangrui/Developer/vliang-chinesechess-cpp/cmake-build-release /Users/zhangrui/Developer/vliang-chinesechess-cpp/cmake-build-release /Users/zhangrui/Developer/vliang-chinesechess-cpp/cmake-build-release/CMakeFiles/vliang_chinese_chess.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/vliang_chinese_chess.dir/depend

