/* Include files */

#include "blascompat32.h"
#include "canudas_goal_sfun.h"
#include "c2_canudas_goal.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "canudas_goal_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c2_debug_family_names[18] = { "T", "thetad", "r", "a",
  "alpha", "G", "J", "B", "nargin", "nargout", "q", "qr", "eps", "K1", "K2", "v",
  "w", "qe" };

static const char * c2_b_debug_family_names[3] = { "nargin", "nargout", "angle"
};

/* Function Declarations */
static void initialize_c2_canudas_goal(SFc2_canudas_goalInstanceStruct
  *chartInstance);
static void initialize_params_c2_canudas_goal(SFc2_canudas_goalInstanceStruct
  *chartInstance);
static void enable_c2_canudas_goal(SFc2_canudas_goalInstanceStruct
  *chartInstance);
static void disable_c2_canudas_goal(SFc2_canudas_goalInstanceStruct
  *chartInstance);
static void c2_update_debugger_state_c2_canudas_goal
  (SFc2_canudas_goalInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_canudas_goal
  (SFc2_canudas_goalInstanceStruct *chartInstance);
static void set_sim_state_c2_canudas_goal(SFc2_canudas_goalInstanceStruct
  *chartInstance, const mxArray *c2_st);
static void finalize_c2_canudas_goal(SFc2_canudas_goalInstanceStruct
  *chartInstance);
static void sf_c2_canudas_goal(SFc2_canudas_goalInstanceStruct *chartInstance);
static void c2_chartstep_c2_canudas_goal(SFc2_canudas_goalInstanceStruct
  *chartInstance);
static void initSimStructsc2_canudas_goal(SFc2_canudas_goalInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static void c2_emlrt_marshallIn(SFc2_canudas_goalInstanceStruct *chartInstance,
  const mxArray *c2_qe, const char_T *c2_identifier, real_T c2_y[3]);
static void c2_b_emlrt_marshallIn(SFc2_canudas_goalInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[3]);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_c_emlrt_marshallIn(SFc2_canudas_goalInstanceStruct
  *chartInstance, const mxArray *c2_w, const char_T *c2_identifier);
static real_T c2_d_emlrt_marshallIn(SFc2_canudas_goalInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_e_emlrt_marshallIn(SFc2_canudas_goalInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[4]);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_f_emlrt_marshallIn(SFc2_canudas_goalInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[6]);
static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_g_emlrt_marshallIn(SFc2_canudas_goalInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[6]);
static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_h_emlrt_marshallIn(SFc2_canudas_goalInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[9]);
static void c2_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[30]);
static void c2_eml_scalar_eg(SFc2_canudas_goalInstanceStruct *chartInstance);
static real_T c2_abs(SFc2_canudas_goalInstanceStruct *chartInstance, real_T c2_x);
static real_T c2_atan2(SFc2_canudas_goalInstanceStruct *chartInstance, real_T
  c2_y, real_T c2_x);
static void c2_b_eml_scalar_eg(SFc2_canudas_goalInstanceStruct *chartInstance);
static real_T c2_limit_angle(SFc2_canudas_goalInstanceStruct *chartInstance,
  real_T c2_angle);
static real_T c2_mpower(SFc2_canudas_goalInstanceStruct *chartInstance, real_T
  c2_a);
static void c2_c_eml_scalar_eg(SFc2_canudas_goalInstanceStruct *chartInstance);
static void c2_d_eml_scalar_eg(SFc2_canudas_goalInstanceStruct *chartInstance);
static const mxArray *c2_g_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_i_emlrt_marshallIn(SFc2_canudas_goalInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_j_emlrt_marshallIn(SFc2_canudas_goalInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_canudas_goal, const char_T
  *c2_identifier);
static uint8_T c2_k_emlrt_marshallIn(SFc2_canudas_goalInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void init_dsm_address_info(SFc2_canudas_goalInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c2_canudas_goal(SFc2_canudas_goalInstanceStruct
  *chartInstance)
{
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_is_active_c2_canudas_goal = 0U;
}

static void initialize_params_c2_canudas_goal(SFc2_canudas_goalInstanceStruct
  *chartInstance)
{
}

static void enable_c2_canudas_goal(SFc2_canudas_goalInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_canudas_goal(SFc2_canudas_goalInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_canudas_goal
  (SFc2_canudas_goalInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c2_canudas_goal
  (SFc2_canudas_goalInstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  int32_T c2_i0;
  real_T c2_u[3];
  const mxArray *c2_b_y = NULL;
  real_T c2_hoistedGlobal;
  real_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  real_T c2_b_hoistedGlobal;
  real_T c2_c_u;
  const mxArray *c2_d_y = NULL;
  uint8_T c2_c_hoistedGlobal;
  uint8_T c2_d_u;
  const mxArray *c2_e_y = NULL;
  real_T *c2_v;
  real_T *c2_w;
  real_T (*c2_qe)[3];
  c2_qe = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 3);
  c2_w = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_v = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(4), FALSE);
  for (c2_i0 = 0; c2_i0 < 3; c2_i0++) {
    c2_u[c2_i0] = (*c2_qe)[c2_i0];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_hoistedGlobal = *c2_v;
  c2_b_u = c2_hoistedGlobal;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  c2_b_hoistedGlobal = *c2_w;
  c2_c_u = c2_b_hoistedGlobal;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 2, c2_d_y);
  c2_c_hoistedGlobal = chartInstance->c2_is_active_c2_canudas_goal;
  c2_d_u = c2_c_hoistedGlobal;
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", &c2_d_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 3, c2_e_y);
  sf_mex_assign(&c2_st, c2_y, FALSE);
  return c2_st;
}

static void set_sim_state_c2_canudas_goal(SFc2_canudas_goalInstanceStruct
  *chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_u;
  real_T c2_dv0[3];
  int32_T c2_i1;
  real_T *c2_v;
  real_T *c2_w;
  real_T (*c2_qe)[3];
  c2_qe = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 3);
  c2_w = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_v = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 0)), "qe",
                      c2_dv0);
  for (c2_i1 = 0; c2_i1 < 3; c2_i1++) {
    (*c2_qe)[c2_i1] = c2_dv0[c2_i1];
  }

  *c2_v = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 1)),
    "v");
  *c2_w = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 2)),
    "w");
  chartInstance->c2_is_active_c2_canudas_goal = c2_j_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 3)),
     "is_active_c2_canudas_goal");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_canudas_goal(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_canudas_goal(SFc2_canudas_goalInstanceStruct
  *chartInstance)
{
}

static void sf_c2_canudas_goal(SFc2_canudas_goalInstanceStruct *chartInstance)
{
  int32_T c2_i2;
  int32_T c2_i3;
  int32_T c2_i4;
  real_T *c2_v;
  real_T *c2_w;
  real_T *c2_eps;
  real_T *c2_K1;
  real_T *c2_K2;
  real_T (*c2_qe)[3];
  real_T (*c2_qr)[3];
  real_T (*c2_q)[3];
  c2_K2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c2_K1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c2_eps = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c2_qe = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 3);
  c2_qr = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  c2_w = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_v = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_q = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  for (c2_i2 = 0; c2_i2 < 3; c2_i2++) {
    _SFD_DATA_RANGE_CHECK((*c2_q)[c2_i2], 0U);
  }

  _SFD_DATA_RANGE_CHECK(*c2_v, 1U);
  _SFD_DATA_RANGE_CHECK(*c2_w, 2U);
  for (c2_i3 = 0; c2_i3 < 3; c2_i3++) {
    _SFD_DATA_RANGE_CHECK((*c2_qr)[c2_i3], 3U);
  }

  for (c2_i4 = 0; c2_i4 < 3; c2_i4++) {
    _SFD_DATA_RANGE_CHECK((*c2_qe)[c2_i4], 4U);
  }

  _SFD_DATA_RANGE_CHECK(*c2_eps, 5U);
  _SFD_DATA_RANGE_CHECK(*c2_K1, 6U);
  _SFD_DATA_RANGE_CHECK(*c2_K2, 7U);
  chartInstance->c2_sfEvent = CALL_EVENT;
  c2_chartstep_c2_canudas_goal(chartInstance);
  sf_debug_check_for_state_inconsistency(_canudas_goalMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c2_chartstep_c2_canudas_goal(SFc2_canudas_goalInstanceStruct
  *chartInstance)
{
  real_T c2_hoistedGlobal;
  real_T c2_b_hoistedGlobal;
  real_T c2_c_hoistedGlobal;
  int32_T c2_i5;
  real_T c2_q[3];
  int32_T c2_i6;
  real_T c2_qr[3];
  real_T c2_eps;
  real_T c2_K1;
  real_T c2_K2;
  uint32_T c2_debug_family_var_map[18];
  real_T c2_T[9];
  real_T c2_thetad;
  real_T c2_r;
  real_T c2_a;
  real_T c2_alpha;
  real_T c2_G[6];
  real_T c2_J[6];
  real_T c2_B[4];
  real_T c2_nargin = 5.0;
  real_T c2_nargout = 3.0;
  real_T c2_v;
  real_T c2_w;
  real_T c2_qe[3];
  real_T c2_x;
  real_T c2_b_x;
  real_T c2_c_x;
  real_T c2_d_x;
  real_T c2_e_x;
  real_T c2_f_x;
  real_T c2_g_x;
  real_T c2_h_x;
  int32_T c2_i7;
  int32_T c2_i8;
  static real_T c2_dv1[3] = { 0.0, 0.0, 1.0 };

  int32_T c2_i9;
  real_T c2_b_a[9];
  int32_T c2_i10;
  real_T c2_b[3];
  int32_T c2_i11;
  int32_T c2_i12;
  int32_T c2_i13;
  real_T c2_C[3];
  int32_T c2_i14;
  int32_T c2_i15;
  int32_T c2_i16;
  int32_T c2_i17;
  int32_T c2_i18;
  int32_T c2_i19;
  real_T c2_b_b;
  real_T c2_c_b;
  real_T c2_y;
  real_T c2_A;
  real_T c2_b_B;
  real_T c2_i_x;
  real_T c2_b_y;
  real_T c2_j_x;
  real_T c2_c_y;
  real_T c2_c_a;
  real_T c2_d_b;
  real_T c2_k_x;
  real_T c2_l_x;
  real_T c2_m_x;
  real_T c2_n_x;
  int32_T c2_i20;
  int32_T c2_i21;
  real_T c2_d_a;
  real_T c2_e_b;
  real_T c2_d_y;
  real_T c2_b_A;
  real_T c2_c_B;
  real_T c2_o_x;
  real_T c2_e_y;
  real_T c2_p_x;
  real_T c2_f_y;
  real_T c2_g_y;
  real_T c2_c_A;
  real_T c2_d_B;
  real_T c2_q_x;
  real_T c2_h_y;
  real_T c2_r_x;
  real_T c2_i_y;
  real_T c2_j_y;
  real_T c2_e_a;
  real_T c2_f_b;
  real_T c2_k_y;
  real_T c2_d_A;
  real_T c2_s_x;
  real_T c2_t_x;
  real_T c2_l_y;
  real_T c2_e_A;
  real_T c2_e_B;
  real_T c2_u_x;
  real_T c2_m_y;
  real_T c2_v_x;
  real_T c2_n_y;
  real_T c2_o_y;
  real_T c2_g_b;
  real_T c2_p_y;
  real_T c2_f_A;
  real_T c2_f_B;
  real_T c2_w_x;
  real_T c2_q_y;
  real_T c2_x_x;
  real_T c2_r_y;
  real_T c2_s_y;
  real_T c2_g_A;
  real_T c2_g_B;
  real_T c2_y_x;
  real_T c2_t_y;
  real_T c2_ab_x;
  real_T c2_u_y;
  real_T c2_v_y;
  real_T c2_h_A;
  real_T c2_h_B;
  real_T c2_bb_x;
  real_T c2_w_y;
  real_T c2_cb_x;
  real_T c2_x_y;
  real_T c2_y_y;
  real_T c2_i_A;
  real_T c2_i_B;
  real_T c2_db_x;
  real_T c2_ab_y;
  real_T c2_eb_x;
  real_T c2_bb_y;
  real_T c2_cb_y;
  real_T c2_j_B;
  real_T c2_db_y;
  real_T c2_eb_y;
  real_T c2_fb_y;
  real_T c2_j_A;
  real_T c2_k_B;
  real_T c2_fb_x;
  real_T c2_gb_y;
  real_T c2_gb_x;
  real_T c2_hb_y;
  real_T c2_ib_y;
  int32_T c2_i22;
  real_T c2_f_a[6];
  int32_T c2_i23;
  int32_T c2_i24;
  int32_T c2_i25;
  int32_T c2_i26;
  int32_T c2_i27;
  real_T c2_jb_y[6];
  int32_T c2_i28;
  int32_T c2_i29;
  int32_T c2_i30;
  real_T c2_h_b[6];
  int32_T c2_i31;
  int32_T c2_i32;
  int32_T c2_i33;
  real_T c2_b_C[4];
  int32_T c2_i34;
  int32_T c2_i35;
  int32_T c2_i36;
  int32_T c2_i37;
  int32_T c2_i38;
  int32_T c2_i39;
  int32_T c2_i40;
  int32_T c2_i41;
  int32_T c2_i42;
  real_T c2_g_a;
  real_T c2_i_b;
  real_T c2_kb_y;
  real_T c2_h_a;
  real_T c2_j_b;
  real_T c2_i_a;
  real_T c2_k_b;
  real_T c2_lb_y;
  real_T c2_j_a;
  real_T c2_l_b;
  real_T c2_mb_y;
  int32_T c2_i43;
  real_T *c2_b_eps;
  real_T *c2_b_K1;
  real_T *c2_b_K2;
  real_T *c2_b_v;
  real_T *c2_b_w;
  real_T (*c2_b_qe)[3];
  real_T (*c2_b_qr)[3];
  real_T (*c2_b_q)[3];
  boolean_T guard1 = FALSE;
  c2_b_K2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c2_b_K1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c2_b_eps = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c2_b_qe = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 3);
  c2_b_qr = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  c2_b_w = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_b_v = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_b_q = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  c2_hoistedGlobal = *c2_b_eps;
  c2_b_hoistedGlobal = *c2_b_K1;
  c2_c_hoistedGlobal = *c2_b_K2;
  for (c2_i5 = 0; c2_i5 < 3; c2_i5++) {
    c2_q[c2_i5] = (*c2_b_q)[c2_i5];
  }

  for (c2_i6 = 0; c2_i6 < 3; c2_i6++) {
    c2_qr[c2_i6] = (*c2_b_qr)[c2_i6];
  }

  c2_eps = c2_hoistedGlobal;
  c2_K1 = c2_b_hoistedGlobal;
  c2_K2 = c2_c_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 18U, 18U, c2_debug_family_names,
    c2_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(c2_T, 0U, c2_f_sf_marshallOut,
    c2_f_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_thetad, 1U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_r, 2U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_a, 3U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_alpha, 4U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_G, 5U, c2_e_sf_marshallOut,
    c2_e_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_J, 6U, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_B, 7U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargin, 8U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargout, 9U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c2_q, 10U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c2_qr, 11U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_eps, 12U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_K1, 13U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_K2, 14U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c2_v, 15U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_w, 16U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_qe, 17U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 4);
  c2_x = c2_qr[2];
  c2_b_x = c2_x;
  c2_b_x = muDoubleScalarCos(c2_b_x);
  c2_c_x = c2_qr[2];
  c2_d_x = c2_c_x;
  c2_d_x = muDoubleScalarSin(c2_d_x);
  c2_e_x = c2_qr[2];
  c2_f_x = c2_e_x;
  c2_f_x = muDoubleScalarSin(c2_f_x);
  c2_g_x = c2_qr[2];
  c2_h_x = c2_g_x;
  c2_h_x = muDoubleScalarCos(c2_h_x);
  c2_T[0] = c2_b_x;
  c2_T[3] = c2_d_x;
  c2_T[6] = 0.0;
  c2_T[1] = -c2_f_x;
  c2_T[4] = c2_h_x;
  c2_T[7] = 0.0;
  c2_i7 = 0;
  for (c2_i8 = 0; c2_i8 < 3; c2_i8++) {
    c2_T[c2_i7 + 2] = c2_dv1[c2_i8];
    c2_i7 += 3;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 7);
  for (c2_i9 = 0; c2_i9 < 9; c2_i9++) {
    c2_b_a[c2_i9] = c2_T[c2_i9];
  }

  for (c2_i10 = 0; c2_i10 < 3; c2_i10++) {
    c2_b[c2_i10] = c2_q[c2_i10] - c2_qr[c2_i10];
  }

  c2_eml_scalar_eg(chartInstance);
  c2_eml_scalar_eg(chartInstance);
  for (c2_i11 = 0; c2_i11 < 3; c2_i11++) {
    c2_qe[c2_i11] = 0.0;
  }

  for (c2_i12 = 0; c2_i12 < 3; c2_i12++) {
    c2_qe[c2_i12] = 0.0;
  }

  for (c2_i13 = 0; c2_i13 < 3; c2_i13++) {
    c2_C[c2_i13] = c2_qe[c2_i13];
  }

  for (c2_i14 = 0; c2_i14 < 3; c2_i14++) {
    c2_qe[c2_i14] = c2_C[c2_i14];
  }

  for (c2_i15 = 0; c2_i15 < 3; c2_i15++) {
    c2_C[c2_i15] = c2_qe[c2_i15];
  }

  for (c2_i16 = 0; c2_i16 < 3; c2_i16++) {
    c2_qe[c2_i16] = c2_C[c2_i16];
  }

  for (c2_i17 = 0; c2_i17 < 3; c2_i17++) {
    c2_qe[c2_i17] = 0.0;
    c2_i18 = 0;
    for (c2_i19 = 0; c2_i19 < 3; c2_i19++) {
      c2_qe[c2_i17] += c2_b_a[c2_i18 + c2_i17] * c2_b[c2_i19];
      c2_i18 += 3;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 12);
  guard1 = FALSE;
  if (CV_EML_COND(0, 1, 0, c2_abs(chartInstance, c2_qe[0]) < c2_eps)) {
    if (CV_EML_COND(0, 1, 1, c2_abs(chartInstance, c2_qe[1]) == c2_eps)) {
      CV_EML_MCDC(0, 1, 0, TRUE);
      CV_EML_IF(0, 1, 0, TRUE);
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 13);
      c2_thetad = 0.0;
    } else {
      guard1 = TRUE;
    }
  } else {
    guard1 = TRUE;
  }

  if (guard1 == TRUE) {
    CV_EML_MCDC(0, 1, 0, FALSE);
    CV_EML_IF(0, 1, 0, FALSE);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 15);
    c2_b_b = c2_atan2(chartInstance, c2_qe[1], c2_qe[0]);
    c2_thetad = 2.0 * c2_b_b;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 16);
    c2_thetad = c2_limit_angle(chartInstance, c2_thetad);
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 19);
  if (CV_EML_IF(0, 1, 1, c2_abs(chartInstance, c2_qe[1]) < c2_eps)) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 20);
    c2_r = 0.0;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 22);
    c2_c_b = c2_qe[1];
    c2_y = 2.0 * c2_c_b;
    c2_A = c2_mpower(chartInstance, c2_qe[0]) + c2_mpower(chartInstance, c2_qe[1]);
    c2_b_B = c2_y;
    c2_i_x = c2_A;
    c2_b_y = c2_b_B;
    c2_j_x = c2_i_x;
    c2_c_y = c2_b_y;
    c2_r = c2_j_x / c2_c_y;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 25);
  c2_c_a = c2_r;
  c2_d_b = c2_thetad;
  c2_a = c2_c_a * c2_d_b;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 26);
  c2_alpha = c2_qe[2] - c2_thetad;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 27);
  c2_alpha = c2_limit_angle(chartInstance, c2_alpha);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 30);
  c2_k_x = c2_q[2];
  c2_l_x = c2_k_x;
  c2_l_x = muDoubleScalarCos(c2_l_x);
  c2_m_x = c2_q[2];
  c2_n_x = c2_m_x;
  c2_n_x = muDoubleScalarSin(c2_n_x);
  c2_G[0] = c2_l_x;
  c2_G[3] = 0.0;
  c2_G[1] = c2_n_x;
  c2_G[4] = 0.0;
  c2_i20 = 0;
  for (c2_i21 = 0; c2_i21 < 2; c2_i21++) {
    c2_G[c2_i20 + 2] = (real_T)c2_i21;
    c2_i20 += 3;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 34);
  c2_d_a = c2_thetad;
  c2_e_b = c2_qe[0];
  c2_d_y = c2_d_a * c2_e_b;
  c2_b_A = c2_d_y;
  c2_c_B = c2_qe[1];
  c2_o_x = c2_b_A;
  c2_e_y = c2_c_B;
  c2_p_x = c2_o_x;
  c2_f_y = c2_e_y;
  c2_g_y = c2_p_x / c2_f_y;
  c2_c_A = c2_mpower(chartInstance, c2_qe[0]);
  c2_d_B = c2_mpower(chartInstance, c2_qe[1]);
  c2_q_x = c2_c_A;
  c2_h_y = c2_d_B;
  c2_r_x = c2_q_x;
  c2_i_y = c2_h_y;
  c2_j_y = c2_r_x / c2_i_y;
  c2_e_a = c2_thetad;
  c2_f_b = 1.0 - c2_j_y;
  c2_k_y = c2_e_a * c2_f_b;
  c2_d_A = c2_k_y;
  c2_s_x = c2_d_A;
  c2_t_x = c2_s_x;
  c2_l_y = c2_t_x / 2.0;
  c2_e_A = c2_qe[0];
  c2_e_B = c2_qe[1];
  c2_u_x = c2_e_A;
  c2_m_y = c2_e_B;
  c2_v_x = c2_u_x;
  c2_n_y = c2_m_y;
  c2_o_y = c2_v_x / c2_n_y;
  c2_g_b = c2_qe[1];
  c2_p_y = 2.0 * c2_g_b;
  c2_f_A = c2_mpower(chartInstance, c2_qe[1]);
  c2_f_B = c2_mpower(chartInstance, c2_qe[0]);
  c2_w_x = c2_f_A;
  c2_q_y = c2_f_B;
  c2_x_x = c2_w_x;
  c2_r_y = c2_q_y;
  c2_s_y = c2_x_x / c2_r_y;
  c2_g_A = c2_p_y;
  c2_g_B = 1.0 + c2_s_y;
  c2_y_x = c2_g_A;
  c2_t_y = c2_g_B;
  c2_ab_x = c2_y_x;
  c2_u_y = c2_t_y;
  c2_v_y = c2_ab_x / c2_u_y;
  c2_h_A = c2_v_y;
  c2_h_B = c2_mpower(chartInstance, c2_qe[0]);
  c2_bb_x = c2_h_A;
  c2_w_y = c2_h_B;
  c2_cb_x = c2_bb_x;
  c2_x_y = c2_w_y;
  c2_y_y = c2_cb_x / c2_x_y;
  c2_i_A = c2_mpower(chartInstance, c2_qe[1]);
  c2_i_B = c2_mpower(chartInstance, c2_qe[0]);
  c2_db_x = c2_i_A;
  c2_ab_y = c2_i_B;
  c2_eb_x = c2_db_x;
  c2_bb_y = c2_ab_y;
  c2_cb_y = c2_eb_x / c2_bb_y;
  c2_j_B = 1.0 + c2_cb_y;
  c2_db_y = c2_j_B;
  c2_eb_y = c2_db_y;
  c2_fb_y = -2.0 / c2_eb_y;
  c2_j_A = c2_fb_y;
  c2_k_B = c2_qe[0];
  c2_fb_x = c2_j_A;
  c2_gb_y = c2_k_B;
  c2_gb_x = c2_fb_x;
  c2_hb_y = c2_gb_y;
  c2_ib_y = c2_gb_x / c2_hb_y;
  c2_J[0] = c2_g_y - 1.0;
  c2_J[2] = c2_l_y + c2_o_y;
  c2_J[4] = 0.0;
  c2_J[1] = c2_y_y;
  c2_J[3] = c2_ib_y;
  c2_J[5] = 1.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 37);
  for (c2_i22 = 0; c2_i22 < 6; c2_i22++) {
    c2_f_a[c2_i22] = c2_J[c2_i22];
  }

  for (c2_i23 = 0; c2_i23 < 9; c2_i23++) {
    c2_b_a[c2_i23] = c2_T[c2_i23];
  }

  c2_c_eml_scalar_eg(chartInstance);
  c2_c_eml_scalar_eg(chartInstance);
  for (c2_i24 = 0; c2_i24 < 2; c2_i24++) {
    c2_i25 = 0;
    c2_i26 = 0;
    for (c2_i27 = 0; c2_i27 < 3; c2_i27++) {
      c2_jb_y[c2_i25 + c2_i24] = 0.0;
      c2_i28 = 0;
      for (c2_i29 = 0; c2_i29 < 3; c2_i29++) {
        c2_jb_y[c2_i25 + c2_i24] += c2_f_a[c2_i28 + c2_i24] * c2_b_a[c2_i29 +
          c2_i26];
        c2_i28 += 2;
      }

      c2_i25 += 2;
      c2_i26 += 3;
    }
  }

  for (c2_i30 = 0; c2_i30 < 6; c2_i30++) {
    c2_h_b[c2_i30] = c2_G[c2_i30];
  }

  c2_d_eml_scalar_eg(chartInstance);
  c2_d_eml_scalar_eg(chartInstance);
  for (c2_i31 = 0; c2_i31 < 4; c2_i31++) {
    c2_B[c2_i31] = 0.0;
  }

  for (c2_i32 = 0; c2_i32 < 4; c2_i32++) {
    c2_B[c2_i32] = 0.0;
  }

  for (c2_i33 = 0; c2_i33 < 4; c2_i33++) {
    c2_b_C[c2_i33] = c2_B[c2_i33];
  }

  for (c2_i34 = 0; c2_i34 < 4; c2_i34++) {
    c2_B[c2_i34] = c2_b_C[c2_i34];
  }

  for (c2_i35 = 0; c2_i35 < 4; c2_i35++) {
    c2_b_C[c2_i35] = c2_B[c2_i35];
  }

  for (c2_i36 = 0; c2_i36 < 4; c2_i36++) {
    c2_B[c2_i36] = c2_b_C[c2_i36];
  }

  for (c2_i37 = 0; c2_i37 < 2; c2_i37++) {
    c2_i38 = 0;
    c2_i39 = 0;
    for (c2_i40 = 0; c2_i40 < 2; c2_i40++) {
      c2_B[c2_i38 + c2_i37] = 0.0;
      c2_i41 = 0;
      for (c2_i42 = 0; c2_i42 < 3; c2_i42++) {
        c2_B[c2_i38 + c2_i37] += c2_jb_y[c2_i41 + c2_i37] * c2_h_b[c2_i42 +
          c2_i39];
        c2_i41 += 2;
      }

      c2_i38 += 2;
      c2_i39 += 3;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 39);
  c2_g_a = -c2_K1;
  c2_i_b = c2_B[0];
  c2_kb_y = c2_g_a * c2_i_b;
  c2_h_a = c2_kb_y;
  c2_j_b = c2_a;
  c2_v = c2_h_a * c2_j_b;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 40);
  c2_i_a = -c2_B[1];
  c2_k_b = c2_v;
  c2_lb_y = c2_i_a * c2_k_b;
  c2_j_a = c2_K2;
  c2_l_b = c2_alpha;
  c2_mb_y = c2_j_a * c2_l_b;
  c2_w = c2_lb_y - c2_mb_y;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -40);
  sf_debug_symbol_scope_pop();
  *c2_b_v = c2_v;
  *c2_b_w = c2_w;
  for (c2_i43 = 0; c2_i43 < 3; c2_i43++) {
    (*c2_b_qe)[c2_i43] = c2_qe[c2_i43];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
}

