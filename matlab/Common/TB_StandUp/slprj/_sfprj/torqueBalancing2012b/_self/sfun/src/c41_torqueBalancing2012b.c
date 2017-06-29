/* Include files */

#include <stddef.h>
#include "blas.h"
#include "torqueBalancing2012b_sfun.h"
#include "c41_torqueBalancing2012b.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "torqueBalancing2012b_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c41_debug_family_names[10] = { "nargin", "nargout", "t",
  "t_switch", "first_xCom", "xCoMDes", "dxCoMDes", "ddxCoMDes", "fixedComBench",
  "Comrefs" };

/* Function Declarations */
static void initialize_c41_torqueBalancing2012b
  (SFc41_torqueBalancing2012bInstanceStruct *chartInstance);
static void initialize_params_c41_torqueBalancing2012b
  (SFc41_torqueBalancing2012bInstanceStruct *chartInstance);
static void enable_c41_torqueBalancing2012b
  (SFc41_torqueBalancing2012bInstanceStruct *chartInstance);
static void disable_c41_torqueBalancing2012b
  (SFc41_torqueBalancing2012bInstanceStruct *chartInstance);
static void c41_update_debugger_state_c41_torqueBalancing2012b
  (SFc41_torqueBalancing2012bInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c41_torqueBalancing2012b
  (SFc41_torqueBalancing2012bInstanceStruct *chartInstance);
static void set_sim_state_c41_torqueBalancing2012b
  (SFc41_torqueBalancing2012bInstanceStruct *chartInstance, const mxArray
   *c41_st);
static void finalize_c41_torqueBalancing2012b
  (SFc41_torqueBalancing2012bInstanceStruct *chartInstance);
static void sf_c41_torqueBalancing2012b(SFc41_torqueBalancing2012bInstanceStruct
  *chartInstance);
static void initSimStructsc41_torqueBalancing2012b
  (SFc41_torqueBalancing2012bInstanceStruct *chartInstance);
static void registerMessagesc41_torqueBalancing2012b
  (SFc41_torqueBalancing2012bInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c41_machineNumber, uint32_T
  c41_chartNumber);
static const mxArray *c41_sf_marshallOut(void *chartInstanceVoid, void
  *c41_inData);
static void c41_emlrt_marshallIn(SFc41_torqueBalancing2012bInstanceStruct
  *chartInstance, const mxArray *c41_Comrefs, const char_T *c41_identifier,
  real_T c41_y[9]);
static void c41_b_emlrt_marshallIn(SFc41_torqueBalancing2012bInstanceStruct
  *chartInstance, const mxArray *c41_u, const emlrtMsgIdentifier *c41_parentId,
  real_T c41_y[9]);
static void c41_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c41_mxArrayInData, const char_T *c41_varName, void *c41_outData);
static const mxArray *c41_b_sf_marshallOut(void *chartInstanceVoid, void
  *c41_inData);
static const mxArray *c41_c_sf_marshallOut(void *chartInstanceVoid, void
  *c41_inData);
static const mxArray *c41_d_sf_marshallOut(void *chartInstanceVoid, void
  *c41_inData);
static real_T c41_c_emlrt_marshallIn(SFc41_torqueBalancing2012bInstanceStruct
  *chartInstance, const mxArray *c41_u, const emlrtMsgIdentifier *c41_parentId);
static void c41_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c41_mxArrayInData, const char_T *c41_varName, void *c41_outData);
static const mxArray *c41_e_sf_marshallOut(void *chartInstanceVoid, void
  *c41_inData);
static int32_T c41_d_emlrt_marshallIn(SFc41_torqueBalancing2012bInstanceStruct
  *chartInstance, const mxArray *c41_u, const emlrtMsgIdentifier *c41_parentId);
static void c41_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c41_mxArrayInData, const char_T *c41_varName, void *c41_outData);
static uint8_T c41_e_emlrt_marshallIn(SFc41_torqueBalancing2012bInstanceStruct
  *chartInstance, const mxArray *c41_b_is_active_c41_torqueBalancing2012b, const
  char_T *c41_identifier);
static uint8_T c41_f_emlrt_marshallIn(SFc41_torqueBalancing2012bInstanceStruct
  *chartInstance, const mxArray *c41_u, const emlrtMsgIdentifier *c41_parentId);
