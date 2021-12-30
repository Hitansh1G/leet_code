class Solution {
public:
    int hcf(int a, int b)
    {
        if(b==0) return a;
        return hcf(b,a%b);
    }
    bool canMeasureWater(int x, int y, int z) {
        if(x+y<z) return 0;
        if(z==0) return 1;
        if(x==0&&y==0&&z!=0) return 0;
        if(x==0&&y!=0&&y!=z) return 0;
        if(x==0&&y!=0&&y==z) return 1;
        if(x!=0&&y==0&&x!=z) return 0;
        if(x!=0&&y==0&&x==z) return 1;
        if(x<y) swap(x,y);
            hcf(x,y);
        if(z%hcf(x,y)==0) return 1;
        return 0;
    }
};