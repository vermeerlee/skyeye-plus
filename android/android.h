/* Copyright (C)
* xq2537@gmail.com
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* as published by the Free Software Foundation; either version 2
* of the License, or (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
* 
*/
/**
* @file android.h
* @brief The definition of system controller 
* @author xq2537@gmail.com
* @version 78.77
*/

/* Autogenerated by SkyEye script */
#ifndef __android_H__
#define __android_H__

#define  CONFIG_SHAPER  1

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <skyeye_types.h>

typedef struct android_t{
	conf_object_t* obj;
}android_t;

/** in vl.c */

/* emulated network up/down speeds, expressed in bits/seconds */
extern double   qemu_net_upload_speed;
extern double   qemu_net_download_speed;

/* emulated network min-max latency, expressed in ms */
extern int      qemu_net_min_latency;
extern int      qemu_net_max_latency;

/* global flag, when true, network is disabled */
extern int      qemu_net_disable;

/* list of supported network speed names and values in bits/seconds */
typedef struct {
    const char*  name;
    const char*  display;
    int          upload;
    int          download;
} NetworkSpeed;

extern const NetworkSpeed   android_netspeeds[];
extern const size_t android_netspeeds_count;

/* list of supported network latency names and min-max values in ms */
typedef struct {
    const char*  name;
    const char*  display;
    int          min_ms;
    int          max_ms;
} NetworkLatency;

extern const NetworkLatency  android_netdelays[];
extern const size_t android_netdelays_count;

/* default network settings for emulator */
#define  DEFAULT_NETSPEED  "full"
#define  DEFAULT_NETDELAY  "none"

/* enable/disable interrupt polling mode. the emulator will always use 100%
 * of host CPU time, but will get high-quality time measurments. this is
 * required for the tracing mode unless you can bear 10ms granularities
 */
extern void  qemu_polling_enable(void);
extern void  qemu_polling_disable(void);

/**in hw/goldfish_fb.c */

/* framebuffer dimensions in pixels, note these can change dynamically */
extern int  android_framebuffer_w;
extern int  android_framebuffer_h;
/* framebuffer dimensions in mm */
extern int  android_framebuffer_phys_w;
extern int  android_framebuffer_phys_h;

/* framebuffer rotation, relative to device */
typedef enum {
    ANDROID_ROTATION_0 = 0,
    ANDROID_ROTATION_90,
    ANDROID_ROTATION_180,
    ANDROID_ROTATION_270
} AndroidRotation;

extern AndroidRotation  android_framebuffer_rotation;

/**  in android_main.c */

/* this is the port used for the control console in this emulator instance.
 * starts at 5554, with increments of 2 */
extern int   android_base_port;

/* parses a network speed parameter and sets qemu_net_upload_speed and
 * qemu_net_download_speed accordingly. returns -1 on failure, 0 on success */
extern int   android_parse_network_speed(const char*  speed);

/* parse a network delay parameter and sets qemu_net_min/max_latency
 * accordingly. returns -1 on error, 0 on success */
extern int   android_parse_network_latency(const char*  delay);

extern void  android_emulation_setup( void );
extern void  android_emulation_teardown( void );
#endif