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
#include "signal/src/dspcopy_wrappers/dspcopy_int16.h"
#include "signal/src/dspcopy.h"

// TODO(b/286250473): remove namespace once de-duped libraries
namespace tflm_signal {

void DspCopyInt16(const int16_t *input, int16_t *output, int32_t fft_length) {
  return dspcopy_fixed16::arm_copy_q15(
      reinterpret_cast<const dspcopy_fixed16::q15_t*>(input),
      reinterpret_cast<dspcopy_fixed16::q15_t*>(output), fft_length);
}

}  // namespace tflm_signal
