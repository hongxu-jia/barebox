/* SPDX-License-Identifier: GPL-2.0-only */
/* SPDX-FileCopyrightText: 2021 Yann Sionneau <ysionneau@kalray.eu>, Kalray Inc. */

#ifndef __ASM_DMA_H
#define __ASM_DMA_H

#include <linux/types.h>
#include <linux/build_bug.h>
#include <malloc.h>

#define DMA_ALIGNMENT	64

struct device;

#define dma_alloc_coherent dma_alloc_coherent
static inline void *dma_alloc_coherent(struct device *dev,
				       size_t size, dma_addr_t *dma_handle)
{
	BUILD_BUG_ON_MSG(1, "dma_alloc_coherent not supported: "
			"MMU support is required to map uncached pages");
	return NULL;
}

#define dma_free_coherent dma_free_coherent
static inline void dma_free_coherent(struct device *dev,
				     void *mem, dma_addr_t dma_handle,
				     size_t size)
{
	free(mem);
}

#endif /* __ASM_DMA_H */
