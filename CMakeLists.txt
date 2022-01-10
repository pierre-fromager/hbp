cmake_minimum_required (VERSION 2.8)
project (Hbp)

file (GLOB_RECURSE Hbp_SOURCES CONFIGURE_DEPENDS "src/*.cpp")
file (GLOB_RECURSE Hbp_HEADERS CONFIGURE_DEPENDS "include/*.h")

set (Hbp_INCLUDE_DIRS "")
foreach (_headerFile ${Hbp_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND Hbp_INCLUDE_DIRS ${_dir})
endforeach()
list (REMOVE_DUPLICATES Hbp_INCLUDE_DIRS)

add_executable(hbp ${Hbp_SOURCES})
target_include_directories(hbp PRIVATE ${Hbp_INCLUDE_DIRS})

include_directories(${Hbp_INCLUDE_DIRS})
add_library (hbp_lib ${Hbp_SOURCES} ${Hbp_INCLUDE_DIRS})
target_link_libraries(hbp hbp_lib)

enable_testing ()
add_subdirectory (test)