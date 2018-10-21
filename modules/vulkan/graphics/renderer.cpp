//
// Created by Arthur Wendel on 20/10/2018.
//

#include "renderer.hpp"

#include <fstream>
#include <iomanip>
#include <imgui.h>
#include <boost/dll.hpp>
#include <shiva/filesystem/filesystem.hpp>

namespace shiva::vulkan
{
    renderer::render_system() noexcept
    {

    }

    //! Public static functions
    std::unique_ptr<shiva::graphics::renderer> renderer::create(shiva::entt::dispatcher &dispatcher,
                                                                           shiva::entt::entity_registry &registry,
                                                                           const float &fixed_delta_time) noexcept
    {
        return std::make_unique<shiva::plugins::render_system>(dispatcher, registry, fixed_delta_time);
    }

    //! Public member functions overriden
    void renderer::update() noexcept
    {

    }

    //! Reflection
    constexpr auto render_system::reflected_functions() noexcept
    {
        return meta::makeMap(reflect_function(&render_system::update));
    }

    constexpr auto render_system::reflected_members() noexcept
    {
        return meta::makeMap();
    }
}

BOOST_DLL_ALIAS(
    shiva::plugins::render_system::system_creator, // <-- this function is exported with...
    create_plugin                               // <-- ...this alias name
)
