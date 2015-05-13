/* Include files */

#include "blascompat32.h"
#include "canudas_goal2_sfun.h"
#include "c3_canudas_goal2.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "canudas_goal2_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c3_debug_family_names[12] = { "b", "b1", "b2", "nargin",
  "nargout", "z", "thetad", "qe", "k1", "k2", "w", "v" };

/* Function Declarations */
static void initialize_c3_canudas_goal2(SFc3_canudas_goal2InstanceStruct
  *chartInstance);
static void initialize_params_c3_canudas_goal2(SFc3_canudas_goal2InstanceStruct *
  chartInstance);
static void enable_c3_canudas_goal2(SFc3_canudas_goal2InstanceStruct
  *chartInstance);
static void disable_c3_canudas_goal2(SFc3_canudas_goal2InstanceStruct
  *chartInstance);
static void c3_update_debugger_state_c3_canudas_goal2
  (SFc3_canudas_goal2InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c3_canudas_goal2
  (SFc3_canudas_goal2InstanceStruct *chartInstance);
static void set_sim_state_c3_canudas_goal2(SFc3_canudas_goal2InstanceStruct
  *chartInstance, const mxArray *c3_st);
static void finalize_c3_canudas_goal2(SFc3_canudas_goal2InstanceStruct
  *chartInstance);
static void sf_c3_canudas_goal2(SFc3_canudas_goal2InstanceStruct *chartInstance);
static void initSimStructsc3_canudas_goal2(SFc3_canudas_goal2InstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static real_T c3_emlrt_marshallIn(SFc3_canudas_goal2InstanceStruct
  *chartInstance, const mxArray *c3_v, const char_T *c3_identifier);
static real_T c3_b_emlrt_marshallIn(SFc3_canudas_goal2InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_info_helper(c3_ResolvedFunctionInfo c3_info[14]);
static real_T c3_mpower(SFc3_canudas_goal2InstanceStruct *chartInstance, real_T
  c3_a);
static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_c_emlrt_marshallIn(SFc3_canudas_goal2InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static uint8_T c3_d_emlrt_marshallIn(SFc3_canudas_goal2InstanceStruct
  *chartInstance, const mxArray *c3_b_is_active_c3_canudas_goal2, const char_T
  *c3_identifier);
static uint8_T c3_e_emlrt_marshallIn(SFc3_canudas_goal2InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void init_dsm_address_info(SFc3_canudas_goal2InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c3_canudas_goal2(SFc3_canudas_goal2InstanceStruct
  *chartInstance)
{
  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c3_is_active_c3_canudas_goal2 = 0U;
}

static void initialize_params_c3_canudas_goal2(SFc3_canudas_goal2InstanceStruct *
  chartInstance)
{
}

static void enable_c3_canudas_goal2(SFc3_canudas_goal2InstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c3_canudas_goal2(SFc3_canudas_goal2InstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c3_update_debugger_state_c3_canudas_goal2
  (SFc3_canudas_goal2InstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c3_canudas_goal2
  (SFc3_canudas_goal2InstanceStruct *chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  real_T c3_hoistedGlobal;
  real_T c3_u;
  const mxArray *c3_b_y = NULL;
  real_T c3_b_hoistedGlobal;
  real_T c3_b_u;
  const mxArray *c3_c_y = NULL;
  uint8_T c3_c_hoistedGlobal;
  uint8_T c3_c_u;
  const mxArray *c3_d_y = NULL;
  real_T *c3_v;
  real_T *c3_w;
  c3_v = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_w = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellarray(3), FALSE);
  c3_hoistedGlobal = *c3_v;
  c3_u = c3_hoistedGlobal;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_b_hoistedGlobal = *c3_w;
  c3_b_u = c3_b_hoistedGlobal;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 1, c3_c_y);
  c3_c_hoistedGlobal = chartInstance->c3_is_active_c3_canudas_goal2;
  c3_c_u = c3_c_hoistedGlobal;
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 2, c3_d_y);
  sf_mex_assign(&c3_st, c3_y, FALSE);
  return c3_st;
}

static void set_sim_state_c3_canudas_goal2(SFc3_canudas_goal2InstanceStruct
  *chartInstance, const mxArray *c3_st)
{
  const mxArray *c3_u;
  real_T *c3_v;
  real_T *c3_w;
  c3_v = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_w = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c3_doneDoubleBufferReInit = TRUE;
  c3_u = sf_mex_dup(c3_st);
  *c3_v = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 0)),
    "v");
  *c3_w = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 1)),
    "w");
  chartInstance->c3_is_active_c3_canudas_goal2 = c3_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 2)),
     "is_active_c3_canudas_goal2");
  sf_mex_destroy(&c3_u);
  c3_update_debugger_state_c3_canudas_goal2(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void finalize_c3_canudas_goal2(SFc3_canudas_goal2InstanceStruct
  *chartInstance)
{
}

static void sf_c3_canudas_goal2(SFc3_canudas_goal2InstanceStruct *chartInstance)
{
  int32_T c3_i0;
  int32_T c3_i1;
  real_T c3_hoistedGlobal;
  real_T c3_b_hoistedGlobal;
  real_T c3_c_hoistedGlobal;
  int32_T c3_i2;
  real_T c3_z[2];
  real_T c3_thetad;
  int32_T c3_i3;
  real_T c3_qe[3];
  real_T c3_k1;
  real_T c3_k2;
  uint32_T c3_debug_family_var_map[12];
  real_T c3_b;
  real_T c3_b1;
  real_T c3_b2;
  real_T c3_nargin = 5.0;
  real_T c3_nargout = 2.0;
  real_T c3_w;
  real_T c3_v;
  real_T c3_A;
  real_T c3_B;
  real_T c3_x;
  real_T c3_y;
  real_T c3_b_x;
  real_T c3_b_y;
  real_T c3_c_x;
  real_T c3_d_x;
  real_T c3_b_A;
  real_T c3_b_B;
  real_T c3_e_x;
  real_T c3_c_y;
  real_T c3_f_x;
  real_T c3_d_y;
  real_T c3_e_y;
  real_T c3_a;
  real_T c3_b_b;
  real_T c3_f_y;
  real_T c3_g_x;
  real_T c3_h_x;
  real_T c3_c_B;
  real_T c3_g_y;
  real_T c3_h_y;
  real_T c3_i_y;
  real_T c3_b_a;
  real_T c3_c_b;
  real_T c3_j_y;
  real_T c3_c_A;
  real_T c3_i_x;
  real_T c3_j_x;
  real_T c3_k_y;
  real_T c3_d_B;
  real_T c3_l_y;
  real_T c3_m_y;
  real_T c3_n_y;
  real_T c3_c_a;
  real_T c3_d_b;
  real_T c3_o_y;
  real_T c3_k_x;
  real_T c3_l_x;
  real_T c3_d_a;
  real_T c3_p_y;
  real_T c3_e_a;
  real_T c3_e_b;
  real_T c3_q_y;
  real_T c3_f_a;
  real_T c3_f_b;
  real_T c3_r_y;
  real_T c3_d_A;
  real_T c3_e_B;
  real_T c3_m_x;
  real_T c3_s_y;
  real_T c3_n_x;
  real_T c3_t_y;
  real_T c3_u_y;
  real_T c3_o_x;
  real_T c3_p_x;
  real_T c3_g_a;
  real_T c3_v_y;
  real_T c3_h_a;
  real_T c3_g_b;
  real_T c3_w_y;
  real_T c3_e_A;
  real_T c3_f_B;
  real_T c3_q_x;
  real_T c3_x_y;
  real_T c3_r_x;
  real_T c3_y_y;
  real_T c3_ab_y;
  real_T c3_i_a;
  real_T c3_h_b;
  real_T c3_bb_y;
  real_T c3_j_a;
  real_T c3_i_b;
  real_T c3_k_a;
  real_T c3_j_b;
  real_T c3_cb_y;
  real_T c3_l_a;
  real_T c3_k_b;
  real_T c3_db_y;
  real_T *c3_b_v;
  real_T *c3_b_w;
  real_T *c3_b_k2;
  real_T *c3_b_k1;
  real_T *c3_b_thetad;
  real_T (*c3_b_qe)[3];
  real_T (*c3_b_z)[2];
  c3_b_k2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c3_b_k1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c3_b_qe = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 2);
  c3_b_v = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_b_thetad = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c3_b_z = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 0);
  c3_b_w = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c3_b_w, 0U);
  for (c3_i0 = 0; c3_i0 < 2; c3_i0++) {
    _SFD_DATA_RANGE_CHECK((*c3_b_z)[c3_i0], 1U);
  }

  _SFD_DATA_RANGE_CHECK(*c3_b_thetad, 2U);
  _SFD_DATA_RANGE_CHECK(*c3_b_v, 3U);
  for (c3_i1 = 0; c3_i1 < 3; c3_i1++) {
    _SFD_DATA_RANGE_CHECK((*c3_b_qe)[c3_i1], 4U);
  }

  _SFD_DATA_RANGE_CHECK(*c3_b_k1, 5U);
  _SFD_DATA_RANGE_CHECK(*c3_b_k2, 6U);
  chartInstance->c3_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  c3_hoistedGlobal = *c3_b_thetad;
  c3_b_hoistedGlobal = *c3_b_k1;
  c3_c_hoistedGlobal = *c3_b_k2;
  for (c3_i2 = 0; c3_i2 < 2; c3_i2++) {
    c3_z[c3_i2] = (*c3_b_z)[c3_i2];
  }

  c3_thetad = c3_hoistedGlobal;
  for (c3_i3 = 0; c3_i3 < 3; c3_i3++) {
    c3_qe[c3_i3] = (*c3_b_qe)[c3_i3];
  }

  c3_k1 = c3_b_hoistedGlobal;
  c3_k2 = c3_c_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 12U, 12U, c3_debug_family_names,
    c3_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c3_b, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_b1, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_b2, 2U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_nargin, 3U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_nargout, 4U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c3_z, 5U, c3_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_thetad, 6U, c3_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c3_qe, 7U, c3_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_k1, 8U, c3_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_k2, 9U, c3_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c3_w, 10U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_v, 11U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 4);
  c3_A = c3_qe[1];
  c3_B = c3_qe[0];
  c3_x = c3_A;
  c3_y = c3_B;
  c3_b_x = c3_x;
  c3_b_y = c3_y;
  c3_b = c3_b_x / c3_b_y;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 5);
  c3_c_x = c3_qe[2];
  c3_d_x = c3_c_x;
  c3_d_x = muDoubleScalarCos(c3_d_x);
  c3_b_A = c3_thetad;
  c3_b_B = c3_b;
  c3_e_x = c3_b_A;
  c3_c_y = c3_b_B;
  c3_f_x = c3_e_x;
  c3_d_y = c3_c_y;
  c3_e_y = c3_f_x / c3_d_y;
  c3_a = c3_d_x;
  c3_b_b = c3_e_y - 1.0;
  c3_f_y = c3_a * c3_b_b;
  c3_g_x = c3_qe[2];
  c3_h_x = c3_g_x;
  c3_h_x = muDoubleScalarSin(c3_h_x);
  c3_c_B = c3_mpower(chartInstance, c3_b);
  c3_g_y = c3_c_B;
  c3_h_y = c3_g_y;
  c3_i_y = 1.0 / c3_h_y;
  c3_b_a = c3_thetad;
  c3_c_b = 1.0 - c3_i_y;
  c3_j_y = c3_b_a * c3_c_b;
  c3_c_A = c3_j_y;
  c3_i_x = c3_c_A;
  c3_j_x = c3_i_x;
  c3_k_y = c3_j_x / 2.0;
  c3_d_B = c3_b;
  c3_l_y = c3_d_B;
  c3_m_y = c3_l_y;
  c3_n_y = 1.0 / c3_m_y;
  c3_c_a = c3_h_x;
  c3_d_b = c3_k_y + c3_n_y;
  c3_o_y = c3_c_a * c3_d_b;
  c3_b1 = c3_f_y + c3_o_y;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 6);
  c3_k_x = c3_qe[2];
  c3_l_x = c3_k_x;
  c3_l_x = muDoubleScalarCos(c3_l_x);
  c3_d_a = c3_l_x;
  c3_p_y = c3_d_a * 2.0;
  c3_e_a = c3_p_y;
  c3_e_b = c3_b;
  c3_q_y = c3_e_a * c3_e_b;
  c3_f_a = 1.0 + c3_mpower(chartInstance, c3_b);
  c3_f_b = c3_qe[0];
  c3_r_y = c3_f_a * c3_f_b;
  c3_d_A = c3_q_y;
  c3_e_B = c3_r_y;
  c3_m_x = c3_d_A;
  c3_s_y = c3_e_B;
  c3_n_x = c3_m_x;
  c3_t_y = c3_s_y;
  c3_u_y = c3_n_x / c3_t_y;
  c3_o_x = c3_qe[2];
  c3_p_x = c3_o_x;
  c3_p_x = muDoubleScalarSin(c3_p_x);
  c3_g_a = c3_p_x;
  c3_v_y = c3_g_a * 2.0;
  c3_h_a = 1.0 + c3_mpower(chartInstance, c3_b);
  c3_g_b = c3_qe[0];
  c3_w_y = c3_h_a * c3_g_b;
  c3_e_A = c3_v_y;
  c3_f_B = c3_w_y;
  c3_q_x = c3_e_A;
  c3_x_y = c3_f_B;
  c3_r_x = c3_q_x;
  c3_y_y = c3_x_y;
  c3_ab_y = c3_r_x / c3_y_y;
  c3_b2 = c3_u_y - c3_ab_y;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 8);
  c3_i_a = -c3_k1;
  c3_h_b = c3_b1;
  c3_bb_y = c3_i_a * c3_h_b;
  c3_j_a = c3_bb_y;
  c3_i_b = c3_z[0];
  c3_v = c3_j_a * c3_i_b;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 9);
  c3_k_a = -c3_b2;
  c3_j_b = c3_v;
  c3_cb_y = c3_k_a * c3_j_b;
  c3_l_a = c3_k2;
  c3_k_b = c3_z[1];
  c3_db_y = c3_l_a * c3_k_b;
  c3_w = c3_cb_y - c3_db_y;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -9);
  sf_debug_symbol_scope_pop();
  *c3_b_w = c3_w;
  *c3_b_v = c3_v;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  sf_debug_check_for_state_inconsistency(_canudas_goal2MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc3_canudas_goal2(SFc3_canudas_goal2InstanceStruct
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
  SFc3_canudas_goal2InstanceStruct *chartInstance;
  chartInstance = (SFc3_canudas_goal2InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static real_T c3_emlrt_marshallIn(SFc3_canudas_goal2InstanceStruct
  *chartInstance, const mxArray *c3_v, const char_T *c3_identifier)
{
  real_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_v), &c3_thisId);
  sf_mex_destroy(&c3_v);
  return c3_y;
}

static real_T c3_b_emlrt_marshallIn(SFc3_canudas_goal2InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d0;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d0, 1, 0, 0U, 0, 0U, 0);
  c3_y = c3_d0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_v;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_canudas_goal2InstanceStruct *chartInstance;
  chartInstance = (SFc3_canudas_goal2InstanceStruct *)chartInstanceVoid;
  c3_v = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_v), &c3_thisId);
  sf_mex_destroy(&c3_v);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i4;
  real_T c3_b_inData[3];
  int32_T c3_i5;
  real_T c3_u[3];
  const mxArray *c3_y = NULL;
  SFc3_canudas_goal2InstanceStruct *chartInstance;
  chartInstance = (SFc3_canudas_goal2InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i4 = 0; c3_i4 < 3; c3_i4++) {
    c3_b_inData[c3_i4] = (*(real_T (*)[3])c3_inData)[c3_i4];
  }

  for (c3_i5 = 0; c3_i5 < 3; c3_i5++) {
    c3_u[c3_i5] = c3_b_inData[c3_i5];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i6;
  real_T c3_b_inData[2];
  int32_T c3_i7;
  real_T c3_u[2];
  const mxArray *c3_y = NULL;
  SFc3_canudas_goal2InstanceStruct *chartInstance;
  chartInstance = (SFc3_canudas_goal2InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i6 = 0; c3_i6 < 2; c3_i6++) {
    c3_b_inData[c3_i6] = (*(real_T (*)[2])c3_inData)[c3_i6];
  }

  for (c3_i7 = 0; c3_i7 < 2; c3_i7++) {
    c3_u[c3_i7] = c3_b_inData[c3_i7];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 2), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

const mxArray *sf_c3_canudas_goal2_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo;
  c3_ResolvedFunctionInfo c3_info[14];
  const mxArray *c3_m0 = NULL;
  int32_T c3_i8;
  c3_ResolvedFunctionInfo *c3_r0;
  c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  c3_info_helper(c3_info);
  sf_mex_assign(&c3_m0, sf_mex_createstruct("nameCaptureInfo", 1, 14), FALSE);
  for (c3_i8 = 0; c3_i8 < 14; c3_i8++) {
    c3_r0 = &c3_info[c3_i8];
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->context)), "context", "nameCaptureInfo",
                    c3_i8);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c3_r0->name)), "name", "nameCaptureInfo", c3_i8);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c3_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c3_i8);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->resolved)), "resolved", "nameCaptureInfo",
                    c3_i8);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c3_i8);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c3_i8);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c3_i8);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c3_i8);
  }

  sf_mex_assign(&c3_nameCaptureInfo, c3_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c3_nameCaptureInfo);
  return c3_nameCaptureInfo;
}

