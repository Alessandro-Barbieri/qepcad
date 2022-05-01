FILE(GLOB SORT_SRC
GIS.c
GISL.c
GMS.c
GMSL.c
GMSDS.c
GMSDSL.c
BVC.c
BVIS.c
BVCI1.c
BVISI1.c
)

set_source_files_properties(${SORT_SRC} PROPERTIES LANGUAGE CXX)
add_library(sort OBJECT ${SORT_SRC})
set_target_properties(sort PROPERTIES LANGUAGE CXX)
target_include_directories(sort
        PUBLIC
        /usr/include/saclib
        ${CMAKE_SOURCE_DIR}/source/
        ${CMAKE_SOURCE_DIR}/extensions/sfext
)

target_sources(libqepcad PRIVATE $<TARGET_OBJECTS:sort>)
