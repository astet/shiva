//
// Created by roman Sztergbaum on 15/06/2018.
//

#pragma once

#include <shiva/dll/plugin.hpp>
#include <shiva/reflection/reflection.hpp>

namespace shiva::vulkan
{
    class renderer final : public shiva::plugins::<renderer>
    {
    public:
        renderer() noexcept;

        //! Public static functions
        static std::unique_ptr<shiva::plugins::render_system> create(entt::dispatcher &dispatcher,
                                                               entt::entity_registry &registry,
                                                               const float &fixed_delta_time) noexcept;

        //! Public member functions overriden
        void update() noexcept final;

        //! Reflection
        reflect_class(renderer)

        static constexpr auto reflected_functions() noexcept;

        static constexpr auto reflected_members() noexcept;

    private:

    };
}