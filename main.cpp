#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;
const int n = 150;

void generateFifthPowers(unsigned long long* array_given) {

    for (unsigned long long i = 0; i < n; i++)
    {
        array_given[i] = i * i * i * i * i;
    }


    return;
}


int binarySearch(unsigned long long arr[], int l, int r, unsigned long long x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;

        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;

        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid + 1, r, x);
    }

    // We reach here when element is not
    // present in array
    return -1;
}


void findNumber(unsigned long long array_given[]) {


    // a^5+b^5+c^5+d^5 = e^5
    // a <= b <= c <= d <= e <= n (150 by default)

    int aIndex = 0;
    int bIndex = 0;
    int cIndex = 0;
    int dIndex = 0;
    unsigned long long total_sum = 0;
    unsigned long long max_sum = array_given[n - 1];






    for (aIndex = 1; aIndex < n; aIndex++)
    {
        for (bIndex = aIndex; bIndex < n; bIndex++)
        {
            for (cIndex = bIndex; cIndex < n; cIndex++)
            {
                for (dIndex = cIndex; dIndex < n; dIndex++)
                {
                    total_sum = array_given[aIndex] + array_given[bIndex] + array_given[cIndex] + array_given[dIndex];




                    if (total_sum <= max_sum) {


                        int binarySearchResult = binarySearch(array_given, dIndex, n, total_sum);

                        if (binarySearchResult != -1) {




                            cout << aIndex << "^5 + " << bIndex << "^5 + " << cIndex << "^5 + " << dIndex << "^5 = " << binarySearchResult << "^5" << endl;

                            return;
                        }


                    }
                    else {
                        dIndex = n + 1;
                    }


                }
            }
        }
    }


}

int main() {


    unsigned long long x_fifth[n];
    unsigned long long* x_fifth_ptr = x_fifth;

    generateFifthPowers(x_fifth_ptr);





    findNumber(x_fifth);



    return 0;
}