static void initSimStructsc2_canudas_goal(SFc2_canudas_goalInstanceStruct
  *chartInstance)
{
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
  _SFD_SCRIPT_TRANSLATION(c2_chartNumber, 0U, sf_debug_get_script_id(
    "C:/Users/samati/Steph/Work/Simulink models/simulink/limit_angle.m"));
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i44;
  real_T c2_b_inData[3];
  int32_T c2_i45;
  real_T c2_u[3];
  const mxArray *c2_y = NULL;
  SFc2_canudas_goalInstanceStruct *chartInstance;
  chartInstance = (SFc2_canudas_goalInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i44 = 0; c2_i44 < 3; c2_i44++) {
    c2_b_inData[c2_i44] = (*(real_T (*)[3])c2_inData)[c2_i44];
  }

  for (c2_i45 = 0; c2_i45 < 3; c2_i45++) {
    c2_u[c2_i45] = c2_b_inData[c2_i45];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_emlrt_marshallIn(SFc2_canudas_goalInstanceStruct *chartInstance,
  const mxArray *c2_qe, const char_T *c2_identifier, real_T c2_y[3])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_qe), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_qe);
}

static void c2_b_emlrt_marshallIn(SFc2_canudas_goalInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[3])
{
  real_T c2_dv2[3];
  int32_T c2_i46;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv2, 1, 0, 0U, 1, 0U, 1, 3);
  for (c2_i46 = 0; c2_i46 < 3; c2_i46++) {
    c2_y[c2_i46] = c2_dv2[c2_i46];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_qe;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[3];
  int32_T c2_i47;
  SFc2_canudas_goalInstanceStruct *chartInstance;
  chartInstance = (SFc2_canudas_goalInstanceStruct *)chartInstanceVoid;
  c2_qe = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_qe), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_qe);
  for (c2_i47 = 0; c2_i47 < 3; c2_i47++) {
    (*(real_T (*)[3])c2_outData)[c2_i47] = c2_y[c2_i47];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_canudas_goalInstanceStruct *chartInstance;
  chartInstance = (SFc2_canudas_goalInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_c_emlrt_marshallIn(SFc2_canudas_goalInstanceStruct
  *chartInstance, const mxArray *c2_w, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_w), &c2_thisId);
  sf_mex_destroy(&c2_w);
  return c2_y;
}

