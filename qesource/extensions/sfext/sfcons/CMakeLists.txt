FILE(GLOB SFCONS_SRC
DOPFSUFF.c
NAIVEDOPFSUFF.c
ESPCADDOPFSUFF.c
NAIVESF.c
IMPCONS.c
MINCOVBF.c
LISTOTA.c
LISTOETA.c
NECCONDS.c
GEOTEST.c
GEOPARTII.c
CYLFORM.c
CYLIMPFORM.c
SFC1.c
SFC2.c
SFC3.c
SFC3f.c
SFC4.c
SFCFULLD.c
SFCFULLDf.c
SOLEXTINT.c
)

set_source_files_properties(${SFCONS_SRC} PROPERTIES LANGUAGE CXX)
add_library(sfcons OBJECT ${SFCONS_SRC})
set_target_properties(sfcons PROPERTIES LANGUAGE CXX)
target_include_directories(sfcons
        PUBLIC
        /usr/include/saclib
        ${CMAKE_SOURCE_DIR}/source/
        ${CMAKE_SOURCE_DIR}/extensions/sfext
)

target_sources(libqepcad PRIVATE $<TARGET_OBJECTS:sfcons>)
