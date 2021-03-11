/*
 *
 * Copyright (c) 2012-2015 Qualcomm Technologies, Inc. All Rights Reserved.
 * Qualcomm Technologies Proprietary and Confidential.
 */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>
#include <pthread.h>
//#include "qcarcam.h"


#define INPUT_STREAM  4
#define WIDTH         1280
#define HEIGHT        720

unsigned int start = 0;
static void * temp_data = NULL;
/*
qcarcam_inputs_t inputs_info[4];

void UYVYtoNV12(unsigned char *inyuv,unsigned char *outyuv,int width,int height){
    int i,j,ysize;
    unsigned char* up = NULL,*yp1 = NULL,*yp2 = NULL,*in1 = NULL,*in2 = NULL;

    ysize = width*height;
    up = outyuv + ysize;

    yp1 = outyuv;
    yp2 = outyuv + width;

    in1 = inyuv;
    in2 = inyuv + 2*width;

    for(i = 0; i < height/2 ; i++){
        if(i){
            yp1 += width;
            yp2 += width;
            in1 += 2*width;
            in2 += 2*width;
        }

        for(j = 0; j < width/2; j++){
            *up++ = *in1;
            *yp1++ = *(in1 + 1);
            *yp1++ = *(in1 + 3);

            *yp2++ = *(in2 + 1);
            *yp2++ = *(in2 + 3);
            *up++ = *(in2 + 2);

            in1 += 4;
            in2 += 4;
        }
    }
}

static void write_image(void *data, const int size, int width, int height,int channel,const char *name)
{
    char filename[80];
    static unsigned int count = 0;
    //unsigned int i;
    size_t bytes;
    FILE *fp;
    //printf("camera Write dump write_image\n");
    snprintf(filename, sizeof(filename), "/data/misc/cameraserver/dump_channel_%d_%d_%d_%03u.%s", channel,width,
              height, count, name);
    fp = fopen (filename, "w+");
    if (fp == NULL) {
        printf("open file %s failed %s \n", filename, strerror (errno));
        return ;
    }
    if ((bytes = fwrite (data, size, 1, fp)) < (size_t)size)
        //printf(" Write less raw bytes to %s: %d, %d \n", filename, size, bytes);

    count++;

    fclose (fp);
}

static void qcarcam_event_cb_channel_0_func(int buffer_idx,int channel){
	uint32_t i;
    qcarcam_inputs_t *input = NULL;
    void *frame_buffer_viraddr = NULL;
    int size = 0;
    int width,height;

    input = &inputs_info[channel];
	if(input == NULL){
		return;
	}

    frame_buffer_viraddr = input->input_buffer_info[buffer_idx].viraddr;
    size = input->input_buffer_info[buffer_idx].size;
    width = input->width;
    height = input->height;

    qcarcam_put_frame_buffer(channel,buffer_idx);

	if(frame_buffer_viraddr == NULL){
		return;
	}
    write_image(frame_buffer_viraddr,size,width,height,channel,"uyvy");

	printf("xxxxxxxxxxxxxxxx qcarcam_event_cb_func: channel=0x%x buffer_idx=%d\n",channel,buffer_idx);
}

static void qcarcam_event_cb_channel_1_func(int buffer_idx,int channel){
    uint32_t i;
    qcarcam_inputs_t *input = NULL;
    void *frame_buffer_viraddr = NULL;
    int size = 0;
    int width,height;

    input = &inputs_info[channel];
    if(input == NULL){
        return;
    }

    frame_buffer_viraddr = input->input_buffer_info[buffer_idx].viraddr;
    size = input->input_buffer_info[buffer_idx].size;
    width = input->width;
    height = input->height;

    qcarcam_put_frame_buffer(channel,buffer_idx);

    if(frame_buffer_viraddr == NULL){
        return;
    }
    write_image(frame_buffer_viraddr,size,width,height,channel,"uyvy");
    printf("xxxxxxxxxxxxxxxx qcarcam_event_cb_func: channel=0x%x buffer_idx=%d\n",channel,buffer_idx);
}


static void qcarcam_event_cb_channel_2_func(int buffer_idx,int channel){

    uint32_t i;
    qcarcam_inputs_t *input = NULL;
    void *frame_buffer_viraddr = NULL;
    int size = 0;
    int width,height;

    input = &inputs_info[channel];
    if(input == NULL){
        return;
    }

    frame_buffer_viraddr = input->input_buffer_info[buffer_idx].viraddr;
    size = input->input_buffer_info[buffer_idx].size;
    width = input->width;
    height = input->height;

    qcarcam_put_frame_buffer(channel,buffer_idx);
    if(frame_buffer_viraddr == NULL){
        return;
    }
    write_image(frame_buffer_viraddr,size,width,height,channel,"uyvy");

    printf("xxxxxxxxxxxxxxxx qcarcam_event_cb_func: channel=0x%x buffer_idx=%d\n",channel,buffer_idx);
}

static void qcarcam_event_cb_channel_3_func(int buffer_idx,int channel){
    uint32_t i;
    qcarcam_inputs_t *input = NULL;
    void *frame_buffer_viraddr = NULL;
    int size = 0;
    int width,height;

    input = &inputs_info[channel];
    if(input == NULL){
        return;
    }

    frame_buffer_viraddr = input->input_buffer_info[buffer_idx].viraddr;
    size = input->input_buffer_info[buffer_idx].size;
    width = input->width;
    height = input->height;

    qcarcam_put_frame_buffer(channel,buffer_idx);

    if(frame_buffer_viraddr == NULL){
        return;
    }
    write_image(frame_buffer_viraddr,size,width,height,channel,"uyvy");
    printf("xxxxxxxxxxxxxxxx qcarcam_event_cb_func: channel=0x%x buffer_idx=%d\n",channel,buffer_idx);
}
*/
int main(int argc, char **argv){
/*
int ret;
	int i;
	printf("qcarcam_query_inputs start\n");
	qcarcam_query_inputs(INPUT_STREAM,&inputs_info[0]);

    inputs_info[0].event_cb_fcn = (void*)qcarcam_event_cb_channel_0_func;

    if(INPUT_STREAM > 1)
        inputs_info[1].event_cb_fcn = (void*)qcarcam_event_cb_channel_1_func;

    if(INPUT_STREAM > 2)
        inputs_info[2].event_cb_fcn = (void*)qcarcam_event_cb_channel_2_func;

    if(INPUT_STREAM > 3)
        inputs_info[3].event_cb_fcn = (void*)qcarcam_event_cb_channel_3_func;

	ret = qcarcam_open();
	if(ret < 0){
		printf("qcarcam_open failed\n");
		return 0;
	}
	qcarcam_inputs_info_param_init(INPUT_STREAM,&inputs_info[0]);
	printf("qcarcam_open done\n");

    printf("qcarcam_start begain stream\n");
    qcarcam_start();
    printf("qcarcam_start done\n");
    sleep(60);
    printf("qcarcam_stop begain\n");

	qcarcam_stop();
	qcarcam_close();

	qcarcam_release_inputs(INPUT_STREAM,&inputs_info[0]);
*/
    int fd = -1;    
        fd = open("/dev/video1",O_RDWR);   
        if (fd== -1) {   
            printf("open device error! %d,%s\n",errno,strerror(errno));   
        } else {
            close(fd);
        }

	printf("qcarcam  release done\n");
	return 0;
}
