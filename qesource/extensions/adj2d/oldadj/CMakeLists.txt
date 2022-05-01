FILE(GLOB OLDADJ_SRC
LLBRSPFSS.c
DNCAC.c
LLSISS.c
RIIFACMA.c
ACMADJ2D.c
RIIFACMABR.c
SPRLC.c
)

set_source_files_properties(${OLDADJ_SRC} PROPERTIES LANGUAGE CXX)
add_library(oldadj OBJECT ${OLDADJ_SRC})
set_target_properties(oldadj PROPERTIES LANGUAGE CXX)
target_include_directories(oldadj
	PUBLIC
        /usr/include/saclib
        ${CMAKE_SOURCE_DIR}/source
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_sources(libqepcad PRIVATE $<TARGET_OBJECTS:oldadj>)

install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/oldadj.h" DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/qepcad/adj2d")
