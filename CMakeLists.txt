cmake_minimum_required(VERSION 3.16)

project(cplusplus_learning
	LANGUAGES CXX CUDA)

include(cmake/util.cmake)
sub_dir_list(sub_dirs ${CMAKE_CURRENT_SOURCE_DIR})
list(REMOVE_ITEM sub_dirs ".git" "cmake")

foreach(sub_dir ${sub_dirs})
    add_subdirectory(${sub_dir})
endforeach()

#add_subdirectory(charpter_0001)
#add_subdirectory(charpter_0002)
#add_subdirectory(variadic_template)
#add_subdirectory(getenv)
