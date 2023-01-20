cmake_minimum_required(VERSION 3.9)

project(playground)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS ON)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -mfpmath=sse -Werror=unused-but-set-variable")
    if (WIN32)
        SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-error=misleading-indentation")
    endif (WIN32)
elseif ("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Zi -Z7 /diagnostics:classic -Xclang -fgnu-keywords")
    include_directories(${MSVC_INCLUDE} ${WINKIT_INCLUDE}/ucrt ${WINKIT_INCLUDE}/shared ${WINKIT_INCLUDE}/um)
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
  # using Visual Studio C++
endif()

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    set(GLOBAL_LFLAGS "-Wl,--warn-common -Wl,--demangle")
elseif ("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
    set(GLOBAL_LFLAGS "/MACHINE:x64")
endif()

file(GLOB sources "playground.C")

add_executable(${PROJECT_NAME} ${sources})

#include_directories(.. ${Qt5Core_INCLUDE_DIRS} ${Qt5Widgets_INCLUDE_DIRS})

#target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Core Qt5::Widgets)




