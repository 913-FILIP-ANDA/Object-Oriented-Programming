# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\User\Desktop\a23-913-FILIP-ANDA

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\User\Desktop\a23-913-FILIP-ANDA\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\lab2.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\lab2.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\lab2.dir\flags.make

CMakeFiles\lab2.dir\main.c.obj: CMakeFiles\lab2.dir\flags.make
CMakeFiles\lab2.dir\main.c.obj: ..\main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\User\Desktop\a23-913-FILIP-ANDA\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/lab2.dir/main.c.obj"
	C:\PROGRA~2\MIB055~1\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\lab2.dir\main.c.obj /FdCMakeFiles\lab2.dir\ /FS -c C:\Users\User\Desktop\a23-913-FILIP-ANDA\main.c
<<

CMakeFiles\lab2.dir\main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lab2.dir/main.c.i"
	C:\PROGRA~2\MIB055~1\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe > CMakeFiles\lab2.dir\main.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\User\Desktop\a23-913-FILIP-ANDA\main.c
<<

CMakeFiles\lab2.dir\main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lab2.dir/main.c.s"
	C:\PROGRA~2\MIB055~1\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\lab2.dir\main.c.s /c C:\Users\User\Desktop\a23-913-FILIP-ANDA\main.c
<<

CMakeFiles\lab2.dir\domain\Estate.c.obj: CMakeFiles\lab2.dir\flags.make
CMakeFiles\lab2.dir\domain\Estate.c.obj: ..\domain\Estate.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\User\Desktop\a23-913-FILIP-ANDA\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/lab2.dir/domain/Estate.c.obj"
	C:\PROGRA~2\MIB055~1\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\lab2.dir\domain\Estate.c.obj /FdCMakeFiles\lab2.dir\ /FS -c C:\Users\User\Desktop\a23-913-FILIP-ANDA\domain\Estate.c
<<

CMakeFiles\lab2.dir\domain\Estate.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lab2.dir/domain/Estate.c.i"
	C:\PROGRA~2\MIB055~1\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe > CMakeFiles\lab2.dir\domain\Estate.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\User\Desktop\a23-913-FILIP-ANDA\domain\Estate.c
<<

CMakeFiles\lab2.dir\domain\Estate.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lab2.dir/domain/Estate.c.s"
	C:\PROGRA~2\MIB055~1\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\lab2.dir\domain\Estate.c.s /c C:\Users\User\Desktop\a23-913-FILIP-ANDA\domain\Estate.c
<<

CMakeFiles\lab2.dir\repository\Repository.c.obj: CMakeFiles\lab2.dir\flags.make
CMakeFiles\lab2.dir\repository\Repository.c.obj: ..\repository\Repository.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\User\Desktop\a23-913-FILIP-ANDA\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/lab2.dir/repository/Repository.c.obj"
	C:\PROGRA~2\MIB055~1\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\lab2.dir\repository\Repository.c.obj /FdCMakeFiles\lab2.dir\ /FS -c C:\Users\User\Desktop\a23-913-FILIP-ANDA\repository\Repository.c
<<

CMakeFiles\lab2.dir\repository\Repository.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lab2.dir/repository/Repository.c.i"
	C:\PROGRA~2\MIB055~1\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe > CMakeFiles\lab2.dir\repository\Repository.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\User\Desktop\a23-913-FILIP-ANDA\repository\Repository.c
<<

CMakeFiles\lab2.dir\repository\Repository.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lab2.dir/repository/Repository.c.s"
	C:\PROGRA~2\MIB055~1\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\lab2.dir\repository\Repository.c.s /c C:\Users\User\Desktop\a23-913-FILIP-ANDA\repository\Repository.c
<<

CMakeFiles\lab2.dir\service\Service.c.obj: CMakeFiles\lab2.dir\flags.make
CMakeFiles\lab2.dir\service\Service.c.obj: ..\service\Service.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\User\Desktop\a23-913-FILIP-ANDA\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/lab2.dir/service/Service.c.obj"
	C:\PROGRA~2\MIB055~1\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\lab2.dir\service\Service.c.obj /FdCMakeFiles\lab2.dir\ /FS -c C:\Users\User\Desktop\a23-913-FILIP-ANDA\service\Service.c
<<

CMakeFiles\lab2.dir\service\Service.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lab2.dir/service/Service.c.i"
	C:\PROGRA~2\MIB055~1\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe > CMakeFiles\lab2.dir\service\Service.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\User\Desktop\a23-913-FILIP-ANDA\service\Service.c
<<

CMakeFiles\lab2.dir\service\Service.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lab2.dir/service/Service.c.s"
	C:\PROGRA~2\MIB055~1\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\lab2.dir\service\Service.c.s /c C:\Users\User\Desktop\a23-913-FILIP-ANDA\service\Service.c
<<

