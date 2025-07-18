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

#ifndef SIGNAL_SRC_DSP_RFFT_WRAPPERS_DSP_RFFT_INT16_H_
#define SIGNAL_SRC_DSP_RFFT_WRAPPERS_DSP_RFFT_INT16_H_

#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

namespace dsp_rfft_fixed16 {
#include "dsp/transform_functions.h"
}  // namespace dsp_rfft_fixed16
#undef FIXED_POINT

#endif  // SIGNAL_SRC_DSP_RFFT_WRAPPERS_DSP_RFFT_INT16_H_
