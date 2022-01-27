/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (c) 2021, The Linux Foundation. All rights reserved.
 */


#ifndef _CAM_TFE640_H_
#define _CAM_TFE640_H_
#include "cam_tfe_core.h"
#include "cam_tfe_bus.h"


static struct cam_tfe_top_reg_offset_common  tfe640_top_commong_reg  = {
	.hw_version                             = 0x00001800,
	.hw_capability                          = 0x00001804,
	.lens_feature                           = 0x00001808,
	.stats_feature                          = 0x0000180C,
	.zoom_feature                           = 0x00001810,
	.global_reset_cmd                       = 0x00001814,
	.core_cgc_ctrl                          = 0x00001818,
	.ahb_cgc_ctrl                           = 0x0000181C,
	.core_cfg_0                             = 0x00001824,
	.reg_update_cmd                         = 0x0000182C,
	.diag_config                            = 0x00001860,
	.diag_sensor_status_0                   = 0x00001864,
	.diag_sensor_status_1                   = 0x00001868,
	.diag_sensor_frame_cnt_status           = 0x0000186C,
	.violation_status                       = 0x00001870,
	.stats_throttle_cnt_cfg_0               = 0x00001874,
	.stats_throttle_cnt_cfg_1               = 0x00001878,
	.num_debug_reg                          = 10,
	.debug_reg = {
		0x000018A0,
		0x000018A4,
		0x000018A8,
		0x000018AC,
		0x000018B0,
		0x000018B4,
		0x000018B8,
		0x000018BC,
		0x000018C0,
		0x000018C4,
	},
	.debug_cfg                              = 0x000018DC,
	.num_perf_cfg                           = 2,
	.perf_cfg = {
		{
			.perf_cnt_cfg           = 0x000018E0,
			.perf_pixel_count       = 0x000018E4,
			.perf_line_count        = 0x000018E8,
			.perf_stall_count       = 0x000018EC,
			.perf_always_count      = 0x000018F0,
			.perf_count_status      = 0x000018F4,
		},
		{
			.perf_cnt_cfg           = 0x000018F8,
			.perf_pixel_count       = 0x000018FC,
			.perf_line_count        = 0x00001900,
			.perf_stall_count       = 0x00001904,
			.perf_always_count      = 0x00001908,
			.perf_count_status      = 0x0000190C,
		},
	},
	.diag_min_hbi_error_shift               = 15,
	.diag_neq_hbi_shift                     = 14,
	.diag_sensor_hbi_mask                   = 0x3FFF,
	.serializer_supported                   = true,
};

static struct cam_tfe_camif_reg  tfe640_camif_reg = {
	.hw_version                   = 0x00001C00,
	.hw_status                    = 0x00001C04,
	.module_cfg                   = 0x00001C60,
	.pdaf_raw_crop_width_cfg      = 0x00001C68,
	.pdaf_raw_crop_height_cfg     = 0x00001C6C,
	.line_skip_pattern            = 0x00001C70,
	.pixel_skip_pattern           = 0x00001C74,
	.period_cfg                   = 0x00001C78,
	.irq_subsample_pattern        = 0x00001C7C,
	.epoch_irq_cfg                = 0x00001C80,
	.debug_1                      = 0x00001DF0,
	.debug_0                      = 0x00001DF4,
	.test_bus_ctrl                = 0x00001DF8,
	.spare                        = 0x00001DFC,
	.reg_update_cmd               = 0x0000182C,
};

static struct cam_tfe_camif_reg_data tfe640_camif_reg_data = {
	.extern_reg_update_mask       = 0x00000001,
	.dual_tfe_pix_en_shift        = 0x00000001,
	.extern_reg_update_shift      = 0x0,
	.dual_tfe_sync_sel_shift      = 18,
	.delay_line_en_shift          = 8,
	.pixel_pattern_shift          = 24,
	.pixel_pattern_mask           = 0x7000000,
	.module_enable_shift          = 0,
	.pix_out_enable_shift         = 8,
	.pdaf_output_enable_shift     = 9,
	.dsp_mode_shift               = 0,
	.dsp_mode_mask                = 0,
	.dsp_en_shift                 = 0,
	.dsp_en_mask                  = 0,
	.reg_update_cmd_data          = 0x1,
	.epoch_line_cfg               = 0x00140014,
	.sof_irq_mask                 = 0x00000001,
	.epoch0_irq_mask              = 0x00000004,
	.epoch1_irq_mask              = 0x00000008,
	.eof_irq_mask                 = 0x00000002,
	.reg_update_irq_mask          = 0x00000001,
	.error_irq_mask0              = 0x00010100,
	.error_irq_mask2              = 0x00000023,
	.subscribe_irq_mask           = {
		0x00000000,
		0x00000007,
		0x00000000,
	},
	.enable_diagnostic_hw         = 0x1,
	.perf_cnt_start_cmd_shift     = 0,
	.perf_cnt_continuous_shift    = 2,
	.perf_client_sel_shift        = 8,
	.perf_window_start_shift      = 16,
	.perf_window_end_shift        = 20,
	.ai_c_srl_en_shift            = 11,
	.ds16_c_srl_en_shift          = 10,
	.ds4_c_srl_en_shift           = 9,
};

static struct cam_tfe_rdi_reg  tfe640_rdi0_reg = {
	.rdi_hw_version              = 0x00001E00,
	.rdi_hw_status               = 0x00001E04,
	.rdi_module_config           = 0x00001E60,
	.rdi_skip_period             = 0x00001E68,
	.rdi_irq_subsample_pattern   = 0x00001E6C,
	.rdi_epoch_irq               = 0x00001E70,
	.rdi_debug_1                 = 0x00001FF0,
	.rdi_debug_0                 = 0x00001FF4,
	.rdi_test_bus_ctrl           = 0x00001FF8,
	.rdi_spare                   = 0x00001FFC,
	.reg_update_cmd              = 0x0000182C,
};

