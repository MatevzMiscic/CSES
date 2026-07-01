#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

struct fenwick{
    int n;
    vector<ll> arr;
    vector<ll> tree;
    fenwick(int n): n(n){
        arr.assign(n, 0);
        tree.assign(n + 1, 0);
    }
    void set(int i, ll x){
        add(i, x - arr[i]);
    }
    void add(int i, ll x){
        arr[i] += x;
        for(int j = i + 1; j <= n; j += j & -j) tree[j] += x;
    }
    ll query(int i){
        ll sum = 0;
        for(int j = i + 1; j > 0; j -= j & -j) sum += tree[j];
        return sum;
    }
    ll query(int a, int b){
        return query(b) - query(a-1);
    }
};

constexpr ll HOR_BEGIN = 0, HOR_END = 2, VER = 1;

struct event{
    ll type, x, y1, y2, time;
    bool operator<(const event &other) const{
        if(x != other.x) return x < other.x;
        return type < other.type;
    }
};

struct segment{
    ll x1, y1, x2, y2, len;
    bool hor() const{
        return y1 == y2;
    }
    ll intersect(const segment &other) const{
        if(max(y1, y2) < min(other.y1, other.y2) || max(other.y1, other.y2) < min(y1, y2)) return len;
        if(max(x1, x2) < min(other.x1, other.x2) || max(other.x1, other.x2) < min(x1, x2)) return len;
        if(hor()) return abs(other.x1 - x1);
        return abs(other.y1 - y1);
    }
};

bool intersections(vector<event> &events, int m, int last){
    fenwick tree(m);
    for(event& e : events){
        int limit = (e.time < 0 || e.time == last ? 1 : 2);
        if(e.type == HOR_BEGIN){
            //printf("adding 1 at x= %lld, y = %lld\n", e.x, e.y1);
            tree.add(e.y1, 1);
        }else if(e.type == HOR_END){
            //printf("subtracting 1 at x = %lld, y = %lld\n", e.x, e.y1);
            tree.add(e.y1, -1);
        }else if(e.type == VER){
            //printf("inter at x = %lld, on y = [%lld, %lld] of time %lld\n", e.x, e.y1, e.y2, e.time);
            //for(int i = 0; i < m; ++i) printf("%lld ", tree.query(i, i));
            //printf("\nlimit: %d\n", limit);
            if(tree.query(e.y1, e.y2) > limit) return true;
        }
    }
    return false;
}

char reverse(char dir){
    if(dir == 'D') return 'U';
    if(dir == 'U') return 'D';
    if(dir == 'R') return 'L';
    if(dir == 'L') return 'R';
    return 'S';
}

int main(){
    int n;
    char dir, lastdir = 'S';
    ll x = 0, y = 0, dist = 0;
    scanf("%d ", &n);
    vector<ll> compress = {0};
    vector<event> events;
    vector<segment> segments;
    vector<ll> distance = {0};
    int j = 0;
    for(int i = 0; i < n; i++){
        int curdist;
        scanf("%c %d ", &dir, &curdist);
        if(lastdir == 'S'){
            if(dir == 'U' || dir == 'D'){
                events.push_back({HOR_BEGIN, 0, 0, 0, -1});
                events.push_back({HOR_END, 0, 0, 0, -1});
            }else{
                events.push_back({VER, 0, 0, 0, -1});
            }
        }else if(dir != lastdir){
            distance.push_back(distance.back() + dist);
            if(lastdir == 'U'){
                events.push_back({VER, x, y, y + dist, j});
                segments.push_back({x, y, x, y + dist, dist});
                y += dist;
                compress.push_back(y);
            }else if(lastdir == 'D'){
                events.push_back({VER, x, y - dist, y, j});
                segments.push_back({x, y, x, y - dist, dist});
                y -= dist;
                compress.push_back(y);
            }else if(lastdir == 'R'){
                events.push_back({HOR_BEGIN, x, y, y, j});
                events.push_back({HOR_END, x + dist, y, y, j});
                segments.push_back({x, y, x + dist, y, dist});
                x += dist;
            }else if(lastdir == 'L'){
                events.push_back({HOR_BEGIN, x - dist, y, y, j});
                events.push_back({HOR_END, x, y, y, j});
                segments.push_back({x, y, x - dist, y, dist});
                x -= dist;
            }
            dist = 0;
            j += 1;
        }
        if(reverse(dir) == lastdir){
            break;
        }
        dist += curdist;
        lastdir = dir;
    }
    if(dist > 0){
        distance.push_back(distance.back() + dist);
        if(lastdir == 'U'){
            events.push_back({VER, x, y, y + dist, j});
            segments.push_back({x, y, x, y + dist, dist});
            y += dist;
            compress.push_back(y);
        }else if(lastdir == 'D'){
            events.push_back({VER, x, y - dist, y, j});
            segments.push_back({x, y, x, y - dist, dist});
            y -= dist;
            compress.push_back(y);
        }else if(lastdir == 'R'){
            events.push_back({HOR_BEGIN, x, y, y, j});
            events.push_back({HOR_END, x + dist, y, y, j});
            segments.push_back({x, y, x + dist, y, dist});
            x += dist;
        }else if(lastdir == 'L'){
            events.push_back({HOR_BEGIN, x - dist, y, y, j});
            events.push_back({HOR_END, x, y, y, j});
            segments.push_back({x, y, x - dist, y, dist});
            x -= dist;
        }
        dist = 0;
        j += 1;
    }
    n = j;
    //for(segment& s : segments) printf("(%lld, %lld)--(%lld, %lld)\n", s.x1, s.y1, s.x2, s.y2);
    //for(event& e : events) printf("type: %lld, x: %lld, y1: %lld, y2: %lld, time: %lld\n", e.type, e.x, e.y1, e.y2, e.time);
    sort(compress.begin(), compress.end());
    compress.erase(unique(compress.begin(), compress.end()), compress.end());
    for(event& e : events){
        e.y1 = lower_bound(compress.begin(), compress.end(), e.y1) - compress.begin();
        e.y2 = lower_bound(compress.begin(), compress.end(), e.y2) - compress.begin();
    }
    //for(event& e : events) printf("type: %lld, x: %lld, y1: %lld, y2: %lld, time: %lld\n", e.type, e.x, e.y1, e.y2, e.time);
    sort(events.begin(), events.end());
    int a = 1, b = n + 1;
    while(b - a > 1){
        int mid = (a + b) / 2;
        vector<event> subevents;
        for(event& e : events){
            if(e.time < mid) subevents.push_back(e);
        }
        if(intersections(subevents, compress.size(), mid - 1)) b = mid;
        else a = mid;
        //printf("At %d there are intersections: %d\n", mid, (int)(b == mid));

    }
    if(b == n + 1){
        printf("%lld\n", distance[n]);
    }else{
        ll ans = segments[a].len;
        for(int i = 0; i < a - 1; i++){
            //printf("seg %d -> seg %d: intersect = %lld\n", a, i, segments[a].intersect(segments[i]));
            ans = min(ans, segments[a].intersect(segments[i]));
        }
        //printf("First %d steps are ok. Distance: %lld, length of the last step: %lld\n", a, distance[a], ans);
        ans += distance[a];
        printf("%lld\n", ans);
    }
}