cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(Tutorial VERSION 1.0)

# add optionality of using library
option(USE_MYMATH "Use tutorial provided math implementation" ON)

# configure header file
configure_file(TutorialConfig.h.in TutorialConfig.h)

# add required configuration
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add the MathFunctions library
if(USE_MYMATH)
    add_subdirectory(MathFunctions)
    list(APPEND EXTRA_LIBS MathFunctions)
    list(APPEND EXRTA_INCLUDES "${PROJECT_SOURCE_DIR}/MathFunctions")
endif()

# add the executable
add_executable(Tutorial tutorial.cpp)

target_link_libraries(Tutorial PUBLIC ${EXTRA_LIBS})

target_include_directories(Tutorial PUBLIC
                            "${PROJECT_BINARY_DIR}"
                            "${EXTRA_INCLUDES}"
                            )