static struct cam_tfe_rdi_reg_data tfe640_rdi0_reg_data = {
	.reg_update_cmd_data         = 0x2,
	.epoch_line_cfg              = 0x00140014,
	.pixel_pattern_shift         = 24,
	.pixel_pattern_mask          = 0x07000000,
	.rdi_out_enable_shift        = 0,

	.sof_irq_mask                = 0x00000010,
	.epoch0_irq_mask             = 0x00000040,
	.epoch1_irq_mask             = 0x00000080,
	.eof_irq_mask                = 0x00000020,
	.error_irq_mask0             = 0x00020200,
	.error_irq_mask2             = 0x00000004,
	.subscribe_irq_mask          = {
		0x00000000,
		0x00000030,
		0x00000000,
	},
	.enable_diagnostic_hw        = 0x1,
	.diag_sensor_sel             = 0x1,
	.diag_sensor_shift           = 0x1,
};

static struct cam_tfe_rdi_reg  tfe640_rdi1_reg = {
	.rdi_hw_version              = 0x00002000,
	.rdi_hw_status               = 0x00002004,
	.rdi_module_config           = 0x00002060,
	.rdi_skip_period             = 0x00002068,
	.rdi_irq_subsample_pattern   = 0x0000206C,
	.rdi_epoch_irq               = 0x00002070,
	.rdi_debug_1                 = 0x000021F0,
	.rdi_debug_0                 = 0x000021F4,
	.rdi_test_bus_ctrl           = 0x000021F8,
	.rdi_spare                   = 0x000021FC,
	.reg_update_cmd              = 0x0000182C,
};

static struct cam_tfe_rdi_reg_data tfe640_rdi1_reg_data = {
	.reg_update_cmd_data         = 0x4,
	.epoch_line_cfg              = 0x00140014,
	.pixel_pattern_shift         = 24,
	.pixel_pattern_mask          = 0x07000000,
	.rdi_out_enable_shift        = 0,

	.sof_irq_mask                = 0x00000100,
	.epoch0_irq_mask             = 0x00000400,
	.epoch1_irq_mask             = 0x00000800,
	.eof_irq_mask                = 0x00000200,
	.error_irq_mask0             = 0x00040400,
	.error_irq_mask2             = 0x00000008,
	.subscribe_irq_mask          = {
		0x00000000,
		0x00000300,
		0x00000000,
	},
	.enable_diagnostic_hw        = 0x1,
	.diag_sensor_sel             = 0x2,
	.diag_sensor_shift           = 0x1,
};

static struct cam_tfe_rdi_reg  tfe640_rdi2_reg = {
	.rdi_hw_version              = 0x00002200,
	.rdi_hw_status               = 0x00002204,
	.rdi_module_config           = 0x00002260,
	.rdi_skip_period             = 0x00002268,
	.rdi_irq_subsample_pattern   = 0x0000226C,
	.rdi_epoch_irq               = 0x00002270,
	.rdi_debug_1                 = 0x000023F0,
	.rdi_debug_0                 = 0x000023F4,
	.rdi_test_bus_ctrl           = 0x000023F8,
	.rdi_spare                   = 0x000023FC,
	.reg_update_cmd              = 0x0000182C,
};

static struct cam_tfe_rdi_reg_data tfe640_rdi2_reg_data = {
	.reg_update_cmd_data         = 0x8,
	.epoch_line_cfg              = 0x00140014,
	.pixel_pattern_shift         = 24,
	.pixel_pattern_mask          = 0x07000000,
	.rdi_out_enable_shift        = 0,

	.sof_irq_mask                = 0x00001000,
	.epoch0_irq_mask             = 0x00004000,
	.epoch1_irq_mask             = 0x00008000,
	.eof_irq_mask                = 0x00002000,
	.error_irq_mask0             = 0x00080800,
	.error_irq_mask2             = 0x00000004,
	.subscribe_irq_mask          = {
		0x00000000,
		0x00003000,
		0x00000000,
	},
	.enable_diagnostic_hw        = 0x1,
	.diag_sensor_sel             = 0x3,
	.diag_sensor_shift           = 0x1,

};

