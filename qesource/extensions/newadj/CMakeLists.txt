FILE(GLOB NEWADJ_SRC
HAP1.c
HAP2.c
HAP3.c
HA.c
HALDCOEFMASK.c
HAS_CONS.c
HAC_CONS.c
HATEST.c
)

FILE(GLOB NEWADJ_HEADERS
adj2D.h
newadj2D.h
)

set_source_files_properties(${NEWADJ_SRC} PROPERTIES LANGUAGE CXX)
add_library(newadj OBJECT ${NEWADJ_SRC})
set_target_properties(newadj PROPERTIES LANGUAGE CXX)
target_include_directories(newadj
	PUBLIC
	/usr/include/saclib
	${CMAKE_SOURCE_DIR}/source/
	${CMAKE_CURRENT_SOURCE_DIR}
)

target_sources(libqepcad PRIVATE $<TARGET_OBJECTS:newadj>)

install(FILES ${NEWADJ_HEADERS} DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/qepcad/newadj")
