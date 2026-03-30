include("${_build_cmake_local}")

message("Adding library: ${PISUBMARINE_MODULE_NAME}")
add_library(${PISUBMARINE_MODULE_NAME}
        PiSubmarine/Drv8908/PowerManager.cpp
        PiSubmarine/Drv8908/IPowerManager.cpp
        PiSubmarine/Drv8908/PowerLease.cpp
)
target_include_directories(${PISUBMARINE_MODULE_NAME} PUBLIC "../public")
PiSubmarineInitTarget(${PISUBMARINE_MODULE_NAME})
PiSubmarineAddDependency("https://github.com/PiSubmarine/Drv8908" "")
target_link_libraries(${PISUBMARINE_MODULE_NAME} PUBLIC PiSubmarine.Drv8908)