static struct cam_tfe_clc_hw_status  tfe640_clc_hw_info[CAM_TFE_MAX_CLC] = {
	{
		.name = "CLC_CAMIF",
		.hw_status_reg = 0x1C04,
	},
	{
		.name = "CLC_RDI0_CAMIF",
		.hw_status_reg = 0x1E04,
	},
	{
		.name = "CLC_RDI1_CAMIF",
		.hw_status_reg = 0x2004,
	},
	{
		.name = "CLC_RDI2_CAMIF",
		.hw_status_reg = 0x2204,
	},
	{
		.name = "CLC_CHANNEL_GAIN",
		.hw_status_reg = 0x6004,
	},
	{
		.name = "CLC_BPC_PDPC",
		.hw_status_reg = 0x6204,
	},
	{
		.name = "CLC_LCS",
		.hw_status_reg = 0x6404,
	},
	{
		.name = "CLC_SHARED_LB",
		.hw_status_reg = 0x6604,
	},
	{
		.name = "CLC_WB_BDS",
		.hw_status_reg = 0x6804,
	},
	{
		.name = "CLC_CROP_RND_CLAMP_POST_BDS",
		.hw_status_reg = 0x6A04,
	},
	{
		.name = "CLC_BLS",
		.hw_status_reg = 0x6C04,
	},
	{
		.name = "CLC_BAYER_GLUT",
		.hw_status_reg = 0x6E04,
	},
	{
		.name = "CLC_BAYER_DS4",
		.hw_status_reg = 0x7004,
	},
	{
		.name = "CLC_COLOR_XFORM_DS4",
		.hw_status_reg = 0x7204,
	},
	{
		.name = "CLC_CHROMA_DS2",
		.hw_status_reg = 0x7404,
	},
	{
		.name = "CLC_CROP_RND_CLAMP_Y_DS4",
		.hw_status_reg = 0x7604,
	},
	{
		.name = "CLC_CROP_RND_CLAMP_C_DS4",
		.hw_status_reg = 0x7804,
	},
	{
		.name = "CLC_R2PD_DS4",
		.hw_status_reg = 0x7A04,
	},
	{
		.name = "CLC_DOWNSCALE_4TO1_Y",
		.hw_status_reg = 0x7C04,
	},
	{
		.name = "CLC_DOWNSCALE_4TO1_C",
		.hw_status_reg = 0x7E04,
	},
	{
		.name = "CLC_CROP_RND_CLAMP_Y_DS16",
		.hw_status_reg = 0x8004,
	},
	{
		.name = "CLC_CROP_RND_CLAMP_C_DS16",
		.hw_status_reg = 0x8204,
	},
	{
		.name = "CLC_R2PD_DS16",
		.hw_status_reg = 0x8404,
	},
	{
		.name = "CLC_WB_GAIN",
		.hw_status_reg = 0x8604,
	},
	{
		.name = "CLC_BAYER_DS2",
		.hw_status_reg = 0x8804,
	},
	{
		.name = "CLC_GTM",
		.hw_status_reg = 0x8A04,
	},
	{
		.name = "CLC_COLOR_XFORM_AI_DS",
		.hw_status_reg = 0x8C04,
	},
	{
		.name = "CLC_DOWNSCALE_MN_Y",
		.hw_status_reg = 0x8E04,
	},
	{
		.name = "CLC_DOWNSCALE_MN_C",
		.hw_status_reg = 0x9004,
	},
	{
		.name = "CLC_CROP_RND_CLAMP_Y_AI_DS",
		.hw_status_reg = 0x9204,
	},
	{
		.name = "CLC_CROP_RND_CLAMP_C_AI_DS",
		.hw_status_reg = 0x9404,
	},
	{
		.name = "CLC_CROP_RND_CLAMP_IDEAL_RAW",
		.hw_status_reg = 0x9604,
	},
	{
		.name = "CLC_ABF",
		.hw_status_reg = 0x9804,
	},
	{
		.name = "CLC_STATS_BG",
		.hw_status_reg = 0x9A04,
	},
	{
		.name = "CLC_STATS_BHIST",
		.hw_status_reg = 0x9C04,
	},
	{
		.name = "CLC_STATS_AWB_BG",
		.hw_status_reg = 0x9E04,
	},
	{
		.name = "CLC_STATS_AEC_BG",
		.hw_status_reg = 0xA004,
	},
	{
		.name = "CLC_STATS_BAF",
		.hw_status_reg = 0xA204,
	},
	{
		.name = "CLC_STATS_RS",
		.hw_status_reg = 0xA404,
	},
};

static struct  cam_tfe_top_hw_info tfe640_top_hw_info = {
	.common_reg = &tfe640_top_commong_reg,
	.camif_hw_info = {
		.camif_reg = &tfe640_camif_reg,
		.reg_data  = &tfe640_camif_reg_data,
	},
	.rdi_hw_info  = {
		{
			.rdi_reg  = &tfe640_rdi0_reg,
			.reg_data = &tfe640_rdi0_reg_data,
		},
		{
			.rdi_reg  = &tfe640_rdi1_reg,
			.reg_data = &tfe640_rdi1_reg_data,
		},
		{
			.rdi_reg  = &tfe640_rdi2_reg,
			.reg_data = &tfe640_rdi2_reg_data,
		},
	},
	.in_port = {
		CAM_TFE_CAMIF_VER_1_0,
		CAM_TFE_RDI_VER_1_0,
		CAM_TFE_RDI_VER_1_0,
		CAM_TFE_RDI_VER_1_0
	},
	.reg_dump_data  = {
		.num_reg_dump_entries    = 19,
		.num_lut_dump_entries    = 0,
		.bus_start_addr          = 0x2000,
		.bus_write_top_end_addr  = 0x2120,
		.bus_client_start_addr   = 0x2200,
		.bus_client_offset       = 0x100,
		.num_bus_clients         = 10,
		.reg_entry = {
			{
				.start_offset = 0x1000,
				.end_offset   = 0x10F4,
			},
			{
				.start_offset = 0x1260,
				.end_offset   = 0x1280,
			},
			{
				.start_offset = 0x13F0,
				.end_offset   = 0x13FC,
			},
			{
				.start_offset = 0x1460,
				.end_offset   = 0x1470,
			},
			{
				.start_offset = 0x15F0,
				.end_offset   = 0x15FC,
			},
			{
				.start_offset = 0x1660,
				.end_offset   = 0x1670,
			},
			{
				.start_offset = 0x17F0,
				.end_offset   = 0x17FC,
			},
			{
				.start_offset = 0x1860,
				.end_offset   = 0x1870,
			},
			{
				.start_offset = 0x19F0,
				.end_offset   = 0x19FC,
			},
			{
				.start_offset = 0x2660,
				.end_offset   = 0x2694,
			},
			{
				.start_offset = 0x2860,
				.end_offset   = 0x2884,
			},
			{
				.start_offset = 0x2A60,
				.end_offset   = 0X2B34,
			},
			{
				.start_offset = 0x2C60,
				.end_offset   = 0X2C80,
			},
			{
				.start_offset = 0x2E60,
				.end_offset   = 0X2E7C,
			},
			{
				.start_offset = 0x3060,
				.end_offset   = 0X3110,
			},
			{
				.start_offset = 0x3260,
				.end_offset   = 0X3278,
			},
			{
				.start_offset = 0x3460,
				.end_offset   = 0X3478,
			},
			{
				.start_offset = 0x3660,
				.end_offset   = 0X3684,
			},
			{
				.start_offset = 0x3860,
				.end_offset   = 0X3884,
			},
		},
		.lut_entry = {
			{
				.lut_word_size = 1,
				.lut_bank_sel  = 0x40,
				.lut_addr_size = 180,
				.dmi_reg_offset = 0x2800,
			},
			{
				.lut_word_size = 1,
				.lut_bank_sel  = 0x41,
				.lut_addr_size = 180,
				.dmi_reg_offset = 0x3000,
			},
		},
	},
};

