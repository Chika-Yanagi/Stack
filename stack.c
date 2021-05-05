#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_BUF_SIZE 1024

#define QUEUESIZE 128
typedef char elementtype;

typedef struct {
  int front, rear;
  elementtype elements[QUEUESIZE];
} queue;

void initqueue(queue *q)
{
     q->front = q->rear = 0;
}

int queueempty(queue *q)
{
  return q->front == q->rear;
}

void printqueue(queue *q)
{
  int  i; 
  printf("[%c",q->elements[q->front]);
     for(i=q->front+1;i <=q->rear - 1; i++){
        printf(", %c",q->elements[i]);
      }
     printf("]\n");
}

void putq(queue *q, elementtype x)
{
   q->elements[q->rear] = x;
   q->rear++;
   if(q->rear >= QUEUESIZE){
       q->rear=0;
    } 
}

elementtype getq(queue *q)
{
  elementtype x;
  if(queueempty(q)) { return 0; }
  else{
    x=q->elements[q->front];
    q->front++;
    if(q->front >= QUEUESIZE){
       q->front=0;
     } 
    return x;
  }
}

void test(void)
{
  elementtype x;
  queue q;
  char buf[MAX_BUF_SIZE], str[MAX_BUF_SIZE];
  int n = 0;

  initqueue(&q);

  while(fgets(buf, MAX_BUF_SIZE, stdin) != NULL){
    if (strncmp(buf, "putq ", 5) == 0){
      // putq
      x = buf[5]; // 6文字目が要素
      putq(&q, x);
      continue;
    }
    if (strncmp(buf, "getq", 4) == 0){
      // getq
      x = getq(&q);
      str[n] = x;
      n++;
      continue;
    }
    printf("Unknown command.\n");
  }

  printqueue(&q);

  for(int i = 0; i < n; i++){
    printf("%c", str[i]);
  }
  printf("\n");
}

int main(void)
{
  test();

  return 0;
}
