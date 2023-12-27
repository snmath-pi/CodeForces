#include<bits/stdc++.h>
using namespace std;


/// REMEMEBER THSI NOTE VERY IMPORTANT 111
/// THIS TREE IS BASED ON 0 INDEXING OKAY
/// THE ONLY THING IS THAT IT DOES ALL THE WORK FOR A QUERY CONSIDERING IT FOR 
/// L, R - 1 (AFTER THE QUERY IS MADE 0 INDEXED)
/// SO TO GET THE ANSWER JUST DON'T MAKE RIGHT BOUNDARY OF QUERY 0 INDEXED
/// ONLY ALTER LEFT BOUNDARY
// TYPE 1 sum and minimums
struct segtree {
	vector<long long> tree;
	int n;
	segtree(int x) {
		for(n = 1; n < x; n *= 2) {}
		tree.resize(2*n);
	}	
	void build(vector<int> &a, int x, int lx, int rx) {
		if(rx-lx==1) {
			if(lx < (int) a.size()) {
				tree[x] = a[lx];
			}
			return;
		}
		int m = lx + rx >> 1;
		build(a, 2*x + 1, lx, m);
		build(a, 2*x + 2, m, rx);
		tree[x] = min(tree[2*x+1], tree[2*x+2]);
	}
	void build(vector<int> &a) {
		build(a, 0, 0, n);
	}
	void set(int i, int v, int x, int lx, int rx) {
		if(rx - lx == 1) tree[x] = v;
		else {
			int m = lx + rx >> 1;
			if(i < m) {
				set(i, v, 2*x + 1, lx, m);
			} else {
				set(i, v, 2*x + 2, m, rx);
			}
			tree[x] = min(tree[2*x+1], tree[2*x+2]);
		}
	}
	void set(int i, int v) {
		set(i, v, 0, 0, n);
	}
	long long sum(int x, int l, int r, int lx, int rx) {
		if(lx >= r || rx <= l) return 0;
		if(lx>=l && rx<=r) return tree[x];
		int m = lx + rx >> 1;
		return sum(2*x+1, l, r, lx, m) + sum(2*x+2, l, r, m, rx);
	}
	long long sum(int x, int l, int r) {
		return sum(x, l, r, 0, n);
	}
	int min_e(int x, int l, int r, int lx, int rx) {
		if(lx >= r || rx <= l) return 2e9;
		if(lx>=l && rx<=r) return tree[x];
		int m = lx + rx >> 1;
		return min(min_e(2*x+1, l, r, lx,m), min_e(2*x+2, l, r, m, rx));
	}
   	int min_e(int l, int r) {
		return min_e(0, l, r, 0, n);
	}
};



//TYPE 2 USED TO FIND MINIMUM ELEMENT PLUS ITS COUNT


struct segtree {
	vector<pair<int, int>> tree;
	int n;
	segtree(int x) {
		for(n = 1; n < x; n *= 2) {}
		tree.resize(2*n);
	}	

	pair<int, int> func(pair<int, int> x, pair<int, int> y) {
		if(x.first < y.first) {
			return x;
		}
		else if(x.first > y.first) return y;
		return {x.first, x.second + y.second};
	}
	void build(vector<int> &a, int x, int lx, int rx) {
		if(rx-lx==1) {
			if(lx < (int) a.size()) {
				tree[x] = {a[lx], 1};
			}
			return;
		}
		int m = lx + rx >> 1;
		build(a, 2*x + 1, lx, m);
		build(a, 2*x + 2, m, rx);
		tree[x] = func(tree[2*x+1], tree[2*x+2]);
	}
	void build(vector<int> &a) {
		build(a, 0, 0, n);
	}
	void set(int i, int v, int x, int lx, int rx) {
		if(rx - lx == 1) tree[x] = {v, 1};
		else {
			int m = lx + rx >> 1;
			if(i < m) {
				set(i, v, 2*x + 1, lx, m);
			} else {
				set(i, v, 2*x + 2, m, rx);
			}
			tree[x] = func(tree[2*x+1], tree[2*x+2]);
		}
	}
	void set(int i, int v) {
		set(i, v, 0, 0, n);
	}
	pair<int, int> min_e(int x, int l, int r, int lx, int rx) {
		if(lx >= r || rx <= l) return {2e9,0};
		if(lx>=l && rx<=r) return tree[x];
		int m = lx + rx >> 1;
		return func(min_e(2*x+1, l, r, lx,m), min_e(2*x+2, l, r, m, rx));
	}
   	pair<int, int> min_e(int l, int r) {
		return min_e(0, l, r, 0, n);
	}
};


// TO FIND MAX SUM FOR ANY SUBSEGEEMENT AFTER CHANGES 

struct item {
	long long seg, pref, suf, sum;
};
struct seg {
	int n;
	vector<item> tree;
	
