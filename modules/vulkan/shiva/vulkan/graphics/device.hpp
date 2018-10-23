//
// Created by avendel on 22.10.2018.
//

#pragma once

#include <vulkan/vulkan.hpp>

namespace shiva::vulkan {

    class device {
    public:

    private:
        vk::Device                          device_;
        vk::PhysicalDevice*					gpu_;
        vk::PhysicalDeviceProperties		gpu_properties_;
        vk::PhysicalDeviceMemoryProperties	memory_properties_;
    };

}
