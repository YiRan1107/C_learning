#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>//输入输出头文件
#include <stdlib.h>//标准库头文件
#include <direct.h>//目录操作头文件
#include <errno.h>//错误处理头文件
#include <time.h>//时间的获取
#include <conio.h>//获取字符

struct WalkDataRecord
{
    int day;
    float distance;
};
 void print_distances(FILE *output,const struct WalkDataRecord records[], int days)
{
     fprintf(output, "Distance walked each day:\n");

     for (int i = 0;i < days;i++)
     {
         fprintf(output, "|Day %4d| %8.2f kilometers|\n", records[i].day, records[i].distance);
     }
}

 int main()
 { 
    int walk_days;
    float walk_distance;
    float total_distance = 0;
    float max_distance = 0;
    int max_day;
    char response;

    printf("Enter the number of days you walked: ");

    if (scanf("%d", &walk_days) != 1 || walk_days <= 0 || walk_days > 1000)
    {
        printf("Please enter a positive number of days (up to 1000).\n");
        return 1;
    }

    struct WalkDataRecord *records = malloc(sizeof(struct WalkDataRecord) * walk_days);
    if (records == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < walk_days; i++)
    {
        printf("Enter the distance walked on day %d (in kilometers): ", i + 1);

        if (scanf("%f", &walk_distance) != 1 || walk_distance < 0 || walk_distance > 1000)
        {
            printf("The number cannot be negative or exceed 1000.\n");
            free(records); // Free the allocated memory
            return 1;
        }

        records[i].day = i + 1;
        records[i].distance = walk_distance;
        total_distance += walk_distance;

        if (i == 0 || walk_distance > max_distance)
        {
            max_distance = walk_distance;
            max_day = records[i].day;
        }
    }
    printf("Total distance walked over %d days: %.2f kilometers\n", walk_days, total_distance);

    float average_distance = total_distance / walk_days;
    printf("Average distance walked per day: %.2f kilometers\n", average_distance);

    printf("Maximum distance walked in a single day: %.2f kilometers\n", max_distance);
    printf("This maximum distance was walked on day %d.\n", max_day);

    printf("Do you want to see the distances walked each day with txt formate? (y/n): ");
    scanf(" %c", &response);

    if (response == 'y' || response == 'Y')
    {
        _mkdir("D:/vscoding/files_io");
        FILE* file = fopen("D:/vscoding/files_io/try.txt", "w");
        if (file == NULL)
        {
            printf("Failed to save. Data is still in memory.\n");
        }
        else
        {
            print_distances(file, records, walk_days);
            fclose(file);
        }
    }
    free(records); // Free the allocated memory
    printf("please press any key to continue...");
    _getch();

    return 0;
 }



