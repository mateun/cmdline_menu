file(GLOB sources src/*.cpp)
include_directories(include ../lib/include)

add_executable(testapp ${sources})

target_link_libraries(testapp cmdlinemenu)

