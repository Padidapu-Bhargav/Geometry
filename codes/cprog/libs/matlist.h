//Function declaration
typedef struct list
{
double data;
struct list *next;
}node;

node *linspace_pointer(double, double, int );
void  display(struct node *r);
void append(int num);
void add( int num );
int count();
int delete(int num);
void insert(int num);
void addafter(int num, int loc);
//End function declaration

/*

int main(void)
{
node *ap;
double a = -1.0, l = 1.0;
int n = 100;

//Getting the head of the AP list
ap = linspace_pointer(a,l,n);

//Printing the AP
while(ap->next != NULL)
{
	printf("%lf\n", ap->data);
	ap = ap->next; 
}

return 0;
}
*/

node *linspace_pointer(double a, double l, int n)
{
//Variable declarations
node *ap, *head;
double d;
int i;

//Common difference
d = (l-a)/(n-1);

ap = (node *)malloc(sizeof(node));
head = ap;
//Generating the AP
for(i = 0; i < 100; i++)
{

ap->data = a+i*d;
//Creating memory for next node
ap->next = (node *)malloc(sizeof(node));
//Initializing next node	
ap->next->next = NULL;
//node increment
ap = ap->next;
}
//Returning the address of the first memory block
return head;

}

struct node
{
    int data;
    struct node *next;
}*head;
 
 
 
void append(int num)
{
    struct node *temp,*right;
    temp= (struct node *)malloc(sizeof(struct node));
    temp->data=num;
    right=(struct node *)head;
    while(right->next != NULL)
    right=right->next;
    right->next =temp;
    right=temp;
    right->next=NULL;
}
 
 
 
void add( int num )
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=num;
    if (head== NULL)
    {
    head=temp;
    head->next=NULL;
    }
    else
    {
    temp->next=head;
    head=temp;
    }
}
void addafter(int num, int loc)
{
    int i;
    struct node *temp,*left,*right;
    right=head;
    for(i=1;i<loc;i++)
    {
    left=right;
    right=right->next;
    }
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=num;
    left->next=temp;
    left=temp;
    left->next=right;
    return;
}
 
 
 
void insert(int num)
{
    int c=0;
    struct node *temp;
    temp=head;
    if(temp==NULL)
    {
    add(num);
    }
    else
    {
    while(temp!=NULL)
    {
        if(temp->data<num)
        c++;
        temp=temp->next;
    }
    if(c==0)
        add(num);
    else if(c<count())
        addafter(num,++c);
    else
        append(num);
    }
}
 
 
 
int delete(int num)
{
    struct node *temp, *prev;
    temp=head;
    while(temp!=NULL)
    {
    if(temp->data==num)
    {
        if(temp==head)
        {
        head=temp->next;
        free(temp);
        return 1;
        }
        else
        {
        prev->next=temp->next;
        free(temp);
        return 1;
        }
    }
    else
    {
        prev=temp;
        temp= temp->next;
    }
    }
    return 0;
}
 
 
void  display(struct node *r)
{
    r=head;
    if(r==NULL)
    {
    return;
    }
    while(r!=NULL)
    {
    printf("%d ",r->data);
    r=r->next;
    }
    printf("\n");
}
 
 
int count()
{
    struct node *n;
    int c=0;
    n=head;
    while(n!=NULL)
    {
    n=n->next;
    c++;
    }
    return c;
}
 