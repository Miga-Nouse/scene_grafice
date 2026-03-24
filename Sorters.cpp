//#include <iostream>
//#include <cstdlib>
//#include <chrono>
//
//// ============ RADIX SORT FUNCTIONS ============
//int max(int n, int* arr) {
//    int m = arr[0];
//    for (int i = 0; i < n; i++) {
//        if (m < arr[i]) {
//            m = arr[i];
//        }
//    }
//    return m;
//}
//
//void countsort(int n, int* arr, int exp) {
//    int countrr[10] = { 0 };
//    int* outrr = new int[n];
//
//    for (int i = 0; i < n; i++) {
//        countrr[(arr[i] / exp) % 10]++;
//    }
//
//    for (int i = 1; i < 10; i++) {
//        countrr[i] += countrr[i - 1];
//    }
//
//    for (int i = n - 1; i >= 0; i--) {
//        int digit = (arr[i] / exp) % 10;
//        outrr[countrr[digit] - 1] = arr[i];
//        countrr[digit]--;
//    }
//
//    for (int i = 0; i < n; i++) {
//        arr[i] = outrr[i];
//    }
//
//    delete[] outrr;
//}
//
//void radixSort(int n, int* arr) {
//    int m = max(n, arr);
//    for (int exp = 1; m / exp > 0; exp *= 10) {
//        countsort(n, arr, exp);
//    }
//}
//
//// ============ MERGE SORT FUNCTIONS ============
//void merge(int* arr, int left, int mid, int right) {
//    int n1 = mid - left + 1;
//    int n2 = right - mid;
//
//    int* L = new int[n1];
//    int* R = new int[n2];
//
//    for (int i = 0; i < n1; i++)
//        L[i] = arr[left + i];
//    for (int j = 0; j < n2; j++)
//        R[j] = arr[mid + 1 + j];
//
//    int i = 0, j = 0, k = left;
//
//    while (i < n1 && j < n2) {
//        if (L[i] <= R[j]) {
//            arr[k] = L[i];
//            i++;
//        }
//        else {
//            arr[k] = R[j];
//            j++;
//        }
//        k++;
//    }
//
//    while (i < n1) {
//        arr[k] = L[i];
//        i++;
//        k++;
//    }
//
//    while (j < n2) {
//        arr[k] = R[j];
//        j++;
//        k++;
//    }
//
//    delete[] L;
//    delete[] R;
//}
//
//void mergeSort(int* arr, int left, int right) {
//    if (left < right) {
//        int mid = left + (right - left) / 2;
//        mergeSort(arr, left, mid);
//        mergeSort(arr, mid + 1, right);
//        merge(arr, left, mid, right);
//    }
//}
//
//// ============ MAIN FUNCTION ============
//int main() {
//    int n;
//
//    std::cout << "Enter the number of elements: ";
//    std::cin >> n;
//
//    
//    int* arr = new int[n];
//
//    
//    std::cout << "Original array: ";
//    for (int i = 0; i < n; i++) {
//        arr[i] = rand() % 100;
//        std::cout << arr[i] << " ";
//    }
//    std::cout << std::endl;
//
//    
//    int choice;
//    std::cout << "Choose sorting algorithm:\n";
//    std::cout << "1. Merge Sort\n";
//    std::cout << "2. Radix Sort\n";
//    std::cout << "Enter choice: ";
//    std::cin >> choice;
//
//    if (choice == 1) {
//        auto start = std::chrono::high_resolution_clock::now();
//        mergeSort(arr, 0, n - 1);
//        auto end = std::chrono::high_resolution_clock::now();
//        std::cout << "Sorted using Merge Sort: ";
//        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
//        std::cout << "\n=== Timing Results ===" << std::endl;
//        std::cout << "Time taken: " << duration.count() << " microseconds" << std::endl;
//        std::cout << "Time taken: " << duration.count() / 1000.0 << " milliseconds" << std::endl;
//        
//    }
//    else if (choice == 2) {
//        auto start = std::chrono::high_resolution_clock::now();
//        radixSort(n, arr);
//        auto end = std::chrono::high_resolution_clock::now();
//        std::cout << "Sorted using Radix Sort: ";
//        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
//        std::cout << "\n=== Timing Results ===" << std::endl;
//        std::cout << "Time taken: " << duration.count() << " microseconds" << std::endl;
//        std::cout << "Time taken: " << duration.count() / 1000.0 << " milliseconds" << std::endl;
//        
//    }
//    else {
//        std::cout << "Invalid choice, using Merge Sort: ";
//        auto start = std::chrono::high_resolution_clock::now();
//        mergeSort(arr, 0, n - 1);
//        auto end = std::chrono::high_resolution_clock::now();
//        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
//        std::cout << "\n=== Timing Results ===" << std::endl;
//        std::cout << "Time taken: " << duration.count() << " microseconds" << std::endl;
//        std::cout << "Time taken: " << duration.count() / 1000.0 << " milliseconds" << std::endl;
//        
//    }
//   
//    
//    for (int i = 0; i < n; i++) {
//        std::cout << arr[i] << " ";
//    }
//    std::cout << std::endl;
//
//    
//    delete[] arr;
//
//    return 0;
//}