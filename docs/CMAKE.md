# What is CMake?

Cmake is a cross-platform tool that automates a build process for projects. CMake, in itself, is not a build system, but rather a build-system generator. Cmake can be used to build makefiles, project files for IDEs, and various other build scripts

# What is the minimum possible setup to use cmake?

The most minimum cmake setup is compiling a lone executable. All you need is a CmakeLists.txt

CmakeLists.txt:
```project( "project name" )```

```add_executable( "name" "sourcefile")```

# How to compile applications that use cmake?

* Use the Cmake command pathed to the source dir: 
```$cmake /path/to/source ```

* Then call the build files that were generated: 
```$make```

* The cmake Program is now compiled
