# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.16

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.1\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\spo_5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\spo_5\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/spo_5.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/spo_5.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/spo_5.dir/flags.make

CMakeFiles/spo_5.dir/main.c.obj: CMakeFiles/spo_5.dir/flags.make
CMakeFiles/spo_5.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\spo_5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/spo_5.dir/main.c.obj"
	C:\PROGRA~2\MINGW_~1\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\spo_5.dir\main.c.obj   -c C:\spo_5\main.c

CMakeFiles/spo_5.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/spo_5.dir/main.c.i"
	C:\PROGRA~2\MINGW_~1\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\spo_5\main.c > CMakeFiles\spo_5.dir\main.c.i

CMakeFiles/spo_5.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/spo_5.dir/main.c.s"
	C:\PROGRA~2\MINGW_~1\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\spo_5\main.c -o CMakeFiles\spo_5.dir\main.c.s

# Object files for target spo_5
spo_5_OBJECTS = \
"CMakeFiles/spo_5.dir/main.c.obj"

# External object files for target spo_5
spo_5_EXTERNAL_OBJECTS =

spo_5.exe: CMakeFiles/spo_5.dir/main.c.obj
spo_5.exe: CMakeFiles/spo_5.dir/build.make
spo_5.exe: CMakeFiles/spo_5.dir/linklibs.rsp
spo_5.exe: CMakeFiles/spo_5.dir/objects1.rsp
spo_5.exe: CMakeFiles/spo_5.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\spo_5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable spo_5.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\spo_5.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/spo_5.dir/build: spo_5.exe

.PHONY : CMakeFiles/spo_5.dir/build

CMakeFiles/spo_5.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\spo_5.dir\cmake_clean.cmake
.PHONY : CMakeFiles/spo_5.dir/clean

CMakeFiles/spo_5.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\spo_5 C:\spo_5 C:\spo_5\cmake-build-debug C:\spo_5\cmake-build-debug C:\spo_5\cmake-build-debug\CMakeFiles\spo_5.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/spo_5.dir/depend