static void init_dsm_address_info(SFc41_torqueBalancing2012bInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c41_torqueBalancing2012b
  (SFc41_torqueBalancing2012bInstanceStruct *chartInstance)
{
  chartInstance->c41_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c41_is_active_c41_torqueBalancing2012b = 0U;
}

static void initialize_params_c41_torqueBalancing2012b
  (SFc41_torqueBalancing2012bInstanceStruct *chartInstance)
{
}

static void enable_c41_torqueBalancing2012b
  (SFc41_torqueBalancing2012bInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c41_torqueBalancing2012b
  (SFc41_torqueBalancing2012bInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c41_update_debugger_state_c41_torqueBalancing2012b
  (SFc41_torqueBalancing2012bInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c41_torqueBalancing2012b
  (SFc41_torqueBalancing2012bInstanceStruct *chartInstance)
{
  const mxArray *c41_st;
  const mxArray *c41_y = NULL;
  int32_T c41_i0;
  real_T c41_u[9];
  const mxArray *c41_b_y = NULL;
  uint8_T c41_hoistedGlobal;
  uint8_T c41_b_u;
  const mxArray *c41_c_y = NULL;
  real_T (*c41_Comrefs)[9];
  c41_Comrefs = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c41_st = NULL;
  c41_st = NULL;
  c41_y = NULL;
  sf_mex_assign(&c41_y, sf_mex_createcellarray(2), FALSE);
  for (c41_i0 = 0; c41_i0 < 9; c41_i0++) {
    c41_u[c41_i0] = (*c41_Comrefs)[c41_i0];
  }

  c41_b_y = NULL;
  sf_mex_assign(&c41_b_y, sf_mex_create("y", c41_u, 0, 0U, 1U, 0U, 1, 9), FALSE);
  sf_mex_setcell(c41_y, 0, c41_b_y);
  c41_hoistedGlobal = chartInstance->c41_is_active_c41_torqueBalancing2012b;
  c41_b_u = c41_hoistedGlobal;
  c41_c_y = NULL;
  sf_mex_assign(&c41_c_y, sf_mex_create("y", &c41_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c41_y, 1, c41_c_y);
  sf_mex_assign(&c41_st, c41_y, FALSE);
  return c41_st;
}

static void set_sim_state_c41_torqueBalancing2012b
  (SFc41_torqueBalancing2012bInstanceStruct *chartInstance, const mxArray
   *c41_st)
{
  const mxArray *c41_u;
  real_T c41_dv0[9];
  int32_T c41_i1;
  real_T (*c41_Comrefs)[9];
  c41_Comrefs = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c41_doneDoubleBufferReInit = TRUE;
  c41_u = sf_mex_dup(c41_st);
  c41_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c41_u, 0)),
                       "Comrefs", c41_dv0);
  for (c41_i1 = 0; c41_i1 < 9; c41_i1++) {
    (*c41_Comrefs)[c41_i1] = c41_dv0[c41_i1];
  }

  chartInstance->c41_is_active_c41_torqueBalancing2012b = c41_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c41_u, 1)),
     "is_active_c41_torqueBalancing2012b");
  sf_mex_destroy(&c41_u);
  c41_update_debugger_state_c41_torqueBalancing2012b(chartInstance);
  sf_mex_destroy(&c41_st);
}

static void finalize_c41_torqueBalancing2012b
  (SFc41_torqueBalancing2012bInstanceStruct *chartInstance)
{
}

