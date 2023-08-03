#include <stdio.h>
#include <stdlib.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int mid, i, p1 = 0, p2 = 0, trace = 0;
    mid = (nums1Size + nums2Size) / 2;
    for(i = 0; i <= mid; i++){
        if(p1 < nums1Size && p2 < nums2Size){
            if(nums1[p1] < nums2[p2]){
                p1++;
            }
            else{
                p2++;
                if(i >= mid - 1){
                    trace++;
                }
            }
        }
        else if(p1 == nums1Size){
            p2++;
            if(i >= mid - 1){
                trace++;
            }
        }else if(p2 == nums2Size){
            p1++;
        }          
    }
    
    p1--; p2--;
    printf("P1: %d, P2: %d, Trace: %d", p1, p2, trace);

    if((nums1Size + nums2Size) % 2 != 0){
        if(trace == 0)
            return  (double) nums1[p1];
        else if(trace == 1)
            if(nums1[p1] > nums2[p2])
                return  (double) nums1[p1];
            else
                return (double) nums1[p2];
        else
            return  (double) nums2[p2];
    }
    else{
        if(trace == 0)
            return  (double)(nums1[p1 - 1] + nums1[p1]) / 2;
        else if(trace == 1)
            return  (double)(nums1[p1] + nums2[p2]) / 2;
        else
            return  (double)(nums2[p2 - 1] + nums2[p2]) / 2;
    }

    return 0;
}



int main(){
    int arr1[2] = {1,2};
    int arr2[2] = {3,4};
    int arr1Size = 2, arr2Size = 2;
    //printf("%d", arr1[0]);
    double a = findMedianSortedArrays(arr1, arr1Size, arr2, arr2Size);
    printf("\n%f", a);
}