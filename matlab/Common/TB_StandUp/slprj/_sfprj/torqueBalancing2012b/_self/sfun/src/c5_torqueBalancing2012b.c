/* Include files */

#include <stddef.h>
#include "blas.h"
#include "torqueBalancing2012b_sfun.h"
#include "c5_torqueBalancing2012b.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "torqueBalancing2012b_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c5_debug_family_names[10] = { "Jc", "pinvJb", "nargin",
  "nargout", "JcLeftFoot", "JcRightFoot", "activeFeetConstraints", "qD", "reg",
  "y" };

/* Function Declarations */
static void initialize_c5_torqueBalancing2012b
  (SFc5_torqueBalancing2012bInstanceStruct *chartInstance);
static void initialize_params_c5_torqueBalancing2012b
  (SFc5_torqueBalancing2012bInstanceStruct *chartInstance);
static void enable_c5_torqueBalancing2012b
  (SFc5_torqueBalancing2012bInstanceStruct *chartInstance);
static void disable_c5_torqueBalancing2012b
  (SFc5_torqueBalancing2012bInstanceStruct *chartInstance);
static void c5_update_debugger_state_c5_torqueBalancing2012b
  (SFc5_torqueBalancing2012bInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c5_torqueBalancing2012b
  (SFc5_torqueBalancing2012bInstanceStruct *chartInstance);
static void set_sim_state_c5_torqueBalancing2012b
  (SFc5_torqueBalancing2012bInstanceStruct *chartInstance, const mxArray *c5_st);
static void finalize_c5_torqueBalancing2012b
  (SFc5_torqueBalancing2012bInstanceStruct *chartInstance);
static void sf_c5_torqueBalancing2012b(SFc5_torqueBalancing2012bInstanceStruct
  *chartInstance);
static void c5_chartstep_c5_torqueBalancing2012b
  (SFc5_torqueBalancing2012bInstanceStruct *chartInstance);
static void initSimStructsc5_torqueBalancing2012b
  (SFc5_torqueBalancing2012bInstanceStruct *chartInstance);
static void registerMessagesc5_torqueBalancing2012b
  (SFc5_torqueBalancing2012bInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber);
static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData);
static void c5_emlrt_marshallIn(SFc5_torqueBalancing2012bInstanceStruct
  *chartInstance, const mxArray *c5_y, const char_T *c5_identifier, real_T
  c5_b_y[6]);
static void c5_b_emlrt_marshallIn(SFc5_torqueBalancing2012bInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_y[6]);
static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static c5_struct_1ZGMVR6bgCMpDdXTSGnu6G c5_c_emlrt_marshallIn
  (SFc5_torqueBalancing2012bInstanceStruct *chartInstance, const mxArray *c5_u,
   const emlrtMsgIdentifier *c5_parentId);
static real_T c5_d_emlrt_marshallIn(SFc5_torqueBalancing2012bInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_d_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_e_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_f_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static void c5_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_g_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static void c5_e_emlrt_marshallIn(SFc5_torqueBalancing2012bInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_y[72]);
static void c5_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_h_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static void c5_f_emlrt_marshallIn(SFc5_torqueBalancing2012bInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_y[348]);
static void c5_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static void c5_info_helper(c5_ResolvedFunctionInfo c5_info[125]);
static void c5_b_info_helper(c5_ResolvedFunctionInfo c5_info[125]);
static void c5_eml_scalar_eg(SFc5_torqueBalancing2012bInstanceStruct
  *chartInstance);
static void c5_mldivide(SFc5_torqueBalancing2012bInstanceStruct *chartInstance,
  real_T c5_A[36], real_T c5_B[72], real_T c5_Y[72]);
static void c5_realmin(SFc5_torqueBalancing2012bInstanceStruct *chartInstance);
static void c5_eps(SFc5_torqueBalancing2012bInstanceStruct *chartInstance);
static void c5_eml_matlab_zgetrf(SFc5_torqueBalancing2012bInstanceStruct
  *chartInstance, real_T c5_A[36], real_T c5_b_A[36], int32_T c5_ipiv[6],
  int32_T *c5_info);
static void c5_check_forloop_overflow_error
  (SFc5_torqueBalancing2012bInstanceStruct *chartInstance, boolean_T c5_overflow);
static void c5_eml_xger(SFc5_torqueBalancing2012bInstanceStruct *chartInstance,
  int32_T c5_m, int32_T c5_n, real_T c5_alpha1, int32_T c5_ix0, int32_T c5_iy0,
  real_T c5_A[36], int32_T c5_ia0, real_T c5_b_A[36]);
static void c5_eml_warning(SFc5_torqueBalancing2012bInstanceStruct
  *chartInstance);
static void c5_eml_xtrsm(SFc5_torqueBalancing2012bInstanceStruct *chartInstance,
  real_T c5_A[36], real_T c5_B[72], real_T c5_b_B[72]);
static void c5_below_threshold(SFc5_torqueBalancing2012bInstanceStruct
  *chartInstance);
static void c5_b_eml_scalar_eg(SFc5_torqueBalancing2012bInstanceStruct
  *chartInstance);
static void c5_b_eml_xtrsm(SFc5_torqueBalancing2012bInstanceStruct
  *chartInstance, real_T c5_A[36], real_T c5_B[72], real_T c5_b_B[72]);
static void c5_c_eml_scalar_eg(SFc5_torqueBalancing2012bInstanceStruct
  *chartInstance);
static void c5_eml_xgemm(SFc5_torqueBalancing2012bInstanceStruct *chartInstance,
  real_T c5_A[72], real_T c5_B[276], real_T c5_C[138], real_T c5_b_C[138]);
static void c5_d_eml_scalar_eg(SFc5_torqueBalancing2012bInstanceStruct
  *chartInstance);
static const mxArray *c5_i_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static int32_T c5_g_emlrt_marshallIn(SFc5_torqueBalancing2012bInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static uint8_T c5_h_emlrt_marshallIn(SFc5_torqueBalancing2012bInstanceStruct
  *chartInstance, const mxArray *c5_b_is_active_c5_torqueBalancing2012b, const
  char_T *c5_identifier);
static uint8_T c5_i_emlrt_marshallIn(SFc5_torqueBalancing2012bInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_b_eml_matlab_zgetrf(SFc5_torqueBalancing2012bInstanceStruct
  *chartInstance, real_T c5_A[36], int32_T c5_ipiv[6], int32_T *c5_info);
static void c5_b_eml_xger(SFc5_torqueBalancing2012bInstanceStruct *chartInstance,
  int32_T c5_m, int32_T c5_n, real_T c5_alpha1, int32_T c5_ix0, int32_T c5_iy0,
  real_T c5_A[36], int32_T c5_ia0);
static void c5_c_eml_xtrsm(SFc5_torqueBalancing2012bInstanceStruct
  *chartInstance, real_T c5_A[36], real_T c5_B[72]);
static void c5_d_eml_xtrsm(SFc5_torqueBalancing2012bInstanceStruct
  *chartInstance, real_T c5_A[36], real_T c5_B[72]);
static void c5_b_eml_xgemm(SFc5_torqueBalancing2012bInstanceStruct
  *chartInstance, real_T c5_A[72], real_T c5_B[276], real_T c5_C[138]);
static void init_dsm_address_info(SFc5_torqueBalancing2012bInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c5_torqueBalancing2012b
  (SFc5_torqueBalancing2012bInstanceStruct *chartInstance)
{
  chartInstance->c5_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c5_is_active_c5_torqueBalancing2012b = 0U;
}

static void initialize_params_c5_torqueBalancing2012b
  (SFc5_torqueBalancing2012bInstanceStruct *chartInstance)
{
  const mxArray *c5_m0 = NULL;
  const mxArray *c5_mxField;
  c5_struct_1ZGMVR6bgCMpDdXTSGnu6G c5_r0;
  sf_set_error_prefix_string(
    "Error evaluating data 'reg' in the parent workspace.\n");
  c5_m0 = sf_mex_get_sfun_param(chartInstance->S, 0, 1);
  c5_mxField = sf_mex_getfield(c5_m0, "pinvTol", "reg", 0);
  sf_mex_import_named("reg", sf_mex_dup(c5_mxField), &c5_r0.pinvTol, 1, 0, 0U, 0,
                      0U, 0);
  c5_mxField = sf_mex_getfield(c5_m0, "pinvDamp", "reg", 0);
  sf_mex_import_named("reg", sf_mex_dup(c5_mxField), &c5_r0.pinvDamp, 1, 0, 0U,
                      0, 0U, 0);
  c5_mxField = sf_mex_getfield(c5_m0, "pinvDampVb", "reg", 0);
  sf_mex_import_named("reg", sf_mex_dup(c5_mxField), &c5_r0.pinvDampVb, 1, 0, 0U,
                      0, 0U, 0);
  c5_mxField = sf_mex_getfield(c5_m0, "HessianQP", "reg", 0);
  sf_mex_import_named("reg", sf_mex_dup(c5_mxField), &c5_r0.HessianQP, 1, 0, 0U,
                      0, 0U, 0);
  c5_mxField = sf_mex_getfield(c5_m0, "impedances", "reg", 0);
  sf_mex_import_named("reg", sf_mex_dup(c5_mxField), &c5_r0.impedances, 1, 0, 0U,
                      0, 0U, 0);
  c5_mxField = sf_mex_getfield(c5_m0, "dampings", "reg", 0);
  sf_mex_import_named("reg", sf_mex_dup(c5_mxField), &c5_r0.dampings, 1, 0, 0U,
                      0, 0U, 0);
  c5_mxField = sf_mex_getfield(c5_m0, "norm_tolerance", "reg", 0);
  sf_mex_import_named("reg", sf_mex_dup(c5_mxField), &c5_r0.norm_tolerance, 1, 0,
                      0U, 0, 0U, 0);
  sf_mex_destroy(&c5_m0);
  chartInstance->c5_reg = c5_r0;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c5_torqueBalancing2012b
  (SFc5_torqueBalancing2012bInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c5_torqueBalancing2012b
  (SFc5_torqueBalancing2012bInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c5_update_debugger_state_c5_torqueBalancing2012b
  (SFc5_torqueBalancing2012bInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c5_torqueBalancing2012b
  (SFc5_torqueBalancing2012bInstanceStruct *chartInstance)
{
  const mxArray *c5_st;
  const mxArray *c5_y = NULL;
  int32_T c5_i0;
  real_T c5_u[6];
  const mxArray *c5_b_y = NULL;
  uint8_T c5_hoistedGlobal;
  uint8_T c5_b_u;
  const mxArray *c5_c_y = NULL;
  real_T (*c5_d_y)[6];
  c5_d_y = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c5_st = NULL;
  c5_st = NULL;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_createcellarray(2), FALSE);
  for (c5_i0 = 0; c5_i0 < 6; c5_i0++) {
    c5_u[c5_i0] = (*c5_d_y)[c5_i0];
  }

  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  sf_mex_setcell(c5_y, 0, c5_b_y);
  c5_hoistedGlobal = chartInstance->c5_is_active_c5_torqueBalancing2012b;
  c5_b_u = c5_hoistedGlobal;
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", &c5_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c5_y, 1, c5_c_y);
  sf_mex_assign(&c5_st, c5_y, FALSE);
  return c5_st;
}

static void set_sim_state_c5_torqueBalancing2012b
  (SFc5_torqueBalancing2012bInstanceStruct *chartInstance, const mxArray *c5_st)
{
  const mxArray *c5_u;
  real_T c5_dv0[6];
  int32_T c5_i1;
  real_T (*c5_y)[6];
  c5_y = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c5_doneDoubleBufferReInit = TRUE;
  c5_u = sf_mex_dup(c5_st);
  c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 0)), "y",
                      c5_dv0);
  for (c5_i1 = 0; c5_i1 < 6; c5_i1++) {
    (*c5_y)[c5_i1] = c5_dv0[c5_i1];
  }

  chartInstance->c5_is_active_c5_torqueBalancing2012b = c5_h_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 1)),
     "is_active_c5_torqueBalancing2012b");
  sf_mex_destroy(&c5_u);
  c5_update_debugger_state_c5_torqueBalancing2012b(chartInstance);
  sf_mex_destroy(&c5_st);
}

static void finalize_c5_torqueBalancing2012b
  (SFc5_torqueBalancing2012bInstanceStruct *chartInstance)
{
}

static void sf_c5_torqueBalancing2012b(SFc5_torqueBalancing2012bInstanceStruct
  *chartInstance)
{
  int32_T c5_i2;
  int32_T c5_i3;
  int32_T c5_i4;
  int32_T c5_i5;
  int32_T c5_i6;
  real_T (*c5_qD)[23];
  real_T (*c5_y)[6];
  real_T (*c5_activeFeetConstraints)[2];
  real_T (*c5_JcRightFoot)[174];
  real_T (*c5_JcLeftFoot)[174];
  c5_qD = (real_T (*)[23])ssGetInputPortSignal(chartInstance->S, 3);
  c5_y = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c5_activeFeetConstraints = (real_T (*)[2])ssGetInputPortSignal
    (chartInstance->S, 2);
  c5_JcRightFoot = (real_T (*)[174])ssGetInputPortSignal(chartInstance->S, 1);
  c5_JcLeftFoot = (real_T (*)[174])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 3U, chartInstance->c5_sfEvent);
  for (c5_i2 = 0; c5_i2 < 174; c5_i2++) {
    _SFD_DATA_RANGE_CHECK((*c5_JcLeftFoot)[c5_i2], 0U);
  }

  for (c5_i3 = 0; c5_i3 < 174; c5_i3++) {
    _SFD_DATA_RANGE_CHECK((*c5_JcRightFoot)[c5_i3], 1U);
  }

  for (c5_i4 = 0; c5_i4 < 2; c5_i4++) {
    _SFD_DATA_RANGE_CHECK((*c5_activeFeetConstraints)[c5_i4], 2U);
  }

  for (c5_i5 = 0; c5_i5 < 6; c5_i5++) {
    _SFD_DATA_RANGE_CHECK((*c5_y)[c5_i5], 3U);
  }

  for (c5_i6 = 0; c5_i6 < 23; c5_i6++) {
    _SFD_DATA_RANGE_CHECK((*c5_qD)[c5_i6], 4U);
  }

  chartInstance->c5_sfEvent = CALL_EVENT;
  c5_chartstep_c5_torqueBalancing2012b(chartInstance);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_torqueBalancing2012bMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c5_chartstep_c5_torqueBalancing2012b
  (SFc5_torqueBalancing2012bInstanceStruct *chartInstance)
{
  int32_T c5_i7;
  real_T c5_JcLeftFoot[174];
  int32_T c5_i8;
  real_T c5_JcRightFoot[174];
  int32_T c5_i9;
  real_T c5_activeFeetConstraints[2];
  int32_T c5_i10;
  real_T c5_qD[23];
  c5_struct_1ZGMVR6bgCMpDdXTSGnu6G c5_b_reg;
  uint32_T c5_debug_family_var_map[10];
  real_T c5_Jc[348];
  real_T c5_pinvJb[72];
  real_T c5_nargin = 5.0;
  real_T c5_nargout = 1.0;
  real_T c5_y[6];
  real_T c5_a;
  int32_T c5_i11;
  real_T c5_b[174];
  int32_T c5_i12;
  real_T c5_b_a;
  int32_T c5_i13;
  real_T c5_b_b[174];
  int32_T c5_i14;
  int32_T c5_i15;
  int32_T c5_i16;
  int32_T c5_i17;
  int32_T c5_i18;
  int32_T c5_i19;
  int32_T c5_i20;
  int32_T c5_i21;
  int32_T c5_i22;
  int32_T c5_i23;
  int32_T c5_i24;
  int32_T c5_i25;
  int32_T c5_i26;
  real_T c5_c_a[72];
  int32_T c5_i27;
  int32_T c5_i28;
  int32_T c5_i29;
  real_T c5_c_b[72];
  int32_T c5_i30;
  int32_T c5_i31;
  int32_T c5_i32;
  int32_T c5_i33;
  real_T c5_b_y[36];
  int32_T c5_i34;
  int32_T c5_i35;
  real_T c5_d_a;
  int32_T c5_i36;
  static real_T c5_d_b[36] = { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0 };

  real_T c5_c_y[36];
  int32_T c5_i37;
  real_T c5_d_y[36];
  int32_T c5_i38;
  int32_T c5_i39;
  int32_T c5_i40;
  int32_T c5_i41;
  real_T c5_b_Jc[72];
  real_T c5_dv1[72];
  int32_T c5_i42;
  int32_T c5_i43;
  int32_T c5_i44;
  int32_T c5_i45;
  int32_T c5_i46;
  real_T c5_e_b[276];
  int32_T c5_i47;
  real_T c5_e_y[138];
  int32_T c5_i48;
  real_T c5_e_a[72];
  int32_T c5_i49;
  real_T c5_f_b[276];
  int32_T c5_i50;
  real_T c5_g_b[23];
  int32_T c5_i51;
  int32_T c5_i52;
  int32_T c5_i53;
  real_T c5_C[6];
  int32_T c5_i54;
  int32_T c5_i55;
  int32_T c5_i56;
  int32_T c5_i57;
  int32_T c5_i58;
  int32_T c5_i59;
  int32_T c5_i60;
  real_T (*c5_f_y)[6];
  real_T (*c5_b_qD)[23];
  real_T (*c5_b_activeFeetConstraints)[2];
  real_T (*c5_b_JcRightFoot)[174];
  real_T (*c5_b_JcLeftFoot)[174];
  c5_b_qD = (real_T (*)[23])ssGetInputPortSignal(chartInstance->S, 3);
  c5_f_y = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c5_b_activeFeetConstraints = (real_T (*)[2])ssGetInputPortSignal
    (chartInstance->S, 2);
  c5_b_JcRightFoot = (real_T (*)[174])ssGetInputPortSignal(chartInstance->S, 1);
  c5_b_JcLeftFoot = (real_T (*)[174])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c5_sfEvent);
  for (c5_i7 = 0; c5_i7 < 174; c5_i7++) {
    c5_JcLeftFoot[c5_i7] = (*c5_b_JcLeftFoot)[c5_i7];
  }

  for (c5_i8 = 0; c5_i8 < 174; c5_i8++) {
    c5_JcRightFoot[c5_i8] = (*c5_b_JcRightFoot)[c5_i8];
  }

  for (c5_i9 = 0; c5_i9 < 2; c5_i9++) {
    c5_activeFeetConstraints[c5_i9] = (*c5_b_activeFeetConstraints)[c5_i9];
  }

  for (c5_i10 = 0; c5_i10 < 23; c5_i10++) {
    c5_qD[c5_i10] = (*c5_b_qD)[c5_i10];
  }

  c5_b_reg = chartInstance->c5_reg;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 10U, 10U, c5_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_Jc, 0U, c5_h_sf_marshallOut,
    c5_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_pinvJb, 1U, c5_g_sf_marshallOut,
    c5_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 2U, c5_f_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 3U, c5_f_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_JcLeftFoot, 4U, c5_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_JcRightFoot, 5U, c5_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_activeFeetConstraints, 6U, c5_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_qD, 7U, c5_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_reg, 8U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_y, 9U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 4);
  c5_a = c5_activeFeetConstraints[0];
  for (c5_i11 = 0; c5_i11 < 174; c5_i11++) {
    c5_b[c5_i11] = c5_JcLeftFoot[c5_i11];
  }

  for (c5_i12 = 0; c5_i12 < 174; c5_i12++) {
    c5_b[c5_i12] *= c5_a;
  }

  c5_b_a = c5_activeFeetConstraints[1];
  for (c5_i13 = 0; c5_i13 < 174; c5_i13++) {
    c5_b_b[c5_i13] = c5_JcRightFoot[c5_i13];
  }

  for (c5_i14 = 0; c5_i14 < 174; c5_i14++) {
    c5_b_b[c5_i14] *= c5_b_a;
  }

  c5_i15 = 0;
  c5_i16 = 0;
  for (c5_i17 = 0; c5_i17 < 29; c5_i17++) {
    for (c5_i18 = 0; c5_i18 < 6; c5_i18++) {
      c5_Jc[c5_i18 + c5_i15] = c5_b[c5_i18 + c5_i16];
    }

    c5_i15 += 12;
    c5_i16 += 6;
  }

  c5_i19 = 0;
  c5_i20 = 0;
  for (c5_i21 = 0; c5_i21 < 29; c5_i21++) {
    for (c5_i22 = 0; c5_i22 < 6; c5_i22++) {
      c5_Jc[(c5_i22 + c5_i19) + 6] = c5_b_b[c5_i22 + c5_i20];
    }

    c5_i19 += 12;
    c5_i20 += 6;
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 7);
  c5_i23 = 0;
  for (c5_i24 = 0; c5_i24 < 12; c5_i24++) {
    c5_i25 = 0;
    for (c5_i26 = 0; c5_i26 < 6; c5_i26++) {
      c5_c_a[c5_i26 + c5_i23] = c5_Jc[c5_i25 + c5_i24];
      c5_i25 += 12;
    }

    c5_i23 += 6;
  }

  c5_i27 = 0;
  for (c5_i28 = 0; c5_i28 < 6; c5_i28++) {
    for (c5_i29 = 0; c5_i29 < 12; c5_i29++) {
      c5_c_b[c5_i29 + c5_i27] = c5_Jc[c5_i29 + c5_i27];
    }

    c5_i27 += 12;
  }

  c5_eml_scalar_eg(chartInstance);
  c5_eml_scalar_eg(chartInstance);
  for (c5_i30 = 0; c5_i30 < 6; c5_i30++) {
    c5_i31 = 0;
    c5_i32 = 0;
    for (c5_i33 = 0; c5_i33 < 6; c5_i33++) {
      c5_b_y[c5_i31 + c5_i30] = 0.0;
      c5_i34 = 0;
      for (c5_i35 = 0; c5_i35 < 12; c5_i35++) {
        c5_b_y[c5_i31 + c5_i30] += c5_c_a[c5_i34 + c5_i30] * c5_c_b[c5_i35 +
          c5_i32];
        c5_i34 += 6;
      }

      c5_i31 += 6;
      c5_i32 += 12;
    }
  }

  c5_d_a = c5_b_reg.pinvDampVb;
  for (c5_i36 = 0; c5_i36 < 36; c5_i36++) {
    c5_c_y[c5_i36] = c5_d_a * c5_d_b[c5_i36];
  }

  for (c5_i37 = 0; c5_i37 < 36; c5_i37++) {
    c5_d_y[c5_i37] = c5_b_y[c5_i37] + c5_c_y[c5_i37];
  }

  c5_i38 = 0;
  for (c5_i39 = 0; c5_i39 < 12; c5_i39++) {
    c5_i40 = 0;
    for (c5_i41 = 0; c5_i41 < 6; c5_i41++) {
      c5_b_Jc[c5_i41 + c5_i38] = c5_Jc[c5_i40 + c5_i39];
      c5_i40 += 12;
    }

    c5_i38 += 6;
  }

  c5_mldivide(chartInstance, c5_d_y, c5_b_Jc, c5_dv1);
  for (c5_i42 = 0; c5_i42 < 72; c5_i42++) {
    c5_pinvJb[c5_i42] = c5_dv1[c5_i42];
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 11);
  for (c5_i43 = 0; c5_i43 < 72; c5_i43++) {
    c5_c_a[c5_i43] = -c5_pinvJb[c5_i43];
  }

  c5_i44 = 0;
  for (c5_i45 = 0; c5_i45 < 23; c5_i45++) {
    for (c5_i46 = 0; c5_i46 < 12; c5_i46++) {
      c5_e_b[c5_i46 + c5_i44] = c5_Jc[(c5_i46 + c5_i44) + 72];
    }

    c5_i44 += 12;
  }

  c5_c_eml_scalar_eg(chartInstance);
  c5_c_eml_scalar_eg(chartInstance);
  for (c5_i47 = 0; c5_i47 < 138; c5_i47++) {
    c5_e_y[c5_i47] = 0.0;
  }

  for (c5_i48 = 0; c5_i48 < 72; c5_i48++) {
    c5_e_a[c5_i48] = c5_c_a[c5_i48];
  }

  for (c5_i49 = 0; c5_i49 < 276; c5_i49++) {
    c5_f_b[c5_i49] = c5_e_b[c5_i49];
  }

  c5_b_eml_xgemm(chartInstance, c5_e_a, c5_f_b, c5_e_y);
  for (c5_i50 = 0; c5_i50 < 23; c5_i50++) {
    c5_g_b[c5_i50] = c5_qD[c5_i50];
  }

  c5_d_eml_scalar_eg(chartInstance);
  c5_d_eml_scalar_eg(chartInstance);
  for (c5_i51 = 0; c5_i51 < 6; c5_i51++) {
    c5_y[c5_i51] = 0.0;
  }

  for (c5_i52 = 0; c5_i52 < 6; c5_i52++) {
    c5_y[c5_i52] = 0.0;
  }

  for (c5_i53 = 0; c5_i53 < 6; c5_i53++) {
    c5_C[c5_i53] = c5_y[c5_i53];
  }

  for (c5_i54 = 0; c5_i54 < 6; c5_i54++) {
    c5_y[c5_i54] = c5_C[c5_i54];
  }

  for (c5_i55 = 0; c5_i55 < 6; c5_i55++) {
    c5_C[c5_i55] = c5_y[c5_i55];
  }

  for (c5_i56 = 0; c5_i56 < 6; c5_i56++) {
    c5_y[c5_i56] = c5_C[c5_i56];
  }

  for (c5_i57 = 0; c5_i57 < 6; c5_i57++) {
    c5_y[c5_i57] = 0.0;
    c5_i58 = 0;
    for (c5_i59 = 0; c5_i59 < 23; c5_i59++) {
      c5_y[c5_i57] += c5_e_y[c5_i58 + c5_i57] * c5_g_b[c5_i59];
      c5_i58 += 6;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
  for (c5_i60 = 0; c5_i60 < 6; c5_i60++) {
    (*c5_f_y)[c5_i60] = c5_y[c5_i60];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c5_sfEvent);
}

static void initSimStructsc5_torqueBalancing2012b
  (SFc5_torqueBalancing2012bInstanceStruct *chartInstance)
{
}

static void registerMessagesc5_torqueBalancing2012b
  (SFc5_torqueBalancing2012bInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber)
{
}

static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i61;
  real_T c5_b_inData[6];
  int32_T c5_i62;
  real_T c5_u[6];
  const mxArray *c5_y = NULL;
  SFc5_torqueBalancing2012bInstanceStruct *chartInstance;
  chartInstance = (SFc5_torqueBalancing2012bInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i61 = 0; c5_i61 < 6; c5_i61++) {
    c5_b_inData[c5_i61] = (*(real_T (*)[6])c5_inData)[c5_i61];
  }

  for (c5_i62 = 0; c5_i62 < 6; c5_i62++) {
    c5_u[c5_i62] = c5_b_inData[c5_i62];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static void c5_emlrt_marshallIn(SFc5_torqueBalancing2012bInstanceStruct
  *chartInstance, const mxArray *c5_y, const char_T *c5_identifier, real_T
  c5_b_y[6])
{
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_y), &c5_thisId, c5_b_y);
  sf_mex_destroy(&c5_y);
}

