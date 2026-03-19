#include <stdio.h>
int main() {
int a[2][2],b[2][2],c[2][2],d[2][2],e[2][2],f[2][2],g[2][2],i,j,k;
printf("Enter Elements of A: ");
for(i=0;i<2;i++){
    for(j=0;j<2;j++){
        scanf("%d",&a[i][j]);
    }
}
printf("Enter Elements of B: ");
for(i=0;i<2;i++){
    for(j=0;j<2;j++){
        scanf("%d",&b[i][j]);
    }
}
for(i=0;i<2;i++){
    for(j=0;j<2;j++){
        c[i][j]=a[i][j]+b[i][j];
    }
}
for(i=0;i<2;i++){
    for(j=0;j<2;j++){
        d[i][j]=a[i][j]-b[i][j];
    }
}
for(i=0;i<2;i++){
    for(j=0;j<2;j++){
        e[i][j]=a[j][i];
    }
}
for(i=0;i<2;i++){
    for(j=0;j<2;j++){
        f[i][j]=b[j][i];
    }
}
for(i=0;i<2;i++){
    for(j=0;j<2;j++){
        g[i][j]=0;
        for(k=0;k<2;k++){
            g[i][j]+=a[i][k]*b[k][j];
        }
    }
}
printf("Addition of both matrix:\n");
for(i=0;i<2;i++){
    for(j=0;j<2;j++){
        printf("%d",c[i][j]);
    }printf("\n");
}
printf("Subtraction of both matrix:\n");
for(i=0;i<2;i++){
    for(j=0;j<2;j++){
        printf("%d",d[i][j]);
    }printf("\n");
}
printf("Transpose of A:\n");
for(i=0;i<2;i++){
    for(j=0;j<2;j++){
        printf("%d",e[i][j]);
    }printf("\n");
}
printf("Transpose of B:\n");
for(i=0;i<2;i++){
    for(j=0;j<2;j++){
        printf("%d",f[i][j]);
    }printf("\n");
}
printf("Multiplication of both matrix:\n");
for(i=0;i<2;i++){
    for(j=0;j<2;j++){
        printf("%d",g[i][j]);
    }printf("\n");
}
    return 0;
}
