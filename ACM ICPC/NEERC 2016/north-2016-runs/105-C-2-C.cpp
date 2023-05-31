#include<stdio.h>
#include<iostream>
#include <algorithm>

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

bool comp(par &a, par&b){
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

	int left = n;
	while(rootcf->next != NULL){
		while(!a[0][rootcf->num].second && rootcf->next != NULL){
			rootcf = rootcf->next;
			left--;
		}
	
		if(rootcf->next == NULL)break;

		while(roottc->num != rootcf->num){
			a[1][roottc->num].second = left-1;
			a[0][roottc->num].second = 0;
			roottc = roottc->next;                       
		}
		a[1][rootcf->num].second = left-1;
		a[0][rootcf->num].second = 0;
		roottc = roottc->next;
	}

	if(a[0][rootcf->num].second)
		a[1][rootcf->num].second = 0;

	for(int i = 0; i < n; i++)
		cout << a[1][i].second << endl;
	
	return 0;
}
   						

