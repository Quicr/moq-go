# Install script for directory: /Users/snk/work/tech/moq/quicr-go/libquicr/dependencies/picoquic

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set path to fallback-tool for dependency-resolution.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/Users/snk/work/tech/moq/quicr-go/build/libquicr/dependencies/picoquic/libpicohttp-core.a")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libpicohttp-core.a" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libpicohttp-core.a")
    execute_process(COMMAND "/usr/bin/ranlib" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libpicohttp-core.a")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES
    "/Users/snk/work/tech/moq/quicr-go/libquicr/dependencies/picoquic/picohttp/h3zero.h"
    "/Users/snk/work/tech/moq/quicr-go/libquicr/dependencies/picoquic/picohttp/h3zero_common.h"
    "/Users/snk/work/tech/moq/quicr-go/libquicr/dependencies/picoquic/picohttp/h3zero_uri.h"
    "/Users/snk/work/tech/moq/quicr-go/libquicr/dependencies/picoquic/picohttp/h3zero_url_template.h"
    "/Users/snk/work/tech/moq/quicr-go/libquicr/dependencies/picoquic/picohttp/democlient.h"
    "/Users/snk/work/tech/moq/quicr-go/libquicr/dependencies/picoquic/picohttp/demoserver.h"
    "/Users/snk/work/tech/moq/quicr-go/libquicr/dependencies/picoquic/picohttp/pico_webtransport.h"
    "/Users/snk/work/tech/moq/quicr-go/libquicr/dependencies/picoquic/picohttp/picomask.h"
    "/Users/snk/work/tech/moq/quicr-go/libquicr/dependencies/picoquic/picohttp/wt_baton.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/Users/snk/work/tech/moq/quicr-go/build/libquicr/dependencies/picoquic/picolog_t")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/picolog_t" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/picolog_t")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" -u -r "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/picolog_t")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/Users/snk/work/tech/moq/quicr-go/build/libquicr/dependencies/picoquic/libpicoquic-log.a")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libpicoquic-log.a" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libpicoquic-log.a")
    execute_process(COMMAND "/usr/bin/ranlib" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libpicoquic-log.a")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES
    "/Users/snk/work/tech/moq/quicr-go/libquicr/dependencies/picoquic/loglib/autoqlog.h"
    "/Users/snk/work/tech/moq/quicr-go/libquicr/dependencies/picoquic/loglib/auto_memlog.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/Users/snk/work/tech/moq/quicr-go/build/libquicr/dependencies/picoquic/libpicoquic-core.a")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libpicoquic-core.a" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libpicoquic-core.a")
    execute_process(COMMAND "/usr/bin/ranlib" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libpicoquic-core.a")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/Users/snk/work/tech/moq/quicr-go/build/_deps/picotls-build/libpicotls-core.a")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libpicotls-core.a" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libpicotls-core.a")
    execute_process(COMMAND "/usr/bin/ranlib" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libpicotls-core.a")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/Users/snk/work/tech/moq/quicr-go/build/_deps/picotls-build/libpicotls-openssl.a")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libpicotls-openssl.a" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libpicotls-openssl.a")
    execute_process(COMMAND "/usr/bin/ranlib" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libpicotls-openssl.a")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/Users/snk/work/tech/moq/quicr-go/build/_deps/picotls-build/libpicotls-minicrypto.a")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libpicotls-minicrypto.a" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libpicotls-minicrypto.a")
    execute_process(COMMAND "/usr/bin/ranlib" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libpicotls-minicrypto.a")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/picoquic/picoquic-targets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/picoquic/picoquic-targets.cmake"
         "/Users/snk/work/tech/moq/quicr-go/build/libquicr/dependencies/picoquic/CMakeFiles/Export/36367f4f060ff48b6b09cf9101705788/picoquic-targets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/picoquic/picoquic-targets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/picoquic/picoquic-targets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/picoquic" TYPE FILE FILES "/Users/snk/work/tech/moq/quicr-go/build/libquicr/dependencies/picoquic/CMakeFiles/Export/36367f4f060ff48b6b09cf9101705788/picoquic-targets.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/picoquic" TYPE FILE FILES "/Users/snk/work/tech/moq/quicr-go/build/libquicr/dependencies/picoquic/CMakeFiles/Export/36367f4f060ff48b6b09cf9101705788/picoquic-targets-release.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES
    "/Users/snk/work/tech/moq/quicr-go/libquicr/dependencies/picoquic/picoquic/picoquic.h"
    "/Users/snk/work/tech/moq/quicr-go/libquicr/dependencies/picoquic/picoquic/picosocks.h"
    "/Users/snk/work/tech/moq/quicr-go/libquicr/dependencies/picoquic/picoquic/picoquic_utils.h"
    "/Users/snk/work/tech/moq/quicr-go/libquicr/dependencies/picoquic/picoquic/picoquic_packet_loop.h"
    "/Users/snk/work/tech/moq/quicr-go/libquicr/dependencies/picoquic/picoquic/picoquic_config.h"
    "/Users/snk/work/tech/moq/quicr-go/libquicr/dependencies/picoquic/picoquic/picoquic_lb.h"
    "/Users/snk/work/tech/moq/quicr-go/libquicr/dependencies/picoquic/picoquic/picoquic_newreno.h"
    "/Users/snk/work/tech/moq/quicr-go/libquicr/dependencies/picoquic/picoquic/picoquic_cubic.h"
    "/Users/snk/work/tech/moq/quicr-go/libquicr/dependencies/picoquic/picoquic/picoquic_bbr.h"
    "/Users/snk/work/tech/moq/quicr-go/libquicr/dependencies/picoquic/picoquic/picoquic_bbr1.h"
    "/Users/snk/work/tech/moq/quicr-go/libquicr/dependencies/picoquic/picoquic/picoquic_fastcc.h"
    "/Users/snk/work/tech/moq/quicr-go/libquicr/dependencies/picoquic/picoquic/picoquic_prague.h"
    "/Users/snk/work/tech/moq/quicr-go/libquicr/dependencies/picoquic/picoquic/c4.h"
    "/Users/snk/work/tech/moq/quicr-go/libquicr/dependencies/picoquic/picoquic/siphash.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/picoquic" TYPE FILE FILES
    "/Users/snk/work/tech/moq/quicr-go/build/libquicr/dependencies/picoquic/picoquic-config.cmake"
    "/Users/snk/work/tech/moq/quicr-go/build/libquicr/dependencies/picoquic/picoquic-config-version.cmake"
    )
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
if(CMAKE_INSTALL_LOCAL_ONLY)
  file(WRITE "/Users/snk/work/tech/moq/quicr-go/build/libquicr/dependencies/picoquic/install_local_manifest.txt"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
endif()
