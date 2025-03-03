/*
Copyright (c) 2025 Jyri Puputti

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the “Software”), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
of the Software, and to permit persons to whom the Software is furnished to do
so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef JMP_VK_UTILS_H
#define JMP_VK_UTILS_H

#include <vulkan/vulkan.h>

#ifdef JMP_VK_UTILS_ENABLE_ALL
	#define JMP_VK_UTILS_ENABLE_SET_NAME
	#define JMP_VK_UTILS_ENABLE_PRINT
#endif // JMP_VK_UTILS_ENABLE_ALL

#ifdef __STDC_VERSION__
#if __STDC_VERSION__ >= 201112L
#define JMP_VK_UTILS_C11
#endif // __STDC_VERSION__ >= 201112L
#endif // __STDC_VERSION__

#define jmp_vk_util_array_size(x)			(sizeof (x) / sizeof(*(x)))
#define jmp_vk_util_offset_of(type, field)	((uint64_t)(&(((type*)(0))->field)))

#if defined(JMP_VK_UTILS_ENABLE_SET_NAME) && defined(JMP_VK_UTILS_C11)
#define JMP_VK_HANDLE_TO_VK_OBJECT_TYPE(handle)	_Generic((handle),				\
						default: VK_OBJECT_TYPE_UNKNOWN,						\
					 VkInstance: VK_OBJECT_TYPE_INSTANCE,						\
			   VkPhysicalDevice: VK_OBJECT_TYPE_PHYSICAL_DEVICE,				\
					   VkDevice: VK_OBJECT_TYPE_DEVICE,							\
						VkQueue: VK_OBJECT_TYPE_QUEUE,							\
					VkSemaphore: VK_OBJECT_TYPE_SEMAPHORE,						\
				VkCommandBuffer: VK_OBJECT_TYPE_COMMAND_BUFFER,					\
						VkFence: VK_OBJECT_TYPE_FENCE,							\
				 VkDeviceMemory: VK_OBJECT_TYPE_DEVICE_MEMORY,					\
					   VkBuffer: VK_OBJECT_TYPE_BUFFER,							\
						VkImage: VK_OBJECT_TYPE_IMAGE,							\
						VkEvent: VK_OBJECT_TYPE_EVENT,							\
					VkQueryPool: VK_OBJECT_TYPE_QUERY_POOL,						\
				   VkBufferView: VK_OBJECT_TYPE_BUFFER_VIEW,					\
					VkImageView: VK_OBJECT_TYPE_IMAGE_VIEW,						\
				 VkShaderModule: VK_OBJECT_TYPE_SHADER_MODULE,					\
				VkPipelineCache: VK_OBJECT_TYPE_PIPELINE_CACHE,					\
			   VkPipelineLayout: VK_OBJECT_TYPE_PIPELINE_LAYOUT,				\
				   VkRenderPass: VK_OBJECT_TYPE_RENDER_PASS,					\
					 VkPipeline: VK_OBJECT_TYPE_PIPELINE,						\
		  VkDescriptorSetLayout: VK_OBJECT_TYPE_DESCRIPTOR_SET_LAYOUT,			\
					  VkSampler: VK_OBJECT_TYPE_SAMPLER,						\
			   VkDescriptorPool: VK_OBJECT_TYPE_DESCRIPTOR_POOL,				\
				VkDescriptorSet: VK_OBJECT_TYPE_DESCRIPTOR_SET,					\
				  VkFramebuffer: VK_OBJECT_TYPE_FRAMEBUFFER,					\
				  VkCommandPool: VK_OBJECT_TYPE_COMMAND_POOL,					\
	   VkSamplerYcbcrConversion: VK_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION,		\
	 VkDescriptorUpdateTemplate: VK_OBJECT_TYPE_DESCRIPTOR_UPDATE_TEMPLATE,		\
			  VkPrivateDataSlot: VK_OBJECT_TYPE_PRIVATE_DATA_SLOT,				\
				   VkSurfaceKHR: VK_OBJECT_TYPE_SURFACE_KHR,					\
				 VkSwapchainKHR: VK_OBJECT_TYPE_SWAPCHAIN_KHR,					\
				   VkDisplayKHR: VK_OBJECT_TYPE_DISPLAY_KHR,					\
			   VkDisplayModeKHR: VK_OBJECT_TYPE_DISPLAY_MODE_KHR,				\
	   VkDebugReportCallbackEXT: VK_OBJECT_TYPE_DEBUG_REPORT_CALLBACK_EXT,		\
			  VkVideoSessionKHR: VK_OBJECT_TYPE_VIDEO_SESSION_KHR,				\
	VkVideoSessionParametersKHR: VK_OBJECT_TYPE_VIDEO_SESSION_PARAMETERS_KHR,	\
				  VkCuModuleNVX: VK_OBJECT_TYPE_CU_MODULE_NVX,					\
				VkCuFunctionNVX: VK_OBJECT_TYPE_CU_FUNCTION_NVX,				\
	   VkDebugUtilsMessengerEXT: VK_OBJECT_TYPE_DEBUG_UTILS_MESSENGER_EXT,		\
	 VkAccelerationStructureKHR: VK_OBJECT_TYPE_ACCELERATION_STRUCTURE_KHR,		\
		   VkValidationCacheEXT: VK_OBJECT_TYPE_VALIDATION_CACHE_EXT,			\
	  VkAccelerationStructureNV: VK_OBJECT_TYPE_ACCELERATION_STRUCTURE_NV,		\
VkPerformanceConfigurationINTEL: VK_OBJECT_TYPE_PERFORMANCE_CONFIGURATION_INTEL,\
		 VkDeferredOperationKHR: VK_OBJECT_TYPE_DEFERRED_OPERATION_KHR,			\
	 VkIndirectCommandsLayoutNV: VK_OBJECT_TYPE_INDIRECT_COMMANDS_LAYOUT_NV,	\
				 VkCudaModuleNV: VK_OBJECT_TYPE_CUDA_MODULE_NV,					\
			   VkCudaFunctionNV: VK_OBJECT_TYPE_CUDA_FUNCTION_NV,				\
				  VkMicromapEXT: VK_OBJECT_TYPE_MICROMAP_EXT,					\
		 VkOpticalFlowSessionNV: VK_OBJECT_TYPE_OPTICAL_FLOW_SESSION_NV,		\
					VkShaderEXT: VK_OBJECT_TYPE_SHADER_EXT,						\
			VkPipelineBinaryKHR: VK_OBJECT_TYPE_PIPELINE_BINARY_KHR,			\
	VkIndirectCommandsLayoutEXT: VK_OBJECT_TYPE_INDIRECT_COMMANDS_LAYOUT_EXT,	\
	  VkIndirectExecutionSetEXT: VK_OBJECT_TYPE_INDIRECT_EXECUTION_SET_EXT)


#define jmp_vkSetName(device, pObjectHandle, pObjectName) jmp_vkSetName__impl((device), JMP_VK_HANDLE_TO_VK_OBJECT_TYPE (pObjectHandle), pObjectHandle, (pObjectName))
inline VkResult jmp_vkSetName__impl (VkDevice device, VkObjectType objectType, void *pObjectHandle, const char *pObjectName)
{
	VkResult result = VK_SUCCESS;
	PFN_vkSetDebugUtilsObjectNameEXT jmp_internal__vkSetDebugUtilsObjectNameEXT = NULL;
	if (NULL != device)
	{
		jmp_internal__vkSetDebugUtilsObjectNameEXT = (PFN_vkSetDebugUtilsObjectNameEXT) vkGetDeviceProcAddr (device, "vkSetDebugUtilsObjectNameEXT");
	}
	
	if (NULL != jmp_internal__vkSetDebugUtilsObjectNameEXT)
	{
		VkDebugUtilsObjectNameInfoEXT name_info = {
			.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT,
			.pNext = NULL,
			.objectType = objectType,
			.objectHandle = ((uint64_t) pObjectHandle),
			.pObjectName = pObjectName,
		};

		result = jmp_internal__vkSetDebugUtilsObjectNameEXT (device, &name_info);
	}

	return (result);
}

#endif // JMP_VK_UTILS_ENABLE_SET_NAME




#if defined(JMP_VK_UTILS_ENABLE_PRINT)

typedef struct jmp_vk_util_field_info_t
{
	const char *name;
	uint64_t offset;
} jmp_vk_util_field_info_t;

typedef void(*jmp_vk_util_pfn_print_t)(const char *field_name, VkBool32 field_value);
inline void jmp_vkPrintPhysicalDeviceFeatures(const VkPhysicalDeviceFeatures *features, jmp_vk_util_pfn_print_t pfn_print)
{
	#define JMP_VK_UTIL_FIELD_INFO(t, f) { .name = #f, .offset = jmp_vk_util_offset_of (t, f) }
	static const jmp_vk_util_field_info_t jmp_vk_utils_VkPhysicalDeviceFeatures_fields [] = {
		JMP_VK_UTIL_FIELD_INFO (VkPhysicalDeviceFeatures, robustBufferAccess),
		JMP_VK_UTIL_FIELD_INFO (VkPhysicalDeviceFeatures, fullDrawIndexUint32),
		JMP_VK_UTIL_FIELD_INFO (VkPhysicalDeviceFeatures, imageCubeArray),
		JMP_VK_UTIL_FIELD_INFO (VkPhysicalDeviceFeatures, independentBlend),
		JMP_VK_UTIL_FIELD_INFO (VkPhysicalDeviceFeatures, geometryShader),
		JMP_VK_UTIL_FIELD_INFO (VkPhysicalDeviceFeatures, tessellationShader),
		JMP_VK_UTIL_FIELD_INFO (VkPhysicalDeviceFeatures, sampleRateShading),
		JMP_VK_UTIL_FIELD_INFO (VkPhysicalDeviceFeatures, dualSrcBlend),
		JMP_VK_UTIL_FIELD_INFO (VkPhysicalDeviceFeatures, logicOp),
		JMP_VK_UTIL_FIELD_INFO (VkPhysicalDeviceFeatures, multiDrawIndirect),
		JMP_VK_UTIL_FIELD_INFO (VkPhysicalDeviceFeatures, drawIndirectFirstInstance),
		JMP_VK_UTIL_FIELD_INFO (VkPhysicalDeviceFeatures, depthClamp),
		JMP_VK_UTIL_FIELD_INFO (VkPhysicalDeviceFeatures, depthBiasClamp),
		JMP_VK_UTIL_FIELD_INFO (VkPhysicalDeviceFeatures, fillModeNonSolid),
		JMP_VK_UTIL_FIELD_INFO (VkPhysicalDeviceFeatures, depthBounds),
		JMP_VK_UTIL_FIELD_INFO (VkPhysicalDeviceFeatures, wideLines),
		JMP_VK_UTIL_FIELD_INFO (VkPhysicalDeviceFeatures, largePoints),
		JMP_VK_UTIL_FIELD_INFO (VkPhysicalDeviceFeatures, alphaToOne),
		JMP_VK_UTIL_FIELD_INFO (VkPhysicalDeviceFeatures, multiViewport),
		JMP_VK_UTIL_FIELD_INFO (VkPhysicalDeviceFeatures, samplerAnisotropy),
		JMP_VK_UTIL_FIELD_INFO (VkPhysicalDeviceFeatures, textureCompressionETC2),
		JMP_VK_UTIL_FIELD_INFO (VkPhysicalDeviceFeatures, textureCompressionASTC_LDR),
		JMP_VK_UTIL_FIELD_INFO (VkPhysicalDeviceFeatures, textureCompressionBC),
		JMP_VK_UTIL_FIELD_INFO (VkPhysicalDeviceFeatures, occlusionQueryPrecise),
		JMP_VK_UTIL_FIELD_INFO (VkPhysicalDeviceFeatures, pipelineStatisticsQuery),
		JMP_VK_UTIL_FIELD_INFO (VkPhysicalDeviceFeatures, vertexPipelineStoresAndAtomics),
		JMP_VK_UTIL_FIELD_INFO (VkPhysicalDeviceFeatures, fragmentStoresAndAtomics),
		JMP_VK_UTIL_FIELD_INFO (VkPhysicalDeviceFeatures, shaderTessellationAndGeometryPointSize),
		JMP_VK_UTIL_FIELD_INFO (VkPhysicalDeviceFeatures, shaderImageGatherExtended),
		JMP_VK_UTIL_FIELD_INFO (VkPhysicalDeviceFeatures, shaderStorageImageExtendedFormats),
		JMP_VK_UTIL_FIELD_INFO (VkPhysicalDeviceFeatures, shaderStorageImageMultisample),
		JMP_VK_UTIL_FIELD_INFO (VkPhysicalDeviceFeatures, shaderStorageImageReadWithoutFormat),
		JMP_VK_UTIL_FIELD_INFO (VkPhysicalDeviceFeatures, shaderStorageImageWriteWithoutFormat),
		JMP_VK_UTIL_FIELD_INFO (VkPhysicalDeviceFeatures, shaderUniformBufferArrayDynamicIndexing),
		JMP_VK_UTIL_FIELD_INFO (VkPhysicalDeviceFeatures, shaderSampledImageArrayDynamicIndexing),
		JMP_VK_UTIL_FIELD_INFO (VkPhysicalDeviceFeatures, shaderStorageBufferArrayDynamicIndexing),
		JMP_VK_UTIL_FIELD_INFO (VkPhysicalDeviceFeatures, shaderStorageImageArrayDynamicIndexing),
		JMP_VK_UTIL_FIELD_INFO (VkPhysicalDeviceFeatures, shaderClipDistance),
		JMP_VK_UTIL_FIELD_INFO (VkPhysicalDeviceFeatures, shaderCullDistance),
		JMP_VK_UTIL_FIELD_INFO (VkPhysicalDeviceFeatures, shaderFloat64),
		JMP_VK_UTIL_FIELD_INFO (VkPhysicalDeviceFeatures, shaderInt64),
		JMP_VK_UTIL_FIELD_INFO (VkPhysicalDeviceFeatures, shaderInt16),
		JMP_VK_UTIL_FIELD_INFO (VkPhysicalDeviceFeatures, shaderResourceResidency),
		JMP_VK_UTIL_FIELD_INFO (VkPhysicalDeviceFeatures, shaderResourceMinLod),
		JMP_VK_UTIL_FIELD_INFO (VkPhysicalDeviceFeatures, sparseBinding),
		JMP_VK_UTIL_FIELD_INFO (VkPhysicalDeviceFeatures, sparseResidencyBuffer),
		JMP_VK_UTIL_FIELD_INFO (VkPhysicalDeviceFeatures, sparseResidencyImage2D),
		JMP_VK_UTIL_FIELD_INFO (VkPhysicalDeviceFeatures, sparseResidencyImage3D),
		JMP_VK_UTIL_FIELD_INFO (VkPhysicalDeviceFeatures, sparseResidency2Samples),
		JMP_VK_UTIL_FIELD_INFO (VkPhysicalDeviceFeatures, sparseResidency4Samples),
		JMP_VK_UTIL_FIELD_INFO (VkPhysicalDeviceFeatures, sparseResidency8Samples),
		JMP_VK_UTIL_FIELD_INFO (VkPhysicalDeviceFeatures, sparseResidency16Samples),
		JMP_VK_UTIL_FIELD_INFO (VkPhysicalDeviceFeatures, sparseResidencyAliased),
		JMP_VK_UTIL_FIELD_INFO (VkPhysicalDeviceFeatures, variableMultisampleRate),
		JMP_VK_UTIL_FIELD_INFO (VkPhysicalDeviceFeatures, inheritedQueries),
	};
	#undef JMP_VK_UTIL_FIELD_INFO

	uint8_t *ptr = (uint8_t *) features;
	for (uint32_t i = 0; i < jmp_vk_util_array_size (jmp_vk_utils_VkPhysicalDeviceFeatures_fields); ++ i)
	{
		jmp_vk_util_field_info_t field = jmp_vk_utils_VkPhysicalDeviceFeatures_fields [i];
		pfn_print (field.name, *((VkBool32*)(ptr + field.offset)));
	}
}

#endif // JMP_VK_UTILS_ENABLE_PRINT

#endif // JMP_VK_UTILS_H
