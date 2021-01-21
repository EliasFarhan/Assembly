cmake_minimum_required(VERSION 3.9)
project(Assembly)
enable_language(ASM_NASM)

find_package(benchmark CONFIG REQUIRED)
#target_link_libraries(main PRIVATE benchmark::benchmark benchmark::benchmark_main)

find_package(GTest CONFIG REQUIRED)

IF(MSVC)
    file(GLOB_RECURSE ASM_FILES asm/win/*.asm)
ELSE()
    file(GLOB_RECURSE ASM_FILES asm/unix/*.asm)
ENDIF()
foreach(asm_file ${ASM_FILES})
    get_filename_component(asm_name ${asm_file} NAME)
    set(output_file ${CMAKE_BINARY_DIR}/asm/${asm_name}.o)
    list(APPEND asm_out ${output_file})
    add_custom_command(OUTPUT ${asm_name}.o COMMAND ${YASM_EXE}
            ARGS -f elf64 -o ${CMAKE_BINARY_DIR}/asm/${asm_name}.o ${asm_file})
endforeach()

add_library(ASM_LIB ${ASM_FILES})
set_target_properties(ASM_LIB PROPERTIES LINKER_LANGUAGE CXX)

file(GLOB_RECURSE SRC_FILES src/*.cpp include/*.h)
add_library(Common ${SRC_FILES})
target_link_libraries(Common PUBLIC ASM_LIB)
target_include_directories(Common PUBLIC include/)
IF(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /arch:AVX2 /Oi /Oy-")
else()
    set_target_properties(Common PROPERTIES COMPILE_FLAGS "-save-temps=obj -masm=intel -march=haswell -ffast-math -fno-omit-frame-pointer")
ENDIF()


SET(COURSE_DIR ${CMAKE_SOURCE_DIR}/test)
file(GLOB COURSE_FILES ${COURSE_DIR}/*.cpp )

foreach(course_file ${COURSE_FILES} )
    # I used a simple string replace, to cut off .cpp.
    file(RELATIVE_PATH course_relative_path ${COURSE_DIR} ${course_file})
    string( REPLACE ".cpp" "" course_name ${course_relative_path} )
    add_executable(${course_name} ${course_file})
    # Make sure YourLib is linked to each app
    target_link_libraries(${course_name} PUBLIC Common)

    target_link_libraries(${course_name} PRIVATE GTest::gtest GTest::gtest_main)
    set_property(TARGET ${course_name} PROPERTY CXX_STANDARD 20)


    IF(MSVC)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /arch:AVX2 /Oi /Oy-")
    else()
        set_target_properties(${course_name} PROPERTIES COMPILE_FLAGS "-save-temps -march=haswell -ffast-math -fno-omit-frame-pointer")
    ENDIF()
    set_target_properties (${course_name} PROPERTIES
            FOLDER Courses)
endforeach()