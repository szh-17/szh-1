#include<stdio.h>
#include<string.h>

char chinese1[100][100] = {"��", "һ", "��", "��", "��", "��", "��", "��", "��", "��", "ʮ"};
int q1(char a[]) {
    int i;
    for (i = 0; i < 11; i++) {if (strcmp(chinese1[i], a) == 0)    return i;  
    }
    return 0;
}
char chinese2[100][100] = {"��", "һ", "��", "��", "��", "��", "��", "��", "��", "��", "ʮ"};
int q2(char a[]) {
    int i;
    for (i = 0; i < 11; i++) {if (strcmp(chinese2[i], a) == 0)     return i;
        
    }
    return 0;
}
int compare1(char a[], char b[], char c[]) {
    int x;
    x = q1(a);
    if (strcmp(a, "����") == 0) printf("%s", b);
    else if (strcmp(a, "С��") == 0) 
	printf("%s", c);
}

int compare2(int n, char a[], char b[]) {
    int sum;
    sum = q1(b);
    if (strcmp(a, "����") == 0)
        return n + sum;
    if (strcmp(a, "����") == 0)
        return n - sum;
    
}
int main() {
    int out1, out2;
    char a[100], b[100], c[100], d[100], e[100], f[100], g[100], h[100], j[100], k[100];
    scanf("%s %s %s %s %s %s %s %s %s %s %s", a, b, c, d, a, g, c, h, b, j, k);
    out1 = q1(d);
    out2 = q2(h);
    scanf("%s %s", f, g);
    while (scanf("%s %s", f, g) != EOF)
	 {
    	
        if (strcmp(g, "����") != 0) 
		{
            scanf("%s", k);
            out1 = compare2(out1, j, k);
		
            if (out1 > q1(d))
               
			    printf("%s", chinese2[out2 +1]);
			}

    }
}
