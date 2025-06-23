#[[
 @file
 @brief This is a module file to build the species folder
 
 @author Sebastian Einsiedler
 @date 2025-06-08
 @copyright Copyright (c) 2025
]]#

set(include_species "${include_inhabitants}/species")
set(source_species "${source_inhabitants}/species")

add_library(Species)
target_sources(Species
	PRIVATE
		"${include_species}/base.hpp"
		"${source_species}/base.cpp"
)
target_include_directories(Species
	PRIVATE
	"${include}"
)
target_link_libraries(Species
	PRIVATE
	Combat
)
if(MSVC)
	target_compile_options(Species PRIVATE /W4 /WX)
else()
	target_compile_options(Species PRIVATE -Wall -Wextra -Wpedantic)
endif()