static void sf_c41_torqueBalancing2012b(SFc41_torqueBalancing2012bInstanceStruct
  *chartInstance)
{
  int32_T c41_i2;
  int32_T c41_i3;
  int32_T c41_i4;
  int32_T c41_i5;
  int32_T c41_i6;
  real_T c41_hoistedGlobal;
  real_T c41_b_hoistedGlobal;
  boolean_T c41_c_hoistedGlobal;
  real_T c41_t;
  real_T c41_t_switch;
  int32_T c41_i7;
  real_T c41_first_xCom[3];
  int32_T c41_i8;
  real_T c41_xCoMDes[3];
  int32_T c41_i9;
  real_T c41_dxCoMDes[3];
  int32_T c41_i10;
  real_T c41_ddxCoMDes[3];
  boolean_T c41_fixedComBench;
  uint32_T c41_debug_family_var_map[10];
  real_T c41_nargin = 7.0;
  real_T c41_nargout = 1.0;
  real_T c41_Comrefs[9];
  int32_T c41_i11;
  int32_T c41_i12;
  int32_T c41_i13;
  int32_T c41_i14;
  int32_T c41_i15;
  int32_T c41_i16;
  int32_T c41_i17;
  int32_T c41_i18;
  int32_T c41_i19;
  int32_T c41_i20;
  real_T *c41_b_t;
  real_T *c41_b_t_switch;
  boolean_T *c41_b_fixedComBench;
  real_T (*c41_b_Comrefs)[9];
  real_T (*c41_b_ddxCoMDes)[3];
  real_T (*c41_b_dxCoMDes)[3];
  real_T (*c41_b_xCoMDes)[3];
  real_T (*c41_b_first_xCom)[3];
  c41_b_fixedComBench = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c41_b_ddxCoMDes = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 5);
  c41_b_dxCoMDes = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 4);
  c41_b_xCoMDes = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 3);
  c41_b_first_xCom = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 2);
  c41_b_Comrefs = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c41_b_t_switch = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c41_b_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 40U, chartInstance->c41_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c41_b_t, 0U);
  _SFD_DATA_RANGE_CHECK(*c41_b_t_switch, 1U);
  for (c41_i2 = 0; c41_i2 < 9; c41_i2++) {
    _SFD_DATA_RANGE_CHECK((*c41_b_Comrefs)[c41_i2], 2U);
  }

  for (c41_i3 = 0; c41_i3 < 3; c41_i3++) {
    _SFD_DATA_RANGE_CHECK((*c41_b_first_xCom)[c41_i3], 3U);
  }

  for (c41_i4 = 0; c41_i4 < 3; c41_i4++) {
    _SFD_DATA_RANGE_CHECK((*c41_b_xCoMDes)[c41_i4], 4U);
  }

  for (c41_i5 = 0; c41_i5 < 3; c41_i5++) {
    _SFD_DATA_RANGE_CHECK((*c41_b_dxCoMDes)[c41_i5], 5U);
  }

  for (c41_i6 = 0; c41_i6 < 3; c41_i6++) {
    _SFD_DATA_RANGE_CHECK((*c41_b_ddxCoMDes)[c41_i6], 6U);
  }

  _SFD_DATA_RANGE_CHECK((real_T)*c41_b_fixedComBench, 7U);
  chartInstance->c41_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 40U, chartInstance->c41_sfEvent);
  c41_hoistedGlobal = *c41_b_t;
  c41_b_hoistedGlobal = *c41_b_t_switch;
  c41_c_hoistedGlobal = *c41_b_fixedComBench;
  c41_t = c41_hoistedGlobal;
  c41_t_switch = c41_b_hoistedGlobal;
  for (c41_i7 = 0; c41_i7 < 3; c41_i7++) {
    c41_first_xCom[c41_i7] = (*c41_b_first_xCom)[c41_i7];
  }

  for (c41_i8 = 0; c41_i8 < 3; c41_i8++) {
    c41_xCoMDes[c41_i8] = (*c41_b_xCoMDes)[c41_i8];
  }

  for (c41_i9 = 0; c41_i9 < 3; c41_i9++) {
    c41_dxCoMDes[c41_i9] = (*c41_b_dxCoMDes)[c41_i9];
  }

  for (c41_i10 = 0; c41_i10 < 3; c41_i10++) {
    c41_ddxCoMDes[c41_i10] = (*c41_b_ddxCoMDes)[c41_i10];
  }

  c41_fixedComBench = c41_c_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 10U, 10U, c41_debug_family_names,
    c41_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c41_nargin, 0U, c41_d_sf_marshallOut,
    c41_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c41_nargout, 1U, c41_d_sf_marshallOut,
    c41_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c41_t, 2U, c41_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c41_t_switch, 3U, c41_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c41_first_xCom, 4U, c41_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c41_xCoMDes, 5U, c41_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c41_dxCoMDes, 6U, c41_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c41_ddxCoMDes, 7U, c41_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c41_fixedComBench, 8U, c41_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c41_Comrefs, 9U, c41_sf_marshallOut,
    c41_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c41_sfEvent, 4);
  if (CV_EML_IF(0, 1, 0, c41_fixedComBench)) {
    _SFD_EML_CALL(0U, chartInstance->c41_sfEvent, 6);
    if (CV_EML_IF(0, 1, 1, c41_t <= c41_t_switch)) {
      _SFD_EML_CALL(0U, chartInstance->c41_sfEvent, 7);
      for (c41_i11 = 0; c41_i11 < 3; c41_i11++) {
        c41_Comrefs[c41_i11] = c41_first_xCom[c41_i11];
      }

      for (c41_i12 = 0; c41_i12 < 3; c41_i12++) {
        c41_Comrefs[c41_i12 + 3] = c41_dxCoMDes[c41_i12];
      }

      for (c41_i13 = 0; c41_i13 < 3; c41_i13++) {
        c41_Comrefs[c41_i13 + 6] = c41_ddxCoMDes[c41_i13];
      }
    } else {
      _SFD_EML_CALL(0U, chartInstance->c41_sfEvent, 9);
      for (c41_i14 = 0; c41_i14 < 3; c41_i14++) {
        c41_Comrefs[c41_i14] = c41_xCoMDes[c41_i14];
      }

      for (c41_i15 = 0; c41_i15 < 3; c41_i15++) {
        c41_Comrefs[c41_i15 + 3] = c41_dxCoMDes[c41_i15];
      }

      for (c41_i16 = 0; c41_i16 < 3; c41_i16++) {
        c41_Comrefs[c41_i16 + 6] = c41_ddxCoMDes[c41_i16];
      }
    }
  } else {
    _SFD_EML_CALL(0U, chartInstance->c41_sfEvent, 13);
    for (c41_i17 = 0; c41_i17 < 3; c41_i17++) {
      c41_Comrefs[c41_i17] = c41_xCoMDes[c41_i17];
    }

    for (c41_i18 = 0; c41_i18 < 3; c41_i18++) {
      c41_Comrefs[c41_i18 + 3] = c41_dxCoMDes[c41_i18];
    }

    for (c41_i19 = 0; c41_i19 < 3; c41_i19++) {
      c41_Comrefs[c41_i19 + 6] = c41_ddxCoMDes[c41_i19];
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c41_sfEvent, -13);
  _SFD_SYMBOL_SCOPE_POP();
  for (c41_i20 = 0; c41_i20 < 9; c41_i20++) {
    (*c41_b_Comrefs)[c41_i20] = c41_Comrefs[c41_i20];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 40U, chartInstance->c41_sfEvent);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_torqueBalancing2012bMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc41_torqueBalancing2012b
  (SFc41_torqueBalancing2012bInstanceStruct *chartInstance)
{
}

static void registerMessagesc41_torqueBalancing2012b
  (SFc41_torqueBalancing2012bInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c41_machineNumber, uint32_T
  c41_chartNumber)
{
}

static const mxArray *c41_sf_marshallOut(void *chartInstanceVoid, void
  *c41_inData)
{
  const mxArray *c41_mxArrayOutData = NULL;
  int32_T c41_i21;
  real_T c41_b_inData[9];
  int32_T c41_i22;
  real_T c41_u[9];
  const mxArray *c41_y = NULL;
  SFc41_torqueBalancing2012bInstanceStruct *chartInstance;
  chartInstance = (SFc41_torqueBalancing2012bInstanceStruct *)chartInstanceVoid;
  c41_mxArrayOutData = NULL;
  for (c41_i21 = 0; c41_i21 < 9; c41_i21++) {
    c41_b_inData[c41_i21] = (*(real_T (*)[9])c41_inData)[c41_i21];
  }

  for (c41_i22 = 0; c41_i22 < 9; c41_i22++) {
    c41_u[c41_i22] = c41_b_inData[c41_i22];
  }

  c41_y = NULL;
  sf_mex_assign(&c41_y, sf_mex_create("y", c41_u, 0, 0U, 1U, 0U, 1, 9), FALSE);
  sf_mex_assign(&c41_mxArrayOutData, c41_y, FALSE);
  return c41_mxArrayOutData;
}

static void c41_emlrt_marshallIn(SFc41_torqueBalancing2012bInstanceStruct
  *chartInstance, const mxArray *c41_Comrefs, const char_T *c41_identifier,
  real_T c41_y[9])
{
  emlrtMsgIdentifier c41_thisId;
  c41_thisId.fIdentifier = c41_identifier;
  c41_thisId.fParent = NULL;
  c41_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c41_Comrefs), &c41_thisId,
    c41_y);
  sf_mex_destroy(&c41_Comrefs);
}

