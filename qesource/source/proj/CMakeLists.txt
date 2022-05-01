FILE(GLOB PROJ_SRC
APPEND.c
APPENDEC.c
ECLEVEL.c
EXTRACT.c
EXTRACTS.c
GROUPSAMEPJ.c
IPDSCRPRS.c
IPDSCRQE.c
IPLFAC.c
IPRESQE.c
LCM.c
LOAR.c
LUNION.c
MPOLY.c
PROJ.c
PROJCO.c
PROJHO.c
PROJLA.c
PROJMC.c
PROJMCx.c
PROJMCmod.c
PROJMCECmod.c
PROJECT.c
PROJMCEC.c
PROPCONS.c
UDEQNCONST.c
SEPLAB.c
PROJECTauto.c
)

set_source_files_properties(${PROJ_SRC} PROPERTIES LANGUAGE CXX)
add_library(proj OBJECT ${PROJ_SRC})
set_target_properties(proj PROPERTIES LANGUAGE CXX)
target_include_directories(proj
        PUBLIC
        /usr/include/saclib
        ${CMAKE_SOURCE_DIR}/source
)

target_sources(libqepcad PRIVATE $<TARGET_OBJECTS:proj>)
