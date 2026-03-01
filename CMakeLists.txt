zephyr_library()
zephyr_library_sources(src/battery_text.c)

# Ensure the ZMK app include directory is available so headers like
# <zmk/behavior.h> can be found when this module is built as an
# extra module (ZMK_EXTRA_MODULES). ZEPHYR_BASE/.. points to the
# workspace root where the `zmk/app/include` directory resides.
zephyr_include_directories(${ZEPHYR_BASE}/../zmk/app/include)

zephyr_library_link_libraries(zmk)