static void c41_b_emlrt_marshallIn(SFc41_torqueBalancing2012bInstanceStruct
  *chartInstance, const mxArray *c41_u, const emlrtMsgIdentifier *c41_parentId,
  real_T c41_y[9])
{
  real_T c41_dv1[9];
  int32_T c41_i23;
  sf_mex_import(c41_parentId, sf_mex_dup(c41_u), c41_dv1, 1, 0, 0U, 1, 0U, 1, 9);
  for (c41_i23 = 0; c41_i23 < 9; c41_i23++) {
    c41_y[c41_i23] = c41_dv1[c41_i23];
  }

  sf_mex_destroy(&c41_u);
}

static void c41_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c41_mxArrayInData, const char_T *c41_varName, void *c41_outData)
{
  const mxArray *c41_Comrefs;
  const char_T *c41_identifier;
  emlrtMsgIdentifier c41_thisId;
  real_T c41_y[9];
  int32_T c41_i24;
  SFc41_torqueBalancing2012bInstanceStruct *chartInstance;
  chartInstance = (SFc41_torqueBalancing2012bInstanceStruct *)chartInstanceVoid;
  c41_Comrefs = sf_mex_dup(c41_mxArrayInData);
  c41_identifier = c41_varName;
  c41_thisId.fIdentifier = c41_identifier;
  c41_thisId.fParent = NULL;
  c41_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c41_Comrefs), &c41_thisId,
    c41_y);
  sf_mex_destroy(&c41_Comrefs);
  for (c41_i24 = 0; c41_i24 < 9; c41_i24++) {
    (*(real_T (*)[9])c41_outData)[c41_i24] = c41_y[c41_i24];
  }

  sf_mex_destroy(&c41_mxArrayInData);
}

