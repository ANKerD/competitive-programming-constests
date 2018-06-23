def ok(k):
    if k <= 0:
        return 0

    candy = n
    v = 0
    while candy>0:
        v += min(candy, k)
        candy -= min(candy, k);
        candy -= floor(candy*.1)

    return 2*v >= n;

n = int(raw_input())
ans = n

ll maxok = 1;
ll minnot = 100000000000000000LL;
// cout << 100000000000000000LL + 100000000000000000LL << '\n';
// cout << fixed << pow(2, 63) << '\n';

while(maxok <= minnot){
ll guess = (minnot + maxok)/2;
// cout << guess << ' ' << minnot << ' ' << maxok << '\n';
if(ok(guess)){
ans = min(ans, guess);
minnot = guess-1;
} else
maxok = guess+1;

}

if(ok(maxok+1))
ans = min(ans, maxok+1);
if(ok(maxok))
ans = min(ans, maxok);

if(ok(minnot))
ans = min(ans, minnot);
if(ok(minnot+1))
ans = min(ans, minnot+1);

cout << ans << '\n';

return 0;
}
