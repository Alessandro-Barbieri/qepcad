FILE(GLOB UTIL_SRC
CELLDEG.c
CELLDIM.c
MATCHWORD.c
MBPROD.c
MMFLR.c
PLDEG.c
PSIMREP.c
RMCONS.c
RNFAF.c
SVPOWR.c
SVPROD.c
VALIDLBL.c
)

set_source_files_properties(${UTIL_SRC} PROPERTIES LANGUAGE CXX)
add_library(util OBJECT ${UTIL_SRC})
set_target_properties(util PROPERTIES LANGUAGE CXX)
target_include_directories(util
        PUBLIC
        /usr/include/saclib
        ${CMAKE_SOURCE_DIR}/source
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_sources(libqepcad PRIVATE $<TARGET_OBJECTS:util>)
