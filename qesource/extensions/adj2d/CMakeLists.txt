FILE(GLOB ADJ2D_SRC
testfunc.c
ADJ_2D.c
ADJ_2D_PART.c
AD2DC_CONS.c
AD2DS_CONS.c
LDCOEFMASK.c
VECTOR_LTEQ.c
VECTOR_SUM.c
VECTOR_DIF_S.c
VECTOR_SEMI_COMP.c
VECTOR_S_PROD.c
VECTOR_NEG.c
SUM_NORM_SP.c
CWD_VECTOR_Q.c
ZERO_VECTOR.c
EQUAL_ON_ONES.c
ADD_2_SOL.c
Mystery_f.c
ADJ_2D_CONSTRUCT.c
P1.c
P2.c
P3.c
P4.c
ADJ_2D1_COMPLETE.c
ADJ_2D1.c
ADJ_2D1_SIMPLE.c
ADJ_2D1P1.c
ADJ_2D1P2.c
ADJ_2D1P3.c
VECTOR_ODD_E.c
)

add_subdirectory(oldadj)
add_subdirectory(truthbytop)
add_subdirectory(sac_ext)

set_source_files_properties(${ADJ2D_SRC} PROPERTIES LANGUAGE CXX)
add_library(adj2d OBJECT ${ADJ2D_SRC})
set_target_properties(adj2d PROPERTIES LANGUAGE CXX)
target_include_directories(adj2d
	PUBLIC
	/usr/include/saclib
	${CMAKE_SOURCE_DIR}/source/
	${CMAKE_CURRENT_SOURCE_DIR}
)
target_sources(libqepcad PRIVATE $<TARGET_OBJECTS:adj2d>)

target_include_directories(rend PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(truthbytop PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(oldadj PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/adj2D.h" DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/qepcad/adj2d")
