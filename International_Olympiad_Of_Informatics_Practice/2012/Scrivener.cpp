//IOI 2012 Scrivener https://contest.yandex.ru/ioi/contest/572/problems/C/
#pragma GCC optimize("O2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include "grader.h"
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef long long ll;
#define pb push_back
#define eb emplace_back
#define countbits __builtin_popcount
#define beg0 __builtin_clz
#define terminal0 __builtin_ctz
#define mod 1e9+7
int N;
struct node{
	char letter;
	int level;
	node* parent[20];
	node(char letter, node *par):letter(letter){
		parent[0]=par;
		if (par!=NULL) level = par->level + 1; else level = 0;
		for (int i=1;i<20;i++){
			if (parent[i-1]==NULL) parent[i]=NULL;
			else parent[i]=parent[i-1]->parent[i-1];
		}
	}
};
node* Commands[(int)1e6+5];
node* curr;
void Init(){
	curr=new node(0,NULL);
	Commands[1]=curr;N=1;
}
void TypeLetter(char a){
	Commands[++N] = new node(a, curr);
    curr = Commands[N];
}
void UndoCommands(int n){
	int s = N-n;
	Commands[++N]=Commands[s];
	curr=Commands[N];
}
char GetLetter(int p){
	p++;
	node *s = curr; int L = curr->level-p;
	for (int i=0;(1<<i)<=L;i++){
		if (L&(1<<i)){
			s=s->parent[i];
		}
	}
	return s->letter;
}