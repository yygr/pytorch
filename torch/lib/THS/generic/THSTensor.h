#ifndef THS_GENERIC_FILE
#define THS_GENERIC_FILE "generic/THSTensor.h"
#else

typedef struct THSTensor
{  // Stored in COO format, indices + values
    long *size;
    ptrdiff_t nnz;
    int nDimension;

    // 2-D tensor of nDim x nnz of indices. May have nnz dim bigger than nnz
    // as buffer, so we keep track of both
    THLongTensor *indices;
    THTensor *values;
    // Math operations can only be performed on ordered sparse tensors
    int contiguous;

} THSTensor;

/**** access methods ****/
TH_API int THSTensor_(nDimension)(const THSTensor *self);
TH_API long THSTensor_(size)(const THSTensor *self, int dim);
TH_API ptrdiff_t THSTensor_(nnz)(const THSTensor *self);
TH_API THLongStorage *THSTensor_(newSizeOf)(THSTensor *self);
TH_API THLongTensor *THSTensor_(indices)(const THSTensor *self);
TH_API THTensor *THSTensor_(values)(const THSTensor *self);

/**** creation methods ****/
TH_API THSTensor *THSTensor_(new)(void);
TH_API THSTensor *THSTensor_(newWithTensor)(THLongTensor *indices, THTensor *values);
TH_API THSTensor *THSTensor_(newWithTensorAndSize)(THLongTensor *indices, THTensor *values, THLongStorage *sizes);

TH_API THSTensor *THSTensor_(newWithSize)(THLongStorage *size_);
TH_API THSTensor *THSTensor_(newWithSize1d)(long size0_);
TH_API THSTensor *THSTensor_(newWithSize2d)(long size0_, long size1_);
TH_API THSTensor *THSTensor_(newWithSize3d)(long size0_, long size1_, long size2_);
TH_API THSTensor *THSTensor_(newWithSize4d)(long size0_, long size1_, long size2_, long size3_);

TH_API THSTensor *THSTensor_(newClone)(THSTensor *self);
TH_API THSTensor *THSTensor_(newContiguous)(THSTensor *self);
TH_API THSTensor *THSTensor_(newTranspose)(THSTensor *self, int dimension1_, int dimension2_);

/**** reshaping methods ***/
TH_API THSTensor *THSTensor_(resize)(THSTensor *self, THLongStorage *size);
TH_API THSTensor *THSTensor_(resize1d)(THSTensor *self, long size0);
TH_API THSTensor *THSTensor_(resize2d)(THSTensor *self, long size0, long size1);
TH_API THSTensor *THSTensor_(resize3d)(THSTensor *self, long size0, long size1, long size2);
TH_API THSTensor *THSTensor_(resize4d)(THSTensor *self, long size0, long size1, long size2, long size3);

TH_API THTensor *THSTensor_(toDense)(THSTensor *self);

TH_API void THSTensor_(transpose)(THSTensor *self, int dimension1_, int dimension2_);
TH_API int THSTensor_(isContiguous)(const THSTensor *self);
TH_API void THSTensor_(contiguous)(THSTensor *self);

TH_API void THSTensor_(free)(THSTensor *self);


/* TODO (check function signatures too, might be wrong)
TH_API void THSTensor_(freeCopyTo)(THSTensor *self, THSTensor *dst);

TH_API void THSTensor_(narrow)(THSTensor *self, THSTensor *src, int dimension_, long firstIndex_, long size_);
TH_API void THSTensor_(select)(THSTensor *self, THSTensor *src, int dimension_, long sliceIndex_);
*/

#endif
