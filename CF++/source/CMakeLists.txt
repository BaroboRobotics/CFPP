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
	PARENT_SCOPE)
add_library(cfpp ${sources})