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
include CMakeFiles/mysem.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/mysem.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mysem.dir/flags.make

CMakeFiles/mysem.dir/mysem.c.o: CMakeFiles/mysem.dir/flags.make
CMakeFiles/mysem.dir/mysem.c.o: ../mysem.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/liuqi/Documents/system_programming/process_5/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/mysem.dir/mysem.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/mysem.dir/mysem.c.o   -c /home/liuqi/Documents/system_programming/process_5/mysem.c

CMakeFiles/mysem.dir/mysem.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mysem.dir/mysem.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/liuqi/Documents/system_programming/process_5/mysem.c > CMakeFiles/mysem.dir/mysem.c.i

CMakeFiles/mysem.dir/mysem.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mysem.dir/mysem.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/liuqi/Documents/system_programming/process_5/mysem.c -o CMakeFiles/mysem.dir/mysem.c.s

CMakeFiles/mysem.dir/mysem.c.o.requires:

.PHONY : CMakeFiles/mysem.dir/mysem.c.o.requires

CMakeFiles/mysem.dir/mysem.c.o.provides: CMakeFiles/mysem.dir/mysem.c.o.requires
	$(MAKE) -f CMakeFiles/mysem.dir/build.make CMakeFiles/mysem.dir/mysem.c.o.provides.build
.PHONY : CMakeFiles/mysem.dir/mysem.c.o.provides

CMakeFiles/mysem.dir/mysem.c.o.provides.build: CMakeFiles/mysem.dir/mysem.c.o


# Object files for target mysem
mysem_OBJECTS = \
"CMakeFiles/mysem.dir/mysem.c.o"

# External object files for target mysem
mysem_EXTERNAL_OBJECTS =

mysem: CMakeFiles/mysem.dir/mysem.c.o
mysem: CMakeFiles/mysem.dir/build.make
mysem: CMakeFiles/mysem.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/liuqi/Documents/system_programming/process_5/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable mysem"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mysem.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mysem.dir/build: mysem

.PHONY : CMakeFiles/mysem.dir/build

CMakeFiles/mysem.dir/requires: CMakeFiles/mysem.dir/mysem.c.o.requires

.PHONY : CMakeFiles/mysem.dir/requires

CMakeFiles/mysem.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mysem.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mysem.dir/clean

CMakeFiles/mysem.dir/depend:
	cd /home/liuqi/Documents/system_programming/process_5/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/liuqi/Documents/system_programming/process_5 /home/liuqi/Documents/system_programming/process_5 /home/liuqi/Documents/system_programming/process_5/cmake-build-debug /home/liuqi/Documents/system_programming/process_5/cmake-build-debug /home/liuqi/Documents/system_programming/process_5/cmake-build-debug/CMakeFiles/mysem.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mysem.dir/depend