static void c5_b_emlrt_marshallIn(SFc5_torqueBalancing2012bInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_y[6])
{
  real_T c5_dv2[6];
  int32_T c5_i63;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), c5_dv2, 1, 0, 0U, 1, 0U, 1, 6);
  for (c5_i63 = 0; c5_i63 < 6; c5_i63++) {
    c5_y[c5_i63] = c5_dv2[c5_i63];
  }

  sf_mex_destroy(&c5_u);
}

static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_y;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_b_y[6];
  int32_T c5_i64;
  SFc5_torqueBalancing2012bInstanceStruct *chartInstance;
  chartInstance = (SFc5_torqueBalancing2012bInstanceStruct *)chartInstanceVoid;
  c5_y = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_y), &c5_thisId, c5_b_y);
  sf_mex_destroy(&c5_y);
  for (c5_i64 = 0; c5_i64 < 6; c5_i64++) {
    (*(real_T (*)[6])c5_outData)[c5_i64] = c5_b_y[c5_i64];
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  c5_struct_1ZGMVR6bgCMpDdXTSGnu6G c5_u;
  const mxArray *c5_y = NULL;
  real_T c5_b_u;
  const mxArray *c5_b_y = NULL;
  real_T c5_c_u;
  const mxArray *c5_c_y = NULL;
  real_T c5_d_u;
  const mxArray *c5_d_y = NULL;
  real_T c5_e_u;
  const mxArray *c5_e_y = NULL;
  real_T c5_f_u;
  const mxArray *c5_f_y = NULL;
  real_T c5_g_u;
  const mxArray *c5_g_y = NULL;
  real_T c5_h_u;
  const mxArray *c5_h_y = NULL;
  SFc5_torqueBalancing2012bInstanceStruct *chartInstance;
  chartInstance = (SFc5_torqueBalancing2012bInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(c5_struct_1ZGMVR6bgCMpDdXTSGnu6G *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_createstruct("structure", 2, 1, 1), FALSE);
  c5_b_u = c5_u.pinvTol;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", &c5_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c5_y, c5_b_y, "pinvTol", "pinvTol", 0);
  c5_c_u = c5_u.pinvDamp;
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", &c5_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c5_y, c5_c_y, "pinvDamp", "pinvDamp", 0);
  c5_d_u = c5_u.pinvDampVb;
  c5_d_y = NULL;
  sf_mex_assign(&c5_d_y, sf_mex_create("y", &c5_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c5_y, c5_d_y, "pinvDampVb", "pinvDampVb", 0);
  c5_e_u = c5_u.HessianQP;
  c5_e_y = NULL;
  sf_mex_assign(&c5_e_y, sf_mex_create("y", &c5_e_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c5_y, c5_e_y, "HessianQP", "HessianQP", 0);
  c5_f_u = c5_u.impedances;
  c5_f_y = NULL;
  sf_mex_assign(&c5_f_y, sf_mex_create("y", &c5_f_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c5_y, c5_f_y, "impedances", "impedances", 0);
  c5_g_u = c5_u.dampings;
  c5_g_y = NULL;
  sf_mex_assign(&c5_g_y, sf_mex_create("y", &c5_g_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c5_y, c5_g_y, "dampings", "dampings", 0);
  c5_h_u = c5_u.norm_tolerance;
  c5_h_y = NULL;
  sf_mex_assign(&c5_h_y, sf_mex_create("y", &c5_h_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_addfield(c5_y, c5_h_y, "norm_tolerance", "norm_tolerance", 0);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static c5_struct_1ZGMVR6bgCMpDdXTSGnu6G c5_c_emlrt_marshallIn
  (SFc5_torqueBalancing2012bInstanceStruct *chartInstance, const mxArray *c5_u,
   const emlrtMsgIdentifier *c5_parentId)
{
  c5_struct_1ZGMVR6bgCMpDdXTSGnu6G c5_y;
  emlrtMsgIdentifier c5_thisId;
  static const char * c5_fieldNames[7] = { "pinvTol", "pinvDamp", "pinvDampVb",
    "HessianQP", "impedances", "dampings", "norm_tolerance" };

  c5_thisId.fParent = c5_parentId;
  sf_mex_check_struct(c5_parentId, c5_u, 7, c5_fieldNames, 0U, 0);
  c5_thisId.fIdentifier = "pinvTol";
  c5_y.pinvTol = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c5_u, "pinvTol", "pinvTol", 0)),
    &c5_thisId);
  c5_thisId.fIdentifier = "pinvDamp";
  c5_y.pinvDamp = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_u, "pinvDamp", "pinvDamp", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "pinvDampVb";
  c5_y.pinvDampVb = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_u, "pinvDampVb", "pinvDampVb", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "HessianQP";
  c5_y.HessianQP = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_u, "HessianQP", "HessianQP", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "impedances";
  c5_y.impedances = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_u, "impedances", "impedances", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "dampings";
  c5_y.dampings = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_u, "dampings", "dampings", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "norm_tolerance";
  c5_y.norm_tolerance = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_u, "norm_tolerance", "norm_tolerance", 0)), &c5_thisId);
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static real_T c5_d_emlrt_marshallIn(SFc5_torqueBalancing2012bInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  real_T c5_y;
  real_T c5_d0;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_d0, 1, 0, 0U, 0, 0U, 0);
  c5_y = c5_d0;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_reg;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  c5_struct_1ZGMVR6bgCMpDdXTSGnu6G c5_y;
  SFc5_torqueBalancing2012bInstanceStruct *chartInstance;
  chartInstance = (SFc5_torqueBalancing2012bInstanceStruct *)chartInstanceVoid;
  c5_b_reg = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_reg), &c5_thisId);
  sf_mex_destroy(&c5_b_reg);
  *(c5_struct_1ZGMVR6bgCMpDdXTSGnu6G *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i65;
  real_T c5_b_inData[23];
  int32_T c5_i66;
  real_T c5_u[23];
  const mxArray *c5_y = NULL;
  SFc5_torqueBalancing2012bInstanceStruct *chartInstance;
  chartInstance = (SFc5_torqueBalancing2012bInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i65 = 0; c5_i65 < 23; c5_i65++) {
    c5_b_inData[c5_i65] = (*(real_T (*)[23])c5_inData)[c5_i65];
  }

  for (c5_i66 = 0; c5_i66 < 23; c5_i66++) {
    c5_u[c5_i66] = c5_b_inData[c5_i66];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 1, 23), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static const mxArray *c5_d_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i67;
  real_T c5_b_inData[2];
  int32_T c5_i68;
  real_T c5_u[2];
  const mxArray *c5_y = NULL;
  SFc5_torqueBalancing2012bInstanceStruct *chartInstance;
  chartInstance = (SFc5_torqueBalancing2012bInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i67 = 0; c5_i67 < 2; c5_i67++) {
    c5_b_inData[c5_i67] = (*(real_T (*)[2])c5_inData)[c5_i67];
  }

  for (c5_i68 = 0; c5_i68 < 2; c5_i68++) {
    c5_u[c5_i68] = c5_b_inData[c5_i68];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 1, 2), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static const mxArray *c5_e_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i69;
  int32_T c5_i70;
  int32_T c5_i71;
  real_T c5_b_inData[174];
  int32_T c5_i72;
  int32_T c5_i73;
  int32_T c5_i74;
  real_T c5_u[174];
  const mxArray *c5_y = NULL;
  SFc5_torqueBalancing2012bInstanceStruct *chartInstance;
  chartInstance = (SFc5_torqueBalancing2012bInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_i69 = 0;
  for (c5_i70 = 0; c5_i70 < 29; c5_i70++) {
    for (c5_i71 = 0; c5_i71 < 6; c5_i71++) {
      c5_b_inData[c5_i71 + c5_i69] = (*(real_T (*)[174])c5_inData)[c5_i71 +
        c5_i69];
    }

    c5_i69 += 6;
  }

  c5_i72 = 0;
  for (c5_i73 = 0; c5_i73 < 29; c5_i73++) {
    for (c5_i74 = 0; c5_i74 < 6; c5_i74++) {
      c5_u[c5_i74 + c5_i72] = c5_b_inData[c5_i74 + c5_i72];
    }

    c5_i72 += 6;
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 2, 6, 29), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static const mxArray *c5_f_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  real_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_torqueBalancing2012bInstanceStruct *chartInstance;
  chartInstance = (SFc5_torqueBalancing2012bInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(real_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static void c5_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_nargout;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y;
  SFc5_torqueBalancing2012bInstanceStruct *chartInstance;
  chartInstance = (SFc5_torqueBalancing2012bInstanceStruct *)chartInstanceVoid;
  c5_nargout = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_nargout), &c5_thisId);
  sf_mex_destroy(&c5_nargout);
  *(real_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_g_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i75;
  int32_T c5_i76;
  int32_T c5_i77;
  real_T c5_b_inData[72];
  int32_T c5_i78;
  int32_T c5_i79;
  int32_T c5_i80;
  real_T c5_u[72];
  const mxArray *c5_y = NULL;
  SFc5_torqueBalancing2012bInstanceStruct *chartInstance;
  chartInstance = (SFc5_torqueBalancing2012bInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_i75 = 0;
  for (c5_i76 = 0; c5_i76 < 12; c5_i76++) {
    for (c5_i77 = 0; c5_i77 < 6; c5_i77++) {
      c5_b_inData[c5_i77 + c5_i75] = (*(real_T (*)[72])c5_inData)[c5_i77 +
        c5_i75];
    }

    c5_i75 += 6;
  }

  c5_i78 = 0;
  for (c5_i79 = 0; c5_i79 < 12; c5_i79++) {
    for (c5_i80 = 0; c5_i80 < 6; c5_i80++) {
      c5_u[c5_i80 + c5_i78] = c5_b_inData[c5_i80 + c5_i78];
    }

    c5_i78 += 6;
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 2, 6, 12), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static void c5_e_emlrt_marshallIn(SFc5_torqueBalancing2012bInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_y[72])
{
  real_T c5_dv3[72];
  int32_T c5_i81;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), c5_dv3, 1, 0, 0U, 1, 0U, 2, 6, 12);
  for (c5_i81 = 0; c5_i81 < 72; c5_i81++) {
    c5_y[c5_i81] = c5_dv3[c5_i81];
  }

  sf_mex_destroy(&c5_u);
}

static void c5_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_pinvJb;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y[72];
  int32_T c5_i82;
  int32_T c5_i83;
  int32_T c5_i84;
  SFc5_torqueBalancing2012bInstanceStruct *chartInstance;
  chartInstance = (SFc5_torqueBalancing2012bInstanceStruct *)chartInstanceVoid;
  c5_pinvJb = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_pinvJb), &c5_thisId, c5_y);
  sf_mex_destroy(&c5_pinvJb);
  c5_i82 = 0;
  for (c5_i83 = 0; c5_i83 < 12; c5_i83++) {
    for (c5_i84 = 0; c5_i84 < 6; c5_i84++) {
      (*(real_T (*)[72])c5_outData)[c5_i84 + c5_i82] = c5_y[c5_i84 + c5_i82];
    }

    c5_i82 += 6;
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_h_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i85;
  int32_T c5_i86;
  int32_T c5_i87;
  real_T c5_b_inData[348];
  int32_T c5_i88;
  int32_T c5_i89;
  int32_T c5_i90;
  real_T c5_u[348];
  const mxArray *c5_y = NULL;
  SFc5_torqueBalancing2012bInstanceStruct *chartInstance;
  chartInstance = (SFc5_torqueBalancing2012bInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_i85 = 0;
  for (c5_i86 = 0; c5_i86 < 29; c5_i86++) {
    for (c5_i87 = 0; c5_i87 < 12; c5_i87++) {
      c5_b_inData[c5_i87 + c5_i85] = (*(real_T (*)[348])c5_inData)[c5_i87 +
        c5_i85];
    }

    c5_i85 += 12;
  }

  c5_i88 = 0;
  for (c5_i89 = 0; c5_i89 < 29; c5_i89++) {
    for (c5_i90 = 0; c5_i90 < 12; c5_i90++) {
      c5_u[c5_i90 + c5_i88] = c5_b_inData[c5_i90 + c5_i88];
    }

    c5_i88 += 12;
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 2, 12, 29), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static void c5_f_emlrt_marshallIn(SFc5_torqueBalancing2012bInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_y[348])
{
  real_T c5_dv4[348];
  int32_T c5_i91;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), c5_dv4, 1, 0, 0U, 1, 0U, 2, 12,
                29);
  for (c5_i91 = 0; c5_i91 < 348; c5_i91++) {
    c5_y[c5_i91] = c5_dv4[c5_i91];
  }

  sf_mex_destroy(&c5_u);
}

static void c5_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_Jc;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y[348];
  int32_T c5_i92;
  int32_T c5_i93;
  int32_T c5_i94;
  SFc5_torqueBalancing2012bInstanceStruct *chartInstance;
  chartInstance = (SFc5_torqueBalancing2012bInstanceStruct *)chartInstanceVoid;
  c5_Jc = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_Jc), &c5_thisId, c5_y);
  sf_mex_destroy(&c5_Jc);
  c5_i92 = 0;
  for (c5_i93 = 0; c5_i93 < 29; c5_i93++) {
    for (c5_i94 = 0; c5_i94 < 12; c5_i94++) {
      (*(real_T (*)[348])c5_outData)[c5_i94 + c5_i92] = c5_y[c5_i94 + c5_i92];
    }

    c5_i92 += 12;
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

const mxArray *sf_c5_torqueBalancing2012b_get_eml_resolved_functions_info(void)
{
  const mxArray *c5_nameCaptureInfo;
  c5_ResolvedFunctionInfo c5_info[125];
  const mxArray *c5_m1 = NULL;
  int32_T c5_i95;
  c5_ResolvedFunctionInfo *c5_r1;
  c5_nameCaptureInfo = NULL;
  c5_nameCaptureInfo = NULL;
  c5_info_helper(c5_info);
  c5_b_info_helper(c5_info);
  sf_mex_assign(&c5_m1, sf_mex_createstruct("nameCaptureInfo", 1, 125), FALSE);
  for (c5_i95 = 0; c5_i95 < 125; c5_i95++) {
    c5_r1 = &c5_info[c5_i95];
    sf_mex_addfield(c5_m1, sf_mex_create("nameCaptureInfo", c5_r1->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c5_r1->context)), "context", "nameCaptureInfo",
                    c5_i95);
    sf_mex_addfield(c5_m1, sf_mex_create("nameCaptureInfo", c5_r1->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c5_r1->name)), "name", "nameCaptureInfo", c5_i95);
    sf_mex_addfield(c5_m1, sf_mex_create("nameCaptureInfo", c5_r1->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c5_r1->dominantType)), "dominantType",
                    "nameCaptureInfo", c5_i95);
    sf_mex_addfield(c5_m1, sf_mex_create("nameCaptureInfo", c5_r1->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c5_r1->resolved)), "resolved", "nameCaptureInfo",
                    c5_i95);
    sf_mex_addfield(c5_m1, sf_mex_create("nameCaptureInfo", &c5_r1->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c5_i95);
    sf_mex_addfield(c5_m1, sf_mex_create("nameCaptureInfo", &c5_r1->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c5_i95);
    sf_mex_addfield(c5_m1, sf_mex_create("nameCaptureInfo", &c5_r1->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c5_i95);
    sf_mex_addfield(c5_m1, sf_mex_create("nameCaptureInfo", &c5_r1->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c5_i95);
  }

  sf_mex_assign(&c5_nameCaptureInfo, c5_m1, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c5_nameCaptureInfo);
  return c5_nameCaptureInfo;
}

static void c5_info_helper(c5_ResolvedFunctionInfo c5_info[125])
{
  c5_info[0].context = "";
  c5_info[0].name = "mtimes";
  c5_info[0].dominantType = "double";
  c5_info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[0].fileTimeLo = 1289519692U;
  c5_info[0].fileTimeHi = 0U;
  c5_info[0].mFileTimeLo = 0U;
  c5_info[0].mFileTimeHi = 0U;
  c5_info[1].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[1].name = "eml_index_class";
  c5_info[1].dominantType = "";
  c5_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c5_info[1].fileTimeLo = 1323170578U;
  c5_info[1].fileTimeHi = 0U;
  c5_info[1].mFileTimeLo = 0U;
  c5_info[1].mFileTimeHi = 0U;
  c5_info[2].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[2].name = "eml_scalar_eg";
  c5_info[2].dominantType = "double";
  c5_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c5_info[2].fileTimeLo = 1286818796U;
  c5_info[2].fileTimeHi = 0U;
  c5_info[2].mFileTimeLo = 0U;
  c5_info[2].mFileTimeHi = 0U;
  c5_info[3].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[3].name = "eml_xgemm";
  c5_info[3].dominantType = "char";
  c5_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c5_info[3].fileTimeLo = 1299076772U;
  c5_info[3].fileTimeHi = 0U;
  c5_info[3].mFileTimeLo = 0U;
  c5_info[3].mFileTimeHi = 0U;
  c5_info[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c5_info[4].name = "eml_blas_inline";
  c5_info[4].dominantType = "";
  c5_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c5_info[4].fileTimeLo = 1299076768U;
  c5_info[4].fileTimeHi = 0U;
  c5_info[4].mFileTimeLo = 0U;
  c5_info[4].mFileTimeHi = 0U;
  c5_info[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  c5_info[5].name = "mtimes";
  c5_info[5].dominantType = "double";
  c5_info[5].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[5].fileTimeLo = 1289519692U;
  c5_info[5].fileTimeHi = 0U;
  c5_info[5].mFileTimeLo = 0U;
  c5_info[5].mFileTimeHi = 0U;
  c5_info[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c5_info[6].name = "eml_index_class";
  c5_info[6].dominantType = "";
  c5_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c5_info[6].fileTimeLo = 1323170578U;
  c5_info[6].fileTimeHi = 0U;
  c5_info[6].mFileTimeLo = 0U;
  c5_info[6].mFileTimeHi = 0U;
  c5_info[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c5_info[7].name = "eml_scalar_eg";
  c5_info[7].dominantType = "double";
  c5_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c5_info[7].fileTimeLo = 1286818796U;
  c5_info[7].fileTimeHi = 0U;
  c5_info[7].mFileTimeLo = 0U;
  c5_info[7].mFileTimeHi = 0U;
  c5_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c5_info[8].name = "eml_refblas_xgemm";
  c5_info[8].dominantType = "char";
  c5_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c5_info[8].fileTimeLo = 1299076774U;
  c5_info[8].fileTimeHi = 0U;
  c5_info[8].mFileTimeLo = 0U;
  c5_info[8].mFileTimeHi = 0U;
  c5_info[9].context = "";
  c5_info[9].name = "eye";
  c5_info[9].dominantType = "double";
  c5_info[9].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m";
  c5_info[9].fileTimeLo = 1286818688U;
  c5_info[9].fileTimeHi = 0U;
  c5_info[9].mFileTimeLo = 0U;
  c5_info[9].mFileTimeHi = 0U;
  c5_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c5_info[10].name = "eml_assert_valid_size_arg";
  c5_info[10].dominantType = "double";
  c5_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c5_info[10].fileTimeLo = 1286818694U;
  c5_info[10].fileTimeHi = 0U;
  c5_info[10].mFileTimeLo = 0U;
  c5_info[10].mFileTimeHi = 0U;
  c5_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isintegral";
  c5_info[11].name = "isinf";
  c5_info[11].dominantType = "double";
  c5_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  c5_info[11].fileTimeLo = 1286818760U;
  c5_info[11].fileTimeHi = 0U;
  c5_info[11].mFileTimeLo = 0U;
  c5_info[11].mFileTimeHi = 0U;
  c5_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!numel_for_size";
  c5_info[12].name = "mtimes";
  c5_info[12].dominantType = "double";
  c5_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[12].fileTimeLo = 1289519692U;
  c5_info[12].fileTimeHi = 0U;
  c5_info[12].mFileTimeLo = 0U;
  c5_info[12].mFileTimeHi = 0U;
  c5_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c5_info[13].name = "eml_index_class";
  c5_info[13].dominantType = "";
  c5_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c5_info[13].fileTimeLo = 1323170578U;
  c5_info[13].fileTimeHi = 0U;
  c5_info[13].mFileTimeLo = 0U;
  c5_info[13].mFileTimeHi = 0U;
  c5_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c5_info[14].name = "intmax";
  c5_info[14].dominantType = "char";
  c5_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c5_info[14].fileTimeLo = 1311255316U;
  c5_info[14].fileTimeHi = 0U;
  c5_info[14].mFileTimeLo = 0U;
  c5_info[14].mFileTimeHi = 0U;
  c5_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c5_info[15].name = "eml_is_float_class";
  c5_info[15].dominantType = "char";
  c5_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c5_info[15].fileTimeLo = 1286818782U;
  c5_info[15].fileTimeHi = 0U;
  c5_info[15].mFileTimeLo = 0U;
  c5_info[15].mFileTimeHi = 0U;
  c5_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c5_info[16].name = "min";
  c5_info[16].dominantType = "double";
  c5_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c5_info[16].fileTimeLo = 1311255318U;
  c5_info[16].fileTimeHi = 0U;
  c5_info[16].mFileTimeLo = 0U;
  c5_info[16].mFileTimeHi = 0U;
  c5_info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c5_info[17].name = "eml_min_or_max";
  c5_info[17].dominantType = "char";
  c5_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c5_info[17].fileTimeLo = 1334071490U;
  c5_info[17].fileTimeHi = 0U;
  c5_info[17].mFileTimeLo = 0U;
  c5_info[17].mFileTimeHi = 0U;
  c5_info[18].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c5_info[18].name = "eml_scalar_eg";
  c5_info[18].dominantType = "double";
  c5_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c5_info[18].fileTimeLo = 1286818796U;
  c5_info[18].fileTimeHi = 0U;
  c5_info[18].mFileTimeLo = 0U;
  c5_info[18].mFileTimeHi = 0U;
  c5_info[19].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c5_info[19].name = "eml_scalexp_alloc";
  c5_info[19].dominantType = "double";
  c5_info[19].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c5_info[19].fileTimeLo = 1352424860U;
  c5_info[19].fileTimeHi = 0U;
  c5_info[19].mFileTimeLo = 0U;
  c5_info[19].mFileTimeHi = 0U;
  c5_info[20].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c5_info[20].name = "eml_index_class";
  c5_info[20].dominantType = "";
  c5_info[20].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c5_info[20].fileTimeLo = 1323170578U;
  c5_info[20].fileTimeHi = 0U;
  c5_info[20].mFileTimeLo = 0U;
  c5_info[20].mFileTimeHi = 0U;
  c5_info[21].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum";
  c5_info[21].name = "eml_scalar_eg";
  c5_info[21].dominantType = "double";
  c5_info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c5_info[21].fileTimeLo = 1286818796U;
  c5_info[21].fileTimeHi = 0U;
  c5_info[21].mFileTimeLo = 0U;
  c5_info[21].mFileTimeHi = 0U;
  c5_info[22].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c5_info[22].name = "eml_index_class";
  c5_info[22].dominantType = "";
  c5_info[22].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c5_info[22].fileTimeLo = 1323170578U;
  c5_info[22].fileTimeHi = 0U;
  c5_info[22].mFileTimeLo = 0U;
  c5_info[22].mFileTimeHi = 0U;
  c5_info[23].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c5_info[23].name = "eml_int_forloop_overflow_check";
  c5_info[23].dominantType = "";
  c5_info[23].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c5_info[23].fileTimeLo = 1346510340U;
  c5_info[23].fileTimeHi = 0U;
  c5_info[23].mFileTimeLo = 0U;
  c5_info[23].mFileTimeHi = 0U;
  c5_info[24].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  c5_info[24].name = "intmax";
  c5_info[24].dominantType = "char";
  c5_info[24].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c5_info[24].fileTimeLo = 1311255316U;
  c5_info[24].fileTimeHi = 0U;
  c5_info[24].mFileTimeLo = 0U;
  c5_info[24].mFileTimeHi = 0U;
  c5_info[25].context = "";
  c5_info[25].name = "mldivide";
  c5_info[25].dominantType = "double";
  c5_info[25].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.p";
  c5_info[25].fileTimeLo = 1357951548U;
  c5_info[25].fileTimeHi = 0U;
  c5_info[25].mFileTimeLo = 1319729966U;
  c5_info[25].mFileTimeHi = 0U;
  c5_info[26].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.p";
  c5_info[26].name = "eml_lusolve";
  c5_info[26].dominantType = "double";
  c5_info[26].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m";
  c5_info[26].fileTimeLo = 1309451196U;
  c5_info[26].fileTimeHi = 0U;
  c5_info[26].mFileTimeLo = 0U;
  c5_info[26].mFileTimeHi = 0U;
  c5_info[27].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m";
  c5_info[27].name = "eml_index_class";
  c5_info[27].dominantType = "";
  c5_info[27].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c5_info[27].fileTimeLo = 1323170578U;
  c5_info[27].fileTimeHi = 0U;
  c5_info[27].mFileTimeLo = 0U;
  c5_info[27].mFileTimeHi = 0U;
  c5_info[28].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolveNxN";
  c5_info[28].name = "eml_index_class";
  c5_info[28].dominantType = "";
  c5_info[28].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c5_info[28].fileTimeLo = 1323170578U;
  c5_info[28].fileTimeHi = 0U;
  c5_info[28].mFileTimeLo = 0U;
  c5_info[28].mFileTimeHi = 0U;
  c5_info[29].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolveNxN";
  c5_info[29].name = "eml_xgetrf";
  c5_info[29].dominantType = "double";
  c5_info[29].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgetrf.m";
  c5_info[29].fileTimeLo = 1286818806U;
  c5_info[29].fileTimeHi = 0U;
  c5_info[29].mFileTimeLo = 0U;
  c5_info[29].mFileTimeHi = 0U;
  c5_info[30].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgetrf.m";
  c5_info[30].name = "eml_lapack_xgetrf";
  c5_info[30].dominantType = "double";
  c5_info[30].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgetrf.m";
  c5_info[30].fileTimeLo = 1286818810U;
  c5_info[30].fileTimeHi = 0U;
  c5_info[30].mFileTimeLo = 0U;
  c5_info[30].mFileTimeHi = 0U;
  c5_info[31].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgetrf.m";
  c5_info[31].name = "eml_matlab_zgetrf";
  c5_info[31].dominantType = "double";
  c5_info[31].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c5_info[31].fileTimeLo = 1302688994U;
  c5_info[31].fileTimeHi = 0U;
  c5_info[31].mFileTimeLo = 0U;
  c5_info[31].mFileTimeHi = 0U;
  c5_info[32].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c5_info[32].name = "realmin";
  c5_info[32].dominantType = "char";
  c5_info[32].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c5_info[32].fileTimeLo = 1307651242U;
  c5_info[32].fileTimeHi = 0U;
  c5_info[32].mFileTimeLo = 0U;
  c5_info[32].mFileTimeHi = 0U;
  c5_info[33].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c5_info[33].name = "eml_realmin";
  c5_info[33].dominantType = "char";
  c5_info[33].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m";
  c5_info[33].fileTimeLo = 1307651244U;
  c5_info[33].fileTimeHi = 0U;
  c5_info[33].mFileTimeLo = 0U;
  c5_info[33].mFileTimeHi = 0U;
  c5_info[34].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m";
  c5_info[34].name = "eml_float_model";
  c5_info[34].dominantType = "char";
  c5_info[34].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c5_info[34].fileTimeLo = 1326727996U;
  c5_info[34].fileTimeHi = 0U;
  c5_info[34].mFileTimeLo = 0U;
  c5_info[34].mFileTimeHi = 0U;
  c5_info[35].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c5_info[35].name = "eps";
  c5_info[35].dominantType = "char";
  c5_info[35].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c5_info[35].fileTimeLo = 1326727996U;
  c5_info[35].fileTimeHi = 0U;
  c5_info[35].mFileTimeLo = 0U;
  c5_info[35].mFileTimeHi = 0U;
  c5_info[36].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c5_info[36].name = "eml_is_float_class";
  c5_info[36].dominantType = "char";
  c5_info[36].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c5_info[36].fileTimeLo = 1286818782U;
  c5_info[36].fileTimeHi = 0U;
  c5_info[36].mFileTimeLo = 0U;
  c5_info[36].mFileTimeHi = 0U;
  c5_info[37].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c5_info[37].name = "eml_eps";
  c5_info[37].dominantType = "char";
  c5_info[37].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c5_info[37].fileTimeLo = 1326727996U;
  c5_info[37].fileTimeHi = 0U;
  c5_info[37].mFileTimeLo = 0U;
  c5_info[37].mFileTimeHi = 0U;
  c5_info[38].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c5_info[38].name = "eml_float_model";
  c5_info[38].dominantType = "char";
  c5_info[38].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c5_info[38].fileTimeLo = 1326727996U;
  c5_info[38].fileTimeHi = 0U;
  c5_info[38].mFileTimeLo = 0U;
  c5_info[38].mFileTimeHi = 0U;
  c5_info[39].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c5_info[39].name = "min";
  c5_info[39].dominantType = "coder.internal.indexInt";
  c5_info[39].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c5_info[39].fileTimeLo = 1311255318U;
  c5_info[39].fileTimeHi = 0U;
  c5_info[39].mFileTimeLo = 0U;
  c5_info[39].mFileTimeHi = 0U;
  c5_info[40].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c5_info[40].name = "eml_scalar_eg";
  c5_info[40].dominantType = "coder.internal.indexInt";
  c5_info[40].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c5_info[40].fileTimeLo = 1286818796U;
  c5_info[40].fileTimeHi = 0U;
  c5_info[40].mFileTimeLo = 0U;
  c5_info[40].mFileTimeHi = 0U;
  c5_info[41].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c5_info[41].name = "eml_scalexp_alloc";
  c5_info[41].dominantType = "coder.internal.indexInt";
  c5_info[41].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c5_info[41].fileTimeLo = 1352424860U;
  c5_info[41].fileTimeHi = 0U;
  c5_info[41].mFileTimeLo = 0U;
  c5_info[41].mFileTimeHi = 0U;
  c5_info[42].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum";
  c5_info[42].name = "eml_scalar_eg";
  c5_info[42].dominantType = "coder.internal.indexInt";
  c5_info[42].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c5_info[42].fileTimeLo = 1286818796U;
  c5_info[42].fileTimeHi = 0U;
  c5_info[42].mFileTimeLo = 0U;
  c5_info[42].mFileTimeHi = 0U;
  c5_info[43].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c5_info[43].name = "colon";
  c5_info[43].dominantType = "double";
  c5_info[43].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c5_info[43].fileTimeLo = 1348191928U;
  c5_info[43].fileTimeHi = 0U;
  c5_info[43].mFileTimeLo = 0U;
  c5_info[43].mFileTimeHi = 0U;
  c5_info[44].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c5_info[44].name = "colon";
  c5_info[44].dominantType = "double";
  c5_info[44].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c5_info[44].fileTimeLo = 1348191928U;
  c5_info[44].fileTimeHi = 0U;
  c5_info[44].mFileTimeLo = 0U;
  c5_info[44].mFileTimeHi = 0U;
  c5_info[45].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c5_info[45].name = "floor";
  c5_info[45].dominantType = "double";
  c5_info[45].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c5_info[45].fileTimeLo = 1343830380U;
  c5_info[45].fileTimeHi = 0U;
  c5_info[45].mFileTimeLo = 0U;
  c5_info[45].mFileTimeHi = 0U;
  c5_info[46].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c5_info[46].name = "eml_scalar_floor";
  c5_info[46].dominantType = "double";
  c5_info[46].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c5_info[46].fileTimeLo = 1286818726U;
  c5_info[46].fileTimeHi = 0U;
  c5_info[46].mFileTimeLo = 0U;
  c5_info[46].mFileTimeHi = 0U;
  c5_info[47].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange";
  c5_info[47].name = "intmin";
  c5_info[47].dominantType = "char";
  c5_info[47].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c5_info[47].fileTimeLo = 1311255318U;
  c5_info[47].fileTimeHi = 0U;
  c5_info[47].mFileTimeLo = 0U;
  c5_info[47].mFileTimeHi = 0U;
  c5_info[48].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange";
  c5_info[48].name = "intmax";
  c5_info[48].dominantType = "char";
  c5_info[48].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c5_info[48].fileTimeLo = 1311255316U;
  c5_info[48].fileTimeHi = 0U;
  c5_info[48].mFileTimeLo = 0U;
  c5_info[48].mFileTimeHi = 0U;
  c5_info[49].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher";
  c5_info[49].name = "intmin";
  c5_info[49].dominantType = "char";
  c5_info[49].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c5_info[49].fileTimeLo = 1311255318U;
  c5_info[49].fileTimeHi = 0U;
  c5_info[49].mFileTimeLo = 0U;
  c5_info[49].mFileTimeHi = 0U;
  c5_info[50].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher";
  c5_info[50].name = "intmax";
  c5_info[50].dominantType = "char";
  c5_info[50].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c5_info[50].fileTimeLo = 1311255316U;
  c5_info[50].fileTimeHi = 0U;
  c5_info[50].mFileTimeLo = 0U;
  c5_info[50].mFileTimeHi = 0U;
  c5_info[51].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher";
  c5_info[51].name = "eml_isa_uint";
  c5_info[51].dominantType = "coder.internal.indexInt";
  c5_info[51].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m";
  c5_info[51].fileTimeLo = 1286818784U;
  c5_info[51].fileTimeHi = 0U;
  c5_info[51].mFileTimeLo = 0U;
  c5_info[51].mFileTimeHi = 0U;
  c5_info[52].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c5_info[52].name = "eml_unsigned_class";
  c5_info[52].dominantType = "char";
  c5_info[52].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m";
  c5_info[52].fileTimeLo = 1323170580U;
  c5_info[52].fileTimeHi = 0U;
  c5_info[52].mFileTimeLo = 0U;
  c5_info[52].mFileTimeHi = 0U;
  c5_info[53].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m";
  c5_info[53].name = "eml_index_class";
  c5_info[53].dominantType = "";
  c5_info[53].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c5_info[53].fileTimeLo = 1323170578U;
  c5_info[53].fileTimeHi = 0U;
  c5_info[53].mFileTimeLo = 0U;
  c5_info[53].mFileTimeHi = 0U;
  c5_info[54].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c5_info[54].name = "eml_index_class";
  c5_info[54].dominantType = "";
  c5_info[54].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c5_info[54].fileTimeLo = 1323170578U;
  c5_info[54].fileTimeHi = 0U;
  c5_info[54].mFileTimeLo = 0U;
  c5_info[54].mFileTimeHi = 0U;
  c5_info[55].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c5_info[55].name = "intmax";
  c5_info[55].dominantType = "char";
  c5_info[55].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c5_info[55].fileTimeLo = 1311255316U;
  c5_info[55].fileTimeHi = 0U;
  c5_info[55].mFileTimeLo = 0U;
  c5_info[55].mFileTimeHi = 0U;
  c5_info[56].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c5_info[56].name = "eml_isa_uint";
  c5_info[56].dominantType = "coder.internal.indexInt";
  c5_info[56].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m";
  c5_info[56].fileTimeLo = 1286818784U;
  c5_info[56].fileTimeHi = 0U;
  c5_info[56].mFileTimeLo = 0U;
  c5_info[56].mFileTimeHi = 0U;
  c5_info[57].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c5_info[57].name = "eml_index_plus";
  c5_info[57].dominantType = "double";
  c5_info[57].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c5_info[57].fileTimeLo = 1286818778U;
  c5_info[57].fileTimeHi = 0U;
  c5_info[57].mFileTimeLo = 0U;
  c5_info[57].mFileTimeHi = 0U;
  c5_info[58].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c5_info[58].name = "eml_index_class";
  c5_info[58].dominantType = "";
  c5_info[58].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c5_info[58].fileTimeLo = 1323170578U;
  c5_info[58].fileTimeHi = 0U;
  c5_info[58].mFileTimeLo = 0U;
  c5_info[58].mFileTimeHi = 0U;
  c5_info[59].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_signed_integer_colon";
  c5_info[59].name = "eml_int_forloop_overflow_check";
  c5_info[59].dominantType = "";
  c5_info[59].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c5_info[59].fileTimeLo = 1346510340U;
  c5_info[59].fileTimeHi = 0U;
  c5_info[59].mFileTimeLo = 0U;
  c5_info[59].mFileTimeHi = 0U;
  c5_info[60].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c5_info[60].name = "eml_index_class";
  c5_info[60].dominantType = "";
  c5_info[60].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c5_info[60].fileTimeLo = 1323170578U;
  c5_info[60].fileTimeHi = 0U;
  c5_info[60].mFileTimeLo = 0U;
  c5_info[60].mFileTimeHi = 0U;
  c5_info[61].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c5_info[61].name = "eml_index_plus";
  c5_info[61].dominantType = "double";
  c5_info[61].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c5_info[61].fileTimeLo = 1286818778U;
  c5_info[61].fileTimeHi = 0U;
  c5_info[61].mFileTimeLo = 0U;
  c5_info[61].mFileTimeHi = 0U;
  c5_info[62].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c5_info[62].name = "eml_int_forloop_overflow_check";
  c5_info[62].dominantType = "";
  c5_info[62].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c5_info[62].fileTimeLo = 1346510340U;
  c5_info[62].fileTimeHi = 0U;
  c5_info[62].mFileTimeLo = 0U;
  c5_info[62].mFileTimeHi = 0U;
  c5_info[63].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c5_info[63].name = "eml_index_minus";
  c5_info[63].dominantType = "double";
  c5_info[63].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c5_info[63].fileTimeLo = 1286818778U;
  c5_info[63].fileTimeHi = 0U;
  c5_info[63].mFileTimeLo = 0U;
  c5_info[63].mFileTimeHi = 0U;
}

static void c5_b_info_helper(c5_ResolvedFunctionInfo c5_info[125])
{
  c5_info[64].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c5_info[64].name = "eml_index_class";
  c5_info[64].dominantType = "";
  c5_info[64].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c5_info[64].fileTimeLo = 1323170578U;
  c5_info[64].fileTimeHi = 0U;
  c5_info[64].mFileTimeLo = 0U;
  c5_info[64].mFileTimeHi = 0U;
  c5_info[65].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c5_info[65].name = "eml_index_minus";
  c5_info[65].dominantType = "coder.internal.indexInt";
  c5_info[65].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c5_info[65].fileTimeLo = 1286818778U;
  c5_info[65].fileTimeHi = 0U;
  c5_info[65].mFileTimeLo = 0U;
  c5_info[65].mFileTimeHi = 0U;
  c5_info[66].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c5_info[66].name = "eml_index_times";
  c5_info[66].dominantType = "coder.internal.indexInt";
  c5_info[66].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c5_info[66].fileTimeLo = 1286818780U;
  c5_info[66].fileTimeHi = 0U;
  c5_info[66].mFileTimeLo = 0U;
  c5_info[66].mFileTimeHi = 0U;
  c5_info[67].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c5_info[67].name = "eml_index_class";
  c5_info[67].dominantType = "";
  c5_info[67].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c5_info[67].fileTimeLo = 1323170578U;
  c5_info[67].fileTimeHi = 0U;
  c5_info[67].mFileTimeLo = 0U;
  c5_info[67].mFileTimeHi = 0U;
  c5_info[68].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c5_info[68].name = "eml_index_plus";
  c5_info[68].dominantType = "coder.internal.indexInt";
  c5_info[68].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c5_info[68].fileTimeLo = 1286818778U;
  c5_info[68].fileTimeHi = 0U;
  c5_info[68].mFileTimeLo = 0U;
  c5_info[68].mFileTimeHi = 0U;
  c5_info[69].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c5_info[69].name = "eml_ixamax";
  c5_info[69].dominantType = "double";
  c5_info[69].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_ixamax.m";
  c5_info[69].fileTimeLo = 1299076770U;
  c5_info[69].fileTimeHi = 0U;
  c5_info[69].mFileTimeLo = 0U;
  c5_info[69].mFileTimeHi = 0U;
  c5_info[70].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_ixamax.m";
  c5_info[70].name = "eml_blas_inline";
  c5_info[70].dominantType = "";
  c5_info[70].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c5_info[70].fileTimeLo = 1299076768U;
  c5_info[70].fileTimeHi = 0U;
  c5_info[70].mFileTimeLo = 0U;
  c5_info[70].mFileTimeHi = 0U;
  c5_info[71].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_ixamax.m!below_threshold";
  c5_info[71].name = "length";
  c5_info[71].dominantType = "double";
  c5_info[71].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c5_info[71].fileTimeLo = 1303146206U;
  c5_info[71].fileTimeHi = 0U;
  c5_info[71].mFileTimeLo = 0U;
  c5_info[71].mFileTimeHi = 0U;
  c5_info[72].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m!intlength";
  c5_info[72].name = "eml_index_class";
  c5_info[72].dominantType = "";
  c5_info[72].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c5_info[72].fileTimeLo = 1323170578U;
  c5_info[72].fileTimeHi = 0U;
  c5_info[72].mFileTimeLo = 0U;
  c5_info[72].mFileTimeHi = 0U;
  c5_info[73].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_ixamax.m";
  c5_info[73].name = "eml_index_class";
  c5_info[73].dominantType = "";
  c5_info[73].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c5_info[73].fileTimeLo = 1323170578U;
  c5_info[73].fileTimeHi = 0U;
  c5_info[73].mFileTimeLo = 0U;
  c5_info[73].mFileTimeHi = 0U;
  c5_info[74].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_ixamax.m";
  c5_info[74].name = "eml_refblas_ixamax";
  c5_info[74].dominantType = "double";
  c5_info[74].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c5_info[74].fileTimeLo = 1299076770U;
  c5_info[74].fileTimeHi = 0U;
  c5_info[74].mFileTimeLo = 0U;
  c5_info[74].mFileTimeHi = 0U;
  c5_info[75].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c5_info[75].name = "eml_index_class";
  c5_info[75].dominantType = "";
  c5_info[75].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c5_info[75].fileTimeLo = 1323170578U;
  c5_info[75].fileTimeHi = 0U;
  c5_info[75].mFileTimeLo = 0U;
  c5_info[75].mFileTimeHi = 0U;
  c5_info[76].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c5_info[76].name = "eml_xcabs1";
  c5_info[76].dominantType = "double";
  c5_info[76].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c5_info[76].fileTimeLo = 1286818706U;
  c5_info[76].fileTimeHi = 0U;
  c5_info[76].mFileTimeLo = 0U;
  c5_info[76].mFileTimeHi = 0U;
  c5_info[77].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c5_info[77].name = "abs";
  c5_info[77].dominantType = "double";
  c5_info[77].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c5_info[77].fileTimeLo = 1343830366U;
  c5_info[77].fileTimeHi = 0U;
  c5_info[77].mFileTimeLo = 0U;
  c5_info[77].mFileTimeHi = 0U;
  c5_info[78].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c5_info[78].name = "eml_scalar_abs";
  c5_info[78].dominantType = "double";
  c5_info[78].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c5_info[78].fileTimeLo = 1286818712U;
  c5_info[78].fileTimeHi = 0U;
  c5_info[78].mFileTimeLo = 0U;
  c5_info[78].mFileTimeHi = 0U;
  c5_info[79].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c5_info[79].name = "eml_int_forloop_overflow_check";
  c5_info[79].dominantType = "";
  c5_info[79].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c5_info[79].fileTimeLo = 1346510340U;
  c5_info[79].fileTimeHi = 0U;
  c5_info[79].mFileTimeLo = 0U;
  c5_info[79].mFileTimeHi = 0U;
  c5_info[80].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c5_info[80].name = "eml_index_plus";
  c5_info[80].dominantType = "coder.internal.indexInt";
  c5_info[80].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c5_info[80].fileTimeLo = 1286818778U;
  c5_info[80].fileTimeHi = 0U;
  c5_info[80].mFileTimeLo = 0U;
  c5_info[80].mFileTimeHi = 0U;
  c5_info[81].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c5_info[81].name = "eml_xswap";
  c5_info[81].dominantType = "double";
  c5_info[81].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m";
  c5_info[81].fileTimeLo = 1299076778U;
  c5_info[81].fileTimeHi = 0U;
  c5_info[81].mFileTimeLo = 0U;
  c5_info[81].mFileTimeHi = 0U;
  c5_info[82].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m";
  c5_info[82].name = "eml_blas_inline";
  c5_info[82].dominantType = "";
  c5_info[82].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c5_info[82].fileTimeLo = 1299076768U;
  c5_info[82].fileTimeHi = 0U;
  c5_info[82].mFileTimeLo = 0U;
  c5_info[82].mFileTimeHi = 0U;
  c5_info[83].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xswap.m";
  c5_info[83].name = "eml_index_class";
  c5_info[83].dominantType = "";
  c5_info[83].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c5_info[83].fileTimeLo = 1323170578U;
  c5_info[83].fileTimeHi = 0U;
  c5_info[83].mFileTimeLo = 0U;
  c5_info[83].mFileTimeHi = 0U;
  c5_info[84].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xswap.m";
  c5_info[84].name = "eml_refblas_xswap";
  c5_info[84].dominantType = "double";
  c5_info[84].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c5_info[84].fileTimeLo = 1299076786U;
  c5_info[84].fileTimeHi = 0U;
  c5_info[84].mFileTimeLo = 0U;
  c5_info[84].mFileTimeHi = 0U;
  c5_info[85].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c5_info[85].name = "eml_index_class";
  c5_info[85].dominantType = "";
  c5_info[85].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c5_info[85].fileTimeLo = 1323170578U;
  c5_info[85].fileTimeHi = 0U;
  c5_info[85].mFileTimeLo = 0U;
  c5_info[85].mFileTimeHi = 0U;
  c5_info[86].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c5_info[86].name = "abs";
  c5_info[86].dominantType = "coder.internal.indexInt";
  c5_info[86].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c5_info[86].fileTimeLo = 1343830366U;
  c5_info[86].fileTimeHi = 0U;
  c5_info[86].mFileTimeLo = 0U;
  c5_info[86].mFileTimeHi = 0U;
  c5_info[87].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c5_info[87].name = "eml_scalar_abs";
  c5_info[87].dominantType = "coder.internal.indexInt";
  c5_info[87].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c5_info[87].fileTimeLo = 1286818712U;
  c5_info[87].fileTimeHi = 0U;
  c5_info[87].mFileTimeLo = 0U;
  c5_info[87].mFileTimeHi = 0U;
  c5_info[88].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c5_info[88].name = "eml_int_forloop_overflow_check";
  c5_info[88].dominantType = "";
  c5_info[88].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c5_info[88].fileTimeLo = 1346510340U;
  c5_info[88].fileTimeHi = 0U;
  c5_info[88].mFileTimeLo = 0U;
  c5_info[88].mFileTimeHi = 0U;
  c5_info[89].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c5_info[89].name = "eml_index_plus";
  c5_info[89].dominantType = "coder.internal.indexInt";
  c5_info[89].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c5_info[89].fileTimeLo = 1286818778U;
  c5_info[89].fileTimeHi = 0U;
  c5_info[89].mFileTimeLo = 0U;
  c5_info[89].mFileTimeHi = 0U;
  c5_info[90].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c5_info[90].name = "eml_div";
  c5_info[90].dominantType = "double";
  c5_info[90].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c5_info[90].fileTimeLo = 1313347810U;
  c5_info[90].fileTimeHi = 0U;
  c5_info[90].mFileTimeLo = 0U;
  c5_info[90].mFileTimeHi = 0U;
  c5_info[91].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c5_info[91].name = "eml_xgeru";
  c5_info[91].dominantType = "double";
  c5_info[91].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m";
  c5_info[91].fileTimeLo = 1299076774U;
  c5_info[91].fileTimeHi = 0U;
  c5_info[91].mFileTimeLo = 0U;
  c5_info[91].mFileTimeHi = 0U;
  c5_info[92].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m";
  c5_info[92].name = "eml_blas_inline";
  c5_info[92].dominantType = "";
  c5_info[92].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c5_info[92].fileTimeLo = 1299076768U;
  c5_info[92].fileTimeHi = 0U;
  c5_info[92].mFileTimeLo = 0U;
  c5_info[92].mFileTimeHi = 0U;
  c5_info[93].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m";
  c5_info[93].name = "eml_xger";
  c5_info[93].dominantType = "double";
  c5_info[93].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xger.m";
  c5_info[93].fileTimeLo = 1299076774U;
  c5_info[93].fileTimeHi = 0U;
  c5_info[93].mFileTimeLo = 0U;
  c5_info[93].mFileTimeHi = 0U;
  c5_info[94].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xger.m";
  c5_info[94].name = "eml_blas_inline";
  c5_info[94].dominantType = "";
  c5_info[94].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c5_info[94].fileTimeLo = 1299076768U;
  c5_info[94].fileTimeHi = 0U;
  c5_info[94].mFileTimeLo = 0U;
  c5_info[94].mFileTimeHi = 0U;
  c5_info[95].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m!below_threshold";
  c5_info[95].name = "intmax";
  c5_info[95].dominantType = "char";
  c5_info[95].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c5_info[95].fileTimeLo = 1311255316U;
  c5_info[95].fileTimeHi = 0U;
  c5_info[95].mFileTimeLo = 0U;
  c5_info[95].mFileTimeHi = 0U;
  c5_info[96].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m!below_threshold";
  c5_info[96].name = "min";
  c5_info[96].dominantType = "double";
  c5_info[96].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c5_info[96].fileTimeLo = 1311255318U;
  c5_info[96].fileTimeHi = 0U;
  c5_info[96].mFileTimeLo = 0U;
  c5_info[96].mFileTimeHi = 0U;
  c5_info[97].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m!below_threshold";
  c5_info[97].name = "mtimes";
  c5_info[97].dominantType = "double";
  c5_info[97].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[97].fileTimeLo = 1289519692U;
  c5_info[97].fileTimeHi = 0U;
  c5_info[97].mFileTimeLo = 0U;
  c5_info[97].mFileTimeHi = 0U;
  c5_info[98].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m";
  c5_info[98].name = "eml_index_class";
  c5_info[98].dominantType = "";
  c5_info[98].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c5_info[98].fileTimeLo = 1323170578U;
  c5_info[98].fileTimeHi = 0U;
  c5_info[98].mFileTimeLo = 0U;
  c5_info[98].mFileTimeHi = 0U;
  c5_info[99].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m";
  c5_info[99].name = "eml_refblas_xger";
  c5_info[99].dominantType = "double";
  c5_info[99].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xger.m";
  c5_info[99].fileTimeLo = 1299076776U;
  c5_info[99].fileTimeHi = 0U;
  c5_info[99].mFileTimeLo = 0U;
  c5_info[99].mFileTimeHi = 0U;
  c5_info[100].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xger.m";
  c5_info[100].name = "eml_refblas_xgerx";
  c5_info[100].dominantType = "char";
  c5_info[100].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c5_info[100].fileTimeLo = 1299076778U;
  c5_info[100].fileTimeHi = 0U;
  c5_info[100].mFileTimeLo = 0U;
  c5_info[100].mFileTimeHi = 0U;
  c5_info[101].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c5_info[101].name = "eml_index_class";
  c5_info[101].dominantType = "";
  c5_info[101].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c5_info[101].fileTimeLo = 1323170578U;
  c5_info[101].fileTimeHi = 0U;
  c5_info[101].mFileTimeLo = 0U;
  c5_info[101].mFileTimeHi = 0U;
  c5_info[102].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c5_info[102].name = "abs";
  c5_info[102].dominantType = "coder.internal.indexInt";
  c5_info[102].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c5_info[102].fileTimeLo = 1343830366U;
  c5_info[102].fileTimeHi = 0U;
  c5_info[102].mFileTimeLo = 0U;
  c5_info[102].mFileTimeHi = 0U;
  c5_info[103].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c5_info[103].name = "eml_index_minus";
  c5_info[103].dominantType = "double";
  c5_info[103].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c5_info[103].fileTimeLo = 1286818778U;
  c5_info[103].fileTimeHi = 0U;
  c5_info[103].mFileTimeLo = 0U;
  c5_info[103].mFileTimeHi = 0U;
  c5_info[104].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c5_info[104].name = "eml_int_forloop_overflow_check";
  c5_info[104].dominantType = "";
  c5_info[104].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c5_info[104].fileTimeLo = 1346510340U;
  c5_info[104].fileTimeHi = 0U;
  c5_info[104].mFileTimeLo = 0U;
  c5_info[104].mFileTimeHi = 0U;
  c5_info[105].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c5_info[105].name = "eml_index_plus";
  c5_info[105].dominantType = "double";
  c5_info[105].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c5_info[105].fileTimeLo = 1286818778U;
  c5_info[105].fileTimeHi = 0U;
  c5_info[105].mFileTimeLo = 0U;
  c5_info[105].mFileTimeHi = 0U;
  c5_info[106].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c5_info[106].name = "eml_index_plus";
  c5_info[106].dominantType = "coder.internal.indexInt";
  c5_info[106].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c5_info[106].fileTimeLo = 1286818778U;
  c5_info[106].fileTimeHi = 0U;
  c5_info[106].mFileTimeLo = 0U;
  c5_info[106].mFileTimeHi = 0U;
  c5_info[107].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!warn_singular";
  c5_info[107].name = "eml_warning";
  c5_info[107].dominantType = "char";
  c5_info[107].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c5_info[107].fileTimeLo = 1286818802U;
  c5_info[107].fileTimeHi = 0U;
  c5_info[107].mFileTimeLo = 0U;
  c5_info[107].mFileTimeHi = 0U;
  c5_info[108].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolveNxN";
  c5_info[108].name = "eml_scalar_eg";
  c5_info[108].dominantType = "double";
  c5_info[108].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c5_info[108].fileTimeLo = 1286818796U;
  c5_info[108].fileTimeHi = 0U;
  c5_info[108].mFileTimeLo = 0U;
  c5_info[108].mFileTimeHi = 0U;
  c5_info[109].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolveNxN";
  c5_info[109].name = "eml_int_forloop_overflow_check";
  c5_info[109].dominantType = "";
  c5_info[109].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c5_info[109].fileTimeLo = 1346510340U;
  c5_info[109].fileTimeHi = 0U;
  c5_info[109].mFileTimeLo = 0U;
  c5_info[109].mFileTimeHi = 0U;
  c5_info[110].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolveNxN";
  c5_info[110].name = "eml_xtrsm";
  c5_info[110].dominantType = "char";
  c5_info[110].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xtrsm.m";
  c5_info[110].fileTimeLo = 1299076778U;
  c5_info[110].fileTimeHi = 0U;
  c5_info[110].mFileTimeLo = 0U;
  c5_info[110].mFileTimeHi = 0U;
  c5_info[111].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xtrsm.m";
  c5_info[111].name = "eml_blas_inline";
  c5_info[111].dominantType = "";
  c5_info[111].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c5_info[111].fileTimeLo = 1299076768U;
  c5_info[111].fileTimeHi = 0U;
  c5_info[111].mFileTimeLo = 0U;
  c5_info[111].mFileTimeHi = 0U;
  c5_info[112].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xtrsm.m!below_threshold";
  c5_info[112].name = "mtimes";
  c5_info[112].dominantType = "double";
  c5_info[112].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[112].fileTimeLo = 1289519692U;
  c5_info[112].fileTimeHi = 0U;
  c5_info[112].mFileTimeLo = 0U;
  c5_info[112].mFileTimeHi = 0U;
  c5_info[113].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xtrsm.m";
  c5_info[113].name = "eml_index_class";
  c5_info[113].dominantType = "";
  c5_info[113].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c5_info[113].fileTimeLo = 1323170578U;
  c5_info[113].fileTimeHi = 0U;
  c5_info[113].mFileTimeLo = 0U;
  c5_info[113].mFileTimeHi = 0U;
  c5_info[114].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xtrsm.m";
  c5_info[114].name = "eml_scalar_eg";
  c5_info[114].dominantType = "double";
  c5_info[114].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c5_info[114].fileTimeLo = 1286818796U;
  c5_info[114].fileTimeHi = 0U;
  c5_info[114].mFileTimeLo = 0U;
  c5_info[114].mFileTimeHi = 0U;
  c5_info[115].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xtrsm.m";
  c5_info[115].name = "eml_refblas_xtrsm";
  c5_info[115].dominantType = "char";
  c5_info[115].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c5_info[115].fileTimeLo = 1299076786U;
  c5_info[115].fileTimeHi = 0U;
  c5_info[115].mFileTimeLo = 0U;
  c5_info[115].mFileTimeHi = 0U;
  c5_info[116].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c5_info[116].name = "eml_scalar_eg";
  c5_info[116].dominantType = "double";
  c5_info[116].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c5_info[116].fileTimeLo = 1286818796U;
  c5_info[116].fileTimeHi = 0U;
  c5_info[116].mFileTimeLo = 0U;
  c5_info[116].mFileTimeHi = 0U;
  c5_info[117].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c5_info[117].name = "eml_index_minus";
  c5_info[117].dominantType = "double";
  c5_info[117].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c5_info[117].fileTimeLo = 1286818778U;
  c5_info[117].fileTimeHi = 0U;
  c5_info[117].mFileTimeLo = 0U;
  c5_info[117].mFileTimeHi = 0U;
  c5_info[118].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c5_info[118].name = "eml_index_class";
  c5_info[118].dominantType = "";
  c5_info[118].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c5_info[118].fileTimeLo = 1323170578U;
  c5_info[118].fileTimeHi = 0U;
  c5_info[118].mFileTimeLo = 0U;
  c5_info[118].mFileTimeHi = 0U;
  c5_info[119].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c5_info[119].name = "eml_int_forloop_overflow_check";
  c5_info[119].dominantType = "";
  c5_info[119].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c5_info[119].fileTimeLo = 1346510340U;
  c5_info[119].fileTimeHi = 0U;
  c5_info[119].mFileTimeLo = 0U;
  c5_info[119].mFileTimeHi = 0U;
  c5_info[120].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c5_info[120].name = "eml_index_times";
  c5_info[120].dominantType = "coder.internal.indexInt";
  c5_info[120].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c5_info[120].fileTimeLo = 1286818780U;
  c5_info[120].fileTimeHi = 0U;
  c5_info[120].mFileTimeLo = 0U;
  c5_info[120].mFileTimeHi = 0U;
  c5_info[121].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c5_info[121].name = "eml_index_plus";
  c5_info[121].dominantType = "coder.internal.indexInt";
  c5_info[121].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c5_info[121].fileTimeLo = 1286818778U;
  c5_info[121].fileTimeHi = 0U;
  c5_info[121].mFileTimeLo = 0U;
  c5_info[121].mFileTimeHi = 0U;
  c5_info[122].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c5_info[122].name = "eml_index_plus";
  c5_info[122].dominantType = "double";
  c5_info[122].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c5_info[122].fileTimeLo = 1286818778U;
  c5_info[122].fileTimeHi = 0U;
  c5_info[122].mFileTimeLo = 0U;
  c5_info[122].mFileTimeHi = 0U;
  c5_info[123].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  c5_info[123].name = "intmin";
  c5_info[123].dominantType = "char";
  c5_info[123].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c5_info[123].fileTimeLo = 1311255318U;
  c5_info[123].fileTimeHi = 0U;
  c5_info[123].mFileTimeLo = 0U;
  c5_info[123].mFileTimeHi = 0U;
  c5_info[124].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c5_info[124].name = "eml_div";
  c5_info[124].dominantType = "double";
  c5_info[124].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c5_info[124].fileTimeLo = 1313347810U;
  c5_info[124].fileTimeHi = 0U;
  c5_info[124].mFileTimeLo = 0U;
  c5_info[124].mFileTimeHi = 0U;
}

static void c5_eml_scalar_eg(SFc5_torqueBalancing2012bInstanceStruct
  *chartInstance)
{
}

static void c5_mldivide(SFc5_torqueBalancing2012bInstanceStruct *chartInstance,
  real_T c5_A[36], real_T c5_B[72], real_T c5_Y[72])
{
  int32_T c5_i96;
  real_T c5_b_A[36];
  int32_T c5_info;
  int32_T c5_ipiv[6];
  int32_T c5_b_info;
  int32_T c5_c_info;
  int32_T c5_d_info;
  int32_T c5_i97;
  int32_T c5_i;
  int32_T c5_b_i;
  int32_T c5_ip;
  int32_T c5_j;
  int32_T c5_b_j;
  real_T c5_temp;
  int32_T c5_i98;
  real_T c5_c_A[36];
  int32_T c5_i99;
  real_T c5_d_A[36];
  for (c5_i96 = 0; c5_i96 < 36; c5_i96++) {
    c5_b_A[c5_i96] = c5_A[c5_i96];
  }

  c5_b_eml_matlab_zgetrf(chartInstance, c5_b_A, c5_ipiv, &c5_info);
  c5_b_info = c5_info;
  c5_c_info = c5_b_info;
  c5_d_info = c5_c_info;
  if (c5_d_info > 0) {
    c5_eml_warning(chartInstance);
  }

  for (c5_i97 = 0; c5_i97 < 72; c5_i97++) {
    c5_Y[c5_i97] = c5_B[c5_i97];
  }

  for (c5_i = 1; c5_i < 7; c5_i++) {
    c5_b_i = c5_i;
    if (c5_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c5_b_i), 1, 6, 1, 0) - 1] != c5_b_i) {
      c5_ip = c5_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c5_b_i), 1, 6, 1, 0) - 1];
      for (c5_j = 1; c5_j < 13; c5_j++) {
        c5_b_j = c5_j;
        c5_temp = c5_Y[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c5_b_i), 1, 6, 1, 0) + 6 *
                        (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c5_b_j), 1, 12, 2, 0) - 1)) - 1];
        c5_Y[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c5_b_i), 1, 6, 1, 0) + 6 * (_SFD_EML_ARRAY_BOUNDS_CHECK(
                "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c5_b_j), 1, 12, 2, 0)
               - 1)) - 1] = c5_Y[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c5_ip), 1, 6, 1, 0) + 6 *
          (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c5_b_j), 1, 12, 2, 0) - 1)) - 1];
        c5_Y[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c5_ip), 1, 6, 1, 0) + 6 * (_SFD_EML_ARRAY_BOUNDS_CHECK(
                "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c5_b_j), 1, 12, 2, 0)
               - 1)) - 1] = c5_temp;
      }
    }
  }

  for (c5_i98 = 0; c5_i98 < 36; c5_i98++) {
    c5_c_A[c5_i98] = c5_b_A[c5_i98];
  }

  c5_c_eml_xtrsm(chartInstance, c5_c_A, c5_Y);
  for (c5_i99 = 0; c5_i99 < 36; c5_i99++) {
    c5_d_A[c5_i99] = c5_b_A[c5_i99];
  }

  c5_d_eml_xtrsm(chartInstance, c5_d_A, c5_Y);
}

