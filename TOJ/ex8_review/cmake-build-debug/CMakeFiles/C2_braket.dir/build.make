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
CMAKE_SOURCE_DIR = /Users/zyh/CLionProjects/ex8_review

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/zyh/CLionProjects/ex8_review/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/C2_braket.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/C2_braket.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/C2_braket.dir/flags.make

CMakeFiles/C2_braket.dir/C2_braket.cpp.o: CMakeFiles/C2_braket.dir/flags.make
CMakeFiles/C2_braket.dir/C2_braket.cpp.o: ../C2_braket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zyh/CLionProjects/ex8_review/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/C2_braket.dir/C2_braket.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/C2_braket.dir/C2_braket.cpp.o -c /Users/zyh/CLionProjects/ex8_review/C2_braket.cpp

CMakeFiles/C2_braket.dir/C2_braket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/C2_braket.dir/C2_braket.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zyh/CLionProjects/ex8_review/C2_braket.cpp > CMakeFiles/C2_braket.dir/C2_braket.cpp.i

CMakeFiles/C2_braket.dir/C2_braket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/C2_braket.dir/C2_braket.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zyh/CLionProjects/ex8_review/C2_braket.cpp -o CMakeFiles/C2_braket.dir/C2_braket.cpp.s

# Object files for target C2_braket
C2_braket_OBJECTS = \
"CMakeFiles/C2_braket.dir/C2_braket.cpp.o"

# External object files for target C2_braket
C2_braket_EXTERNAL_OBJECTS =

C2_braket: CMakeFiles/C2_braket.dir/C2_braket.cpp.o
C2_braket: CMakeFiles/C2_braket.dir/build.make
C2_braket: CMakeFiles/C2_braket.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/zyh/CLionProjects/ex8_review/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable C2_braket"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/C2_braket.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/C2_braket.dir/build: C2_braket
.PHONY : CMakeFiles/C2_braket.dir/build

CMakeFiles/C2_braket.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/C2_braket.dir/cmake_clean.cmake
.PHONY : CMakeFiles/C2_braket.dir/clean

CMakeFiles/C2_braket.dir/depend:
	cd /Users/zyh/CLionProjects/ex8_review/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/zyh/CLionProjects/ex8_review /Users/zyh/CLionProjects/ex8_review /Users/zyh/CLionProjects/ex8_review/cmake-build-debug /Users/zyh/CLionProjects/ex8_review/cmake-build-debug /Users/zyh/CLionProjects/ex8_review/cmake-build-debug/CMakeFiles/C2_braket.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/C2_braket.dir/depend

