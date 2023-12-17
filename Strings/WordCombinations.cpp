#include <iostream>
#include <array>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

constexpr int len = 'z' - 'a' + 1;
constexpr int start = 'a';

struct node{
    array<int, len> edges;
    bool terminal;
    node(){
        edges.fill(-1);
        terminal = false;
    }
};

struct trie{
    vector<node> nodes;
    trie(){
        nodes.push_back(node());
    }
    void add(string& word){
        int idx = 0;
        for(char c : word){
            if(nodes[idx].edges[c - start] == -1){
                nodes[idx].edges[c - start] = nodes.size();
                nodes.push_back(node());
            }
            idx = nodes[idx].edges[c - start];
        }
        nodes[idx].terminal = true;
    }
    bool contains(string& word){
        int idx = 0;
        for(char c : word){
            if(nodes[idx].edges[c - start] == -1) return false;
            idx = nodes[idx].edges[c - start];
        }
        return nodes[idx].terminal;
    }
};

const int mod = 1e9 + 7;

int main(){
    string str, word;
    getline(cin, str);
    int k, n = str.length();
    scanf("%d ", &k);
    trie t;
    for(int i = 0; i < k; ++i){
        getline(cin, word);
        t.add(word);
    }

    vector<ll> dp(n + 1, 0);
    dp[0] = 1;
    for(int i = 0; i < n; ++i){
        if(dp[i] == 0) continue;
        int idx = 0;
        for(int j = i; j < n; ++j){
            char c = str[j];
            idx = t.nodes[idx].edges[c - start];
            if(idx == -1) break;
            if(t.nodes[idx].terminal) dp[j+1] = (dp[j+1] + dp[i]) % mod;
        }
    }
    printf("%ld", dp[n]);
}