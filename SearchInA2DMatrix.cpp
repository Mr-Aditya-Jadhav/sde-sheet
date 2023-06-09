//https://www.codingninjas.com/codestudio/problems/search-in-a-2d-matrix_8230773?challengeSlug=striver-sde-challenge

bool searchMatrix(vector<vector<int>>& mat, int target) {
    int x = mat.size();
    int y = mat[0].size();
    int a = 0, b = x*y-1;
    while (a <= b){
        int mid = (a+b)/2;
        if(target == mat[mid/y][mid%y]) return true;
        else{
            if(target > mat[mid/y][mid%y])
                a = mid+1;
            else b = mid-1;
        }
    }
    return false;
}