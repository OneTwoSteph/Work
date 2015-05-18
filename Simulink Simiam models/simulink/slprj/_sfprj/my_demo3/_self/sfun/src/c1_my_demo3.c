/* Include files */

#include "blascompat32.h"
#include "my_demo3_sfun.h"
#include "c1_my_demo3.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "my_demo3_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c1_debug_family_names[14] = { "Kp", "Ki", "Kd", "dt",
  "derivative", "nargin", "nargout", "e", "e_theta", "prev_error",
  "prev_integral", "v", "error", "integral" };

/* Function Declarations */
static void initialize_c1_my_demo3(SFc1_my_demo3InstanceStruct *chartInstance);
static void initialize_params_c1_my_demo3(SFc1_my_demo3InstanceStruct
  *chartInstance);
static void enable_c1_my_demo3(SFc1_my_demo3InstanceStruct *chartInstance);
static void disable_c1_my_demo3(SFc1_my_demo3InstanceStruct *chartInstance);
static void c1_update_debugger_state_c1_my_demo3(SFc1_my_demo3InstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c1_my_demo3(SFc1_my_demo3InstanceStruct
  *chartInstance);
static void set_sim_state_c1_my_demo3(SFc1_my_demo3InstanceStruct *chartInstance,
  const mxArray *c1_st);
static void finalize_c1_my_demo3(SFc1_my_demo3InstanceStruct *chartInstance);
static void sf_c1_my_demo3(SFc1_my_demo3InstanceStruct *chartInstance);
static void initSimStructsc1_my_demo3(SFc1_my_demo3InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static real_T c1_emlrt_marshallIn(SFc1_my_demo3InstanceStruct *chartInstance,
  const mxArray *c1_integral, const char_T *c1_identifier);
static real_T c1_b_emlrt_marshallIn(SFc1_my_demo3InstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[15]);
static real_T c1_mpower(SFc1_my_demo3InstanceStruct *chartInstance, real_T c1_a);
static void c1_eml_error(SFc1_my_demo3InstanceStruct *chartInstance);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_c_emlrt_marshallIn(SFc1_my_demo3InstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint8_T c1_d_emlrt_marshallIn(SFc1_my_demo3InstanceStruct *chartInstance,
  const mxArray *c1_b_is_active_c1_my_demo3, const char_T *c1_identifier);
static uint8_T c1_e_emlrt_marshallIn(SFc1_my_demo3InstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void init_dsm_address_info(SFc1_my_demo3InstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c1_my_demo3(SFc1_my_demo3InstanceStruct *chartInstance)
{
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_is_active_c1_my_demo3 = 0U;
}

static void initialize_params_c1_my_demo3(SFc1_my_demo3InstanceStruct
  *chartInstance)
{
}

static void enable_c1_my_demo3(SFc1_my_demo3InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_my_demo3(SFc1_my_demo3InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c1_update_debugger_state_c1_my_demo3(SFc1_my_demo3InstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c1_my_demo3(SFc1_my_demo3InstanceStruct
  *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  real_T c1_hoistedGlobal;
  real_T c1_u;
  const mxArray *c1_b_y = NULL;
  real_T c1_b_hoistedGlobal;
  real_T c1_b_u;
  const mxArray *c1_c_y = NULL;
  real_T c1_c_hoistedGlobal;
  real_T c1_c_u;
  const mxArray *c1_d_y = NULL;
  uint8_T c1_d_hoistedGlobal;
  uint8_T c1_d_u;
  const mxArray *c1_e_y = NULL;
  real_T *c1_error;
  real_T *c1_integral;
  real_T *c1_v;
  c1_integral = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_error = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_v = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(4), FALSE);
  c1_hoistedGlobal = *c1_error;
  c1_u = c1_hoistedGlobal;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_b_hoistedGlobal = *c1_integral;
  c1_b_u = c1_b_hoistedGlobal;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  c1_c_hoistedGlobal = *c1_v;
  c1_c_u = c1_c_hoistedGlobal;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 2, c1_d_y);
  c1_d_hoistedGlobal = chartInstance->c1_is_active_c1_my_demo3;
  c1_d_u = c1_d_hoistedGlobal;
  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", &c1_d_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 3, c1_e_y);
  sf_mex_assign(&c1_st, c1_y, FALSE);
  return c1_st;
}

static void set_sim_state_c1_my_demo3(SFc1_my_demo3InstanceStruct *chartInstance,
  const mxArray *c1_st)
{
  const mxArray *c1_u;
  real_T *c1_error;
  real_T *c1_integral;
  real_T *c1_v;
  c1_integral = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_error = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_v = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c1_doneDoubleBufferReInit = TRUE;
  c1_u = sf_mex_dup(c1_st);
  *c1_error = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    0)), "error");
  *c1_integral = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 1)), "integral");
  *c1_v = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 2)),
    "v");
  chartInstance->c1_is_active_c1_my_demo3 = c1_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 3)), "is_active_c1_my_demo3");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_my_demo3(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_my_demo3(SFc1_my_demo3InstanceStruct *chartInstance)
{
}

static void sf_c1_my_demo3(SFc1_my_demo3InstanceStruct *chartInstance)
{
  int32_T c1_i0;
  real_T c1_hoistedGlobal;
  real_T c1_b_hoistedGlobal;
  real_T c1_c_hoistedGlobal;
  int32_T c1_i1;
  real_T c1_e[2];
  real_T c1_e_theta;
  real_T c1_prev_error;
  real_T c1_prev_integral;
  uint32_T c1_debug_family_var_map[14];
  real_T c1_Kp;
  real_T c1_Ki;
  real_T c1_Kd;
  real_T c1_dt;
  real_T c1_derivative;
  real_T c1_nargin = 4.0;
  real_T c1_nargout = 3.0;
  real_T c1_v;
  real_T c1_error;
  real_T c1_integral;
  real_T c1_x;
  real_T c1_b_x;
  real_T c1_c_x;
  real_T c1_d_x;
  real_T c1_a;
  real_T c1_b;
  real_T c1_b_a;
  real_T c1_y;
  real_T c1_A;
  real_T c1_e_x;
  real_T c1_f_x;
  real_T c1_b_b;
  real_T c1_b_y;
  real_T c1_c_b;
  real_T c1_c_y;
  real_T c1_d_b;
  real_T c1_d_y;
  real_T *c1_b_integral;
  real_T *c1_b_error;
  real_T *c1_b_v;
  real_T *c1_b_prev_integral;
  real_T *c1_b_prev_error;
  real_T *c1_b_e_theta;
  real_T (*c1_b_e)[2];
  c1_b_prev_integral = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c1_b_integral = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_b_error = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_b_prev_error = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c1_b_e_theta = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_b_v = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_b_e = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  for (c1_i0 = 0; c1_i0 < 2; c1_i0++) {
    _SFD_DATA_RANGE_CHECK((*c1_b_e)[c1_i0], 0U);
  }

  _SFD_DATA_RANGE_CHECK(*c1_b_v, 1U);
  _SFD_DATA_RANGE_CHECK(*c1_b_e_theta, 2U);
  _SFD_DATA_RANGE_CHECK(*c1_b_prev_error, 3U);
  _SFD_DATA_RANGE_CHECK(*c1_b_error, 4U);
  _SFD_DATA_RANGE_CHECK(*c1_b_integral, 5U);
  _SFD_DATA_RANGE_CHECK(*c1_b_prev_integral, 6U);
  chartInstance->c1_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  c1_hoistedGlobal = *c1_b_e_theta;
  c1_b_hoistedGlobal = *c1_b_prev_error;
  c1_c_hoistedGlobal = *c1_b_prev_integral;
  for (c1_i1 = 0; c1_i1 < 2; c1_i1++) {
    c1_e[c1_i1] = (*c1_b_e)[c1_i1];
  }

  c1_e_theta = c1_hoistedGlobal;
  c1_prev_error = c1_b_hoistedGlobal;
  c1_prev_integral = c1_c_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 14U, 14U, c1_debug_family_names,
    c1_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c1_Kp, 0U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_Ki, 1U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_Kd, 2U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_dt, 3U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c1_derivative, 4U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargin, 5U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargout, 6U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c1_e, 7U, c1_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_e_theta, 8U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_prev_error, 9U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_prev_integral, 10U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c1_v, 11U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_error, 12U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_integral, 13U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 3);
  c1_Kp = 10.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_Ki = 1.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 5);
  c1_Kd = 0.1;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 6);
  c1_dt = 0.033;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_x = c1_mpower(chartInstance, c1_e[0]) + c1_mpower(chartInstance, c1_e[1]);
  c1_b_x = c1_x;
  if (c1_b_x < 0.0) {
    c1_eml_error(chartInstance);
  }

  c1_b_x = muDoubleScalarSqrt(c1_b_x);
  c1_c_x = c1_e_theta;
  c1_d_x = c1_c_x;
  c1_d_x = muDoubleScalarCos(c1_d_x);
  c1_a = c1_b_x;
  c1_b = c1_d_x;
  c1_error = c1_a * c1_b;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 9);
  c1_b_a = c1_error;
  c1_y = c1_b_a * 0.033;
  c1_integral = c1_prev_integral + c1_y;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 10);
  c1_A = c1_error - c1_prev_error;
  c1_e_x = c1_A;
  c1_f_x = c1_e_x;
  c1_derivative = c1_f_x / 0.033;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 11);
  c1_b_b = c1_error;
  c1_b_y = 10.0 * c1_b_b;
  c1_c_b = c1_integral;
  c1_c_y = c1_c_b;
  c1_d_b = c1_derivative;
  c1_d_y = 0.1 * c1_d_b;
  c1_v = (c1_b_y + c1_c_y) + c1_d_y;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -11);
  sf_debug_symbol_scope_pop();
  *c1_b_v = c1_v;
  *c1_b_error = c1_error;
  *c1_b_integral = c1_integral;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  sf_debug_check_for_state_inconsistency(_my_demo3MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc1_my_demo3(SFc1_my_demo3InstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_my_demo3InstanceStruct *chartInstance;
  chartInstance = (SFc1_my_demo3InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static real_T c1_emlrt_marshallIn(SFc1_my_demo3InstanceStruct *chartInstance,
  const mxArray *c1_integral, const char_T *c1_identifier)
{
  real_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_integral),
    &c1_thisId);
  sf_mex_destroy(&c1_integral);
  return c1_y;
}

static real_T c1_b_emlrt_marshallIn(SFc1_my_demo3InstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d0, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_integral;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_my_demo3InstanceStruct *chartInstance;
  chartInstance = (SFc1_my_demo3InstanceStruct *)chartInstanceVoid;
  c1_integral = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_integral),
    &c1_thisId);
  sf_mex_destroy(&c1_integral);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i2;
  real_T c1_b_inData[2];
  int32_T c1_i3;
  real_T c1_u[2];
  const mxArray *c1_y = NULL;
  SFc1_my_demo3InstanceStruct *chartInstance;
  chartInstance = (SFc1_my_demo3InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i2 = 0; c1_i2 < 2; c1_i2++) {
    c1_b_inData[c1_i2] = (*(real_T (*)[2])c1_inData)[c1_i2];
  }

  for (c1_i3 = 0; c1_i3 < 2; c1_i3++) {
    c1_u[c1_i3] = c1_b_inData[c1_i3];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 2, 1), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

