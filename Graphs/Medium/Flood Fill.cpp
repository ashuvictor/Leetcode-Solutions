



An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.

Return the modified image after performing the flood fill.



class Solution {
public:
    void solve(vector<vector<int>>&image,int sr,int sc,int newColor,int oldColor)
    {
        if(sr<0 or sr>=image.size() or sc<0 or sc>=image[0].size() or image[sr][sc]!=oldColor or image[sr][sc]==newColor)
            return;
        image[sr][sc]=newColor;
        solve(image,sr+1,sc,newColor,oldColor);
           solve(image,sr,sc-1,newColor,oldColor);
           solve(image,sr,sc+1,newColor,oldColor);
           solve(image,sr-1,sc,newColor,oldColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        solve(image,sr,sc,newColor,image[sr][sc]);
        return image;
    }
};