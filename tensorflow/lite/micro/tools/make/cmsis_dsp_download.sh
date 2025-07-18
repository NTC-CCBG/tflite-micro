#!/bin/bash
# Copyright 2021 The TensorFlow Authors. All Rights Reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
# ==============================================================================
#
# Called with following arguments:
# 1 - Path to the downloads folder which is typically
#    ${TENSORFLOW_ROOT}tensorflow/lite/micro/tools/make/downloads
# 2 - (optional) TENSORFLOW_ROOT: path to root of the TFLM tree (relative to directory from where the script is called.
# This script is called from the Makefile and uses the following convention to
# enable determination of sucess/failure:
#
#   - If the script is successful, the only output on stdout should be SUCCESS.
#     The makefile checks for this particular string.
#
#   - Any string on stdout that is not SUCCESS will be shown in the makefile as
#     the cause for the script to have failed.
#
#   - Any other informational prints should be on stderr.

set -e

source ${2}tensorflow/lite/micro/tools/make/bash_helpers.sh

DOWNLOADS_DIR=${1}
if [ ! -d ${DOWNLOADS_DIR} ]; then
  echo "The top-level downloads directory: ${DOWNLOADS_DIR} does not exist."
  exit 1
fi

DOWNLOADED_CMSIS_DSP_PATH=${DOWNLOADS_DIR}/cmsis_dsp

if [ -d ${DOWNLOADED_CMSIS_DSP_PATH} ]; then
  echo >&2 "${DOWNLOADED_CMSIS_DSP_PATH} already exists, skipping the download."
else

  CMSIS_DSP_URL="http://github.com/ARM-software/CMSIS-DSP/archive/03c78a997d9ee65a30ad7d869e842412c003aff7.zip"
  CMSIS_DSP_MD5="12adb9105f83e7e638c860eca4c8a9b4"

  TEMPDIR="$(mktemp -d)"
  TEMPFILE="${TEMPDIR}/03c78a997d9ee65a30ad7d869e842412c003aff7.zip"
  wget ${CMSIS_DSP_URL} -O "${TEMPFILE}" >&2
  check_md5 "${TEMPFILE}" ${CMSIS_DSP_MD5}

  unzip -qo "$TEMPFILE" -d "${TEMPDIR}" >&2
  mv "${TEMPDIR}/CMSIS-DSP-03c78a997d9ee65a30ad7d869e842412c003aff7" ${DOWNLOADED_CMSIS_DSP_PATH}
  rm -rf "${TEMPDIR}"

  pushd ${DOWNLOADED_CMSIS_DSP_PATH} > /dev/null
  create_git_repo ./
  popd > /dev/null
fi

echo "SUCCESS"
