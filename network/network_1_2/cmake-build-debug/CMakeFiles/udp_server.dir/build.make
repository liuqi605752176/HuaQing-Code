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
include CMakeFiles/udp_server.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/udp_server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/udp_server.dir/flags.make

CMakeFiles/udp_server.dir/udp_server.c.o: CMakeFiles/udp_server.dir/flags.make
CMakeFiles/udp_server.dir/udp_server.c.o: ../udp_server.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/liuqi/Documents/network/network_1_2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/udp_server.dir/udp_server.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/udp_server.dir/udp_server.c.o   -c /home/liuqi/Documents/network/network_1_2/udp_server.c

CMakeFiles/udp_server.dir/udp_server.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/udp_server.dir/udp_server.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/liuqi/Documents/network/network_1_2/udp_server.c > CMakeFiles/udp_server.dir/udp_server.c.i

CMakeFiles/udp_server.dir/udp_server.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/udp_server.dir/udp_server.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/liuqi/Documents/network/network_1_2/udp_server.c -o CMakeFiles/udp_server.dir/udp_server.c.s

CMakeFiles/udp_server.dir/udp_server.c.o.requires:

.PHONY : CMakeFiles/udp_server.dir/udp_server.c.o.requires

CMakeFiles/udp_server.dir/udp_server.c.o.provides: CMakeFiles/udp_server.dir/udp_server.c.o.requires
	$(MAKE) -f CMakeFiles/udp_server.dir/build.make CMakeFiles/udp_server.dir/udp_server.c.o.provides.build
.PHONY : CMakeFiles/udp_server.dir/udp_server.c.o.provides

CMakeFiles/udp_server.dir/udp_server.c.o.provides.build: CMakeFiles/udp_server.dir/udp_server.c.o


# Object files for target udp_server
udp_server_OBJECTS = \
"CMakeFiles/udp_server.dir/udp_server.c.o"

# External object files for target udp_server
udp_server_EXTERNAL_OBJECTS =

udp_server: CMakeFiles/udp_server.dir/udp_server.c.o
udp_server: CMakeFiles/udp_server.dir/build.make
udp_server: CMakeFiles/udp_server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/liuqi/Documents/network/network_1_2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable udp_server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/udp_server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/udp_server.dir/build: udp_server

.PHONY : CMakeFiles/udp_server.dir/build

CMakeFiles/udp_server.dir/requires: CMakeFiles/udp_server.dir/udp_server.c.o.requires

.PHONY : CMakeFiles/udp_server.dir/requires

CMakeFiles/udp_server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/udp_server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/udp_server.dir/clean

CMakeFiles/udp_server.dir/depend:
	cd /home/liuqi/Documents/network/network_1_2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/liuqi/Documents/network/network_1_2 /home/liuqi/Documents/network/network_1_2 /home/liuqi/Documents/network/network_1_2/cmake-build-debug /home/liuqi/Documents/network/network_1_2/cmake-build-debug /home/liuqi/Documents/network/network_1_2/cmake-build-debug/CMakeFiles/udp_server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/udp_server.dir/depend

