ll p(ll x,ll y)
{
    ll result = 1; 
    while (y) { 
        if (y & 1) 
            result = result * x; 
        y = y / 2; 
        x = x * x; 
    } 
    return result;
}