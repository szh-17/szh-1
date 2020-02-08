
#include<stdio.h>
#include<string.h>
int num(char* s);//������תΪ����
int change(char* s);//����������ת��Ϊ����
char *extract(char* a, char* b);//��ȡ��ʮ����ǰ�������
char chinese[11][3] = { "��","һ","��","��","��","��","��","��","��","��","ʮ" };
int main()
{
    char s[10];
    char sp[10];
    int i,caibu;
    scanf("%s", s);
    if (strcmp(s, "����") == 0)
    {
        scanf("%s", s);
        strcpy(sp, s);
        for (i = 0; i < 2; i++)
            scanf("%s", s);
        caibu = num(s);
        scanf("%s", s);
        while (strcmp(s, sp) == 0)
        {
            scanf("%s", s);
            if (strcmp(s, "����") == 0)
            {
                scanf("%s", s);
                caibu += num(s);
            }
            else if (strcmp(s, "����") == 0)
            {
                scanf("%s", s);
                caibu -= num(s);
            }
            scanf("%s", s);
        }
        scanf("%s", s);
        if (caibu <= 10)
            printf("%s", chinese[caibu]);
        else if (caibu > 10 && caibu < 20)
            printf("ʮ%s", chinese[caibu - 10]);
        else if (caibu % 10 == 0)
            printf("%sʮ", chinese[caibu / 10]);
        else
            printf("%sʮ%s", chinese[caibu / 10], chinese[caibu % 10]);
    }
    else
        printf("error");
    return 0;
}
int num(char* s)
{
    int i,j;
    int n;
    char buffer[5] = "";
    if (strlen(s) == 2)//����0-9�ĺ���
    {
        j=change(s);
    }
    else if (strlen(s) == 4)//����10-19�Լ�ʮ�ı����ĺ���
    {
        strcpy(buffer,extract(buffer, s));
        if (strcmp(buffer, "ʮ") == 0)//����10-19�ĺ���
        {
            j = 10 + change(extract(buffer,s+2));
        }
        else//����ʮ�ı���
        {
            j = change(buffer) * 10;
        }
    }
    else//����ʮ���ĺ���
    {
        j = change(extract(buffer, s)) * 10 + change(extract(buffer, s + 4));
    }
    return j;
}
int change(char* s)
{
    int i;
    for (i = 0; i < 11; i++)
    {
        if (strcmp(s, chinese[i]) == 0)
            return i;
    }
}
char *extract(char* a, char* b)
{
    a[0] = b[0];
    a[1] = b[1];
    return a;
}
