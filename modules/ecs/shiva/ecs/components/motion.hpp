//
// Created by avendel on 24.10.2018.
//

#pragma once

#include <shiva/reflection/reflection.hpp>
#include <shiva/enums/enums.hpp>

namespace shiva::ecs
{
    struct motion
    {
        template <typename CPhysics>
        motion(CPhysics ptr) noexcept : physics_(ptr)
        {
        }

        reflect_class(motion)

        static constexpr auto reflected_functions() noexcept
        {
            return meta::makeMap();
        }

        static constexpr auto reflected_members() noexcept
        {
            return meta::makeMap();
        }

        std::shared_ptr<void> physics_{nullptr};
    };
}
