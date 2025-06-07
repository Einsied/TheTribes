#[[
 @file
 @brief This is a module file to build the goods folder
 
 @author Sebastian Einsiedler
 @date 2025-05-23
 @copyright Copyright (c) 2025
]]#

set(include_inhabitants "${include_namespaced}/inhabitants")
set(source_inhabitants "${source}/inhabitants")

add_library(Inhabitants)
target_sources(Inhabitants
	PRIVATE
		"${include_inhabitants}/harm.hpp"
		"${source_inhabitants}/harm.cpp"
)
target_include_directories(Inhabitants
	PRIVATE
	"${include}"
)
target_link_libraries(Inhabitants
	PRIVATE
)
if(MSVC)
  target_compile_options(Inhabitants PRIVATE /W4 /WX)
else()
  target_compile_options(Inhabitants PRIVATE -Wall -Wextra -Wpedantic)
endif()
