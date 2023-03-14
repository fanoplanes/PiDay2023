#include<stdio.h>
#include<stdlib.h>

#define PI 3.14159265358979323846

int main(int argc, char** argv)
{
	double input = atof(argv[1]);
	double input2 = input;
	double sin = 0;
	double cos = 1;
	double sin_tmp;
	double cos_tmp;
	double delta = 1e-7;
	int first_sign_flag = 0;
	if(input2 < 0)
	{
		input2 *= -1;
		first_sign_flag = 1;
	}

	while(input2 - 2*PI > 0)
	{
		input2 -= 2*PI;
	}

	int second_sign_flag = 0;
	if(input2 - PI > 0)
	{
		input2 = 2*PI - input2;
		second_sign_flag = 1;
	}

	sin_tmp = sin;
	cos_tmp = cos;
	for(double i = 0; i < input2; i += delta)
	{
		sin += cos_tmp*delta;
		cos -= sin_tmp*delta;
		sin_tmp = sin;
		cos_tmp = cos;
	}
	
	printf("sin(%.6f) = %.6f\n",input , (first_sign_flag ^ second_sign_flag) ? -sin : sin);
	printf("cos(%.6f) = %.6f\n",input , cos);
	printf("tan(%.6f) = %.6f\n",input , (first_sign_flag ^ second_sign_flag) ? -(sin/cos) : sin/cos);
	return 0;
}
