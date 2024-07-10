class Solution {
public:
    bool f(int sx,int sy,int tx,int ty){
        if(tx<sx ||ty<sy)return false;
        else if(tx==sx)return ((ty-sy)%sx)==0;
        else return f(sy,sx,ty%tx,tx);
        
    }
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        if(tx<ty){
            return f(sx,sy,tx,ty);
        }else{
            return f(sy,sx,ty,tx);
        }
    }
};