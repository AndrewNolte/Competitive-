
#include <iostream>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <utility>
#include <queue>
#include <stack>
#include <unordered_map>
#include <climits>

using namespace std;

//returns the spot that this substring can be "added" into the current string
pair<string, int> doesWork(string s, vector<bool> done, string add){
    //first check if add is already inside
    int n = s.find(add);
    while(n != string::npos){
        if(done[n]){
            n = s.find(add, n+1);
            continue;
        }
        return {s, n};
    }
    //check if can be put on either end, matching 2
    
    if(s.substr(0, 2) == add.substr(1, 2)){//put at beginning, matching 2
        return {add[0] + s, -1};//encode a shift
    }
    if(s.substr(s.size()-2, 2) == add.substr(0, 2)){//put at end
        return {s + add[2], s.size()-2}
    }
    if(s.substr(2, 1) == add.substr(1, 2)){//put at beginning, matching 2
        return {add.substr(0, 2) + s, -2};//encode a shift
    }
    if(s.substr(s.size()-2, 2) == add.substr(0, 2)){//put at end
        return {s + add.substr(1,2), s.size()-2}
    }
    return {s, -3}; //cant match anywhere, we'll save for later
}

vector<bool> finished;

int main()
{
    int n;
    cin >> n;
    fi
    // a1 = 3 a2 = 2 a3 = 3

    //     b1 = 1 b2 = 2 b3 = 1

    //     c 1 = 1 c 2 = 1 c 3 = 1

    //     a2 b3 a3 b1 a2 a1
    string cul = "";
    // vector<string> toCheck;
    // for (int i = 0; i < n; i++){
    //     finished.push_back(false);
    // }
    
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if(i == 0){
            cul = s;
            finished.push_back(true);
            finished.push_back(false);
            finished.push_back(false);
            continue;
        }
        pair ans = doesWork(cul, s);
        if(ans.second == -3 || ){
            toCheck.push_back(ans.second);
            continue;
        }
        if(ans.second < 0){
            if(ans.second == -1){
                finished.insert(finished.begin(), true);
            }else{
                finished.insert(finished.begin(), false);
                finished.insert(finished.begin(), true);
            }
            cul = ans.first;
            continue;
        }

        if(ans.second >= cul.size()-2){
            int dif = ans.second-(cul.size()-2);
            if(dif == 0){
                finished.push_back(false);

            }else{//dif = 1
                finished.push_back(false);
                finished.push_back(false);
            }
            finished[ans.second] = true;
            cul = ans.first;
            continue;
        }

        finished[ans.second] = true;
    }
    
}