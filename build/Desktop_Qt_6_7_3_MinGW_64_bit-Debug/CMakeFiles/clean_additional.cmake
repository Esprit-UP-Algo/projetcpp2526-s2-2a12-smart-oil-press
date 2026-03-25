# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\integration_complete_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\integration_complete_autogen.dir\\ParseCache.txt"
  "integration_complete_autogen"
  )
endif()
