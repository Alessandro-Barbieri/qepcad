FILE(GLOB SACLIB_SRC
IPFZT.c
IPFZT1.c
IPPSCT.c
IPRNEVAL.c
RVSPTSVSP.c
SOSRSUBS.c
SOSRSUPS.c
SUBSET.c
)

set_source_files_properties(${SACLIB_SRC} PROPERTIES LANGUAGE CXX)
add_library(qepcadsaclib OBJECT ${SACLIB_SRC})
set_target_properties(qepcadsaclib PROPERTIES LANGUAGE CXX)
target_include_directories(qepcadsaclib
        PUBLIC
        /usr/include/saclib
        ${CMAKE_SOURCE_DIR}/source
        PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
)

target_sources(libqepcad PRIVATE $<TARGET_OBJECTS:qepcadsaclib>)
