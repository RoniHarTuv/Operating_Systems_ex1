#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int maxSubArray(vector<int> array, int size)
{
    int best = 0, sum = 0;
    for (int k = 0; k < size; k++)
    {
        sum = max(array[k], sum + array[k]);
        best = max(best, sum);
    }
    return (best);
}

int return_random_number(){
    return rand();
}

int main(int argc, char *argv[])
{
    int random_seed = atoi(argv[1]);
    int size_of_arr = atoi(argv[2]);
    int lower_bound = -25;
    int upper_bound = 30;
    srand(random_seed);
    vector<int> arr(size_of_arr);
    for (int i = 0; i < size_of_arr; i++)
    {
        int random_number = return_random_number() % (upper_bound - lower_bound + 1) + lower_bound;
        arr[i] = random_number;
    }
    cout << "max subArray sum:" << maxSubArray(arr, size_of_arr);
    return 0;
}