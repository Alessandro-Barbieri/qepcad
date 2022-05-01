FILE(GLOB CRCADS_SRC
CADSCL.c
CADSTATS.c
CELLFINDEX.c
CSN.c
LPFZC.c
LPFZCAL.c
CRCELL.c
CSORCELL.c
CSORCELL_MOD.c
FALSECELLWRITE.c
TRUECELLWRITE.c
LISTOFCWTV.c
NUMSOLPOINTS.c
RNCADRTV.c
SPCADCBDD.c
SOLSETDIM.c
LPFOWCS.c
)

set_source_files_properties(${CRCADS_SRC} PROPERTIES LANGUAGE CXX)
add_library(crcads OBJECT ${CRCADS_SRC})
set_target_properties(crcads PROPERTIES LANGUAGE CXX)
target_include_directories(crcads
        PUBLIC
	/usr/include/saclib
        ${CMAKE_SOURCE_DIR}/source/
        ${CMAKE_SOURCE_DIR}/extensions/sfext
)

target_sources(libqepcad PRIVATE $<TARGET_OBJECTS:crcads>)
