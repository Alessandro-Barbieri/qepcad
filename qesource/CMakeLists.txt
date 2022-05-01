CMAKE_MINIMUM_REQUIRED(VERSION 3.19)
PROJECT(QEPCAD
	VERSION 1.72
	LANGUAGES CXX
)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
include(GNUInstallDirs)

add_subdirectory(source)
add_subdirectory(extensions)
add_subdirectory(cad2d)
add_subdirectory(plot2d)

install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/default.qepcadrc" DESTINATION "${CMAKE_INSTALL_SYSCONFDIR}")
