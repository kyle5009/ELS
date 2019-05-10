cmake_minimum_required(VERSION 3.11)
# Require modern C++
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(ELS)

#### Setup Directories ####
#Main output directory
SET(OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/")
# Ouput all DLLs from all libs into main build folder
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIRECTORY})

#### Add External Dependencies ####
add_subdirectory("lib/sfml")
set(SFML_INCS "lib/sfml/include")
link_directories("${CMAKE_BINARY_DIR}/lib/sfml/lib")


#### Space Invaders ####
file(GLOB_RECURSE SOURCES Earths_Last_Stand/*.cpp Earths_Last_Stand/*.h)
add_executable(Earths_Last_Stand ${SOURCES} )
target_include_directories(Earths_Last_Stand SYSTEM PRIVATE ${SFML_INCS})
target_link_libraries(Earths_Last_Stand sfml-graphics)
add_custom_target(copy_resources ALL COMMAND ${CMAKE_COMMAND}
  -E copy_directory
    "${PROJECT_SOURCE_DIR}/res"
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/$<CONFIGURATION>/res
)
set_target_properties(
  Earths_Last_Stand PROPERTIES
  VS_DEBUGGER_WORKING_DIRECTORY
  ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/$(Configuration)
)
add_dependencies(Earths_Last_Stand copy_resources)
