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
include CMakeFiles/sem.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sem.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sem.dir/flags.make

CMakeFiles/sem.dir/sem.c.o: CMakeFiles/sem.dir/flags.make
CMakeFiles/sem.dir/sem.c.o: ../sem.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/liuqi/Documents/system_programming/process_2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/sem.dir/sem.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sem.dir/sem.c.o   -c /home/liuqi/Documents/system_programming/process_2/sem.c

CMakeFiles/sem.dir/sem.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sem.dir/sem.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/liuqi/Documents/system_programming/process_2/sem.c > CMakeFiles/sem.dir/sem.c.i

CMakeFiles/sem.dir/sem.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sem.dir/sem.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/liuqi/Documents/system_programming/process_2/sem.c -o CMakeFiles/sem.dir/sem.c.s

CMakeFiles/sem.dir/sem.c.o.requires:

.PHONY : CMakeFiles/sem.dir/sem.c.o.requires

CMakeFiles/sem.dir/sem.c.o.provides: CMakeFiles/sem.dir/sem.c.o.requires
	$(MAKE) -f CMakeFiles/sem.dir/build.make CMakeFiles/sem.dir/sem.c.o.provides.build
.PHONY : CMakeFiles/sem.dir/sem.c.o.provides

CMakeFiles/sem.dir/sem.c.o.provides.build: CMakeFiles/sem.dir/sem.c.o


# Object files for target sem
sem_OBJECTS = \
"CMakeFiles/sem.dir/sem.c.o"

# External object files for target sem
sem_EXTERNAL_OBJECTS =

sem: CMakeFiles/sem.dir/sem.c.o
sem: CMakeFiles/sem.dir/build.make
sem: CMakeFiles/sem.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/liuqi/Documents/system_programming/process_2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable sem"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sem.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sem.dir/build: sem

.PHONY : CMakeFiles/sem.dir/build

CMakeFiles/sem.dir/requires: CMakeFiles/sem.dir/sem.c.o.requires

.PHONY : CMakeFiles/sem.dir/requires

CMakeFiles/sem.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sem.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sem.dir/clean

CMakeFiles/sem.dir/depend:
	cd /home/liuqi/Documents/system_programming/process_2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/liuqi/Documents/system_programming/process_2 /home/liuqi/Documents/system_programming/process_2 /home/liuqi/Documents/system_programming/process_2/cmake-build-debug /home/liuqi/Documents/system_programming/process_2/cmake-build-debug /home/liuqi/Documents/system_programming/process_2/cmake-build-debug/CMakeFiles/sem.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sem.dir/depend

