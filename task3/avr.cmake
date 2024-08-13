cmake_minimum_required(VERSION 3.0)

if (${CMAKE_SYSTEM_PROCESSOR} MATCHES "arm")
	set(CMAKE_CXX_COMPILER ${TOOLCHAIN}/aarch64-linux-gnu-g++)
endif()

project(SimpleLibrary VERSION 1.2.3.4 LANGUAGES CXX)


set(CMAKE_SKIP_BUILD_RPATH FALSE)
set(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

include_directories(include)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${SimpleLibrary_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${SimpleLibrary_SOURCE_DIR}/lib)

install(FILES include/buffer.h
		DESTINATION include)

add_subdirectory(src)
add_executable(Main main.cpp)
add_executable(MainLib main_lib.cpp)

install(TARGETS Main MainLib
		RUNTIME DESTINATION bin)

target_link_libraries(MainLib buffer)
