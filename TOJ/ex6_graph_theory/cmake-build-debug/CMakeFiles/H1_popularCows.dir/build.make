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
include CMakeFiles/H1_popularCows.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/H1_popularCows.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/H1_popularCows.dir/flags.make

CMakeFiles/H1_popularCows.dir/H1_popularCows.cpp.o: CMakeFiles/H1_popularCows.dir/flags.make
CMakeFiles/H1_popularCows.dir/H1_popularCows.cpp.o: ../H1_popularCows.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zyh/CLionProjects/ex6_graph_theory/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/H1_popularCows.dir/H1_popularCows.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/H1_popularCows.dir/H1_popularCows.cpp.o -c /Users/zyh/CLionProjects/ex6_graph_theory/H1_popularCows.cpp

CMakeFiles/H1_popularCows.dir/H1_popularCows.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/H1_popularCows.dir/H1_popularCows.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zyh/CLionProjects/ex6_graph_theory/H1_popularCows.cpp > CMakeFiles/H1_popularCows.dir/H1_popularCows.cpp.i

CMakeFiles/H1_popularCows.dir/H1_popularCows.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/H1_popularCows.dir/H1_popularCows.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zyh/CLionProjects/ex6_graph_theory/H1_popularCows.cpp -o CMakeFiles/H1_popularCows.dir/H1_popularCows.cpp.s

# Object files for target H1_popularCows
H1_popularCows_OBJECTS = \
"CMakeFiles/H1_popularCows.dir/H1_popularCows.cpp.o"

# External object files for target H1_popularCows
H1_popularCows_EXTERNAL_OBJECTS =

H1_popularCows: CMakeFiles/H1_popularCows.dir/H1_popularCows.cpp.o
H1_popularCows: CMakeFiles/H1_popularCows.dir/build.make
H1_popularCows: CMakeFiles/H1_popularCows.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/zyh/CLionProjects/ex6_graph_theory/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable H1_popularCows"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/H1_popularCows.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/H1_popularCows.dir/build: H1_popularCows
.PHONY : CMakeFiles/H1_popularCows.dir/build

CMakeFiles/H1_popularCows.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/H1_popularCows.dir/cmake_clean.cmake
.PHONY : CMakeFiles/H1_popularCows.dir/clean

CMakeFiles/H1_popularCows.dir/depend:
	cd /Users/zyh/CLionProjects/ex6_graph_theory/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/zyh/CLionProjects/ex6_graph_theory /Users/zyh/CLionProjects/ex6_graph_theory /Users/zyh/CLionProjects/ex6_graph_theory/cmake-build-debug /Users/zyh/CLionProjects/ex6_graph_theory/cmake-build-debug /Users/zyh/CLionProjects/ex6_graph_theory/cmake-build-debug/CMakeFiles/H1_popularCows.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/H1_popularCows.dir/depend

