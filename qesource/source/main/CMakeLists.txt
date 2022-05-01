FILE(GLOB MAIN_SRC
BEGINQEPCAD.c
ENDQEPCAD.c
INITCTRL.c
INITDB.c
INITIO.c
INITSTAT.c
INITSYS.c
INPUTRD.c
PRINTBANNER.c
QEPCAD.c
SETUPSYS.c
FAIL.c
data.c
QEPCADauto.c
qepcadcls.c
CADautoConst.c
)

FILE(GLOB MAIN_HEADERS
formulaAPI.h
qepcadcls.h
unsatcore.h
)

set_source_files_properties(${MAIN_SRC} PROPERTIES LANGUAGE CXX)
add_library(main OBJECT ${MAIN_SRC})
set_target_properties(main PROPERTIES LANGUAGE CXX)
target_include_directories(main
        PUBLIC
        /usr/include/saclib
        ${CMAKE_SOURCE_DIR}/source
	${CMAKE_CURRENT_SOURCE_DIR}
)

target_sources(libqepcad PRIVATE $<TARGET_OBJECTS:main>)

add_library(qepcad-obj OBJECT ${CMAKE_CURRENT_SOURCE_DIR}/MAIN.c)
set_source_files_properties(
        ${CMAKE_CURRENT_SOURCE_DIR}/MAIN.c
        PROPERTIES
        LANGUAGE
        CXX
)
target_include_directories(qepcad-obj
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        /usr/include/saclib
        ${CMAKE_SOURCE_DIR}/source
)

target_sources(qepcad PUBLIC $<TARGET_OBJECTS:qepcad-obj>)

install(FILES ${MAIN_HEADERS} DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/qepcad")