static struct cam_tfe_bus_hw_info  tfe640_bus_hw_info = {
	.common_reg = {
		.hw_version  = 0x00003000,
		.cgc_ovd     = 0x00003008,
		.comp_cfg_0  = 0x0000300C,
		.comp_cfg_1  = 0x00003010,
		.frameheader_cfg  = {
			0x00003034,
			0x00003038,
			0x0000303C,
			0x00003040,
		},
		.pwr_iso_cfg = 0x0000305C,
		.overflow_status_clear = 0x00003060,
		.ccif_violation_status = 0x00003064,
		.overflow_status       = 0x00003068,
		.image_size_violation_status = 0x00003070,
		.perf_count_cfg = {
			0x00003074,
			0x00003078,
			0x0000307C,
			0x00003080,
			0x00003084,
			0x00003088,
			0x0000308C,
			0x00003090,
		},
		.perf_count_val = {
			0x00003094,
			0x00003098,
			0x0000309C,
			0x000030A0,
			0x000030A4,
			0x000030A8,
			0x000030AC,
			0x000030B0,
		},
		.perf_count_status = 0x000030B4,
		.debug_status_top_cfg = 0x000030D4,
		.debug_status_top = 0x000030D8,
		.test_bus_ctrl = 0x000030DC,
		.irq_mask = {
			0x00003018,
			0x0000301C,
		},
		.irq_clear = {
			0x00003020,
			0x00003024,
		},
		.irq_status = {
			0x00003028,
			0x0000302C,
		},
		.irq_cmd = 0x00003030,
		.cons_violation_shift = 28,
		.violation_shift  = 30,
		.image_size_violation = 31,
	},
	.num_client = 16,
	.bus_client_reg = {
		/* BUS Client 0 BAYER */
		{
			.cfg                   = 0x00003200,
			.image_addr            = 0x00003204,
			.frame_incr            = 0x00003208,
			.image_cfg_0           = 0x0000320C,
			.image_cfg_1           = 0x00003210,
			.image_cfg_2           = 0x00003214,
			.packer_cfg            = 0x00003218,
			.bw_limit              = 0x0000321C,
			.frame_header_addr     = 0x00003220,
			.frame_header_incr     = 0x00003224,
			.frame_header_cfg      = 0x00003228,
			.line_done_cfg         = 0x00000000,
			.irq_subsample_period  = 0x00003230,
			.irq_subsample_pattern = 0x00003234,
			.framedrop_period      = 0x00003238,
			.framedrop_pattern     = 0x0000323C,
			.addr_status_0         = 0x00003268,
			.addr_status_1         = 0x0000326C,
			.addr_status_2         = 0x00003270,
			.addr_status_3         = 0x00003274,
			.debug_status_cfg      = 0x00003278,
			.debug_status_0        = 0x0000327C,
			.debug_status_1        = 0x00003280,
			.comp_group            = CAM_TFE_BUS_COMP_GRP_0,
			.client_name           = "BAYER",
		},
		/* BUS Client 1 IDEAL RAW*/
		{
			.cfg                   = 0x00003300,
			.image_addr            = 0x00003304,
			.frame_incr            = 0x00003308,
			.image_cfg_0           = 0x0000330C,
			.image_cfg_1           = 0x00003310,
			.image_cfg_2           = 0x00003314,
			.packer_cfg            = 0x00003318,
			.bw_limit              = 0x0000331C,
			.frame_header_addr     = 0x00003320,
			.frame_header_incr     = 0x00003324,
			.frame_header_cfg      = 0x00003328,
			.line_done_cfg         = 0x00000000,
			.irq_subsample_period  = 0x00003330,
			.irq_subsample_pattern = 0x00003334,
			.framedrop_period      = 0x00003338,
			.framedrop_pattern     = 0x0000333C,
			.addr_status_0         = 0x00003368,
			.addr_status_1         = 0x0000336C,
			.addr_status_2         = 0x00003370,
			.addr_status_3         = 0x00003374,
			.debug_status_cfg      = 0x00003378,
			.debug_status_0        = 0x0000337C,
			.debug_status_1        = 0x00003380,
			.comp_group            = CAM_TFE_BUS_COMP_GRP_1,
			.client_name           = "IDEAL_RAW",
		},
		/* BUS Client 2 Stats BE Tintless */
		{
			.cfg                   = 0x00003400,
			.image_addr            = 0x00003404,
			.frame_incr            = 0x00003408,
			.image_cfg_0           = 0x0000340C,
			.image_cfg_1           = 0x00003410,
			.image_cfg_2           = 0x00003414,
			.packer_cfg            = 0x00003418,
			.bw_limit              = 0x0000341C,
			.frame_header_addr     = 0x00003420,
			.frame_header_incr     = 0x00003424,
			.frame_header_cfg      = 0x00003428,
			.line_done_cfg         = 0x00003400,
			.irq_subsample_period  = 0x00003430,
			.irq_subsample_pattern = 0x00003434,
			.framedrop_period      = 0x00003438,
			.framedrop_pattern     = 0x0000343C,
			.addr_status_0         = 0x00003468,
			.addr_status_1         = 0x0000346C,
			.addr_status_2         = 0x00003470,
			.addr_status_3         = 0x00003474,
			.debug_status_cfg      = 0x00003478,
			.debug_status_0        = 0x0000347C,
			.debug_status_1        = 0x00003480,
			.comp_group            = CAM_TFE_BUS_COMP_GRP_2,
			.client_name           = "STATS BE TINTLESS",
		},
		/* BUS Client 3 Stats Bhist */
		{
			.cfg                   = 0x00003500,
			.image_addr            = 0x00003504,
			.frame_incr            = 0x00003508,
			.image_cfg_0           = 0x0000350C,
			.image_cfg_1           = 0x00003510,
			.image_cfg_2           = 0x00003514,
			.packer_cfg            = 0x00003518,
			.bw_limit              = 0x0000351C,
			.frame_header_addr     = 0x00003520,
			.frame_header_incr     = 0x00003524,
			.frame_header_cfg      = 0x00003528,
			.line_done_cfg         = 0x00000000,
			.irq_subsample_period  = 0x00003530,
			.irq_subsample_pattern = 0x00003534,
			.framedrop_period      = 0x00003538,
			.framedrop_pattern     = 0x0000353C,
			.addr_status_0         = 0x00003568,
			.addr_status_1         = 0x0000356C,
			.addr_status_2         = 0x00003570,
			.addr_status_3         = 0x00003574,
			.debug_status_cfg      = 0x00003578,
			.debug_status_0        = 0x0000357C,
			.debug_status_1        = 0x00003580,
			.comp_group            = CAM_TFE_BUS_COMP_GRP_2,
			.client_name           = "STATS BHIST",
		},
		/* BUS Client 4 Stats AWB BG */
		{
			.cfg                   = 0x00003600,
			.image_addr            = 0x00003604,
			.frame_incr            = 0x00003608,
			.image_cfg_0           = 0x0000360C,
			.image_cfg_1           = 0x00003610,
			.image_cfg_2           = 0x00003614,
			.packer_cfg            = 0x00003618,
			.bw_limit              = 0x0000361C,
			.frame_header_addr     = 0x00003620,
			.frame_header_incr     = 0x00003624,
			.frame_header_cfg      = 0x00003628,
			.line_done_cfg         = 0x00000000,
			.irq_subsample_period  = 0x00003630,
			.irq_subsample_pattern = 0x00003634,
			.framedrop_period      = 0x00003638,
			.framedrop_pattern     = 0x0000363C,
			.addr_status_0         = 0x00003668,
			.addr_status_1         = 0x0000366C,
			.addr_status_2         = 0x00003670,
			.addr_status_3         = 0x00003674,
			.debug_status_cfg      = 0x00003678,
			.debug_status_0        = 0x0000367C,
			.debug_status_1        = 0x00003680,
			.comp_group            = CAM_TFE_BUS_COMP_GRP_3,
			.client_name           = "STATS AWB BG",
		},
		/* BUS Client 5 Stats AEC BG */
		{
			.cfg                   = 0x00003700,
			.image_addr            = 0x00003704,
			.frame_incr            = 0x00003708,
			.image_cfg_0           = 0x0000370C,
			.image_cfg_1           = 0x00003710,
			.image_cfg_2           = 0x00003714,
			.packer_cfg            = 0x00003718,
			.bw_limit              = 0x0000371C,
			.frame_header_addr     = 0x00003720,
			.frame_header_incr     = 0x00003724,
			.frame_header_cfg      = 0x00003728,
			.line_done_cfg         = 0x00000000,
			.irq_subsample_period  = 0x00003730,
			.irq_subsample_pattern = 0x00003734,
			.framedrop_period      = 0x00003738,
			.framedrop_pattern     = 0x0000373C,
			.addr_status_0         = 0x00003768,
			.addr_status_1         = 0x0000376C,
			.addr_status_2         = 0x00003770,
			.addr_status_3         = 0x00003774,
			.debug_status_cfg      = 0x00003778,
			.debug_status_0        = 0x0000377C,
			.debug_status_1        = 0x00003780,
			.comp_group            = CAM_TFE_BUS_COMP_GRP_3,
			.client_name           = "STATS AEC BG",
		},
		/* BUS Client 6 Stats BAF */
		{
			.cfg                   = 0x00003800,
			.image_addr            = 0x00003804,
			.frame_incr            = 0x00003808,
			.image_cfg_0           = 0x0000380C,
			.image_cfg_1           = 0x00003810,
			.image_cfg_2           = 0x00003814,
			.packer_cfg            = 0x00003818,
			.bw_limit              = 0x0000381C,
			.frame_header_addr     = 0x00003820,
			.frame_header_incr     = 0x00003824,
			.frame_header_cfg      = 0x00003828,
			.line_done_cfg         = 0x00000000,
			.irq_subsample_period  = 0x00003830,
			.irq_subsample_pattern = 0x00003834,
			.framedrop_period      = 0x00003838,
			.framedrop_pattern     = 0x0000383C,
			.addr_status_0         = 0x00003868,
			.addr_status_1         = 0x0000386C,
			.addr_status_2         = 0x00003870,
			.addr_status_3         = 0x00003874,
			.debug_status_cfg      = 0x00003878,
			.debug_status_0        = 0x0000387C,
			.debug_status_1        = 0x00003880,
			.comp_group            = CAM_TFE_BUS_COMP_GRP_4,
			.client_name           = "STATS BAF",
		},
		/* BUS Client 7 RDI0 */
		{
			.cfg                   = 0x00003900,
			.image_addr            = 0x00003904,
			.frame_incr            = 0x00003908,
			.image_cfg_0           = 0x0000390C,
			.image_cfg_1           = 0x00003910,
			.image_cfg_2           = 0x00003914,
			.packer_cfg            = 0x00003918,
			.bw_limit              = 0x0000391C,
			.frame_header_addr     = 0x00003920,
			.frame_header_incr     = 0x00003924,
			.frame_header_cfg      = 0x00003928,
			.line_done_cfg         = 0x00000000,
			.irq_subsample_period  = 0x00003930,
			.irq_subsample_pattern = 0x00003934,
			.framedrop_period      = 0x00003938,
			.framedrop_pattern     = 0x0000393C,
			.addr_status_0         = 0x00003968,
			.addr_status_1         = 0x0000396C,
			.addr_status_2         = 0x00003970,
			.addr_status_3         = 0x00003974,
			.debug_status_cfg      = 0x00003978,
			.debug_status_0        = 0x0000397C,
			.debug_status_1        = 0x00003980,
			.comp_group            = CAM_TFE_BUS_COMP_GRP_5,
			.client_name           = "RDI0",
		},
		/* BUS Client 8 RDI1 */
		{
			.cfg                   = 0x00003A00,
			.image_addr            = 0x00003A04,
			.frame_incr            = 0x00003A08,
			.image_cfg_0           = 0x00003A0C,
			.image_cfg_1           = 0x00003A10,
			.image_cfg_2           = 0x00003A14,
			.packer_cfg            = 0x00003A18,
			.bw_limit              = 0x00003A1C,
			.frame_header_addr     = 0x00003A20,
			.frame_header_incr     = 0x00003A24,
			.frame_header_cfg      = 0x00003A28,
			.line_done_cfg         = 0x00000000,
			.irq_subsample_period  = 0x00003A30,
			.irq_subsample_pattern = 0x00003A34,
			.framedrop_period      = 0x00003A38,
			.framedrop_pattern     = 0x00003A3C,
			.addr_status_0         = 0x00003A68,
			.addr_status_1         = 0x00003A6C,
			.addr_status_2         = 0x00003A70,
			.addr_status_3         = 0x00003A74,
			.debug_status_cfg      = 0x00003A78,
			.debug_status_0        = 0x00003A7C,
			.debug_status_1        = 0x00003A80,
			.comp_group            = CAM_TFE_BUS_COMP_GRP_6,
			.client_name           = "RDI1",
		},
		/* BUS Client 9 RDI2 */
		{
			.cfg                   = 0x00003B00,
			.image_addr            = 0x00003B04,
			.frame_incr            = 0x00003B08,
			.image_cfg_0           = 0x00003B0C,
			.image_cfg_1           = 0x00003B10,
			.image_cfg_2           = 0x00003B14,
			.packer_cfg            = 0x00003B18,
			.bw_limit              = 0x00003B1C,
			.frame_header_addr     = 0x00003B20,
			.frame_header_incr     = 0x00003B24,
			.frame_header_cfg      = 0x00003B28,
			.line_done_cfg         = 0x00000000,
			.irq_subsample_period  = 0x00003B30,
			.irq_subsample_pattern = 0x00003B34,
			.framedrop_period      = 0x00003B38,
			.framedrop_pattern     = 0x00003B3C,
			.addr_status_0         = 0x00003B68,
			.addr_status_1         = 0x00003B6C,
			.addr_status_2         = 0x00003B70,
			.addr_status_3         = 0x00003B74,
			.debug_status_cfg      = 0x00003B78,
			.debug_status_0        = 0x00003B7C,
			.debug_status_1        = 0x00003B80,
			.comp_group            = CAM_TFE_BUS_COMP_GRP_7,
			.client_name           = "RDI2",
		},
		/* BUS Client 10 PDAF */
		{
			.cfg                   = 0x00003C00,
			.image_addr            = 0x00003C04,
			.frame_incr            = 0x00003C08,
			.image_cfg_0           = 0x00003C0C,
			.image_cfg_1           = 0x00003C10,
			.image_cfg_2           = 0x00003C14,
			.packer_cfg            = 0x00003C18,
			.bw_limit              = 0x00003C1C,
			.frame_header_addr     = 0x00003C20,
			.frame_header_incr     = 0x00003C24,
			.frame_header_cfg      = 0x00003C28,
			.line_done_cfg         = 0x00000000,
			.irq_subsample_period  = 0x00003C30,
			.irq_subsample_pattern = 0x00003C34,
			.framedrop_period      = 0x00003C38,
			.framedrop_pattern     = 0x00003C3C,
			.addr_status_0         = 0x00003C68,
			.addr_status_1         = 0x00003C6C,
			.addr_status_2         = 0x00003C70,
			.addr_status_3         = 0x00003C74,
			.debug_status_cfg      = 0x00003C78,
			.debug_status_0        = 0x00003C7C,
			.debug_status_1        = 0x00003C80,
			.comp_group            = CAM_TFE_BUS_COMP_GRP_8,
			.client_name           = "PDAF",
		},
		/* BUS Client 11 DS4 */
		{
			.cfg                   = 0x00003D00,
			.image_addr            = 0x00003D04,
			.frame_incr            = 0x00003D08,
			.image_cfg_0           = 0x00003D0C,
			.image_cfg_1           = 0x00003D10,
			.image_cfg_2           = 0x00003D14,
			.packer_cfg            = 0x00003D18,
			.bw_limit              = 0x00003D1C,
			.frame_header_addr     = 0x00003D20,
			.frame_header_incr     = 0x00003D24,
			.frame_header_cfg      = 0x00003D28,
			.line_done_cfg         = 0x00000000,
			.irq_subsample_period  = 0x00003D30,
			.irq_subsample_pattern = 0x00003D34,
			.framedrop_period      = 0x00003D38,
			.framedrop_pattern     = 0x00003D3C,
			.addr_status_0         = 0x00003D68,
			.addr_status_1         = 0x00003D6C,
			.addr_status_2         = 0x00003D70,
			.addr_status_3         = 0x00003D74,
			.debug_status_cfg      = 0x00003D78,
			.debug_status_0        = 0x00003D7C,
			.debug_status_1        = 0x00003D80,
			.comp_group            = CAM_TFE_BUS_COMP_GRP_0,
			.client_name           = "DS4",
		},
		/* BUS Client 12 DS16 */
		{
			.cfg                   = 0x00003E00,
			.image_addr            = 0x00003E04,
			.frame_incr            = 0x00003E08,
			.image_cfg_0           = 0x00003E0C,
			.image_cfg_1           = 0x00003E10,
			.image_cfg_2           = 0x00003E14,
			.packer_cfg            = 0x00003E18,
			.bw_limit              = 0x00003E1C,
			.frame_header_addr     = 0x00003E20,
			.frame_header_incr     = 0x00003E24,
			.frame_header_cfg      = 0x00003E28,
			.line_done_cfg         = 0x00000000,
			.irq_subsample_period  = 0x00003E30,
			.irq_subsample_pattern = 0x00003E34,
			.framedrop_period      = 0x00003E38,
			.framedrop_pattern     = 0x00003E3C,
			.addr_status_0         = 0x00003E68,
			.addr_status_1         = 0x00003E6C,
			.addr_status_2         = 0x00003E70,
			.addr_status_3         = 0x00003E74,
			.debug_status_cfg      = 0x00003E78,
			.debug_status_0        = 0x00003E7C,
			.debug_status_1        = 0x00003E80,
			.comp_group            = CAM_TFE_BUS_COMP_GRP_0,
			.client_name           = "DS16",
		},
		/* BUS Client 13 AI-Y */
		{
			.cfg                   = 0x00003F00,
			.image_addr            = 0x00003F04,
			.frame_incr            = 0x00003F08,
			.image_cfg_0           = 0x00003F0C,
			.image_cfg_1           = 0x00003F10,
			.image_cfg_2           = 0x00003F14,
			.packer_cfg            = 0x00003F18,
			.bw_limit              = 0x00003F1C,
			.frame_header_addr     = 0x00003F20,
			.frame_header_incr     = 0x00003F24,
			.frame_header_cfg      = 0x00003F28,
			.line_done_cfg         = 0x00000000,
			.irq_subsample_period  = 0x00003F30,
			.irq_subsample_pattern = 0x00003F34,
			.framedrop_period      = 0x00003F38,
			.framedrop_pattern     = 0x00003F3C,
			.addr_status_0         = 0x00003F68,
			.addr_status_1         = 0x00003F6C,
			.addr_status_2         = 0x00003F70,
			.addr_status_3         = 0x00003F74,
			.debug_status_cfg      = 0x00003F78,
			.debug_status_0        = 0x00003F7C,
			.debug_status_1        = 0x00003F80,
			.comp_group            = CAM_TFE_BUS_COMP_GRP_9,
			.client_name           = "AI-Y",
		},
		/* BUS Client 14 AI-C */
		{
			.cfg                   = 0x00004000,
			.image_addr            = 0x00004004,
			.frame_incr            = 0x00004008,
			.image_cfg_0           = 0x0000400C,
			.image_cfg_1           = 0x00004010,
			.image_cfg_2           = 0x00004014,
			.packer_cfg            = 0x00004018,
			.bw_limit              = 0x0000401C,
			.frame_header_addr     = 0x00004020,
			.frame_header_incr     = 0x00004024,
			.frame_header_cfg      = 0x00004028,
			.line_done_cfg         = 0x00000000,
			.irq_subsample_period  = 0x00004030,
			.irq_subsample_pattern = 0x00004034,
			.framedrop_period      = 0x00004038,
			.framedrop_pattern     = 0x0000403C,
			.addr_status_0         = 0x00004068,
			.addr_status_1         = 0x0000406C,
			.addr_status_2         = 0x00004070,
			.addr_status_3         = 0x00004074,
			.debug_status_cfg      = 0x00004078,
			.debug_status_0        = 0x0000407C,
			.debug_status_1        = 0x00004080,
			.comp_group            = CAM_TFE_BUS_COMP_GRP_9,
			.client_name           = "AI-C",
		},
		/* BUS Client 15 Stats RS */
		{
			.cfg                   = 0x00004100,
			.image_addr            = 0x00004104,
			.frame_incr            = 0x00004108,
			.image_cfg_0           = 0x0000410C,
			.image_cfg_1           = 0x00004110,
			.image_cfg_2           = 0x00004114,
			.packer_cfg            = 0x00004118,
			.bw_limit              = 0x0000411C,
			.frame_header_addr     = 0x00004120,
			.frame_header_incr     = 0x00004124,
			.frame_header_cfg      = 0x00004128,
			.line_done_cfg         = 0x00000000,
			.irq_subsample_period  = 0x00004130,
			.irq_subsample_pattern = 0x00004134,
			.framedrop_period      = 0x00004138,
			.framedrop_pattern     = 0x0000413C,
			.addr_status_0         = 0x00004168,
			.addr_status_1         = 0x0000416C,
			.addr_status_2         = 0x00004170,
			.addr_status_3         = 0x00004174,
			.debug_status_cfg      = 0x00004178,
			.debug_status_0        = 0x0000417C,
			.debug_status_1        = 0x00004180,
			.comp_group            = CAM_TFE_BUS_COMP_GRP_10,
			.client_name           = "STATS RS",
		},
	},
	.num_out  = 15,
	.tfe_out_hw_info = {
		{
			.tfe_out_id       = CAM_TFE_BUS_TFE_OUT_RDI0,
			.max_width        = -1,
			.max_height       = -1,
			.composite_group  = CAM_TFE_BUS_COMP_GRP_5,
			.rup_group_id     = CAM_TFE_BUS_RUP_GRP_1,
			.mid              = 4,
		},
		{
			.tfe_out_id       = CAM_TFE_BUS_TFE_OUT_RDI1,
			.max_width        = -1,
			.max_height       = -1,
			.composite_group  = CAM_TFE_BUS_COMP_GRP_6,
			.rup_group_id     = CAM_TFE_BUS_RUP_GRP_2,
			.mid              = 5,
		},
		{
			.tfe_out_id       = CAM_TFE_BUS_TFE_OUT_RDI2,
			.max_width        = -1,
			.max_height       = -1,
			.composite_group  = CAM_TFE_BUS_COMP_GRP_7,
			.rup_group_id     = CAM_TFE_BUS_RUP_GRP_3,
			.mid              = 6,
		},
		{
			.tfe_out_id       = CAM_TFE_BUS_TFE_OUT_FULL,
			.max_width        = 4096,
			.max_height       = 4096,
			.composite_group  = CAM_TFE_BUS_COMP_GRP_0,
			.rup_group_id     = CAM_TFE_BUS_RUP_GRP_0,
			.mid              = 16,
		},
		{
			.tfe_out_id       = CAM_TFE_BUS_TFE_OUT_RAW_DUMP,
			.max_width        = 4096,
			.max_height       = 4096,
			.composite_group  = CAM_TFE_BUS_COMP_GRP_1,
			.rup_group_id     = CAM_TFE_BUS_RUP_GRP_0,
			.mid              = 7,
		},
		{
			.tfe_out_id       = CAM_TFE_BUS_TFE_OUT_PDAF,
			.max_width        = 4096,
			.max_height       = 4096,
			.composite_group  = CAM_TFE_BUS_COMP_GRP_8,
			.rup_group_id     = CAM_TFE_BUS_RUP_GRP_0,
			.mid              = 26,
		},
		{
			.tfe_out_id       = CAM_TFE_BUS_TFE_OUT_STATS_HDR_BE,
			.max_width        = -1,
			.max_height       = -1,
			.composite_group  = CAM_TFE_BUS_COMP_GRP_3,
			.rup_group_id     = CAM_TFE_BUS_RUP_GRP_0,
			.mid              = 21,
		},
		{
			.tfe_out_id       = CAM_TFE_BUS_TFE_OUT_STATS_HDR_BHIST,
			.max_width        = -1,
			.max_height       = -1,
			.composite_group  = CAM_TFE_BUS_COMP_GRP_2,
			.rup_group_id     = CAM_TFE_BUS_RUP_GRP_0,
			.mid              = 18,
		},
		{
			.tfe_out_id       = CAM_TFE_BUS_TFE_OUT_STATS_TL_BG,
			.max_width        = -1,
			.max_height       = -1,
			.composite_group  = CAM_TFE_BUS_COMP_GRP_2,
			.rup_group_id     = CAM_TFE_BUS_RUP_GRP_0,
			.mid              = 17,
		},
		{
			.tfe_out_id       = CAM_TFE_BUS_TFE_OUT_STATS_AWB_BG,
			.max_width        = -1,
			.max_height       = -1,
			.composite_group  = CAM_TFE_BUS_COMP_GRP_3,
			.rup_group_id     = CAM_TFE_BUS_RUP_GRP_0,
			.mid              = 19,
		},
		{
			.tfe_out_id       = CAM_TFE_BUS_TFE_OUT_STATS_BF,
			.max_width        = -1,
			.max_height       = -1,
			.composite_group  = CAM_TFE_BUS_COMP_GRP_4,
			.rup_group_id     = CAM_TFE_BUS_RUP_GRP_0,
			.mid              = 21,
		},
		{
			.tfe_out_id       = CAM_TFE_BUS_TFE_OUT_STATS_RS,
			.max_width        = -1,
			.max_height       = -1,
			.composite_group  = CAM_TFE_BUS_COMP_GRP_10,
			.rup_group_id     = CAM_TFE_BUS_RUP_GRP_0,
			.mid              = 27,
		},
		{
			.tfe_out_id       = CAM_TFE_BUS_TFE_OUT_DS4,
			.max_width        = -1,
			.max_height       = -1,
			.composite_group  = CAM_TFE_BUS_COMP_GRP_0,
			.rup_group_id     = CAM_TFE_BUS_RUP_GRP_0,
			.mid              = 22,
		},
		{
			.tfe_out_id       = CAM_TFE_BUS_TFE_OUT_DS16,
			.max_width        = -1,
			.max_height       = -1,
			.composite_group  = CAM_TFE_BUS_COMP_GRP_0,
			.rup_group_id     = CAM_TFE_BUS_RUP_GRP_0,
			.mid              = 23,
		},
		{
			.tfe_out_id       = CAM_TFE_BUS_TFE_OUT_AI,
			.max_width        = 1920,
			.max_height       = 1920,
			.composite_group  = CAM_TFE_BUS_COMP_GRP_9,
			.rup_group_id     = CAM_TFE_BUS_RUP_GRP_0,
			.mid              = 24,
		},
	},
	.num_comp_grp             = 11,
	.max_wm_per_comp_grp      = 3,
	.comp_done_shift          = 8,
	.top_bus_wr_irq_shift     = 1,
	.comp_buf_done_mask = 0x7FF00,
	.comp_rup_done_mask = 0xF,
	.bus_irq_error_mask = {
		0xD0000000,
		0x00000000,
	},
	.support_consumed_addr = true,
	.pdaf_rdi2_mux_en = false,
	.rdi_width = 128,
};

