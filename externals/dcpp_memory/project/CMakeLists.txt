CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

#[PROJECT_NAME]
PROJECT(DCPPMemory)

#[BUILD_TYPE]
SET(CMAKE_BUILD_TYPE Debug)

# Set the output folders where the program will be created
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/../cmake_modules)
SET(CMAKE_INCLUDE_PATH ${PROJECT_SOURCE_DIR}/../cmake_include)
SET(EXTERNALS_PATH ${PROJECT_SOURCE_DIR}/../externals)

INCLUDE(${CMAKE_INCLUDE_PATH}/CMake-Include.txt)

#[PRJ_INCLUDE]
INCLUDE_DIRECTORIES(include)
INCLUDE_DIRECTORIES(include/memory)

#[PRJ_HEADER_FILES]
SET(HEADERS
	include/memory/linearallocator.h
	include/memory/memory.h
	include/memory/shortalloc.h
	include/memory/stackallocator.h
)

#[PRJ_SOURCE_FILES]
SET(SOURCES
	src/memory/linearallocator.cpp
	src/memory/memory.cpp
	src/memory/stackallocator.cpp
)

# Generate the static library from the sources
ADD_LIBRARY(${PROJECT_NAME} STATIC ${SOURCES} ${HEADERS})

#[ORGANIZATION]

SOURCE_GROUP_BY_FOLDER("${SOURCES}")
SOURCE_GROUP_BY_FOLDER("${HEADERS}")

#[EXTERNAL_PROJECTS]

SET_TARGET_PROPERTIES(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)
 
# Set the location for library installation
# Use "sudo make install" to apply
INSTALL(TARGETS ${PROJECT_NAME} DESTINATION ${LIBRARY_OUTPUT_PATH})
INSTALL(DIRECTORY ${PROJECT_SOURCE_DIR}/include DESTINATION ${LIBRARY_OUTPUT_PATH})
