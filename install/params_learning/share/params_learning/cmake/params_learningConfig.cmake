# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_params_learning_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED params_learning_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(params_learning_FOUND FALSE)
  elseif(NOT params_learning_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(params_learning_FOUND FALSE)
  endif()
  return()
endif()
set(_params_learning_CONFIG_INCLUDED TRUE)

# output package information
if(NOT params_learning_FIND_QUIETLY)
  message(STATUS "Found params_learning: 0.0.0 (${params_learning_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'params_learning' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${params_learning_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(params_learning_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${params_learning_DIR}/${_extra}")
endforeach()
