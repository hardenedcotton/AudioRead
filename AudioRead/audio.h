// libstdaudio
// Copyright (c) 2018 - Timur Doumler
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

#pragma once

#include <optional>

// TODO: this is a temporary measure until std::span becomes available
#include "cpp/span.hpp"
template <typename ElementType, std::ptrdiff_t Extent = TCB_SPAN_NAMESPACE_NAME::dynamic_extent>
using span = TCB_SPAN_NAMESPACE_NAME::span<ElementType, Extent>;

#define _LIBSTDAUDIO_NAMESPACE std::experimental

#define _LIBSTDAUDIO_NAMESPACE_BEGIN namespace _LIBSTDAUDIO_NAMESPACE {
#define _LIBSTDAUDIO_NAMESPACE_END }

#include <__audio_buffer.h>
#include <__audio_device.h>

#ifdef __APPLE__
  #include <audio_backend/__coreaudio_backend.h>
#elif defined(_WIN32)
  #include <audio_backend/__wasapi_backend.h>
#else
  #include <audio_backend/__null_backend.h>
#endif // __APPLE__
