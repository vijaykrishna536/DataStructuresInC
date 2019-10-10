#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
int main()
{
    FILE * fp = fopen("abc.txt","w");
    fprintf(fp,"Sucessful creation");
    fclose(fp);
    FILE * fp = fopen("abc.txt","r");

    printf("Hello world!\n");
    return 0;
}

char* readline();
char** split_string(char*);

long arrayManipulation(int n, int queries_rows, int queries_columns, int** queries) {
int a=queries_rows+1,i,j,k,max=0,b=n;
int arr[a][b];
for(i=0;i<a;i++)
{
    for(j=0;j<b;j++)
    {
        arr[i][j]=0;
    }
}
for(k=0;k<queries_rows;k++)
{
    for(i=k+1;i<a;i++)
    {
        for(j=(queries[k][0])-1;j<(queries[k][1]);j++)
        {
            arr[i][j]+=queries[k][2];
        }

    }
}
for(i=1;i<a;i++)
{
    for(j=0;j<b;j++)
    {

        printf("%d \n",arr[i][j]);
    }
}


for(i=1;i<a;i++)
{
    for(j=0;j<b;j++)
    {
        if(arr[i][j]>max)
        {
            max=arr[i][j];
        }
    }
}
long maxx = max;
return maxx;
}
int main()
{
    int a[4][3]={{1,2,100},{2,5,100},{3,4,100}};
    long ab=arrayManipulation(5,4,3,a);
    printf("%l",ab);
    return 0;

}
char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);
        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}

/*
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {


    char c[1000];
    int i=0,arr[10];
    for(i=0;i<10;i++)
        arr[i]=0;
    scanf("%[^\n]%*c",&c);
    i=0;
    while(c[i]!='\0')
    {
        printf("%c",c[i]);
        switch (c[i])
        {
            case '1':
            arr[1]+=1;
            break;
            case '2':
            arr[2]+=1;
            break;
            case '3':
            arr[3]+=1;
            break;
            case '4':
            arr[4]+=1;
            break;
            case '5':
            arr[5]+=1;
            break;
            case '6':
            arr[6]+=1;
            break;
            case '7':
            arr[7]+=1;
            break;
            case '8':
            arr[8]+=1;
            break;
            case '9':
            arr[9]+=1;
            break;
            case '0':
            arr[0]+=1;
            break;
        }
        i++;
    }
    for(i=0;i<10;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}






#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <stdio.h>
#include <stdlib.h>
#define MAX_STRING_LENGTH 6

struct package
{
	char* id;
	int weight;
};

typedef struct package package;

struct post_office
{
	int min_weight;
	int max_weight;
	package* packages;
	int packages_count;
};

typedef struct post_office post_office;

struct town
{
	char* name;
	post_office* offices;
	int offices_count;
};

typedef struct town town;



void print_all_packages(town t) {
    int i=t.offices_count,j;
    printf("%s:\n", t.name);
    for(i=0;i<t.offices_count;i++)
    {
        if(t.offices->packages_count>0)
        {
            printf("\t%d:\n",i);
            for(j=0;j<t.offices[i].packages_count;j++)
            {
                printf("\t\t%s\n",t.offices[i].packages[j].id);
            }

        }

    }


}

void send_all_acceptable_packages(town* source, int source_office_index, town* target, int target_office_index) {
    int i,j,k;
    for(i=0;i<source.offices[source_office_index].packages_count;i++)
    {
        if((source->offices[source_office_index].packages[i].weight>target->offices           [target_office_index].min_weight)&&(source->offices[source_office_index].packages[i].weight>target->offices[target_office_index].max_weight))
        {
            target->offices[target_office_index].packages_count++;
            k=target->offices[target_office_index].packages_count;
            target->offices[target_office_index].packages[k]=source->offices[source_office_index].packages[i];
            for(j=0;j<source->offices[source_office_index].packages_count;j++)
            {
                source->offices[source_office_index].packages[j]=source->offices[source_office_index].packages[j+1];
            }
            source->offices[source_office_index].packages_count--;


        }
    }


}

town town_with_most_packages(town* towns, int towns_count) {
    town c;
    int i,count=0,j,k,sum;
    for(i=0;i<towns_count;i++)
    {
        sum=0;
        for(j=0;j<towns[i].offices_count;j++)
        {
            sum+=towns[i].offices[j].packages_count;
        }
        if(count<sum)
        {
            count = sum;
            c=towns[i];
        }
    }
    return c;
}

town* find_town(town* towns, int towns_count, char* name) {
    int i=0;

    for(i=0;i<towns_count;i++)
    {
        int j=0,f=0;
        char c=towns[i].name[j],s=name[j];
        while(c!='\0'&&s!='\0')
        {
            if(c!=s)
            {
                f++;
                break;
            }
            j++;
            c=towns[i].name[j];s=name[j];
        }
        if(f==0)
        {
            break;
        }


    }
    return &towns[i];
}

int main()
{
	int towns_count,i,j,k;
	scanf("%d", &towns_count);
	town* towns = malloc(sizeof(town)*towns_count);
	for ( i = 0; i < towns_count; i++) {
		towns[i].name = malloc(sizeof(char) * MAX_STRING_LENGTH);
		scanf("%s", towns[i].name);
		scanf("%d", &towns[i].offices_count);
		towns[i].offices = malloc(sizeof(post_office)*towns[i].offices_count);
		for ( j = 0; j < towns[i].offices_count; j++) {
			scanf("%d%d%d", &towns[i].offices[j].packages_count, &towns[i].offices[j].min_weight, &towns[i].offices[j].max_weight);
			towns[i].offices[j].packages = malloc(sizeof(package)*towns[i].offices[j].packages_count);
			for ( k = 0; k < towns[i].offices[j].packages_count; k++) {
				towns[i].offices[j].packages[k].id = malloc(sizeof(char) * MAX_STRING_LENGTH);
				scanf("%s", towns[i].offices[j].packages[k].id);
				scanf("%d", &towns[i].offices[j].packages[k].weight);
			}
		}
	}
	int queries;
	scanf("%d", &queries);
	char town_name[MAX_STRING_LENGTH];
	while (queries--) {
		int type;
		scanf("%d", &type);
		switch (type) {
		case 1:
			scanf("%s", town_name);
			town* t = find_town(towns, towns_count, town_name);
			print_all_packages(*t);
			break;
		case 2:
			scanf("%s", town_name);
			town* source = find_town(towns, towns_count, town_name);
			int source_index;
			scanf("%d", &source_index);
			scanf("%s", town_name);
			town* target = find_town(towns, towns_count, town_name);
			int target_index;
			scanf("%d", &target_index);
			send_all_acceptable_packages(source, source_index, target, target_index);
			break;
		case 3:
			printf("Town with the most number of packages is %s\n", town_with_most_packages(towns, towns_count).name);
			break;
		}
	}
	return 0;
}
*/
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char** split_string(char*);

