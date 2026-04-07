#include<stdio.h>
#include<stdlib.h>

struct node{
    int page;
    int count;
    struct node *prev;
    struct node *next;
};
struct node *haq1=NULL;
struct node *haq0=NULL;
struct node *caq1=NULL;
struct node *caq0=NULL;
int hisize=0, casize=0;
struct node* page[20001];
int in[20001];
int k, n, m;

struct node* create_node(int page){
    struct node* p=(struct node*)malloc(sizeof(struct node));
    p->page=page;
    p->count=1;
    p->prev=NULL;
    p->next=NULL;
    return p;
}

void hismov(struct node* p){
    if(p->prev){
        p->prev->next=p->next;
    }else{
        haq1=p->next;
    }
    if(p->next){
        p->next->prev=p->prev;
    }else{
        haq0=p->prev;
    }
    p->prev=p->next=NULL;
    hisize--;
}

void hisadd(struct node* p){
    p->prev=haq0;
    p->next=NULL;
    if(haq0){
        haq0->next=p;
    }else{
        haq1=p;
    }
    haq0=p; 
    hisize++;
    in[p->page]=1;
}

void cacmov(struct node* p){
    if(p->prev){
        p->prev->next=p->next;
    }else{
        caq1=p->next;
    }
    if(p->next){
        p->next->prev=p->prev;
    }else{
        caq0=p->prev;
    }
    p->prev=p->next=NULL;
    casize--;
}

void cacadd(struct node* p){
    p->prev=caq0;
    p->next=NULL;
    if(caq0){
        caq0->next=p;
    }else{
        caq1=p;
    }
    caq0=p;
    casize++;
    in[p->page]=2;
}

void hisout(){
    if(!haq1){
        return;
    }
    struct node* p=haq1;
    hismov(p);
    page[p->page]=NULL;
    in[p->page]=0;
    free(p);
}

void cacout(){
    if(!caq1){
        return;
    }
    struct node* p=caq1;
    cacmov(p);
    page[p->page]=NULL;
    in[p->page]=0;
    free(p);
}

int main(){
    scanf("%d %d %d", &k, &n, &m);
    for(int i=0; i<m; i++){
        int x;
        scanf("%d", &x);
        if(in[x]==2){
            struct node* p=page[x];
            cacmov(p);
            cacadd(p);
        }else if(in[x]==1){
            struct node* p=page[x];
            hismov(p);
            p->count++;
            if(p->count==k){
                if(casize==n){
                    cacout();
                }
                cacadd(p);
            }else{
                hisadd(p);
            }

        }else{
            if(hisize==n){
                hisout();
            }
            struct node* p=create_node(x);
            page[x]=p;
            hisadd(p);
            in[x]=1;
        }
    }
    if(!haq1){
        printf("-\n");
    }else{
        struct node *cur = haq1;
        printf("%d", cur->page);
        while((cur=cur->next)!=NULL)
            printf(" %d", cur->page);
        printf("\n");
    }

    if(!caq1){
        printf("-\n");
    }else{
        struct node *cur = caq1;
        printf("%d", cur->page);
        while((cur=cur->next)!=NULL)
            printf(" %d", cur->page);
        printf("\n");
    }

    while(haq1){
        struct node* p=haq1;
        haq1=haq1->next;
        free(p);
    }

    while(caq1){
        struct node* p=caq1;
        caq1=caq1->next;
        free(p);
    }

    return 0;

}