CMAKE_MINIMUM_REQUIRED(VERSION 3.14 FATAL_ERROR)
PROJECT(Dolly LANGUAGES CXX)

# Define the TARGET: Levin::Framework
ADD_SUBDIRECTORY(Dependency/Levin)

ADD_LIBRARY(Dolly STATIC
        Source/Graphics/Pixel.cpp
        Source/Application.cpp
        Source/Drawable.cpp
        Source/Client.cpp
        Source/Core.cpp
        )
SET_TARGET_PROPERTIES(Dolly PROPERTIES CXX_STANDARD 17)
TARGET_LINK_LIBRARIES(Dolly PRIVATE Levin::Framework)
TARGET_INCLUDE_DIRECTORIES(Dolly PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Include/>)

ADD_EXECUTABLE(Dolly.App Main.cpp)
SET_TARGET_PROPERTIES(Dolly.App PROPERTIES CXX_STANDARD 17)
TARGET_LINK_LIBRARIES(Dolly.App PRIVATE Dolly)


# Try to find X11 on UNIX systems.
FIND_PACKAGE(X11)

# True if X11 is available
IF (X11_FOUND)
    # Link against these to use X11
    TARGET_LINK_LIBRARIES(Dolly PRIVATE ${X11_LIBRARIES})
    # Include directories to use X11
    TARGET_INCLUDE_DIRECTORIES(Dolly PRIVATE ${X11_INCLUDE_DIR})
ELSE ()
    MESSAGE(FATAL_ERROR "Not is possible found X11 in the System.")
ENDIF ()