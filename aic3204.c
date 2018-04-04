/*****************************************************************************/
/*                                                                           */
/* FILENAME                                                                  */
/* 	 aic3204.c                                                               */
/*                                                                           */
/* DESCRIPTION                                                               */
/*   Setup functions for aic3204 codec on the EZDSP 5535 USB Stick.          */
/*                                                                           */
/* REVISION                                                                  */
/*   Revision: 1.00	                                                         */
/*   Author  : Dejan Bokan                                                   */
/*****************************************************************************/
#include <stdio.h>
#include "tistdtypes.h"

FILE* input_file;
FILE* output_file;

int aic3204_enabled = 0;

/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  aic3204_enable( )                                                       *
 *                                                                          *
 * ------------------------------------------------------------------------ */  

void aic3204_hardware_init(void)
{
    //Dummy for now
}

/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  aic3204_disable( )                                                      *
 *                                                                          *
 * ------------------------------------------------------------------------ */

void aic3204_disable(void)
{
	aic3204_enabled = 0;
	if(input_file != 0)
		fclose(input_file);
	if(output_file != 0)
		fclose(output_file);
}



/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  aic3204_codec_read( )                                                   *
 *                                                                          *
 * ------------------------------------------------------------------------ */

void aic3204_codec_read(Int16* left_input, Int16* right_input)
{
	Int16 n = 0;
	Int16 buff[2];
	if(aic3204_enabled)
	{
		n = fread(buff, 1, 2, input_file);
		if(n == 2)
		{
			*left_input = buff[0] | (buff[1] << 8);
			n = fread(buff, 1, 2, input_file);
			if(n == 2)
			{
				*right_input = buff[0] | (buff[1] << 8);
				return;
			}

		}
	}

	*left_input = 0;
	*right_input = 0;
}

/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  aic3204_codec_write( )                                                  *
 *                                                                          *
 * ------------------------------------------------------------------------ */
 
void aic3204_codec_write(Int16 left_output, Int16 right_output)
{
	Int16 buff[2];
	if(aic3204_enabled)
	{
		buff[0] = left_output & 0x00FF;
		buff[1] = left_output >> 8;
		fwrite(buff, 1, 2, output_file);

		buff[0] = right_output & 0x00FF;
		buff[1] = right_output >> 8;
		fwrite(buff, 1, 2, output_file);
	}
}

/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  End of aic3204.c                                                        *
 *                                                                          *
 * ------------------------------------------------------------------------ */
