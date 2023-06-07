// C program to Open a File,
// Read from it, And Close the File
# include <stdio.h>
# include <string.h>

int main( )
{
    // Declare the file pointer
    FILE *filePointer;
    // Declare the variable for the data to be read from file
    char dataToBeRead[50];
    // Open the existing file GfgTest.c using fopen()
    // in read mode using "r" attribute
    filePointer = fopen("./tmp/test.txt", "r");
    // Check if this filePointer is null
    // which maybe if the file does not exist

    if ( filePointer == NULL) {
        printf( "failed to open the file.\n" ) ;
    } else {
        // Read the dataToBeRead from the file
        // using fgets() method
        while(fgets (dataToBeRead, 50, filePointer) != NULL ) {
            printf("%s",dataToBeRead);      // Print the dataToBeRead
        }
        fclose(filePointer) ;               // Closing the file using fclose()
    }
    return 0;
}
