/*
 *  Copyright 2008-2014 NVIDIA Corporation
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

/*! \file blas.h
 *  \brief BLAS-like functions
 */


#pragma once

#include <cusp/detail/config.h>

#include <cusp/complex.h>
#include <cusp/detail/type_traits.h>

namespace cusp
{
namespace blas
{

/*! \addtogroup dense Dense Algorithms
 *  \addtogroup blas BLAS
 *  \ingroup dense
 *  \brief Interface to BLAS routines
 *  \{
 */

/*! \cond */
template <typename DerivedPolicy,
          typename Array>
int amax(const thrust::detail::execution_policy_base<DerivedPolicy> &exec,
         const Array& x);
/*! \endcond */

/*! \p amax : index of the largest element in a array
 */
template <typename Array>
int amax(const Array& x);

/*! \cond */
template <typename DerivedPolicy,
          typename Array>
typename cusp::detail::norm_type<typename Array::value_type>::type
asum(const thrust::detail::execution_policy_base<DerivedPolicy> &exec,
     const Array& x);
/*! \endcond */

/*! \p asum : sum of absolute value of all entries in array
 */
template <typename Array>
typename cusp::detail::norm_type<typename Array::value_type>::type
asum(const Array& x);

/*! \cond */
template <typename DerivedPolicy,
          typename Array1,
          typename Array2,
          typename ScalarType>
void axpy(const thrust::detail::execution_policy_base<DerivedPolicy> &exec,
          const Array1& x,
                Array2& y,
          const ScalarType alpha);
/*! \endcond */

/*! \p axpy : scaled vector addition (y = alpha * x + y)
 */
template <typename Array1,
          typename Array2,
          typename ScalarType>
void axpy(const Array1& x,
                Array2& y,
          const ScalarType alpha);

/*! \cond */
template <typename DerivedPolicy,
          typename Array1,
          typename Array2,
          typename Array3,
          typename ScalarType1,
          typename ScalarType2>
void axpby(const thrust::detail::execution_policy_base<DerivedPolicy> &exec,
           const Array1& x,
           const Array2& y,
                 Array3& output,
                 ScalarType1 alpha,
                 ScalarType2 beta);
/*! \endcond */

/*! \p axpby : linear combination of two vectors (output = alpha * x + beta * y)
 */
template <typename Array1,
          typename Array2,
          typename Array3,
          typename ScalarType1,
          typename ScalarType2>
void axpby(const Array1& x,
           const Array2& y,
                 Array3& output,
                 ScalarType1 alpha,
                 ScalarType2 beta);

/*! \cond */
template <typename DerivedPolicy,
          typename Array1,
          typename Array2,
          typename Array3,
          typename Array4,
          typename ScalarType1,
          typename ScalarType2,
          typename ScalarType3>
void axpbypcz(const thrust::detail::execution_policy_base<DerivedPolicy> &exec,
              const Array1& x,
              const Array2& y,
              const Array3& z,
                    Array4& output,
              ScalarType1 alpha,
              ScalarType2 beta,
              ScalarType3 gamma);
/*! \endcond */

/*! \p axpbycz : linear combination of three vectors (output = alpha * x + beta * y + gamma * z)
 */
template <typename Array1,
          typename Array2,
          typename Array3,
          typename Array4,
          typename ScalarType1,
          typename ScalarType2,
          typename ScalarType3>
void axpbypcz(const Array1& x,
              const Array2& y,
              const Array3& z,
                    Array4& output,
              ScalarType1 alpha,
              ScalarType2 beta,
              ScalarType3 gamma);

/*! \cond */
template <typename DerivedPolicy,
          typename Array1,
          typename Array2,
          typename Array3>
void xmy(const thrust::detail::execution_policy_base<DerivedPolicy> &exec,
         const Array1& x,
         const Array2& y,
               Array3& output);
/*! \endcond */

/*! \p xmy : elementwise multiplication of two vectors (output[i] = x[i] * y[i])
 */
template <typename Array1,
          typename Array2,
          typename Array3>
void xmy(const Array1& x,
         const Array2& y,
               Array3& output);

/*! \cond */
template <typename DerivedPolicy,
          typename Array1,
          typename Array2>
void copy(const thrust::detail::execution_policy_base<DerivedPolicy> &exec,
          const Array1& x,
                Array2& y);
/*! \endcond */

/*! \p copy : vector copy (y = x)
 */
template <typename Array1,
          typename Array2>
void copy(const Array1& x,
                Array2& y);

/*! \cond */
template <typename DerivedPolicy,
          typename Array1,
          typename Array2>
typename Array1::value_type
dot(const thrust::detail::execution_policy_base<DerivedPolicy> &exec,
    const Array1& x,
    const Array2& y);
/*! \endcond */

/*! \p dot : dot product (x^T * y)
 */
template <typename Array1,
          typename Array2>
typename Array1::value_type
dot(const Array1& x,
    const Array2& y);

/*! \cond */
template <typename DerivedPolicy,
          typename Array1,
          typename Array2>
typename Array1::value_type
dotc(const thrust::detail::execution_policy_base<DerivedPolicy> &exec,
     const Array1& x,
     const Array2& y);
/*! \endcond */

/*! \p dotc : conjugate dot product (conjugate(x)^T * y)
 */
template <typename Array1,
          typename Array2>
typename Array1::value_type
dotc(const Array1& x,
     const Array2& y);

/*! \cond */
template <typename DerivedPolicy,
          typename Array,
          typename ScalarType>
void fill(const thrust::detail::execution_policy_base<DerivedPolicy> &exec,
          Array& array,
          const ScalarType alpha);
/*! \endcond */

/*! \p fill : vector fill (x[i] = alpha)
 */
template <typename Array,
          typename ScalarType>
void fill(Array& array,
          const ScalarType alpha);

/*! \cond */
template <typename DerivedPolicy,
          typename Array>
typename cusp::detail::norm_type<typename Array::value_type>::type
nrm1(const thrust::detail::execution_policy_base<DerivedPolicy> &exec,
     const Array& array);
/*! \endcond */

/*! \p nrm1 : vector 1-norm (sum abs(x[i]))
 */
template <typename Array>
typename cusp::detail::norm_type<typename Array::value_type>::type
nrm1(const Array& array);

/*! \cond */
template <typename DerivedPolicy,
          typename Array>
typename cusp::detail::norm_type<typename Array::value_type>::type
nrm2(const thrust::detail::execution_policy_base<DerivedPolicy> &exec,
     const Array& array);
/*! \endcond */

/*! \p nrm2 : vector 2-norm (sqrt(sum x[i] * x[i] )
 */
template <typename Array>
typename cusp::detail::norm_type<typename Array::value_type>::type
nrm2(const Array& array);

/*! \cond */
template <typename DerivedPolicy,
          typename Array>
typename Array::value_type
nrmmax(const thrust::detail::execution_policy_base<DerivedPolicy> &exec,
       const Array& array);
/*! \endcond */

/*! \p nrmmax : vector infinity norm
 */
template <typename Array>
typename Array::value_type
nrmmax(const Array& array);

/*! \cond */
template <typename DerivedPolicy,
          typename Array,
          typename ScalarType>
void scal(const thrust::detail::execution_policy_base<DerivedPolicy> &exec,
          Array& x,
          const ScalarType alpha);
/*! \endcond */

/*! \p scal : scale vector (x[i] = alpha * x[i])
 */
template <typename Array,
          typename ScalarType>
void scal(Array& x,
          const ScalarType alpha);

/*! \cond */
template <typename DerivedPolicy,
          typename Array2d1,
          typename Array1d1,
          typename Array1d2>
void gemv(const thrust::detail::execution_policy_base<DerivedPolicy> &exec,
          const Array2d1& A,
          const Array1d1& x,
                Array1d2& y);
/*! \endcond */

template<typename Array2d1,
         typename Array1d1,
         typename Array1d2>
void gemv(const Array2d1& A,
          const Array1d1& x,
                Array1d2& y);

/*! \cond */
template <typename DerivedPolicy,
          typename Array1d1,
          typename Array1d2,
          typename Array2d1>
void ger(const thrust::detail::execution_policy_base<DerivedPolicy> &exec,
         const Array1d1& x,
         const Array1d2& y,
               Array2d1& A);
/*! \endcond */

template<typename Array1d1,
         typename Array1d2,
         typename Array2d1>
void ger(const Array1d1& x,
         const Array1d2& y,
               Array2d1& A);

/*! \cond */
template <typename DerivedPolicy,
          typename Array2d1,
          typename Array1d1,
          typename Array1d2>
void symv(const thrust::detail::execution_policy_base<DerivedPolicy> &exec,
          const Array2d1& A,
          const Array1d1& x,
                Array1d2& y);
/*! \endcond */

template <typename Array2d1,
          typename Array1d1,
          typename Array1d2>
void symv(const Array2d1& A,
          const Array1d1& x,
                Array1d2& y);

/*! \cond */
template <typename DerivedPolicy,
          typename Array1d,
          typename Array2d>
void syr(const thrust::detail::execution_policy_base<DerivedPolicy> &exec,
         const Array1d& x,
               Array2d& A);
/*! \endcond */

template <typename Array1d,
          typename Array2d>
void syr(const Array1d& x,
               Array2d& A);

/*! \cond */
template <typename DerivedPolicy,
          typename Array2d,
          typename Array1d>
void trmv(const thrust::detail::execution_policy_base<DerivedPolicy> &exec,
          const Array2d& A,
                Array1d& x);
/*! \endcond */

template<typename Array2d,
         typename Array1d>
void trmv(const Array2d& A,
                Array1d& x);

/*! \cond */
template <typename DerivedPolicy,
          typename Array2d,
          typename Array1d>
void trsv(const thrust::detail::execution_policy_base<DerivedPolicy> &exec,
          const Array2d& A,
                Array1d& x);
/*! \endcond */

template<typename Array2d,
         typename Array1d>
void trsv(const Array2d& A,
                Array1d& x);

/*! \cond */
template <typename DerivedPolicy,
          typename Array2d1,
          typename Array2d2,
          typename Array2d3>
void gemm(const thrust::detail::execution_policy_base<DerivedPolicy> &exec,
          const Array2d1& A,
          const Array2d2& B,
                Array2d3& C);
/*! \endcond */

template<typename Array2d1,
         typename Array2d2,
         typename Array2d3>
void gemm(const Array2d1& A,
          const Array2d2& B,
                Array2d3& C);

/*! \cond */
template <typename DerivedPolicy,
          typename Array2d1,
          typename Array2d2,
          typename Array2d3>
void symm(const thrust::detail::execution_policy_base<DerivedPolicy> &exec,
          const Array2d1& A,
          const Array2d2& B,
                Array2d3& C);
/*! \endcond */

template<typename Array2d1,
         typename Array2d2,
         typename Array2d3>
void symm(const Array2d1& A,
          const Array2d2& B,
                Array2d3& C);

/*! \cond */
template <typename DerivedPolicy,
          typename Array2d1,
          typename Array2d2>
void syrk(const thrust::detail::execution_policy_base<DerivedPolicy> &exec,
          const Array2d1& A,
                Array2d2& C);
/*! \endcond */

template<typename Array2d1,
         typename Array2d2>
void syrk(const Array2d1& A,
                Array2d2& B);

/*! \cond */
template <typename DerivedPolicy,
          typename Array2d1,
          typename Array2d2,
          typename Array2d3>
void syr2k(const thrust::detail::execution_policy_base<DerivedPolicy> &exec,
           const Array2d1& A,
           const Array2d2& B,
                 Array2d3& C);
/*! \endcond */

template<typename Array2d1,
         typename Array2d2,
         typename Array2d3>
void syr2k(const Array2d1& A,
           const Array2d2& B,
                 Array2d3& C);

/*! \cond */
template <typename DerivedPolicy,
          typename Array2d1,
          typename Array2d2,
          typename Array2d3>
void trmm(const thrust::detail::execution_policy_base<DerivedPolicy> &exec,
          const Array2d1& A,
          const Array2d2& B,
                Array2d3& C);
/*! \endcond */

template<typename Array2d1,
         typename Array2d2,
         typename Array2d3>
void trmm(const Array2d1& A,
          const Array2d2& B,
                Array2d3& C);

/*! \cond */
template <typename DerivedPolicy,
          typename Array2d1,
          typename Array2d2,
          typename Array2d3>
void trsm(const thrust::detail::execution_policy_base<DerivedPolicy> &exec,
          const Array2d1& A,
          const Array2d2& B,
                Array2d3& C);
/*! \endcond */

template<typename Array2d1,
         typename Array2d2,
         typename Array2d3>
void trsm(const Array2d1& A,
          const Array2d2& B,
                Array2d3& C);

/*! \}
 */

} // end namespace blas
} // end namespace cusp

#include <cusp/blas/blas.inl>
