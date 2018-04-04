//////////////////////////////////////////////////////////////////////////////
// *
// * Predmetni projekat iz predmeta OAiS DSP 2
// * Godina: 2017
// *
// * Zadatak: Ekvalizacija audio signala
// * Autor:
// *                                                                          
// *                                                                          
/////////////////////////////////////////////////////////////////////////////

#include "stdio.h"
#include "ezdsp5535.h"
#include "ezdsp5535_i2c.h"
#include "aic3204.h"
#include "ezdsp5535_aic3204_dma.h"
#include "ezdsp5535_i2s.h"
#include "ezdsp5535_sar.h"
#include "print_number.h"
#include "math.h"

#include "iir.h"
#include "processing.h"

/* Frekvencija odabiranja */
#define SAMPLE_RATE 16000L

#define PI 3.14159265

/* Niz za smestanje ulaznih i izlaznih odbiraka */
#pragma DATA_ALIGN(sampleBufferL,4)
Int16 sampleBufferL[AUDIO_IO_SIZE];
#pragma DATA_ALIGN(sampleBufferR,4)
Int16 sampleBufferR[AUDIO_IO_SIZE];

#pragma DATA_ALIGN(hpBuffer,4)
Int16 hpBuffer[AUDIO_IO_SIZE];
#pragma DATA_ALIGN(lpBuffer,4)
Int16 lpBuffer[AUDIO_IO_SIZE];
#pragma DATA_ALIGN(peek1Buffer,4)
Int16 peek1Buffer[AUDIO_IO_SIZE];
#pragma DATA_ALIGN(peek2Buffer,4)
Int16 peek2Buffer[AUDIO_IO_SIZE];

Int16 coeffs_lp[4];
Int16 coeffs_hp[4];
Int16 coeffs_p1[6];
Int16 coeffs_p2[6];

Int16 dir_impulse[AUDIO_IO_SIZE];

Int16 input_history_low[1];
Int16 output_history_low[1];

Int16 input_history_high[1];
Int16 output_history_high[1];

Int16 input_history_peek[2];
Int16 output_history_peek[2];

Int16 input_history_peek2[2];
Int16 output_history_peek2[2];

Int16 freq[6] = {180, 570, 280, 3045, 1935, 5500};
float omega[6];

Uint16 old = NoKey;
Int16 index=0;
Int16 k[4]={16385, 16385, 16385, 16385};

Uint16 getKey()
{
    Uint16 key = EZDSP5535_SAR_getKey();

    if (key == old) {
        return NoKey;
    } else {
        old = key;
        return key;
    }
}

void main( void )
{
	int i;

	/* Inicijalizaija razvojne ploce */
    EZDSP5535_init( );
	
	/* Inicijalizacija kontrolera za ocitavanje vrednosti pritisnutog dugmeta*/
    EZDSP5535_SAR_init();

    /* Inicijalizacija LCD kontrolera */
    initPrintNumber();

	printf("\n Ekvalizacija audio signala \n");

    /* Inicijalizacija veze sa AIC3204 kodekom (AD/DA) */
    aic3204_hardware_init();

	aic3204_set_input_filename("../Multi_Tone16k.pcm");
    aic3204_set_output_filename("../Multi_Tone16k_EQ.pcm");

    /* Inicijalizacija AIC3204 kodeka */
	aic3204_init();
	
	aic3204_dma_init();

    /* Postavljanje vrednosti frekvencije odabiranja i pojacanja na kodeku */
    set_sampling_frequency_and_gain(SAMPLE_RATE, 0);

    /* Your code here */

    for (i=0; i<6; i++){
		omega[i] = (2 * PI * freq[i])/SAMPLE_RATE;
	}


	dir_impulse[0]=32767;

	for(i=1; i<AUDIO_IO_SIZE; i++)
	{
		dir_impulse[i]=0;
	}


	calculateShelvingCoeff(calculateAlpha(omega[0]), coeffs_lp);
	calculateShelvingCoeff(calculateAlpha(omega[5]), coeffs_hp);

	calculatePeekCoeff(calculateAlpha(omega[2]), calculateBeta(omega[1]), coeffs_p1);
	calculatePeekCoeff(calculateAlpha(omega[4]), calculateBeta(omega[3]), coeffs_p2);

    while(1)
    {
    	aic3204_read_block(sampleBufferL, sampleBufferR);

		/* Your code here */

    	Uint16 key = getKey();

    	switch (key) {
		case SW1:
				index++;
				if (index == 4) index = 0;
				//printchar(index);
				break;

		case SW2:
				k[index] -= 3277;
				if (k[index] < 0) {
					k[index] = 32767;
				}
				//uraditi print char
				break;
    	}

		for (i=0; i<AUDIO_IO_SIZE; i++){
			lpBuffer[i] = shelvingLP(dir_impulse[i], coeffs_lp, input_history_low, output_history_low, k[0]);
			peek1Buffer[i] = shelvingPeek(lpBuffer[i], coeffs_p1, input_history_peek, output_history_peek, k[1]);

			peek2Buffer[i] = shelvingPeek(peek1Buffer[i], coeffs_p2, input_history_peek2, output_history_peek2, k[2]);
			hpBuffer[i] = shelvingHP(peek2Buffer[i], coeffs_hp, input_history_high, output_history_high, k[3]);
		}

		aic3204_write_block(sampleBufferR, sampleBufferR);
	}

    	
	/* Prekid veze sa AIC3204 kodekom */
    aic3204_disable();

    printf( "\n***Kraj programa***\n" );
	SW_BREAKPOINT;
}

