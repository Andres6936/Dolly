CMAKE_MINIMUM_REQUIRED(VERSION 3.15)
PROJECT(Dolly)

SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_CXX_EXTENSIONS OFF)

INCLUDE_DIRECTORIES(Include)

# With its we can include the header of libraries
INCLUDE_DIRECTORIES(Library)
# Here find the library Levin for purpose of log
LINK_DIRECTORIES(${CMAKE_SOURCE_DIR}/Library/Levin)

ADD_EXECUTABLE(Dolly Main.cpp
        Include/Graphics/Pixel.cpp
        Include/Application.cpp
        Include/Drawable.cpp
        Include/Client.cpp
        Include/Core.cpp
        )
TARGET_LINK_LIBRARIES(Dolly PRIVATE X11)
TARGET_LINK_LIBRARIES(Dolly PRIVATE Levin)