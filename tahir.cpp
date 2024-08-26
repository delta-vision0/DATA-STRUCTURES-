#include<stdio.h>

void readFile(const char *filename);
void insertion();
void deletion(int);
void search(int);
void traverse(int);
void saveFile(const char *filename);

struct product{
	int product_id;
	char product_name[30];
	float product_price;
	float gst;
};

struct product product_list[100];
int count=0;

int main()
{
	int choice,pos,id;
	readFile("product.txt");
	
	while(1)
	{
		printf("\n1.Add Product\n2.Delete Product\n3.Search\n4.Display List\n5.Save in File\n");
		printf("Enter choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				    insertion();
				    break;
			case 2:
				    printf("\nEnter position to delete:");
				    scanf("%d",&pos);
				    pos-=1;
				    deletion(pos);
				    break;
		    case 3:
		    	    printf("\nEnter product ID to search:");
				    scanf("%d",&id);
				    search(id);
				    break;
			case 4:
					traverse(count);
				    break;
			case 5:
					saveFile("product.txt");
					break;
			default :
					printf("Invalid Choice\n");		
		}
	}
}

void readFile(const char *filename)
{
	FILE *f1;
	f1=fopen("product.txt","r");
	if(f1==NULL)
	{
		printf("FIle not open\n");
	}
	for(count=0;count<100;count++)
	{
		if(fscanf(f1,"%d %s %f %f",&product_list[count].product_id,
									product_list[count].product_name,
		                        	&product_list[count].product_price,
									&product_list[count].gst)!=4)
		{
			break;
		} 
	}
	fclose(f1);
	printf("count=%d\n",count);
}

void insertion()
{
	if(count<100)
	{
	printf("\nEnter product ID   :");
	scanf("%d",&product_list[count].product_id);
	printf("Enter product Name :");
	scanf("%s",product_list[count].product_name);
	printf("Enter product Price:");
	scanf("%f",&product_list[count].product_price);
	printf("Enter product GST  :");
	scanf("%f",&product_list[count].gst);
	count++;
    }
	else
		printf("List is full\n");
}

void deletion(int pos)
{
	int i;
    if(count!=0)
    {
    	for(i=pos;i<count;i++)
    	{
    		product_list[i]=product_list[i+1];	
		}
		count--;
	}
	else
	    printf("List is empty\n");
}

void search(int id)
{
	int i;
	if(count!=0)
	{
		for(i=0;i<count;i++)
		{
			if(id==product_list[i].product_id)
			{
			 printf("Id= %d\nName= %s\nPrice= %f\ndGST= %f\n",product_list[i].product_id,product_list[i].product_name,
		                                                      product_list[i].product_price,product_list[i].gst);
			}
			else
				printf("List is empty\n");
		}
	}
}

void traverse(int count)
{
	int i;
	if(count>0)
	{
		for(i=0;i,i<count;i++)
		{
			printf("\nPRODUCT %d\n",i+1);
			printf("Id= %d\nName= %s\nPrice= %f\ndGST= %f\n",product_list[i].product_id,product_list[i].product_name,
		                                                      product_list[i].product_price,product_list[i].gst);
		}
	}
	else
		printf("\nList is Empty\n");
}

void saveFile(const char *filename)
{
	int i;
	FILE *f1;
	f1=fopen("product.txt","w");
	if(f1==NULL)
	{
		printf("FIle not open\n");
	}
	for(i=0;i<count;i++)
	{
	    fprintf(f1,"\n%d     %-10s     %-10.2f     %-10.2f",product_list[i].product_id,product_list[i].product_name,
		                        product_list[i].product_price,product_list[i].gst);
		
	}	
	fclose(f1);
	printf("\nData save in file successfully\n");
	printf("count=%d\n",count);
}




