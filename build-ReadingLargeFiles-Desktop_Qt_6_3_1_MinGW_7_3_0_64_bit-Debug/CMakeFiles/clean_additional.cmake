# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\ReadingLargeFiles_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\ReadingLargeFiles_autogen.dir\\ParseCache.txt"
  "ReadingLargeFiles_autogen"
  )
endif()