static void c5_realmin(SFc5_torqueBalancing2012bInstanceStruct *chartInstance)
{
}

static void c5_eps(SFc5_torqueBalancing2012bInstanceStruct *chartInstance)
{
}

static void c5_eml_matlab_zgetrf(SFc5_torqueBalancing2012bInstanceStruct
  *chartInstance, real_T c5_A[36], real_T c5_b_A[36], int32_T c5_ipiv[6],
  int32_T *c5_info)
{
  int32_T c5_i100;
  for (c5_i100 = 0; c5_i100 < 36; c5_i100++) {
    c5_b_A[c5_i100] = c5_A[c5_i100];
  }

  c5_b_eml_matlab_zgetrf(chartInstance, c5_b_A, c5_ipiv, c5_info);
}

static void c5_check_forloop_overflow_error
  (SFc5_torqueBalancing2012bInstanceStruct *chartInstance, boolean_T c5_overflow)
{
  int32_T c5_i101;
  static char_T c5_cv0[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  char_T c5_u[34];
  const mxArray *c5_y = NULL;
  int32_T c5_i102;
  static char_T c5_cv1[23] = { 'c', 'o', 'd', 'e', 'r', '.', 'i', 'n', 't', 'e',
    'r', 'n', 'a', 'l', '.', 'i', 'n', 'd', 'e', 'x', 'I', 'n', 't' };

  char_T c5_b_u[23];
  const mxArray *c5_b_y = NULL;
  if (!c5_overflow) {
  } else {
    for (c5_i101 = 0; c5_i101 < 34; c5_i101++) {
      c5_u[c5_i101] = c5_cv0[c5_i101];
    }

    c5_y = NULL;
    sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 10, 0U, 1U, 0U, 2, 1, 34),
                  FALSE);
    for (c5_i102 = 0; c5_i102 < 23; c5_i102++) {
      c5_b_u[c5_i102] = c5_cv1[c5_i102];
    }

    c5_b_y = NULL;
    sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_b_u, 10, 0U, 1U, 0U, 2, 1, 23),
                  FALSE);
    sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U,
      14, c5_y, 14, c5_b_y));
  }
}

