"""Loads the cmsis_core library, used by TF Lite."""

load("//third_party:repo.bzl", "tf_http_archive")

def repo():
    tf_http_archive(
        name = "cmsiscore",
        strip_prefix = "CMSIS_6-5782d6f8057906d360f4b95ec08a2354afe5c9b9",
        sha256 = "7d1de644243e370e8d1d798a0dfa8c8d67ab1121082816fbfe75bdb2183aac54",
        urls = [
            "http://github.com/ARM-software/CMSIS_6/archive/5782d6f8057906d360f4b95ec08a2354afe5c9b9.zip",
        ],
        build_file = "//third_party/cmsiscore:BUILD.bazel",
    )