	item neutral_element = {0, 0, 0, 0};
	item merge(item a, item b) {
		return {
			max(a.seg, max(b.seg, (a.suf + b.pref))), 
			max(a.pref, a.sum+b.pref),
			max(b.suf, b.sum+a.suf),
			a.sum+b.sum
		};
	}
	item single(int v) {
		if(v > 0) {
			return {v, v, v, v};
		} 
		return {0, 0, 0, v};
	}
	seg(int x) {
		n = 1;
		for(; n < x; n <<= 1) {}
		tree.resize(n<<1);
	}
	void build(int x, int lx, int rx, vector<int> &a) {
		if(rx - lx == 1) {
			if(lx < (int) a.size()) {
				tree[x] = single(a[lx]);
			}
			return;
		}

		int m = lx + rx >> 1;
		build(2*x+1, lx, m, a);
		build(2*x+2, m, rx, a);
		tree[x] = merge(tree[2*x+1], tree[2*x+2]);
	}
	void build(vector<int> &a) {
		build(0, 0, n, a);
	}
	void set(int x, int lx, int rx, int i, int v) {
		if(rx - lx == 1) {
			tree[x] = single(v);
			return;
		}
		int m = lx + rx >> 1;
		if(i < m) {
			set(2*x+1, lx, m, i, v);
		} else {
			set(2*x+2, m, rx, i, v);
		}

		tree[x] = merge(tree[2*x+1], tree[2*x+2]);
	}
	void set(int i, int v) {
		set(0, 0, n, i, v);
	}
	
	item mx(int x, int l, int r, int lx, int rx) {
		if(lx>=r||rx<=l) return neutral_element;
		if(lx>=l&&rx<=r) return tree[x];
		int m = lx + rx>>1;
		return merge(mx(2*x+1, l, r, lx, m), mx(2*x+2, l, r, m, rx));
	}
	item mx(int l, int r) {
		return mx(0,l, r, 0,n);
	}
};



// Finding the KthOne


typedef int item;
struct seg {
    int n;
    vector<item> tree;
    
    item neutral_element = 0;

    seg(int x) {
        n = 1;
        for(; n < x; n <<= 1) {}
        tree.resize(n<<1);
    }

    item merge(item a, item b) {
        return a+b;
    }
    item single(int v) {
        return v;
    }

    void build(int x, int lx, int rx, vector<int> &a) {
        if(rx - lx == 1) {
            if(lx < (int) a.size()) {
                tree[x] = single(a[lx]);
            }
            return;
        }

        int m = lx + rx >> 1;
        build(2*x+1, lx, m, a);
        build(2*x+2, m, rx, a);
        tree[x] = merge(tree[2*x+1], tree[2*x+2]);
    }
    void build(vector<int> &a) {
        build(0, 0, n, a);
    }
    void set(int x, int lx, int rx, int i, int v) {
        if(rx - lx == 1) {
            tree[x] = single(v);
            return;
        }
        int m = lx + rx >> 1;
        if(i < m) {
            set(2*x+1, lx, m, i, v);
        } else {
            set(2*x+2, m, rx, i, v);
        }

        tree[x] = merge(tree[2*x+1], tree[2*x+2]);
    }
    void set(int i, int v) {
        set(0, 0, n, i, v);
    }

    int find(int k, int x, int lx, int rx) {
        if(rx-lx==1) {
            return lx;
        }
        int m = lx + rx >> 1;
        int ii = tree[2*x+1];
        if(k < ii) {
            return find(k, 2*x+1, lx, m);
        } 
        return find(k-ii, 2*x+2, m, rx);
    }
    int find(int k) {
        return find(k, 0, 0, n);
    }
};
rep(i, m) {
    int t; cin >> t;
    if(t==1) {
        int j; cin >> j;
        a[j]^=1;
        st.set(j, a[j]);
    } else {
        int k; cin >> k;
        cout << st.find(k) << nl;
    }
}



// FIRST ELEMENT >= X WITH CHANGES 

typedef int item;
struct seg {
    int n;
    vector<item> tree;
    
    item neutral_element = INT_MIN;

    seg(int x) {
        n = 1;
        for(; n < x; n <<= 1) {}
        tree.resize(n<<1);
    }

    item merge(item a, item b) {
        return max(a, b);
    }
    item single(int v) {
        return v;
    }

