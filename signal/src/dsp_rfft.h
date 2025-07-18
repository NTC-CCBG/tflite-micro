/* Copyright 2023 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#ifndef SIGNAL_SRC_DSP_RFFT_H_
#define SIGNAL_SRC_DSP_RFFT_H_

#include <stddef.h>
#include <stdint.h>

#include "signal/src/complex.h"

// TODO(b/286250473): remove namespace once de-duped libraries
namespace tflm_signal {

size_t DspRfftInt16GetStateSize(int32_t fft_length);

void* DspRfftInt16Init(int32_t fft_length, void* state, size_t state_size);

void DspRfftInt16Apply(void* state, const int16_t* input, Complex<int16_t>* output);

}  // namespace tflm_signal

#endif  // SIGNAL_SRC_DSP_RFFT_H_
