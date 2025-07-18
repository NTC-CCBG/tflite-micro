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

#include <stddef.h>
#include <stdint.h>

#include "signal/src/complex.h"
#include "signal/src/dsp_rfft_wrappers/dsp_rfft_int16.h"
#include "signal/src/dsp_rfft.h"

// TODO(b/286250473): remove namespace once de-duped libraries
namespace tflm_signal {


size_t DspRfftInt16GetStateSize(int32_t fft_length) {
  (void)fft_length;
  return sizeof(dsp_rfft_fixed16::arm_rfft_instance_q15);
}

void* DspRfftInt16Init(int32_t fft_length, void* state, size_t state_size) {
  if (state == nullptr || state_size < sizeof(dsp_rfft_fixed16::arm_rfft_instance_q15)) {
    return nullptr;
  }

  auto rfft_instance = reinterpret_cast<dsp_rfft_fixed16::arm_rfft_instance_q15*>(state);
  dsp_rfft_fixed16::arm_status status =
      dsp_rfft_fixed16::arm_rfft_init_q15(rfft_instance, static_cast<uint32_t>(fft_length), 0, 1);

  if (status != dsp_rfft_fixed16::ARM_MATH_SUCCESS) {
    return nullptr;
  }
  return rfft_instance;
}

void DspRfftInt16Apply(void* state, const int16_t* input,
                       Complex<int16_t>* output) {
  if (state == nullptr || input == nullptr || output == nullptr) {
    return;
  }

  auto rfft_instance = reinterpret_cast<dsp_rfft_fixed16::arm_rfft_instance_q15*>(state);

  dsp_rfft_fixed16::arm_rfft_q15(
      rfft_instance,
      const_cast<dsp_rfft_fixed16::q15_t*>(
          reinterpret_cast<const dsp_rfft_fixed16::q15_t*>(input)),
      reinterpret_cast<dsp_rfft_fixed16::q15_t*>(output));
}

}  // namespace tflm_signal
