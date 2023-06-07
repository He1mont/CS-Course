# include <stdio.h>
# include <string.h>
int main()
{
    // Declare the file pointer
    FILE *fp ;
    char dataToBeWritten[50];

    // Get the data to be written in file
    fgets(dataToBeWritten, 50, stdin);

    // Open the existing file test.txt using fopen()
    // in write mode using "w" attribute
    fp = fopen("./tmp/test.txt", "w") ;

    // Check if this filePointer is null
    // which maybe if the file does not exist
    if ( fp == NULL ){
        printf( "failed to open the file.\n" ) ;

    } else {
        // Write the dataToBeWritten into the file
        if ( strlen(dataToBeWritten) > 0 ){   
            fputs(dataToBeWritten, fp) ;    // writing in the file using fputs()
        }
        fclose(fp) ;        // Closing the file using fclose()
    }
    return 0;
}
