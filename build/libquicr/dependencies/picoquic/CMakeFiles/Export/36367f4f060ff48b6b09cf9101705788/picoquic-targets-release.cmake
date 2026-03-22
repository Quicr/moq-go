#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "picoquic::picoquic-core" for configuration "Release"
set_property(TARGET picoquic::picoquic-core APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(picoquic::picoquic-core PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "C"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libpicoquic-core.a"
  )

list(APPEND _cmake_import_check_targets picoquic::picoquic-core )
list(APPEND _cmake_import_check_files_for_picoquic::picoquic-core "${_IMPORT_PREFIX}/lib/libpicoquic-core.a" )

# Import target "picoquic::picotls-core" for configuration "Release"
set_property(TARGET picoquic::picotls-core APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(picoquic::picotls-core PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "C"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libpicotls-core.a"
  )

list(APPEND _cmake_import_check_targets picoquic::picotls-core )
list(APPEND _cmake_import_check_files_for_picoquic::picotls-core "${_IMPORT_PREFIX}/lib/libpicotls-core.a" )

# Import target "picoquic::picotls-openssl" for configuration "Release"
set_property(TARGET picoquic::picotls-openssl APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(picoquic::picotls-openssl PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "C"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libpicotls-openssl.a"
  )

list(APPEND _cmake_import_check_targets picoquic::picotls-openssl )
list(APPEND _cmake_import_check_files_for_picoquic::picotls-openssl "${_IMPORT_PREFIX}/lib/libpicotls-openssl.a" )

# Import target "picoquic::picotls-minicrypto" for configuration "Release"
set_property(TARGET picoquic::picotls-minicrypto APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(picoquic::picotls-minicrypto PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "C"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libpicotls-minicrypto.a"
  )

list(APPEND _cmake_import_check_targets picoquic::picotls-minicrypto )
list(APPEND _cmake_import_check_files_for_picoquic::picotls-minicrypto "${_IMPORT_PREFIX}/lib/libpicotls-minicrypto.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
