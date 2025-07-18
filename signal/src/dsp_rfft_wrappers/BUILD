package(
    default_visibility = ["//signal/src:__subpackages__"],
    licenses = ["notice"],
)

cc_library(
    name = "dsp_rfft_wrappers",
    srcs = [
        "dsp_rfft_int16.cc",
    ],
    hdrs = [
        "dsp_rfft_int16.h",
    ],
    deps = [
        "@cmsisdsp//:cmsis_dsp",
    ],
    copts = [
	    "-D__GNUC_PYTHON__",
    ],
)