struct cam_tfe_hw_info cam_tfe640 = {
	.top_irq_mask = {
		0x00001834,
		0x00001838,
		0x0000183C,
	},
	.top_irq_clear = {
		0x00001840,
		0x00001844,
		0x00001848,
	},
	.top_irq_status = {
		0x0000184C,
		0x00001850,
		0x00001854,
	},
	.top_irq_cmd                       = 0x00001830,
	.global_clear_bitmask              = 0x00000001,
	.bus_irq_mask = {
		0x00003018,
		0x0000301C,
	},
	.bus_irq_clear = {
		0x00003020,
		0x00003024,
	},
	.bus_irq_status = {
		0x00003028,
		0x0000302C,
	},
	.bus_irq_cmd = 0x00003030,
	.bus_violation_reg = 0x00003064,
	.bus_overflow_reg = 0x00003068,
	.bus_image_size_vilation_reg = 0x3070,
	.bus_overflow_clear_cmd = 0x3060,
	.debug_status_top = 0x30D8,

	.reset_irq_mask = {
		0x00000001,
		0x00000000,
		0x00000000,
	},
	.error_irq_mask = {
		0x000F0F00,
		0x00000000,
		0x0000003F,
	},
	.bus_reg_irq_mask = {
		0x00000002,
		0x00000000,
	},
	.bus_error_irq_mask = {
		0xC0000000,
		0x00000000,
	},

	.num_clc = 39,
	.clc_hw_status_info            = tfe640_clc_hw_info,
	.bus_version                   = CAM_TFE_BUS_1_0,
	.bus_hw_info                   = &tfe640_bus_hw_info,

	.top_version                   = CAM_TFE_TOP_1_0,
	.top_hw_info                   = &tfe640_top_hw_info,
};

#endif /* _CAM_TFE640__H_ */