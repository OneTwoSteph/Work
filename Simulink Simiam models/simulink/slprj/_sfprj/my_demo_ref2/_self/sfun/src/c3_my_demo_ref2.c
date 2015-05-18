/* Include files */

#include "blascompat32.h"
#include "my_demo_ref2_sfun.h"
#include "c3_my_demo_ref2.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "my_demo_ref2_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c3_debug_family_names[13] = { "dmin", "xx", "yy", "d",
  "nargin", "nargout", "x", "y", "fpath", "x_g", "y_g", "stop", "i" };

/* Function Declarations */
static void initialize_c3_my_demo_ref2(SFc3_my_demo_ref2InstanceStruct
  *chartInstance);
static void initialize_params_c3_my_demo_ref2(SFc3_my_demo_ref2InstanceStruct
  *chartInstance);
static void enable_c3_my_demo_ref2(SFc3_my_demo_ref2InstanceStruct
  *chartInstance);
static void disable_c3_my_demo_ref2(SFc3_my_demo_ref2InstanceStruct
  *chartInstance);
static void c3_update_debugger_state_c3_my_demo_ref2
  (SFc3_my_demo_ref2InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c3_my_demo_ref2
  (SFc3_my_demo_ref2InstanceStruct *chartInstance);
static void set_sim_state_c3_my_demo_ref2(SFc3_my_demo_ref2InstanceStruct
  *chartInstance, const mxArray *c3_st);
static void finalize_c3_my_demo_ref2(SFc3_my_demo_ref2InstanceStruct
  *chartInstance);
static void sf_c3_my_demo_ref2(SFc3_my_demo_ref2InstanceStruct *chartInstance);
static void initSimStructsc3_my_demo_ref2(SFc3_my_demo_ref2InstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static real_T c3_emlrt_marshallIn(SFc3_my_demo_ref2InstanceStruct *chartInstance,
  const mxArray *c3_b_i, const char_T *c3_identifier);
static real_T c3_b_emlrt_marshallIn(SFc3_my_demo_ref2InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static real_T c3_c_emlrt_marshallIn(SFc3_my_demo_ref2InstanceStruct
  *chartInstance, const mxArray *c3_stop, const char_T *c3_identifier);
static real_T c3_d_emlrt_marshallIn(SFc3_my_demo_ref2InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_e_emlrt_marshallIn(SFc3_my_demo_ref2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[85]);
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static real_T c3_mpower(SFc3_my_demo_ref2InstanceStruct *chartInstance, real_T
  c3_a);
static void c3_eml_error(SFc3_my_demo_ref2InstanceStruct *chartInstance);
static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_f_emlrt_marshallIn(SFc3_my_demo_ref2InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static uint8_T c3_g_emlrt_marshallIn(SFc3_my_demo_ref2InstanceStruct
  *chartInstance, const mxArray *c3_b_is_active_c3_my_demo_ref2, const char_T
  *c3_identifier);
static uint8_T c3_h_emlrt_marshallIn(SFc3_my_demo_ref2InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void init_dsm_address_info(SFc3_my_demo_ref2InstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c3_my_demo_ref2(SFc3_my_demo_ref2InstanceStruct
  *chartInstance)
{
  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c3_i_not_empty = FALSE;
  chartInstance->c3_is_active_c3_my_demo_ref2 = 0U;
}

static void initialize_params_c3_my_demo_ref2(SFc3_my_demo_ref2InstanceStruct
  *chartInstance)
{
}

static void enable_c3_my_demo_ref2(SFc3_my_demo_ref2InstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c3_my_demo_ref2(SFc3_my_demo_ref2InstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c3_update_debugger_state_c3_my_demo_ref2
  (SFc3_my_demo_ref2InstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c3_my_demo_ref2
  (SFc3_my_demo_ref2InstanceStruct *chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  real_T c3_hoistedGlobal;
  real_T c3_u;
  const mxArray *c3_b_y = NULL;
  real_T c3_b_hoistedGlobal;
  real_T c3_b_u;
  const mxArray *c3_c_y = NULL;
  real_T c3_c_hoistedGlobal;
  real_T c3_c_u;
  const mxArray *c3_d_y = NULL;
  real_T c3_d_hoistedGlobal;
  real_T c3_d_u;
  const mxArray *c3_e_y = NULL;
  uint8_T c3_e_hoistedGlobal;
  uint8_T c3_e_u;
  const mxArray *c3_f_y = NULL;
  real_T *c3_stop;
  real_T *c3_x_g;
  real_T *c3_y_g;
  c3_stop = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c3_y_g = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_x_g = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellarray(5), FALSE);
  c3_hoistedGlobal = *c3_stop;
  c3_u = c3_hoistedGlobal;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_b_hoistedGlobal = *c3_x_g;
  c3_b_u = c3_b_hoistedGlobal;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 1, c3_c_y);
  c3_c_hoistedGlobal = *c3_y_g;
  c3_c_u = c3_c_hoistedGlobal;
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 2, c3_d_y);
  c3_d_hoistedGlobal = chartInstance->c3_i;
  c3_d_u = c3_d_hoistedGlobal;
  c3_e_y = NULL;
  if (!chartInstance->c3_i_not_empty) {
    sf_mex_assign(&c3_e_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c3_e_y, sf_mex_create("y", &c3_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c3_y, 3, c3_e_y);
  c3_e_hoistedGlobal = chartInstance->c3_is_active_c3_my_demo_ref2;
  c3_e_u = c3_e_hoistedGlobal;
  c3_f_y = NULL;
  sf_mex_assign(&c3_f_y, sf_mex_create("y", &c3_e_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 4, c3_f_y);
  sf_mex_assign(&c3_st, c3_y, FALSE);
  return c3_st;
}

static void set_sim_state_c3_my_demo_ref2(SFc3_my_demo_ref2InstanceStruct
  *chartInstance, const mxArray *c3_st)
{
  const mxArray *c3_u;
  real_T *c3_stop;
  real_T *c3_x_g;
  real_T *c3_y_g;
  c3_stop = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c3_y_g = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_x_g = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c3_doneDoubleBufferReInit = TRUE;
  c3_u = sf_mex_dup(c3_st);
  *c3_stop = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u,
    0)), "stop");
  *c3_x_g = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u,
    1)), "x_g");
  *c3_y_g = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u,
    2)), "y_g");
  chartInstance->c3_i = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 3)), "i");
  chartInstance->c3_is_active_c3_my_demo_ref2 = c3_g_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 4)),
     "is_active_c3_my_demo_ref2");
  sf_mex_destroy(&c3_u);
  c3_update_debugger_state_c3_my_demo_ref2(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void finalize_c3_my_demo_ref2(SFc3_my_demo_ref2InstanceStruct
  *chartInstance)
{
}

static void sf_c3_my_demo_ref2(SFc3_my_demo_ref2InstanceStruct *chartInstance)
{
  int32_T c3_i0;
  real_T c3_hoistedGlobal;
  real_T c3_b_hoistedGlobal;
  real_T c3_x;
  real_T c3_y;
  int32_T c3_i1;
  real_T c3_fpath[170];
  uint32_T c3_debug_family_var_map[13];
  real_T c3_dmin;
  real_T c3_xx[85];
  real_T c3_yy[85];
  real_T c3_d;
  real_T c3_nargin = 3.0;
  real_T c3_nargout = 3.0;
  real_T c3_x_g;
  real_T c3_y_g;
  real_T c3_stop;
  int32_T c3_i2;
  int32_T c3_i3;
  real_T c3_c_hoistedGlobal;
  real_T c3_d_hoistedGlobal;
  real_T c3_b_x;
  real_T c3_c_x;
  real_T *c3_b_x_g;
  real_T *c3_b_y_g;
  real_T *c3_d_x;
  real_T *c3_b_y;
  real_T *c3_b_stop;
  real_T (*c3_b_fpath)[170];
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  c3_b_stop = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c3_b_fpath = (real_T (*)[170])ssGetInputPortSignal(chartInstance->S, 2);
  c3_b_y = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c3_d_x = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c3_b_y_g = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_b_x_g = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c3_b_x_g, 0U);
  _SFD_DATA_RANGE_CHECK(*c3_b_y_g, 1U);
  _SFD_DATA_RANGE_CHECK(*c3_d_x, 2U);
  _SFD_DATA_RANGE_CHECK(*c3_b_y, 3U);
  for (c3_i0 = 0; c3_i0 < 170; c3_i0++) {
    _SFD_DATA_RANGE_CHECK((*c3_b_fpath)[c3_i0], 4U);
  }

  _SFD_DATA_RANGE_CHECK(*c3_b_stop, 5U);
  chartInstance->c3_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
  c3_hoistedGlobal = *c3_d_x;
  c3_b_hoistedGlobal = *c3_b_y;
  c3_x = c3_hoistedGlobal;
  c3_y = c3_b_hoistedGlobal;
  for (c3_i1 = 0; c3_i1 < 170; c3_i1++) {
    c3_fpath[c3_i1] = (*c3_b_fpath)[c3_i1];
  }

  sf_debug_symbol_scope_push_eml(0U, 13U, 13U, c3_debug_family_names,
    c3_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c3_dmin, 0U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c3_xx, 1U, c3_d_sf_marshallOut,
    c3_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c3_yy, 2U, c3_d_sf_marshallOut,
    c3_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_d, 3U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_nargin, 4U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_nargout, 5U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c3_x, 6U, c3_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_y, 7U, c3_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c3_fpath, 8U, c3_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c3_x_g, 9U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_y_g, 10U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_stop, 11U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c3_i, 12U,
    c3_sf_marshallOut, c3_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 6);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 7);
  if (CV_EML_IF(0, 1, 0, !chartInstance->c3_i_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 8);
    chartInstance->c3_i = 1.0;
    chartInstance->c3_i_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 12);
  c3_stop = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 13);
  c3_dmin = 0.2;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 26);
  for (c3_i2 = 0; c3_i2 < 85; c3_i2++) {
    c3_xx[c3_i2] = c3_fpath[c3_i2];
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 27);
  for (c3_i3 = 0; c3_i3 < 85; c3_i3++) {
    c3_yy[c3_i3] = c3_fpath[c3_i3 + 85];
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 29);
  c3_c_hoistedGlobal = chartInstance->c3_i;
  c3_d_hoistedGlobal = chartInstance->c3_i;
  c3_b_x = c3_mpower(chartInstance, c3_x - c3_xx[_SFD_EML_ARRAY_BOUNDS_CHECK(
    "xx", (int32_T)_SFD_INTEGER_CHECK("i", c3_c_hoistedGlobal), 1, 85, 1, 0) - 1])
    + c3_mpower(chartInstance, c3_y - c3_yy[_SFD_EML_ARRAY_BOUNDS_CHECK("yy",
    (int32_T)_SFD_INTEGER_CHECK("i", c3_d_hoistedGlobal), 1, 85, 1, 0) - 1]);
  c3_d = c3_b_x;
  if (c3_d < 0.0) {
    c3_eml_error(chartInstance);
  }

  c3_c_x = c3_d;
  c3_d = c3_c_x;
  c3_d = muDoubleScalarSqrt(c3_d);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 31);
  guard2 = FALSE;
  if (CV_EML_COND(0, 1, 0, c3_d < c3_dmin)) {
    if (CV_EML_COND(0, 1, 1, chartInstance->c3_i < 85.0)) {
      CV_EML_MCDC(0, 1, 0, TRUE);
      CV_EML_IF(0, 1, 1, TRUE);
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 32);
      chartInstance->c3_i++;
    } else {
      guard2 = TRUE;
    }
  } else {
    guard2 = TRUE;
  }

  if (guard2 == TRUE) {
    CV_EML_MCDC(0, 1, 0, FALSE);
    CV_EML_IF(0, 1, 1, FALSE);
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 36);
  c3_x_g = c3_xx[_SFD_EML_ARRAY_BOUNDS_CHECK("xx", (int32_T)_SFD_INTEGER_CHECK(
    "i", chartInstance->c3_i), 1, 85, 1, 0) - 1];
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 37);
  c3_y_g = c3_yy[_SFD_EML_ARRAY_BOUNDS_CHECK("yy", (int32_T)_SFD_INTEGER_CHECK(
    "i", chartInstance->c3_i), 1, 85, 1, 0) - 1];
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 40);
  guard1 = FALSE;
  if (CV_EML_COND(0, 1, 2, c3_d < c3_dmin)) {
    if (CV_EML_COND(0, 1, 3, chartInstance->c3_i == 85.0)) {
      CV_EML_MCDC(0, 1, 1, TRUE);
      CV_EML_IF(0, 1, 2, TRUE);
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 41);
      c3_stop = 1.0;
    } else {
      guard1 = TRUE;
    }
  } else {
    guard1 = TRUE;
  }

  if (guard1 == TRUE) {
    CV_EML_MCDC(0, 1, 1, FALSE);
    CV_EML_IF(0, 1, 2, FALSE);
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -41);
  sf_debug_symbol_scope_pop();
  *c3_b_x_g = c3_x_g;
  *c3_b_y_g = c3_y_g;
  *c3_b_stop = c3_stop;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
  sf_debug_check_for_state_inconsistency(_my_demo_ref2MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc3_my_demo_ref2(SFc3_my_demo_ref2InstanceStruct
  *chartInstance)
{
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber)
{
}

static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_my_demo_ref2InstanceStruct *chartInstance;
  chartInstance = (SFc3_my_demo_ref2InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  if (!chartInstance->c3_i_not_empty) {
    sf_mex_assign(&c3_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static real_T c3_emlrt_marshallIn(SFc3_my_demo_ref2InstanceStruct *chartInstance,
  const mxArray *c3_b_i, const char_T *c3_identifier)
{
  real_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_i), &c3_thisId);
  sf_mex_destroy(&c3_b_i);
  return c3_y;
}

static real_T c3_b_emlrt_marshallIn(SFc3_my_demo_ref2InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d0;
  if (mxIsEmpty(c3_u)) {
    chartInstance->c3_i_not_empty = FALSE;
  } else {
    chartInstance->c3_i_not_empty = TRUE;
    sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d0, 1, 0, 0U, 0, 0U, 0);
    c3_y = c3_d0;
  }

  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_i;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_my_demo_ref2InstanceStruct *chartInstance;
  chartInstance = (SFc3_my_demo_ref2InstanceStruct *)chartInstanceVoid;
  c3_b_i = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_i), &c3_thisId);
  sf_mex_destroy(&c3_b_i);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_my_demo_ref2InstanceStruct *chartInstance;
  chartInstance = (SFc3_my_demo_ref2InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static real_T c3_c_emlrt_marshallIn(SFc3_my_demo_ref2InstanceStruct
  *chartInstance, const mxArray *c3_stop, const char_T *c3_identifier)
{
  real_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_stop), &c3_thisId);
  sf_mex_destroy(&c3_stop);
  return c3_y;
}

