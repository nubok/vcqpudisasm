cmake_minimum_required(VERSION 3.0)

project(vcqpudisasm)

find_path(MESA_SOURCE_DIR src/broadcom/qpu/qpu_disasm.h)

if (MESA_SOURCE_DIR)
    message(STATUS "Source files of Mesa are found in ${MESA_SOURCE_DIR}")
else ()
    message(FATAL_ERROR "Source directory of Mesa is not found")
endif ()

find_path(MESA_BUILD_DIR src/broadcom/qpu/libbroadcom_qpu.a)

if (MESA_BUILD_DIR)
    message(STATUS "Build files of Mesa are found in ${MESA_BUILD_DIR}")
else ()
    message(FATAL_ERROR "Build directory of Mesa is not found")
endif ()

add_compile_options(-pipe -g -O2 -W -Wall -Wextra)

add_executable(vc6qpudisasm vc6qpudisasm.c)
target_include_directories(vc6qpudisasm PRIVATE
        ${MESA_SOURCE_DIR}/src
        ${MESA_SOURCE_DIR}/include)
target_link_libraries(vc6qpudisasm
        ${MESA_BUILD_DIR}/src/broadcom/qpu/libbroadcom_qpu.a
        ${MESA_BUILD_DIR}/src/util/libmesa_util.a
        stdc++)

add_executable(vc4qpudisasm vc4qpudisasm.c)
target_include_directories(vc4qpudisasm PRIVATE
        ${MESA_SOURCE_DIR}/src
        ${MESA_SOURCE_DIR}/include)
target_link_libraries(vc4qpudisasm
        ${MESA_BUILD_DIR}/src/gallium/drivers/vc4/libvc4.a)
