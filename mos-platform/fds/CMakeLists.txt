platform(fds COMPLETE PARENT nes)

if(NOT CMAKE_CROSSCOMPILING)
  return()
endif()

install(FILES
  common.ld
  fds.ld
  prg-ram.ld
  c-in-prg-ram.ld
TYPE LIB)
install(FILES mapper.h TYPE INCLUDE)

add_platform_object_file(fds-crt0-o crt0.o)
add_platform_object_file(fds-reset-o reset.o reset.s)

add_platform_library(fds-c mapper.c)
target_include_directories(fds-c PRIVATE ../nes)
target_link_libraries(fds-c PRIVATE common-asminc)

#add_subdirectory(fdslib)