static void c3_info_helper(c3_ResolvedFunctionInfo c3_info[14])
{
  c3_info[0].context = "";
  c3_info[0].name = "mrdivide";
  c3_info[0].dominantType = "double";
  c3_info[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c3_info[0].fileTimeLo = 1342814544U;
  c3_info[0].fileTimeHi = 0U;
  c3_info[0].mFileTimeLo = 1319733566U;
  c3_info[0].mFileTimeHi = 0U;
  c3_info[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c3_info[1].name = "rdivide";
  c3_info[1].dominantType = "double";
  c3_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c3_info[1].fileTimeLo = 1286822444U;
  c3_info[1].fileTimeHi = 0U;
  c3_info[1].mFileTimeLo = 0U;
  c3_info[1].mFileTimeHi = 0U;
  c3_info[2].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c3_info[2].name = "eml_div";
  c3_info[2].dominantType = "double";
  c3_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c3_info[2].fileTimeLo = 1313351410U;
  c3_info[2].fileTimeHi = 0U;
  c3_info[2].mFileTimeLo = 0U;
  c3_info[2].mFileTimeHi = 0U;
  c3_info[3].context = "";
  c3_info[3].name = "cos";
  c3_info[3].dominantType = "double";
  c3_info[3].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c3_info[3].fileTimeLo = 1286822306U;
  c3_info[3].fileTimeHi = 0U;
  c3_info[3].mFileTimeLo = 0U;
  c3_info[3].mFileTimeHi = 0U;
  c3_info[4].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c3_info[4].name = "eml_scalar_cos";
  c3_info[4].dominantType = "double";
  c3_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c3_info[4].fileTimeLo = 1286822322U;
  c3_info[4].fileTimeHi = 0U;
  c3_info[4].mFileTimeLo = 0U;
  c3_info[4].mFileTimeHi = 0U;
  c3_info[5].context = "";
  c3_info[5].name = "mtimes";
  c3_info[5].dominantType = "double";
  c3_info[5].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[5].fileTimeLo = 1289523292U;
  c3_info[5].fileTimeHi = 0U;
  c3_info[5].mFileTimeLo = 0U;
  c3_info[5].mFileTimeHi = 0U;
  c3_info[6].context = "";
  c3_info[6].name = "sin";
  c3_info[6].dominantType = "double";
  c3_info[6].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c3_info[6].fileTimeLo = 1286822350U;
  c3_info[6].fileTimeHi = 0U;
  c3_info[6].mFileTimeLo = 0U;
  c3_info[6].mFileTimeHi = 0U;
  c3_info[7].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c3_info[7].name = "eml_scalar_sin";
  c3_info[7].dominantType = "double";
  c3_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c3_info[7].fileTimeLo = 1286822336U;
  c3_info[7].fileTimeHi = 0U;
  c3_info[7].mFileTimeLo = 0U;
  c3_info[7].mFileTimeHi = 0U;
  c3_info[8].context = "";
  c3_info[8].name = "mpower";
  c3_info[8].dominantType = "double";
  c3_info[8].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c3_info[8].fileTimeLo = 1286822442U;
  c3_info[8].fileTimeHi = 0U;
  c3_info[8].mFileTimeLo = 0U;
  c3_info[8].mFileTimeHi = 0U;
  c3_info[9].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c3_info[9].name = "power";
  c3_info[9].dominantType = "double";
  c3_info[9].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c3_info[9].fileTimeLo = 1336525696U;
  c3_info[9].fileTimeHi = 0U;
  c3_info[9].mFileTimeLo = 0U;
  c3_info[9].mFileTimeHi = 0U;
  c3_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c3_info[10].name = "eml_scalar_eg";
  c3_info[10].dominantType = "double";
  c3_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c3_info[10].fileTimeLo = 1286822396U;
  c3_info[10].fileTimeHi = 0U;
  c3_info[10].mFileTimeLo = 0U;
  c3_info[10].mFileTimeHi = 0U;
  c3_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c3_info[11].name = "eml_scalexp_alloc";
  c3_info[11].dominantType = "double";
  c3_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c3_info[11].fileTimeLo = 1330612034U;
  c3_info[11].fileTimeHi = 0U;
  c3_info[11].mFileTimeLo = 0U;
  c3_info[11].mFileTimeHi = 0U;
  c3_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c3_info[12].name = "floor";
  c3_info[12].dominantType = "double";
  c3_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c3_info[12].fileTimeLo = 1286822342U;
  c3_info[12].fileTimeHi = 0U;
  c3_info[12].mFileTimeLo = 0U;
  c3_info[12].mFileTimeHi = 0U;
  c3_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c3_info[13].name = "eml_scalar_floor";
  c3_info[13].dominantType = "double";
  c3_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c3_info[13].fileTimeLo = 1286822326U;
  c3_info[13].fileTimeHi = 0U;
  c3_info[13].mFileTimeLo = 0U;
  c3_info[13].mFileTimeHi = 0U;
}

static real_T c3_mpower(SFc3_canudas_goal2InstanceStruct *chartInstance, real_T
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

static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_canudas_goal2InstanceStruct *chartInstance;
  chartInstance = (SFc3_canudas_goal2InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static int32_T c3_c_emlrt_marshallIn(SFc3_canudas_goal2InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i9;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i9, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i9;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_sfEvent;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y;
  SFc3_canudas_goal2InstanceStruct *chartInstance;
  chartInstance = (SFc3_canudas_goal2InstanceStruct *)chartInstanceVoid;
  c3_b_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent),
    &c3_thisId);
  sf_mex_destroy(&c3_b_sfEvent);
  *(int32_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static uint8_T c3_d_emlrt_marshallIn(SFc3_canudas_goal2InstanceStruct
  *chartInstance, const mxArray *c3_b_is_active_c3_canudas_goal2, const char_T
  *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_is_active_c3_canudas_goal2), &c3_thisId);
  sf_mex_destroy(&c3_b_is_active_c3_canudas_goal2);
  return c3_y;
}

static uint8_T c3_e_emlrt_marshallIn(SFc3_canudas_goal2InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_y;
  uint8_T c3_u0;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u0, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_u0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void init_dsm_address_info(SFc3_canudas_goal2InstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c3_canudas_goal2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1909151622U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1035360815U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2148861727U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3807504516U);
}

mxArray *sf_c3_canudas_goal2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("FdTFpQZxbb4xnt8rgyBND");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);

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

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c3_canudas_goal2(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[10],T\"v\",},{M[1],M[11],T\"w\",},{M[8],M[0],T\"is_active_c3_canudas_goal2\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_canudas_goal2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_canudas_goal2InstanceStruct *chartInstance;
    chartInstance = (SFc3_canudas_goal2InstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_canudas_goal2MachineNumber_,
           3,
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
          init_script_number_translation(_canudas_goal2MachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_canudas_goal2MachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_canudas_goal2MachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,2,0,1,"w");
          _SFD_SET_DATA_PROPS(1,1,1,0,"z");
          _SFD_SET_DATA_PROPS(2,1,1,0,"thetad");
          _SFD_SET_DATA_PROPS(3,2,0,1,"v");
          _SFD_SET_DATA_PROPS(4,1,1,0,"qe");
          _SFD_SET_DATA_PROPS(5,1,1,0,"k1");
          _SFD_SET_DATA_PROPS(6,1,1,0,"k2");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,323);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c3_w;
          real_T *c3_thetad;
          real_T *c3_v;
          real_T *c3_k1;
          real_T *c3_k2;
          real_T (*c3_z)[2];
          real_T (*c3_qe)[3];
          c3_k2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c3_k1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c3_qe = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 2);
          c3_v = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c3_thetad = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c3_z = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 0);
          c3_w = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c3_w);
          _SFD_SET_DATA_VALUE_PTR(1U, *c3_z);
          _SFD_SET_DATA_VALUE_PTR(2U, c3_thetad);
          _SFD_SET_DATA_VALUE_PTR(3U, c3_v);
          _SFD_SET_DATA_VALUE_PTR(4U, *c3_qe);
          _SFD_SET_DATA_VALUE_PTR(5U, c3_k1);
          _SFD_SET_DATA_VALUE_PTR(6U, c3_k2);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_canudas_goal2MachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization()
{
  return "xUJklHItFpEhkcIUhKOTdF";
}

