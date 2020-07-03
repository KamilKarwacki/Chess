cmake_minimum_required(VERSION "3.7.1")
project("ChessGame")

include_directories(include)

file(GLOB helloworld_SRC
		    "include/*.h"
			"src/*.cpp"
)

add_executable(ChessApp ${helloworld_SRC})


# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

find_package(SFML COMPONENTS network audio graphics window system)
if(SFML_FOUND)
	include_directories(${SFML_INCLUDE_DIR})
	target_link_libraries(ChessApp ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()

install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)


