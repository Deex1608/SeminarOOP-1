# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\SeminarOOP_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\SeminarOOP_autogen.dir\\ParseCache.txt"
  "SeminarOOP_autogen"
  )
endif()
