//
// Created by Arthur on 19.10.2018.
//

#pragma once

#include <string>
#include <shiva/reflection/reflection.hpp>

namespace shiva::ecs
{
    struct hud_component
    {
        reflect_class(hud_component)

        static constexpr auto reflected_functions() noexcept
        {
            return meta::makeMap();
        }

        static constexpr auto reflected_members() noexcept
        {
            return meta::makeMap();
        }
    };
}
