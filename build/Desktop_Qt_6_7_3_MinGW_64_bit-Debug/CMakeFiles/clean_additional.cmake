# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\GestionMachines_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\GestionMachines_autogen.dir\\ParseCache.txt"
  "GestionMachines_autogen"
  )
endif()
