cmake_minimum_required(VERSION 3.16)

project(UnitTests LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME}
    Debug_Tasks.h
    FactorAlgorithm.cpp
    FactorAlgorithm.h
    FactorAnalysis.cpp
    FactorAnalysis.h
    LongNumberVectorResult.cpp
    LongNumberVectorResult.h
    main.cpp
    SubtractAlgorithm.h
    UnitTests.cpp
)

set(LIBRARY "TestLibrary")
target_include_directories(${PROJECT_NAME} PRIVATE ../${LIBRARY})
target_link_libraries(${PROJECT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/../build-${LIBRARY}-Desktop-${CMAKE_BUILD_TYPE}/lib${LIBRARY}.a
    pthread
)
