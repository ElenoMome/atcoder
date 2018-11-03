//二分木で考える貪欲法

//コストの合計は，各葉の節点の板の長さx節点の深さ

typedef long long ll;

//入力
int N, L[MAX_N];

void solve()
{
    ll ans = 0;

    while(N > 1)
    {
        int mil1 = 0; mil2 = 1;
        if(L[mil1] > L[mil2]) swap(mil1, mil2);

        rep(i=2, N)
        {
            if(L[i] < L[mil1])
            {
                mil2 = mil1;
                mil1 = i;
            }
            else if (L[i] < L[mil2])
            {
                mil2 = i;
            }
        }
    }
}
//美しくない......

//動的計画法
//ナップサック問題
//愚直に各品物を入れるか入れないかで分岐しながら全探索

int n, W;
int w[MAX_N], v[MAX_N];

//i番目以降の品物から重さの総和がj以下となるように選ぶ
int rec(int i, int j)
{
    int res;
    if (i == n) res = 0; //品物はもう残っていない
    else if(j < w[i])
    {
        res = rec(i + 1, j);
    }
    else
    {
        res = max(rec(i+1, j), rec(i + 1, j - w[i]) + v[i]);
    }
    return res;
}

void solve()
{
    cout << rec(0, W);
}

//動的計画法メモリ保存版

int dp[MAX_N+1][MAX_W+1];

int rec(int i, int j)
{
    if(dp[i][j] >= 0) return dp[i][j];
    int res;
    if(i == n) res = 0;
    else if(j < w[i])
    {
        res = rec(i+1, j);
    }
    else
    {
        res = max();
    }
    return dp[i][j] = res;
}

memset(dp, -1, sizeof(dp));



int heap[MAX_N], sz = 0;

void push(int x)
{
    int i = sz++;

    while(i>0)
    {
        //親のノード番号
        int p = (i-1)/2;

        //もう逆転していないなら抜ける
        if(heap[p] <= x) break;

    }
}

//実際にはSTLにヒープは実装されている
#include <queue>
priority_queue<int> pque;

int L,P,N;
int A[MAX_N+1], B[MAX_N+1];

void solve()
{
    A[N] = L;
    B[N] = 0;
    N++;

    priority_queue<int> que;
    int ans=0; pos=0; tank=p;
    rep(i,N)
    {
        int d = A[i] - pos;

        while(tank - d < 0)
        {
            if(que.empty())

        }
    }
}


priority_queue<int, vector<int>, qreater<int>> que;


const int ST_SIZE = (1 << 15) - 1;

int N,C;
int L[MAX_N];
int S[MAX_C], A[MAX_N];

//セグメント木のデータ
double vx[ST_SIZE], vy[ST_SIZE];
double ang[ST_SIZE];

//現在の角度
double prv[MAX_N];

//STを初期化
//kは節点の番号, l,rはその節点がl,r区間に対応することを示す
void init(int k, int l, int r)
{
    ang[k] = vx[k] = 0.0;

    if(r-l == 1)
    {
        //11    kjhgfdsaiuytrewq    @poiuytrewq 葉
        vy[k] = L[l];
    }
    else
    {
        //葉ではない節点
        int chl = k * 2 + 1, chr = k * 2 + 2;
        init(chl, 1, (1+r) / 2);
    }

}

void solve()
{
    init(0,0,N);
}

LL N, X[1009], Y[1009], H[1009]; vector<tuple<LL,LL,LL>>vec;

int main()
{
    cin >> N; tuple<LL,LL,LL>G = make_tuple(-1,-1,-1);
    FOR(i, 1, N + 1)
    {
        cin >> X[i] >> Y[i] >> H[i];
        if(H[i] >= 1) G = make_tuple(X[i], Y[i], H[i]);
    }
    REP(i, 101)
    {
        REP(j, 101)
        {
            LL V = get<2>(G) + abs(get<0>(G) - i) + abs()
        }
    }
}


