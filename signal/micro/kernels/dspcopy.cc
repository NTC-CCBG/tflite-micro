/* Copyright 2021 The TensorFlow Authors. All Rights Reserved.

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

#include <stdint.h>

#include "signal/src/dspcopy.h"

#include "tensorflow/lite/kernels/internal/tensor_ctypes.h"
#include "tensorflow/lite/kernels/kernel_util.h"
#include "tensorflow/lite/micro/flatbuffer_utils.h"
#include "tensorflow/lite/micro/kernels/kernel_util.h"
#include "tensorflow/lite/micro/memory_helpers.h"
#include "tensorflow/lite/micro/micro_context.h"
#include "tensorflow/lite/micro/micro_utils.h"

namespace tflite {
namespace {

// Tensor indices
constexpr int kInputTensor = 0;
constexpr int kOutputTensor = 0;

TfLiteStatus DspCopyEval(TfLiteContext* context, TfLiteNode* node) {
  const TfLiteEvalTensor* input =
      tflite::micro::GetEvalInput(context, node, kInputTensor);
  TfLiteEvalTensor* output =
      tflite::micro::GetEvalOutput(context, node, kOutputTensor);

  const int16_t* input_data = tflite::micro::GetTensorData<int16_t>(input);
  int16_t* output_data = tflite::micro::GetTensorData<int16_t>(output);

  int size = input->dims->data[0];
  for (int i = 1; i < input->dims->size; ++i) {
    size *= input->dims->data[i];
  }

  // for (int i = 0; i < size; ++i) {
  //   output_data[i] = input_data[i];
  // }

  ::tflm_signal::DspCopyInt16(input_data, output_data, size);

  return kTfLiteOk;
}

}  // namespace

namespace tflm_signal {

TFLMRegistration* Register_DSP_COPY() {
  static TFLMRegistration r = micro::RegisterOp(
      nullptr, nullptr, DspCopyEval, nullptr, nullptr);
  return &r;
}

}  // namespace tflm_signal
}  // namespace tflite