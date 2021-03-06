/* vector/gsl_vector_int.h
 * 
 * Copyright (C) 1996, 1997, 1998, 1999, 2000 Gerard Jungman, Brian Gough
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or (at
 * your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#ifndef __GSL_VECTOR_INT_H__
#define __GSL_VECTOR_INT_H__

#include <stdlib.h>
#include <gsl/gsl_types.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_check_range.h>
#include <gsl/gsl_block_int.h>

#include "..\\WinGslDll.inl"

#undef __BEGIN_DECLS
#undef __END_DECLS
#ifdef __cplusplus
# define __BEGIN_DECLS extern "C" {
# define __END_DECLS }
#else
# define __BEGIN_DECLS /* empty */
# define __END_DECLS /* empty */
#endif

__BEGIN_DECLS

typedef struct 
{
  size_t size;
  size_t stride;
  int *data;
  gsl_block_int *block;
  int owner;
} 
gsl_vector_int;

typedef struct
{
  gsl_vector_int vector;
} _gsl_vector_int_view;

typedef _gsl_vector_int_view gsl_vector_int_view;

typedef struct
{
  gsl_vector_int vector;
} _gsl_vector_int_const_view;

typedef const _gsl_vector_int_const_view gsl_vector_int_const_view;


/* Allocation */

WINGSLDLL_API gsl_vector_int *gsl_vector_int_alloc (const size_t n);
WINGSLDLL_API gsl_vector_int *gsl_vector_int_calloc (const size_t n);

WINGSLDLL_API gsl_vector_int *gsl_vector_int_alloc_from_block (gsl_block_int * b,
                                                     const size_t offset, 
                                                     const size_t n, 
                                                     const size_t stride);

WINGSLDLL_API gsl_vector_int *gsl_vector_int_alloc_from_vector (gsl_vector_int * v,
                                                      const size_t offset, 
                                                      const size_t n, 
                                                      const size_t stride);

WINGSLDLL_API void gsl_vector_int_free (gsl_vector_int * v);

/* Views */

WINGSLDLL_API _gsl_vector_int_view 
gsl_vector_int_view_array (int *v, size_t n);

WINGSLDLL_API _gsl_vector_int_view 
gsl_vector_int_view_array_with_stride (int *base,
                                         size_t stride,
                                         size_t n);

WINGSLDLL_API _gsl_vector_int_const_view 
gsl_vector_int_const_view_array (const int *v, size_t n);

WINGSLDLL_API _gsl_vector_int_const_view 
gsl_vector_int_const_view_array_with_stride (const int *base,
                                               size_t stride,
                                               size_t n);

WINGSLDLL_API _gsl_vector_int_view 
gsl_vector_int_subvector (gsl_vector_int *v, 
                            size_t i, 
                            size_t n);

WINGSLDLL_API _gsl_vector_int_view 
gsl_vector_int_subvector_with_stride (gsl_vector_int *v, 
                                        size_t i,
                                        size_t stride,
                                        size_t n);

WINGSLDLL_API _gsl_vector_int_const_view 
gsl_vector_int_const_subvector (const gsl_vector_int *v, 
                                  size_t i, 
                                  size_t n);

WINGSLDLL_API _gsl_vector_int_const_view 
gsl_vector_int_const_subvector_with_stride (const gsl_vector_int *v, 
                                              size_t i, 
                                              size_t stride,
                                              size_t n);

/* Operations */

WINGSLDLL_API int gsl_vector_int_get (const gsl_vector_int * v, const size_t i);
WINGSLDLL_API void gsl_vector_int_set (gsl_vector_int * v, const size_t i, int x);

WINGSLDLL_API int *gsl_vector_int_ptr (gsl_vector_int * v, const size_t i);
WINGSLDLL_API const int *gsl_vector_int_const_ptr (const gsl_vector_int * v, const size_t i);

