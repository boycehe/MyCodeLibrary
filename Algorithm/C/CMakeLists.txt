cmake_minimum_required(VERSION 3.13)
project(algorithm)
include_directories("${PROJECT_SOURCE_DIR}/C")

aux_source_directory(${PROJECT_SOURCE_DIR}/C WADATA_LIB_HTTP_PARSER)
add_library(wadatahttpparser ${WADATA_LIB_HTTP_PARSER} C/he_sort.c C/he_sort.h C/he_search.h)

add_executable(libdatabee C/main.c)
target_link_libraries(libdatabee wadatahttpparser)


