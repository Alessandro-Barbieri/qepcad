FILE(GLOB CAD2D_SRC
	src/MAIN.c
	src/CAD2D.c
	src/CONSTRUCT.c
	src/PROJECT.c
	src/PRINTCAD2DBANNER.c
	src/TICAD.c
)

set_source_files_properties(
	${CAD2D_SRC}
	PROPERTIES
	LANGUAGE
	CXX
)
add_executable(CAD2D ${CAD2D_SRC})
set_target_properties(CAD2D PROPERTIES LANGUAGE CXX)
target_include_directories(CAD2D
	PUBLIC
	/usr/include/saclib
	${CMAKE_SOURCE_DIR}/source
	PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/src
)
target_link_libraries(CAD2D PUBLIC libqepcad)
install(TARGETS CAD2D DESTINATION "${CMAKE_INSTALL_BINDIR}")
