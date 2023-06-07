#include<stdio.h>
/* Our structure */
struct rec
{
    int x,y,z;
};

int main()
{
    int counter;
    FILE *fp;
    struct rec my_record;
    fp=fopen("./tmp/program.bin","rb");

    if (!fp){
        printf("Unable to open file!\n");
        return 1;
    }
    
    fseek(fp, sizeof(struct rec)*2, SEEK_SET);
    
    printf("%d\n", ftell(fp));
      
    fread(&my_record,sizeof(struct rec),1,fp);
    printf("%d\n",my_record.x);

    fseek(fp, sizeof(struct rec)*2, SEEK_CUR);

    printf("%d\n", ftell(fp));

    fread(&my_record,sizeof(struct rec),1,fp);
    printf("%d\n",my_record.x);

    fseek(fp, sizeof(struct rec), SEEK_END);

    printf("%d\n", ftell(fp));

    fread(&my_record,sizeof(struct rec),1,fp);
    printf("%d\n",my_record.x);

    rewind(fp);

    printf("%d\n", ftell(fp));

    fread(&my_record,sizeof(struct rec),1,fp);
    printf("%d\n",my_record.x);
  
    fclose(fp);
    return 0;
}
