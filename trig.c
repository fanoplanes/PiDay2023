#include <stdio.h>
#include <stdlib.h>

#define EPSILON 1e-6
#define PI 3.14159265358979323846

double oneoverfact(int x)
{
	double a = 1;
	for(int i = 1; i < x + 1; i++)
	{
		a /= i;
	}
	return a;
}

double sin(double x)
{
	double ans = 0;
	double temp;
	double mult_temp;
	int n = 0;
	do {
		temp = ans;
		mult_temp = 1;
		for(int i = 0; i < 2*n + 1; i++)
		{
			mult_temp *= x;
		}
		ans += mult_temp * (double)(n%2 ? -1 : 1) * oneoverfact(2*n + 1);
		n++;
	} while (((ans - temp) > EPSILON) || ((temp - ans) > EPSILON));

	return ans;
}

double cos(double x)
{
	double ans = 0;
	double temp;
	double mult_temp;
	int n = 0;
	do {
		temp = ans;
		mult_temp = 1;
		for(int i = 0; i < 2*n; i++)
		{
			mult_temp *= x;
		}
		ans += mult_temp * (double)(n%2 ? -1 : 1) * oneoverfact(2*n);
		n++;
	} while (((ans - temp) > EPSILON) || ((temp - ans) > EPSILON));

	return ans;
}

double tan(double x)
{
	return sin(x)/cos(x);
}

int main(int argc, char ** argv)
{
	double a = atof(argv[1]);
	double a2 = a;
	int first_sign_flag = 0;
	if(a2<0)
	{
		a2 *= -1;
		first_sign_flag = 1;
	}
	while(a2 - 2*PI > 0)
	{
		a2 -= 2*PI;
	}
	int second_sign_flag = 0;
	if(a2 - PI > 0)
	{
		a2 = 2*PI - a2;
		second_sign_flag = 1;
	}

	printf("sin(%.6f) = %.6f\n",a, (first_sign_flag ^ second_sign_flag) ? -sin(a2) : sin(a2));
	printf("cos(%.6f) = %.6f\n",a, cos(a2));
	printf("tan(%.6f) = %.6f\n",a, (first_sign_flag ^ second_sign_flag) ? -tan(a2) : tan(a2));
	return 0;
}
