# CMakeList.txt : CMake project for test_work, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (server "server.cpp" "server.h" "table.cpp" "table.h" "column.cpp" "column.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET server PROPERTY CXX_STANDARD 17)
endif()

# TODO: Add tests and install targets if needed.
