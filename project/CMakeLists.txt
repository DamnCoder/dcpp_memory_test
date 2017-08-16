CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

#[PROJECT_NAME]
PROJECT(DCPPMemoryTest)

#[BUILD_TYPE]
SET(CMAKE_BUILD_TYPE Debug)

# Set the output folders where the program will be created
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/../cmake_modules)
SET(CMAKE_INCLUDE_PATH ${PROJECT_SOURCE_DIR}/../cmake_include)
SET(EXTERNALS_PATH ${PROJECT_SOURCE_DIR}/../externals)

INCLUDE(${CMAKE_INCLUDE_PATH}/CMake-Include.txt)

# C++ Dialect
SET(CMAKE_CXX_STANDARD 11) # C++11...
SET(CMAKE_CXX_STANDARD_REQUIRED ON) #...is required...
SET(CMAKE_CXX_EXTENSIONS OFF) #...without compiler extensions like gnu++11

#[PRJ_INCLUDE]
INCLUDE_DIRECTORIES(include)
INCLUDE_DIRECTORIES(include/test)

#[PRJ_HEADER_FILES]
SET(HEADERS
	include/test/lineartests.h
	include/test/newdeletetest.h
	include/test/stacktest.h
)

#[PRJ_SOURCE_FILES]
SET(SOURCES
	src/main.cpp
)

# Generate the executable from the sources
ADD_EXECUTABLE(${PROJECT_NAME} ${SOURCES} ${HEADERS})

#[EXTERNAL_PROJECTS]
ADD_SUBDIRECTORY(${EXTERNALS_PATH}/dcpp_memory/project ${PROJECT_BINARY_DIR}/dcpp_memory)
INCLUDE_DIRECTORIES(${EXTERNALS_PATH}/dcpp_memory/project/include)

TARGET_LINK_LIBRARIES(${PROJECT_NAME}
	DCPPMemory
)


# Set the location for executable installation
INSTALL(TARGETS ${PROJECT_NAME} DESTINATION ${EXECUTABLE_OUTPUT_PATH})
