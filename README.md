# CMAKE-TEMPLATE #
### Introduction ###
* cmake template for using GTest
* With cppcheck support
* With clang-tidy support

### Depandancies ###
* conan
* clang-tidy

### Installation ###
* clone this repo with `git clone https://github.com/jmswu/cmake-template.git`
* put test source files in `my_lib` folder
* change `CppCheckSuppressions.txt` path to your path (optional)

### Build ###
* run `mkdir build && cd build`
* run `conan install ..`
* run `cmake ..`
* run `make

### Run tests ###
* run `cd build`
* run `ctest`