static real_T c2_d_emlrt_marshallIn(SFc2_canudas_goalInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
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
  const mxArray *c2_w;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_canudas_goalInstanceStruct *chartInstance;
  chartInstance = (SFc2_canudas_goalInstanceStruct *)chartInstanceVoid;
  c2_w = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_w), &c2_thisId);
  sf_mex_destroy(&c2_w);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i48;
  int32_T c2_i49;
  int32_T c2_i50;
  real_T c2_b_inData[4];
  int32_T c2_i51;
  int32_T c2_i52;
  int32_T c2_i53;
  real_T c2_u[4];
  const mxArray *c2_y = NULL;
  SFc2_canudas_goalInstanceStruct *chartInstance;
  chartInstance = (SFc2_canudas_goalInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i48 = 0;
  for (c2_i49 = 0; c2_i49 < 2; c2_i49++) {
    for (c2_i50 = 0; c2_i50 < 2; c2_i50++) {
      c2_b_inData[c2_i50 + c2_i48] = (*(real_T (*)[4])c2_inData)[c2_i50 + c2_i48];
    }

    c2_i48 += 2;
  }

  c2_i51 = 0;
  for (c2_i52 = 0; c2_i52 < 2; c2_i52++) {
    for (c2_i53 = 0; c2_i53 < 2; c2_i53++) {
      c2_u[c2_i53 + c2_i51] = c2_b_inData[c2_i53 + c2_i51];
    }

    c2_i51 += 2;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 2, 2), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_e_emlrt_marshallIn(SFc2_canudas_goalInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[4])
{
  real_T c2_dv3[4];
  int32_T c2_i54;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv3, 1, 0, 0U, 1, 0U, 2, 2, 2);
  for (c2_i54 = 0; c2_i54 < 4; c2_i54++) {
    c2_y[c2_i54] = c2_dv3[c2_i54];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_B;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[4];
  int32_T c2_i55;
  int32_T c2_i56;
  int32_T c2_i57;
  SFc2_canudas_goalInstanceStruct *chartInstance;
  chartInstance = (SFc2_canudas_goalInstanceStruct *)chartInstanceVoid;
  c2_B = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_B), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_B);
  c2_i55 = 0;
  for (c2_i56 = 0; c2_i56 < 2; c2_i56++) {
    for (c2_i57 = 0; c2_i57 < 2; c2_i57++) {
      (*(real_T (*)[4])c2_outData)[c2_i57 + c2_i55] = c2_y[c2_i57 + c2_i55];
    }

    c2_i55 += 2;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i58;
  int32_T c2_i59;
  int32_T c2_i60;
  real_T c2_b_inData[6];
  int32_T c2_i61;
  int32_T c2_i62;
  int32_T c2_i63;
  real_T c2_u[6];
  const mxArray *c2_y = NULL;
  SFc2_canudas_goalInstanceStruct *chartInstance;
  chartInstance = (SFc2_canudas_goalInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i58 = 0;
  for (c2_i59 = 0; c2_i59 < 3; c2_i59++) {
    for (c2_i60 = 0; c2_i60 < 2; c2_i60++) {
      c2_b_inData[c2_i60 + c2_i58] = (*(real_T (*)[6])c2_inData)[c2_i60 + c2_i58];
    }

    c2_i58 += 2;
  }

  c2_i61 = 0;
  for (c2_i62 = 0; c2_i62 < 3; c2_i62++) {
    for (c2_i63 = 0; c2_i63 < 2; c2_i63++) {
      c2_u[c2_i63 + c2_i61] = c2_b_inData[c2_i63 + c2_i61];
    }

    c2_i61 += 2;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 2, 3), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_f_emlrt_marshallIn(SFc2_canudas_goalInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[6])
{
  real_T c2_dv4[6];
  int32_T c2_i64;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv4, 1, 0, 0U, 1, 0U, 2, 2, 3);
  for (c2_i64 = 0; c2_i64 < 6; c2_i64++) {
    c2_y[c2_i64] = c2_dv4[c2_i64];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_J;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[6];
  int32_T c2_i65;
  int32_T c2_i66;
  int32_T c2_i67;
  SFc2_canudas_goalInstanceStruct *chartInstance;
  chartInstance = (SFc2_canudas_goalInstanceStruct *)chartInstanceVoid;
  c2_J = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_J), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_J);
  c2_i65 = 0;
  for (c2_i66 = 0; c2_i66 < 3; c2_i66++) {
    for (c2_i67 = 0; c2_i67 < 2; c2_i67++) {
      (*(real_T (*)[6])c2_outData)[c2_i67 + c2_i65] = c2_y[c2_i67 + c2_i65];
    }

    c2_i65 += 2;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i68;
  int32_T c2_i69;
  int32_T c2_i70;
  real_T c2_b_inData[6];
  int32_T c2_i71;
  int32_T c2_i72;
  int32_T c2_i73;
  real_T c2_u[6];
  const mxArray *c2_y = NULL;
  SFc2_canudas_goalInstanceStruct *chartInstance;
  chartInstance = (SFc2_canudas_goalInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i68 = 0;
  for (c2_i69 = 0; c2_i69 < 2; c2_i69++) {
    for (c2_i70 = 0; c2_i70 < 3; c2_i70++) {
      c2_b_inData[c2_i70 + c2_i68] = (*(real_T (*)[6])c2_inData)[c2_i70 + c2_i68];
    }

    c2_i68 += 3;
  }

  c2_i71 = 0;
  for (c2_i72 = 0; c2_i72 < 2; c2_i72++) {
    for (c2_i73 = 0; c2_i73 < 3; c2_i73++) {
      c2_u[c2_i73 + c2_i71] = c2_b_inData[c2_i73 + c2_i71];
    }

    c2_i71 += 3;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 3, 2), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_g_emlrt_marshallIn(SFc2_canudas_goalInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[6])
{
  real_T c2_dv5[6];
  int32_T c2_i74;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv5, 1, 0, 0U, 1, 0U, 2, 3, 2);
  for (c2_i74 = 0; c2_i74 < 6; c2_i74++) {
    c2_y[c2_i74] = c2_dv5[c2_i74];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_G;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[6];
  int32_T c2_i75;
  int32_T c2_i76;
  int32_T c2_i77;
  SFc2_canudas_goalInstanceStruct *chartInstance;
  chartInstance = (SFc2_canudas_goalInstanceStruct *)chartInstanceVoid;
  c2_G = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_G), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_G);
  c2_i75 = 0;
  for (c2_i76 = 0; c2_i76 < 2; c2_i76++) {
    for (c2_i77 = 0; c2_i77 < 3; c2_i77++) {
      (*(real_T (*)[6])c2_outData)[c2_i77 + c2_i75] = c2_y[c2_i77 + c2_i75];
    }

    c2_i75 += 3;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i78;
  int32_T c2_i79;
  int32_T c2_i80;
  real_T c2_b_inData[9];
  int32_T c2_i81;
  int32_T c2_i82;
  int32_T c2_i83;
  real_T c2_u[9];
  const mxArray *c2_y = NULL;
  SFc2_canudas_goalInstanceStruct *chartInstance;
  chartInstance = (SFc2_canudas_goalInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i78 = 0;
  for (c2_i79 = 0; c2_i79 < 3; c2_i79++) {
    for (c2_i80 = 0; c2_i80 < 3; c2_i80++) {
      c2_b_inData[c2_i80 + c2_i78] = (*(real_T (*)[9])c2_inData)[c2_i80 + c2_i78];
    }

    c2_i78 += 3;
  }

  c2_i81 = 0;
  for (c2_i82 = 0; c2_i82 < 3; c2_i82++) {
    for (c2_i83 = 0; c2_i83 < 3; c2_i83++) {
      c2_u[c2_i83 + c2_i81] = c2_b_inData[c2_i83 + c2_i81];
    }

    c2_i81 += 3;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_h_emlrt_marshallIn(SFc2_canudas_goalInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[9])
{
  real_T c2_dv6[9];
  int32_T c2_i84;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv6, 1, 0, 0U, 1, 0U, 2, 3, 3);
  for (c2_i84 = 0; c2_i84 < 9; c2_i84++) {
    c2_y[c2_i84] = c2_dv6[c2_i84];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_T;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[9];
  int32_T c2_i85;
  int32_T c2_i86;
  int32_T c2_i87;
  SFc2_canudas_goalInstanceStruct *chartInstance;
  chartInstance = (SFc2_canudas_goalInstanceStruct *)chartInstanceVoid;
  c2_T = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_T), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_T);
  c2_i85 = 0;
  for (c2_i86 = 0; c2_i86 < 3; c2_i86++) {
    for (c2_i87 = 0; c2_i87 < 3; c2_i87++) {
      (*(real_T (*)[9])c2_outData)[c2_i87 + c2_i85] = c2_y[c2_i87 + c2_i85];
    }

    c2_i85 += 3;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray *sf_c2_canudas_goal_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo;
  c2_ResolvedFunctionInfo c2_info[30];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i88;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  c2_info_helper(c2_info);
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 30), FALSE);
  for (c2_i88 = 0; c2_i88 < 30; c2_i88++) {
    c2_r0 = &c2_info[c2_i88];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context", "nameCaptureInfo",
                    c2_i88);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name", "nameCaptureInfo", c2_i88);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c2_i88);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved", "nameCaptureInfo",
                    c2_i88);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c2_i88);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c2_i88);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c2_i88);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c2_i88);
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c2_nameCaptureInfo);
  return c2_nameCaptureInfo;
}

