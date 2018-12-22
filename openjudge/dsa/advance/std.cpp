//32ms
#include <cstdio>
#include <algorithm>
using namespace std;

int const SIZE = 20005;
//分隔符，多串连接时需要用到，第0个为结束符，肯定用到
char const DELIMETER[] = {'#'};
int const DELIMETER_CNT = 1;
//字母表的字母个数
int const ALPHA_SIZE = DELIMETER_CNT + 26;
//char转int
inline int tr(char ch){
    if ( DELIMETER[0] == ch ) return 0;
    return ch - 'a' + 1;
}
//辅助宏，以下划线开头
#define _F(x) ((x)/3+((x)%3==1?0:tb))
#define _G(x) ((x)<tb?(x)*3+1:((x)-tb)*3+2)
//辅助数组，以下划线开头
int _wa[SIZE],_wb[SIZE],_wv[SIZE],_ws[SIZE];
//辅助函数
int _c0(int const r[],int a,int b){
    return r[a] == r[b]
        && r[a+1] == r[b+1]
        && r[a+2] == r[b+2];
}
int _c12(int k,int *r,int a,int b){
    if( 2 == k ) return r[a]<r[b] || ( r[a]==r[b]&&_c12(1,r,a+1,b+1) );
    return r[a]<r[b] || ( r[a]==r[b]&&_wv[a+1]<_wv[b+1] );
}
void _sort(int const r[],int *a,int *b,int n,int m){
    int i;
    for(i=0;i<n;i++) _wv[i] = r[a[i]];
    for(i=0;i<m;i++) _ws[i] = 0;
    for(i=0;i<n;i++) _ws[_wv[i]]++;
    for(i=1;i<m;i++) _ws[i] += _ws[i-1];
    for(i=n-1;i>=0;i--) b[--_ws[_wv[i]]] = a[i];
    return;
}
//后缀数组的dc3算法，使用此dc3算法一定要保证r与sa的最大长度不小于3倍原长度
//r: 源数组，且除r[n-1]外，其余r[i]>0
//n: r的长度
//m: r中的元素取值的上界，即任意r[i]<m
//sa:后缀数组，即结果
void dc3(int r[],int n,int m,int sa[]){
    int i,j,*rn=r+n,*san=sa+n,ta=0,tb=(n+1)/3,tbc=0,p;
    r[n] = r[n+1] = 0;
    for(i=0;i<n;i++) if(i%3!=0) _wa[tbc++]=i;
    _sort(r+2,_wa,_wb,tbc,m);
    _sort(r+1,_wb,_wa,tbc,m);
    _sort(r,_wa,_wb,tbc,m);
    for(p=1,rn[_F(_wb[0])]=0,i=1;i<tbc;i++)
        rn[_F(_wb[i])] = _c0(r,_wb[i-1],_wb[i])?p-1:p++;
    if(p<tbc) dc3(rn,tbc,p,san);
    else for(i=0;i<tbc;i++) san[rn[i]]=i;
    for(i=0;i<tbc;i++) if(san[i]<tb) _wb[ta++] = san[i]*3;
    if(n%3==1) _wb[ta++]=n-1;
    _sort(r,_wb,_wa,ta,m);
    for(i=0;i<tbc;i++) _wv[_wb[i] = _G(san[i])] = i;
    for(i=0,j=0,p=0;i<ta&&j<tbc;p++)
        sa[p] = _c12(_wb[j]%3,r,_wa[i],_wb[j]) ? _wa[i++] : _wb[j++];
    for(;i<ta;p++) sa[p] = _wa[i++];
    for(;j<tbc;p++) sa[p] = _wb[j++];
    return;
}
//计算rank数组与height数组
//r:  源数组
//sa: 后缀数组
//n:  源数组的长度
//rank: rank数组，即计算结果
//height: height数组，即计算结果
void calHeight(int const r[],int const sa[],int n,int rank[],int height[]){
    int i,j,k=0;
    for(i=1;i<n;i++) rank[sa[i]]=i;
    for(i=0;i<n-1;height[rank[i++]]=k)
    for(k?k--:0,j=sa[rank[i]-1];r[i+k]==r[j+k];k++);
    return;
}

void dispArray(int const a[],int n){
    for(int i=0;i<n;++i)printf("%d ",a[i]);
    printf("\n");
}


int R[SIZE*3],SA[SIZE*3];//3倍！！！
int Rank[SIZE],Height[SIZE];
int N,K;
int A[SIZE];
int Idx[1000005];
bool read(){
    if ( EOF == scanf("%d%d",&N,&K) ) return false;
    //输入的可能取值为1000000，做一个离散化可以到20000
    for(int i=0;i<N;++i)scanf("%d",A+i),R[i]=A[i];
    sort(A,A+N);
    int n = unique(A,A+N) - A;
    for(int i=0;i<n;++i)Idx[A[i]] = i + 1;
    for(int i=0;i<N;++i) R[i] = Idx[R[i]];
    R[N++] = 0;
    return true;
}
//判断n值是否满足条件
//Height数组中至少连续K-1个值不小于v
bool check(int v){
    int i = 1;
    while( i < N ){
        while( i < N && Height[i] < v ) ++i;
        int k = 0;
        while( i + k < N && Height[i+k] >= v && k < K - 1 ) ++k;
        if( K - 1 == k ) return true;
        i += k + 1;
    }
    return false;
}
int proc(){
    dc3(R,N,N+2,SA);
    calHeight(R,SA,N,Rank,Height);

    /*
    dispArray(R,N);
    dispArray(SA,N);
    dispArray(Rank,N);
    dispArray(Height,N);
    //*/
    //二分法查找至少重复了k次的子串的最长长度，可重迭
    int left = 0;//答案至少是0
    int right = N - K;//答案至多是N-k
    do{
        int mid = ( left + right ) >> 1;
        if ( check(mid) ) left = mid + 1;
        else right = mid - 1;
    }while( left <= right );
    return right;
}

int main(){
    while( read() )printf("%d\n",proc());
    return 0;
}

