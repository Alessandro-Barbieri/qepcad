FILE(GLOB USERINT_SRC
CELLFIDX.c
ESPIWR.c
ESPORD.c
GETCID.c
GFPCSTAT.c
HELPFRD.c
HELPWR.c
INTERACT.c
PRAFUPBRI.c
PRAPPROX.c
PRCCS.c
PRCCSF.c
PRDC.c
PRDCC.c
PRDCS.c
PRDDESIRED.c
PRDESIRED.c
PRDF.c
PRDFPCSTAT.c
PRDIP.c
PRDLFI.c
PRDLPI.c
PRDLV.c
PRDNQFF.c
PRDPC.c
PRDPCS.c
PRDPF.c
PRDPJ.c
PRDQ.c
PRDQFF.c
PRDSEARCH.c
PRDSET.c
PRDSTACK.c
PRDTRACEA.c
PRDTRACED.c
PRDVL.c
PREQNCONST.c
PRFINISH.c
PRGO.c
PRHELP.c
PRIPFZT.c
PRIGS.c
PRLDB.c
PRMCC.c
PROMPT.c
PRPROJOP.c
PRQUIT.c
PRRMPF.c
PRRMPJ.c
PRRSP.c
PRSEARCH.c
PRSIMPLIFIER.c
PRSTEP.c
PRTCN.c
PRTRACEA.c
PRTRACED.c
PRUDB.c
PRUSEDESIRED.c
PRWHATIS.c
RMMPF.c
RMMPJ.c
PRCHPIVOT.c
PRDEQNCONST.c
PREQNCONSTL.c
PRPROPEC.c
PRRESALG.c
USERINT.c
)

set_source_files_properties(${USERINT_SRC} PROPERTIES LANGUAGE CXX)
add_library(userint OBJECT ${USERINT_SRC})
set_target_properties(userint PROPERTIES LANGUAGE CXX)
target_include_directories(userint
        PUBLIC
        /usr/include/saclib
        ${CMAKE_SOURCE_DIR}/source
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_sources(libqepcad PRIVATE $<TARGET_OBJECTS:userint>)
