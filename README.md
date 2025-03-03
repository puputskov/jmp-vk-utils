# jmp-vk-utils.h
Simple header only utility C library for Vulkan

## Feature flags
| Feature flag                 | Description                                    | Note         |
|------------------------------|------------------------------------------------|--------------|
| JMP_VK_UTILS_ENABLE_ALL      | Enables all feature flags                      |              |
| JMP_VK_UTILS_ENABLE_SET_NAME | Introduces `jmp_vkSetName`                     | Requires C11 |
| JMP_VK_UTILS_ENABLE_PRINT    | Introduces `jmp_vkPrintPhysicalDeviceFeatures` |              |

## Usage
```C
#define JMP_VK_UTILS_ENABLE_ALL
#include "jmp-vk-utils.h"

// ...
VkImage image = VK_NULL_HANDLE;
vkCreateImage(device, &image_create_info, NULL, &image);
jmp_vkSetName (device, image, "My Image");
```
