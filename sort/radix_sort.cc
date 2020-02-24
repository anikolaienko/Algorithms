#include "./include/sort.hpp"

// template<class T>
// bool count_sort(std::vector<T>& A, int i);


// more like a bucket sort
void count_sort(std::vector<int>& A, int i) {
    std::vector<int> B;
    int bit = 1 << i;
    int j = 0;
    for (int i = 0; i < A.size(); i++)
        if (A[i] & bit) B.push_back(A[i]);
        else A[j++] = A[i];

    for (int i = 0; i < B.size(); i++)
        A[j++] = B[i];
}

void count_sort_alt(std::vector<int>& A, int i) {

}
// void RadixSortLSD(int *a, int arraySize)
// {
// 	int i, bucket[MAX], maxVal = 0, digitPosition =1 ;
// 	for(i = 0; i < arraySize; i++) {
// 		if(a[i] > maxVal) maxVal = a[i];
// 	}

// 	int pass = 1;  // used to show the progress
// 	/* maxVal: this variable decide the while-loop count 
// 	           if maxVal is 3 digits, then we loop through 3 times */
// 	while(maxVal/digitPosition > 0) {
// 		/* reset counter */
// 		int digitCount[10] = {0};

// 		/* count pos-th digits (keys) */
// 		for(i = 0; i < arraySize; i++)
// 			digitCount[a[i]/digitPosition%10]++;

// 		/* accumulated count */
// 		for(i = 1; i < 10; i++)
// 			digitCount[i] += digitCount[i-1];

// 		/* To keep the order, start from back side */
// 		for(i = arraySize - 1; i >= 0; i--)
// 			bucket[--digitCount[a[i]/digitPosition%10]] = a[i];

// 		/* rearrange the original array using elements in the bucket */
// 		for(i = 0; i < arraySize; i++)
// 			a[i] = bucket[i];

// 		/* at this point, a array is sorted by digitPosition-th digit */
// 		cout << "pass #" << pass++ << ": ";
// 		print(a,arraySize);

// 		/* move up the digit position */
// 		digitPosition *= 10;
// 	}   
//  }

void count_sort(std::vector<std::string>& A, int i) {

}

int getMax(std::vector<int> A) {
    int min = 32;
    for (int& a: A) {
        int count = __builtin_clz(a);
        if (count < min) min = count;
    }
    return 32 - min;
}

int getMax(std::vector<std::string> A) {
    int max = 0;
    for (std::string& s: A)
        if (s.size() > max) max = s.size();
    return max;
}

template <class T>
void radix_sort(std::vector<T> A) {
    int maxPos = getMax(A);
    for (int i = 0; i < maxPos; i++)
        count_sort(A, i);
}