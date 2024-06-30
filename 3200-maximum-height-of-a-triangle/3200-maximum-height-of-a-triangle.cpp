class Solution {
public:
    int f(int red,int blue){
        int cnt=0;
        int i=1;
        while(true){
            if(red>=i && i%2==1){
                red-=i;
                cnt++;
            }
            else if(blue>=i && i%2==0){
                blue-=i;
                cnt++;
            }
            else{
                break;
            }
            i++;
        }
        return cnt;
    }
    int maxHeightOfTriangle(int red, int blue) {
        return max(f(red,blue),f(blue,red));
    }
};