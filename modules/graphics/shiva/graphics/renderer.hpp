//
// Created by Arthur on 21.10.2018.
//

#pragma once

#include <shiva/reflection/reflection.hpp>

namespace shiva::graphics {
    class renderer
    {
    public:
        //! Public static functions
        static std::unique_ptr<shiva::graphics::renderer> create() noexcept;

        //! Public member functions overriden
        virtual void update() noexcept = 0;

//        //! Reflection
//        reflect_class(renderer)
//
//        static constexpr auto reflected_functions() noexcept;
//
//        static constexpr auto reflected_members() noexcept;
    };
}
