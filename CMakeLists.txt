cmake_minimum_required(VERSION 3.28)

project(monkeymarket)

find_package(raylib)

file(GLOB SOURCES src/*.c src/widgets/*.c)
file(GLOB HEADERS src/*.h src/**/*.h)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
