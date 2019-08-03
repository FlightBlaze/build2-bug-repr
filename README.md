# The reproduction of build2's heuristics bug

Building
```
git clone https://github.com/FlightBlaze/build2-bug-repr.git
cd build2-bug-repr
bdep init -C ../bug-build-clang cc config.cxx=clang++
b
```
