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
CMAKE_SOURCE_DIR = /home/liuqi/Documents/network/network_1_2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/liuqi/Documents/network/network_1_2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/inet_addr.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/inet_addr.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/inet_addr.dir/flags.make

CMakeFiles/inet_addr.dir/inet_addr.c.o: CMakeFiles/inet_addr.dir/flags.make
CMakeFiles/inet_addr.dir/inet_addr.c.o: ../inet_addr.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/liuqi/Documents/network/network_1_2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/inet_addr.dir/inet_addr.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/inet_addr.dir/inet_addr.c.o   -c /home/liuqi/Documents/network/network_1_2/inet_addr.c

CMakeFiles/inet_addr.dir/inet_addr.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/inet_addr.dir/inet_addr.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/liuqi/Documents/network/network_1_2/inet_addr.c > CMakeFiles/inet_addr.dir/inet_addr.c.i

CMakeFiles/inet_addr.dir/inet_addr.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/inet_addr.dir/inet_addr.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/liuqi/Documents/network/network_1_2/inet_addr.c -o CMakeFiles/inet_addr.dir/inet_addr.c.s

CMakeFiles/inet_addr.dir/inet_addr.c.o.requires:

.PHONY : CMakeFiles/inet_addr.dir/inet_addr.c.o.requires

CMakeFiles/inet_addr.dir/inet_addr.c.o.provides: CMakeFiles/inet_addr.dir/inet_addr.c.o.requires
	$(MAKE) -f CMakeFiles/inet_addr.dir/build.make CMakeFiles/inet_addr.dir/inet_addr.c.o.provides.build
.PHONY : CMakeFiles/inet_addr.dir/inet_addr.c.o.provides

CMakeFiles/inet_addr.dir/inet_addr.c.o.provides.build: CMakeFiles/inet_addr.dir/inet_addr.c.o


# Object files for target inet_addr
inet_addr_OBJECTS = \
"CMakeFiles/inet_addr.dir/inet_addr.c.o"

# External object files for target inet_addr
inet_addr_EXTERNAL_OBJECTS =

inet_addr: CMakeFiles/inet_addr.dir/inet_addr.c.o
inet_addr: CMakeFiles/inet_addr.dir/build.make
inet_addr: CMakeFiles/inet_addr.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/liuqi/Documents/network/network_1_2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable inet_addr"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/inet_addr.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/inet_addr.dir/build: inet_addr

.PHONY : CMakeFiles/inet_addr.dir/build

CMakeFiles/inet_addr.dir/requires: CMakeFiles/inet_addr.dir/inet_addr.c.o.requires

.PHONY : CMakeFiles/inet_addr.dir/requires

CMakeFiles/inet_addr.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/inet_addr.dir/cmake_clean.cmake
.PHONY : CMakeFiles/inet_addr.dir/clean

CMakeFiles/inet_addr.dir/depend:
	cd /home/liuqi/Documents/network/network_1_2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/liuqi/Documents/network/network_1_2 /home/liuqi/Documents/network/network_1_2 /home/liuqi/Documents/network/network_1_2/cmake-build-debug /home/liuqi/Documents/network/network_1_2/cmake-build-debug /home/liuqi/Documents/network/network_1_2/cmake-build-debug/CMakeFiles/inet_addr.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/inet_addr.dir/depend