WINGSLDLL_API void gsl_vector_int_set_zero (gsl_vector_int * v);
WINGSLDLL_API void gsl_vector_int_set_all (gsl_vector_int * v, int x);
WINGSLDLL_API int gsl_vector_int_set_basis (gsl_vector_int * v, size_t i);

WINGSLDLL_API int gsl_vector_int_fread (FILE * stream, gsl_vector_int * v);
WINGSLDLL_API int gsl_vector_int_fwrite (FILE * stream, const gsl_vector_int * v);
WINGSLDLL_API int gsl_vector_int_fscanf (FILE * stream, gsl_vector_int * v);
WINGSLDLL_API int gsl_vector_int_fprintf (FILE * stream, const gsl_vector_int * v,
                              const char *format);

WINGSLDLL_API int gsl_vector_int_memcpy (gsl_vector_int * dest, const gsl_vector_int * src);

WINGSLDLL_API int gsl_vector_int_reverse (gsl_vector_int * v);

WINGSLDLL_API int gsl_vector_int_swap (gsl_vector_int * v, gsl_vector_int * w);
WINGSLDLL_API int gsl_vector_int_swap_elements (gsl_vector_int * v, const size_t i, const size_t j);

WINGSLDLL_API int gsl_vector_int_max (const gsl_vector_int * v);
WINGSLDLL_API int gsl_vector_int_min (const gsl_vector_int * v);
WINGSLDLL_API void gsl_vector_int_minmax (const gsl_vector_int * v, int * min_out, int * max_out);

WINGSLDLL_API size_t gsl_vector_int_max_index (const gsl_vector_int * v);
WINGSLDLL_API size_t gsl_vector_int_min_index (const gsl_vector_int * v);
WINGSLDLL_API void gsl_vector_int_minmax_index (const gsl_vector_int * v, size_t * imin, size_t * imax);

WINGSLDLL_API int gsl_vector_int_add (gsl_vector_int * a, const gsl_vector_int * b);
WINGSLDLL_API int gsl_vector_int_sub (gsl_vector_int * a, const gsl_vector_int * b);
WINGSLDLL_API int gsl_vector_int_mul (gsl_vector_int * a, const gsl_vector_int * b);
WINGSLDLL_API int gsl_vector_int_div (gsl_vector_int * a, const gsl_vector_int * b);
WINGSLDLL_API int gsl_vector_int_scale (gsl_vector_int * a, const double x);
WINGSLDLL_API int gsl_vector_int_add_constant (gsl_vector_int * a, const double x);

WINGSLDLL_API int gsl_vector_int_isnull (const gsl_vector_int * v);

#if HAVE_INLINE

extern inline
int
gsl_vector_int_get (const gsl_vector_int * v, const size_t i)
{
#if GSL_RANGE_CHECK
  if (i >= v->size)
    {
      GSL_ERROR_VAL ("index out of range", GSL_EINVAL, 0);
    }
#endif
  return v->data[i * v->stride];
}

extern inline
void
gsl_vector_int_set (gsl_vector_int * v, const size_t i, int x)
{
#if GSL_RANGE_CHECK
  if (i >= v->size)
    {
      GSL_ERROR_VOID ("index out of range", GSL_EINVAL);
    }
#endif
  v->data[i * v->stride] = x;
}

extern inline
int *
gsl_vector_int_ptr (gsl_vector_int * v, const size_t i)
{
#if GSL_RANGE_CHECK
  if (i >= v->size)
    {
      GSL_ERROR_NULL ("index out of range", GSL_EINVAL);
    }
#endif
  return (int *) (v->data + i * v->stride);
}

extern inline
const int *
gsl_vector_int_const_ptr (const gsl_vector_int * v, const size_t i)
{
#if GSL_RANGE_CHECK
  if (i >= v->size)
    {
      GSL_ERROR_NULL ("index out of range", GSL_EINVAL);
    }
#endif
  return (const int *) (v->data + i * v->stride);
}


#endif /* HAVE_INLINE */

__END_DECLS

#endif /* __GSL_VECTOR_INT_H__ */


