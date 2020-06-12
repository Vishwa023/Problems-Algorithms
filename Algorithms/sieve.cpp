const ll N = 1e5+5;
ll prime[N];
void sieve()
{
	memset(prime,0,sizeof(prime));
	for(ll i = 2; i*i <= N; i++)
	{
		if(!prime[i])
		{
			for(ll j=i*i;j<=N;j+=i)
				prime[j] = 1;
		}
	}
}