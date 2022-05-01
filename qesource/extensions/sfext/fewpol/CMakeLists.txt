FILE(GLOB FEWPOL_SRC
CSORTSS.c
ICSIGDIFFL.c
MINPFSET.c
SIGEQUALOL.c
PWUDSCWCP.c
TDTOD.c
)

set_source_files_properties(${FEWPOL_SRC} PROPERTIES LANGUAGE CXX)
add_library(fewpol OBJECT ${FEWPOL_SRC})
set_target_properties(fewpol PROPERTIES LANGUAGE CXX)
target_include_directories(fewpol
        PUBLIC
        /usr/include/saclib
        ${CMAKE_SOURCE_DIR}/source/
        ${CMAKE_SOURCE_DIR}/extensions/sfext
)

target_sources(libqepcad PRIVATE $<TARGET_OBJECTS:fewpol>)
