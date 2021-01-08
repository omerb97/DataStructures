cmake_minimum_required(VERSION 3.15)
project(Wet1)

set(CMAKE_CXX_STANDARD 11)

add_executable(Wet1 main.cpp library2.h ListNode.h List.h HashTable.h Class.h Class.cpp Course.h Course.cpp
        AVLRankTree.h CoursesManager.h CoursesManager.cpp Exceptions.cpp Exceptions.h library2.cpp)