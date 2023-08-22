# CMakeList.txt : CMake project for test_work, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (client "client.cpp" "client.h" "../core/platform_client.h" "../core/platform_client.cpp" "../core/table.cpp" "../core/table.h" "../core/column.h" "../core/column.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET client PROPERTY CXX_STANDARD 17)
endif()

target_link_libraries(client core)

# TODO: Add tests and install targets if needed.