    void build(int x, int lx, int rx, vector<int> &a) {
        if(rx - lx == 1) {
            if(lx < (int) a.size()) {
                tree[x] = single(a[lx]);
            }
            return;
        }

        int m = lx + rx >> 1;
        build(2*x+1, lx, m, a);
        build(2*x+2, m, rx, a);
        tree[x] = merge(tree[2*x+1], tree[2*x+2]);
    }
    void build(vector<int> &a) {
        build(0, 0, n, a);
    }
    void set(int x, int lx, int rx, int i, int v) {
        if(rx - lx == 1) {
            tree[x] = single(v);
            return;
        }
        int m = lx + rx >> 1;
        if(i < m) {
            set(2*x+1, lx, m, i, v);
        } else {
            set(2*x+2, m, rx, i, v);
        }

        tree[x] = merge(tree[2*x+1], tree[2*x+2]);
    }
    void set(int i, int v) {
        return set(0, 0, n, i, v);
    }
    int first_above(int x, int lx, int rx, int v) {
        if(tree[x] < v) return -1;
        if(rx-lx==1) return lx;
        int m = lx + rx >> 1;
        int res = first_above(2*x+1, lx, m, v);
        if(res == -1) {
            res = first_above(2*x+2, m, rx, v);
        }
        return res;
    }
    int first_above(int v) {
        return first_above(0, 0, n, v);
    }
};



// TYPE LEFTMOST ELEMENT >= X WITH LEFT BOUNDARY CONDITION


typedef int item;
struct seg {
    int n;
    vector<item> tree;
    
    item neutral_element = INT_MIN;

    seg(int x) {
        n = 1;
        for(; n < x; n <<= 1) {}
        tree.resize(n<<1);
    }

    item merge(item a, item b) {
        return max(a, b);
    }
    item single(int v) {
        return v;
    }

    void build(int x, int lx, int rx, vector<int> &a) {
        if(rx - lx == 1) {
            if(lx < (int) a.size()) {
                tree[x] = single(a[lx]);
            }
            return;
        }

        int m = lx + rx >> 1;
        build(2*x+1, lx, m, a);
        build(2*x+2, m, rx, a);
        tree[x] = merge(tree[2*x+1], tree[2*x+2]);
    }
    void build(vector<int> &a) {
        build(0, 0, n, a);
    }
    void set(int x, int lx, int rx, int i, int v) {
        if(rx - lx == 1) {
            tree[x] = single(v);
            return;
        }
        int m = lx + rx >> 1;
        if(i < m) {
            set(2*x+1, lx, m, i, v);
        } else {
            set(2*x+2, m, rx, i, v);
        }

        tree[x] = merge(tree[2*x+1], tree[2*x+2]);
    }
    void set(int i, int v) {
        return set(0, 0, n, i, v);
    }
    int first_above(int x, int lx, int rx, int l, int v) {
        if(tree[x] < v || rx <= l) return -1;
        if(rx-lx==1) return lx;
        int m = lx + rx >> 1;
        int res = first_above(2*x+1, lx, m, l, v);
        if(res == -1) {
            res = first_above(2*x+2, m, rx, l, v);
        }
        return res;
    }
    int first_above(int l, int v) {
        return first_above(0, 0, n, l, v);
    }
};


// TYPE FINDING NORMAL INVERSIONS 

typedef ll item;
struct seg {
    int n;
    vector<item> tree;
    
    item neutral_element = 0;

    seg(int x) {
        n = 1;
        for(; n < x; n <<= 1) {}
        tree.resize(n<<1);
    }

    item merge(item a, item b) {
        return a+b;
    }
    item single(int v) {
        return v;
    }

    void build(int x, int lx, int rx, vector<int> &a) {
        if(rx - lx == 1) {
            if(lx < (int) a.size()) {
                tree[x] = single(a[lx]);
            }
            return;
        }

        int m = lx + rx >> 1;
        build(2*x+1, lx, m, a);
        build(2*x+2, m, rx, a);
        tree[x] = merge(tree[2*x+1], tree[2*x+2]);
    }
    void build(vector<int> &a) {
        build(0, 0, n, a);
    }
    void set(int x, int lx, int rx, int i, int v) {
        if(rx - lx == 1) {
            tree[x] = single(v);
            return;
        }
        int m = lx + rx >> 1;
        if(i < m) {
            set(2*x+1, lx, m, i, v);
        } else {
            set(2*x+2, m, rx, i, v);
        }

        tree[x] = merge(tree[2*x+1], tree[2*x+2]);
    }
    void set(int i, int v) {
        return set(0, 0, n, i, v);
    }
    long long sum(int x, int l, int r, int lx, int rx) {
        if(lx >= r || rx <= l) return 0;
        if(lx>=l && rx<=r) return tree[x];
        int m = lx + rx >> 1;
        return sum(2*x+1, l, r, lx, m) + sum(2*x+2, l, r, m, rx);
    }
    long long sum(int x, int l, int r) {
        return sum(x, l, r, 0, n);
    }
};

cin >> n;
seg st(n);
vi b(n);
debug(b)
st.build(b);
rep(i, n) {
    int x; cin >> x; // element of the array
    cout << st.sum(0, x, n) << sp;
    st.set(x-1, 1);

    debug(st.tree);
}


