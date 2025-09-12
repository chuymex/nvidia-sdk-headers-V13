/*
 * This copyright notice applies to this header file only:
 *
 * Copyright (c) 2010-2024 NVIDIA Corporation
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the software, and to permit persons to whom the
 * software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

/*****************************************************************************************************/
//! \file cuviddec.h
//! NVDECODE API provides video decoding interface to NVIDIA GPU devices.
//! This file contains constants, structure definitions and function prototypes used for decoding.
/*****************************************************************************************************/

#if !defined(__CUDA_VIDEO_H__)
#define __CUDA_VIDEO_H__

#ifndef __cuda_cuda_h__
#include <cuda.h>
#endif // __cuda_cuda_h__

#if defined(_WIN64) || defined(__LP64__) || defined(__x86_64) || defined(AMD64) || defined(_M_AMD64)
#if (CUDA_VERSION >= 3020) && (!defined(CUDA_FORCE_API_VERSION) || (CUDA_FORCE_API_VERSION >= 3020))
#define __CUVID_DEVPTR64
#endif
#endif

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

typedef void *CUvideodecoder;
typedef struct _CUcontextlock_st *CUvideoctxlock;

/*********************************************************************************/
//! \enum cudaVideoCodec
//! Video codec enums
//! These enums are used in CUVIDDECODECREATEINFO and CUVIDDECODECAPS structures
/*********************************************************************************/
typedef enum cudaVideoCodec_enum {
    cudaVideoCodec_MPEG1=0,                                         /**<  MPEG1             */
    cudaVideoCodec_MPEG2,                                           /**<  MPEG2             */
    cudaVideoCodec_MPEG4,                                           /**<  MPEG4             */
    cudaVideoCodec_VC1,                                             /**<  VC1               */
    cudaVideoCodec_H264,                                            /**<  H264              */
    cudaVideoCodec_JPEG,                                            /**<  JPEG              */
    cudaVideoCodec_H264_SVC,                                        /**<  H264-SVC          */
    cudaVideoCodec_H264_MVC,                                        /**<  H264-MVC          */
    cudaVideoCodec_HEVC,                                            /**<  HEVC              */
    cudaVideoCodec_VP8,                                             /**<  VP8               */
    cudaVideoCodec_VP9,                                             /**<  VP9               */
    cudaVideoCodec_AV1,                                             /**<  AV1               */
    cudaVideoCodec_NumCodecs,                                       /**<  Max codecs        */
    // Uncompressed YUV
    cudaVideoCodec_YUV420 = ((...