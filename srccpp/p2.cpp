
#include <iostream>
#include <vector>
#include <stack>

using namespace std;
int depth;
int m;
int n;

struct cord{
    int d;
    int x;
    int y;
};

bool outOfBounds(int d, int x, int y){
    return d < 0 || x < 0 || y < 0 || d >= depth || x >= m || y >= n;
}

int main(){

    cin >> depth;
    cin >> m;
    cin >> n;

    char arr[depth][m][n];

    for(int i = 0; i < depth; i++){
        for(int j = 0; j < m; j++){
            for(int k = 0; k < n; k++){
                cin >> arr[i][j][k];
            }
        }
    }

    int x;
    int y;
    cin >> x;
    cin >> y;

    struct cord start = {0, x-1, y-1};
    stack<struct cord> st;
    st.push(start);
    int dxr[6][3] = {{-1,0,0},{1,0,0},{0,-1,0},{0, 1, 0},{0,0,-1},{0,0,1}};

    int numvis = 0;
    while(!st.empty()){
        struct cord cur = st.top();
        st.pop();
        if(arr[cur.d][cur.x][cur.y] == '#') continue;
        for(int i = 0; i < 6; i++){
            struct cord dd = {cur.d + dxr[i][0], cur.x + dxr[i][1], cur.y + dxr[i][2]};
            if(outOfBounds(dd.d, dd.x, dd.y) || arr[dd.d][dd.x][dd.y] == '#'){
                continue;
            }
            st.push(dd);
        }
        numvis++;
        //mark visited
        // cout << "visited: " << cur.d << " " << cur.x << " " << cur.y << endl;
        arr[cur.d][cur.x][cur.y] = '#';

    }

    cout << numvis << endl;

    //finished reading input;
    

    
}
