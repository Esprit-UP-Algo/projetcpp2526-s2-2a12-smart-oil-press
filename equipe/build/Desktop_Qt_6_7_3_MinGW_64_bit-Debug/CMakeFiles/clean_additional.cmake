# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\equipe_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\equipe_autogen.dir\\ParseCache.txt"
  "equipe_autogen"
  )
endif()
