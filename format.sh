#!/bin/bash
find ./ -name "*.cc" -o -name "*.c" -o -name "*.h" -o -name "*.cpp" -o -name "*.hpp" -o -name "*.CPP"| xargs clang-format -style=LLVM -i
