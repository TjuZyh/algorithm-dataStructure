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
CMAKE_SOURCE_DIR = /Users/zyh/CLionProjects/ex7_String

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/zyh/CLionProjects/ex7_String/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ex7_String.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/ex7_String.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ex7_String.dir/flags.make

CMakeFiles/ex7_String.dir/main.cpp.o: CMakeFiles/ex7_String.dir/flags.make
CMakeFiles/ex7_String.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zyh/CLionProjects/ex7_String/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ex7_String.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ex7_String.dir/main.cpp.o -c /Users/zyh/CLionProjects/ex7_String/main.cpp

CMakeFiles/ex7_String.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ex7_String.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zyh/CLionProjects/ex7_String/main.cpp > CMakeFiles/ex7_String.dir/main.cpp.i

CMakeFiles/ex7_String.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ex7_String.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zyh/CLionProjects/ex7_String/main.cpp -o CMakeFiles/ex7_String.dir/main.cpp.s

# Object files for target ex7_String
ex7_String_OBJECTS = \
"CMakeFiles/ex7_String.dir/main.cpp.o"

# External object files for target ex7_String
ex7_String_EXTERNAL_OBJECTS =

ex7_String: CMakeFiles/ex7_String.dir/main.cpp.o
ex7_String: CMakeFiles/ex7_String.dir/build.make
ex7_String: CMakeFiles/ex7_String.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/zyh/CLionProjects/ex7_String/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ex7_String"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ex7_String.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ex7_String.dir/build: ex7_String
.PHONY : CMakeFiles/ex7_String.dir/build

CMakeFiles/ex7_String.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ex7_String.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ex7_String.dir/clean

CMakeFiles/ex7_String.dir/depend:
	cd /Users/zyh/CLionProjects/ex7_String/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/zyh/CLionProjects/ex7_String /Users/zyh/CLionProjects/ex7_String /Users/zyh/CLionProjects/ex7_String/cmake-build-debug /Users/zyh/CLionProjects/ex7_String/cmake-build-debug /Users/zyh/CLionProjects/ex7_String/cmake-build-debug/CMakeFiles/ex7_String.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ex7_String.dir/depend

