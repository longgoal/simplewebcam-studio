#
# qcarcam_test
#
LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_LDFLAGS :=

LOCAL_SRC_FILES:= qcarcam_test.c

# LOCAL_C_INCLUDES:= \
#	$(LOCAL_PATH)/../API/inc \
LOCAL_C_INCLUDES:= \
	LOCAL_C_INCLUDES += $(TARGET_OUT_INTERMEDIATES)/KERNEL_OBJ/usr/include/ \


#ifneq ($(TARGET_USES_GRALLOC1), true)
 #   LOCAL_C_INCLUDES  += $(TOP)/hardware/qcom/display/libgralloc
#else
 #   LOCAL_C_INCLUDES  += $(TOP)/hardware/qcom/display/libgralloc1
#endif #TARGET_USES_GRALLOC1

# LOCAL_C_INCLUDES += $(TARGET_OUT_INTERMEDIATES)/KERNEL_OBJ/usr/include/


# LOCAL_SHARED_LIBRARIES:= libcutils libmmqcar_ais_moudle
LOCAL_SHARED_LIBRARIES:= libcutils


LOCAL_MODULE:= qcarcam_test
LOCAL_MODULE_TAGS := optional

LOCAL_32_BIT_ONLY := true

include $(BUILD_EXECUTABLE)