const mxArray *sf_c1_my_demo3_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo;
  c1_ResolvedFunctionInfo c1_info[15];
  const mxArray *c1_m0 = NULL;
  int32_T c1_i4;
  c1_ResolvedFunctionInfo *c1_r0;
  c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  c1_info_helper(c1_info);
  sf_mex_assign(&c1_m0, sf_mex_createstruct("nameCaptureInfo", 1, 15), FALSE);
  for (c1_i4 = 0; c1_i4 < 15; c1_i4++) {
    c1_r0 = &c1_info[c1_i4];
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->context)), "context", "nameCaptureInfo",
                    c1_i4);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c1_r0->name)), "name", "nameCaptureInfo", c1_i4);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c1_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c1_i4);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->resolved)), "resolved", "nameCaptureInfo",
                    c1_i4);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c1_i4);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c1_i4);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c1_i4);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c1_i4);
  }

  sf_mex_assign(&c1_nameCaptureInfo, c1_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c1_nameCaptureInfo);
  return c1_nameCaptureInfo;
}

static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[15])
{
  c1_info[0].context = "";
  c1_info[0].name = "mpower";
  c1_info[0].dominantType = "double";
  c1_info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c1_info[0].fileTimeLo = 1286822442U;
  c1_info[0].fileTimeHi = 0U;
  c1_info[0].mFileTimeLo = 0U;
  c1_info[0].mFileTimeHi = 0U;
  c1_info[1].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c1_info[1].name = "power";
  c1_info[1].dominantType = "double";
  c1_info[1].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c1_info[1].fileTimeLo = 1336525696U;
  c1_info[1].fileTimeHi = 0U;
  c1_info[1].mFileTimeLo = 0U;
  c1_info[1].mFileTimeHi = 0U;
  c1_info[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c1_info[2].name = "eml_scalar_eg";
  c1_info[2].dominantType = "double";
  c1_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[2].fileTimeLo = 1286822396U;
  c1_info[2].fileTimeHi = 0U;
  c1_info[2].mFileTimeLo = 0U;
  c1_info[2].mFileTimeHi = 0U;
  c1_info[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c1_info[3].name = "eml_scalexp_alloc";
  c1_info[3].dominantType = "double";
  c1_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c1_info[3].fileTimeLo = 1330612034U;
  c1_info[3].fileTimeHi = 0U;
  c1_info[3].mFileTimeLo = 0U;
  c1_info[3].mFileTimeHi = 0U;
  c1_info[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c1_info[4].name = "floor";
  c1_info[4].dominantType = "double";
  c1_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c1_info[4].fileTimeLo = 1286822342U;
  c1_info[4].fileTimeHi = 0U;
  c1_info[4].mFileTimeLo = 0U;
  c1_info[4].mFileTimeHi = 0U;
  c1_info[5].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c1_info[5].name = "eml_scalar_floor";
  c1_info[5].dominantType = "double";
  c1_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c1_info[5].fileTimeLo = 1286822326U;
  c1_info[5].fileTimeHi = 0U;
  c1_info[5].mFileTimeLo = 0U;
  c1_info[5].mFileTimeHi = 0U;
  c1_info[6].context = "";
  c1_info[6].name = "sqrt";
  c1_info[6].dominantType = "double";
  c1_info[6].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c1_info[6].fileTimeLo = 1286822352U;
  c1_info[6].fileTimeHi = 0U;
  c1_info[6].mFileTimeLo = 0U;
  c1_info[6].mFileTimeHi = 0U;
  c1_info[7].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c1_info[7].name = "eml_error";
  c1_info[7].dominantType = "char";
  c1_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c1_info[7].fileTimeLo = 1305321600U;
  c1_info[7].fileTimeHi = 0U;
  c1_info[7].mFileTimeLo = 0U;
  c1_info[7].mFileTimeHi = 0U;
  c1_info[8].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c1_info[8].name = "eml_scalar_sqrt";
  c1_info[8].dominantType = "double";
  c1_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  c1_info[8].fileTimeLo = 1286822338U;
  c1_info[8].fileTimeHi = 0U;
  c1_info[8].mFileTimeLo = 0U;
  c1_info[8].mFileTimeHi = 0U;
  c1_info[9].context = "";
  c1_info[9].name = "cos";
  c1_info[9].dominantType = "double";
  c1_info[9].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c1_info[9].fileTimeLo = 1286822306U;
  c1_info[9].fileTimeHi = 0U;
  c1_info[9].mFileTimeLo = 0U;
  c1_info[9].mFileTimeHi = 0U;
  c1_info[10].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c1_info[10].name = "eml_scalar_cos";
  c1_info[10].dominantType = "double";
  c1_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c1_info[10].fileTimeLo = 1286822322U;
  c1_info[10].fileTimeHi = 0U;
  c1_info[10].mFileTimeLo = 0U;
  c1_info[10].mFileTimeHi = 0U;
  c1_info[11].context = "";
  c1_info[11].name = "mtimes";
  c1_info[11].dominantType = "double";
  c1_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[11].fileTimeLo = 1289523292U;
  c1_info[11].fileTimeHi = 0U;
  c1_info[11].mFileTimeLo = 0U;
  c1_info[11].mFileTimeHi = 0U;
  c1_info[12].context = "";
  c1_info[12].name = "mrdivide";
  c1_info[12].dominantType = "double";
  c1_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c1_info[12].fileTimeLo = 1342814544U;
  c1_info[12].fileTimeHi = 0U;
  c1_info[12].mFileTimeLo = 1319733566U;
  c1_info[12].mFileTimeHi = 0U;
  c1_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c1_info[13].name = "rdivide";
  c1_info[13].dominantType = "double";
  c1_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[13].fileTimeLo = 1286822444U;
  c1_info[13].fileTimeHi = 0U;
  c1_info[13].mFileTimeLo = 0U;
  c1_info[13].mFileTimeHi = 0U;
  c1_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[14].name = "eml_div";
  c1_info[14].dominantType = "double";
  c1_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c1_info[14].fileTimeLo = 1313351410U;
  c1_info[14].fileTimeHi = 0U;
  c1_info[14].mFileTimeLo = 0U;
  c1_info[14].mFileTimeHi = 0U;
}

static real_T c1_mpower(SFc1_my_demo3InstanceStruct *chartInstance, real_T c1_a)
{
  real_T c1_b_a;
  real_T c1_c_a;
  real_T c1_ak;
  c1_b_a = c1_a;
  c1_c_a = c1_b_a;
  c1_ak = c1_c_a;
  return muDoubleScalarPower(c1_ak, 2.0);
}

static void c1_eml_error(SFc1_my_demo3InstanceStruct *chartInstance)
{
  int32_T c1_i5;
  static char_T c1_varargin_1[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o',
    'o', 'l', 'b', 'o', 'x', ':', 's', 'q', 'r', 't', '_', 'd', 'o', 'm', 'a',
    'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c1_u[30];
  const mxArray *c1_y = NULL;
  for (c1_i5 = 0; c1_i5 < 30; c1_i5++) {
    c1_u[c1_i5] = c1_varargin_1[c1_i5];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 30), FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U, 14,
    c1_y));
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_my_demo3InstanceStruct *chartInstance;
  chartInstance = (SFc1_my_demo3InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static int32_T c1_c_emlrt_marshallIn(SFc1_my_demo3InstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i6;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i6, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i6;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_my_demo3InstanceStruct *chartInstance;
  chartInstance = (SFc1_my_demo3InstanceStruct *)chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static uint8_T c1_d_emlrt_marshallIn(SFc1_my_demo3InstanceStruct *chartInstance,
  const mxArray *c1_b_is_active_c1_my_demo3, const char_T *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_my_demo3), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_my_demo3);
  return c1_y;
}

static uint8_T c1_e_emlrt_marshallIn(SFc1_my_demo3InstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void init_dsm_address_info(SFc1_my_demo3InstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c1_my_demo3_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1164947887U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1547355822U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3812963944U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1312829358U);
}

mxArray *sf_c1_my_demo3_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("eEOblCd9LLIUm0NSM4GTb");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
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
      pr[0] = (double)(1);
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
      pr[0] = (double)(1);
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
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

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
      pr[0] = (double)(1);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c1_my_demo3(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[12],T\"error\",},{M[1],M[11],T\"integral\",},{M[1],M[5],T\"v\",},{M[8],M[0],T\"is_active_c1_my_demo3\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_my_demo3_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_my_demo3InstanceStruct *chartInstance;
    chartInstance = (SFc1_my_demo3InstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart(_my_demo3MachineNumber_,
          1,
          1,
          1,
          7,
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
          init_script_number_translation(_my_demo3MachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_my_demo3MachineNumber_,
            chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_my_demo3MachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"e");
          _SFD_SET_DATA_PROPS(1,2,0,1,"v");
          _SFD_SET_DATA_PROPS(2,1,1,0,"e_theta");
          _SFD_SET_DATA_PROPS(3,1,1,0,"prev_error");
          _SFD_SET_DATA_PROPS(4,2,0,1,"error");
          _SFD_SET_DATA_PROPS(5,2,0,1,"integral");
          _SFD_SET_DATA_PROPS(6,1,1,0,"prev_integral");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,283);
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
          dimVector[0]= 2;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c1_v;
          real_T *c1_e_theta;
          real_T *c1_prev_error;
          real_T *c1_error;
          real_T *c1_integral;
          real_T *c1_prev_integral;
          real_T (*c1_e)[2];
          c1_prev_integral = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c1_integral = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c1_error = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c1_prev_error = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c1_e_theta = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c1_v = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c1_e = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c1_e);
          _SFD_SET_DATA_VALUE_PTR(1U, c1_v);
          _SFD_SET_DATA_VALUE_PTR(2U, c1_e_theta);
          _SFD_SET_DATA_VALUE_PTR(3U, c1_prev_error);
          _SFD_SET_DATA_VALUE_PTR(4U, c1_error);
          _SFD_SET_DATA_VALUE_PTR(5U, c1_integral);
          _SFD_SET_DATA_VALUE_PTR(6U, c1_prev_integral);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_my_demo3MachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization()
{
  return "raKoxOR01nIuepXCpsVGUG";
}

static void sf_opaque_initialize_c1_my_demo3(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_my_demo3InstanceStruct*) chartInstanceVar)
    ->S,0);
  initialize_params_c1_my_demo3((SFc1_my_demo3InstanceStruct*) chartInstanceVar);
  initialize_c1_my_demo3((SFc1_my_demo3InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_my_demo3(void *chartInstanceVar)
{
  enable_c1_my_demo3((SFc1_my_demo3InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_my_demo3(void *chartInstanceVar)
{
  disable_c1_my_demo3((SFc1_my_demo3InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_my_demo3(void *chartInstanceVar)
{
  sf_c1_my_demo3((SFc1_my_demo3InstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_my_demo3(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_my_demo3((SFc1_my_demo3InstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_my_demo3();/* state var info */
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

extern void sf_internal_set_sim_state_c1_my_demo3(SimStruct* S, const mxArray
  *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_my_demo3();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_my_demo3((SFc1_my_demo3InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_my_demo3(SimStruct* S)
{
  return sf_internal_get_sim_state_c1_my_demo3(S);
}

static void sf_opaque_set_sim_state_c1_my_demo3(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c1_my_demo3(S, st);
}

static void sf_opaque_terminate_c1_my_demo3(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_my_demo3InstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c1_my_demo3((SFc1_my_demo3InstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_my_demo3_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_my_demo3((SFc1_my_demo3InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_my_demo3(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_my_demo3((SFc1_my_demo3InstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_my_demo3(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_my_demo3_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,1,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,4);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,3);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(4029860640U));
  ssSetChecksum1(S,(35268363U));
  ssSetChecksum2(S,(3856945910U));
  ssSetChecksum3(S,(1805992042U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_my_demo3(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_my_demo3(SimStruct *S)
{
  SFc1_my_demo3InstanceStruct *chartInstance;
  chartInstance = (SFc1_my_demo3InstanceStruct *)malloc(sizeof
    (SFc1_my_demo3InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_my_demo3InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c1_my_demo3;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c1_my_demo3;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c1_my_demo3;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_my_demo3;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_my_demo3;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c1_my_demo3;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c1_my_demo3;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c1_my_demo3;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_my_demo3;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_my_demo3;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c1_my_demo3;
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

void c1_my_demo3_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_my_demo3(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_my_demo3(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_my_demo3(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_my_demo3_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
