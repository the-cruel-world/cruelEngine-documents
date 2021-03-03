#pragma once

#include <vulkan/vulkan_core.h>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_inverse.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/string_cast.hpp>

// System Headers
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
#include <chrono>
#include <stdexcept>


class Earth{
    public:
        void run();

    private:
        void initVulkan();

        void mainLoop();
        void cleanUp();

        void setDebugMessager();
        void destoryDebugMessager();
    private:
        // main window
        int windowWidth = 800;
        int windowHeight = 600;
        GLFWwindow *mainWindow;
        void initWindow();

        // vulkan instance
	    VkInstance vkInstance;
        void createVulkanInstance();
        void destroyVulkanInstance();

        // validation layers
	    const bool enableValidationLayers = true;
	    const std::vector<const char*> validationLayers = {
            "VK_LAYER_KHRONOS_validation",
            "VK_LAYER_LUNARG_monitor"
        };
        bool checkValidationLayerSupport();

        // surface
        VkSurfaceKHR surface;
        void createWindowSurface();
        void destroyWindowSurface();

        // physicalDevice 
        VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
        bool isDeviceSuitable(VkPhysicalDevice device);
        void pickPhysicalDevice();

        // QueueFamily for device find
	    struct QueueFamilyIndices {
            int graphicsFamily = -1;
            int presentFamily = -1;
            bool isComplete() {
	            return graphicsFamily >= 0 && presentFamily >= 0;
            }
        };
        QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);

        // extensions
        const std::vector<const char*> vkDeviceExtensions = {
            VK_KHR_SWAPCHAIN_EXTENSION_NAME
        };
        std::vector<const char*> getRequiredExtensions();
        bool checkDeviceExtensionSupport(VkPhysicalDevice device);

        // logic devices
        VkDevice logicalDevice;
        void createLogicalDevice();
        void destroyLogicalDevice();

		VkQueue presentQueue;
		VkQueue graphicsQueue;

        // swap chain
        struct SwapChainSupportDetails {
            VkSurfaceCapabilitiesKHR capabilities;
            std::vector<VkSurfaceFormatKHR> formats;
            std::vector<VkPresentModeKHR> presentModes;
        };
        VkSwapchainKHR swapChain;
        void createSwapChain();
        void destroySwapChain();
        SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);

        VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
        VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR> availablePresentModes);
        VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);

        // image swap chain
        std::vector<VkImage> swapChainImages;
        VkFormat swapChainImageFormat;
        VkExtent2D swapChainExtent;

        // swapchain image view
        std::vector<VkImageView> swapChainImageViews;
        void createImageViews();
        void destroyImageViews();


        // Graphics Pipeline
        VkPipeline graphicsPipeline;
        VkPipelineLayout pipelineLayout;
        void createGraphicPipeline();
        void destroyGraphicPipeline();

        // Readin shaders
        static std::vector<char> readFile(const std::string& filename);
        VkShaderModule createShaderModule(const std::vector<char>& code);

        // render pass
        VkRenderPass renderPass;
        void createRenderPass();
        void destroyRenderPass();

        // frame buffers
        std::vector<VkFramebuffer> swapChainFramebuffers;
        void createFrameBuffer();
        void destroyFrameBuffer();

        // command buffer & pool
        std::vector<VkCommandBuffer> commandBuffers;
        VkCommandPool commandPool;
        void createCommandBuffer();
        void destroyCommandBuffer();
        void createCommandPool();
        void destroyCommandPool();

        // Draw Frame
        VkSemaphore imageAvailableSemaphore;
        VkSemaphore renderFinishedSemaphore;
        void drawFrame();
        void createSemaphores();
        void destroySemaphores();
 
        // maxframe in meme
        int MAX_FRAMES_IN_FLIGHT = 2;
        std::vector<VkSemaphore> imageAvailableSemaphores;
        std::vector<VkSemaphore> renderFinishedSemaphores;
        std::vector<VkFence> inFlightFences;
        std::vector<VkFence> imagesInFlight;

        size_t currentFrame = 0;
};