static void c5_eml_xger(SFc5_torqueBalancing2012bInstanceStruct *chartInstance,
  int32_T c5_m, int32_T c5_n, real_T c5_alpha1, int32_T c5_ix0, int32_T c5_iy0,
  real_T c5_A[36], int32_T c5_ia0, real_T c5_b_A[36])
{
  int32_T c5_i103;
  for (c5_i103 = 0; c5_i103 < 36; c5_i103++) {
    c5_b_A[c5_i103] = c5_A[c5_i103];
  }

  c5_b_eml_xger(chartInstance, c5_m, c5_n, c5_alpha1, c5_ix0, c5_iy0, c5_b_A,
                c5_ia0);
}

static void c5_eml_warning(SFc5_torqueBalancing2012bInstanceStruct
  *chartInstance)
{
  int32_T c5_i104;
  static char_T c5_varargin_1[27] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a',
    't', 'r', 'i', 'x' };

  char_T c5_u[27];
  const mxArray *c5_y = NULL;
  for (c5_i104 = 0; c5_i104 < 27; c5_i104++) {
    c5_u[c5_i104] = c5_varargin_1[c5_i104];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 10, 0U, 1U, 0U, 2, 1, 27), FALSE);
  sf_mex_call_debug("warning", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U,
    14, c5_y));
}

