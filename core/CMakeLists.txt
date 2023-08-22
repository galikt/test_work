# CMakeList.txt : CMake project for test_work, include source and define
# project specific logic here.
#

# Add source to this project's executable.
#add_executable (core "core.cpp" "core.h")
add_library(core STATIC "core.h" "platform.h" "platform.cpp" "replication.h" "replication.cpp" "gate.h" "gate.cpp" "messenger.h" "messenger.cpp" "message.h" "message.cpp" "wrapper.h" "wrapper.cpp" "object.h" "object.cpp" "object_container.h" "object_container.cpp" "buffer.h" "buffer.cpp" "serialization.cpp" "meta_object.cpp" "string.h" "string.cpp" "row.h" "row.cpp"   "table_view.cpp")

#add_library(core::core ALIAS core)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET core PROPERTY CXX_STANDARD 17)
endif()

# TODO: Add tests and install targets if needed.
