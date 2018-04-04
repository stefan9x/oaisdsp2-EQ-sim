/*****************************************************************************/
/*                                                                           */
/* FILENAME                                                                  */
/* 	 aic3204.h                                                               */
/*                                                                           */
/* DESCRIPTION                                                               */
/*   Header file for aic3204 codec on the EZDSP 5535 USB Stick.              */
/*                                                                           */
/*****************************************************************************/
/*
 *
 * Copyright (C) 2010 Texas Instruments Incorporated - http://www.ti.com/ 
 * 
*/

#ifndef TEMPLATE_DMA_AIC3204_H_
#define TEMPLATE_DMA_AIC3204_H_

 extern void aic3204_init();
 extern void aic3204_set_input_filename(const char* input_filename);
 extern void aic3204_set_output_filename(const char* output_filename);
 extern unsigned long set_sampling_frequency_and_gain(unsigned long, unsigned int);
 extern void aic3204_hardware_init(void);
 extern void aic3204_codec_read(Int16*, Int16*);
 extern void aic3204_codec_write(Int16, Int16);
 extern void aic3204_disable(void);

 extern FILE* input_file;
 extern FILE* output_file;
 extern int aic3204_enabled;

#endif /*TEMPLATE_DMA_AIC3204_H_*/


/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  End of aic3204.h                                                        *
 *                                                                          *
 * ------------------------------------------------------------------------ */
 