static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[30])
{
  c2_info[0].context = "";
  c2_info[0].name = "cos";
  c2_info[0].dominantType = "double";
  c2_info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c2_info[0].fileTimeLo = 1286822306U;
  c2_info[0].fileTimeHi = 0U;
  c2_info[0].mFileTimeLo = 0U;
  c2_info[0].mFileTimeHi = 0U;
  c2_info[1].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c2_info[1].name = "eml_scalar_cos";
  c2_info[1].dominantType = "double";
  c2_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c2_info[1].fileTimeLo = 1286822322U;
  c2_info[1].fileTimeHi = 0U;
  c2_info[1].mFileTimeLo = 0U;
  c2_info[1].mFileTimeHi = 0U;
  c2_info[2].context = "";
  c2_info[2].name = "sin";
  c2_info[2].dominantType = "double";
  c2_info[2].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c2_info[2].fileTimeLo = 1286822350U;
  c2_info[2].fileTimeHi = 0U;
  c2_info[2].mFileTimeLo = 0U;
  c2_info[2].mFileTimeHi = 0U;
  c2_info[3].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c2_info[3].name = "eml_scalar_sin";
  c2_info[3].dominantType = "double";
  c2_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c2_info[3].fileTimeLo = 1286822336U;
  c2_info[3].fileTimeHi = 0U;
  c2_info[3].mFileTimeLo = 0U;
  c2_info[3].mFileTimeHi = 0U;
  c2_info[4].context = "";
  c2_info[4].name = "mtimes";
  c2_info[4].dominantType = "double";
  c2_info[4].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[4].fileTimeLo = 1289523292U;
  c2_info[4].fileTimeHi = 0U;
  c2_info[4].mFileTimeLo = 0U;
  c2_info[4].mFileTimeHi = 0U;
  c2_info[5].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[5].name = "eml_index_class";
  c2_info[5].dominantType = "";
  c2_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[5].fileTimeLo = 1323174178U;
  c2_info[5].fileTimeHi = 0U;
  c2_info[5].mFileTimeLo = 0U;
  c2_info[5].mFileTimeHi = 0U;
  c2_info[6].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[6].name = "eml_scalar_eg";
  c2_info[6].dominantType = "double";
  c2_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[6].fileTimeLo = 1286822396U;
  c2_info[6].fileTimeHi = 0U;
  c2_info[6].mFileTimeLo = 0U;
  c2_info[6].mFileTimeHi = 0U;
  c2_info[7].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[7].name = "eml_xgemm";
  c2_info[7].dominantType = "char";
  c2_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c2_info[7].fileTimeLo = 1299080372U;
  c2_info[7].fileTimeHi = 0U;
  c2_info[7].mFileTimeLo = 0U;
  c2_info[7].mFileTimeHi = 0U;
  c2_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c2_info[8].name = "eml_blas_inline";
  c2_info[8].dominantType = "";
  c2_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c2_info[8].fileTimeLo = 1299080368U;
  c2_info[8].fileTimeHi = 0U;
  c2_info[8].mFileTimeLo = 0U;
  c2_info[8].mFileTimeHi = 0U;
  c2_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  c2_info[9].name = "mtimes";
  c2_info[9].dominantType = "double";
  c2_info[9].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[9].fileTimeLo = 1289523292U;
  c2_info[9].fileTimeHi = 0U;
  c2_info[9].mFileTimeLo = 0U;
  c2_info[9].mFileTimeHi = 0U;
  c2_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c2_info[10].name = "eml_index_class";
  c2_info[10].dominantType = "";
  c2_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[10].fileTimeLo = 1323174178U;
  c2_info[10].fileTimeHi = 0U;
  c2_info[10].mFileTimeLo = 0U;
  c2_info[10].mFileTimeHi = 0U;
  c2_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c2_info[11].name = "eml_scalar_eg";
  c2_info[11].dominantType = "double";
  c2_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[11].fileTimeLo = 1286822396U;
  c2_info[11].fileTimeHi = 0U;
  c2_info[11].mFileTimeLo = 0U;
  c2_info[11].mFileTimeHi = 0U;
  c2_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c2_info[12].name = "eml_refblas_xgemm";
  c2_info[12].dominantType = "char";
  c2_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c2_info[12].fileTimeLo = 1299080374U;
  c2_info[12].fileTimeHi = 0U;
  c2_info[12].mFileTimeLo = 0U;
  c2_info[12].mFileTimeHi = 0U;
  c2_info[13].context = "";
  c2_info[13].name = "abs";
  c2_info[13].dominantType = "double";
  c2_info[13].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c2_info[13].fileTimeLo = 1286822294U;
  c2_info[13].fileTimeHi = 0U;
  c2_info[13].mFileTimeLo = 0U;
  c2_info[13].mFileTimeHi = 0U;
  c2_info[14].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c2_info[14].name = "eml_scalar_abs";
  c2_info[14].dominantType = "double";
  c2_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c2_info[14].fileTimeLo = 1286822312U;
  c2_info[14].fileTimeHi = 0U;
  c2_info[14].mFileTimeLo = 0U;
  c2_info[14].mFileTimeHi = 0U;
  c2_info[15].context = "";
  c2_info[15].name = "atan2";
  c2_info[15].dominantType = "double";
  c2_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m";
  c2_info[15].fileTimeLo = 1286822304U;
  c2_info[15].fileTimeHi = 0U;
  c2_info[15].mFileTimeLo = 0U;
  c2_info[15].mFileTimeHi = 0U;
  c2_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m";
  c2_info[16].name = "eml_scalar_eg";
  c2_info[16].dominantType = "double";
  c2_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[16].fileTimeLo = 1286822396U;
  c2_info[16].fileTimeHi = 0U;
  c2_info[16].mFileTimeLo = 0U;
  c2_info[16].mFileTimeHi = 0U;
  c2_info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m";
  c2_info[17].name = "eml_scalexp_alloc";
  c2_info[17].dominantType = "double";
  c2_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c2_info[17].fileTimeLo = 1330612034U;
  c2_info[17].fileTimeHi = 0U;
  c2_info[17].mFileTimeLo = 0U;
  c2_info[17].mFileTimeHi = 0U;
  c2_info[18].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m";
  c2_info[18].name = "eml_scalar_atan2";
  c2_info[18].dominantType = "double";
  c2_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_atan2.m";
  c2_info[18].fileTimeLo = 1286822320U;
  c2_info[18].fileTimeHi = 0U;
  c2_info[18].mFileTimeLo = 0U;
  c2_info[18].mFileTimeHi = 0U;
  c2_info[19].context = "";
  c2_info[19].name = "limit_angle";
  c2_info[19].dominantType = "double";
  c2_info[19].resolved =
    "[E]C:/Users/samati/Steph/Work/Simulink models/simulink/limit_angle.m";
  c2_info[19].fileTimeLo = 1430997605U;
  c2_info[19].fileTimeHi = 0U;
  c2_info[19].mFileTimeLo = 0U;
  c2_info[19].mFileTimeHi = 0U;
  c2_info[20].context =
    "[E]C:/Users/samati/Steph/Work/Simulink models/simulink/limit_angle.m";
  c2_info[20].name = "mtimes";
  c2_info[20].dominantType = "double";
  c2_info[20].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[20].fileTimeLo = 1289523292U;
  c2_info[20].fileTimeHi = 0U;
  c2_info[20].mFileTimeLo = 0U;
  c2_info[20].mFileTimeHi = 0U;
  c2_info[21].context = "";
  c2_info[21].name = "mpower";
  c2_info[21].dominantType = "double";
  c2_info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[21].fileTimeLo = 1286822442U;
  c2_info[21].fileTimeHi = 0U;
  c2_info[21].mFileTimeLo = 0U;
  c2_info[21].mFileTimeHi = 0U;
  c2_info[22].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[22].name = "power";
  c2_info[22].dominantType = "double";
  c2_info[22].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[22].fileTimeLo = 1336525696U;
  c2_info[22].fileTimeHi = 0U;
  c2_info[22].mFileTimeLo = 0U;
  c2_info[22].mFileTimeHi = 0U;
  c2_info[23].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c2_info[23].name = "eml_scalar_eg";
  c2_info[23].dominantType = "double";
  c2_info[23].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[23].fileTimeLo = 1286822396U;
  c2_info[23].fileTimeHi = 0U;
  c2_info[23].mFileTimeLo = 0U;
  c2_info[23].mFileTimeHi = 0U;
  c2_info[24].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c2_info[24].name = "eml_scalexp_alloc";
  c2_info[24].dominantType = "double";
  c2_info[24].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c2_info[24].fileTimeLo = 1330612034U;
  c2_info[24].fileTimeHi = 0U;
  c2_info[24].mFileTimeLo = 0U;
  c2_info[24].mFileTimeHi = 0U;
  c2_info[25].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c2_info[25].name = "floor";
  c2_info[25].dominantType = "double";
  c2_info[25].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c2_info[25].fileTimeLo = 1286822342U;
  c2_info[25].fileTimeHi = 0U;
  c2_info[25].mFileTimeLo = 0U;
  c2_info[25].mFileTimeHi = 0U;
  c2_info[26].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c2_info[26].name = "eml_scalar_floor";
  c2_info[26].dominantType = "double";
  c2_info[26].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c2_info[26].fileTimeLo = 1286822326U;
  c2_info[26].fileTimeHi = 0U;
  c2_info[26].mFileTimeLo = 0U;
  c2_info[26].mFileTimeHi = 0U;
  c2_info[27].context = "";
  c2_info[27].name = "mrdivide";
  c2_info[27].dominantType = "double";
  c2_info[27].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[27].fileTimeLo = 1342814544U;
  c2_info[27].fileTimeHi = 0U;
  c2_info[27].mFileTimeLo = 1319733566U;
  c2_info[27].mFileTimeHi = 0U;
  c2_info[28].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[28].name = "rdivide";
  c2_info[28].dominantType = "double";
  c2_info[28].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[28].fileTimeLo = 1286822444U;
  c2_info[28].fileTimeHi = 0U;
  c2_info[28].mFileTimeLo = 0U;
  c2_info[28].mFileTimeHi = 0U;
  c2_info[29].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[29].name = "eml_div";
  c2_info[29].dominantType = "double";
  c2_info[29].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c2_info[29].fileTimeLo = 1313351410U;
  c2_info[29].fileTimeHi = 0U;
  c2_info[29].mFileTimeLo = 0U;
  c2_info[29].mFileTimeHi = 0U;
}

