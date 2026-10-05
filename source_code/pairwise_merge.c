#include <stdio.h>

void merge(int a[], int n, int b[], int m, int result[]) {
    int i=0, j=0, k=0;
    while (i<n && j<m) {
        if (a[i] < b[j]) result[k++] = a[i++];
        else result[k++] = b[j++];
    }
    while (i<n) result[k++] = a[i++];
    while (j<m) result[k++] = b[j++];
}
int main() {
    int L1[]={10,30,50,70}, L2[]={20,40,60,80}, L3[]={15,35,55,75};
    int temp[8], result[12];
    merge(L1,4,L2,4,temp);
    printf("After merging L1 and L2:\n");
    for(int i=0;i<8;i++) printf("%d ",temp[i]);
    merge(temp,8,L3,4,result);
    printf("\n\nFinal Pairwise Merge:\n");
    for(int i=0;i<12;i++) printf("%d ",result[i]);
    printf("\n");
    return 0;
}
