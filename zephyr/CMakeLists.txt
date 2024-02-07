
if (CONFIG_DYNAMIXEL)

zephyr_library()

set(DXL_SDK_BASE ${CMAKE_CURRENT_LIST_DIR}/../)

zephyr_include_directories(
    ${DXL_SDK_BASEl}/c/include/
    ${DXL_SDK_BASEl}/c/include/dynamixel_sdk
)

zpehyr_sources(
    ${DXL_SDK_BASEl}/c/src/dynamixel_sdk/group_bulk_read.c
    ${DXL_SDK_BASEl}/c/src/dynamixel_sdk/group_bulk_write.c
    ${DXL_SDK_BASEl}/c/src/dynamixel_sdk/group_sync_read.c
    ${DXL_SDK_BASEl}/c/src/dynamixel_sdk/group_sync_write.c
    ${DXL_SDK_BASEl}/c/src/dynamixel_sdk/protocol1_packet_handler.c
    ${DXL_SDK_BASEl}/c/src/dynamixel_sdk/protocol2_packet_handler.c
    ${DXL_SDK_BASEl}/c/src/dynamixel_sdk/packet_handler.c
    ${DXL_SDK_BASEl}/c/src/dynamixel_sdk/port_handler_zephyr.c
)

endif()