CMakeFiles\lab2.dir\ui\Ui.c.obj: CMakeFiles\lab2.dir\flags.make
CMakeFiles\lab2.dir\ui\Ui.c.obj: ..\ui\Ui.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\User\Desktop\a23-913-FILIP-ANDA\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/lab2.dir/ui/Ui.c.obj"
	C:\PROGRA~2\MIB055~1\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\lab2.dir\ui\Ui.c.obj /FdCMakeFiles\lab2.dir\ /FS -c C:\Users\User\Desktop\a23-913-FILIP-ANDA\ui\Ui.c
<<

CMakeFiles\lab2.dir\ui\Ui.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lab2.dir/ui/Ui.c.i"
	C:\PROGRA~2\MIB055~1\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe > CMakeFiles\lab2.dir\ui\Ui.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\User\Desktop\a23-913-FILIP-ANDA\ui\Ui.c
<<

CMakeFiles\lab2.dir\ui\Ui.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lab2.dir/ui/Ui.c.s"
	C:\PROGRA~2\MIB055~1\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\lab2.dir\ui\Ui.c.s /c C:\Users\User\Desktop\a23-913-FILIP-ANDA\ui\Ui.c
<<

CMakeFiles\lab2.dir\vector\DynamicArray.c.obj: CMakeFiles\lab2.dir\flags.make
CMakeFiles\lab2.dir\vector\DynamicArray.c.obj: ..\vector\DynamicArray.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\User\Desktop\a23-913-FILIP-ANDA\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/lab2.dir/vector/DynamicArray.c.obj"
	C:\PROGRA~2\MIB055~1\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\lab2.dir\vector\DynamicArray.c.obj /FdCMakeFiles\lab2.dir\ /FS -c C:\Users\User\Desktop\a23-913-FILIP-ANDA\vector\DynamicArray.c
<<

CMakeFiles\lab2.dir\vector\DynamicArray.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lab2.dir/vector/DynamicArray.c.i"
	C:\PROGRA~2\MIB055~1\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe > CMakeFiles\lab2.dir\vector\DynamicArray.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\User\Desktop\a23-913-FILIP-ANDA\vector\DynamicArray.c
<<

CMakeFiles\lab2.dir\vector\DynamicArray.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lab2.dir/vector/DynamicArray.c.s"
	C:\PROGRA~2\MIB055~1\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\lab2.dir\vector\DynamicArray.c.s /c C:\Users\User\Desktop\a23-913-FILIP-ANDA\vector\DynamicArray.c
<<

# Object files for target lab2
lab2_OBJECTS = \
"CMakeFiles\lab2.dir\main.c.obj" \
"CMakeFiles\lab2.dir\domain\Estate.c.obj" \
"CMakeFiles\lab2.dir\repository\Repository.c.obj" \
"CMakeFiles\lab2.dir\service\Service.c.obj" \
"CMakeFiles\lab2.dir\ui\Ui.c.obj" \
"CMakeFiles\lab2.dir\vector\DynamicArray.c.obj"

# External object files for target lab2
lab2_EXTERNAL_OBJECTS =

lab2.exe: CMakeFiles\lab2.dir\main.c.obj
lab2.exe: CMakeFiles\lab2.dir\domain\Estate.c.obj
lab2.exe: CMakeFiles\lab2.dir\repository\Repository.c.obj
lab2.exe: CMakeFiles\lab2.dir\service\Service.c.obj
lab2.exe: CMakeFiles\lab2.dir\ui\Ui.c.obj
lab2.exe: CMakeFiles\lab2.dir\vector\DynamicArray.c.obj
lab2.exe: CMakeFiles\lab2.dir\build.make
lab2.exe: CMakeFiles\lab2.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\User\Desktop\a23-913-FILIP-ANDA\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking C executable lab2.exe"
	"C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\lab2.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\mt.exe --manifests  -- C:\PROGRA~2\MIB055~1\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\lab2.dir\objects1.rsp @<<
 /out:lab2.exe /implib:lab2.lib /pdb:C:\Users\User\Desktop\a23-913-FILIP-ANDA\cmake-build-debug\lab2.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\lab2.dir\build: lab2.exe

.PHONY : CMakeFiles\lab2.dir\build

CMakeFiles\lab2.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\lab2.dir\cmake_clean.cmake
.PHONY : CMakeFiles\lab2.dir\clean

CMakeFiles\lab2.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\User\Desktop\a23-913-FILIP-ANDA C:\Users\User\Desktop\a23-913-FILIP-ANDA C:\Users\User\Desktop\a23-913-FILIP-ANDA\cmake-build-debug C:\Users\User\Desktop\a23-913-FILIP-ANDA\cmake-build-debug C:\Users\User\Desktop\a23-913-FILIP-ANDA\cmake-build-debug\CMakeFiles\lab2.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\lab2.dir\depend

