# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/Users/P_Cat/IdeaProjects/naivebayes-hassang2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/P_Cat/IdeaProjects/naivebayes-hassang2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/testunit.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/testunit.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/testunit.dir/flags.make

CMakeFiles/testunit.dir/Tests/digit_feature_test.cpp.o: CMakeFiles/testunit.dir/flags.make
CMakeFiles/testunit.dir/Tests/digit_feature_test.cpp.o: ../Tests/digit_feature_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/P_Cat/IdeaProjects/naivebayes-hassang2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/testunit.dir/Tests/digit_feature_test.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/testunit.dir/Tests/digit_feature_test.cpp.o -c /mnt/c/Users/P_Cat/IdeaProjects/naivebayes-hassang2/Tests/digit_feature_test.cpp

CMakeFiles/testunit.dir/Tests/digit_feature_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testunit.dir/Tests/digit_feature_test.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/P_Cat/IdeaProjects/naivebayes-hassang2/Tests/digit_feature_test.cpp > CMakeFiles/testunit.dir/Tests/digit_feature_test.cpp.i

CMakeFiles/testunit.dir/Tests/digit_feature_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testunit.dir/Tests/digit_feature_test.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/P_Cat/IdeaProjects/naivebayes-hassang2/Tests/digit_feature_test.cpp -o CMakeFiles/testunit.dir/Tests/digit_feature_test.cpp.s

CMakeFiles/testunit.dir/Tests/digit_feature_test.cpp.o.requires:

.PHONY : CMakeFiles/testunit.dir/Tests/digit_feature_test.cpp.o.requires

CMakeFiles/testunit.dir/Tests/digit_feature_test.cpp.o.provides: CMakeFiles/testunit.dir/Tests/digit_feature_test.cpp.o.requires
	$(MAKE) -f CMakeFiles/testunit.dir/build.make CMakeFiles/testunit.dir/Tests/digit_feature_test.cpp.o.provides.build
.PHONY : CMakeFiles/testunit.dir/Tests/digit_feature_test.cpp.o.provides

CMakeFiles/testunit.dir/Tests/digit_feature_test.cpp.o.provides.build: CMakeFiles/testunit.dir/Tests/digit_feature_test.cpp.o


CMakeFiles/testunit.dir/Tests/digit_classifier_test.cpp.o: CMakeFiles/testunit.dir/flags.make
CMakeFiles/testunit.dir/Tests/digit_classifier_test.cpp.o: ../Tests/digit_classifier_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/P_Cat/IdeaProjects/naivebayes-hassang2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/testunit.dir/Tests/digit_classifier_test.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/testunit.dir/Tests/digit_classifier_test.cpp.o -c /mnt/c/Users/P_Cat/IdeaProjects/naivebayes-hassang2/Tests/digit_classifier_test.cpp

CMakeFiles/testunit.dir/Tests/digit_classifier_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testunit.dir/Tests/digit_classifier_test.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/P_Cat/IdeaProjects/naivebayes-hassang2/Tests/digit_classifier_test.cpp > CMakeFiles/testunit.dir/Tests/digit_classifier_test.cpp.i

CMakeFiles/testunit.dir/Tests/digit_classifier_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testunit.dir/Tests/digit_classifier_test.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/P_Cat/IdeaProjects/naivebayes-hassang2/Tests/digit_classifier_test.cpp -o CMakeFiles/testunit.dir/Tests/digit_classifier_test.cpp.s

CMakeFiles/testunit.dir/Tests/digit_classifier_test.cpp.o.requires:

.PHONY : CMakeFiles/testunit.dir/Tests/digit_classifier_test.cpp.o.requires

CMakeFiles/testunit.dir/Tests/digit_classifier_test.cpp.o.provides: CMakeFiles/testunit.dir/Tests/digit_classifier_test.cpp.o.requires
	$(MAKE) -f CMakeFiles/testunit.dir/build.make CMakeFiles/testunit.dir/Tests/digit_classifier_test.cpp.o.provides.build
.PHONY : CMakeFiles/testunit.dir/Tests/digit_classifier_test.cpp.o.provides

CMakeFiles/testunit.dir/Tests/digit_classifier_test.cpp.o.provides.build: CMakeFiles/testunit.dir/Tests/digit_classifier_test.cpp.o


# Object files for target testunit
testunit_OBJECTS = \
"CMakeFiles/testunit.dir/Tests/digit_feature_test.cpp.o" \
"CMakeFiles/testunit.dir/Tests/digit_classifier_test.cpp.o"

# External object files for target testunit
testunit_EXTERNAL_OBJECTS =

testunit: CMakeFiles/testunit.dir/Tests/digit_feature_test.cpp.o
testunit: CMakeFiles/testunit.dir/Tests/digit_classifier_test.cpp.o
testunit: CMakeFiles/testunit.dir/build.make
testunit: CMakeFiles/testunit.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/P_Cat/IdeaProjects/naivebayes-hassang2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable testunit"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testunit.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/testunit.dir/build: testunit

.PHONY : CMakeFiles/testunit.dir/build

CMakeFiles/testunit.dir/requires: CMakeFiles/testunit.dir/Tests/digit_feature_test.cpp.o.requires
CMakeFiles/testunit.dir/requires: CMakeFiles/testunit.dir/Tests/digit_classifier_test.cpp.o.requires

.PHONY : CMakeFiles/testunit.dir/requires

CMakeFiles/testunit.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/testunit.dir/cmake_clean.cmake
.PHONY : CMakeFiles/testunit.dir/clean

CMakeFiles/testunit.dir/depend:
	cd /mnt/c/Users/P_Cat/IdeaProjects/naivebayes-hassang2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/P_Cat/IdeaProjects/naivebayes-hassang2 /mnt/c/Users/P_Cat/IdeaProjects/naivebayes-hassang2 /mnt/c/Users/P_Cat/IdeaProjects/naivebayes-hassang2/cmake-build-debug /mnt/c/Users/P_Cat/IdeaProjects/naivebayes-hassang2/cmake-build-debug /mnt/c/Users/P_Cat/IdeaProjects/naivebayes-hassang2/cmake-build-debug/CMakeFiles/testunit.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/testunit.dir/depend