static void c5_eml_xtrsm(SFc5_torqueBalancing2012bInstanceStruct *chartInstance,
  real_T c5_A[36], real_T c5_B[72], real_T c5_b_B[72])
{
  int32_T c5_i105;
  int32_T c5_i106;
  real_T c5_b_A[36];
  for (c5_i105 = 0; c5_i105 < 72; c5_i105++) {
    c5_b_B[c5_i105] = c5_B[c5_i105];
  }

  for (c5_i106 = 0; c5_i106 < 36; c5_i106++) {
    c5_b_A[c5_i106] = c5_A[c5_i106];
  }

  c5_c_eml_xtrsm(chartInstance, c5_b_A, c5_b_B);
}

static void c5_below_threshold(SFc5_torqueBalancing2012bInstanceStruct
  *chartInstance)
{
}

static void c5_b_eml_scalar_eg(SFc5_torqueBalancing2012bInstanceStruct
  *chartInstance)
{
}

static void c5_b_eml_xtrsm(SFc5_torqueBalancing2012bInstanceStruct
  *chartInstance, real_T c5_A[36], real_T c5_B[72], real_T c5_b_B[72])
{
  int32_T c5_i107;
  int32_T c5_i108;
  real_T c5_b_A[36];
  for (c5_i107 = 0; c5_i107 < 72; c5_i107++) {
    c5_b_B[c5_i107] = c5_B[c5_i107];
  }

  for (c5_i108 = 0; c5_i108 < 36; c5_i108++) {
    c5_b_A[c5_i108] = c5_A[c5_i108];
  }

  c5_d_eml_xtrsm(chartInstance, c5_b_A, c5_b_B);
}

