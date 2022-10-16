#include <stdio.h>
char sub[20][20];  // variable to store names of subjects
int points[20];    // variable to store points scored in subjects
float credits[20]; // variable to store credits allocated for subjects
int n;             // variable to store no. of subjects

void result(float credit_points[n])
{
    int count = 0; // variable to count backlogs
    float sum = 0 /*variable to store sum of credit points*/;
    float csum = 0 /*varialbe to store sum of credits*/, sgpa /*variable to store result*/;
    for (int i = 0; i < n; i++)
    {
        sum += credit_points[i];
        csum += credits[i];
    }
    sgpa = sum / csum;
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        if (credit_points[i] == 0)
        {
            printf("Due in '%s'\n", sub[i]);
            count++;
        }
    }
    printf("\nYour SGPA for this semester is "
           "%.2f"
           "\n",
           sgpa);
    printf("\nYou Passed %d out of 8 subjects\n", 8 - count);
    if (count == 0)
        printf("\n*****CONGRATULATIONS*****\n\n");
}

void logic() // this function calculates the credit points
{
    float credit_points[n]; // variable to store credit points
    for (int i = 0; i < n; i++)
    {
        credit_points[i] = credits[i] * points[i];
    }
    result(credit_points);
}
int main()
{
    int i;
    printf("\n\n*******SGPA Calculator*******\n\n");
    // users enter the no. of subjects they have this semester
    printf("Enter no. of subjects: ");
    scanf("%d", &n);
    printf("\n");
    // users enter the names of subjects they have this semester
    for (i = 0; i < n; i++)
    {
        printf("Enter name of subject %d: ", i + 1);
        scanf("%*c%[^\n]", sub[i]);
    }
    printf("\n");
    // users enter the credits allocated for each subject
    for (i = 0; i < n; i++)
    {
        printf("Enter credits allocated for %s: ", sub[i]);
        scanf("%f", &credits[i]);
    }
    printf("\n");
    // users enter the points they scored in each subject
    for (i = 0; i < n; i++)
    {
        printf("Enter points scored in %s: ", sub[i]);
        scanf("%d", &points[i]);
    }
    printf("\n");
    // after taking all the inputs the function 'logic' is called
    logic();
    return 0;
}