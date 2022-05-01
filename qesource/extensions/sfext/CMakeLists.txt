add_subdirectory(addpol)
add_subdirectory(crcads)
add_subdirectory(espcad)
add_subdirectory(extlang)
add_subdirectory(fewpol)
add_subdirectory(formula)
add_subdirectory(pcadst)
add_subdirectory(projpf)
add_subdirectory(sfcons)
add_subdirectory(sort)
add_subdirectory(minhit)

FILE(GLOB SFEXT_HEADERS
coarsecad.h
mysort.h
newpols.h
)

install(FILES ${SFEXT_HEADERS} DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/qepcad/sfext")
