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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sangddung/lec-iot/homework/dns-01

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sangddung/lec-iot/homework/dns-01/build

# Include any dependencies generated for this target.
include CMakeFiles/dns-server.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/dns-server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/dns-server.dir/flags.make

CMakeFiles/dns-server.dir/main.cpp.o: CMakeFiles/dns-server.dir/flags.make
CMakeFiles/dns-server.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sangddung/lec-iot/homework/dns-01/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/dns-server.dir/main.cpp.o"
	/usr/bin/aarch64-linux-gnu-g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dns-server.dir/main.cpp.o -c /home/sangddung/lec-iot/homework/dns-01/main.cpp

CMakeFiles/dns-server.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dns-server.dir/main.cpp.i"
	/usr/bin/aarch64-linux-gnu-g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sangddung/lec-iot/homework/dns-01/main.cpp > CMakeFiles/dns-server.dir/main.cpp.i

CMakeFiles/dns-server.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dns-server.dir/main.cpp.s"
	/usr/bin/aarch64-linux-gnu-g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sangddung/lec-iot/homework/dns-01/main.cpp -o CMakeFiles/dns-server.dir/main.cpp.s

CMakeFiles/dns-server.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/dns-server.dir/main.cpp.o.requires

CMakeFiles/dns-server.dir/main.cpp.o.provides: CMakeFiles/dns-server.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/dns-server.dir/build.make CMakeFiles/dns-server.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/dns-server.dir/main.cpp.o.provides

CMakeFiles/dns-server.dir/main.cpp.o.provides.build: CMakeFiles/dns-server.dir/main.cpp.o


CMakeFiles/dns-server.dir/host.cpp.o: CMakeFiles/dns-server.dir/flags.make
CMakeFiles/dns-server.dir/host.cpp.o: ../host.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sangddung/lec-iot/homework/dns-01/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/dns-server.dir/host.cpp.o"
	/usr/bin/aarch64-linux-gnu-g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dns-server.dir/host.cpp.o -c /home/sangddung/lec-iot/homework/dns-01/host.cpp

CMakeFiles/dns-server.dir/host.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dns-server.dir/host.cpp.i"
	/usr/bin/aarch64-linux-gnu-g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sangddung/lec-iot/homework/dns-01/host.cpp > CMakeFiles/dns-server.dir/host.cpp.i

CMakeFiles/dns-server.dir/host.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dns-server.dir/host.cpp.s"
	/usr/bin/aarch64-linux-gnu-g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sangddung/lec-iot/homework/dns-01/host.cpp -o CMakeFiles/dns-server.dir/host.cpp.s

CMakeFiles/dns-server.dir/host.cpp.o.requires:

.PHONY : CMakeFiles/dns-server.dir/host.cpp.o.requires

CMakeFiles/dns-server.dir/host.cpp.o.provides: CMakeFiles/dns-server.dir/host.cpp.o.requires
	$(MAKE) -f CMakeFiles/dns-server.dir/build.make CMakeFiles/dns-server.dir/host.cpp.o.provides.build
.PHONY : CMakeFiles/dns-server.dir/host.cpp.o.provides

CMakeFiles/dns-server.dir/host.cpp.o.provides.build: CMakeFiles/dns-server.dir/host.cpp.o


CMakeFiles/dns-server.dir/manager.cpp.o: CMakeFiles/dns-server.dir/flags.make
CMakeFiles/dns-server.dir/manager.cpp.o: ../manager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sangddung/lec-iot/homework/dns-01/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/dns-server.dir/manager.cpp.o"
	/usr/bin/aarch64-linux-gnu-g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dns-server.dir/manager.cpp.o -c /home/sangddung/lec-iot/homework/dns-01/manager.cpp

CMakeFiles/dns-server.dir/manager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dns-server.dir/manager.cpp.i"
	/usr/bin/aarch64-linux-gnu-g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sangddung/lec-iot/homework/dns-01/manager.cpp > CMakeFiles/dns-server.dir/manager.cpp.i

CMakeFiles/dns-server.dir/manager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dns-server.dir/manager.cpp.s"
	/usr/bin/aarch64-linux-gnu-g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sangddung/lec-iot/homework/dns-01/manager.cpp -o CMakeFiles/dns-server.dir/manager.cpp.s

CMakeFiles/dns-server.dir/manager.cpp.o.requires:

.PHONY : CMakeFiles/dns-server.dir/manager.cpp.o.requires

CMakeFiles/dns-server.dir/manager.cpp.o.provides: CMakeFiles/dns-server.dir/manager.cpp.o.requires
	$(MAKE) -f CMakeFiles/dns-server.dir/build.make CMakeFiles/dns-server.dir/manager.cpp.o.provides.build
