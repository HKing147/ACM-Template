//首先预处理出所有阶乘取模的余数fact[N]，以及所有阶乘取模的逆元infact[N]
//如果取模的数是质数，可以用费马小定理求逆元
int qmi(int a, int k, int p) // 快速幂模板
{
  int res = 1;
  while (k) {
    if (k & 1)
      res = (LL)res * a % p;
    a = (LL)a * a % p;
    k >>= 1;
  }
  return res;
}

// 预处理阶乘的余数和阶乘逆元的余数
fact[0] = infact[0] = 1;
for (int i = 1; i < N; i++) {
  fact[i] = (LL)fact[i - 1] * i % mod;
  infact[i] = (LL)infact[i - 1] * qmi(i, mod - 2, mod) % mod;
}
