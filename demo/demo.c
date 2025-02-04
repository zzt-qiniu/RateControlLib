#include <stdio.h>
#include <stdlib.h>
#include "../inc/algrc_api.h"



int main()
{
	void* rc_handle;
	ALGRC_CONFIG_T	config_rc;
	ALGRC_INPUT_T	input_rc;
	ALGRC_OUTPUT_T	output_rc = {0};

	config_rc.fps = 25;
	config_rc.rc_method = 0;//012 cbr vbr jpeg
	config_rc.method.config_cbr.i_bitrate = 1024;
	config_rc.pic_width = 1920;
	config_rc.pic_height = 1080;
	config_rc.GOP = 50;
	rc_handle = algrc_open(config_rc);


	input_rc.frame_num = 0;
	input_rc.last_frame_qp = 0;
	input_rc.last_frame_bits = 0;
	input_rc.frame_type = 2;
	algrc_process(rc_handle, input_rc, &output_rc);
	
	printf("QP:%d\n ", output_rc.frame_qp);


	algrc_close(rc_handle);

	return 0;
}



