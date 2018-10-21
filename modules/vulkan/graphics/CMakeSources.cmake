set(MODULE_PATH
        ${CMAKE_CURRENT_SOURCE_DIR}/graphics)


set(MODULE_PUBLIC_SOURCES
        "${MODULE_PATH}/system-vulkan-graphics.cpp"
        )

set(MODULE_PUBLIC_HEADERS
        "${MODULE_PATH}/system-vulkan-graphics.hpp"
        "${MODULE_PATH}/window_config.hpp"
        )

set(MODULE_PRIVATE_HEADERS
        "")

set(MODULE_SOURCES
        ${MODULE_PUBLIC_SOURCES}
        ${MODULE_PUBLIC_HEADERS}
        ${MODULE_PRIVATE_HEADERS})