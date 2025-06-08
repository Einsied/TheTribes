#[[
 @file
 @brief This is a module file to build the combat folder
 
 @author Sebastian Einsiedler
 @date 2025-05-23
 @copyright Copyright (c) 2025
]]#

set(include_combat "${include_namespaced}/combat")
set(source_combat "${source}/combat")

add_library(Combat)
target_sources(Combat
	PRIVATE
		"${include_combat}/harm.hpp"
		"${source_combat}/harm.cpp"
)
target_include_directories(Combat
	PRIVATE
	"${include}"
)
target_link_libraries(Combat
	PRIVATE
)
if(MSVC)
  target_compile_options(Combat PRIVATE /W4 /WX)
else()
  target_compile_options(Combat PRIVATE -Wall -Wextra -Wpedantic)
endif()
