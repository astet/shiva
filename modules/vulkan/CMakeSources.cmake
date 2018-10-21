set(MODULE_PATH
        ${CMAKE_CURRENT_SOURCE_DIR}/shiva/vulkan)

set(MODULE_PUBLIC_HEADERS
        "${MODULE_PATH}/renderer.hpp"
        )

set(MODULE_PRIVATE_HEADERS
        "${MODULE_PATH}/renderer.cpp")

set(MODULE_SOURCES
        ${MODULE_PUBLIC_HEADERS}
        ${MODULE_PRIVATE_HEADERS})