#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "list.h"

LIST_HEAD(fox_list);    //����ͷ

struct fox {
        unsigned int tail_length;
        unsigned int weight;
        struct list_head list;
};

int main(int ac, char *av[])
{  
    //��ʼ��ͷ���
    struct fox *bigfox; //ÿ������������ʱ���õ�ָ��
    struct list_head * pos; 
    struct fox *p;
    struct list_head *n;
    struct fox *q;
    int i;
    
    for (i=0; i < 10; i++) {
        bigfox = (struct fox *)malloc(sizeof(struct fox));
        bigfox->tail_length = i+1+20;
        bigfox->weight      = i+1;
        list_add_tail(&bigfox->list, &fox_list);
        //list_add(&bigfox->list, &fox_list);
        printf("Node %d has added to the list...\n", i+1);
    }
    
    //�������� ��һ
    // i = 0;
    // list_for_each(pos, &fox_list) {
        // p = list_entry(pos, struct fox, list);
        // printf("Node %d's data: %d,%d\n", i, p->tail_length, p->weight);
        // i++;
    // }
    
    //�������� ����
    i = 0;
    list_for_each_entry(p, &fox_list, list) {
        printf("Node %d's data: %d,%d\n", i, p->tail_length, p->weight);
        i++;
    }
    
    //�������� ����
    // i = 0;
    // list_for_each_entry_safe(p, q, &fox_list,list) {
        // printf("Node %d's data: %d,%d\n", i, p->tail_length, p->weight);
        // list_del(&p->list); //��������ɾ����ǰ���       
        // free(p); //�ͷŸ����ݽ����ռ�ռ�
        // printf("Node %d has removed from the doublelist...\n", i++);
    // }
    
    //Ϊ�˰�ȫɾ���������еı��� ��һ 
    i = 0;
    list_for_each_safe(pos, n, &fox_list) {
        list_del(pos); //��������ɾ����ǰ���
        p = list_entry(pos, struct fox, list); //�õ���ǰ���ݽ����׵�ַ����ָ��        
        free(p); //�ͷŸ����ݽ����ռ�ռ�
        printf("Node %d has removed from the doublelist...\n", i++);
    }
    
    //Ϊ�˰�ȫɾ���������еı��� ����
    // i = 0;
    // list_for_each_entry_safe(p, q, &fox_list,list) {
        // list_del(&p->list); //��������ɾ����ǰ���       
        // free(p); //�ͷŸ����ݽ����ռ�ռ�
        // printf("Node %d has removed from the doublelist...\n", i++);
    // }

    i = 0;
    list_for_each_entry(p, &fox_list, list) {
        printf("Node %d's data: %d,%d\n", i, p->tail_length, p->weight);
        i++;
    }
    
    i = list_empty(&fox_list);
    printf("Node is %d\n", i);//1Ϊ������

    return 0;
}