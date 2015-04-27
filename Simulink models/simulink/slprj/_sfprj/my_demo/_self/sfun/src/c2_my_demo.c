/* Include files */

#include "blascompat32.h"
#include "my_demo_sfun.h"
#include "c2_my_demo.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "my_demo_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c2_debug_family_names[13] = { "l", "mat", "R", "u_max", "a",
  "k1", "k2", "K", "nargin", "nargout", "e", "theta", "v" };

/* Function Declarations */
static void initialize_c2_my_demo(SFc2_my_demoInstanceStruct *chartInstance);
static void initialize_params_c2_my_demo(SFc2_my_demoInstanceStruct
  *chartInstance);
static void enable_c2_my_demo(SFc2_my_demoInstanceStruct *chartInstance);
static void disable_c2_my_demo(SFc2_my_demoInstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_my_demo(SFc2_my_demoInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c2_my_demo(SFc2_my_demoInstanceStruct
  *chartInstance);
static void set_sim_state_c2_my_demo(SFc2_my_demoInstanceStruct *chartInstance,
  const mxArray *c2_st);
static void finalize_c2_my_demo(SFc2_my_demoInstanceStruct *chartInstance);
static void sf_c2_my_demo(SFc2_my_demoInstanceStruct *chartInstance);
static void c2_chartstep_c2_my_demo(SFc2_my_demoInstanceStruct *chartInstance);
static void initSimStructsc2_my_demo(SFc2_my_demoInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static void c2_emlrt_marshallIn(SFc2_my_demoInstanceStruct *chartInstance, const
  mxArray *c2_v, const char_T *c2_identifier, real_T c2_y[2]);
static void c2_b_emlrt_marshallIn(SFc2_my_demoInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[2]);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_c_emlrt_marshallIn(SFc2_my_demoInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_d_emlrt_marshallIn(SFc2_my_demoInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[4]);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[26]);
static real_T c2_rdivide(SFc2_my_demoInstanceStruct *chartInstance, real_T c2_x,
  real_T c2_y);
static real_T c2_abs(SFc2_my_demoInstanceStruct *chartInstance, real_T c2_x);
static real_T c2_power(SFc2_my_demoInstanceStruct *chartInstance, real_T c2_a);
static void c2_eml_scalar_eg(SFc2_my_demoInstanceStruct *chartInstance);
static void c2_b_eml_scalar_eg(SFc2_my_demoInstanceStruct *chartInstance);
static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_e_emlrt_marshallIn(SFc2_my_demoInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_f_emlrt_marshallIn(SFc2_my_demoInstanceStruct *chartInstance,
  const mxArray *c2_b_is_active_c2_my_demo, const char_T *c2_identifier);
static uint8_T c2_g_emlrt_marshallIn(SFc2_my_demoInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void init_dsm_address_info(SFc2_my_demoInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c2_my_demo(SFc2_my_demoInstanceStruct *chartInstance)
{
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_is_active_c2_my_demo = 0U;
}

static void initialize_params_c2_my_demo(SFc2_my_demoInstanceStruct
  *chartInstance)
{
}

static void enable_c2_my_demo(SFc2_my_demoInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_my_demo(SFc2_my_demoInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_my_demo(SFc2_my_demoInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c2_my_demo(SFc2_my_demoInstanceStruct
  *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  int32_T c2_i0;
  real_T c2_u[2];
  const mxArray *c2_b_y = NULL;
  uint8_T c2_hoistedGlobal;
  uint8_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  real_T (*c2_v)[2];
  c2_v = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(2), FALSE);
  for (c2_i0 = 0; c2_i0 < 2; c2_i0++) {
    c2_u[c2_i0] = (*c2_v)[c2_i0];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 2), FALSE);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_hoistedGlobal = chartInstance->c2_is_active_c2_my_demo;
  c2_b_u = c2_hoistedGlobal;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  sf_mex_assign(&c2_st, c2_y, FALSE);
  return c2_st;
}

static void set_sim_state_c2_my_demo(SFc2_my_demoInstanceStruct *chartInstance,
  const mxArray *c2_st)
{
  const mxArray *c2_u;
  real_T c2_dv0[2];
  int32_T c2_i1;
  real_T (*c2_v)[2];
  c2_v = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 0)), "v",
                      c2_dv0);
  for (c2_i1 = 0; c2_i1 < 2; c2_i1++) {
    (*c2_v)[c2_i1] = c2_dv0[c2_i1];
  }

  chartInstance->c2_is_active_c2_my_demo = c2_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 1)), "is_active_c2_my_demo");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_my_demo(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_my_demo(SFc2_my_demoInstanceStruct *chartInstance)
{
}

static void sf_c2_my_demo(SFc2_my_demoInstanceStruct *chartInstance)
{
  int32_T c2_i2;
  int32_T c2_i3;
  real_T *c2_theta;
  real_T (*c2_v)[2];
  real_T (*c2_e)[2];
  c2_theta = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c2_v = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_e = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  for (c2_i2 = 0; c2_i2 < 2; c2_i2++) {
    _SFD_DATA_RANGE_CHECK((*c2_e)[c2_i2], 0U);
  }

  for (c2_i3 = 0; c2_i3 < 2; c2_i3++) {
    _SFD_DATA_RANGE_CHECK((*c2_v)[c2_i3], 1U);
  }

  _SFD_DATA_RANGE_CHECK(*c2_theta, 2U);
  chartInstance->c2_sfEvent = CALL_EVENT;
  c2_chartstep_c2_my_demo(chartInstance);
  sf_debug_check_for_state_inconsistency(_my_demoMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c2_chartstep_c2_my_demo(SFc2_my_demoInstanceStruct *chartInstance)
{
  real_T c2_hoistedGlobal;
  int32_T c2_i4;
  real_T c2_e[2];
  real_T c2_theta;
  uint32_T c2_debug_family_var_map[13];
  real_T c2_l;
  real_T c2_mat[4];
  real_T c2_R[4];
  real_T c2_u_max;
  real_T c2_a;
  real_T c2_k1;
  real_T c2_k2;
  real_T c2_K[4];
  real_T c2_nargin = 2.0;
  real_T c2_nargout = 1.0;
  real_T c2_v[2];
  int32_T c2_i5;
  static real_T c2_b_a[4] = { 1.0, 0.0, 0.0, 50.0 };

  real_T c2_x;
  real_T c2_b_x;
  real_T c2_c_x;
  real_T c2_d_x;
  real_T c2_e_x;
  real_T c2_f_x;
  real_T c2_g_x;
  real_T c2_h_x;
  real_T c2_i_x;
  real_T c2_j_x;
  real_T c2_k_x;
  real_T c2_l_x;
  real_T c2_b;
  real_T c2_y;
  real_T c2_m_x;
  real_T c2_n_x;
  real_T c2_o_x;
  real_T c2_p_x;
  real_T c2_b_b;
  real_T c2_b_y;
  int32_T c2_i6;
  real_T c2_c_b[4];
  int32_T c2_i7;
  int32_T c2_i8;
  int32_T c2_i9;
  real_T c2_c_y[4];
  int32_T c2_i10;
  int32_T c2_i11;
  int32_T c2_i12;
  int32_T c2_i13;
  int32_T c2_i14;
  int32_T c2_i15;
  real_T c2_d_y[4];
  int32_T c2_i16;
  int32_T c2_i17;
  int32_T c2_i18;
  real_T c2_d_b[2];
  int32_T c2_i19;
  int32_T c2_i20;
  int32_T c2_i21;
  real_T c2_C[2];
  int32_T c2_i22;
  int32_T c2_i23;
  int32_T c2_i24;
  int32_T c2_i25;
  int32_T c2_i26;
  int32_T c2_i27;
  int32_T c2_i28;
  real_T *c2_b_theta;
  real_T (*c2_b_v)[2];
  real_T (*c2_b_e)[2];
  c2_b_theta = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c2_b_v = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_b_e = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  c2_hoistedGlobal = *c2_b_theta;
  for (c2_i4 = 0; c2_i4 < 2; c2_i4++) {
    c2_e[c2_i4] = (*c2_b_e)[c2_i4];
  }

  c2_theta = c2_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 13U, 13U, c2_debug_family_names,
    c2_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c2_l, 0U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c2_mat, 1U, c2_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c2_R, 2U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c2_u_max, 3U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c2_a, 4U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_k1, 5U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_k2, 6U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_K, 7U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargin, 8U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargout, 9U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c2_e, 10U, c2_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_theta, 11U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c2_v, 12U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 3);
  c2_l = 0.02;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 4);
  for (c2_i5 = 0; c2_i5 < 4; c2_i5++) {
    c2_mat[c2_i5] = c2_b_a[c2_i5];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 5);
  c2_x = -c2_theta;
  c2_b_x = c2_x;
  c2_b_x = muDoubleScalarCos(c2_b_x);
  c2_c_x = -c2_theta;
  c2_d_x = c2_c_x;
  c2_d_x = muDoubleScalarSin(c2_d_x);
  c2_e_x = -c2_theta;
  c2_f_x = c2_e_x;
  c2_f_x = muDoubleScalarSin(c2_f_x);
  c2_g_x = -c2_theta;
  c2_h_x = c2_g_x;
  c2_h_x = muDoubleScalarCos(c2_h_x);
  c2_R[0] = c2_b_x;
  c2_R[2] = -c2_d_x;
  c2_R[1] = c2_f_x;
  c2_R[3] = c2_h_x;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 7);
  c2_u_max = 10.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 8);
  c2_a = 0.01;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 9);
  c2_i_x = c2_abs(chartInstance, c2_e[0]);
  c2_j_x = c2_i_x;
  c2_j_x = muDoubleScalarExp(c2_j_x);
  c2_k_x = -c2_a * c2_power(chartInstance, c2_e[0]);
  c2_l_x = c2_k_x;
  c2_l_x = muDoubleScalarExp(c2_l_x);
  c2_b = 1.0 - c2_l_x;
  c2_y = 10.0 * c2_b;
  c2_k1 = c2_rdivide(chartInstance, 1.0, c2_j_x) + c2_rdivide(chartInstance,
    c2_y, c2_abs(chartInstance, c2_e[0]));
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 10);
  c2_m_x = c2_abs(chartInstance, c2_e[1]);
  c2_n_x = c2_m_x;
  c2_n_x = muDoubleScalarExp(c2_n_x);
  c2_o_x = -c2_a * c2_power(chartInstance, c2_e[1]);
  c2_p_x = c2_o_x;
  c2_p_x = muDoubleScalarExp(c2_p_x);
  c2_b_b = 1.0 - c2_p_x;
  c2_b_y = 10.0 * c2_b_b;
  c2_k2 = c2_rdivide(chartInstance, 1.0, c2_n_x) + c2_rdivide(chartInstance,
    c2_b_y, c2_abs(chartInstance, c2_e[1]));
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 11);
  c2_K[0] = c2_k1;
  c2_K[2] = 0.0;
  c2_K[1] = 0.0;
  c2_K[3] = c2_k2;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 13);
  for (c2_i6 = 0; c2_i6 < 4; c2_i6++) {
    c2_c_b[c2_i6] = c2_R[c2_i6];
  }

  c2_eml_scalar_eg(chartInstance);
  c2_eml_scalar_eg(chartInstance);
  for (c2_i7 = 0; c2_i7 < 2; c2_i7++) {
    c2_i8 = 0;
    for (c2_i9 = 0; c2_i9 < 2; c2_i9++) {
      c2_c_y[c2_i8 + c2_i7] = 0.0;
      c2_i10 = 0;
      for (c2_i11 = 0; c2_i11 < 2; c2_i11++) {
        c2_c_y[c2_i8 + c2_i7] += c2_b_a[c2_i10 + c2_i7] * c2_c_b[c2_i11 + c2_i8];
        c2_i10 += 2;
      }

      c2_i8 += 2;
    }
  }

  for (c2_i12 = 0; c2_i12 < 4; c2_i12++) {
    c2_c_b[c2_i12] = c2_K[c2_i12];
  }

  c2_eml_scalar_eg(chartInstance);
  c2_eml_scalar_eg(chartInstance);
  for (c2_i13 = 0; c2_i13 < 2; c2_i13++) {
    c2_i14 = 0;
    for (c2_i15 = 0; c2_i15 < 2; c2_i15++) {
      c2_d_y[c2_i14 + c2_i13] = 0.0;
      c2_i16 = 0;
      for (c2_i17 = 0; c2_i17 < 2; c2_i17++) {
        c2_d_y[c2_i14 + c2_i13] += c2_c_y[c2_i16 + c2_i13] * c2_c_b[c2_i17 +
          c2_i14];
        c2_i16 += 2;
      }

      c2_i14 += 2;
    }
  }

  for (c2_i18 = 0; c2_i18 < 2; c2_i18++) {
    c2_d_b[c2_i18] = c2_e[c2_i18];
  }

  c2_b_eml_scalar_eg(chartInstance);
  c2_b_eml_scalar_eg(chartInstance);
  for (c2_i19 = 0; c2_i19 < 2; c2_i19++) {
    c2_v[c2_i19] = 0.0;
  }

  for (c2_i20 = 0; c2_i20 < 2; c2_i20++) {
    c2_v[c2_i20] = 0.0;
  }

  for (c2_i21 = 0; c2_i21 < 2; c2_i21++) {
    c2_C[c2_i21] = c2_v[c2_i21];
  }

  for (c2_i22 = 0; c2_i22 < 2; c2_i22++) {
    c2_v[c2_i22] = c2_C[c2_i22];
  }

  for (c2_i23 = 0; c2_i23 < 2; c2_i23++) {
    c2_C[c2_i23] = c2_v[c2_i23];
  }

  for (c2_i24 = 0; c2_i24 < 2; c2_i24++) {
    c2_v[c2_i24] = c2_C[c2_i24];
  }

  for (c2_i25 = 0; c2_i25 < 2; c2_i25++) {
    c2_v[c2_i25] = 0.0;
    c2_i26 = 0;
    for (c2_i27 = 0; c2_i27 < 2; c2_i27++) {
      c2_v[c2_i25] += c2_d_y[c2_i26 + c2_i25] * c2_d_b[c2_i27];
      c2_i26 += 2;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -13);
  sf_debug_symbol_scope_pop();
  for (c2_i28 = 0; c2_i28 < 2; c2_i28++) {
    (*c2_b_v)[c2_i28] = c2_v[c2_i28];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
}

static void initSimStructsc2_my_demo(SFc2_my_demoInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i29;
  real_T c2_b_inData[2];
  int32_T c2_i30;
  real_T c2_u[2];
  const mxArray *c2_y = NULL;
  SFc2_my_demoInstanceStruct *chartInstance;
  chartInstance = (SFc2_my_demoInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i29 = 0; c2_i29 < 2; c2_i29++) {
    c2_b_inData[c2_i29] = (*(real_T (*)[2])c2_inData)[c2_i29];
  }

  for (c2_i30 = 0; c2_i30 < 2; c2_i30++) {
    c2_u[c2_i30] = c2_b_inData[c2_i30];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 2), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_emlrt_marshallIn(SFc2_my_demoInstanceStruct *chartInstance, const
  mxArray *c2_v, const char_T *c2_identifier, real_T c2_y[2])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_v), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_v);
}

