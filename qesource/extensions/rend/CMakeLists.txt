FILE(GLOB REND_SRC
LBRNQORD.c
SSILRCRI.c
CONMIRCAD.cc
PLOT_2D_CAD.cc
PLOT2DCAD2FILE.cc
Rend_Sample.cc
Rend_Cell.cc
Rend_Win.cc
ADD_POINTS.cc
FILL_2D.cc
WRITE_PLOT.cc
WRITE_PS.cc
WRITE_PS_COLOR.cc
WRITE_EPS.cc
WRITE_PS_STANDARD.cc
WRITE_PS_INTERACTIVE.cc
WRITE_PS_RAJI.cc
ZOOM_OUT.cc
GET_COORDS.cc
CH_VIEW_WIN.cc
CH_VIEW_WIN_COOR.cc
DISP2DCAD.cc
)

FILE(GLOB REND_HEADERS
gcmemloc.h
Mapper.h
rend.h
Rend_Cell.h
Rend_Sample.h
Rend_Win.h
Safe_Array.h
)

set_source_files_properties(${REND_SRC} PROPERTIES LANGUAGE CXX)
add_library(rend OBJECT ${REND_SRC})
set_target_properties(rend PROPERTIES LANGUAGE CXX)
target_include_directories(rend
	PUBLIC
	/usr/include/saclib
	${CMAKE_SOURCE_DIR}/source/
	${CMAKE_CURRENT_SOURCE_DIR}
)

target_sources(libqepcad PRIVATE $<TARGET_OBJECTS:rend>)

install(FILES ${REND_HEADERS} DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/qepcad/rend")
