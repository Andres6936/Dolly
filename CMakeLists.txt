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

ADD_EXECUTABLE(Dolly Main.cpp Include/Client.cpp Include/Client.hpp Include/Application.cpp Include/Application.hpp Include/Core.cpp Include/Core.hpp Include/Drawable.cpp Include/Drawable.hpp)
TARGET_LINK_LIBRARIES(Dolly PRIVATE X11)
TARGET_LINK_LIBRARIES(Dolly PRIVATE Levin)