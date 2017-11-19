cmake_minimum_required(VERSION 3.5)
project(glut_acm_practice)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ./bin)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3  -Wall -pedantic")
set(SOURCE_FILES
        src/01pack_v1.0.cpp
        src/8queen.cpp
        src/poj3299_WA.cpp
        src/poj_1007_40percentAC.cpp
        src/poj_1590_33percentAC.cpp
        src/poj_2386_49percentAC.cpp
        src/poj_2538_47percentAC.cpp
        src/poj_3278_31percentAC.cpp
        src/poj_3979_30percentAC.cpp
        src/solution1.cpp
        src/solution2.cpp
        src/solution3.cpp
        src/solution4.cpp
        src/solution5.cpp
        src/solution6.cpp
        src/solution8.cpp)

foreach( sourcefile ${SOURCE_FILES} )
    string( REPLACE ".cpp" "" exename ${sourcefile} )
    string( REPLACE "src/" "" exename ${exename} )
    add_executable( ${exename} ${sourcefile} )
endforeach( sourcefile ${SOURCE_FILES} )

enable_testing()
foreach( testfile ${SOURCE_FILES} )
    string( REPLACE ".cpp" "" testname ${testfile} )
    string( REPLACE "src/" "" testname ${testname} )
    add_test(NAME test_running__${testname} COMMAND sh -c "../bin/${testname} < ../test/${testname}.data > ../test/${testname}.result")
endforeach( testfile ${SOURCE_FILES} )