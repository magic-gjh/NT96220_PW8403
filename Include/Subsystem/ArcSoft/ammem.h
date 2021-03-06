/*----------------------------------------------------------------------------------------------
*
* This file is ArcSoft's property. It contains ArcSoft's trade secret, proprietary and
* confidential information.
*
* The information and code contained in this file is only for authorized ArcSoft employees
* to design, create, modify, or review.
*
* DO NOT DISTRIBUTE, DO NOT DUPLICATE OR TRANSMIT IN ANY FORM WITHOUT PROPER AUTHORIZATION.
*
* If you are not an intended recipient of this file, you must not copy, distribute, modify,
* or take any action in reliance on it.
*
* If you have received this file in error, please immediately notify ArcSoft and
* permanently delete the original and any copy of any file and any printout thereof.
*
*-------------------------------------------------------------------------------------------------*/

#ifndef __AMMEM_H__
#define __AMMEM_H__

#include "amcomdef.h"

/************ duplicate definition in amcomdef.h ************/
/*
typedef struct  _tag_mem_info
{
    MDWord    wTotalMemUsed;
    MDWord    wTotalMemFree;
}MMEMINFO, *LPMMEMINFO;
*/

#ifdef __cplusplus
extern "C" {
#endif



MVoid*  MMemAlloc(MHandle hContext, MLong lSize);
MVoid*  MMemRealloc(MHandle hContext, MVoid* pMem, MLong lSize);
MVoid   MMemFree(MHandle hContext, MVoid* pMem);
MVoid   MMemSet(MVoid* pMem, MByte byVal, MLong lSize);
MVoid   MMemCpy(MVoid* pDst, const MVoid* pSrc, MLong lSize);
MVoid   MMemMove(MVoid* pDst, MVoid* pSrc, MLong lSize);
MLong   MMemCmp(MVoid* pBuf1, MVoid* pBuf2, MLong lSize);



MHandle MMemMgrCreate(MVoid* pMem, MLong lMemSize);
MVoid   MMemMgrDestroy(MHandle hMemMgr);

MBool   MGetMemInfo(LPMMEMINFO pMemInfo);





/*********************************************************************************
**********************************************************************************
**************Removed following functions which have been deprecated**************
**********************************************************************************
**********************************************************************************/


MVoid*  MHugeMemAlloc(MHandle hContext,MLong lSize);
MVoid*  MHugeMemReAlloc(MHandle hContext, MVoid* pMem, MLong lSize);
MVoid   MHugeMemFree(MHandle hContext,MHandle hMem);
MVoid*  MHugeMemLock(MHandle hContext, MHandle hMem);
MVoid   MHugeMemUnlock(MHandle hContext, MHandle hMem);

#ifdef M_DEBUG
#include "trace\ammemd.h"
#endif

#ifdef __cplusplus
}
#endif

#endif

