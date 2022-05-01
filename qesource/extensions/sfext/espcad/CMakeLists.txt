FILE(GLOB ESPCAD_SRC
ESPCADCRNV.c
ESPCADWRITE.c
PCAD2ESPCAD.c
ESPCADLSNC.c
)

set_source_files_properties(${ESPCAD_SRC} PROPERTIES LANGUAGE CXX)
add_library(espcad OBJECT ${ESPCAD_SRC})
set_target_properties(espcad PROPERTIES LANGUAGE CXX)
target_include_directories(espcad
        PUBLIC
	/usr/include/saclib
        ${CMAKE_SOURCE_DIR}/source/
        ${CMAKE_SOURCE_DIR}/extensions/sfext
        ${CMAKE_CURRENT_SOURCE_DIR}/
)

target_sources(libqepcad PRIVATE $<TARGET_OBJECTS:espcad>)

install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/espcad.h" DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/qepcad/sfext")