static const mxArray *c41_b_sf_marshallOut(void *chartInstanceVoid, void
  *c41_inData)
{
  const mxArray *c41_mxArrayOutData = NULL;
  boolean_T c41_u;
  const mxArray *c41_y = NULL;
  SFc41_torqueBalancing2012bInstanceStruct *chartInstance;
  chartInstance = (SFc41_torqueBalancing2012bInstanceStruct *)chartInstanceVoid;
  c41_mxArrayOutData = NULL;
  c41_u = *(boolean_T *)c41_inData;
  c41_y = NULL;
  sf_mex_assign(&c41_y, sf_mex_create("y", &c41_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c41_mxArrayOutData, c41_y, FALSE);
  return c41_mxArrayOutData;
}

static const mxArray *c41_c_sf_marshallOut(void *chartInstanceVoid, void
  *c41_inData)
{
  const mxArray *c41_mxArrayOutData = NULL;
  int32_T c41_i25;
  real_T c41_b_inData[3];
  int32_T c41_i26;
  real_T c41_u[3];
  const mxArray *c41_y = NULL;
  SFc41_torqueBalancing2012bInstanceStruct *chartInstance;
  chartInstance = (SFc41_torqueBalancing2012bInstanceStruct *)chartInstanceVoid;
  c41_mxArrayOutData = NULL;
  for (c41_i25 = 0; c41_i25 < 3; c41_i25++) {
    c41_b_inData[c41_i25] = (*(real_T (*)[3])c41_inData)[c41_i25];
  }

  for (c41_i26 = 0; c41_i26 < 3; c41_i26++) {
    c41_u[c41_i26] = c41_b_inData[c41_i26];
  }

  c41_y = NULL;
  sf_mex_assign(&c41_y, sf_mex_create("y", c41_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c41_mxArrayOutData, c41_y, FALSE);
  return c41_mxArrayOutData;
}

static const mxArray *c41_d_sf_marshallOut(void *chartInstanceVoid, void
  *c41_inData)
{
  const mxArray *c41_mxArrayOutData = NULL;
  real_T c41_u;
  const mxArray *c41_y = NULL;
  SFc41_torqueBalancing2012bInstanceStruct *chartInstance;
  chartInstance = (SFc41_torqueBalancing2012bInstanceStruct *)chartInstanceVoid;
  c41_mxArrayOutData = NULL;
  c41_u = *(real_T *)c41_inData;
  c41_y = NULL;
  sf_mex_assign(&c41_y, sf_mex_create("y", &c41_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c41_mxArrayOutData, c41_y, FALSE);
  return c41_mxArrayOutData;
}

static real_T c41_c_emlrt_marshallIn(SFc41_torqueBalancing2012bInstanceStruct
  *chartInstance, const mxArray *c41_u, const emlrtMsgIdentifier *c41_parentId)
{
  real_T c41_y;
  real_T c41_d0;
  sf_mex_import(c41_parentId, sf_mex_dup(c41_u), &c41_d0, 1, 0, 0U, 0, 0U, 0);
  c41_y = c41_d0;
  sf_mex_destroy(&c41_u);
  return c41_y;
}

static void c41_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c41_mxArrayInData, const char_T *c41_varName, void *c41_outData)
{
  const mxArray *c41_nargout;
  const char_T *c41_identifier;
  emlrtMsgIdentifier c41_thisId;
  real_T c41_y;
  SFc41_torqueBalancing2012bInstanceStruct *chartInstance;
  chartInstance = (SFc41_torqueBalancing2012bInstanceStruct *)chartInstanceVoid;
  c41_nargout = sf_mex_dup(c41_mxArrayInData);
  c41_identifier = c41_varName;
  c41_thisId.fIdentifier = c41_identifier;
  c41_thisId.fParent = NULL;
  c41_y = c41_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c41_nargout),
    &c41_thisId);
  sf_mex_destroy(&c41_nargout);
  *(real_T *)c41_outData = c41_y;
  sf_mex_destroy(&c41_mxArrayInData);
}

