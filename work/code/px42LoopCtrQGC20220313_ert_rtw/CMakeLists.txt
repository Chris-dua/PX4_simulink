## This cmakelist.txt file was generated from
## the UAVToolbox Support Package for PX4 Autopilots

add_definitions(
-DMODEL=px42LoopCtrQGC20220313 -DNUMST=2 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0 -DON_TARGET_WAIT_FOR_START=0 -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTID01EQ=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DEXT_MODE=1 -DINTEGER_CODE=0 -DMT=1 -DPX4 -DFMUv2 -DNULL=0 -DMW_PX4_NUTTX_BUILD -DEXTMODE_DISABLETESTING -DEXTMODE_DISABLEPRINTF -DEXTMODE_DISABLE_ARGS_PROCESSING=1 -D__linux__ -DXCP_PLATFORM_LINUX_NO_PIE_SUPPORT -DSTACK_SIZE=64 -D__MW_TARGET_USE_HARDWARE_RESOURCES_H__ -DRT -DMW_PX4_EXTMODE_BAUD_RATE=115200 -DMW_PX4_EXTMODE_HWPORT=\"/dev/ttyS6\" -DCLASSICAL_EXT_MODE )

px4_add_module(
    MODULE modules__px4_simulink_app
    MAIN px4_simulink_app
    STACK_MAIN 2000
SRCS
   MW_PX4_PWM.cpp
   MW_uORB_Read.cpp
   MW_SCI.cpp
   ert_main.cpp
   px42LoopCtrQGC20220313.cpp
   px42LoopCtrQGC20220313_data.cpp
   rtGetInf.cpp
   rtGetNaN.cpp
   rt_nonfinite.cpp
   updown.c
   ext_work.c
   rtiostream_utils.c
   MW_PX4_TaskControl.cpp
   nuttxinitialize.cpp
   MW_PX4_rtiostream_serial.cpp
   rtiostream_interface.c
   ext_svr_daemon.c
   daemon_checksum.c
   MW_PX4_PWM.h
   MW_uORB_Read.h
   MW_SCI.h
   MW_PX4_SCI.h
   rtGetInf.h
   rtGetNaN.h
   rt_defines.h
   rt_nonfinite.h
   MW_custom_RTOS_header.h
   multiword_types.h
   px42LoopCtrQGC20220313.h
   px42LoopCtrQGC20220313_dt.h
   px42LoopCtrQGC20220313_private.h
   px42LoopCtrQGC20220313_types.h
   rtmodel.h
   rtwtypes.h
   zero_crossing_types.h
   rtiostream_utils.h
   MW_uORB_busstruct_conversion.h
   daemon_checksum.h
   daemon_checksum_prereq.h
   MW_SVD.h
   MW_PX4_TaskControl.h
   MW_uORB_Init.h
   nuttxinitialize.h
   dt_info.h
   ext_share.h
   ext_svr.h
   ext_svr_transport.h
   ext_test.h
   ext_types.h
   ext_work.h
   updown.h
   updown_util.h
   upsup_public.h
   rtw_extmode.h
   sysran_types.h
   rtiostream.h
   MW_target_hardware_resources.h
    COMPILE_FLAGS
       -fpermissive
       -Wno-narrowing
    INCLUDES
       ${PX4_SOURCE_DIR}/src/modules/px4_simulink_app
       ${PX4_SOURCE_DIR}/src/modules/mavlink
       ${PX4_SOURCE_DIR}/mavlink/include/mavlink
)

get_target_property(PX4_SL_APP_COMPILE_FLAGS modules__px4_simulink_app COMPILE_OPTIONS)
list(REMOVE_ITEM PX4_SL_APP_COMPILE_FLAGS -Werror)
set_target_properties(modules__px4_simulink_app PROPERTIES COMPILE_OPTIONS "${PX4_SL_APP_COMPILE_FLAGS}")

