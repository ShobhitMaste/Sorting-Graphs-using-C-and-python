#include<bits/stdc++.h>
#include<chrono>
#include "sorts.h"

using namespace std;
using namespace std::chrono;

int selection_sort(vector<int> arr){
    auto start = high_resolution_clock::now();
    int n = arr.size();
    for(int i = 0; i < n; i++){
        int min_index = i;
        int min_val = arr[i];
        for(int j = i + 1; j < n; j++){
            if(arr[j] < min_val){
                min_val = arr[j];
                min_index = j;
            }
        }
        swap(arr[min_index], arr[i]);
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    return duration.count();
}

int insertion_sort(vector<int> arr){
    auto start = high_resolution_clock::now();

    int n = arr.size();
    for(int i = 1; i < n; i++){
        int j = i - 1;
        int key = arr[i];
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    return duration.count();
}

void merge(vector<int>& arr, int l, int mid, int r){
    vector<int> t1(arr.begin() + l, arr.begin() + mid + 1);
    vector<int> t2(arr.begin() + mid + 1, arr.begin() + r + 1);
    int i1 = 0, i2 = 0;
    while(i1 < static_cast<int>(t1.size()) && i2 < static_cast<int>(t2.size())){
        if(t1[i1] < t2[i2]){
            arr[l++] = t1[i1++];
        } else {
            arr[l++] = t2[i2++];
        }
    }
    while(i1 < static_cast<int>(t1.size())){
        arr[l++] = t1[i1++];
    }

    while(i2 < static_cast<int>(t2.size())){
        arr[l++] = t2[i2++];
    }
}

void merge_sort(vector<int>& arr, int l, int r){
    if(l >= r) return;
    int mid = (l + r) / 2;
    merge_sort(arr, l, mid);
    merge_sort(arr, mid + 1, r);
    merge(arr, l, mid, r);
}

int initiate_merge_sort(vector<int> arr){
    auto start = high_resolution_clock::now();
    
    merge_sort(arr, 0, arr.size() - 1);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    return duration.count();
}

void quick_sort(vector<int>& arr, int l, int r){
    if(l >= r) return;
    int pivot = arr[l];
    int low = l + 1;
    int high = r;
    while(low <= high){
        while(arr[low] <= pivot) low++;
        while(arr[high] > pivot) high--;
        if(low <= high){
            swap(arr[low], arr[high]);
        }
    }
    swap(arr[high], arr[l]);
    quick_sort(arr, l, high - 1);
    quick_sort(arr, high + 1, r);
}

int initiate_quick_sort(vector<int> arr){
    auto start = high_resolution_clock::now();

    quick_sort(arr, 0, arr.size() - 1);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    return duration.count();
}

int gnu_sort(vector<int> &arr){
    auto start = high_resolution_clock::now();

    sort(arr.begin(), arr.end());

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    return duration.count();
}