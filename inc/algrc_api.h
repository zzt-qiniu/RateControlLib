#ifndef ALGRC_API_H
#define ALGRC_API_H


typedef struct
{
	int i_madi;
	int i_madp;
	int i_satd;
	int reserve[16];
} INPUT_CBR_T;

typedef struct
{
	int reserve[16];
} INPUT_VBR_T;

typedef struct
{
	int reencode;
	int reserve[16];
} INPUT_JPEG_T;

typedef struct
{
	int reserve[16];
} INPUT_MJPEG_T;



typedef struct
{
	int i_bitrate;	//target bitrate kbps

	int ipratio;
	int delaytime;	//ms
	int speed;

	int mblevel;	// 0 close(default), 1 open
	int mbsize;		// 0 - 2: 16x16(default) 32x32 64x64

	int reserve[16];
} CONFIG_CBR_T;

typedef struct
{
	int i_maxrate;//max bitrate kbps 
	int i_bitrate;//target bitrate kbps default 0

	int ipratio;
	int delaytime;//ms
	int speed;
	int ipmode;

	int mblevel;	// 0 close(default), 1 open
	int mbsize;		// 0 - 2: 16x16(default) 32x32 64x64

	int reserve[16];
} CONFIG_VBR_T;

typedef struct
{
	int i_speed;
	int target_size;//KB 
	int reserve[16];
} CONFIG_JPEG_T;

typedef struct
{
	int reserve[16];
} CONFIG_MJPEG_T;



typedef struct
{
	int fps;
	int rc_method;//012:cbr vbr jpeg
	int	pic_width;
	int	pic_height;
	int GOP;
	union CONFIG_METHOD {
		CONFIG_CBR_T	config_cbr;
		CONFIG_VBR_T	config_vbr;
		CONFIG_JPEG_T	config_jpeg;
		CONFIG_MJPEG_T	config_mjpeg;
	}method;
	int reserve[16];
} ALGRC_CONFIG_T;


typedef struct
{
	int frame_num;
	int last_frame_qp;
	int last_frame_bits;
	int cur_frame_complexity;
	int frame_type; // 012 pbi
	unsigned char *yuv_plane[3];
	union INPUT_METHOD{
		INPUT_CBR_T		input_cbr;
		INPUT_VBR_T		input_vbr;
		INPUT_JPEG_T	input_jpeg;
		INPUT_MJPEG_T	input_mjpeg;
	}method;
	int reserve[16];
} ALGRC_INPUT_T;


typedef struct
{
	int		frame_qp;
	int		*qpmap;
	int		reserve[16];
} ALGRC_OUTPUT_T;


void* algrc_open(ALGRC_CONFIG_T config_rc);




int algrc_process(void *rc_handle, ALGRC_INPUT_T input_rc, ALGRC_OUTPUT_T *output_rc);




void algrc_close(void* rc_handle);





#endif