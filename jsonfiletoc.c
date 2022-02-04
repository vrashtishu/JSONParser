#include<stdio.h>
#include<jansson.h>
int main()
{
	FILE *fp=fopen("data.json","r");
	size_t index;
	json_t *value;
	json_t *root=json_loadf(fp,0,NULL);
	json_t *array=json_object_get(root,"employee");
	
	size_t arraysize=json_array_size(array);
	printf("\nThis Files Contains %d Employees Data\n",arraysize);
	json_array_foreach(array,index,value)
	{
		json_t *firstname=json_object_get(value,"firstname");
		json_t *lastname=json_object_get(value,"lastname");
		const char *fname=json_string_value(firstname);
		const char *lname=json_string_value(lastname);
		printf("firstname:%s  lastname:%s\n",fname,lname);
		
	}
	printf("\n");
	fclose(fp);
	
}