static void c2_b_emlrt_marshallIn(SFc2_my_demoInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[2])
{
  real_T c2_dv1[2];
  int32_T c2_i31;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv1, 1, 0, 0U, 1, 0U, 1, 2);
  for (c2_i31 = 0; c2_i31 < 2; c2_i31++) {
    c2_y[c2_i31] = c2_dv1[c2_i31];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_v;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[2];
  int32_T c2_i32;
  SFc2_my_demoInstanceStruct *chartInstance;
  chartInstance = (SFc2_my_demoInstanceStruct *)chartInstanceVoid;
  c2_v = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_v), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_v);
  for (c2_i32 = 0; c2_i32 < 2; c2_i32++) {
    (*(real_T (*)[2])c2_outData)[c2_i32] = c2_y[c2_i32];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_my_demoInstanceStruct *chartInstance;
  chartInstance = (SFc2_my_demoInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i33;
  real_T c2_b_inData[2];
  int32_T c2_i34;
  real_T c2_u[2];
  const mxArray *c2_y = NULL;
  SFc2_my_demoInstanceStruct *chartInstance;
  chartInstance = (SFc2_my_demoInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i33 = 0; c2_i33 < 2; c2_i33++) {
    c2_b_inData[c2_i33] = (*(real_T (*)[2])c2_inData)[c2_i33];
  }

  for (c2_i34 = 0; c2_i34 < 2; c2_i34++) {
    c2_u[c2_i34] = c2_b_inData[c2_i34];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 2, 1), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_c_emlrt_marshallIn(SFc2_my_demoInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_nargout;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_my_demoInstanceStruct *chartInstance;
  chartInstance = (SFc2_my_demoInstanceStruct *)chartInstanceVoid;
  c2_nargout = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_nargout), &c2_thisId);
  sf_mex_destroy(&c2_nargout);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i35;
  int32_T c2_i36;
  int32_T c2_i37;
  real_T c2_b_inData[4];
  int32_T c2_i38;
  int32_T c2_i39;
  int32_T c2_i40;
  real_T c2_u[4];
  const mxArray *c2_y = NULL;
  SFc2_my_demoInstanceStruct *chartInstance;
  chartInstance = (SFc2_my_demoInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i35 = 0;
  for (c2_i36 = 0; c2_i36 < 2; c2_i36++) {
    for (c2_i37 = 0; c2_i37 < 2; c2_i37++) {
      c2_b_inData[c2_i37 + c2_i35] = (*(real_T (*)[4])c2_inData)[c2_i37 + c2_i35];
    }

    c2_i35 += 2;
  }

  c2_i38 = 0;
  for (c2_i39 = 0; c2_i39 < 2; c2_i39++) {
    for (c2_i40 = 0; c2_i40 < 2; c2_i40++) {
      c2_u[c2_i40 + c2_i38] = c2_b_inData[c2_i40 + c2_i38];
    }

    c2_i38 += 2;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 2, 2), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_d_emlrt_marshallIn(SFc2_my_demoInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[4])
{
  real_T c2_dv2[4];
  int32_T c2_i41;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv2, 1, 0, 0U, 1, 0U, 2, 2, 2);
  for (c2_i41 = 0; c2_i41 < 4; c2_i41++) {
    c2_y[c2_i41] = c2_dv2[c2_i41];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_K;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[4];
  int32_T c2_i42;
  int32_T c2_i43;
  int32_T c2_i44;
  SFc2_my_demoInstanceStruct *chartInstance;
  chartInstance = (SFc2_my_demoInstanceStruct *)chartInstanceVoid;
  c2_K = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_K), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_K);
  c2_i42 = 0;
  for (c2_i43 = 0; c2_i43 < 2; c2_i43++) {
    for (c2_i44 = 0; c2_i44 < 2; c2_i44++) {
      (*(real_T (*)[4])c2_outData)[c2_i44 + c2_i42] = c2_y[c2_i44 + c2_i42];
    }

    c2_i42 += 2;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray *sf_c2_my_demo_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo;
  c2_ResolvedFunctionInfo c2_info[26];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i45;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  c2_info_helper(c2_info);
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 26), FALSE);
  for (c2_i45 = 0; c2_i45 < 26; c2_i45++) {
    c2_r0 = &c2_info[c2_i45];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context", "nameCaptureInfo",
                    c2_i45);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name", "nameCaptureInfo", c2_i45);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c2_i45);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved", "nameCaptureInfo",
                    c2_i45);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c2_i45);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c2_i45);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c2_i45);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c2_i45);
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c2_nameCaptureInfo);
  return c2_nameCaptureInfo;
}

