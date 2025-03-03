# jmp-vk-utils.h
Simple header only utility C library for Vulkan

## Feature flags
| Feature flag                        | Description                                    | Note         |
|-------------------------------------|------------------------------------------------|--------------|
| JMP_VK_UTILS_ENABLE_ALL             | Enables all feature flags                      |              |
| JMP_VK_UTILS_ENABLE_SET_NAME        | Introduces `jmp_vkSetName`                     | Requires C11 |
| JMP_VK_UTILS_ENABLE_PRINT           | Introduces `jmp_vkPrintPhysicalDeviceFeatures` |              |
| JMP_VK_UTILS_ENABLE_VK_STRUCTURE    | Introduces `jmp_Vk....` macros which have `.sType` and `.pNext` filled by default |              |

## Usage
```C
#define JMP_VK_UTILS_ENABLE_ALL
#include "jmp-vk-utils.h"

// ...

VkInstance instance;
vkCreateInstance (&jmp_VkInstanceCreateInfo(
	.flags = 0,
	.pApplicationInfo = &jmp_VkApplicationInfo(
		.pApplicationName = "App",
		.applicationVersion = VK_MAKE_VERSION(1, 0, 0),
		.pEngineName = "Engine",
		.engineVersion = VK_MAKE_VERSION(5, 4, 2),
		.apiVersion = VK_API_VERSION_1_0
	),
	.enabledLayerCount = number_of_enabled_layers,
	.ppEnabledLayerNames = enabled_layers,
	.enabledExtensionCount = number_of_enabled_extensions,
	.ppEnabledExtensionNames = enabled_extensions,
), NULL, &instance);

// ...
VkImage image = VK_NULL_HANDLE;
vkCreateImage(device, &image_create_info, NULL, &image);
jmp_vkSetName (device, image, "My Image");
```
