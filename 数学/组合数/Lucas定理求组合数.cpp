//若p是质数，则对于任意整数 1 <= m <= n，有：
//    C(n, m) = C(n % p, m % p) * C(n / p, m / p) (mod p)

int qmi(int a, int k, int p) // 快速幂模板
{
  int res = 1 % p;
  while (k) {
    if (k & 1)
      res = (LL)res * a % p;
    a = (LL)a * a % p;
    k >>= 1;
  }
  return res;
}

int C(int a, int b, int p) // 通过定理求组合数C(a, b)
{
  if (a < b)
    return 0;

  LL x = 1, y = 1; // x是分子，y是分母
  for (int i = a, j = 1; j <= b; i--, j++) {
    x = (LL)x * i % p;
    y = (LL)y * j % p;
  }

  return x * (LL)qmi(y, p - 2, p) % p;
}

int lucas(LL a, LL b, int p) {
  if (a < p && b < p)
    return C(a, b, p);
  return (LL)C(a % p, b % p, p) * lucas(a / p, b / p, p) % p;
}