static void c5_c_eml_scalar_eg(SFc5_torqueBalancing2012bInstanceStruct
  *chartInstance)
{
}

static void c5_eml_xgemm(SFc5_torqueBalancing2012bInstanceStruct *chartInstance,
  real_T c5_A[72], real_T c5_B[276], real_T c5_C[138], real_T c5_b_C[138])
{
  int32_T c5_i109;
  int32_T c5_i110;
  real_T c5_b_A[72];
  int32_T c5_i111;
  real_T c5_b_B[276];
  for (c5_i109 = 0; c5_i109 < 138; c5_i109++) {
    c5_b_C[c5_i109] = c5_C[c5_i109];
  }

  for (c5_i110 = 0; c5_i110 < 72; c5_i110++) {
    c5_b_A[c5_i110] = c5_A[c5_i110];
  }

  for (c5_i111 = 0; c5_i111 < 276; c5_i111++) {
    c5_b_B[c5_i111] = c5_B[c5_i111];
  }

  c5_b_eml_xgemm(chartInstance, c5_b_A, c5_b_B, c5_b_C);
}

static void c5_d_eml_scalar_eg(SFc5_torqueBalancing2012bInstanceStruct
  *chartInstance)
{
}

static const mxArray *c5_i_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_torqueBalancing2012bInstanceStruct *chartInstance;
  chartInstance = (SFc5_torqueBalancing2012bInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(int32_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static int32_T c5_g_emlrt_marshallIn(SFc5_torqueBalancing2012bInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  int32_T c5_y;
  int32_T c5_i112;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_i112, 1, 6, 0U, 0, 0U, 0);
  c5_y = c5_i112;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_sfEvent;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  int32_T c5_y;
  SFc5_torqueBalancing2012bInstanceStruct *chartInstance;
  chartInstance = (SFc5_torqueBalancing2012bInstanceStruct *)chartInstanceVoid;
  c5_b_sfEvent = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_sfEvent),
    &c5_thisId);
  sf_mex_destroy(&c5_b_sfEvent);
  *(int32_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static uint8_T c5_h_emlrt_marshallIn(SFc5_torqueBalancing2012bInstanceStruct
  *chartInstance, const mxArray *c5_b_is_active_c5_torqueBalancing2012b, const
  char_T *c5_identifier)
{
  uint8_T c5_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c5_b_is_active_c5_torqueBalancing2012b), &c5_thisId);
  sf_mex_destroy(&c5_b_is_active_c5_torqueBalancing2012b);
  return c5_y;
}

