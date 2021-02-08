CMAKE_MINIMUM_REQUIRED(VERSION 3.14 FATAL_ERROR)
PROJECT(Dolly LANGUAGES CXX)

# With its we can include the header of libraries
INCLUDE_DIRECTORIES(Library)
# Here find the library Levin for purpose of log
LINK_DIRECTORIES(${CMAKE_SOURCE_DIR}/Library/Levin)

ADD_LIBRARY(Dolly STATIC
        Include/Graphics/Pixel.cpp
        Include/Application.cpp
        Include/Drawable.cpp
        Include/Client.cpp
        Include/Core.cpp
        )
SET_TARGET_PROPERTIES(Dolly PROPERTIES CXX_STANDARD 17)
TARGET_LINK_LIBRARIES(Dolly PRIVATE X11)
TARGET_LINK_LIBRARIES(Dolly PRIVATE Levin)
TARGET_INCLUDE_DIRECTORIES(Dolly PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Include/>)

ADD_EXECUTABLE(Dolly.App Main.cpp)
TARGET_LINK_LIBRARIES(Dolly.App PRIVATE Dolly)