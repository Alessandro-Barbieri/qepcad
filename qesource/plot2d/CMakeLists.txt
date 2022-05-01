add_executable(ADJ2D_plot plot.cc)
target_link_libraries(ADJ2D_plot
	PUBLIC
	libqepcad
	-lX11
	-lXext
	-lGLU
	-lGL
	-lglut
	-lpthread
	-lm
)
target_include_directories(ADJ2D_plot PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
install(TARGETS ADJ2D_plot DESTINATION "${CMAKE_INSTALL_BINDIR}")
