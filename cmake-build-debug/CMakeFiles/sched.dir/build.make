# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /home/jj/clion/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/jj/clion/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jj/CLionProjects/sched

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jj/CLionProjects/sched/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/sched.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sched.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sched.dir/flags.make

CMakeFiles/sched.dir/sched.c.o: CMakeFiles/sched.dir/flags.make
CMakeFiles/sched.dir/sched.c.o: ../sched.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jj/CLionProjects/sched/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/sched.dir/sched.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sched.dir/sched.c.o   -c /home/jj/CLionProjects/sched/sched.c

CMakeFiles/sched.dir/sched.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sched.dir/sched.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jj/CLionProjects/sched/sched.c > CMakeFiles/sched.dir/sched.c.i

CMakeFiles/sched.dir/sched.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sched.dir/sched.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jj/CLionProjects/sched/sched.c -o CMakeFiles/sched.dir/sched.c.s

CMakeFiles/sched.dir/proc.c.o: CMakeFiles/sched.dir/flags.make
CMakeFiles/sched.dir/proc.c.o: ../proc.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jj/CLionProjects/sched/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/sched.dir/proc.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sched.dir/proc.c.o   -c /home/jj/CLionProjects/sched/proc.c

CMakeFiles/sched.dir/proc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sched.dir/proc.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jj/CLionProjects/sched/proc.c > CMakeFiles/sched.dir/proc.c.i

CMakeFiles/sched.dir/proc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sched.dir/proc.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jj/CLionProjects/sched/proc.c -o CMakeFiles/sched.dir/proc.c.s

CMakeFiles/sched.dir/procgen.c.o: CMakeFiles/sched.dir/flags.make
CMakeFiles/sched.dir/procgen.c.o: ../procgen.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jj/CLionProjects/sched/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/sched.dir/procgen.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sched.dir/procgen.c.o   -c /home/jj/CLionProjects/sched/procgen.c

CMakeFiles/sched.dir/procgen.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sched.dir/procgen.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jj/CLionProjects/sched/procgen.c > CMakeFiles/sched.dir/procgen.c.i

CMakeFiles/sched.dir/procgen.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sched.dir/procgen.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jj/CLionProjects/sched/procgen.c -o CMakeFiles/sched.dir/procgen.c.s

# Object files for target sched
sched_OBJECTS = \
"CMakeFiles/sched.dir/sched.c.o" \
"CMakeFiles/sched.dir/proc.c.o" \
"CMakeFiles/sched.dir/procgen.c.o"

# External object files for target sched
sched_EXTERNAL_OBJECTS =

sched: CMakeFiles/sched.dir/sched.c.o
sched: CMakeFiles/sched.dir/proc.c.o
sched: CMakeFiles/sched.dir/procgen.c.o
sched: CMakeFiles/sched.dir/build.make
sched: CMakeFiles/sched.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jj/CLionProjects/sched/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable sched"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sched.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sched.dir/build: sched

.PHONY : CMakeFiles/sched.dir/build

CMakeFiles/sched.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sched.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sched.dir/clean

CMakeFiles/sched.dir/depend:
	cd /home/jj/CLionProjects/sched/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jj/CLionProjects/sched /home/jj/CLionProjects/sched /home/jj/CLionProjects/sched/cmake-build-debug /home/jj/CLionProjects/sched/cmake-build-debug /home/jj/CLionProjects/sched/cmake-build-debug/CMakeFiles/sched.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sched.dir/depend

