set(MODULE_PATH
        ${CMAKE_CURRENT_SOURCE_DIR}/shiva/vulkan/graphics)

set(MODULE_PUBLIC_HEADERS
        "${MODULE_PATH}/renderer.hpp"
        )

set(MODULE_PRIVATE_SOURCES
        "${MODULE_PATH}/renderer.cpp")

set(MODULE_PRIVATE_HEADERS
        "${MODULE_PATH}/device.hpp")

set(MODULE_SOURCES
        ${MODULE_PUBLIC_HEADERS}
        ${MODULE_PRIVATE_SOURCES}
        ${MODULE_PRIVATE_HEADERS})