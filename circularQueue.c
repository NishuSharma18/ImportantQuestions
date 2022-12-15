#include<stdio.h>
#include<stdlib.h> 
#include<string.h> 

// struct circularQueue{
//     int size;
//     int f;
//     int r;
//     int * arr;
// };

// int isEmpty(struct circularQueue * q){
//     if(q->r == q->f)
//         return 1;
// return 0;    
// }

// int isFull(struct circularQueue *q){
//     // if(q->r == q->size -1) return 1;
//     if((q->r+1)%(q->size) == q->f) return 1;
// return 0;    
// }

// void enq(struct circularQueue *q,int val){
//     if(isFull(q)){
//     printf("Queue is full\n");
//     return;
//     }

// // q->r++;
// q->r = (q->r +1)%(q->size); 
// q->arr[q->r]= val;
// }


// int deq(struct circularQueue *q){
//     int a =-1;
//     if(isEmpty(q)){
//         printf("Queue is Empty\n");
//     }
//     else{
// //   q->f++;
//   q->f = (q->f+1)%(q->size);
//     a = q->arr[q->f];
//     }
// return a;
// }


// ::::::::::::::::::::::
//  Stack implementation
struct stack {
    int size;
    int top;
    char* arr;
};

char Top(struct stack* st){
    return st->arr[st->top];
}

int isEmpty(struct stack* st){
    if(st->top==-1) return 1; 
return 0;
}

int isFull(struct stack* st){
    if(st->top == st->size -1) return 1;
return 0;
}

void push(struct stack* st,char val){
    if(isFull(st)){
    printf("Stack Overflow\n");
    return ;
    }

    st->top++;
    st->arr[st->top] = val;
}

char pop(struct stack* st){
    if(isEmpty(st)){
    printf("Stack Underflow\n");
    return -1;
    }

    char val = st->arr[st->top];
    st->top--;
    return val;
}

int precedence(char x){
   if(x=='*' || x=='/') return 3;
   if(x=='+' || x=='-') return 2;
   return 0;
}

int isOpr(char x){
    if(x=='*' || x=='/'||x=='+' || x=='-') return 1;
    return 0;
}

 char * infixToPostfix(char* infix){
    struct stack* st = (struct stack*)malloc(sizeof(struct stack));
    st->size = 10;
    st->top = -1;
    st->arr = (char*) malloc(st->size*sizeof(char)); 
 char* postfix = (char*) malloc((strlen(infix)+1)*sizeof(char));
int i=0,j=0;

while(infix[i]!='\0'){
    if(!isOpr(infix[i])){
        postfix[j] =infix[i];
        j++;
        i++;
    }
    else{
        if(precedence(infix[i]) >precedence(Top(st))){
            push(st,infix[i]);
            i++;
        }
        else{
          postfix[j] =pop(st);
          j++;  
        }
    }
}

while (!isEmpty(st)){
   postfix[j] = pop(st);
   j++; 
}

// asigning end of string
postfix[j] ='\0'; 

 return postfix;
 }

void reverse(struct stack* st){
    if(st->top ==-1) return ;
    char ele = pop(st);
    reverse(st);
    printf("%c", ele);
    push(st,ele);
}



int main(){
// struct circularQueue q;
// q.size =5;
// // q.f = q.r = -1;
// q.f = q.r = 0;
// q.arr = (int*) malloc(q.size*sizeof(int));

// enq(&q,2);
// enq(&q,5);
// enq(&q,11);
// enq(&q,19);

// printf("Dequeuing elements %d\n", deq(&q));
// printf("Dequeuing elements %d\n", deq(&q));
// enq(&q,29);

struct stack st;
st.size = 10;
st.top = -1;
struct stack st2;
st2.size = 10;
st2.top = -1;


st.arr = (char*) malloc(10*sizeof(char));
st2.arr = (char*) malloc(10*sizeof(char));
push(&st,'5');
push(&st,'8');
push(&st,'3');
// st.arr = "1-2+3/6";
char * infix = "1-2+3/6";
// char* postfix = infixToPostfix(infix);


reverse(&st);


// printf("%s", postfix);

return 0;
}