set(src getenv.cc)

foreach(src_file ${src})
    get_filename_component(bin_name ${src_file} NAME_WE)
    add_executable(${bin_name} ${src_file})
endforeach()
