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
include CMakeFiles/mkfifo_write.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/mkfifo_write.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mkfifo_write.dir/flags.make

CMakeFiles/mkfifo_write.dir/mkfifo_write.c.o: CMakeFiles/mkfifo_write.dir/flags.make
CMakeFiles/mkfifo_write.dir/mkfifo_write.c.o: ../mkfifo_write.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/liuqi/Documents/system_programming/process_3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/mkfifo_write.dir/mkfifo_write.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/mkfifo_write.dir/mkfifo_write.c.o   -c /home/liuqi/Documents/system_programming/process_3/mkfifo_write.c

CMakeFiles/mkfifo_write.dir/mkfifo_write.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mkfifo_write.dir/mkfifo_write.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/liuqi/Documents/system_programming/process_3/mkfifo_write.c > CMakeFiles/mkfifo_write.dir/mkfifo_write.c.i

CMakeFiles/mkfifo_write.dir/mkfifo_write.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mkfifo_write.dir/mkfifo_write.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/liuqi/Documents/system_programming/process_3/mkfifo_write.c -o CMakeFiles/mkfifo_write.dir/mkfifo_write.c.s

CMakeFiles/mkfifo_write.dir/mkfifo_write.c.o.requires:

.PHONY : CMakeFiles/mkfifo_write.dir/mkfifo_write.c.o.requires

CMakeFiles/mkfifo_write.dir/mkfifo_write.c.o.provides: CMakeFiles/mkfifo_write.dir/mkfifo_write.c.o.requires
	$(MAKE) -f CMakeFiles/mkfifo_write.dir/build.make CMakeFiles/mkfifo_write.dir/mkfifo_write.c.o.provides.build
.PHONY : CMakeFiles/mkfifo_write.dir/mkfifo_write.c.o.provides

CMakeFiles/mkfifo_write.dir/mkfifo_write.c.o.provides.build: CMakeFiles/mkfifo_write.dir/mkfifo_write.c.o


# Object files for target mkfifo_write
mkfifo_write_OBJECTS = \
"CMakeFiles/mkfifo_write.dir/mkfifo_write.c.o"

# External object files for target mkfifo_write
mkfifo_write_EXTERNAL_OBJECTS =

mkfifo_write: CMakeFiles/mkfifo_write.dir/mkfifo_write.c.o
mkfifo_write: CMakeFiles/mkfifo_write.dir/build.make
mkfifo_write: CMakeFiles/mkfifo_write.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/liuqi/Documents/system_programming/process_3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable mkfifo_write"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mkfifo_write.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mkfifo_write.dir/build: mkfifo_write

.PHONY : CMakeFiles/mkfifo_write.dir/build

CMakeFiles/mkfifo_write.dir/requires: CMakeFiles/mkfifo_write.dir/mkfifo_write.c.o.requires

.PHONY : CMakeFiles/mkfifo_write.dir/requires

CMakeFiles/mkfifo_write.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mkfifo_write.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mkfifo_write.dir/clean

CMakeFiles/mkfifo_write.dir/depend:
	cd /home/liuqi/Documents/system_programming/process_3/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/liuqi/Documents/system_programming/process_3 /home/liuqi/Documents/system_programming/process_3 /home/liuqi/Documents/system_programming/process_3/cmake-build-debug /home/liuqi/Documents/system_programming/process_3/cmake-build-debug /home/liuqi/Documents/system_programming/process_3/cmake-build-debug/CMakeFiles/mkfifo_write.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mkfifo_write.dir/depend

