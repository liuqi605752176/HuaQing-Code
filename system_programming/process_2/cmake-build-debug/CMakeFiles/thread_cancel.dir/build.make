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
CMAKE_SOURCE_DIR = /home/liuqi/Documents/system_programming/process_2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/liuqi/Documents/system_programming/process_2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/thread_cancel.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/thread_cancel.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/thread_cancel.dir/flags.make

CMakeFiles/thread_cancel.dir/thread_cancel.c.o: CMakeFiles/thread_cancel.dir/flags.make
CMakeFiles/thread_cancel.dir/thread_cancel.c.o: ../thread_cancel.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/liuqi/Documents/system_programming/process_2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/thread_cancel.dir/thread_cancel.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/thread_cancel.dir/thread_cancel.c.o   -c /home/liuqi/Documents/system_programming/process_2/thread_cancel.c

CMakeFiles/thread_cancel.dir/thread_cancel.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/thread_cancel.dir/thread_cancel.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/liuqi/Documents/system_programming/process_2/thread_cancel.c > CMakeFiles/thread_cancel.dir/thread_cancel.c.i

CMakeFiles/thread_cancel.dir/thread_cancel.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/thread_cancel.dir/thread_cancel.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/liuqi/Documents/system_programming/process_2/thread_cancel.c -o CMakeFiles/thread_cancel.dir/thread_cancel.c.s

CMakeFiles/thread_cancel.dir/thread_cancel.c.o.requires:

.PHONY : CMakeFiles/thread_cancel.dir/thread_cancel.c.o.requires

CMakeFiles/thread_cancel.dir/thread_cancel.c.o.provides: CMakeFiles/thread_cancel.dir/thread_cancel.c.o.requires
	$(MAKE) -f CMakeFiles/thread_cancel.dir/build.make CMakeFiles/thread_cancel.dir/thread_cancel.c.o.provides.build
.PHONY : CMakeFiles/thread_cancel.dir/thread_cancel.c.o.provides

CMakeFiles/thread_cancel.dir/thread_cancel.c.o.provides.build: CMakeFiles/thread_cancel.dir/thread_cancel.c.o


# Object files for target thread_cancel
thread_cancel_OBJECTS = \
"CMakeFiles/thread_cancel.dir/thread_cancel.c.o"

# External object files for target thread_cancel
thread_cancel_EXTERNAL_OBJECTS =

thread_cancel: CMakeFiles/thread_cancel.dir/thread_cancel.c.o
thread_cancel: CMakeFiles/thread_cancel.dir/build.make
thread_cancel: CMakeFiles/thread_cancel.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/liuqi/Documents/system_programming/process_2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable thread_cancel"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/thread_cancel.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/thread_cancel.dir/build: thread_cancel

.PHONY : CMakeFiles/thread_cancel.dir/build

CMakeFiles/thread_cancel.dir/requires: CMakeFiles/thread_cancel.dir/thread_cancel.c.o.requires

.PHONY : CMakeFiles/thread_cancel.dir/requires

CMakeFiles/thread_cancel.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/thread_cancel.dir/cmake_clean.cmake
.PHONY : CMakeFiles/thread_cancel.dir/clean

CMakeFiles/thread_cancel.dir/depend:
	cd /home/liuqi/Documents/system_programming/process_2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/liuqi/Documents/system_programming/process_2 /home/liuqi/Documents/system_programming/process_2 /home/liuqi/Documents/system_programming/process_2/cmake-build-debug /home/liuqi/Documents/system_programming/process_2/cmake-build-debug /home/liuqi/Documents/system_programming/process_2/cmake-build-debug/CMakeFiles/thread_cancel.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/thread_cancel.dir/depend