static void sf_opaque_initialize_c3_canudas_goal2(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc3_canudas_goal2InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c3_canudas_goal2((SFc3_canudas_goal2InstanceStruct*)
    chartInstanceVar);
  initialize_c3_canudas_goal2((SFc3_canudas_goal2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c3_canudas_goal2(void *chartInstanceVar)
{
  enable_c3_canudas_goal2((SFc3_canudas_goal2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c3_canudas_goal2(void *chartInstanceVar)
{
  disable_c3_canudas_goal2((SFc3_canudas_goal2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c3_canudas_goal2(void *chartInstanceVar)
{
  sf_c3_canudas_goal2((SFc3_canudas_goal2InstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c3_canudas_goal2(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c3_canudas_goal2
    ((SFc3_canudas_goal2InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_canudas_goal2();/* state var info */
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

extern void sf_internal_set_sim_state_c3_canudas_goal2(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_canudas_goal2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c3_canudas_goal2((SFc3_canudas_goal2InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c3_canudas_goal2(SimStruct* S)
{
  return sf_internal_get_sim_state_c3_canudas_goal2(S);
}

static void sf_opaque_set_sim_state_c3_canudas_goal2(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c3_canudas_goal2(S, st);
}

static void sf_opaque_terminate_c3_canudas_goal2(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_canudas_goal2InstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c3_canudas_goal2((SFc3_canudas_goal2InstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_canudas_goal2_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_canudas_goal2((SFc3_canudas_goal2InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_canudas_goal2(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c3_canudas_goal2((SFc3_canudas_goal2InstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c3_canudas_goal2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_canudas_goal2_optimization_info();
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
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,3,5);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,3,2);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2487194377U));
  ssSetChecksum1(S,(2572361250U));
  ssSetChecksum2(S,(1966210929U));
  ssSetChecksum3(S,(170559059U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c3_canudas_goal2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c3_canudas_goal2(SimStruct *S)
{
  SFc3_canudas_goal2InstanceStruct *chartInstance;
  chartInstance = (SFc3_canudas_goal2InstanceStruct *)malloc(sizeof
    (SFc3_canudas_goal2InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc3_canudas_goal2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c3_canudas_goal2;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c3_canudas_goal2;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c3_canudas_goal2;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_canudas_goal2;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c3_canudas_goal2;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c3_canudas_goal2;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c3_canudas_goal2;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c3_canudas_goal2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_canudas_goal2;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_canudas_goal2;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c3_canudas_goal2;
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

void c3_canudas_goal2_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_canudas_goal2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_canudas_goal2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_canudas_goal2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_canudas_goal2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
