#include "my.h"

USER* input(){
    USER* userinfo=(USER*)malloc(sizeof(USER));
    printf("请输入姓名: ");
    scanf("%s",&userinfo->name);
    printf("请输入家庭电话: ");
    scanf("%s",&userinfo->htel);
    printf("请输入手机号: ");
    scanf("%s",&userinfo->tel);
    while (getchar()!='\n');
    return userinfo;
}

int save(USER* userinfo){
    fp=NULL;
    fp=fopen(FILENAME,"w+");
    if(fp==NULL){
        printf("can not open file user.dat!\n");
        return -1;
    }
    int ret=fprintf(fp,"%d    %s    %s    %s\n",userinfo->id,userinfo->name,userinfo->htel,userinfo->tel);
    fclose(fp);
    if (ret!=sizeof(USER))
    {
        return -1;
    }
    return 0;
}

int saveAll(UList* head){
    UList *iter=head->next;
    fp=NULL;
    fp=fopen(FILENAME,"w");
    if (fp==NULL)
    {
        printf("opne file fail\n");
        return -1;
    }
    while (iter)
    {
        fprintf(fp,"%d    %s    %s    %s\n",iter->user->id,iter->user->name,iter->user->htel,iter->user->tel);
        iter=iter->next;
    }
    fclose(fp);
    return 0;
}

UList* read(){
    fp=NULL;
    total=0;
    fp=fopen(FILENAME,"r+");
    UList* head=(UList*)malloc(sizeof(UList));
    UList* userList=head;
    if(fp==NULL){
        printf("can not open file user.dat!\n");
        return head;
    }
    while (!feof(fp))
    {
        UList* userListTemp=(UList*)malloc(sizeof(UList));
        USER*temp=(USER*)malloc(sizeof(USER));
        fscanf(fp,"%d    %s    %s    %s\n",&(temp->id),&(temp->name),&(temp->htel),&(temp->tel));
        userListTemp->user=temp;
        userListTemp->next=NULL;
        userList->next=userListTemp;
        userList=userList->next;
        total++;
    }
    fclose(fp);
    return head;
}

int addToList(USER* user,UList* head){
    if (head->next==NULL)
    {
            UList* back=(UList*)malloc(sizeof(UList));
            back->user=user;
            head->next=back;
            back->next=NULL;
            return 0;
    }
    UList* iter=head->next;
    
    while (iter)
    {
        if (iter->next!=NULL&&(iter->next->user->id-iter->user->id>1))
        {
            UList*temp=iter->next;
            UList* back=(UList*)malloc(sizeof(UList));
            back->user=user;
            iter->next=back;
            back->next=temp;
            break;
        }
        else if (iter->next==NULL)
        {
            UList* back=(UList*)malloc(sizeof(UList));
            back->user=user;
            iter->next=back;
            back->next=NULL;
            break;
        }
        iter=iter->next;
    }
    total++;
    return 0;
}

int removeById(UList* head,int id){
    
    UList*iter=head;
    int flag=0;
    while (iter->next)
    {
        if (iter->next->user->id==id)
        {
            if (iter->next->next!=NULL)
            {
                realloc(iter->next->user,sizeof(UList));
                realloc(iter->next,sizeof(UList));
                iter->next=iter->next->next;
            }else
            {
                iter->next=NULL;
            }
            flag=1;
            break;
        }
        iter=iter->next;
    }
    if (!flag)
    {
        return -1;
    }
    return 0;
}

int giveId(UList* head){
    if (head->next==NULL||head->next->user->id!=1)
    {
        return 1;
    }
    UList* iter=head->next;
    while (iter->next)
    {
        if (iter->next->user->id-iter->user->id>1)
        {
            break;
        }
        iter=iter->next;
    }
    return iter->user->id+1;
}

int output(UList* users){
    UList* iter=users->next;
    printf("    id        name          htel           tel\n");
    while (iter)
    {
        printf("    %d         %s           %s         %s\n",iter->user->id,iter->user->name,iter->user->htel,iter->user->tel);
        iter=iter->next;
    }
    return 0;
}


//实现快速排序算法
UList* getEnd(UList *head){
    UList *iter=head;
    while (iter->next)
    {
        iter=iter->next;
    }
    return iter;
}

void swap(USER*a,USER*b)
{
    USER* temp=a;
    a=b;
    b=temp;
}
//定位
UList *partion(UList *pbegin ,UList * pend,int type)
{
    if(pbegin ==pend ||pbegin->next ==pend)
           return pbegin;
    int mykey = pbegin ->user->name[0]; //选择基准
    UList * p =pbegin ; 
    UList* q =pbegin;

    int* pVal;
    int* qVal;

    if (type==SORTBYID)
    {
        pVal=p->user->id;
        qVal=q->user->id;
    }else
    {
        pVal=p->user->name[0];
        qVal=q->user->name[0];
    }
    while(q != pend)
    {
        if(*qVal< mykey )
        {
            p = p->next;
              swap( p->user,q->user); //小于则交换
        }
        q =q ->next;//否则一直往下走
    }
    swap( p->user,q->user); //定位
    return p;
}
void quick_sort(UList *pbegin,UList *pend,int type)
{
    if(pbegin ==pend ||pbegin->next ==pend)
    
        return ;
    UList *mid =partion(pbegin,pend,type);
    quick_sort(pbegin,mid,type);
    quick_sort(mid->next,pend,type);
}
 
UList *mysort(UList *head,UList *end,int type)
{    
    //如果头结点为空，则直接跳出循环
    if(head ==NULL ||head -> next==NULL);
       return head;
    quick_sort(head->next,end,type);
    return head;
}

UList* copyOne(UList *head){
    UList* iter=head->next;
    UList* res=(UList*)malloc(sizeof(UList));
    res->user=NULL;
    UList* rIter=res;
    while (iter)
    {
        UList* temp=(UList*)malloc(sizeof(UList));
        USER* userTemp=(USER*)malloc(sizeof(USER));
        memcpy(userTemp,iter->user,sizeof(USER));
        temp->user=userTemp;
        rIter->next=temp;
        temp->next=NULL;
        rIter=rIter->next;
        iter=iter->next;
    }
    return res;
}

USER* randData(){
    USER *
}