const mxArray *sf_c41_torqueBalancing2012b_get_eml_resolved_functions_info(void)
{
  const mxArray *c41_nameCaptureInfo = NULL;
  c41_nameCaptureInfo = NULL;
  sf_mex_assign(&c41_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), FALSE);
  return c41_nameCaptureInfo;
}

static const mxArray *c41_e_sf_marshallOut(void *chartInstanceVoid, void
  *c41_inData)
{
  const mxArray *c41_mxArrayOutData = NULL;
  int32_T c41_u;
  const mxArray *c41_y = NULL;
  SFc41_torqueBalancing2012bInstanceStruct *chartInstance;
  chartInstance = (SFc41_torqueBalancing2012bInstanceStruct *)chartInstanceVoid;
  c41_mxArrayOutData = NULL;
  c41_u = *(int32_T *)c41_inData;
  c41_y = NULL;
  sf_mex_assign(&c41_y, sf_mex_create("y", &c41_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c41_mxArrayOutData, c41_y, FALSE);
  return c41_mxArrayOutData;
}

static int32_T c41_d_emlrt_marshallIn(SFc41_torqueBalancing2012bInstanceStruct
  *chartInstance, const mxArray *c41_u, const emlrtMsgIdentifier *c41_parentId)
{
  int32_T c41_y;
  int32_T c41_i27;
  sf_mex_import(c41_parentId, sf_mex_dup(c41_u), &c41_i27, 1, 6, 0U, 0, 0U, 0);
  c41_y = c41_i27;
  sf_mex_destroy(&c41_u);
  return c41_y;
}

static void c41_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c41_mxArrayInData, const char_T *c41_varName, void *c41_outData)
{
  const mxArray *c41_b_sfEvent;
  const char_T *c41_identifier;
  emlrtMsgIdentifier c41_thisId;
  int32_T c41_y;
  SFc41_torqueBalancing2012bInstanceStruct *chartInstance;
  chartInstance = (SFc41_torqueBalancing2012bInstanceStruct *)chartInstanceVoid;
  c41_b_sfEvent = sf_mex_dup(c41_mxArrayInData);
  c41_identifier = c41_varName;
  c41_thisId.fIdentifier = c41_identifier;
  c41_thisId.fParent = NULL;
  c41_y = c41_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c41_b_sfEvent),
    &c41_thisId);
  sf_mex_destroy(&c41_b_sfEvent);
  *(int32_T *)c41_outData = c41_y;
  sf_mex_destroy(&c41_mxArrayInData);
}

