
#include<cstdio>
#include<cmath>
#include<fstream>
#include<iostream>
using namespace std;
#define ll long long
using namespace std;
const int maxn = 100001;   // 表长
ll int prime[maxn], pNum = 0;    // prime记录素数，pNum记录素数个数 
bool p[maxn] = { false };        // p记录当前数是否被筛去
#define ten(x) ((x<<1)+(x<<3))
#define Fsize 1000000
#define tc() (A==B&&(B=(A=Fin)+fread(Fin,1,Fsize,stdin),A==B)?EOF:*A++)
#define pc(ch) (FoutSize<Fsize?Fout[FoutSize++]=ch:(fwrite(Fout,1,Fsize,stdout),Fout[(FoutSize=0)++]=ch))
int Top, FoutSize; char ch, * A, * B, Fin[Fsize], Fout[Fsize], Stack[Fsize];
#define inline __inline__ __attribute__((always_inline))
inline void write(register long long x) { if (!x) return (void)(pc('0')); if (x < 0) pc('-'), x = -x; while (x) Stack[++Top] = x % 10 + 48, x /= 10; while (Top) pc(Stack[Top--]); }
	inline void write_char(char x) { pc(x); }
	inline void clear() { fwrite(Fout, 1, FoutSize, stdout); }
	inline void read(register long long& x) { x = 0; while (!isdigit(ch = tc())); while (x = ten(x) + (ch & 15), isdigit(ch = tc())); }

#define Run 1

int main()
{
	srand(time(NULL));
	long long T;
	//scanf("%lld", &T);
	read(T);
	if (T > 10000) {


		for (int i = 2; i < 100000; i++)
		{
			if (!p[i])  // 如果未被筛过，则为素数
				prime[++pNum] = i;
			for (int j = 1; j < pNum; ++j)
			{
				if (i * prime[j] > 100000)      // 当要标记的合数超出范围时跳出
					break;
				p[i * prime[j]] = true;     // 将已经记录的素数的倍数进行标记
				if (!(i % prime[j]))      //关键步骤
					break;
			}
		}
		while (T--) {
			long long t;
			read(t);
			register long long ans = 1;
			register long long tt = t * t;

			for (register ll i = 1; i <= pNum; ++i) {
				register ll h = prime[i];
				if (!(tt % h)) {
					register ll temp = 0;
					while (!(tt % h))
						tt /= h, ++temp;
					ans *= (temp + 1);
				}
			}
			if (tt < 2)ans >>= 1;
#if Run
			write(ans);
			write_char('\n');
#else
			fout << ans << endl;
#endif
		}
		clear();

		return 0;
	}
	while (T--) {
		long long t;
		read(t);
		register long long ans = 1;
		register long long tt = t * t;

		for (register ll i = 2; i < t; ++i) {
			if (!(tt % i)) {
				register ll temp = 0;
				while (!(tt % i))
					tt /= i, ++temp;
				ans *= (temp + 1);
			}
		}
		if (tt < 2)ans >>= 1;
#if Run
		write(ans);
		write_char('\n');
#else
		fout << ans << endl;
#endif
	}
	clear();
return 0;
}
