project(generic_ll)

add_library(linked_list SHARED linked_list.cpp)

target_include_directories(linked_list PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)