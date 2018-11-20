cmake_minimum_required(VERSION 3.12)
project(RunJava)

set(CMAKE_CXX_STANDARD 14)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")
add_executable(RunJava main.cpp)


find_package(jvm REQUIRED)
find_package(JNI REQUIRED)
include_directories(${JNI_INCLUDE_DIRS} ${CLASS_PATH_MAIN})


target_link_libraries(${PROJECT_NAME} ${JVM_LIBRARY})








