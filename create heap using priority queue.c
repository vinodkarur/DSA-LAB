#include <stdio.h>
#include <stdlib.h>

void heapify(int a[10],int n){
int i,k,v,j,flag=0;
for(i=n/2;i>=1;i--){
    k=i;
    v=a[k];
    flag=0;
    while(!flag && (2*k)<=n){
        j=2*k;
        if(j<n && a[j]<a[j+1]){
            j++;
        }
        if(v>=a[j])
            flag=1;
        else{
            a[k]=a[j];
            k=j;
        }
    }
    a[k]=v;
}
}

int main()
{int n,i,a[10],ch;
for(;;){
    printf("\n1-creat heap\n2-extract max\n3-exit\n");
    printf("enter your choice:");
    scanf("%d",&ch);
    switch(ch){
    case 1:
        printf("\n enter number of elements:");
        scanf("%d",&n);
        printf("\n enter elements :\n");
        for(i=0;i<=n;i++)
            scanf("%d",&a[i]);
        heapify(a,n);
        printf("\n elements after heapification:\n");
        for(i=1;i<=n;i++)
            printf("%d\t",a[i]);
        break;
    case 2:
        if(n>=1){
            printf("\n element deleted:%d\n",a[1]);
            a[1]=a[n];
            n--;
            heapify(a,n);
            if(n!=0){
                printf("\n heap after deletion:\n");
                for(i=1;i<=n;i++)
                    printf("%d\t",a[i]);

            }
            else
                printf("\n no element to delete");
            break;
        }
    default :
        exit(0);
    }
}

    return 0;
}
