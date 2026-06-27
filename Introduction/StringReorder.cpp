#include <iostream>
#include <vector>
#include <set>

using namespace std;

int next(int i, const vector<int>& counts){
    int n = counts.size();
    while(i < n && counts[i] == 0) ++i;
    return i;
}

int main(){
    string line;
    getline(cin, line);
    int m = line.length(), n = 'Z' - 'A' + 1;
    vector<int> counts(n, 0);
    for(char c : line){
        counts[c - 'A'] += 1;
    }
    set<pair<int, int>> count_to_idx;
    set<int> idx_to_count;
    for(int i = 0; i < n; ++i){
        if(counts[i] > 0){
            count_to_idx.insert({counts[i], i});
            idx_to_count.insert(i);
        }
    }
    if(2 * count_to_idx.rbegin()->first > m + 1){
        printf("-1");
        return 0;
    }
    string result = "";
    int last_added = -1;
    for(int i = 0; i < m; ++i){
        int idx_to_add = -1;
        if(2 * count_to_idx.rbegin()->first == m - i + 1){
            idx_to_add = count_to_idx.rbegin()->second;
        }else{
            auto it = idx_to_count.begin();
            if(*it == last_added) ++it;
            idx_to_add = *it;
        }
        result += (char)('A' + idx_to_add);
        last_added = idx_to_add;
        count_to_idx.erase(count_to_idx.find({counts[idx_to_add], idx_to_add}));
        counts[idx_to_add] -= 1;
        if(counts[idx_to_add] > 0){
            count_to_idx.insert({counts[idx_to_add], idx_to_add});
        }else{
            idx_to_count.erase(idx_to_add);
        }
    }
    cout << result << endl;
}