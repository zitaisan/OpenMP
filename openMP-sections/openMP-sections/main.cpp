#include <omp.h>
#include <iostream>

int main() {
    int k;
    std::cout << "k = ";
    std::cin >> k;

    #pragma omp parallel num_threads(k)
    {
        #pragma omp sections
        {
            #pragma omp section
            {
                printf("[%d]: came in section %d\n", omp_get_thread_num(), 1);
            }
            #pragma omp section
            {
                printf("[%d]: came in section %d\n", omp_get_thread_num(), 2);
            }
            #pragma omp section
            {
                printf("[%d]: came in section %d\n", omp_get_thread_num(), 3);
            }
        }
        printf("[%d]: parallel region\n", omp_get_thread_num());
    }

    return 0;
}
