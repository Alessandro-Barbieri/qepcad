add_library(libqepcad SHARED "")
set_target_properties(libqepcad PROPERTIES PREFIX "")
target_link_libraries(libqepcad
	PUBLIC
	-lsaclib
	-lrt
	-lreadline
)

add_executable(qepcad "")
target_link_libraries(qepcad PUBLIC libqepcad)

add_subdirectory(db)
add_subdirectory(io)
add_subdirectory(main)
add_subdirectory(normqff)
add_subdirectory(proj)
add_subdirectory(saclib)
add_subdirectory(sysolve)
add_subdirectory(ticad)
add_subdirectory(userint)
add_subdirectory(util)

install(TARGETS libqepcad DESTINATION "${CMAKE_INSTALL_LIBDIR}")
install(TARGETS qepcad DESTINATION "${CMAKE_INSTALL_BINDIR}")
install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/qepcad.help" DESTINATION "${CMAKE_INSTALL_DATAROOTDIR}/qepcad")
install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/qepcad.h" DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/qepcad")
