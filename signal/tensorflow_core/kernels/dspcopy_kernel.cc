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

#include <cstdint>

#include "signal/src/dspcopy.h"
#include "tensorflow/core/framework/op_kernel.h"

namespace tensorflow {
namespace signal {

class DspCopyOp : public tensorflow::OpKernel {
 public:
  explicit DspCopyOp(tensorflow::OpKernelConstruction* context)
      : OpKernel(context) {
  }

  ~DspCopyOp() {}

  void Compute(OpKernelContext* context) override {
    const tensorflow::Tensor& input_tensor = context->input(0);

    tensorflow::Tensor* output_tensor = nullptr;
    OP_REQUIRES_OK(context,
                   context->allocate_output(0, input_tensor.shape(), &output_tensor));

    auto input_data = input_tensor.flat<int16_t>().data();
    auto output_data = output_tensor->flat<int16_t>().data();

    ::tflm_signal::DspCopyInt16(input_data, output_data, input_tensor.NumElements());

  }
};

// TODO(b/286250473): change back name after name clash resolved
REGISTER_KERNEL_BUILDER(Name("SignalDspCopy").Device(tensorflow::DEVICE_CPU),
                        DspCopyOp);

}  // namespace signal
}  // namespace tensorflow
