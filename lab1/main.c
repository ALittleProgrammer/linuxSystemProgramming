#include "my.h"


int main(){
    char choice='0';
    USER *user;
    int id;
    UList* list=read();
    UList *end;
    UList *sList=copyOne(list);
    int flag;
    while (choice!='6')
    {
        printf("*****1.添加联系人*****\n");
        printf("*****2.删除联系人*****\n");
        printf("*****3.联系人按id排序*****\n");
        printf("*****4.联系人按姓名排序*****\n");
        printf("*****5.显示所有联系人*\n");
        printf("*****6.退出**********\n");
        scanf("%c",&choice);
        //清除多余字符
        while (getchar()!='\n');
        switch (choice)
        {
        case '1':
            user=input();
            user->id=giveId(list);
            addToList(user,list);
            if(saveAll(list)==0){
                printf("\n联系人添加成功！\n");
            }
            list=read();
            break;
        case '2':
            printf("\n请输入要删除的联系人id: ");
            scanf("%d",&id);
            while (getchar()!='\n');
            if(removeById(list,id)!=0){
                printf("\n删除失败！没有此联系人！\n");
                break;
            }
            printf("\n删除成功！\n");
            saveAll(list);
            break;
        case '3':
            flag=0;
            break;
        case '4':
            flag=1;
            sList=copyOne(list);
            end=getEnd(sList);
            sList=mysort(sList,end,SORTBYID);
            break;
        case '5':
            if (flag)
            {
                output(sList);
            }else
            {
                output(list);
            }
            break;
        default:
            break;
        }
    }
}