static void c2_eml_scalar_eg(SFc2_canudas_goalInstanceStruct *chartInstance)
{
}

static real_T c2_abs(SFc2_canudas_goalInstanceStruct *chartInstance, real_T c2_x)
{
  real_T c2_b_x;
  c2_b_x = c2_x;
  return muDoubleScalarAbs(c2_b_x);
}

static real_T c2_atan2(SFc2_canudas_goalInstanceStruct *chartInstance, real_T
  c2_y, real_T c2_x)
{
  real_T c2_b_y;
  real_T c2_b_x;
  c2_b_eml_scalar_eg(chartInstance);
  c2_b_y = c2_y;
  c2_b_x = c2_x;
  return muDoubleScalarAtan2(c2_b_y, c2_b_x);
}

static void c2_b_eml_scalar_eg(SFc2_canudas_goalInstanceStruct *chartInstance)
{
}

static real_T c2_limit_angle(SFc2_canudas_goalInstanceStruct *chartInstance,
  real_T c2_angle)
{
  real_T c2_b_angle;
  uint32_T c2_debug_family_var_map[3];
  real_T c2_nargin = 1.0;
  real_T c2_nargout = 1.0;
  int32_T exitg1;
  boolean_T guard1 = FALSE;
  sf_debug_symbol_scope_push_eml(0U, 3U, 4U, c2_b_debug_family_names,
    c2_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargin, 0U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargout, 1U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_angle, 2U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_b_angle, MAX_uint32_T,
    c2_b_sf_marshallOut, c2_b_sf_marshallIn);
  c2_b_angle = c2_angle;
  sf_debug_symbol_switch(2U, 3U);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 8);
  do {
    exitg1 = 0;
    guard1 = FALSE;
    if (c2_b_angle <= -3.1415926535897931) {
      guard1 = TRUE;
    } else if (c2_b_angle > 3.1415926535897931) {
      guard1 = TRUE;
    } else {
      exitg1 = 1;
    }

    if (guard1 == TRUE) {
      CV_SCRIPT_WHILE(0, 0, TRUE);
      _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 9);
      if (CV_SCRIPT_IF(0, 0, c2_b_angle <= -3.1415926535897931)) {
        _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 10);
        c2_b_angle += 6.2831853071795862;
        sf_debug_symbol_switch(2U, 3U);
      } else {
        _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 12);
        c2_b_angle -= 6.2831853071795862;
        sf_debug_symbol_switch(2U, 3U);
      }

      _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 8);
      sf_mex_listen_for_ctrl_c(chartInstance->S);
    }
  } while (exitg1 == 0);

  CV_SCRIPT_WHILE(0, 0, FALSE);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, -12);
  sf_debug_symbol_scope_pop();
  return c2_b_angle;
}

