# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/admin/CLionProjects/date

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/admin/CLionProjects/date/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/date.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/date.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/date.dir/flags.make

CMakeFiles/date.dir/main.cpp.o: CMakeFiles/date.dir/flags.make
CMakeFiles/date.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/admin/CLionProjects/date/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/date.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/date.dir/main.cpp.o -c /Users/admin/CLionProjects/date/main.cpp

CMakeFiles/date.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/date.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/admin/CLionProjects/date/main.cpp > CMakeFiles/date.dir/main.cpp.i

CMakeFiles/date.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/date.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/admin/CLionProjects/date/main.cpp -o CMakeFiles/date.dir/main.cpp.s

CMakeFiles/date.dir/date.cpp.o: CMakeFiles/date.dir/flags.make
CMakeFiles/date.dir/date.cpp.o: ../date.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/admin/CLionProjects/date/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/date.dir/date.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/date.dir/date.cpp.o -c /Users/admin/CLionProjects/date/date.cpp

CMakeFiles/date.dir/date.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/date.dir/date.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/admin/CLionProjects/date/date.cpp > CMakeFiles/date.dir/date.cpp.i

CMakeFiles/date.dir/date.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/date.dir/date.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/admin/CLionProjects/date/date.cpp -o CMakeFiles/date.dir/date.cpp.s

# Object files for target date
date_OBJECTS = \
"CMakeFiles/date.dir/main.cpp.o" \
"CMakeFiles/date.dir/date.cpp.o"

# External object files for target date
date_EXTERNAL_OBJECTS =

date: CMakeFiles/date.dir/main.cpp.o
date: CMakeFiles/date.dir/date.cpp.o
date: CMakeFiles/date.dir/build.make
date: CMakeFiles/date.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/admin/CLionProjects/date/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable date"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/date.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/date.dir/build: date

.PHONY : CMakeFiles/date.dir/build

CMakeFiles/date.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/date.dir/cmake_clean.cmake
.PHONY : CMakeFiles/date.dir/clean

CMakeFiles/date.dir/depend:
	cd /Users/admin/CLionProjects/date/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/admin/CLionProjects/date /Users/admin/CLionProjects/date /Users/admin/CLionProjects/date/cmake-build-debug /Users/admin/CLionProjects/date/cmake-build-debug /Users/admin/CLionProjects/date/cmake-build-debug/CMakeFiles/date.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/date.dir/depend