.PHONY : CMakeFiles/dns-server.dir/manager.cpp.o.provides

CMakeFiles/dns-server.dir/manager.cpp.o.provides.build: CMakeFiles/dns-server.dir/manager.cpp.o


CMakeFiles/dns-server.dir/tools/datatype.cpp.o: CMakeFiles/dns-server.dir/flags.make
CMakeFiles/dns-server.dir/tools/datatype.cpp.o: ../tools/datatype.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sangddung/lec-iot/homework/dns-01/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/dns-server.dir/tools/datatype.cpp.o"
	/usr/bin/aarch64-linux-gnu-g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dns-server.dir/tools/datatype.cpp.o -c /home/sangddung/lec-iot/homework/dns-01/tools/datatype.cpp

CMakeFiles/dns-server.dir/tools/datatype.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dns-server.dir/tools/datatype.cpp.i"
	/usr/bin/aarch64-linux-gnu-g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sangddung/lec-iot/homework/dns-01/tools/datatype.cpp > CMakeFiles/dns-server.dir/tools/datatype.cpp.i

CMakeFiles/dns-server.dir/tools/datatype.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dns-server.dir/tools/datatype.cpp.s"
	/usr/bin/aarch64-linux-gnu-g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sangddung/lec-iot/homework/dns-01/tools/datatype.cpp -o CMakeFiles/dns-server.dir/tools/datatype.cpp.s

CMakeFiles/dns-server.dir/tools/datatype.cpp.o.requires:

.PHONY : CMakeFiles/dns-server.dir/tools/datatype.cpp.o.requires

CMakeFiles/dns-server.dir/tools/datatype.cpp.o.provides: CMakeFiles/dns-server.dir/tools/datatype.cpp.o.requires
	$(MAKE) -f CMakeFiles/dns-server.dir/build.make CMakeFiles/dns-server.dir/tools/datatype.cpp.o.provides.build
.PHONY : CMakeFiles/dns-server.dir/tools/datatype.cpp.o.provides

CMakeFiles/dns-server.dir/tools/datatype.cpp.o.provides.build: CMakeFiles/dns-server.dir/tools/datatype.cpp.o


CMakeFiles/dns-server.dir/database/ConnectionPool.cpp.o: CMakeFiles/dns-server.dir/flags.make
CMakeFiles/dns-server.dir/database/ConnectionPool.cpp.o: ../database/ConnectionPool.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sangddung/lec-iot/homework/dns-01/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/dns-server.dir/database/ConnectionPool.cpp.o"
	/usr/bin/aarch64-linux-gnu-g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dns-server.dir/database/ConnectionPool.cpp.o -c /home/sangddung/lec-iot/homework/dns-01/database/ConnectionPool.cpp

CMakeFiles/dns-server.dir/database/ConnectionPool.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dns-server.dir/database/ConnectionPool.cpp.i"
	/usr/bin/aarch64-linux-gnu-g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sangddung/lec-iot/homework/dns-01/database/ConnectionPool.cpp > CMakeFiles/dns-server.dir/database/ConnectionPool.cpp.i

CMakeFiles/dns-server.dir/database/ConnectionPool.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dns-server.dir/database/ConnectionPool.cpp.s"
	/usr/bin/aarch64-linux-gnu-g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sangddung/lec-iot/homework/dns-01/database/ConnectionPool.cpp -o CMakeFiles/dns-server.dir/database/ConnectionPool.cpp.s

CMakeFiles/dns-server.dir/database/ConnectionPool.cpp.o.requires:

.PHONY : CMakeFiles/dns-server.dir/database/ConnectionPool.cpp.o.requires

CMakeFiles/dns-server.dir/database/ConnectionPool.cpp.o.provides: CMakeFiles/dns-server.dir/database/ConnectionPool.cpp.o.requires
	$(MAKE) -f CMakeFiles/dns-server.dir/build.make CMakeFiles/dns-server.dir/database/ConnectionPool.cpp.o.provides.build
.PHONY : CMakeFiles/dns-server.dir/database/ConnectionPool.cpp.o.provides

CMakeFiles/dns-server.dir/database/ConnectionPool.cpp.o.provides.build: CMakeFiles/dns-server.dir/database/ConnectionPool.cpp.o


