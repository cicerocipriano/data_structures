
//Exemplo de analise de complexidade:
//Note que simplificamos ao máximo na notacao O (removendo o n, ja que O(n^2 +n) = O(n^2), pois a parte quadratica "pesa mais")
//Complexidade: O(n^2 + m + n) = O(n^2 + m)
void funcao1(int n, int m) {
	for(int i=0;i<n;i++) 
		for(int j=0;j<n;j++)
			ct *= j;
	
	for(int k=0;k<m;k++) 
		ct += 10;

	for(int k=0;k<n;k++) 
		ct += 10;
}


//Complexidade: O(n^3 + 2n^2 + m) = O(n^3 + m)
void funcao2(int n, int m) {
	for(int i=0;i<n;i++) 
		for(int j=0;j<n;j++)
			ct *= j;
	
	for(int k=0;k<m;k++) 
		funcao1(30,40);

	for(int k=0;k<n;k++) 
		funcao1(n,200);
}

//Complexidade: O(nk + m/100000) = O(nk + m)
void funcao3(int n, int m, int k) {
	for(int i=0;i<n;i++) 
		for(int j=0;j<k;j++)
			ct *= m;

	for(int i=0;i<m/100000;i++) {
		ct += k;
	}
}

//Complexidade: O(n^2)
void funcao4(int n, int m, int k, int v[]) {
	int ct = 0;
	for(int i=0;i<n;i++) {
		if(v[i]%2==0) break;
		for(int j=0;j<n;j++) {
			ct += v[i] + v[j];
		}
	}
}

//Complexidade: O(n/2) = O(n)
void funcao5(int n, int m, int k, int v[]) {
	int ct = 0;
	for(int i=0;i<n;i++) {		
		for(int j=0;j<n;j++) {
			ct++;
			if(ct%2==0) break;
		}
	}
}

void funcao6(int n, int m, int k, int v[]) {
	int ct = 0;
	for(int i=0;i<n;i++) {		
		for(int j=0;j<n;j++) {
			ct+= log(n);
		}
	}
}

//Complexidade: O((n^2 - n) / 2) = O(n^2)
void funcao7(int n, int m, int k, int v[]) {
	int ct = 0;
	for(int i=1;i<n;i++) {		
		for(int j=i;j<n;j++) {
			ct+= log(n);
		}
	}
}

//Complexidade: O(n*log(m))
void funcao8(int n, int m, int k, int v[]) {
	int ct = 0;
	for(int i=0;i<n;i++) {		
		for(int j=0;j<log(m);j++) {
			ct += sin(k);
		}
	}
}

//Responda (alem de analisar a complexidade): o que essa funcao faz?
//Complexidade: O(log(n))
//Essa funcao descobre o logaritmo de n na base 10
void funcao9(int n) {
	if(n==0) return 0;
	return funcao9(n/10)+1;
}


//Complexidade: O(log(m) + log(n))
//essa funcao dsecobre o logaritmo de m e n na base 2
void funcao10(int n, int m, int k, int v[]) {
	if(n==0 && m==0) return 1;
	if(n==0) return funcao10(n,m/2,k,v);
	else return funcao10(n/2,m,k,v);
}

//Complexidade: O(n + s), onde s eh a soma dos elementos nao negativos do array v
void funcao11(int n, int m, int k, int v[]) {
	int ct = 0;
	for(int i=0;i<n;i++) {
		for(int j=0;j<v[i];j++) {
			ct += k;
		}
	}
}

//Complexidade: O((n-5) * (n-3) * 5) = O(n^2)
int funcao12(int n) {
    int ans = 0;
    for(int i=5;i<n;i++) 
		for(int j=3;j<n;j++) 
	          for(int k=1;k<n;k++) {
	             ans += 2;
	             if(ans%10==0) break;
	          }
     return ans;
}

//Complexidade: O(ufv)
double funcao13(int v,int u, int f) {
	double ans = 0;
	for(int i=0;i<u;i++) {
	   for(int j=0;j<v;j++) ans -= log(i*j);
	   ans += log(u+i);
	   for(int j2=0;j2<f/2;j2++)
	   	for(int k=v/2;k<v;k++)
	   		ans += log(j2*k); 
	}
	return ans;
}


//Analise a complexidade de melhor e pior caso dessa função
//Diga não apenas a complexidade, mas também explique quando esses tempos ocorrem
//Complexidade: O(1) (melhor caso, v[0] = m)
//Complexidade: O(n) (pior caso, m nao ta no array v)
void funcao14(int n, int m, int k, int v[]) {
	int ct = 0;
	for(int i=0;i<n;i++) {
		if(v[i]==m)
			return i;		
	}
	return -1;
}

//Analise a complexidade de melhor e pior caso dessa função
//Diga não apenas a complexidade, mas também explique quando esses tempos ocorrem
//Complexidade: O(n^2) (melhor caso acontece quando w eh divisivel por 2)
//Complexidade: O(n^3) (pior caso acontece quando w eh impar)
int funcao15(int n, int w) {
    int ans = w;
    for(int i=5;i<n;i++) 
		for(int j=3;j<n;j++) 
	          for(int k=1;k<n;k++) {
	             ans += 2;
	             if(ans%10==0) break;
	          }
     return ans;
}

//Complexidade: O(n^2 + n)
int funcao16(int n, int w) {
    double ans = w;
    for(int i=0;i<n;i++) 
    	for(int j=0;j<n;n--) 
    		for(int k=0;k<m;k++)
    			ans += 3.14;
    	
    
    return ans;
}
