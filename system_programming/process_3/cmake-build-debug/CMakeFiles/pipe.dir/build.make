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
CMAKE_SOURCE_DIR = /home/liuqi/Documents/system_programming/process_3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/liuqi/Documents/system_programming/process_3/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/pipe.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/pipe.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pipe.dir/flags.make

CMakeFiles/pipe.dir/pipe.c.o: CMakeFiles/pipe.dir/flags.make
CMakeFiles/pipe.dir/pipe.c.o: ../pipe.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/liuqi/Documents/system_programming/process_3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/pipe.dir/pipe.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/pipe.dir/pipe.c.o   -c /home/liuqi/Documents/system_programming/process_3/pipe.c

CMakeFiles/pipe.dir/pipe.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/pipe.dir/pipe.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/liuqi/Documents/system_programming/process_3/pipe.c > CMakeFiles/pipe.dir/pipe.c.i

CMakeFiles/pipe.dir/pipe.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/pipe.dir/pipe.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/liuqi/Documents/system_programming/process_3/pipe.c -o CMakeFiles/pipe.dir/pipe.c.s

CMakeFiles/pipe.dir/pipe.c.o.requires:

.PHONY : CMakeFiles/pipe.dir/pipe.c.o.requires

CMakeFiles/pipe.dir/pipe.c.o.provides: CMakeFiles/pipe.dir/pipe.c.o.requires
	$(MAKE) -f CMakeFiles/pipe.dir/build.make CMakeFiles/pipe.dir/pipe.c.o.provides.build
.PHONY : CMakeFiles/pipe.dir/pipe.c.o.provides

CMakeFiles/pipe.dir/pipe.c.o.provides.build: CMakeFiles/pipe.dir/pipe.c.o


# Object files for target pipe
pipe_OBJECTS = \
"CMakeFiles/pipe.dir/pipe.c.o"

# External object files for target pipe
pipe_EXTERNAL_OBJECTS =

pipe: CMakeFiles/pipe.dir/pipe.c.o
pipe: CMakeFiles/pipe.dir/build.make
pipe: CMakeFiles/pipe.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/liuqi/Documents/system_programming/process_3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable pipe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pipe.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pipe.dir/build: pipe

.PHONY : CMakeFiles/pipe.dir/build

CMakeFiles/pipe.dir/requires: CMakeFiles/pipe.dir/pipe.c.o.requires

.PHONY : CMakeFiles/pipe.dir/requires

CMakeFiles/pipe.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pipe.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pipe.dir/clean

CMakeFiles/pipe.dir/depend:
	cd /home/liuqi/Documents/system_programming/process_3/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/liuqi/Documents/system_programming/process_3 /home/liuqi/Documents/system_programming/process_3 /home/liuqi/Documents/system_programming/process_3/cmake-build-debug /home/liuqi/Documents/system_programming/process_3/cmake-build-debug /home/liuqi/Documents/system_programming/process_3/cmake-build-debug/CMakeFiles/pipe.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pipe.dir/depend