static uint8_T c5_i_emlrt_marshallIn(SFc5_torqueBalancing2012bInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  uint8_T c5_y;
  uint8_T c5_u0;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_u0, 1, 3, 0U, 0, 0U, 0);
  c5_y = c5_u0;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_b_eml_matlab_zgetrf(SFc5_torqueBalancing2012bInstanceStruct
  *chartInstance, real_T c5_A[36], int32_T c5_ipiv[6], int32_T *c5_info)
{
  int32_T c5_i113;
  int32_T c5_j;
  int32_T c5_b_j;
  int32_T c5_a;
  int32_T c5_jm1;
  int32_T c5_b;
  int32_T c5_mmj;
  int32_T c5_b_a;
  int32_T c5_c;
  int32_T c5_b_b;
  int32_T c5_jj;
  int32_T c5_c_a;
  int32_T c5_jp1j;
  int32_T c5_d_a;
  int32_T c5_b_c;
  int32_T c5_n;
  int32_T c5_ix0;
  int32_T c5_b_n;
  int32_T c5_b_ix0;
  int32_T c5_c_n;
  int32_T c5_c_ix0;
  int32_T c5_idxmax;
  int32_T c5_ix;
  real_T c5_x;
  real_T c5_b_x;
  real_T c5_c_x;
  real_T c5_y;
  real_T c5_d_x;
  real_T c5_e_x;
  real_T c5_b_y;
  real_T c5_smax;
  int32_T c5_d_n;
  int32_T c5_c_b;
  int32_T c5_d_b;
  boolean_T c5_overflow;
  int32_T c5_k;
  int32_T c5_b_k;
  int32_T c5_e_a;
  real_T c5_f_x;
  real_T c5_g_x;
  real_T c5_h_x;
  real_T c5_c_y;
  real_T c5_i_x;
  real_T c5_j_x;
  real_T c5_d_y;
  real_T c5_s;
  int32_T c5_f_a;
  int32_T c5_jpiv_offset;
  int32_T c5_g_a;
  int32_T c5_e_b;
  int32_T c5_jpiv;
  int32_T c5_h_a;
  int32_T c5_f_b;
  int32_T c5_c_c;
  int32_T c5_g_b;
  int32_T c5_jrow;
  int32_T c5_i_a;
  int32_T c5_h_b;
  int32_T c5_jprow;
  int32_T c5_d_ix0;
  int32_T c5_iy0;
  int32_T c5_e_ix0;
  int32_T c5_b_iy0;
  int32_T c5_f_ix0;
  int32_T c5_c_iy0;
  int32_T c5_b_ix;
  int32_T c5_iy;
  int32_T c5_c_k;
  real_T c5_temp;
  int32_T c5_j_a;
  int32_T c5_k_a;
  int32_T c5_b_jp1j;
  int32_T c5_l_a;
  int32_T c5_d_c;
  int32_T c5_m_a;
  int32_T c5_i_b;
  int32_T c5_i114;
  int32_T c5_n_a;
  int32_T c5_j_b;
  int32_T c5_o_a;
  int32_T c5_k_b;
  boolean_T c5_b_overflow;
  int32_T c5_i;
  int32_T c5_b_i;
  real_T c5_k_x;
  real_T c5_e_y;
  real_T c5_z;
  int32_T c5_l_b;
  int32_T c5_e_c;
  int32_T c5_p_a;
  int32_T c5_f_c;
  int32_T c5_q_a;
  int32_T c5_g_c;
  int32_T c5_m;
  int32_T c5_e_n;
  int32_T c5_g_ix0;
  int32_T c5_d_iy0;
  int32_T c5_ia0;
  real_T c5_d1;
  c5_realmin(chartInstance);
  c5_eps(chartInstance);
  for (c5_i113 = 0; c5_i113 < 6; c5_i113++) {
    c5_ipiv[c5_i113] = 1 + c5_i113;
  }

  *c5_info = 0;
  for (c5_j = 1; c5_j < 6; c5_j++) {
    c5_b_j = c5_j;
    c5_a = c5_b_j - 1;
    c5_jm1 = c5_a;
    c5_b = c5_b_j;
    c5_mmj = 6 - c5_b;
    c5_b_a = c5_jm1;
    c5_c = c5_b_a * 7;
    c5_b_b = c5_c + 1;
    c5_jj = c5_b_b;
    c5_c_a = c5_jj + 1;
    c5_jp1j = c5_c_a;
    c5_d_a = c5_mmj;
    c5_b_c = c5_d_a;
    c5_n = c5_b_c + 1;
    c5_ix0 = c5_jj;
    c5_b_n = c5_n;
    c5_b_ix0 = c5_ix0;
    c5_c_n = c5_b_n;
    c5_c_ix0 = c5_b_ix0;
    if (c5_c_n < 1) {
      c5_idxmax = 0;
    } else {
      c5_idxmax = 1;
      if (c5_c_n > 1) {
        c5_ix = c5_c_ix0;
        c5_x = c5_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
          "", (real_T)c5_ix), 1, 36, 1, 0) - 1];
        c5_b_x = c5_x;
        c5_c_x = c5_b_x;
        c5_y = muDoubleScalarAbs(c5_c_x);
        c5_d_x = 0.0;
        c5_e_x = c5_d_x;
        c5_b_y = muDoubleScalarAbs(c5_e_x);
        c5_smax = c5_y + c5_b_y;
        c5_d_n = c5_c_n;
        c5_c_b = c5_d_n;
        c5_d_b = c5_c_b;
        if (2 > c5_d_b) {
          c5_overflow = FALSE;
        } else {
          c5_overflow = (c5_d_b > 2147483646);
        }

        if (c5_overflow) {
          c5_check_forloop_overflow_error(chartInstance, c5_overflow);
        }

        for (c5_k = 2; c5_k <= c5_d_n; c5_k++) {
          c5_b_k = c5_k;
          c5_e_a = c5_ix + 1;
          c5_ix = c5_e_a;
          c5_f_x = c5_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c5_ix), 1, 36, 1, 0) - 1];
          c5_g_x = c5_f_x;
          c5_h_x = c5_g_x;
          c5_c_y = muDoubleScalarAbs(c5_h_x);
          c5_i_x = 0.0;
          c5_j_x = c5_i_x;
          c5_d_y = muDoubleScalarAbs(c5_j_x);
          c5_s = c5_c_y + c5_d_y;
          if (c5_s > c5_smax) {
            c5_idxmax = c5_b_k;
            c5_smax = c5_s;
          }
        }
      }
    }

    c5_f_a = c5_idxmax - 1;
    c5_jpiv_offset = c5_f_a;
    c5_g_a = c5_jj;
    c5_e_b = c5_jpiv_offset;
    c5_jpiv = c5_g_a + c5_e_b;
    if (c5_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c5_jpiv), 1, 36, 1, 0) - 1] != 0.0) {
      if (c5_jpiv_offset != 0) {
        c5_h_a = c5_b_j;
        c5_f_b = c5_jpiv_offset;
        c5_c_c = c5_h_a + c5_f_b;
        c5_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c5_b_j), 1, 6, 1, 0) - 1] = c5_c_c;
        c5_g_b = c5_jm1 + 1;
        c5_jrow = c5_g_b;
        c5_i_a = c5_jrow;
        c5_h_b = c5_jpiv_offset;
        c5_jprow = c5_i_a + c5_h_b;
        c5_d_ix0 = c5_jrow;
        c5_iy0 = c5_jprow;
        c5_e_ix0 = c5_d_ix0;
        c5_b_iy0 = c5_iy0;
        c5_f_ix0 = c5_e_ix0;
        c5_c_iy0 = c5_b_iy0;
        c5_b_ix = c5_f_ix0;
        c5_iy = c5_c_iy0;
        for (c5_c_k = 1; c5_c_k < 7; c5_c_k++) {
          c5_temp = c5_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c5_b_ix), 1, 36, 1, 0) - 1];
          c5_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c5_b_ix), 1, 36, 1, 0) - 1] =
            c5_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c5_iy), 1, 36, 1, 0) - 1];
          c5_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c5_iy), 1, 36, 1, 0) - 1] = c5_temp;
          c5_j_a = c5_b_ix + 6;
          c5_b_ix = c5_j_a;
          c5_k_a = c5_iy + 6;
          c5_iy = c5_k_a;
        }
      }

      c5_b_jp1j = c5_jp1j;
      c5_l_a = c5_mmj;
      c5_d_c = c5_l_a;
      c5_m_a = c5_jp1j;
      c5_i_b = c5_d_c - 1;
      c5_i114 = c5_m_a + c5_i_b;
      c5_n_a = c5_b_jp1j;
      c5_j_b = c5_i114;
      c5_o_a = c5_n_a;
      c5_k_b = c5_j_b;
      if (c5_o_a > c5_k_b) {
        c5_b_overflow = FALSE;
      } else {
        c5_b_overflow = (c5_k_b > 2147483646);
      }

      if (c5_b_overflow) {
        c5_check_forloop_overflow_error(chartInstance, c5_b_overflow);
      }

      for (c5_i = c5_b_jp1j; c5_i <= c5_i114; c5_i++) {
        c5_b_i = c5_i;
        c5_k_x = c5_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c5_b_i), 1, 36, 1, 0) - 1];
        c5_e_y = c5_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c5_jj), 1, 36, 1, 0) - 1];
        c5_z = c5_k_x / c5_e_y;
        c5_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c5_b_i), 1, 36, 1, 0) - 1] = c5_z;
      }
    } else {
      *c5_info = c5_b_j;
    }

    c5_l_b = c5_b_j;
    c5_e_c = 6 - c5_l_b;
    c5_p_a = c5_jj;
    c5_f_c = c5_p_a;
    c5_q_a = c5_jj;
    c5_g_c = c5_q_a;
    c5_m = c5_mmj;
    c5_e_n = c5_e_c;
    c5_g_ix0 = c5_jp1j;
    c5_d_iy0 = c5_f_c + 6;
    c5_ia0 = c5_g_c + 7;
    c5_d1 = -1.0;
    c5_b_eml_xger(chartInstance, c5_m, c5_e_n, c5_d1, c5_g_ix0, c5_d_iy0, c5_A,
                  c5_ia0);
  }

  if (*c5_info == 0) {
    if (!(c5_A[35] != 0.0)) {
      *c5_info = 6;
    }
  }
}

static void c5_b_eml_xger(SFc5_torqueBalancing2012bInstanceStruct *chartInstance,
  int32_T c5_m, int32_T c5_n, real_T c5_alpha1, int32_T c5_ix0, int32_T c5_iy0,
  real_T c5_A[36], int32_T c5_ia0)
{
  int32_T c5_b_m;
  int32_T c5_b_n;
  real_T c5_b_alpha1;
  int32_T c5_b_ix0;
  int32_T c5_b_iy0;
  int32_T c5_b_ia0;
  int32_T c5_c_m;
  int32_T c5_c_n;
  real_T c5_c_alpha1;
  int32_T c5_c_ix0;
  int32_T c5_c_iy0;
  int32_T c5_c_ia0;
  int32_T c5_d_m;
  int32_T c5_d_n;
  real_T c5_d_alpha1;
  int32_T c5_d_ix0;
  int32_T c5_d_iy0;
  int32_T c5_d_ia0;
  int32_T c5_ixstart;
  int32_T c5_a;
  int32_T c5_jA;
  int32_T c5_jy;
  int32_T c5_e_n;
  int32_T c5_b;
  int32_T c5_b_b;
  boolean_T c5_overflow;
  int32_T c5_j;
  real_T c5_yjy;
  real_T c5_temp;
  int32_T c5_ix;
  int32_T c5_c_b;
  int32_T c5_i115;
  int32_T c5_b_a;
  int32_T c5_d_b;
  int32_T c5_i116;
  int32_T c5_c_a;
  int32_T c5_e_b;
  int32_T c5_d_a;
  int32_T c5_f_b;
  boolean_T c5_b_overflow;
  int32_T c5_ijA;
  int32_T c5_b_ijA;
  int32_T c5_e_a;
  int32_T c5_f_a;
  int32_T c5_g_a;
  c5_b_m = c5_m;
  c5_b_n = c5_n;
  c5_b_alpha1 = c5_alpha1;
  c5_b_ix0 = c5_ix0;
  c5_b_iy0 = c5_iy0;
  c5_b_ia0 = c5_ia0;
  c5_c_m = c5_b_m;
  c5_c_n = c5_b_n;
  c5_c_alpha1 = c5_b_alpha1;
  c5_c_ix0 = c5_b_ix0;
  c5_c_iy0 = c5_b_iy0;
  c5_c_ia0 = c5_b_ia0;
  c5_d_m = c5_c_m;
  c5_d_n = c5_c_n;
  c5_d_alpha1 = c5_c_alpha1;
  c5_d_ix0 = c5_c_ix0;
  c5_d_iy0 = c5_c_iy0;
  c5_d_ia0 = c5_c_ia0;
  if (c5_d_alpha1 == 0.0) {
  } else {
    c5_ixstart = c5_d_ix0;
    c5_a = c5_d_ia0 - 1;
    c5_jA = c5_a;
    c5_jy = c5_d_iy0;
    c5_e_n = c5_d_n;
    c5_b = c5_e_n;
    c5_b_b = c5_b;
    if (1 > c5_b_b) {
      c5_overflow = FALSE;
    } else {
      c5_overflow = (c5_b_b > 2147483646);
    }

    if (c5_overflow) {
      c5_check_forloop_overflow_error(chartInstance, c5_overflow);
    }

    for (c5_j = 1; c5_j <= c5_e_n; c5_j++) {
      c5_yjy = c5_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
        "", (real_T)c5_jy), 1, 36, 1, 0) - 1];
      if (c5_yjy != 0.0) {
        c5_temp = c5_yjy * c5_d_alpha1;
        c5_ix = c5_ixstart;
        c5_c_b = c5_jA + 1;
        c5_i115 = c5_c_b;
        c5_b_a = c5_d_m;
        c5_d_b = c5_jA;
        c5_i116 = c5_b_a + c5_d_b;
        c5_c_a = c5_i115;
        c5_e_b = c5_i116;
        c5_d_a = c5_c_a;
        c5_f_b = c5_e_b;
        if (c5_d_a > c5_f_b) {
          c5_b_overflow = FALSE;
        } else {
          c5_b_overflow = (c5_f_b > 2147483646);
        }

        if (c5_b_overflow) {
          c5_check_forloop_overflow_error(chartInstance, c5_b_overflow);
        }

        for (c5_ijA = c5_i115; c5_ijA <= c5_i116; c5_ijA++) {
          c5_b_ijA = c5_ijA;
          c5_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c5_b_ijA), 1, 36, 1, 0) - 1] =
            c5_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c5_b_ijA), 1, 36, 1, 0) - 1] +
            c5_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c5_ix), 1, 36, 1, 0) - 1] * c5_temp;
          c5_e_a = c5_ix + 1;
          c5_ix = c5_e_a;
        }
      }

      c5_f_a = c5_jy + 6;
      c5_jy = c5_f_a;
      c5_g_a = c5_jA + 6;
      c5_jA = c5_g_a;
    }
  }
}

