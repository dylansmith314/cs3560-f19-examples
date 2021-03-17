# Discord Bot using Aegis

1. Clone the source code of Aegis.cpp down

   ```console
   git clone --recursive https://github.com/zeroxs/aegis.cpp.git
   ```

2. Install vcpkg

   Get into project folder. Run
   
   ```console
   git clone https://github.com/microsoft/vcpkg
   .\vcpkg\bootstrap-vcpkg.bat
   ```

3. Install openssl, zlib

   ```console
   .\vcpkg\vcpkg.exe install openssl:x64-windows zlib:x64-windows
   ```

   Other useful commands.
   ```console
   .\vcpkg\vcpkg.exe list
   .\vcpkg\vcpkg.exe remove openssl zlib
   ```

4. Open the folder in Visual Studio. There will be an error, this is ecpected.

5. Edit the CMakeLists.txt's settings.

   Right click on the CMakeLists.txt and click on CMake Settings

   Change the `Configuration type` to `Release`.

   Change CMake toolchain file to a full path to vcpkg.cmake e.g.

   ```plain
   ${projectDir}/vcpkg/scripts/buildsystems/vcpkg.cmake
   ```

   Add `-DMSVC=1 -DBUILD_SHARED_LIBS=0` to "CMake command arguments" under "Command arguments"

   Save the file. Visual Studio should start cmake generation process again.
   This time there should be no error.
