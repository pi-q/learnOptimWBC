#ifndef __c27_torqueBalancing2012b_h__
#define __c27_torqueBalancing2012b_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef struct_struct_amzdx4J7qaaMzgPI7fQ3WD_tag
#define struct_struct_amzdx4J7qaaMzgPI7fQ3WD_tag

struct struct_amzdx4J7qaaMzgPI7fQ3WD_tag
{
  boolean_T ALL;
  boolean_T BASE_EST_IMU;
  boolean_T EXTWRENCHES;
  boolean_T GAIN_SCHE_INFO;
  boolean_T MAIN;
  boolean_T QP;
};

#endif                                 /*struct_struct_amzdx4J7qaaMzgPI7fQ3WD_tag*/

#ifndef typedef_c27_struct_amzdx4J7qaaMzgPI7fQ3WD
#define typedef_c27_struct_amzdx4J7qaaMzgPI7fQ3WD

typedef struct struct_amzdx4J7qaaMzgPI7fQ3WD_tag
  c27_struct_amzdx4J7qaaMzgPI7fQ3WD;

#endif                                 /*typedef_c27_struct_amzdx4J7qaaMzgPI7fQ3WD*/

#ifndef typedef_c27_ResolvedFunctionInfo
#define typedef_c27_ResolvedFunctionInfo

typedef struct {
  const char * context;
  const char * name;
  const char * dominantType;
  const char * resolved;
  uint32_T fileTimeLo;
  uint32_T fileTimeHi;
  uint32_T mFileTimeLo;
  uint32_T mFileTimeHi;
} c27_ResolvedFunctionInfo;

#endif                                 /*typedef_c27_ResolvedFunctionInfo*/

#ifndef struct_struct_J679E6VlgqRAQnIVQBeUwF_tag
#define struct_struct_J679E6VlgqRAQnIVQBeUwF_tag

struct struct_J679E6VlgqRAQnIVQBeUwF_tag
{
  real_T SIMULATION_TIME;
  c27_struct_amzdx4J7qaaMzgPI7fQ3WD SCOPES;
  boolean_T CHECK_LIMITS;
  boolean_T USE_IMU4EST_BASE;
  boolean_T YAW_IMU_FILTER;
  boolean_T PITCH_IMU_FILTER;
  boolean_T CORRECT_NECK_IMU;
  boolean_T ONSOFTCARPET;
  boolean_T USE_QP_SOLVER;
  real_T Ts;
  boolean_T ON_GAZEBO;
  real_T LEFT_RIGHT_FOOT_IN_CONTACT[2];
  real_T SMOOTH_DES_COM;
  real_T SMOOTH_DES_Q;
  real_T smoothingTimeTranDynamics;
  boolean_T DEMO_MOVEMENTS;
  real_T TIME_CONTROLLER_SWITCH;
  real_T JOINTS[23];
  real_T JOINTSITING[23];
  boolean_T iCubStandUp;
  boolean_T useExtArmForces;
  real_T PAUSETIME;
};

#endif                                 /*struct_struct_J679E6VlgqRAQnIVQBeUwF_tag*/

#ifndef typedef_c27_struct_J679E6VlgqRAQnIVQBeUwF
#define typedef_c27_struct_J679E6VlgqRAQnIVQBeUwF

typedef struct struct_J679E6VlgqRAQnIVQBeUwF_tag
  c27_struct_J679E6VlgqRAQnIVQBeUwF;

#endif                                 /*typedef_c27_struct_J679E6VlgqRAQnIVQBeUwF*/

#ifndef typedef_SFc27_torqueBalancing2012bInstanceStruct
#define typedef_SFc27_torqueBalancing2012bInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c27_sfEvent;
  boolean_T c27_isStable;
  boolean_T c27_doneDoubleBufferReInit;
  uint8_T c27_is_active_c27_torqueBalancing2012b;
  c27_struct_J679E6VlgqRAQnIVQBeUwF c27_CONFIG;
} SFc27_torqueBalancing2012bInstanceStruct;

#endif                                 /*typedef_SFc27_torqueBalancing2012bInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c27_torqueBalancing2012b_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c27_torqueBalancing2012b_get_check_sum(mxArray *plhs[]);
extern void c27_torqueBalancing2012b_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