static uint8_T c41_e_emlrt_marshallIn(SFc41_torqueBalancing2012bInstanceStruct
  *chartInstance, const mxArray *c41_b_is_active_c41_torqueBalancing2012b, const
  char_T *c41_identifier)
{
  uint8_T c41_y;
  emlrtMsgIdentifier c41_thisId;
  c41_thisId.fIdentifier = c41_identifier;
  c41_thisId.fParent = NULL;
  c41_y = c41_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c41_b_is_active_c41_torqueBalancing2012b), &c41_thisId);
  sf_mex_destroy(&c41_b_is_active_c41_torqueBalancing2012b);
  return c41_y;
}

static uint8_T c41_f_emlrt_marshallIn(SFc41_torqueBalancing2012bInstanceStruct
  *chartInstance, const mxArray *c41_u, const emlrtMsgIdentifier *c41_parentId)
{
  uint8_T c41_y;
  uint8_T c41_u0;
  sf_mex_import(c41_parentId, sf_mex_dup(c41_u), &c41_u0, 1, 3, 0U, 0, 0U, 0);
  c41_y = c41_u0;
  sf_mex_destroy(&c41_u);
  return c41_y;
}

static void init_dsm_address_info(SFc41_torqueBalancing2012bInstanceStruct
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

void sf_c41_torqueBalancing2012b_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(212758252U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2363110634U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2651000084U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3884822466U);
}

mxArray *sf_c41_torqueBalancing2012b_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("FXtbv0CrCH9ozO752HBrzC");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,7,3,dataFields);

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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
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
      pr[0] = (double)(3);
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
      pr[0] = (double)(3);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(9);
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

mxArray *sf_c41_torqueBalancing2012b_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c41_torqueBalancing2012b(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[8],T\"Comrefs\",},{M[8],M[0],T\"is_active_c41_torqueBalancing2012b\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c41_torqueBalancing2012b_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc41_torqueBalancing2012bInstanceStruct *chartInstance;
    chartInstance = (SFc41_torqueBalancing2012bInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _torqueBalancing2012bMachineNumber_,
           41,
           1,
           1,
           8,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"t");
          _SFD_SET_DATA_PROPS(1,1,1,0,"t_switch");
          _SFD_SET_DATA_PROPS(2,2,0,1,"Comrefs");
          _SFD_SET_DATA_PROPS(3,1,1,0,"first_xCom");
          _SFD_SET_DATA_PROPS(4,1,1,0,"xCoMDes");
          _SFD_SET_DATA_PROPS(5,1,1,0,"dxCoMDes");
          _SFD_SET_DATA_PROPS(6,1,1,0,"ddxCoMDes");
          _SFD_SET_DATA_PROPS(7,1,1,0,"fixedComBench");
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
        _SFD_CV_INIT_EML(0,1,1,2,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,633);
        _SFD_CV_INIT_EML_IF(0,1,0,99,116,279,358);
        _SFD_CV_INIT_EML_IF(0,1,1,144,159,215,276);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c41_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c41_d_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 9;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c41_sf_marshallOut,(MexInFcnForType)
            c41_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c41_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c41_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c41_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c41_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(7,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c41_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c41_t;
          real_T *c41_t_switch;
          boolean_T *c41_fixedComBench;
          real_T (*c41_Comrefs)[9];
          real_T (*c41_first_xCom)[3];
          real_T (*c41_xCoMDes)[3];
          real_T (*c41_dxCoMDes)[3];
          real_T (*c41_ddxCoMDes)[3];
          c41_fixedComBench = (boolean_T *)ssGetInputPortSignal(chartInstance->S,
            6);
          c41_ddxCoMDes = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S,
            5);
          c41_dxCoMDes = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 4);
          c41_xCoMDes = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 3);
          c41_first_xCom = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S,
            2);
          c41_Comrefs = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
          c41_t_switch = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c41_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c41_t);
          _SFD_SET_DATA_VALUE_PTR(1U, c41_t_switch);
          _SFD_SET_DATA_VALUE_PTR(2U, *c41_Comrefs);
          _SFD_SET_DATA_VALUE_PTR(3U, *c41_first_xCom);
          _SFD_SET_DATA_VALUE_PTR(4U, *c41_xCoMDes);
          _SFD_SET_DATA_VALUE_PTR(5U, *c41_dxCoMDes);
          _SFD_SET_DATA_VALUE_PTR(6U, *c41_ddxCoMDes);
          _SFD_SET_DATA_VALUE_PTR(7U, c41_fixedComBench);
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
  return "BCCBxrm1oC49MK4IxoOSNB";
}

