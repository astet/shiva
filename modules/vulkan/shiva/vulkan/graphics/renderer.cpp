//
// Created by Arthur Wendel on 20/10/2018.
//

#include "renderer.hpp"

#include <vector>
#include <boost/dll.hpp>
#include <vulkan/vulkan.hpp>

#include "device.hpp"

namespace shiva::vulkan
{
    class renderer::impl
    {
    public:
        impl() noexcept {}

        //! Public member functions overriden
        void update() noexcept {}

//        //! Reflection
//        reflect_class(renderer::impl)
//
//        static constexpr auto reflected_functions() noexcept;
//
//        static constexpr auto reflected_members() noexcept;

    private:
        vk::Instance instance_;

        std::vector<device> devices_;
    };

    renderer::renderer() noexcept
    {

    }

    //! Public static functions
    std::unique_ptr<shiva::graphics::renderer> renderer::create() noexcept
    {
        return std::make_unique<shiva::vulkan::renderer>();
    }

    //! Public member functions overriden
    void renderer::update() noexcept
    {

    }

    //! Reflection
    constexpr auto renderer::reflected_functions() noexcept
    {
        return meta::makeMap(reflect_function(&renderer::update));
    }

    constexpr auto renderer::reflected_members() noexcept
    {
        return meta::makeMap();
    }
}

BOOST_DLL_ALIAS(
    shiva::vulkan::renderer::create, // <-- this function is exported with...
    create_plugin                               // <-- ...this alias name
)
