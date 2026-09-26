#include <stdio.h>

void print_distances(float distances[], int days)
{
   printf("Distances walked each day:\n");
   for (int i = 0; i < days; i++)
   {
      printf("Day %d: %.2f kilometers\n", i + 1, distances[i]);
   }
}

int main()
{
   int walk_days;
   float walk_distance;
   float total_distance = 0;
   float max_distance = 0;
   int max_day = 0;
   float per_distance[100]; // Array to store distances for each day
   char response;
   
   
    
   printf("Enter the number of days you walked: ");
   scanf("%d", &walk_days);

   if (walk_days <= 0)
   {
      printf("Please enter a positive number of days.\n");
      return 1; 
   }
  
   
   for (int i = 1; i <= walk_days; i++)
   {
      printf("Enter the distance walked on day %d (in kilometers): ", i);
      scanf("%f", &walk_distance);
      
      if (walk_distance < 0 || walk_distance > 1000)
      {
         printf("The number cannot be negative.\n");
         return 1; 
      }
      per_distance[i - 1] = walk_distance; // Store the distance in the array 
      total_distance += walk_distance;
      
      if (walk_distance > max_distance)
      {
         max_distance = walk_distance;
         max_day = i;
      }
   }
    printf("Total distance walked over %d days: %.2f kilometers\n", walk_days, total_distance);

   float average_distance = total_distance / walk_days;
   printf("Average distance walked per day: %.2f kilometers\n", average_distance);

   printf("Maximum distance walked in a single day: %.2f kilometers\n", max_distance);
   printf("This maximum distance was walked on day %d.\n", max_day);

   printf("Do you want to see the distances walked each day? (y/n): ");
   scanf(" %c", &response);
   
   if (response == 'y' || response == 'Y')
   {
      printf("Distances walked each day:\n");
      print_distances(per_distance, walk_days);
   }

   return 0;
}

    
