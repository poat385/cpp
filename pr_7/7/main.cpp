#include <iostream>

using namespace std;

template <typename T, size_t N>
void copy_array(const T (&source)[N], T (&destination)[N]) {
    for (size_t i = 0; i < N; ++i) {
        destination[i] = source[i];
    }
}

int main() {

    int arr_one[] = {10, 20, 30, 40, 50};
    int arr_two[5] = {0};

    copy_array(arr_one, arr_two);

    for(int i : arr_two) {
        cout << i << " ";
    }

    cout << "\n";

    char arr_three[] = {'h', 'a', 'c', 'k', ' ', 'm', 'e', ' ', 'p', 'l', 'e', 'a', 's', 'e', ' ', 'D', 'K', 'I', 'T'};
    char arr_four[19] = {'\0'};

    copy_array(arr_three, arr_four);

    for(char i : arr_four) {
        cout << i << " ";
    }

    return 0;
}