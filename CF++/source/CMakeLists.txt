set(sources 
	CFPP-Array.cpp
	CFPP-AutoPointer.cpp
	CFPP-Boolean.cpp
	CFPP-Data.cpp
	CFPP-Date.cpp
	CFPP-Dictionary.cpp
	CFPP-Error.cpp
	CFPP-Number.cpp
	CFPP-Pair.cpp
	CFPP-ReadStream.cpp
	CFPP-String.cpp
	CFPP-Type.cpp
	CFPP-URL.cpp
	CFPP-UUID.cpp
	CFPP-WriteStream.cpp
	)
add_library(cfpp ${sources})

set_target_properties(cfpp 
    PROPERTIES CXX_STANDARD 11
               CXX_STANDARD_REQUIRED ON
           )

target_include_directories(cfpp
    PUBLIC ../include
    )

find_library(coreFoundationLib CoreFoundation)
find_library(ioKitLib IOKit)
target_link_libraries(cfpp PRIVATE ${ioKitLib} ${coreFoundationLib})
