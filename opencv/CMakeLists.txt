cmake_minimum_required (VERSION 2.6)
project (NavImage)
find_package (OpenCV REQUIRED)
set (NavImage_VERSION_MAJOR 2)
set (NavImage_VERSION_MINOR 3)
configure_file (
    "${PROJECT_SOURCE_DIR}/ImageConfig.h.in"
    "${PROJECT_BINARY_DIR}/ImageConfig.h"
    )
include_directories ("${PROJECT_BINARY_DIR}")
include_directories ("${PROJECT_SOURCE_DIR}/imageFuns")
add_subdirectory (imageFuns)
set (EXTRA_LIBS ${EXTRA_LIBS} imageFuns)
set (EXTRA_LIBS ${EXTRA_LIBS} ${OpenCV_LIBS})
add_executable (NavImage main.cpp)
target_link_libraries (NavImage ${EXTRA_LIBS})

set (CMAKE_INSTALL_PREFIX "/home/enali/Opencv/")
install (TARGETS NavImage DESTINATION bin)
install (FILES "${PROJECT_BINARY_DIR}/ImageConfig.h" DESTINATION include)

include (InstallRequiredSystemLibraries)
set (CPACK_PACKAGE_VERSION_MAJOR "${NavImage_VERSION_MAJOR}")
set (CPACK_PACKAGE_VERSION_MINOR "${NavImage_VERSION_MINOR}")
include (CPack)