static void c5_c_eml_xtrsm(SFc5_torqueBalancing2012bInstanceStruct
  *chartInstance, real_T c5_A[36], real_T c5_B[72])
{
  int32_T c5_j;
  int32_T c5_b_j;
  int32_T c5_a;
  int32_T c5_c;
  int32_T c5_b;
  int32_T c5_b_c;
  int32_T c5_b_b;
  int32_T c5_jBcol;
  int32_T c5_k;
  int32_T c5_b_k;
  int32_T c5_b_a;
  int32_T c5_c_c;
  int32_T c5_c_b;
  int32_T c5_d_c;
  int32_T c5_d_b;
  int32_T c5_kAcol;
  int32_T c5_c_a;
  int32_T c5_e_b;
  int32_T c5_e_c;
  int32_T c5_d_a;
  int32_T c5_i117;
  boolean_T c5_overflow;
  int32_T c5_i;
  int32_T c5_b_i;
  int32_T c5_e_a;
  int32_T c5_f_b;
  int32_T c5_f_c;
  int32_T c5_f_a;
  int32_T c5_g_b;
  int32_T c5_g_c;
  int32_T c5_g_a;
  int32_T c5_h_b;
  int32_T c5_h_c;
  int32_T c5_h_a;
  int32_T c5_i_b;
  int32_T c5_i_c;
  c5_below_threshold(chartInstance);
  c5_b_eml_scalar_eg(chartInstance);
  for (c5_j = 1; c5_j < 13; c5_j++) {
    c5_b_j = c5_j;
    c5_a = c5_b_j;
    c5_c = c5_a;
    c5_b = c5_c - 1;
    c5_b_c = 6 * c5_b;
    c5_b_b = c5_b_c;
    c5_jBcol = c5_b_b;
    for (c5_k = 1; c5_k < 7; c5_k++) {
      c5_b_k = c5_k;
      c5_b_a = c5_b_k;
      c5_c_c = c5_b_a;
      c5_c_b = c5_c_c - 1;
      c5_d_c = 6 * c5_c_b;
      c5_d_b = c5_d_c;
      c5_kAcol = c5_d_b;
      c5_c_a = c5_b_k;
      c5_e_b = c5_jBcol;
      c5_e_c = c5_c_a + c5_e_b;
      if (c5_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c5_e_c), 1, 72, 1, 0) - 1] != 0.0) {
        c5_d_a = c5_b_k;
        c5_i117 = c5_d_a;
        c5_overflow = FALSE;
        if (c5_overflow) {
          c5_check_forloop_overflow_error(chartInstance, c5_overflow);
        }

        for (c5_i = c5_i117 + 1; c5_i < 7; c5_i++) {
          c5_b_i = c5_i;
          c5_e_a = c5_b_i;
          c5_f_b = c5_jBcol;
          c5_f_c = c5_e_a + c5_f_b;
          c5_f_a = c5_b_i;
          c5_g_b = c5_jBcol;
          c5_g_c = c5_f_a + c5_g_b;
          c5_g_a = c5_b_k;
          c5_h_b = c5_jBcol;
          c5_h_c = c5_g_a + c5_h_b;
          c5_h_a = c5_b_i;
          c5_i_b = c5_kAcol;
          c5_i_c = c5_h_a + c5_i_b;
          c5_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c5_f_c), 1, 72, 1, 0) - 1] =
            c5_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c5_g_c), 1, 72, 1, 0) - 1] -
            c5_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c5_h_c), 1, 72, 1, 0) - 1] *
            c5_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c5_i_c), 1, 36, 1, 0) - 1];
        }
      }
    }
  }
}

static void c5_d_eml_xtrsm(SFc5_torqueBalancing2012bInstanceStruct
  *chartInstance, real_T c5_A[36], real_T c5_B[72])
{
  int32_T c5_j;
  int32_T c5_b_j;
  int32_T c5_a;
  int32_T c5_c;
  int32_T c5_b;
  int32_T c5_b_c;
  int32_T c5_b_b;
  int32_T c5_jBcol;
  int32_T c5_k;
  int32_T c5_b_k;
  int32_T c5_b_a;
  int32_T c5_c_c;
  int32_T c5_c_b;
  int32_T c5_d_c;
  int32_T c5_d_b;
  int32_T c5_kAcol;
  int32_T c5_c_a;
  int32_T c5_e_b;
  int32_T c5_e_c;
  int32_T c5_d_a;
  int32_T c5_f_b;
  int32_T c5_f_c;
  int32_T c5_e_a;
  int32_T c5_g_b;
  int32_T c5_g_c;
  int32_T c5_f_a;
  int32_T c5_h_b;
  int32_T c5_h_c;
  real_T c5_x;
  real_T c5_y;
  real_T c5_z;
  int32_T c5_g_a;
  int32_T c5_i118;
  int32_T c5_i_b;
  int32_T c5_j_b;
  boolean_T c5_overflow;
  int32_T c5_i;
  int32_T c5_b_i;
  int32_T c5_h_a;
  int32_T c5_k_b;
  int32_T c5_i_c;
  int32_T c5_i_a;
  int32_T c5_l_b;
  int32_T c5_j_c;
  int32_T c5_j_a;
  int32_T c5_m_b;
  int32_T c5_k_c;
  int32_T c5_k_a;
  int32_T c5_n_b;
  int32_T c5_l_c;
  c5_below_threshold(chartInstance);
  c5_b_eml_scalar_eg(chartInstance);
  for (c5_j = 1; c5_j < 13; c5_j++) {
    c5_b_j = c5_j;
    c5_a = c5_b_j;
    c5_c = c5_a;
    c5_b = c5_c - 1;
    c5_b_c = 6 * c5_b;
    c5_b_b = c5_b_c;
    c5_jBcol = c5_b_b;
    for (c5_k = 6; c5_k > 0; c5_k--) {
      c5_b_k = c5_k;
      c5_b_a = c5_b_k;
      c5_c_c = c5_b_a;
      c5_c_b = c5_c_c - 1;
      c5_d_c = 6 * c5_c_b;
      c5_d_b = c5_d_c;
      c5_kAcol = c5_d_b;
      c5_c_a = c5_b_k;
      c5_e_b = c5_jBcol;
      c5_e_c = c5_c_a + c5_e_b;
      if (c5_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c5_e_c), 1, 72, 1, 0) - 1] != 0.0) {
        c5_d_a = c5_b_k;
        c5_f_b = c5_jBcol;
        c5_f_c = c5_d_a + c5_f_b;
        c5_e_a = c5_b_k;
        c5_g_b = c5_jBcol;
        c5_g_c = c5_e_a + c5_g_b;
        c5_f_a = c5_b_k;
        c5_h_b = c5_kAcol;
        c5_h_c = c5_f_a + c5_h_b;
        c5_x = c5_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
          "", (real_T)c5_g_c), 1, 72, 1, 0) - 1];
        c5_y = c5_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
          "", (real_T)c5_h_c), 1, 36, 1, 0) - 1];
        c5_z = c5_x / c5_y;
        c5_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c5_f_c), 1, 72, 1, 0) - 1] = c5_z;
        c5_g_a = c5_b_k - 1;
        c5_i118 = c5_g_a;
        c5_i_b = c5_i118;
        c5_j_b = c5_i_b;
        if (1 > c5_j_b) {
          c5_overflow = FALSE;
        } else {
          c5_overflow = (c5_j_b > 2147483646);
        }

        if (c5_overflow) {
          c5_check_forloop_overflow_error(chartInstance, c5_overflow);
        }

        for (c5_i = 1; c5_i <= c5_i118; c5_i++) {
          c5_b_i = c5_i;
          c5_h_a = c5_b_i;
          c5_k_b = c5_jBcol;
          c5_i_c = c5_h_a + c5_k_b;
          c5_i_a = c5_b_i;
          c5_l_b = c5_jBcol;
          c5_j_c = c5_i_a + c5_l_b;
          c5_j_a = c5_b_k;
          c5_m_b = c5_jBcol;
          c5_k_c = c5_j_a + c5_m_b;
          c5_k_a = c5_b_i;
          c5_n_b = c5_kAcol;
          c5_l_c = c5_k_a + c5_n_b;
          c5_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c5_i_c), 1, 72, 1, 0) - 1] =
            c5_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c5_j_c), 1, 72, 1, 0) - 1] -
            c5_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c5_k_c), 1, 72, 1, 0) - 1] *
            c5_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c5_l_c), 1, 36, 1, 0) - 1];
        }
      }
    }
  }
}

static void c5_b_eml_xgemm(SFc5_torqueBalancing2012bInstanceStruct
  *chartInstance, real_T c5_A[72], real_T c5_B[276], real_T c5_C[138])
{
  real_T c5_alpha1;
  real_T c5_beta1;
  char_T c5_TRANSB;
  char_T c5_TRANSA;
  ptrdiff_t c5_m_t;
  ptrdiff_t c5_n_t;
  ptrdiff_t c5_k_t;
  ptrdiff_t c5_lda_t;
  ptrdiff_t c5_ldb_t;
  ptrdiff_t c5_ldc_t;
  double * c5_alpha1_t;
  double * c5_Aia0_t;
  double * c5_Bib0_t;
  double * c5_beta1_t;
  double * c5_Cic0_t;
  c5_alpha1 = 1.0;
  c5_beta1 = 0.0;
  c5_TRANSB = 'N';
  c5_TRANSA = 'N';
  c5_m_t = (ptrdiff_t)(6);
  c5_n_t = (ptrdiff_t)(23);
  c5_k_t = (ptrdiff_t)(12);
  c5_lda_t = (ptrdiff_t)(6);
  c5_ldb_t = (ptrdiff_t)(12);
  c5_ldc_t = (ptrdiff_t)(6);
  c5_alpha1_t = (double *)(&c5_alpha1);
  c5_Aia0_t = (double *)(&c5_A[0]);
  c5_Bib0_t = (double *)(&c5_B[0]);
  c5_beta1_t = (double *)(&c5_beta1);
  c5_Cic0_t = (double *)(&c5_C[0]);
  dgemm(&c5_TRANSA, &c5_TRANSB, &c5_m_t, &c5_n_t, &c5_k_t, c5_alpha1_t,
        c5_Aia0_t, &c5_lda_t, c5_Bib0_t, &c5_ldb_t, c5_beta1_t, c5_Cic0_t,
        &c5_ldc_t);
}

static void init_dsm_address_info(SFc5_torqueBalancing2012bInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c5_torqueBalancing2012b_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2609311878U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1939696709U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1409159861U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1516891732U);
}

mxArray *sf_c5_torqueBalancing2012b_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("aGfeCGcwK6wHUSURFtHUY");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(6);
      pr[1] = (double)(29);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(6);
      pr[1] = (double)(29);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(23);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(13));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(6);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c5_torqueBalancing2012b_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c5_torqueBalancing2012b(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c5_torqueBalancing2012b\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c5_torqueBalancing2012b_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc5_torqueBalancing2012bInstanceStruct *chartInstance;
    chartInstance = (SFc5_torqueBalancing2012bInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _torqueBalancing2012bMachineNumber_,
           5,
           1,
           1,
           6,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_torqueBalancing2012bMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_torqueBalancing2012bMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _torqueBalancing2012bMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"JcLeftFoot");
          _SFD_SET_DATA_PROPS(1,1,1,0,"JcRightFoot");
          _SFD_SET_DATA_PROPS(2,1,1,0,"activeFeetConstraints");
          _SFD_SET_DATA_PROPS(3,2,0,1,"y");
          _SFD_SET_DATA_PROPS(4,1,1,0,"qD");
          _SFD_SET_DATA_PROPS(5,10,0,0,"reg");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,300);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 6;
          dimVector[1]= 29;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 6;
          dimVector[1]= 29;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)
            c5_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 23;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(5,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)c5_b_sf_marshallIn);

        {
          real_T (*c5_JcLeftFoot)[174];
          real_T (*c5_JcRightFoot)[174];
          real_T (*c5_activeFeetConstraints)[2];
          real_T (*c5_y)[6];
          real_T (*c5_qD)[23];
          c5_qD = (real_T (*)[23])ssGetInputPortSignal(chartInstance->S, 3);
          c5_y = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
          c5_activeFeetConstraints = (real_T (*)[2])ssGetInputPortSignal
            (chartInstance->S, 2);
          c5_JcRightFoot = (real_T (*)[174])ssGetInputPortSignal
            (chartInstance->S, 1);
          c5_JcLeftFoot = (real_T (*)[174])ssGetInputPortSignal(chartInstance->S,
            0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c5_JcLeftFoot);
          _SFD_SET_DATA_VALUE_PTR(1U, *c5_JcRightFoot);
          _SFD_SET_DATA_VALUE_PTR(2U, *c5_activeFeetConstraints);
          _SFD_SET_DATA_VALUE_PTR(3U, *c5_y);
          _SFD_SET_DATA_VALUE_PTR(4U, *c5_qD);
          _SFD_SET_DATA_VALUE_PTR(5U, &chartInstance->c5_reg);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _torqueBalancing2012bMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "q9hz9H0nLOBpguDFDiv7VE";
}

static void sf_opaque_initialize_c5_torqueBalancing2012b(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc5_torqueBalancing2012bInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c5_torqueBalancing2012b
    ((SFc5_torqueBalancing2012bInstanceStruct*) chartInstanceVar);
  initialize_c5_torqueBalancing2012b((SFc5_torqueBalancing2012bInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c5_torqueBalancing2012b(void *chartInstanceVar)
{
  enable_c5_torqueBalancing2012b((SFc5_torqueBalancing2012bInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c5_torqueBalancing2012b(void *chartInstanceVar)
{
  disable_c5_torqueBalancing2012b((SFc5_torqueBalancing2012bInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c5_torqueBalancing2012b(void *chartInstanceVar)
{
  sf_c5_torqueBalancing2012b((SFc5_torqueBalancing2012bInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c5_torqueBalancing2012b
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c5_torqueBalancing2012b
    ((SFc5_torqueBalancing2012bInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c5_torqueBalancing2012b();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c5_torqueBalancing2012b(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c5_torqueBalancing2012b();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c5_torqueBalancing2012b((SFc5_torqueBalancing2012bInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c5_torqueBalancing2012b(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c5_torqueBalancing2012b(S);
}

static void sf_opaque_set_sim_state_c5_torqueBalancing2012b(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c5_torqueBalancing2012b(S, st);
}

static void sf_opaque_terminate_c5_torqueBalancing2012b(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc5_torqueBalancing2012bInstanceStruct*) chartInstanceVar
      )->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_torqueBalancing2012b_optimization_info();
    }

    finalize_c5_torqueBalancing2012b((SFc5_torqueBalancing2012bInstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc5_torqueBalancing2012b((SFc5_torqueBalancing2012bInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c5_torqueBalancing2012b(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c5_torqueBalancing2012b
      ((SFc5_torqueBalancing2012bInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c5_torqueBalancing2012b(SimStruct *S)
{
  /* Actual parameters from chart:
     reg
   */
  const char_T *rtParamNames[] = { "reg" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0],
    sf_get_param_data_type_id(S,0));
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_torqueBalancing2012b_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      5);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,5,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,5,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,5);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,5,4);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,5,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 4; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,5);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3654278216U));
  ssSetChecksum1(S,(2040900627U));
  ssSetChecksum2(S,(1151640658U));
  ssSetChecksum3(S,(545537918U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c5_torqueBalancing2012b(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c5_torqueBalancing2012b(SimStruct *S)
{
  SFc5_torqueBalancing2012bInstanceStruct *chartInstance;
  chartInstance = (SFc5_torqueBalancing2012bInstanceStruct *)utMalloc(sizeof
    (SFc5_torqueBalancing2012bInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc5_torqueBalancing2012bInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c5_torqueBalancing2012b;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c5_torqueBalancing2012b;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c5_torqueBalancing2012b;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c5_torqueBalancing2012b;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c5_torqueBalancing2012b;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c5_torqueBalancing2012b;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c5_torqueBalancing2012b;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c5_torqueBalancing2012b;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c5_torqueBalancing2012b;
  chartInstance->chartInfo.mdlStart = mdlStart_c5_torqueBalancing2012b;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c5_torqueBalancing2012b;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c5_torqueBalancing2012b_method_dispatcher(SimStruct *S, int_T method, void *
  data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c5_torqueBalancing2012b(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c5_torqueBalancing2012b(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c5_torqueBalancing2012b(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c5_torqueBalancing2012b_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
