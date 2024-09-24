#include "pch.h"
#include <omp.h>
#include <iostream>
#include <cmath>
#include <Windows.h>
#include <iomanip> 
using namespace std;
int main()
{
	long long n;
	std::cout << "n = ";
	std::cin >> n;
	double x, step, res = 0.0;
	step = 1. / (double) n;

	#pragma omp parallel for private(x) reduction(+:res) 
	{
		for (int i = 0; i < n; i++) {
			x = (i + 0.5) * step;
			res += 4.0 / (1.0 + x*x);
		}
		
	}
	res = res * step;
	printf("PI=%15.12f\n", res);
	return 0;
}
