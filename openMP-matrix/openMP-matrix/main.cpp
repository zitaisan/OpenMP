#include <omp.h>
#include <iostream>
#include <vector>
#include <sstream>

int main()
{
    int n;
    std::cout << "n = ";
    std::cin >> n;

    std::vector<std::vector<int>> matrixA(n, std::vector<int>(n));
    std::vector<std::vector<int>> matrixB(n, std::vector<int>(n));
    std::vector<std::vector<int>> matrixC(n, std::vector<int>(n, 0));

    std::cout << "matrix A:" << std::endl;
    std::cin.ignore();
    for (int i = 0; i < n; ++i) {
        std::string line;
        std::getline(std::cin, line); 

        std::istringstream stream(line); 
        for (int j = 0; j < n; ++j) {
            stream >> matrixA[i][j]; 
        }
    }
    std::cout << "matrix B:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::string line;
        std::getline(std::cin, line); 

        std::istringstream stream(line); 
        for (int j = 0; j < n; ++j) {
            stream >> matrixB[i][j]; 
        }
    }
    #pragma omp parallel for
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int sum = 0;
            #pragma omp parallel for reduction(+:sum) shared(i)
            for (int m = 0; m < n; m++)
            {
                sum += matrixA[i][m] * matrixB[m][j];
            }
            matrixC[i][j] = sum;
        }
    }
    std::cout << "matrix C:" << std::endl;
    for (const auto& row : matrixC) {
        for (const auto& elem : row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
    