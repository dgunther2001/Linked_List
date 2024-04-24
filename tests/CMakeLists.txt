project(generic_ll)

set(EXECUTABLE_OUTPUT_PATH ../)

add_executable(test test.cpp)

target_link_libraries(test PRIVATE linked_list)