static real_T c2_mpower(SFc2_canudas_goalInstanceStruct *chartInstance, real_T
  c2_a)
{
  real_T c2_b_a;
  real_T c2_c_a;
  real_T c2_ak;
  c2_b_a = c2_a;
  c2_c_a = c2_b_a;
  c2_b_eml_scalar_eg(chartInstance);
  c2_ak = c2_c_a;
  return muDoubleScalarPower(c2_ak, 2.0);
}

static void c2_c_eml_scalar_eg(SFc2_canudas_goalInstanceStruct *chartInstance)
{
}

static void c2_d_eml_scalar_eg(SFc2_canudas_goalInstanceStruct *chartInstance)
{
}

static const mxArray *c2_g_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_canudas_goalInstanceStruct *chartInstance;
  chartInstance = (SFc2_canudas_goalInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static int32_T c2_i_emlrt_marshallIn(SFc2_canudas_goalInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i89;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i89, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i89;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_canudas_goalInstanceStruct *chartInstance;
  chartInstance = (SFc2_canudas_goalInstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_j_emlrt_marshallIn(SFc2_canudas_goalInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_canudas_goal, const char_T
  *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_canudas_goal), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_canudas_goal);
  return c2_y;
}

static uint8_T c2_k_emlrt_marshallIn(SFc2_canudas_goalInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void init_dsm_address_info(SFc2_canudas_goalInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c2_canudas_goal_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2001500625U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1697106138U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3555579194U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3458294020U);
}

mxArray *sf_c2_canudas_goal_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("yAz6Cmw3Zmkh6Nnl1ZpFMG");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
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
      pr[0] = (double)(3);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c2_canudas_goal(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[7],T\"qe\",},{M[1],M[5],T\"v\",},{M[1],M[9],T\"w\",},{M[8],M[0],T\"is_active_c2_canudas_goal\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_canudas_goal_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_canudas_goalInstanceStruct *chartInstance;
    chartInstance = (SFc2_canudas_goalInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_canudas_goalMachineNumber_,
           2,
           1,
           1,
           8,
           0,
           0,
           0,
           0,
           1,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_canudas_goalMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_canudas_goalMachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_canudas_goalMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"q");
          _SFD_SET_DATA_PROPS(1,2,0,1,"v");
          _SFD_SET_DATA_PROPS(2,2,0,1,"w");
          _SFD_SET_DATA_PROPS(3,1,1,0,"qr");
          _SFD_SET_DATA_PROPS(4,2,0,1,"qe");
          _SFD_SET_DATA_PROPS(5,1,1,0,"eps");
          _SFD_SET_DATA_PROPS(6,1,1,0,"K1");
          _SFD_SET_DATA_PROPS(7,1,1,0,"K2");
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
        _SFD_CV_INIT_EML(0,1,1,2,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,895);
        _SFD_CV_INIT_EML_IF(0,1,0,314,355,372,449);
        _SFD_CV_INIT_EML_IF(0,1,1,451,469,481,528);

        {
          static int condStart[] = { 318, 338 };

          static int condEnd[] = { 332, 353 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,317,354,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        _SFD_CV_INIT_SCRIPT(0,1,1,0,0,0,0,1,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"limit_angle",0,-1,297);
        _SFD_CV_INIT_SCRIPT_IF(0,0,195,211,246,288);
        _SFD_CV_INIT_SCRIPT_WHILE(0,0,153,190,292);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_b_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)
            c2_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c2_v;
          real_T *c2_w;
          real_T *c2_eps;
          real_T *c2_K1;
          real_T *c2_K2;
          real_T (*c2_q)[3];
          real_T (*c2_qr)[3];
          real_T (*c2_qe)[3];
          c2_K2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c2_K1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c2_eps = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c2_qe = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 3);
          c2_qr = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
          c2_w = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c2_v = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c2_q = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c2_q);
          _SFD_SET_DATA_VALUE_PTR(1U, c2_v);
          _SFD_SET_DATA_VALUE_PTR(2U, c2_w);
          _SFD_SET_DATA_VALUE_PTR(3U, *c2_qr);
          _SFD_SET_DATA_VALUE_PTR(4U, *c2_qe);
          _SFD_SET_DATA_VALUE_PTR(5U, c2_eps);
          _SFD_SET_DATA_VALUE_PTR(6U, c2_K1);
          _SFD_SET_DATA_VALUE_PTR(7U, c2_K2);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_canudas_goalMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization()
{
  return "8Cv7t7K7xBqzCUo2M2zGUH";
}

static void sf_opaque_initialize_c2_canudas_goal(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_canudas_goalInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_canudas_goal((SFc2_canudas_goalInstanceStruct*)
    chartInstanceVar);
  initialize_c2_canudas_goal((SFc2_canudas_goalInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_canudas_goal(void *chartInstanceVar)
{
  enable_c2_canudas_goal((SFc2_canudas_goalInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_canudas_goal(void *chartInstanceVar)
{
  disable_c2_canudas_goal((SFc2_canudas_goalInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_canudas_goal(void *chartInstanceVar)
{
  sf_c2_canudas_goal((SFc2_canudas_goalInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_canudas_goal(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_canudas_goal
    ((SFc2_canudas_goalInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_canudas_goal();/* state var info */
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

extern void sf_internal_set_sim_state_c2_canudas_goal(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_canudas_goal();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_canudas_goal((SFc2_canudas_goalInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_canudas_goal(SimStruct* S)
{
  return sf_internal_get_sim_state_c2_canudas_goal(S);
}

static void sf_opaque_set_sim_state_c2_canudas_goal(SimStruct* S, const mxArray *
  st)
{
  sf_internal_set_sim_state_c2_canudas_goal(S, st);
}

static void sf_opaque_terminate_c2_canudas_goal(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_canudas_goalInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c2_canudas_goal((SFc2_canudas_goalInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_canudas_goal_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_canudas_goal((SFc2_canudas_goalInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_canudas_goal(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_canudas_goal((SFc2_canudas_goalInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_canudas_goal(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_canudas_goal_optimization_info();
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
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,5);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,3);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3112031659U));
  ssSetChecksum1(S,(135022071U));
  ssSetChecksum2(S,(2446360019U));
  ssSetChecksum3(S,(3589361427U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c2_canudas_goal(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_canudas_goal(SimStruct *S)
{
  SFc2_canudas_goalInstanceStruct *chartInstance;
  chartInstance = (SFc2_canudas_goalInstanceStruct *)malloc(sizeof
    (SFc2_canudas_goalInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_canudas_goalInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c2_canudas_goal;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_canudas_goal;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c2_canudas_goal;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_canudas_goal;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_canudas_goal;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c2_canudas_goal;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c2_canudas_goal;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_canudas_goal;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_canudas_goal;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_canudas_goal;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_canudas_goal;
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

void c2_canudas_goal_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_canudas_goal(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_canudas_goal(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_canudas_goal(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_canudas_goal_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
