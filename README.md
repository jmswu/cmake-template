# C/C++ GTEST CMAKE-TEMPLATE #
### Introduction ###
* Cmake template for using GTest
* With cppcheck support (optional)
* With clang-tidy support (optional)
* With conan c/c++ package manager

### Depandancies ###
* [conan](https://conan.io/)
* [clang-tidy](https://clang.llvm.org/extra/clang-tidy/)

### Installation ###
* Clone this repo with `git clone https://github.com/jmswu/cmake-template.git`
* Put test source files in `my_lib` folder
* Change `CppCheckSuppressions.txt` path to your path (optional, if using cppcheck)
* Edit `.clang-tidy` for the checks you use

### Build ###
* run `mkdir build && cd build`
* run `conan install ..` to install c/c++ library
* run `cmake ..`
* run `make`

### Run tests ###
* run `cd build`
* run `ctest`

