#include "minFunc.h"
const int * min(const int arr[], int arrSize) {
      
    if (arrSize == 0)
    {
        return nullptr;
    }
    else if (arrSize == 1)
    {
        return arr;
    }
    else 
    {
        const int* a = arr + arrSize - 1;
        const int* b = min(arr, arrSize - 1);

        if (*b < *a)
        {
            return b;
        }
        else
        {
            return a;
        }
    }
}