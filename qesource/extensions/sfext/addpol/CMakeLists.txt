FILE(GLOB ADDPOL_SRC
BPOLSETS.c
CFLCELLLIST.c
CLEAN_BIGLOOP.c
STRIPPED_BIGLOOP.c
ICSIGDIFFLNSC.c
KCONST.c
MINPFSETNSC.c
NEWDERIV.c
)

set_source_files_properties(${ADDPOL_SRC} PROPERTIES LANGUAGE CXX)
add_library(addpol OBJECT ${ADDPOL_SRC})
set_target_properties(addpol PROPERTIES LANGUAGE CXX)
target_include_directories(addpol
        PUBLIC
	/usr/include/saclib
        ${CMAKE_SOURCE_DIR}/source/
        ${CMAKE_SOURCE_DIR}/extensions/sfext
)

target_sources(libqepcad PRIVATE $<TARGET_OBJECTS:addpol>)
