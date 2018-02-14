# Create a library called "libR3BCal" which includes the source files given in
# the array .
# The extension is already found.  Any number of sources could be listed here.

Set(SYSTEM_INCLUDE_DIRECTORIES 
${SYSTEM_INCLUDE_DIRECTORIES}
${BASE_INCLUDE_DIRECTORIES}
###sun add
##${GEANT4_INCLUDE_DIR}
##${GEANT4VMC_INCLUDE_DIR}
##${CLHEP_INCLUDE_DIR}
)

set(INCLUDE_DIRECTORIES
#put here all directories where header files are located
${R3BROOT_SOURCE_DIR}/r3bbase 
${R3BROOT_SOURCE_DIR}/passive 
${R3BROOT_SOURCE_DIR}/glad-tpc

${R3BROOT_SOURCE_DIR}/r3bdata 
${R3BROOT_SOURCE_DIR}/r3bdata/tpcData

)

include_directories( ${INCLUDE_DIRECTORIES})
include_directories(SYSTEM ${SYSTEM_INCLUDE_DIRECTORIES})

set(LINK_DIRECTORIES
${ROOT_LIBRARY_DIR}
${FAIRROOT_LIBRARY_DIR}
###sun add
##${GEANT4_LIBRARY_DIR}
##${GEANT4VMC_LIBRARY_DIR}
) 

link_directories( ${LINK_DIRECTORIES})

set(SRCS
#Put here your sourcefiles
R3BTPC.cxx
R3BTPCDigitizer.cxx

)

###sun add
Set(INCLUDE
${SYSTEM_INCLUDE_DIRECTORIES}
 ${INCLUDE_DIRECTORIES}
)

# fill list of header files from list of source files
# by exchanging the file extension
CHANGE_FILE_EXTENSION(*.cxx *.h HEADERS "${SRCS}")

set(LINKDEF TPCLinkDef.h)
set(LIBRARY_NAME R3BTPC)
set(DEPENDENCIES
    R3Bbase R3BData R3BPassive MCStack)

if(FAIRDB_FOUND)
set(DEPENDENCIES
    ${DEPENDENCIES} FairDB)
endif(FAIRDB_FOUND)

GENERATE_LIBRARY()

