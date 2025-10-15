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
install(FILES
  bios.inc
  DESTINATION ${ASMINCDIR})
install(FILES
  bios.h
  mapper.h
TYPE INCLUDE)

add_platform_object_file(fds-crt0-o crt0.o)
add_platform_object_file(fds-reset-o reset.o reset.s)

add_platform_library(fds-c
  bios.s

  fds_AdjustFileCount.s
  fds_AppendFile.s
  fds_CheckDiskHeader.c
  fds_CheckFileCount.s
  fds_Delay131.c
  fds_Delayms.s
  fds_DisObj.c
  fds_DisPF.c
  fds_DisPFObj.c
  fds_EnObj.c
  fds_EnPF.c
  fds_EnPFObj.c
  fds_FileMatchTest.c
  fds_GetDiskInfo.s
  fds_GetNumFiles.c
  fds_LoadFiles.s
  fds_MemFill.s
  # fds_Nam2PixelConv.c
  fds_Pixel2NamConv.c
  fds_ReadDownExpPads.c
  fds_ReadDownPads.c
  fds_ReadDownVerifyPads.c
  fds_ReadOrDownPads.c
  fds_ReadOrDownVerifyPads.c
  fds_SetFileCount.s
  fds_SetFileCount1.s
  fds_SetNumFiles.c
  fds_SkipFiles.c
  fds_SpriteDMA.c
  fds_UploadObject.c
  fds_VINTWait.c
  fds_VRAMFill.s
  fds_WriteFile.s

  mapper.c
  mapper.s
)
#target_include_directories(fds-c PRIVATE ../nes)
target_include_directories(fds-c BEFORE PUBLIC .)
target_link_libraries(fds-c PRIVATE common-asminc)
