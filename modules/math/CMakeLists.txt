include(CMakeSources.cmake)

set(MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR})
find_package(glm REQUIRED)
CREATE_MODULE(shiva::math "${MODULE_SOURCES}" ${MODULE_PATH})
target_link_libraries(math INTERFACE glm)


AUTO_TARGETS_MODULE_INSTALL(math)