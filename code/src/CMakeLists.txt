#[[
 @file
 @brief This is the central cmake file for the entire project
 
 @author Sebastian Einsiedler
 @date 2025-05-17
 @copyright Copyright (c) 2025
]]#

# Setting CMake Version to the one I tested
cmake_minimum_required(VERSION 3.28.3)

project(Tribes 
	# This version will not be updated until I create a first release
	# If you see this comment I did not due so or I forgot.
	# Anyway the version-number is meaningless
	VERSION 0.0.1 
	DESCRIPTION "A little real-time-strategy game combining influences from Cultures, Settlers, Stronghold ans Spellforce. Please read the readme and be kind."
	HOMEPAGE_URL "https://github.com/Einsied/TheTribes"
	LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(include "../include")
set(source "./")

add_executable(Game)
target_sources(Game
	PRIVATE
		"${include}/tribes/goods/good.hpp"
		"${source}/goods/good.cpp"
)
target_include_directories(Game
	PRIVATE
	"${include}"
)
target_link_libraries(Game
	PRIVATE
)
