#include<stdio.h>
#include<string.h>
#include<jansson.h>
int main()
{
	int choice;
	char fname[100],lname[100];
	FILE *fp=fopen("data2.json","w");
	json_t *root=json_object();
	json_t *array=json_array();
	do
	{
		json_t *data=json_object();
		json_t *named=NULL;
		printf("Enter First name:");
		fflush(stdin);
		fgets(fname,100,stdin);
		char *pos;
		pos=strchr(fname,'\n');
		*pos='\0';
		printf("Enter Last name:");
		fflush(stdin);
		fgets(lname,100,stdin);
		pos=strchr(lname,'\n');
		*pos='\0';
		named=json_string(fname);
		json_object_set_new(data,"firstname",named);
		named=json_string(lname);
		json_object_set_new(data,"lastname",named);
		
		json_array_append(array,data);		
		
		printf("Enter Your Choice(1/0):");
		scanf("%d",&choice);
		getchar();
	}while(choice==1);
	json_object_set_new(root,"employee",array);
	json_dumpf(root,fp,JSON_INDENT(4));
	printf("File Saved Successfully\n");
	fclose(fp);
}
