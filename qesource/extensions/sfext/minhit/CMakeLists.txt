FILE(GLOB MINHIT_SRC
MINHITSET.c
RSFHSP.c
ENUMMINHITSET.c
MINHITSETSR.c
ENUMMINHITSETSR.c
MINHITSETSRDR.c
MINWHITSET.c
)

set_source_files_properties(${MINHIT_SRC} PROPERTIES LANGUAGE CXX)
add_library(minhit OBJECT ${MINHIT_SRC})
set_target_properties(minhit PROPERTIES LANGUAGE CXX)
target_include_directories(minhit
        PUBLIC
        /usr/include/saclib
        ${CMAKE_SOURCE_DIR}/source/
        PRIVATE
        ${CMAKE_SOURCE_DIR}/extensions/sfext
)

target_sources(libqepcad PRIVATE $<TARGET_OBJECTS:minhit>)
