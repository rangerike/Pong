/*
 * paddlectrl2.h
 *
 *  Created on: Oct 28, 2015
 *      Author: cs3841
 */

#ifndef PADDLECTRL2_H_
#define PADDLECTRL2_H_



#ifdef PADDLECTRL2_C
#define EXTERN_PFX
#else
#define EXTERN_PFX extern
#endif

/************************************************************************************
 * External Includes
 ************************************************************************************/
// None as of right now.
/************************************************************************************
 * Public structure / type definitions
 ************************************************************************************/
// None as of right now.

/************************************************************************************
 * Public function / method prototypes
 ************************************************************************************/
EXTERN_PFX void *moveme2(void* vp);
#undef EXTERN_PFX
#endif
