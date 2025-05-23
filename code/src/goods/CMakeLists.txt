#[[
 @file
 @brief This is a module file to build the goods folder
 
 @author Sebastian Einsiedler
 @date 2025-05-23
 @copyright Copyright (c) 2025
]]#

set(include_goods "${include_namespaced}/goods")
set(source_goods "${source}/goods")

add_library(Goods)
target_sources(Goods
	PRIVATE
		"${include_goods}/good.hpp"
		"${source_goods}/good.cpp"
)
target_include_directories(Goods
	PRIVATE
	"${include}"
)
target_link_libraries(Goods
	PRIVATE
)
if(MSVC)
  target_compile_options(Goods PRIVATE /W4 /WX)
else()
  target_compile_options(Goods PRIVATE -Wall -Wextra -Wpedantic)
endif()
