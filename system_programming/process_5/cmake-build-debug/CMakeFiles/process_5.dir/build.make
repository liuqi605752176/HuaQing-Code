# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /home/liuqi/Downloads/clion-2018.1/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/liuqi/Downloads/clion-2018.1/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/liuqi/Documents/system_programming/process_5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/liuqi/Documents/system_programming/process_5/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/process_5.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/process_5.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/process_5.dir/flags.make

CMakeFiles/process_5.dir/main.c.o: CMakeFiles/process_5.dir/flags.make
CMakeFiles/process_5.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/liuqi/Documents/system_programming/process_5/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/process_5.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/process_5.dir/main.c.o   -c /home/liuqi/Documents/system_programming/process_5/main.c

CMakeFiles/process_5.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/process_5.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/liuqi/Documents/system_programming/process_5/main.c > CMakeFiles/process_5.dir/main.c.i

CMakeFiles/process_5.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/process_5.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/liuqi/Documents/system_programming/process_5/main.c -o CMakeFiles/process_5.dir/main.c.s

CMakeFiles/process_5.dir/main.c.o.requires:

.PHONY : CMakeFiles/process_5.dir/main.c.o.requires

CMakeFiles/process_5.dir/main.c.o.provides: CMakeFiles/process_5.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/process_5.dir/build.make CMakeFiles/process_5.dir/main.c.o.provides.build
.PHONY : CMakeFiles/process_5.dir/main.c.o.provides

CMakeFiles/process_5.dir/main.c.o.provides.build: CMakeFiles/process_5.dir/main.c.o


# Object files for target process_5
process_5_OBJECTS = \
"CMakeFiles/process_5.dir/main.c.o"

# External object files for target process_5
process_5_EXTERNAL_OBJECTS =

process_5: CMakeFiles/process_5.dir/main.c.o
process_5: CMakeFiles/process_5.dir/build.make
process_5: CMakeFiles/process_5.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/liuqi/Documents/system_programming/process_5/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable process_5"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/process_5.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/process_5.dir/build: process_5

.PHONY : CMakeFiles/process_5.dir/build

CMakeFiles/process_5.dir/requires: CMakeFiles/process_5.dir/main.c.o.requires

.PHONY : CMakeFiles/process_5.dir/requires

CMakeFiles/process_5.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/process_5.dir/cmake_clean.cmake
.PHONY : CMakeFiles/process_5.dir/clean

CMakeFiles/process_5.dir/depend:
	cd /home/liuqi/Documents/system_programming/process_5/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/liuqi/Documents/system_programming/process_5 /home/liuqi/Documents/system_programming/process_5 /home/liuqi/Documents/system_programming/process_5/cmake-build-debug /home/liuqi/Documents/system_programming/process_5/cmake-build-debug /home/liuqi/Documents/system_programming/process_5/cmake-build-debug/CMakeFiles/process_5.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/process_5.dir/depend

