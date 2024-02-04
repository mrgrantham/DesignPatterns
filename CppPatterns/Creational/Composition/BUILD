cc_library(
    name = "CompositionLib",
    hdrs = glob(["include/**/*.h"]),
    strip_include_prefix = "include/",
    srcs = glob(["src/**"], exclude=["src/main.cpp"]),
    visibility = ["//visibility:public"],
    deps = [],
)

cc_binary(
    name = "Composition",
    srcs = ["src/main.cpp"],
    visibility = ["//visibility:public"],
    deps = [":CompositionLib",],
)