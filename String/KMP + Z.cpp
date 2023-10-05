// border match
// a b c a b b c a a b c 
// 0 0 0 1 2 0 0 1 1 2 3
void buildPrefix(string s) {
    vector<int> prefix(s.size());
    int border = prefix[0] = 0;
    for (int i = 1; i < s.size(); ++i) {
        while (border > 0 && s[i] != s[border]) border = prefix[border - 1];
        if (s[i] == s[border])border++;
        prefix[i] = border;
    }
}

// prefix suffix match 
// a b c a b b c a a b c
// 0 0 0 2 0 0 0 1 3 0 0
void buildZ(string s) {
    vector<int> Z(s.size());
    int l = 0, r = 0;
    for (int i = 1; i < s.size(); ++i) {
        int k = i - l;
        if (i >= r || i + Z[k] >= r) {
            l = i;
            r = max(r, i);
            while (r < s.size() && s[r - l] == s[r])r++;
            Z[i] = r - l;
        } else
            Z[i] = Z[k];
    }
}