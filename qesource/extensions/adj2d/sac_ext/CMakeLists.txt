FILE(GLOB SACEXT_SRC
LBRNMAX.c
LBRNMIN.c
PCFE.c
IUPLBREVAL.c
IPLBREVAL.c
IUPSOPOR.c
IUPSOPORFIL.c
RRCOMPSRI.c
ADJNNA.c
IBPIDFV.c
IPMP2.c
RRLBRNCOMP.c
IPRRILBRI.c
IUPTSII.c
)

set_source_files_properties(${SACEXT_SRC} PROPERTIES LANGUAGE CXX)
add_library(sacext OBJECT ${SACEXT_SRC})
set_target_properties(sacext PROPERTIES LANGUAGE CXX)
target_include_directories(sacext
        PUBLIC
        /usr/include/saclib
        ${CMAKE_SOURCE_DIR}/source
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_sources(libqepcad PRIVATE $<TARGET_OBJECTS:sacext>)

install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/sac_ext.h" DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/qepcad/adj2d")
