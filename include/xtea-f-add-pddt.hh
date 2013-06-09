/*
 *    Copyright (c) 2012-2013 Luxembourg University,
 *    Laboratory of Algorithmics, Cryptology and Security (LACS).
 *
 *    This file is part of the YAARX toolkit. YAARX stands for
 *    Yet Another ARX toolkit for analysis of ARX cryptographic algorithms.
 *
 *    YAARX is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    YAARX is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with YAARX.  If not, see <http://www.gnu.org/licenses/>.
 */
/**
 * \file  xtea-f-add-pddt.hh
 * \author V.Velichkov, vesselin.velichkov@uni.lu
 * \date 2012-2013
 * \brief Declarations for xtea-f-add-pddt.cc. \copybrief xtea-f-add-pddt.cc
 */ 
#ifndef XTEA_F_ADD_PDDT_H
#define XTEA_F_ADD_PDDT_H

void xtea_f_add_pddt_i(const uint32_t k, const uint32_t n, const uint32_t key, const uint32_t delta,
							  const uint32_t lsh_const,  const uint32_t rsh_const,
							  gsl_matrix* A[2][2][2], gsl_matrix* AA[2][2][2], gsl_vector* C, 
							  uint32_t* da, uint32_t* db, uint32_t* dc, uint32_t* dd, 
							  double* p, const double p_thres, 
							  std::set<differential_t, struct_comp_diff_dx_dy>* diff_set_dx_dy);

void xtea_f_add_pddt(uint32_t n, double p_thres, uint32_t lsh_const, uint32_t rsh_const,
							gsl_matrix* A[2][2][2], gsl_matrix* AA[2][2][2], gsl_vector* C, 
							uint32_t key, uint32_t delta, 
							std::set<differential_t, struct_comp_diff_dx_dy>* diff_set_dx_dy);

void xtea_add_pddt_dxy_to_dp(std::multiset<differential_t, struct_comp_diff_p>* diff_mset_p,
									  const std::set<differential_t, struct_comp_diff_dx_dy> diff_set_dx_dy);

#endif // #ifndef XTEA_F_ADD_PDDT_H