CMakeFiles/dns-server.dir/database/HostRepository.cpp.o: CMakeFiles/dns-server.dir/flags.make
CMakeFiles/dns-server.dir/database/HostRepository.cpp.o: ../database/HostRepository.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sangddung/lec-iot/homework/dns-01/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/dns-server.dir/database/HostRepository.cpp.o"
	/usr/bin/aarch64-linux-gnu-g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dns-server.dir/database/HostRepository.cpp.o -c /home/sangddung/lec-iot/homework/dns-01/database/HostRepository.cpp

CMakeFiles/dns-server.dir/database/HostRepository.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dns-server.dir/database/HostRepository.cpp.i"
	/usr/bin/aarch64-linux-gnu-g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sangddung/lec-iot/homework/dns-01/database/HostRepository.cpp > CMakeFiles/dns-server.dir/database/HostRepository.cpp.i

CMakeFiles/dns-server.dir/database/HostRepository.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dns-server.dir/database/HostRepository.cpp.s"
	/usr/bin/aarch64-linux-gnu-g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sangddung/lec-iot/homework/dns-01/database/HostRepository.cpp -o CMakeFiles/dns-server.dir/database/HostRepository.cpp.s

CMakeFiles/dns-server.dir/database/HostRepository.cpp.o.requires:

.PHONY : CMakeFiles/dns-server.dir/database/HostRepository.cpp.o.requires

CMakeFiles/dns-server.dir/database/HostRepository.cpp.o.provides: CMakeFiles/dns-server.dir/database/HostRepository.cpp.o.requires
	$(MAKE) -f CMakeFiles/dns-server.dir/build.make CMakeFiles/dns-server.dir/database/HostRepository.cpp.o.provides.build
.PHONY : CMakeFiles/dns-server.dir/database/HostRepository.cpp.o.provides

CMakeFiles/dns-server.dir/database/HostRepository.cpp.o.provides.build: CMakeFiles/dns-server.dir/database/HostRepository.cpp.o


# Object files for target dns-server
dns__server_OBJECTS = \
"CMakeFiles/dns-server.dir/main.cpp.o" \
"CMakeFiles/dns-server.dir/host.cpp.o" \
"CMakeFiles/dns-server.dir/manager.cpp.o" \
"CMakeFiles/dns-server.dir/tools/datatype.cpp.o" \
"CMakeFiles/dns-server.dir/database/ConnectionPool.cpp.o" \
"CMakeFiles/dns-server.dir/database/HostRepository.cpp.o"

# External object files for target dns-server
dns__server_EXTERNAL_OBJECTS =

dns-server: CMakeFiles/dns-server.dir/main.cpp.o
dns-server: CMakeFiles/dns-server.dir/host.cpp.o
dns-server: CMakeFiles/dns-server.dir/manager.cpp.o
dns-server: CMakeFiles/dns-server.dir/tools/datatype.cpp.o
dns-server: CMakeFiles/dns-server.dir/database/ConnectionPool.cpp.o
dns-server: CMakeFiles/dns-server.dir/database/HostRepository.cpp.o
dns-server: CMakeFiles/dns-server.dir/build.make
dns-server: /usr/lib/aarch64-linux-gnu/libmysqlcppconn.so
dns-server: CMakeFiles/dns-server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sangddung/lec-iot/homework/dns-01/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable dns-server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dns-server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/dns-server.dir/build: dns-server

.PHONY : CMakeFiles/dns-server.dir/build

CMakeFiles/dns-server.dir/requires: CMakeFiles/dns-server.dir/main.cpp.o.requires
CMakeFiles/dns-server.dir/requires: CMakeFiles/dns-server.dir/host.cpp.o.requires
CMakeFiles/dns-server.dir/requires: CMakeFiles/dns-server.dir/manager.cpp.o.requires
CMakeFiles/dns-server.dir/requires: CMakeFiles/dns-server.dir/tools/datatype.cpp.o.requires
CMakeFiles/dns-server.dir/requires: CMakeFiles/dns-server.dir/database/ConnectionPool.cpp.o.requires
CMakeFiles/dns-server.dir/requires: CMakeFiles/dns-server.dir/database/HostRepository.cpp.o.requires

.PHONY : CMakeFiles/dns-server.dir/requires

CMakeFiles/dns-server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/dns-server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/dns-server.dir/clean

CMakeFiles/dns-server.dir/depend:
	cd /home/sangddung/lec-iot/homework/dns-01/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sangddung/lec-iot/homework/dns-01 /home/sangddung/lec-iot/homework/dns-01 /home/sangddung/lec-iot/homework/dns-01/build /home/sangddung/lec-iot/homework/dns-01/build /home/sangddung/lec-iot/homework/dns-01/build/CMakeFiles/dns-server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/dns-server.dir/depend

