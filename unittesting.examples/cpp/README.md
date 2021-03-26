# A Unit Testing Example in C++

## Steps

### Install dependencies

This example will be using cmake as a build system, vcpkg as pacakge manager. Make sure you have [CMake](https://cmake.org/download/), and vcpkg installed. For CMake, you can download the installer from the website or use your package manager to install it. Instruction for how to install vcpkg for each OSes can be found in the [Getting Started](https://github.com/microsoft/vcpkg#getting-started) section. Generally, you clone the respository down and run bootstrap-vcpkg of your operating system. During the setup it will compile the source code of the pacakges, so make sure that you following the steps to install developer tools.

Install the curlpp library by running

```shell
$ ./vcpkg/vcpkg install curlpp
```

This will take quite some time since it will compile every libraries from scratch. During this we can set up our CMakeLists.txt. First create a directory `src` and create new file and name it `CMakeLists.txt`. Put the following content in this new file:

```cmake
add_executable(main main.cc)
```

This is telling CMake that an executable main is from source code main.cc.

Create another `CMakeLists.txt`, this time on your project root directory (just outside of `src` directory) with the following content

```cmake
cmake_minimum_required(VERSION 3.10)

project(UnitTestingExample CXX)

add_subdirectory(src)
```

The first line state that this project need CMake to be at least 3.10. The second line define the project. The last line add our source code directory to the project.

For a tutorial on CMake, you can refer to this [webpage](https://cmake.org/cmake/help/latest/guide/tutorial/index.html). For the commands (show in each of the lines above), see this [page](https://cmake.org/cmake/help/v3.19/manual/cmake-commands.7.html)

To verify that your setup work, let create a simple hello world C++ program `src/main.cc` with the following content.

```cpp
#include <iostream>

int main(int argc, char **argv) {
  std::cout << "Hello, World!" << std::endl;
  return EXIT_SUCCESS;
}
```

Now run `cmake -S . -B build` (on your root directory of the project; not in src directory). Now if you cd into build directory, run make, and run the program we should get the following result.

```shell
$ cd build
$ make
Scanning dependencies of target main
[ 50%] Building CXX object CMakeFiles/main.dir/main.cc.o
[100%] Linking CXX executable main
[100%] Built target main
$ ./src/main
Hello, World!
```

If everything work, let prepare a commit. First of, let create .gitignore with the content from [https://www.toptal.com/developers/gitignore/api/c++,cmake](https://www.toptal.com/developers/gitignore/api/c++,cmake):

```plain

# Created by https://www.toptal.com/developers/gitignore/api/c++,cmake
# Edit at https://www.toptal.com/developers/gitignore?templates=c++,cmake

### C++ ###
# Prerequisites
*.d

# Compiled Object files
*.slo
*.lo
*.o
*.obj

# Precompiled Headers
*.gch
*.pch

# Linker files
*.ilk

# Debugger Files
*.pdb

# Compiled Dynamic libraries
*.so
*.dylib
*.dll

# Fortran module files
*.mod
*.smod

# Compiled Static libraries
*.lai
*.la
*.a
*.lib

# Executables
*.exe
*.out
*.app

### CMake ###
CMakeLists.txt.user
CMakeCache.txt
CMakeFiles
CMakeScripts
Testing
Makefile
cmake_install.cmake
install_manifest.txt
compile_commands.json
CTestTestfile.cmake
_deps
CMakeUserPresets.json

### CMake Patch ###
# External projects
*-prefix/

# End of https://www.toptal.com/developers/gitignore/api/c++,cmake
```

Before we add files to the staging area, let also add vcpkg into the .gitignore. It should just be a line of `vcpkg/` at the top of `.gitignore` file. You can add the vcpkg as a submodule as well, but we will not cover how to do that in this example.

Now let write simple application that use curlpp.

```cpp
/**
Base on example at https://github.com/jpbarrette/curlpp/blob/master/examples/example02.cpp
 */
#include <iostream>
#include <string>
#include <cstring>
#include <list>
#include <sstream>

#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <curlpp/Exception.hpp>

using namespace std;

int main(int argc, char **argv) {
  ostringstream os;
  string url = "https://httpbin.org/get";

  try {
    curlpp::Cleanup cleaner;
    curlpp::Easy request;

    list<string> headers;
    headers.push_back("Content-Type: application/json");

    request.setOpt(new curlpp::Options::Verbose(false));
    request.setOpt(new curlpp::Options::HttpHeader(headers));
    request.setOpt(new curlpp::Options::WriteStream(&os));
    request.setOpt(new curlpp::Options::Url(url));

    request.perform();

    cout << os.str() << std::endl;
  } catch (curlpp::LogicError & e) {
    cout << e.what() << std::endl;
  } catch (curlpp::RuntimeError & e) {
    cout << e.what() << std::endl;
  }
  return EXIT_SUCCESS;
}
```

Since we are using curlpp, we need to modify both CMakeLists.txt files. The first file at the top level of the project should now look like this.

```cmake
cmake_minimum_required(VERSION 3.10)

set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake
  CACHE STRING "Vcpkg toolchain file")

project(UnitTestingExample CXX)

add_subdirectory(src)
```

The one in the `src` directory should now look like this

```cmake
add_executable(main main.cc)

find_package(unofficial-curlpp CONFIG REQUIRED)
target_link_libraries(main PRIVATE unofficial::curlpp::curlpp)
```

Since we are modifying CMakeLists.txt, we need to reconfigure the project by remove the build directory and rerun `cmake -S . -B build` on the top level of the project.

```plain
-- The CXX compiler identification is GNU 10.2.0
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Looking for C++ include pthread.h
-- Looking for C++ include pthread.h - found
-- Performing Test CMAKE_HAVE_LIBC_PTHREAD
-- Performing Test CMAKE_HAVE_LIBC_PTHREAD - Failed
-- Looking for pthread_create in pthreads
-- Looking for pthread_create in pthreads - not found
-- Looking for pthread_create in pthread
-- Looking for pthread_create in pthread - found
-- Found Threads: TRUE  
-- Found OpenSSL: /home/krerkkiat/class/cs3560-fall-2020-2021-ta/repos/examples/unittesting.examples/cpp/vcpkg/installed/x64-linux/debug/lib/libcrypto.a (found suitable version "1.1.1h", minimum required is "1")  
-- Found ZLIB: /home/krerkkiat/class/cs3560-fall-2020-2021-ta/repos/examples/unittesting.examples/cpp/vcpkg/installed/x64-linux/debug/lib/libz.a (found suitable version "1.2.11", minimum required is "1") 
-- Configuring done
-- Generating done
-- Build files have been written to: /home/krerkkiat/class/cs3560-fall-2020-2021-ta/repos/examples/unittesting.examples/cpp/build
```

Now we can recompile and run the program again.

```shell
$ cd build
$ make
Scanning dependencies of target main
[ 50%] Building CXX object src/CMakeFiles/main.dir/main.cc.o
[100%] Linking CXX executable main
[100%] Built target main
$ ./src/main
{
  "args": {}, 
  "headers": {
    "Accept": "*/*", 
    "Content-Type": "application/json", 
    "Host": "httpbin.org", 
  }, 
  "origin": "127.0.0.1", 
  "url": "https://httpbin.org/get"
}
```

Now that we can read response, let parse it into JSON object. We will be using nlohmann/json library that can be installed by

```shell
$ ./vcpkg/vcpkg install nlohmann-json
```

Then add the following two lines into CMakeLists.txt inside src directory.

```cmake
find_package(nlohmann_json CONFIG REQUIRED)
target_link_libraries(main PRIVATE nlohmann_json nlohmann_json::nlohmann_json)
```

For our main.cpp, we need to add

```cpp
#include <nlohmann/json.hpp>

using json = nlohmann::json;
```

Then we can parse the output data into JSON object.

```cpp
    // Existing code.
    request.perform();
    
    auto data = json::parse(os.str());
    
    cout << data["headers"] << endl;
```

Now we should have everything to handle Twitter API call.
