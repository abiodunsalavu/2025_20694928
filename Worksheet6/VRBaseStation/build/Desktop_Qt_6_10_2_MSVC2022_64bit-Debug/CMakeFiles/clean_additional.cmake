# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\VRBaseStation_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\VRBaseStation_autogen.dir\\ParseCache.txt"
  "VRBaseStation_autogen"
  )
endif()
