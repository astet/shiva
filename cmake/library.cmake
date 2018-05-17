option(TEST_CMAKE_PERSONAL_FEATURES "test personal cmake features" OFF)

if (TEST_CMAKE_PERSONAL_FEATURES)
    include(${CMAKE_MODULE_PATH}/test_features.cmake)
endif()

include(buildtype)
include(color)
include(platform)
include(compiler)
include(compiler_utility)
include(unit_tests)
include(directory)
include(module)
