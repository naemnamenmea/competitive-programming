#include<stdio.h>
#include<iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> par;


par a[2][100000];

struct node{
    int num;
    node *next;

    node(int n){
    	num = n;
    	next = NULL;
    }
};

bool comp(par &a, par &b){
	return a.second > b.second;
}

int main()
{
	freopen("codecoder.in","r",stdin);
	freopen("codecoder.out","w",stdout);
		
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[0][i].second >> a[1][i].second;
		a[0][i].first = i;
		a[1][i].first = i;
	}     

	sort(a[0], a[0] + n, comp);
	sort(a[1], a[1] + n, comp);
                                        
	node *rootcf = new node(a[0][0].first);
	node *roottc = new node(a[1][0].first);

	node *cur = rootcf;
	for(int i = 1; i < n; i++){
		cur->next = new node(a[0][i].first);
		cur = cur->next;
	}
	cur = roottc;
	for(int i = 1; i < n; i++){
		cur->next = new node(a[1][i].first);
		cur = cur->next;
	}

	memset(a, -1, sizeof(a));

	int fast = 0;
	int ans = 0;
	int left = n - 1;

	while(rootcf != NULL){

		a[0][rootcf->num].second = 0;
		a[1][rootcf->num].second = left;	
		ans = left;

		//if(roottc == NULL){cout << "roottc null"<<endl;return 0;}
		while(rootcf->num != roottc->num){
			a[0][roottc->num].second = 0;
			a[1][roottc->num].second = left;	
			fast++;
			roottc = roottc->next;
			//if(roottc == NULL){cout << "NULL"<< endl;return 0;}
		}

		roottc = roottc->next;

		while(fast){
		    if(rootcf->next == NULL){
		    	if(!a[0][rootcf->num].second){cout << "TF NULL"<<endl;return 0;}
		    	break;
		    		
		    }
			rootcf = rootcf->next;
			left--;
			if(a[1][rootcf->num].second == ans){
				fast--;
				continue;
			}
			a[0][rootcf->num].second = 0;
			a[1][rootcf->num].second = ans;
		}

		rootcf = rootcf->next;
		left--;

	}

	for(int i = 0; i < n; i++)
		cout << a[1][i].second << endl;
	
	return 0;
}
   						

