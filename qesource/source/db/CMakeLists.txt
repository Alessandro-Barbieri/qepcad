FILE(GLOB DB_SRC
AFCSBMDB.c
AFPNIPDB.c
AFUPGCDB.c
AFUPSFNDB.c
DBADD.c
DBSRCH.c
DBSTATWR.c
FNDTSDB.c
GETRPDB.c
IPFACDB.c
MODCRDB.c
SUBSTDB.c
SINGULAR.c
)

FILE(GLOB DB_HEADERS
CAPolicy.h
convenientstreams.h
readlineistream.h
SINGULAR.h
unnamedpipe.h
CAServer.h
OriginalPolicy.h
SingSacPolicy.h
SingularPolicy.h
)

set_source_files_properties(${DB_SRC} PROPERTIES LANGUAGE CXX)
add_library(db OBJECT ${DB_SRC})
set_target_properties(db PROPERTIES LANGUAGE CXX)
target_include_directories(db
	PUBLIC
	/usr/include/saclib
	${CMAKE_SOURCE_DIR}/source
	${CMAKE_CURRENT_SOURCE_DIR}
)

target_sources(libqepcad PRIVATE $<TARGET_OBJECTS:db>)

install(FILES ${DB_HEADERS} DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/qepcad")
