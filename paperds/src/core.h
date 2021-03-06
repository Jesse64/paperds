#pragma once
#include "common.h"
#include "print.h"

#define LOAD_OVERLAY_ITCM(name)	\
	do {	\
		int default_dma = FS_GetDefaultDMA();	\
		FS_SetDefaultDMA(FS_DMA_NOT_USE);	\
		FS_EXTERN_OVERLAY(name);	\
		FS_LoadOverlay(MI_PROCESSOR_ARM9, FS_OVERLAY_ID(name));	\
		FS_SetDefaultDMA(default_dma);	\
	} while (false);

#define CALLBACK_FUNC(accessor, class_name, func_name)										\
	accessor: void func_name##();															\
	public: static void func_name##(void* arg) { ((##class_name##*)arg)->##func_name##(); } \
	accessor:

//fix error in include (; removed)
#undef GX_FX32_FX10_MAX
#undef GX_FX32_FX10_MIN

#define GX_FX32_FX10_MAX          (fx32)(0x00000fff)
#define GX_FX32_FX10_MIN          (fx32)(0xfffff000)

typedef u8 uint8_t;
typedef u16 uint16_t;
typedef u32 uint32_t;
typedef u64 uint64_t;

typedef s8 int8_t;
typedef s16 int16_t;
typedef s32 int32_t;
typedef s64 int64_t;

#define MKTAG(a0,a1,a2,a3) ((u32)((a0) | ((a1) << 8) | ((a2) << 16) | ((a3) << 24))) 

#define NOCASH_Break() __asm{mov r11, r11}

extern NNSFndHeapHandle gHeapHandle;

void Core_PreInit();

#ifdef __cplusplus

void* operator new(std::size_t blocksize);
void* operator new[](std::size_t blocksize);
void operator delete(void *block) throw();
void operator delete[](void *block) throw();

#endif

void Core_Init();

#include "util.h"