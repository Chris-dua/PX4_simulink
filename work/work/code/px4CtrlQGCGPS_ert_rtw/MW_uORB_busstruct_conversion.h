#ifndef _MW_UORB_BUSSTRUCT_CONVERSION_H_
#define _MW_UORB_BUSSTRUCT_CONVERSION_H_

#include <uORB/topics/actuator_outputs.h>
#include <uORB/topics/input_rc.h>
#include <uORB/topics/vehicle_gps_position.h>
#include <uORB/topics/vehicle_local_position.h>
#include <uORB/topics/vehicle_odometry.h>

typedef struct actuator_outputs_s  px4_Bus_actuator_outputs ;
typedef struct input_rc_s  px4_Bus_input_rc ;
typedef struct vehicle_gps_position_s  px4_Bus_vehicle_gps_position ;
typedef struct vehicle_local_position_s  px4_Bus_vehicle_local_position ;
typedef struct vehicle_odometry_s  px4_Bus_vehicle_odometry ;

#endif
