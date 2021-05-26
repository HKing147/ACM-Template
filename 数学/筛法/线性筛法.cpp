int primes[N], cnt; // primes[]存储所有素数
bool st[N];         // st[x]存储x是否被筛掉

void get_primes(int n) {
  for (int i = 2; i <= n; i++) {
    if (!st[i])
      primes[cnt++] = i;
    for (int j = 0; primes[j] <= n / i; j++) {
      st[primes[j] * i] = true;
      if (i % primes[j] == 0)
        break;
    }
  }
}
