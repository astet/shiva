//
// Created by roman Sztergbaum on 15/06/2018.
//

#pragma once

#include <shiva/graphics/renderer.hpp>
#include <shiva/reflection/reflection.hpp>

namespace shiva::vulkan
{
    class renderer final : public shiva::graphics::renderer
    {
        class impl;
    public:
        renderer() noexcept;

        //! Public static functions
        static std::unique_ptr<shiva::graphics::renderer> create() noexcept;

        //! Public member functions overriden
        void update() noexcept final;

        //! Reflection
        reflect_class(renderer)

        static constexpr auto reflected_functions() noexcept;

        static constexpr auto reflected_members() noexcept;

    private:
        std::unique_ptr<impl> impl_;
    };
}