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
CMAKE_SOURCE_DIR = /Users/zyh/CLionProjects/ex6_graph_theory

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/zyh/CLionProjects/ex6_graph_theory/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/testVector.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/testVector.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/testVector.dir/flags.make

CMakeFiles/testVector.dir/testVector.cpp.o: CMakeFiles/testVector.dir/flags.make
CMakeFiles/testVector.dir/testVector.cpp.o: ../testVector.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zyh/CLionProjects/ex6_graph_theory/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/testVector.dir/testVector.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/testVector.dir/testVector.cpp.o -c /Users/zyh/CLionProjects/ex6_graph_theory/testVector.cpp

CMakeFiles/testVector.dir/testVector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testVector.dir/testVector.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zyh/CLionProjects/ex6_graph_theory/testVector.cpp > CMakeFiles/testVector.dir/testVector.cpp.i

CMakeFiles/testVector.dir/testVector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testVector.dir/testVector.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zyh/CLionProjects/ex6_graph_theory/testVector.cpp -o CMakeFiles/testVector.dir/testVector.cpp.s

# Object files for target testVector
testVector_OBJECTS = \
"CMakeFiles/testVector.dir/testVector.cpp.o"

# External object files for target testVector
testVector_EXTERNAL_OBJECTS =

testVector: CMakeFiles/testVector.dir/testVector.cpp.o
testVector: CMakeFiles/testVector.dir/build.make
testVector: CMakeFiles/testVector.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/zyh/CLionProjects/ex6_graph_theory/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable testVector"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testVector.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/testVector.dir/build: testVector
.PHONY : CMakeFiles/testVector.dir/build

CMakeFiles/testVector.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/testVector.dir/cmake_clean.cmake
.PHONY : CMakeFiles/testVector.dir/clean

CMakeFiles/testVector.dir/depend:
	cd /Users/zyh/CLionProjects/ex6_graph_theory/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/zyh/CLionProjects/ex6_graph_theory /Users/zyh/CLionProjects/ex6_graph_theory /Users/zyh/CLionProjects/ex6_graph_theory/cmake-build-debug /Users/zyh/CLionProjects/ex6_graph_theory/cmake-build-debug /Users/zyh/CLionProjects/ex6_graph_theory/cmake-build-debug/CMakeFiles/testVector.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/testVector.dir/depend