static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[26])
{
  c2_info[0].context = "";
  c2_info[0].name = "mrdivide";
  c2_info[0].dominantType = "double";
  c2_info[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[0].fileTimeLo = 1342814544U;
  c2_info[0].fileTimeHi = 0U;
  c2_info[0].mFileTimeLo = 1319733566U;
  c2_info[0].mFileTimeHi = 0U;
  c2_info[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[1].name = "rdivide";
  c2_info[1].dominantType = "double";
  c2_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[1].fileTimeLo = 1286822444U;
  c2_info[1].fileTimeHi = 0U;
  c2_info[1].mFileTimeLo = 0U;
  c2_info[1].mFileTimeHi = 0U;
  c2_info[2].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[2].name = "eml_div";
  c2_info[2].dominantType = "double";
  c2_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c2_info[2].fileTimeLo = 1313351410U;
  c2_info[2].fileTimeHi = 0U;
  c2_info[2].mFileTimeLo = 0U;
  c2_info[2].mFileTimeHi = 0U;
  c2_info[3].context = "";
  c2_info[3].name = "cos";
  c2_info[3].dominantType = "double";
  c2_info[3].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c2_info[3].fileTimeLo = 1286822306U;
  c2_info[3].fileTimeHi = 0U;
  c2_info[3].mFileTimeLo = 0U;
  c2_info[3].mFileTimeHi = 0U;
  c2_info[4].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c2_info[4].name = "eml_scalar_cos";
  c2_info[4].dominantType = "double";
  c2_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c2_info[4].fileTimeLo = 1286822322U;
  c2_info[4].fileTimeHi = 0U;
  c2_info[4].mFileTimeLo = 0U;
  c2_info[4].mFileTimeHi = 0U;
  c2_info[5].context = "";
  c2_info[5].name = "sin";
  c2_info[5].dominantType = "double";
  c2_info[5].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c2_info[5].fileTimeLo = 1286822350U;
  c2_info[5].fileTimeHi = 0U;
  c2_info[5].mFileTimeLo = 0U;
  c2_info[5].mFileTimeHi = 0U;
  c2_info[6].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c2_info[6].name = "eml_scalar_sin";
  c2_info[6].dominantType = "double";
  c2_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c2_info[6].fileTimeLo = 1286822336U;
  c2_info[6].fileTimeHi = 0U;
  c2_info[6].mFileTimeLo = 0U;
  c2_info[6].mFileTimeHi = 0U;
  c2_info[7].context = "";
  c2_info[7].name = "abs";
  c2_info[7].dominantType = "double";
  c2_info[7].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c2_info[7].fileTimeLo = 1286822294U;
  c2_info[7].fileTimeHi = 0U;
  c2_info[7].mFileTimeLo = 0U;
  c2_info[7].mFileTimeHi = 0U;
  c2_info[8].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c2_info[8].name = "eml_scalar_abs";
  c2_info[8].dominantType = "double";
  c2_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c2_info[8].fileTimeLo = 1286822312U;
  c2_info[8].fileTimeHi = 0U;
  c2_info[8].mFileTimeLo = 0U;
  c2_info[8].mFileTimeHi = 0U;
  c2_info[9].context = "";
  c2_info[9].name = "exp";
  c2_info[9].dominantType = "double";
  c2_info[9].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/exp.m";
  c2_info[9].fileTimeLo = 1286822340U;
  c2_info[9].fileTimeHi = 0U;
  c2_info[9].mFileTimeLo = 0U;
  c2_info[9].mFileTimeHi = 0U;
  c2_info[10].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/exp.m";
  c2_info[10].name = "eml_scalar_exp";
  c2_info[10].dominantType = "double";
  c2_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_exp.m";
  c2_info[10].fileTimeLo = 1301332064U;
  c2_info[10].fileTimeHi = 0U;
  c2_info[10].mFileTimeLo = 0U;
  c2_info[10].mFileTimeHi = 0U;
  c2_info[11].context = "";
  c2_info[11].name = "rdivide";
  c2_info[11].dominantType = "double";
  c2_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[11].fileTimeLo = 1286822444U;
  c2_info[11].fileTimeHi = 0U;
  c2_info[11].mFileTimeLo = 0U;
  c2_info[11].mFileTimeHi = 0U;
  c2_info[12].context = "";
  c2_info[12].name = "power";
  c2_info[12].dominantType = "double";
  c2_info[12].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[12].fileTimeLo = 1336525696U;
  c2_info[12].fileTimeHi = 0U;
  c2_info[12].mFileTimeLo = 0U;
  c2_info[12].mFileTimeHi = 0U;
  c2_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c2_info[13].name = "eml_scalar_eg";
  c2_info[13].dominantType = "double";
  c2_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[13].fileTimeLo = 1286822396U;
  c2_info[13].fileTimeHi = 0U;
  c2_info[13].mFileTimeLo = 0U;
  c2_info[13].mFileTimeHi = 0U;
  c2_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c2_info[14].name = "eml_scalexp_alloc";
  c2_info[14].dominantType = "double";
  c2_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c2_info[14].fileTimeLo = 1330612034U;
  c2_info[14].fileTimeHi = 0U;
  c2_info[14].mFileTimeLo = 0U;
  c2_info[14].mFileTimeHi = 0U;
  c2_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c2_info[15].name = "floor";
  c2_info[15].dominantType = "double";
  c2_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c2_info[15].fileTimeLo = 1286822342U;
  c2_info[15].fileTimeHi = 0U;
  c2_info[15].mFileTimeLo = 0U;
  c2_info[15].mFileTimeHi = 0U;
  c2_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c2_info[16].name = "eml_scalar_floor";
  c2_info[16].dominantType = "double";
  c2_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c2_info[16].fileTimeLo = 1286822326U;
  c2_info[16].fileTimeHi = 0U;
  c2_info[16].mFileTimeLo = 0U;
  c2_info[16].mFileTimeHi = 0U;
  c2_info[17].context = "";
  c2_info[17].name = "mtimes";
  c2_info[17].dominantType = "double";
  c2_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[17].fileTimeLo = 1289523292U;
  c2_info[17].fileTimeHi = 0U;
  c2_info[17].mFileTimeLo = 0U;
  c2_info[17].mFileTimeHi = 0U;
  c2_info[18].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[18].name = "eml_index_class";
  c2_info[18].dominantType = "";
  c2_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[18].fileTimeLo = 1323174178U;
  c2_info[18].fileTimeHi = 0U;
  c2_info[18].mFileTimeLo = 0U;
  c2_info[18].mFileTimeHi = 0U;
  c2_info[19].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[19].name = "eml_scalar_eg";
  c2_info[19].dominantType = "double";
  c2_info[19].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[19].fileTimeLo = 1286822396U;
  c2_info[19].fileTimeHi = 0U;
  c2_info[19].mFileTimeLo = 0U;
  c2_info[19].mFileTimeHi = 0U;
  c2_info[20].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[20].name = "eml_xgemm";
  c2_info[20].dominantType = "char";
  c2_info[20].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c2_info[20].fileTimeLo = 1299080372U;
  c2_info[20].fileTimeHi = 0U;
  c2_info[20].mFileTimeLo = 0U;
  c2_info[20].mFileTimeHi = 0U;
  c2_info[21].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c2_info[21].name = "eml_blas_inline";
  c2_info[21].dominantType = "";
  c2_info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c2_info[21].fileTimeLo = 1299080368U;
  c2_info[21].fileTimeHi = 0U;
  c2_info[21].mFileTimeLo = 0U;
  c2_info[21].mFileTimeHi = 0U;
  c2_info[22].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  c2_info[22].name = "mtimes";
  c2_info[22].dominantType = "double";
  c2_info[22].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[22].fileTimeLo = 1289523292U;
  c2_info[22].fileTimeHi = 0U;
  c2_info[22].mFileTimeLo = 0U;
  c2_info[22].mFileTimeHi = 0U;
  c2_info[23].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c2_info[23].name = "eml_index_class";
  c2_info[23].dominantType = "";
  c2_info[23].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[23].fileTimeLo = 1323174178U;
  c2_info[23].fileTimeHi = 0U;
  c2_info[23].mFileTimeLo = 0U;
  c2_info[23].mFileTimeHi = 0U;
  c2_info[24].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c2_info[24].name = "eml_scalar_eg";
  c2_info[24].dominantType = "double";
  c2_info[24].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[24].fileTimeLo = 1286822396U;
  c2_info[24].fileTimeHi = 0U;
  c2_info[24].mFileTimeLo = 0U;
  c2_info[24].mFileTimeHi = 0U;
  c2_info[25].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c2_info[25].name = "eml_refblas_xgemm";
  c2_info[25].dominantType = "char";
  c2_info[25].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c2_info[25].fileTimeLo = 1299080374U;
  c2_info[25].fileTimeHi = 0U;
  c2_info[25].mFileTimeLo = 0U;
  c2_info[25].mFileTimeHi = 0U;
}

static real_T c2_rdivide(SFc2_my_demoInstanceStruct *chartInstance, real_T c2_x,
  real_T c2_y)
{
  real_T c2_b_x;
  real_T c2_b_y;
  c2_b_x = c2_x;
  c2_b_y = c2_y;
  return c2_b_x / c2_b_y;
}

static real_T c2_abs(SFc2_my_demoInstanceStruct *chartInstance, real_T c2_x)
{
  real_T c2_b_x;
  c2_b_x = c2_x;
  return muDoubleScalarAbs(c2_b_x);
}

static real_T c2_power(SFc2_my_demoInstanceStruct *chartInstance, real_T c2_a)
{
  real_T c2_b_a;
  real_T c2_ak;
  c2_b_a = c2_a;
  c2_ak = c2_b_a;
  return muDoubleScalarPower(c2_ak, 2.0);
}

static void c2_eml_scalar_eg(SFc2_my_demoInstanceStruct *chartInstance)
{
}

static void c2_b_eml_scalar_eg(SFc2_my_demoInstanceStruct *chartInstance)
{
}

static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_my_demoInstanceStruct *chartInstance;
  chartInstance = (SFc2_my_demoInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static int32_T c2_e_emlrt_marshallIn(SFc2_my_demoInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i46;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i46, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i46;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_my_demoInstanceStruct *chartInstance;
  chartInstance = (SFc2_my_demoInstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_f_emlrt_marshallIn(SFc2_my_demoInstanceStruct *chartInstance,
  const mxArray *c2_b_is_active_c2_my_demo, const char_T *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_my_demo), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_my_demo);
  return c2_y;
}

static uint8_T c2_g_emlrt_marshallIn(SFc2_my_demoInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void init_dsm_address_info(SFc2_my_demoInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c2_my_demo_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3091408108U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2672457177U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2013384953U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(844821768U);
}

mxArray *sf_c2_my_demo_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("dGqHzzWTt6kZtVoMZRCzeB");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c2_my_demo(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"v\",},{M[8],M[0],T\"is_active_c2_my_demo\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_my_demo_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_my_demoInstanceStruct *chartInstance;
    chartInstance = (SFc2_my_demoInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart(_my_demoMachineNumber_,
          2,
          1,
          1,
          3,
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
          init_script_number_translation(_my_demoMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_my_demoMachineNumber_,
            chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_my_demoMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"e");
          _SFD_SET_DATA_PROPS(1,2,0,1,"v");
          _SFD_SET_DATA_PROPS(2,1,1,0,"theta");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,315);
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
            1.0,0,0,(MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)
            c2_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c2_theta;
          real_T (*c2_e)[2];
          real_T (*c2_v)[2];
          c2_theta = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c2_v = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 1);
          c2_e = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c2_e);
          _SFD_SET_DATA_VALUE_PTR(1U, *c2_v);
          _SFD_SET_DATA_VALUE_PTR(2U, c2_theta);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_my_demoMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization()
{
  return "TtrQZspp0hfjuxYVMxgjfC";
}

static void sf_opaque_initialize_c2_my_demo(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_my_demoInstanceStruct*) chartInstanceVar)->S,
    0);
  initialize_params_c2_my_demo((SFc2_my_demoInstanceStruct*) chartInstanceVar);
  initialize_c2_my_demo((SFc2_my_demoInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_my_demo(void *chartInstanceVar)
{
  enable_c2_my_demo((SFc2_my_demoInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_my_demo(void *chartInstanceVar)
{
  disable_c2_my_demo((SFc2_my_demoInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_my_demo(void *chartInstanceVar)
{
  sf_c2_my_demo((SFc2_my_demoInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_my_demo(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_my_demo((SFc2_my_demoInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_my_demo();/* state var info */
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

extern void sf_internal_set_sim_state_c2_my_demo(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_my_demo();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_my_demo((SFc2_my_demoInstanceStruct*)chartInfo->chartInstance,
    mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_my_demo(SimStruct* S)
{
  return sf_internal_get_sim_state_c2_my_demo(S);
}

static void sf_opaque_set_sim_state_c2_my_demo(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c2_my_demo(S, st);
}

static void sf_opaque_terminate_c2_my_demo(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_my_demoInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c2_my_demo((SFc2_my_demoInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_my_demo_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_my_demo((SFc2_my_demoInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_my_demo(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_my_demo((SFc2_my_demoInstanceStruct*)(((ChartInfoStruct
      *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_my_demo(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_my_demo_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,2,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,1);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3021480105U));
  ssSetChecksum1(S,(4216568350U));
  ssSetChecksum2(S,(3661112482U));
  ssSetChecksum3(S,(1076234780U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c2_my_demo(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_my_demo(SimStruct *S)
{
  SFc2_my_demoInstanceStruct *chartInstance;
  chartInstance = (SFc2_my_demoInstanceStruct *)malloc(sizeof
    (SFc2_my_demoInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_my_demoInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c2_my_demo;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c2_my_demo;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c2_my_demo;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_my_demo;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_my_demo;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c2_my_demo;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c2_my_demo;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c2_my_demo;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_my_demo;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_my_demo;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_my_demo;
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

void c2_my_demo_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_my_demo(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_my_demo(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_my_demo(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_my_demo_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