static void sf_opaque_initialize_c41_torqueBalancing2012b(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc41_torqueBalancing2012bInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c41_torqueBalancing2012b
    ((SFc41_torqueBalancing2012bInstanceStruct*) chartInstanceVar);
  initialize_c41_torqueBalancing2012b((SFc41_torqueBalancing2012bInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c41_torqueBalancing2012b(void *chartInstanceVar)
{
  enable_c41_torqueBalancing2012b((SFc41_torqueBalancing2012bInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c41_torqueBalancing2012b(void *chartInstanceVar)
{
  disable_c41_torqueBalancing2012b((SFc41_torqueBalancing2012bInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c41_torqueBalancing2012b(void *chartInstanceVar)
{
  sf_c41_torqueBalancing2012b((SFc41_torqueBalancing2012bInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c41_torqueBalancing2012b
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c41_torqueBalancing2012b
    ((SFc41_torqueBalancing2012bInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c41_torqueBalancing2012b();/* state var info */
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

extern void sf_internal_set_sim_state_c41_torqueBalancing2012b(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c41_torqueBalancing2012b();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c41_torqueBalancing2012b
    ((SFc41_torqueBalancing2012bInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c41_torqueBalancing2012b(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c41_torqueBalancing2012b(S);
}

static void sf_opaque_set_sim_state_c41_torqueBalancing2012b(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c41_torqueBalancing2012b(S, st);
}

static void sf_opaque_terminate_c41_torqueBalancing2012b(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc41_torqueBalancing2012bInstanceStruct*) chartInstanceVar)
      ->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_torqueBalancing2012b_optimization_info();
    }

    finalize_c41_torqueBalancing2012b((SFc41_torqueBalancing2012bInstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc41_torqueBalancing2012b
    ((SFc41_torqueBalancing2012bInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c41_torqueBalancing2012b(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c41_torqueBalancing2012b
      ((SFc41_torqueBalancing2012bInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c41_torqueBalancing2012b(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_torqueBalancing2012b_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      41);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,41,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,41,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,41);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,41,7);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,41,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 7; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,41);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(724225286U));
  ssSetChecksum1(S,(3820392566U));
  ssSetChecksum2(S,(725999686U));
  ssSetChecksum3(S,(2075118770U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c41_torqueBalancing2012b(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c41_torqueBalancing2012b(SimStruct *S)
{
  SFc41_torqueBalancing2012bInstanceStruct *chartInstance;
  chartInstance = (SFc41_torqueBalancing2012bInstanceStruct *)utMalloc(sizeof
    (SFc41_torqueBalancing2012bInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc41_torqueBalancing2012bInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c41_torqueBalancing2012b;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c41_torqueBalancing2012b;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c41_torqueBalancing2012b;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c41_torqueBalancing2012b;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c41_torqueBalancing2012b;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c41_torqueBalancing2012b;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c41_torqueBalancing2012b;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c41_torqueBalancing2012b;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c41_torqueBalancing2012b;
  chartInstance->chartInfo.mdlStart = mdlStart_c41_torqueBalancing2012b;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c41_torqueBalancing2012b;
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

void c41_torqueBalancing2012b_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c41_torqueBalancing2012b(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c41_torqueBalancing2012b(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c41_torqueBalancing2012b(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c41_torqueBalancing2012b_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
