#include <bits/stdc++.h>

using namespace std;

const int N = 100500;

int n;
char ans[N];

void print(int cnt, char x) {
	while (cnt--) printf("%c", x);
}

void fail() {
	puts("Impossible");
}

void makeAns(int pos, int g, int b, int bl) {
    int til = (bl - 2) / 2;
	for (int i = 0; i < til; i++) {
				ans[pos] = 'G';    
    			pos += 2;
    			pos %= n;
    			ans[pos] = 'G';
    			pos += 2;
    			pos %= n;
    			ans[pos] = 'B';    
    			pos += 2;
    			pos %= n;
    			ans[pos] = 'B';
    			pos += 2;
    			pos %= n;
    }
    for (int i = 0; i < g - til + 1; i++) {
    	ans[pos] = 'G';
    	pos += 2;
    	pos %= n;
    }		
    for (int i = 0; i < b - til + 1; i++) {
    	ans[pos] = 'B';
    	pos += 2;
    	pos %= n;
    }
}

int main() {
    freopen("boysgirls.in","r",stdin);
    freopen("boysgirls.out","w",stdout);
    int x, y;
    scanf("%d%d%d", &n, &x, &y);
    int gg = n - x;
    int bb = n - y;
    int bg = x + y - n;
    if (!(gg >= 0 && bb >= 0 && bg >= 0)) {
    	puts("Impossible");
    	return 0;
    }

    if (bb + bb >= bg && 2 * gg >= bg && bg % 2 == 0) {
    	if (n % 2 == 1) {
    		int til = (bg - 2) / 2;
    		int pos = 0;
    		for (int i = 1; i <= til; i++) {
    			ans[pos] = 'G';    
    			pos += 2;
    			pos %= n;
    			ans[pos] = 'G';
    			pos += 2;
    			pos %= n;
    			ans[pos] = 'B';    
    			pos += 2;
    			pos %= n;
    			ans[pos] = 'B';
    			pos += 2;
    			pos %= n;
    		}
    		int retg = gg - til;
    		for (int i = 0; i <= retg; i++) {
    			ans[pos] = 'G';
    			pos += 2;
    			pos %= n;
    		}
    		int retb = bb - til;
    		for (int i = 0; i <= retb; i++) {
    			ans[pos] = 'B';
    			pos += 2;
    			pos %= n;
    		}
    		for (int i = 0; i < n; i++) {
    			printf("%c", ans[i]);
    		}
    		puts("");
    		return 0;
    	} else {
    		if (bg == 0) {
    			if (gg == n) {
    				print(n, 'G');
    				puts("");
    				return 0;
    			}
    			if (bb == n) {
    				print(n, 'B');
    				puts("");
    				return 0;
    			}
    			if (bb == gg) {
    				for (int i = 0; i < n / 2; i++) printf("BG");
    				puts("");
    				return 0;
    			}
    			fail();
    			return 0;
    		} else {
    			if (bg == 2) {
    				if (gg >= n / 2) {
    					for (int i = 0; i < n; i += 2) ans[i] = 'G';
    					int pos = 1;
    					for (int i = 0; i <= bb; i++) {
    						ans[pos] = 'B';
    						pos += 2;
    						pos %= n;      
    					}
    					while (pos < n) {
    						ans[pos] = 'G';
    						pos += 2;
    					}
    					for (int i = 0; i < n; i++) printf("%c", ans[i]);
    					puts("");
    					return 0;
    				}
    				if (bb >= n / 2) {
    					for (int i = 0; i < n; i += 2) ans[i] = 'B';
    					int pos = 1;
    					for (int i = 0; i <= gg; i++) {
    						ans[pos] = 'G';
    						pos += 2;
    						pos %= n;      
    					}
    					while (pos < n) {
    						ans[pos] = 'B';
    						pos += 2;
    					}	
    					for (int i = 0; i < n; i++) printf("%c", ans[i]);
    					puts("");
    					return 0;
    				}
    				fail();
    				return 0;
    			}
    			bool feil = true;
    			if (gg > n / 2 && (gg - n / 2) * 2 >= bg) {
    				for (int i = 0; i < n /2 ; i++) {
    					ans[2 * i] = 'G';
    					
    				}
    				makeAns(1, gg - n / 2, bb, bg);
    				for (int i = 0; i < n; i++) printf("%c", ans[i]);
    				puts("");
    				return 0;
    			}
    			if (bb > n / 2 && (bb - n / 2) * 2 >= bg) {
    				for (int i = 0; i < n /2 ; i++) {
    					ans[2 * i] = 'B';
    					
    				}
    				makeAns(1, gg, bb - n / 2, bg);
    				for (int i = 0; i < n; i++) printf("%c", ans[i]);
    				puts("");
    				return 0;
    			}	
    			for (int k = 2; k < bg / 2; k += 2) {
    				if (2 * k <= n / 2 && 2 * (bg - k) <= n / 2) {
    					feil = false;
                       	int b1 = k / 2;
                       	int g1 = k / 2;
                       	int b2 = (bg - k) / 2;
                       	int g2 = (bg - k) / 2;
                       	int ans1 = b1 + g1 + k;
                       	int ans2 = b2 + g2 + bg - k;
                       	while (bb - b1 - b2 > 0 && ans1 < n / 2) {
                       		++ans1;
                       		++b1;
                       	} 
                       	while (gg - g1 - g2 > 0 && ans1 < n/ 2) {
                       		++ans1;
                       		++g1;
                       	}
                       	g2 += (gg - g1 - g2);
                       	b2 += (bb - b1 - b2);
                       	makeAns(1, b1, g1, k);
                       	makeAns(0, b2, g2, bg - k);
                       	for (int j = 0; j < n; j++) printf("%c", ans[j]);
                       	return 0;
                       	break;
    				}                    
    			} 	
    			if (feil) {
    				fail();
    				return 0;
    			}    		
    		}
    	}	
    } else {
    	fail();
    	return 0;
    }
    /*if (bb == 0) {
   		if (bg == 0) {
   			print(n, 'G');
   			return 0;
   		} else {
   			fail();
   			return 0;
   		}
    }
    if (gg == 0) {
    	if (bg == 0) {
    		print(n, 'B');
    		return 0;
    	} else {
    		fail();
    		return 0;
    	}
    }

    if (bg % 2 == 0 && bg >= 2) {
    	print(gg + 1, 'G');
    	print(bb + 1, 'B');
    	int rem = (bg - 2) / 2;
    	for (int i = 0; i < rem; i++) printf("GB");
    	return 0;	
    }   else {
    	fail();
    	return 0;
    }*/
	return 0;
}