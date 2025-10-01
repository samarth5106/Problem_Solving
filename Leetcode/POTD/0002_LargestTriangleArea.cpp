
class Solution {
    private:
    double calArea(vector<int>&p1,vector<int>&p2,vector<int>&p3){
        int x1=p1[0],y1=p1[1];
        int x2=p2[0],y2=p2[1];
        int x3=p3[0],y3=p3[1];
        return 0.5*abs(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2));
    }
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double area;
        double maxi=-1.0;
        int n=points.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    area=calArea(points[i],points[j],points[k]);
                    maxi=max(maxi,area);
                }

            }
        }
        return maxi;
    }
    
};
