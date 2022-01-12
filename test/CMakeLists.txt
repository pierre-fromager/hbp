find_package (Boost COMPONENTS system filesystem unit_test_framework REQUIRED)

include_directories (${Boost_INCLUDE_DIRS})

add_definitions (-DBOOST_TEST_DYN_LINK)

add_executable (
    hbp_test main.cpp 
    suites/humanratios.cpp 
    suites/ellispoid.cpp
    suites/model/ellispoid.cpp)

target_link_libraries (hbp_test 
                        hbp_lib
                       ${Boost_FILESYSTEM_LIBRARY}
                       ${Boost_SYSTEM_LIBRARY}
                       ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
                       )

add_test (NAME MyTest COMMAND hbp_test)