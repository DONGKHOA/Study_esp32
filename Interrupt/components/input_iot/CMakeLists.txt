set(components "src/input.c")

idf_component_register(SRCS "${components}"
                    INCLUDE_DIRS "inc"
                    REQUIRES "driver"
                    )