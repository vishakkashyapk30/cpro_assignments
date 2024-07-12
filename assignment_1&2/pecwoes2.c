#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    
    int totalArea = 0;
    
    for (int i = 0; i < N; i++) {
        int ai, bi, ci, di;
        scanf("%d %d %d %d", &ai, &bi, &ci, &di);
        
        
        int area = (bi - ai) * (di - ci);
        
        
        for (int j = 0; j < i; j++) {
            int aj, bj, cj, dj;
            scanf("%d %d %d %d", &aj, &bj, &cj, &dj);
            
            
            int width = 0;
            int height = 0;
            
            if (ai < bj && aj < bi) {
                width = (bj < bi) ? (bj - ai) : (bi - aj);
            }
            
            if (ci < dj && cj < di) {
                height = (dj < di) ? (dj - ci) : (di - cj);
            }
            
           
            area -= width * height;
        }
        
      
        totalArea += area;
    }
    
    printf("%d\n", totalArea);
    
    return 0;
}