set(INCLUDE_DIR include)
include_directories(${INCLUDE_DIR})

# Add the header files too, so they can be seen in IDE projects
file(GLOB AST_FILES src/*.cpp include/*.h) 
set (SOURCE_FILES ${AST_FILES})

set(COOL_AST_LIB cool-ast)
add_library(${COOL_AST_LIB} STATIC ${AST_FILES})

set(COOl_AST_EXPORT_DESTINATION cool-ast)
