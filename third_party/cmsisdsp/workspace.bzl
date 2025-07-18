"""Loads the cmsis_dsp library, used by TF Lite."""

load("//third_party:repo.bzl", "tf_http_archive")

def repo():
    tf_http_archive(
        name = "cmsisdsp",
        strip_prefix = "CMSIS-DSP-03c78a997d9ee65a30ad7d869e842412c003aff7",
        sha256 = "fb9cfbe6d5096481b034feefe25b5fa645df3a58653c0b31c2cb01485b417514",
        urls = [
            "http://github.com/ARM-software/CMSIS-DSP/archive/03c78a997d9ee65a30ad7d869e842412c003aff7.zip",
        ],
        build_file = "//third_party/cmsisdsp:BUILD.bazel",
    )