// Complete the arrayManipulation function below.
long arrayManipulation(int n, int queries_rows, int queries_columns, int** queries) {
int a=queries_rows+1,i,j,k,b=n;
int arr[a][b],max=0;
for(i=0;i<a;i++)
{
    for(j=0;j<b;j++)
    {
        arr[i][j]=0;
    }
}
for(k=0;k<queries_rows;k++)
{
    for(i=k+1;i<a;i++)
    {
        for(j=(queries[k][0])-1;j<(queries[k][1]);j++)
        {
            arr[i][j]+=queries[k][2];
        }

    }
}
for(i=1;i<a;i++)
{
    for(j=0;j<b;j++)
    {
        printf("%d ",arr[i][j]);
    }
    printf("\n");
}
for(i=1;i<a;i++)
{
    for(j=0;j<b;j++)
    {
        if(arr[i][j]>max)
        {
            max=arr[i][j];
        }
    }
}
//long maxx = max;
return max;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char** nm = split_string(readline());

    char* n_endptr;
    char* n_str = nm[0];
    int n = strtol(n_str, &n_endptr, 10),i,j,k;

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

    char* m_endptr;
    char* m_str = nm[1];
    int m = strtol(m_str, &m_endptr, 10);

    if (m_endptr == m_str || *m_endptr != '\0') { exit(EXIT_FAILURE); }

    int** queries = malloc(m * sizeof(int*));

    for ( i = 0; i < m; i++) {
        *(queries + i) = malloc(3 * (sizeof(int)));

        char** queries_item_temp = split_string(readline());

        for (j = 0; j < 3; j++) {
            char* queries_item_endptr;
            char* queries_item_str = *(queries_item_temp + j);
            int queries_item = strtol(queries_item_str, &queries_item_endptr, 10);

            if (queries_item_endptr == queries_item_str || *queries_item_endptr != '\0') { exit(EXIT_FAILURE); }

            *(*(queries + i) + j) = queries_item;
        }
    }

    int queries_rows = m;
    int queries_columns = 3;

    long result = arrayManipulation(n, queries_rows, queries_columns, queries);

    fprintf(fptr, "%l\n", result);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);
        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}

