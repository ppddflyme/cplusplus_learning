set(src
    exerc_1_1.cc
    exerc_1_2.cc
    exerc_1_3.cc
    exerc_1_4.cc
    exerc_1_16.cc
    exerc_1_20.cc
    exerc_1_21.cc
    exerc_1_22.cc)
foreach(src_file ${src})
    get_filename_component(bin_name ${src_file} NAME_WE)
    add_executable(${bin_name} ${src_file})
endforeach()
