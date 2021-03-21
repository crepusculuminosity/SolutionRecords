#!/bin/bash
find ./ -name "*.cc" | xargs clang-format -style=LLVM -i
