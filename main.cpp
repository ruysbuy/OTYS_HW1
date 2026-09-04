#include <cstdint>
#include <vector>
#include <iostream>

//uint64_t L1NomStrideAccess(const std::vector<std::vector<uint64_t>>& matrix) {
//    size_t n = matrix.size();
//    uint64_t maxSum = 0;
//
//    for (size_t j = 0; j < n; j++) {
//        uint64_t columnSum = 0;
//        for (size_t i = 0; i < n; i++) {
//            columnSum += matrix[i][j];
//        }
//        if (maxSum < columnSum) {
//            maxSum = columnSum;
//        }
//    }
//    return maxSum;
//}

uint64_t L1NomSequentialAccess(const std::vector<std::vector<uint64_t>>& matrix) {
    size_t n = matrix.size();
    uint64_t maxSum = 0;

    for (size_t i = 0; i < n; i++) {
        uint64_t columnSum = 0;
        for (size_t j = 0; j < n; j++) {
            columnSum += matrix[i][j];
        }
        if (maxSum < columnSum) {
            maxSum = columnSum;
        }
    }
    return maxSum;
}

int main(int argc, char** argv) {

    int n = 10000;

    std::vector<std::vector<uint64_t>> matrix(n, std::vector<uint64_t>(n, 0));

    for (size_t t = 0; t < 1; t++){
        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < n; j++) {
                matrix[i][j] = rand() % 1000;
            }
        }
    }

    //uint64_t L1 = L1NomStrideAccess(matrix);

    uint64_t L1 = L1NomSequentialAccess(matrix);

    std::cout << "Result: " << L1 << std::endl;

    return 0;
}
