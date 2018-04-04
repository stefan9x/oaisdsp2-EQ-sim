#include "processing.h"
#include "iir.h"
#include "math.h"

#define INT16_MAX 32767

void calculateShelvingCoeff(float c_alpha, Int16* output)
{
	/* Your code here */
	output[0]=INT16_MAX*c_alpha;
	output[1]=(-INT16_MAX) - 1;

	output[2]=INT16_MAX;
	output[3]=(-INT16_MAX)*c_alpha;
}

void calculatePeekCoeff(float c_alpha, float c_beta, Int16* output)
{
	/* Your code here */
	output[0]=INT16_MAX*c_alpha;
	output[1]=((-INT16_MAX) * c_beta * (1 + c_alpha))*0.5;
	output[2]=INT16_MAX;

	output[3]=INT16_MAX;
	output[4]=((-INT16_MAX) * c_beta * (1 + c_alpha))*0.5;
	output[5]=INT16_MAX*c_alpha;
}

Int16 shelvingHP(Int16 input, Int16* coeff, Int16* x_history, Int16* y_history, Int16 k)
{
	/* Your code here */
	Int16 filtered = (first_order_IIR(input, coeff, x_history, y_history))>>1;

	Int16 input_tmp = input>>1;

	Int16 output = _smpy(k, (input_tmp + filtered)) + (input_tmp - filtered);

	if (output > 32767) {
		return 32767; }
	else if (output < -32767) {
		return -32767; }
	else return (Int16)output;

}

Int16 shelvingLP(Int16 input, Int16* coeff, Int16* x_history, Int16* y_history, Int16 k)
{
	/* Your code here */
	Int16 filtered = (first_order_IIR(input, coeff, x_history, y_history))>>1;

	Int16 input_tmp = input>>1;

	Int16 output = _smpy(k, (input_tmp - filtered)) + (input_tmp + filtered);

	return output;
}

Int16 shelvingPeek(Int16 input, Int16* coeff, Int16* x_history, Int16* y_history, Int16 k)
{
	/* Your code here */
	Int16 filtered = (second_order_IIR(input, coeff, x_history, y_history))>>1;

	Int16 input_tmp = input>>1;

	Int16 output = _smpy(k, (input_tmp - filtered)) + (input_tmp + filtered);

	return output;
}

float calculateBeta(float omega)
{
	return cos(omega);
}

float calculateAlpha(float omega)
{
	return (1 - sin(omega)) / cos(omega);
}
