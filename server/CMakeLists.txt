# CMakeList.txt : CMake project for test_work, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (server "server.cpp" "server.h" "../core/table.cpp" "../core/table.h" "../core/column.cpp" "../core/column.h" "../core/platform_server.h" "../core/platform_server.cpp" "monkey.h" "monkey.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET server PROPERTY CXX_STANDARD 17)
endif()

target_link_libraries(server core)

# TODO: Add tests and install targets if needed.
