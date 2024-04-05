ll power(ll a, ll b){if(b==0) return 1;if(b&1) return a*power(a, b-1);ll ret = power(a, b/2);return ret*ret;}
ll expo(ll a, ll b, ll m){if(b == 0) return 1ll;ll ret = expo(a, b/2, m);ret = (ret%m * ret%m)%m;if(b%2) ret = (ret*a)%m;return ret;}
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}


struct Hashing{
    string s;
    ll n;
    ll primes;
    ll base = 31;
    vector<ll> hashPrimes = {10007, 10009};
    vector<vector<ll>> hashValues;
    vector<vector<ll>> powersOfBase;
    vector<vector<ll>> inversePowerOfBase;

    Hashing(string a){
        primes = hashPrimes.size();
        hashValues.resize(primes);
        powersOfBase.resize(primes);
        inversePowerOfBase.resize(primes);
        s = a;
        n = s.size();

        for(int i=0;i<primes;i++){
            powersOfBase[i].resize(n+1);
            powersOfBase[i][0] = 1;
            for(int j=1;j<=n;j++){
                powersOfBase[i][j] = (powersOfBase[i][j-1]*base)%hashPrimes[i];
            }
            inversePowerOfBase[i].resize(n+1);
            inversePowerOfBase[i][n] = expo(powersOfBase[i][n], hashPrimes[i]-2, hashPrimes[i]);
            for(int j=n-1;j>=0;j--){
                inversePowerOfBase[i][j] = (inversePowerOfBase[i][j+1]*base)%hashPrimes[i];
            }
        }
        for(int i=0;i<primes;i++){
            hashValues[i].resize(n);
            for(int j=0;j<n;j++){
                hashValues[i][j] = (j==0 ? 0 : hashValues[i][j-1]);
                hashValues[i][j] = (hashValues[i][j] + (s[j]-'a'+1)*powersOfBase[i][j])%hashPrimes[i];
            }
        }
    }
    void addCharacter(char c){
        n++;
        s += c;
        for(int i=0;i<primes;i++){
            while(powersOfBase[i].size() < n){
                powersOfBase[i].push_back((powersOfBase[i].back()*base)%hashPrimes[i]);
                inversePowerOfBase[i].push_back((inversePowerOfBase[i].back()*expo(base, hashPrimes[i]-2, hashPrimes[i]))%hashPrimes[i]);
            }
        }
        for(int i=0;i<primes;i++){
            while(hashValues[i].size() < n){
                if(hashValues[i].empty()){
                    hashValues[i].push_back((c-'a'+1)%hashPrimes[i]);
                }
                hashValues[i].push_back((hashValues[i].back() + (c-'a'+1)*powersOfBase[i][n-1])%hashPrimes[i]);
            }
        }
    }
    vector<ll> substringHash(int l, int r){
        vector<ll> res;
        for(int i=0;i<primes;i++){
            ll hashValue = hashValues[i][r];
            if(l > 0){
                hashValue = (hashValue - hashValues[i][l-1] + hashPrimes[i])%hashPrimes[i];
            }
            hashValue = (hashValue*inversePowerOfBase[i][l])%hashPrimes[i];
            res.push_back(hashValue);
        }
        return res;
    }
    bool compareSubstrings(int l1, int r1, int l2, int r2){
        if(r1-l1 != r2-l2){
            return false;
        }
        vector<ll> hash1 = substringHash(l1, r1);
        vector<ll> hash2 = substringHash(l2, r2);
        return hash1 == hash2;
    }
    vector<vector<ll>> samelengthSubstringHashes(int l){
        vector<vector<ll>> res;
        for(int i=0;i<primes;i++){
            vector<ll> hh;
            ll prevHash = 0;
            ll constant_multiply = inversePowerOfBase[i][1];
            for(int j=0;j<l;j++){
                prevHash = ((prevHash + ((s[j]-'a'+1)*powersOfBase[i][j])%hashPrimes[i]))%hashPrimes[i];
            }
            hh.push_back(prevHash);
            for(int j=l;j<n;j++){
                prevHash = mod_sub(prevHash, s[j-l]-'a'+1, hashPrimes[i]);
                prevHash = (prevHash*constant_multiply)%hashPrimes[i];
                prevHash = (prevHash + ((s[j]-'a'+1)*powersOfBase[i][l-1])%hashPrimes[i])%hashPrimes[i];
                hh.push_back(prevHash);
            }
            res.push_back(hh);
        }
        return res;
    }
};
