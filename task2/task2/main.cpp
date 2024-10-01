
#include <omp.h>
#include <iostream>
#include <Windows.h>
int main()
{
	int k, n;
	std::cout << "k = ";
	std::cin >> k;
	std::cout << "n = ";
	std::cin >> n;
	int sum = 0;

	#pragma omp parallel num_threads(k) reduction(+:sum) shared(n)
	{
		#pragma omp for
		for (int i = 1; i < (n + 1); i++)
		{
			sum += i;
		}
		
		printf("[%d]: sum = <%d>.\n", omp_get_thread_num(), sum);
	}
	std::cout << "sum = " << sum << std::endl;
}
