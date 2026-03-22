# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file LICENSE.rst or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION ${CMAKE_VERSION}) # this file comes with cmake

# If CMAKE_DISABLE_SOURCE_CHANGES is set to true and the source directory is an
# existing directory in our source tree, calling file(MAKE_DIRECTORY) on it
# would cause a fatal error, even though it would be a no-op.
if(NOT EXISTS "/Users/snk/work/tech/moq/quicr-go/build/_deps/picotls-src")
  file(MAKE_DIRECTORY "/Users/snk/work/tech/moq/quicr-go/build/_deps/picotls-src")
endif()
file(MAKE_DIRECTORY
  "/Users/snk/work/tech/moq/quicr-go/build/_deps/picotls-build"
  "/Users/snk/work/tech/moq/quicr-go/build/_deps/picotls-subbuild/picotls-populate-prefix"
  "/Users/snk/work/tech/moq/quicr-go/build/_deps/picotls-subbuild/picotls-populate-prefix/tmp"
  "/Users/snk/work/tech/moq/quicr-go/build/_deps/picotls-subbuild/picotls-populate-prefix/src/picotls-populate-stamp"
  "/Users/snk/work/tech/moq/quicr-go/build/_deps/picotls-subbuild/picotls-populate-prefix/src"
  "/Users/snk/work/tech/moq/quicr-go/build/_deps/picotls-subbuild/picotls-populate-prefix/src/picotls-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/snk/work/tech/moq/quicr-go/build/_deps/picotls-subbuild/picotls-populate-prefix/src/picotls-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/snk/work/tech/moq/quicr-go/build/_deps/picotls-subbuild/picotls-populate-prefix/src/picotls-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
