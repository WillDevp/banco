# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /snap/clion/112/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/112/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/wilmar/CLionProjects/Banco

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wilmar/CLionProjects/Banco/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Banco.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Banco.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Banco.dir/flags.make

CMakeFiles/Banco.dir/main.cpp.o: CMakeFiles/Banco.dir/flags.make
CMakeFiles/Banco.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wilmar/CLionProjects/Banco/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Banco.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Banco.dir/main.cpp.o -c /home/wilmar/CLionProjects/Banco/main.cpp

CMakeFiles/Banco.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Banco.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wilmar/CLionProjects/Banco/main.cpp > CMakeFiles/Banco.dir/main.cpp.i

CMakeFiles/Banco.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Banco.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wilmar/CLionProjects/Banco/main.cpp -o CMakeFiles/Banco.dir/main.cpp.s

# Object files for target Banco
Banco_OBJECTS = \
"CMakeFiles/Banco.dir/main.cpp.o"

# External object files for target Banco
Banco_EXTERNAL_OBJECTS =

Banco: CMakeFiles/Banco.dir/main.cpp.o
Banco: CMakeFiles/Banco.dir/build.make
Banco: CMakeFiles/Banco.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wilmar/CLionProjects/Banco/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Banco"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Banco.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Banco.dir/build: Banco

.PHONY : CMakeFiles/Banco.dir/build

CMakeFiles/Banco.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Banco.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Banco.dir/clean

CMakeFiles/Banco.dir/depend:
	cd /home/wilmar/CLionProjects/Banco/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wilmar/CLionProjects/Banco /home/wilmar/CLionProjects/Banco /home/wilmar/CLionProjects/Banco/cmake-build-debug /home/wilmar/CLionProjects/Banco/cmake-build-debug /home/wilmar/CLionProjects/Banco/cmake-build-debug/CMakeFiles/Banco.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Banco.dir/depend
