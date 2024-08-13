cmake_minimum_required(VERSION 3.0)
project(C)

set(CMAKE_CXX_STANDARD 17)

add_custom_target(GEN_H
	DEPENDS ${PROJECT_SOURCE_DIR}/A/preparing.py
	COMMAND python ${PROJECT_SOURCE_DIR}/A/preparing.py ${PROJECT_SOURCE_DIR}/A/index.h
	OUTPUT ${PROJECT_SOURCE_DIR}/A/index.h
	COMMENT "Creating header"
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

add_executable(C ${PROJECT_SOURCE_DIR}/C/main.cpp)
add_subdirectory(${PROJECT_SOURCE_DIR}/B)
target_link_libraries(C lib)
include_directories(${PROJECT_SOURCE_DIR}/C)
include_directories(${PROJECT_SOURCE_DIR})

add_dependencies(C GEN_H)