static real_T c3_d_emlrt_marshallIn(SFc3_my_demo_ref2InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d1;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d1, 1, 0, 0U, 0, 0U, 0);
  c3_y = c3_d1;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_stop;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_my_demo_ref2InstanceStruct *chartInstance;
  chartInstance = (SFc3_my_demo_ref2InstanceStruct *)chartInstanceVoid;
  c3_stop = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_stop), &c3_thisId);
  sf_mex_destroy(&c3_stop);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i4;
  int32_T c3_i5;
  int32_T c3_i6;
  real_T c3_b_inData[170];
  int32_T c3_i7;
  int32_T c3_i8;
  int32_T c3_i9;
  real_T c3_u[170];
  const mxArray *c3_y = NULL;
  SFc3_my_demo_ref2InstanceStruct *chartInstance;
  chartInstance = (SFc3_my_demo_ref2InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_i4 = 0;
  for (c3_i5 = 0; c3_i5 < 2; c3_i5++) {
    for (c3_i6 = 0; c3_i6 < 85; c3_i6++) {
      c3_b_inData[c3_i6 + c3_i4] = (*(real_T (*)[170])c3_inData)[c3_i6 + c3_i4];
    }

    c3_i4 += 85;
  }

  c3_i7 = 0;
  for (c3_i8 = 0; c3_i8 < 2; c3_i8++) {
    for (c3_i9 = 0; c3_i9 < 85; c3_i9++) {
      c3_u[c3_i9 + c3_i7] = c3_b_inData[c3_i9 + c3_i7];
    }

    c3_i7 += 85;
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 85, 2), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i10;
  real_T c3_b_inData[85];
  int32_T c3_i11;
  real_T c3_u[85];
  const mxArray *c3_y = NULL;
  SFc3_my_demo_ref2InstanceStruct *chartInstance;
  chartInstance = (SFc3_my_demo_ref2InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i10 = 0; c3_i10 < 85; c3_i10++) {
    c3_b_inData[c3_i10] = (*(real_T (*)[85])c3_inData)[c3_i10];
  }

  for (c3_i11 = 0; c3_i11 < 85; c3_i11++) {
    c3_u[c3_i11] = c3_b_inData[c3_i11];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 85), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static void c3_e_emlrt_marshallIn(SFc3_my_demo_ref2InstanceStruct *chartInstance,
  const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_y[85])
{
  real_T c3_dv0[85];
  int32_T c3_i12;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv0, 1, 0, 0U, 1, 0U, 1, 85);
  for (c3_i12 = 0; c3_i12 < 85; c3_i12++) {
    c3_y[c3_i12] = c3_dv0[c3_i12];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_yy;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[85];
  int32_T c3_i13;
  SFc3_my_demo_ref2InstanceStruct *chartInstance;
  chartInstance = (SFc3_my_demo_ref2InstanceStruct *)chartInstanceVoid;
  c3_yy = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_yy), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_yy);
  for (c3_i13 = 0; c3_i13 < 85; c3_i13++) {
    (*(real_T (*)[85])c3_outData)[c3_i13] = c3_y[c3_i13];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

const mxArray *sf_c3_my_demo_ref2_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo;
  c3_ResolvedFunctionInfo c3_info[10];
  c3_ResolvedFunctionInfo (*c3_b_info)[10];
  const mxArray *c3_m0 = NULL;
  int32_T c3_i14;
  c3_ResolvedFunctionInfo *c3_r0;
  c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  c3_b_info = (c3_ResolvedFunctionInfo (*)[10])c3_info;
  (*c3_b_info)[0].context = "";
  (*c3_b_info)[0].name = "mpower";
  (*c3_b_info)[0].dominantType = "double";
  (*c3_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  (*c3_b_info)[0].fileTimeLo = 1286822442U;
  (*c3_b_info)[0].fileTimeHi = 0U;
  (*c3_b_info)[0].mFileTimeLo = 0U;
  (*c3_b_info)[0].mFileTimeHi = 0U;
  (*c3_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  (*c3_b_info)[1].name = "power";
  (*c3_b_info)[1].dominantType = "double";
  (*c3_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  (*c3_b_info)[1].fileTimeLo = 1336525696U;
  (*c3_b_info)[1].fileTimeHi = 0U;
  (*c3_b_info)[1].mFileTimeLo = 0U;
  (*c3_b_info)[1].mFileTimeHi = 0U;
  (*c3_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  (*c3_b_info)[2].name = "eml_scalar_eg";
  (*c3_b_info)[2].dominantType = "double";
  (*c3_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  (*c3_b_info)[2].fileTimeLo = 1286822396U;
  (*c3_b_info)[2].fileTimeHi = 0U;
  (*c3_b_info)[2].mFileTimeLo = 0U;
  (*c3_b_info)[2].mFileTimeHi = 0U;
  (*c3_b_info)[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  (*c3_b_info)[3].name = "eml_scalexp_alloc";
  (*c3_b_info)[3].dominantType = "double";
  (*c3_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  (*c3_b_info)[3].fileTimeLo = 1330612034U;
  (*c3_b_info)[3].fileTimeHi = 0U;
  (*c3_b_info)[3].mFileTimeLo = 0U;
  (*c3_b_info)[3].mFileTimeHi = 0U;
  (*c3_b_info)[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  (*c3_b_info)[4].name = "floor";
  (*c3_b_info)[4].dominantType = "double";
  (*c3_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  (*c3_b_info)[4].fileTimeLo = 1286822342U;
  (*c3_b_info)[4].fileTimeHi = 0U;
  (*c3_b_info)[4].mFileTimeLo = 0U;
  (*c3_b_info)[4].mFileTimeHi = 0U;
  (*c3_b_info)[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  (*c3_b_info)[5].name = "eml_scalar_floor";
  (*c3_b_info)[5].dominantType = "double";
  (*c3_b_info)[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  (*c3_b_info)[5].fileTimeLo = 1286822326U;
  (*c3_b_info)[5].fileTimeHi = 0U;
  (*c3_b_info)[5].mFileTimeLo = 0U;
  (*c3_b_info)[5].mFileTimeHi = 0U;
  (*c3_b_info)[6].context = "";
  (*c3_b_info)[6].name = "sqrt";
  (*c3_b_info)[6].dominantType = "double";
  (*c3_b_info)[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  (*c3_b_info)[6].fileTimeLo = 1286822352U;
  (*c3_b_info)[6].fileTimeHi = 0U;
  (*c3_b_info)[6].mFileTimeLo = 0U;
  (*c3_b_info)[6].mFileTimeHi = 0U;
  (*c3_b_info)[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  (*c3_b_info)[7].name = "eml_error";
  (*c3_b_info)[7].dominantType = "char";
  (*c3_b_info)[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  (*c3_b_info)[7].fileTimeLo = 1305321600U;
  (*c3_b_info)[7].fileTimeHi = 0U;
  (*c3_b_info)[7].mFileTimeLo = 0U;
  (*c3_b_info)[7].mFileTimeHi = 0U;
  (*c3_b_info)[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  (*c3_b_info)[8].name = "eml_scalar_sqrt";
  (*c3_b_info)[8].dominantType = "double";
  (*c3_b_info)[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  (*c3_b_info)[8].fileTimeLo = 1286822338U;
  (*c3_b_info)[8].fileTimeHi = 0U;
  (*c3_b_info)[8].mFileTimeLo = 0U;
  (*c3_b_info)[8].mFileTimeHi = 0U;
  (*c3_b_info)[9].context = "";
  (*c3_b_info)[9].name = "length";
  (*c3_b_info)[9].dominantType = "double";
  (*c3_b_info)[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  (*c3_b_info)[9].fileTimeLo = 1303149806U;
  (*c3_b_info)[9].fileTimeHi = 0U;
  (*c3_b_info)[9].mFileTimeLo = 0U;
  (*c3_b_info)[9].mFileTimeHi = 0U;
  sf_mex_assign(&c3_m0, sf_mex_createstruct("nameCaptureInfo", 1, 10), FALSE);
  for (c3_i14 = 0; c3_i14 < 10; c3_i14++) {
    c3_r0 = &c3_info[c3_i14];
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->context)), "context", "nameCaptureInfo",
                    c3_i14);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c3_r0->name)), "name", "nameCaptureInfo", c3_i14);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c3_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c3_i14);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->resolved)), "resolved", "nameCaptureInfo",
                    c3_i14);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c3_i14);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c3_i14);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c3_i14);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c3_i14);
  }

  sf_mex_assign(&c3_nameCaptureInfo, c3_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c3_nameCaptureInfo);
  return c3_nameCaptureInfo;
}

static real_T c3_mpower(SFc3_my_demo_ref2InstanceStruct *chartInstance, real_T
  c3_a)
{
  real_T c3_b_a;
  real_T c3_c_a;
  real_T c3_ak;
  c3_b_a = c3_a;
  c3_c_a = c3_b_a;
  c3_ak = c3_c_a;
  return muDoubleScalarPower(c3_ak, 2.0);
}

static void c3_eml_error(SFc3_my_demo_ref2InstanceStruct *chartInstance)
{
  int32_T c3_i15;
  static char_T c3_varargin_1[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o',
    'o', 'l', 'b', 'o', 'x', ':', 's', 'q', 'r', 't', '_', 'd', 'o', 'm', 'a',
    'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c3_u[30];
  const mxArray *c3_y = NULL;
  for (c3_i15 = 0; c3_i15 < 30; c3_i15++) {
    c3_u[c3_i15] = c3_varargin_1[c3_i15];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 30), FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U, 14,
    c3_y));
}

static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_my_demo_ref2InstanceStruct *chartInstance;
  chartInstance = (SFc3_my_demo_ref2InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static int32_T c3_f_emlrt_marshallIn(SFc3_my_demo_ref2InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i16;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i16, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i16;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_sfEvent;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y;
  SFc3_my_demo_ref2InstanceStruct *chartInstance;
  chartInstance = (SFc3_my_demo_ref2InstanceStruct *)chartInstanceVoid;
  c3_b_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent),
    &c3_thisId);
  sf_mex_destroy(&c3_b_sfEvent);
  *(int32_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static uint8_T c3_g_emlrt_marshallIn(SFc3_my_demo_ref2InstanceStruct
  *chartInstance, const mxArray *c3_b_is_active_c3_my_demo_ref2, const char_T
  *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_is_active_c3_my_demo_ref2), &c3_thisId);
  sf_mex_destroy(&c3_b_is_active_c3_my_demo_ref2);
  return c3_y;
}

static uint8_T c3_h_emlrt_marshallIn(SFc3_my_demo_ref2InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_y;
  uint8_T c3_u0;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u0, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_u0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void init_dsm_address_info(SFc3_my_demo_ref2InstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c3_my_demo_ref2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(325293242U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1668007245U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3447724680U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2862718068U);
}

mxArray *sf_c3_my_demo_ref2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("1gLlcZsnbcKBmqSK0sOg0F");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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
      pr[0] = (double)(85);
      pr[1] = (double)(2);
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

static const mxArray *sf_get_sim_state_info_c3_my_demo_ref2(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[15],T\"stop\",},{M[1],M[11],T\"x_g\",},{M[1],M[12],T\"y_g\",},{M[4],M[0],T\"i\",S'l','i','p'{{M1x2[235 236],M[0],}}},{M[8],M[0],T\"is_active_c3_my_demo_ref2\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_my_demo_ref2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_my_demo_ref2InstanceStruct *chartInstance;
    chartInstance = (SFc3_my_demo_ref2InstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_my_demo_ref2MachineNumber_,
           3,
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
          init_script_number_translation(_my_demo_ref2MachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_my_demo_ref2MachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_my_demo_ref2MachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,2,0,1,"x_g");
          _SFD_SET_DATA_PROPS(1,2,0,1,"y_g");
          _SFD_SET_DATA_PROPS(2,1,1,0,"x");
          _SFD_SET_DATA_PROPS(3,1,1,0,"y");
          _SFD_SET_DATA_PROPS(4,1,1,0,"fpath");
          _SFD_SET_DATA_PROPS(5,2,0,1,"stop");
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
        _SFD_CV_INIT_EML(0,1,1,3,0,0,0,0,0,4,2);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,840);
        _SFD_CV_INIT_EML_IF(0,1,0,237,250,-1,264);
        _SFD_CV_INIT_EML_IF(0,1,1,641,672,-1,691);
        _SFD_CV_INIT_EML_IF(0,1,2,787,817,-1,835);

        {
          static int condStart[] = { 644, 656 };

          static int condEnd[] = { 652, 672 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,644,672,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 790, 802 };

          static int condEnd[] = { 798, 817 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,1,790,817,2,2,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 85;
          dimVector[1]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)c3_b_sf_marshallIn);

        {
          real_T *c3_x_g;
          real_T *c3_y_g;
          real_T *c3_x;
          real_T *c3_y;
          real_T *c3_stop;
          real_T (*c3_fpath)[170];
          c3_stop = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c3_fpath = (real_T (*)[170])ssGetInputPortSignal(chartInstance->S, 2);
          c3_y = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c3_x = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c3_y_g = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c3_x_g = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c3_x_g);
          _SFD_SET_DATA_VALUE_PTR(1U, c3_y_g);
          _SFD_SET_DATA_VALUE_PTR(2U, c3_x);
          _SFD_SET_DATA_VALUE_PTR(3U, c3_y);
          _SFD_SET_DATA_VALUE_PTR(4U, *c3_fpath);
          _SFD_SET_DATA_VALUE_PTR(5U, c3_stop);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_my_demo_ref2MachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization()
{
  return "UVFnI6gPkT9pMhQX3s99gB";
}

static void sf_opaque_initialize_c3_my_demo_ref2(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc3_my_demo_ref2InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c3_my_demo_ref2((SFc3_my_demo_ref2InstanceStruct*)
    chartInstanceVar);
  initialize_c3_my_demo_ref2((SFc3_my_demo_ref2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c3_my_demo_ref2(void *chartInstanceVar)
{
  enable_c3_my_demo_ref2((SFc3_my_demo_ref2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c3_my_demo_ref2(void *chartInstanceVar)
{
  disable_c3_my_demo_ref2((SFc3_my_demo_ref2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c3_my_demo_ref2(void *chartInstanceVar)
{
  sf_c3_my_demo_ref2((SFc3_my_demo_ref2InstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c3_my_demo_ref2(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c3_my_demo_ref2
    ((SFc3_my_demo_ref2InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_my_demo_ref2();/* state var info */
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

extern void sf_internal_set_sim_state_c3_my_demo_ref2(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_my_demo_ref2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c3_my_demo_ref2((SFc3_my_demo_ref2InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c3_my_demo_ref2(SimStruct* S)
{
  return sf_internal_get_sim_state_c3_my_demo_ref2(S);
}

static void sf_opaque_set_sim_state_c3_my_demo_ref2(SimStruct* S, const mxArray *
  st)
{
  sf_internal_set_sim_state_c3_my_demo_ref2(S, st);
}

static void sf_opaque_terminate_c3_my_demo_ref2(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_my_demo_ref2InstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c3_my_demo_ref2((SFc3_my_demo_ref2InstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_my_demo_ref2_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_my_demo_ref2((SFc3_my_demo_ref2InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_my_demo_ref2(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c3_my_demo_ref2((SFc3_my_demo_ref2InstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c3_my_demo_ref2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_my_demo_ref2_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,3,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,3,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,3,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,3,3);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(272749283U));
  ssSetChecksum1(S,(3721087561U));
  ssSetChecksum2(S,(1664616546U));
  ssSetChecksum3(S,(798998811U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c3_my_demo_ref2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c3_my_demo_ref2(SimStruct *S)
{
  SFc3_my_demo_ref2InstanceStruct *chartInstance;
  chartInstance = (SFc3_my_demo_ref2InstanceStruct *)malloc(sizeof
    (SFc3_my_demo_ref2InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc3_my_demo_ref2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c3_my_demo_ref2;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c3_my_demo_ref2;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c3_my_demo_ref2;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_my_demo_ref2;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c3_my_demo_ref2;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c3_my_demo_ref2;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c3_my_demo_ref2;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c3_my_demo_ref2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_my_demo_ref2;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_my_demo_ref2;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c3_my_demo_ref2;
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

void c3_my_demo_ref2_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_my_demo_ref2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_my_demo_ref2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_my_demo_ref2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_my_demo_ref2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
