enable_language(CUDA)
set(src unique_ptr_test.cc unique_ptr_with_cudaMalloc.cc unique_ptr_with_cudaMalloc_2.cc)
foreach(src_file ${src})
    get_filename_component(bin_name ${src_file} NAME_WE)
    add_executable(${bin_name} ${src_file})
    target_link_libraries(${bin_name} PRIVATE cudart)
endforeach()
