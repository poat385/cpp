#include <iostream>
using namespace std;

template<typename T>
T sum_array(const T arr[], size_t size)
{
    T result = T(); 
    
    for(size_t i = 0; i < size; ++i)
    {
        result += arr[i];
    }
    
    return result;
}

int main()
{
    int arr[] = {1, 2, 3, 4};
    double dbl_arr[] = {1.1, 2.2, 3.3, 4.4};
    
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    int dbl_size = sizeof(dbl_arr) / sizeof(dbl_arr[0]);

    cout << sum_array(arr, arr_size) << endl;
    cout << sum_array(dbl_arr, dbl_size) << endl;
    
    return 0;
}