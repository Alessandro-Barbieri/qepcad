FILE(GLOB TRUTHBYTOP_SRC
TVCLOSURE1D.c
TVCLOSURE1DS.c
CCTV.c
CTVPROPUP.c
TVCCOSBSVAI.c
GRAPHMODULE.c
TV2D.c
C1DTOEDGELIST.c
ADJ2DITOEL.c
ADJGRAPHCONS.c
CLOSURE2D.c
BOUNDARY2D.c
)

set_source_files_properties(${TRUTHBYTOP_SRC} PROPERTIES LANGUAGE CXX)
add_library(truthbytop OBJECT ${TRUTHBYTOP_SRC})
set_target_properties(truthbytop PROPERTIES LANGUAGE CXX)
target_include_directories(truthbytop
        PUBLIC
        /usr/include/saclib
        ${CMAKE_SOURCE_DIR}/source
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_sources(libqepcad PRIVATE $<TARGET_OBJECTS:truthbytop>)

install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/truthbytop.h" DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/qepcad/adj2d")
