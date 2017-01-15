add_definitions("-DCMDLINE_EXPORTS")

file(GLOB sources src/*.cpp)
include_directories(include)

add_library(cmdlinemenu SHARED ${sources})

add_custom_command(TARGET cmdlinemenu POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
	"${PROJECT_SOURCE_DIR}/build/lib/$<CONFIGURATION>/cmdlinemenu.dll" 
    "${PROJECT_SOURCE_DIR}/build/testapp/$<CONFIGURATION>")