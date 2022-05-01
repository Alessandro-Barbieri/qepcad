FILE(GLOB NORMQFF_SRC
EXPAFEQ.c
EXPAFGT.c
EXPAFGTS.c
EXPAFLT.c
EXPAFLTS.c
ISATOMF.c
NEGRLOP.c
NORMAF.c
NORMAFS.c
NORMQFF.c
PQFF.c
RMCAFS.c
RMCAON.c
RMLREOP.c
RMNOTOP.c
RMNOTOPN.c
TYPEAF.c
TYPEQFF.c
)

set_source_files_properties(${NORMQFF_SRC} PROPERTIES LANGUAGE CXX)
add_library(normqff OBJECT ${NORMQFF_SRC})
set_target_properties(normqff PROPERTIES LANGUAGE CXX)
target_include_directories(normqff
        PUBLIC
        /usr/include/saclib
        ${CMAKE_SOURCE_DIR}/source
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_sources(libqepcad PRIVATE $<TARGET_OBJECTS:normqff>)
