#include <stdio.h>

void mergeArrays(int a[], int s1, int b[], int s2, int m[]) {
    int i=0, j=0, k=0;
    while(i<s1 && j<s2) m[k++] = (a[i]<b[j]) ? a[i++] : b[j++];
    while(i<s1) m[k++] = a[i++];
    while(j<s2) m[k++] = b[j++];
}

int main() {
    int a[] = {1, 3, 5}, b[] = {2, 4, 6}, m[6];
    mergeArrays(a, 3, b, 3, m);
    for(int i=0; i<6; i++) printf("%d ", m[i]);
    return 0;
}
