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
CMAKE_SOURCE_DIR = /Users/zyh/CLionProjects/ex3_sort

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/zyh/CLionProjects/ex3_sort/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/h4_queue_sort.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/h4_queue_sort.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/h4_queue_sort.dir/flags.make

CMakeFiles/h4_queue_sort.dir/h4_queue_sort.cpp.o: CMakeFiles/h4_queue_sort.dir/flags.make
CMakeFiles/h4_queue_sort.dir/h4_queue_sort.cpp.o: ../h4_queue_sort.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zyh/CLionProjects/ex3_sort/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/h4_queue_sort.dir/h4_queue_sort.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/h4_queue_sort.dir/h4_queue_sort.cpp.o -c /Users/zyh/CLionProjects/ex3_sort/h4_queue_sort.cpp

CMakeFiles/h4_queue_sort.dir/h4_queue_sort.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/h4_queue_sort.dir/h4_queue_sort.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zyh/CLionProjects/ex3_sort/h4_queue_sort.cpp > CMakeFiles/h4_queue_sort.dir/h4_queue_sort.cpp.i

CMakeFiles/h4_queue_sort.dir/h4_queue_sort.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/h4_queue_sort.dir/h4_queue_sort.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zyh/CLionProjects/ex3_sort/h4_queue_sort.cpp -o CMakeFiles/h4_queue_sort.dir/h4_queue_sort.cpp.s

# Object files for target h4_queue_sort
h4_queue_sort_OBJECTS = \
"CMakeFiles/h4_queue_sort.dir/h4_queue_sort.cpp.o"

# External object files for target h4_queue_sort
h4_queue_sort_EXTERNAL_OBJECTS =

h4_queue_sort: CMakeFiles/h4_queue_sort.dir/h4_queue_sort.cpp.o
h4_queue_sort: CMakeFiles/h4_queue_sort.dir/build.make
h4_queue_sort: CMakeFiles/h4_queue_sort.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/zyh/CLionProjects/ex3_sort/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable h4_queue_sort"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/h4_queue_sort.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/h4_queue_sort.dir/build: h4_queue_sort
.PHONY : CMakeFiles/h4_queue_sort.dir/build

CMakeFiles/h4_queue_sort.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/h4_queue_sort.dir/cmake_clean.cmake
.PHONY : CMakeFiles/h4_queue_sort.dir/clean

CMakeFiles/h4_queue_sort.dir/depend:
	cd /Users/zyh/CLionProjects/ex3_sort/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/zyh/CLionProjects/ex3_sort /Users/zyh/CLionProjects/ex3_sort /Users/zyh/CLionProjects/ex3_sort/cmake-build-debug /Users/zyh/CLionProjects/ex3_sort/cmake-build-debug /Users/zyh/CLionProjects/ex3_sort/cmake-build-debug/CMakeFiles/h4_queue_sort.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/h4_queue_sort.dir/depend

