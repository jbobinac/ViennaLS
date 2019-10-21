# ViennaLS

ViennaLS is a header-only C++ level set library developed for high performance topography simulations. The main design goals are simplicity and efficiency, tailored towards scientific simulations. ViennaLS can also be used for visualisation applications, although this is not the main design target.

IMPORTANT NOTE: ViennaLS is under heavy development and improved daily. If you do have suggestions or find bugs, please let us know!

## Support
For help with getting started, have a look at the [Examples](https://github.com/ViennaTools/ViennaLS/tree/master/Examples).

Bug reports and suggestions should be filed on GitHub.

## Contributing
If you want to contribute to ViennaLS, make sure to follow the [LLVM Coding guidelines](https://llvm.org/docs/CodingStandards.html). Before creating a pull request, make sure ALL files have been formatted by clang-format, which can be done using the format-project.sh script in the root directory.

## Releases
Releases are tagged on the maser branch and available in the [releases section](https://github.com/ViennaTools/ViennaLS/releases).

## Building

### System Requirements

* C++ Compiler with OpenMP support
* [ViennaHRLE](https://github.com/ViennaTools/viennahrle)

### Installing

Since this is a header only project, it does not require any installation.
However, we recommend the following procedure.

Make sure you have [ViennaHRLE](https://github.com/ViennaTools/viennahrle) installed on your system and run:

```
git clone github.com/ViennaTools/ViennaLS.git
cd ViennaLS
mkdir build && cd build
cmake .. -DCMAKE_INSTALL_PREFIX=/path/to/your/custom/install/
make install
```

This will install the necessary headers and CMake files to the specified path. If DCMAKE_INSTALL_PREFIX is not specified, it will be installed to the standard path for your system, usually /usr/local/ .

In order to save build time during developement, shared libraries are built by default. This can be disabled by setting the CMake option VIENNALS_BUILD_SHARED_LIBS=OFF .


### Building examples

The examples can be built using CMake:

```
mkdir build && cd build
cmake .. -DVIENNALS_BUILD_EXAMPLES=ON
make
```

### Integration in CMake projects

In order to use this library in your CMake project, add the following lines to the CMakeLists.txt of your project:\
(also do not forget to include ViennaHRLE)

```
set(ViennaLS_DIR "/path/to/your/custom/install/")
find_package(ViennaLS REQUIRED)
add_executable(...)
target_include_directories(${PROJECT_NAME} PUBLIC ${VIENNALS_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${VIENNALS_LIBRARIES})
```

### Shared libraries

In order to save build time during developement, dynamically linked shared libraries are used
if ViennaLS was built with them. In order to build releases with better runtime performance, but
longer build times, the CMake option VIENNALS_USE_SHARED_LIBS=OFF should be used.

## Authors

Current contributors: Lado Filipovic, Paul Manstetten, Xaver Klemenschits and Josef Weinbub

Founder and initial developer: Otmar Ertl

Contact us via: viennats@iue.tuwien.ac.at

ViennaLS was developed under the aegis of the 'Institute for Microelectronics' at the 'TU Wien'.
http://www.iue.tuwien.ac.at/

License
--------------------------
See file LICENSE in the base directory.
