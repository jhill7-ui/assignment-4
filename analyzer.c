/*
 * ICS 212 - Program Structure
 * Homework Assignment 10 - Student Score Analyzer Using Arrays and Pointers
 *
 * Reads student scores, analyzes them using functions (with pointer
 * parameters for returning multiple values), and displays the results.
 */

#include <stdio.h>

#define MAX_STUDENTS 100
#define MIN_SCORE 0
#define MAX_SCORE 100

/* Function prototypes */
void inputScores(int scores[], int size);
void printScores(const int scores[], int size);
void calculateStatistics(const int scores[], int size,
                         int *minimum, int *maximum,
                         double *average);
int countAboveAverage(const int scores[], int size, double average);
int findHighestIndex(const int scores[], int size);
int countInRange(const int scores[], int size, int lower, int upper);

int main(void)
{
    int scores[MAX_STUDENTS];
    int numStudents;
    int minScore;
    int maxScore;
    double averageScore;
    int aboveAverageCount;
    int highestIndex;
    int lowerBound;
    int upperBound;
    int inRangeCount;

    /* Part I: read and validate the number of students */
    printf("Enter the number of students (max %d): ", MAX_STUDENTS);
    scanf("%d", &numStudents);
    while (numStudents < 1 || numStudents > MAX_STUDENTS)
    {
        printf("Error: number of students must be between 1 and %d.\n",
               MAX_STUDENTS);
        printf("Enter the number of students (max %d): ", MAX_STUDENTS);
        scanf("%d", &numStudents);
    }

    /* Part I: read and display the scores */
    inputScores(scores, numStudents);

    printf("\nOriginal scores:\n");
    printScores(scores, numStudents);

    /* Part II: statistics returned through pointer parameters */
    calculateStatistics(scores, numStudents,
                        &minScore, &maxScore, &averageScore);

    printf("\nScore Statistics:\n");
    printf("Minimum score: %d\n", minScore);
    printf("Maximum score: %d\n", maxScore);
    printf("Average score: %.2f\n", averageScore);

    /* Part III: count scores at or above the average */
    aboveAverageCount = countAboveAverage(scores, numStudents, averageScore);
    printf("\nStudents scoring at or above average: %d\n", aboveAverageCount);

    /* Part IV: highest-scoring student (student numbers start at 1) */
    highestIndex = findHighestIndex(scores, numStudents);
    printf("\nHighest-scoring student:\n");
    printf("Student %d (Score: %d)\n", highestIndex + 1, scores[highestIndex]);

    /* Optional Bonus: count scores within an inclusive range */
    printf("\nEnter the lower bound of the range: ");
    scanf("%d", &lowerBound);
    printf("Enter the upper bound of the range: ");
    scanf("%d", &upperBound);

    inRangeCount = countInRange(scores, numStudents, lowerBound, upperBound);
    printf("Scores in the range [%d, %d]: %d\n",
           lowerBound, upperBound, inRangeCount);

    return 0;
}

/*
 * inputScores
 * Reads one score per student into the array. Any score outside the
 * range 0-100 is rejected and the user is asked for that score again.
 */
void inputScores(int scores[], int size)
{
    int i;

    for (i = 0; i < size; i++)
    {
        printf("Enter score for Student %d: ", i + 1);
        scanf("%d", &scores[i]);

        while (scores[i] < MIN_SCORE || scores[i] > MAX_SCORE)
        {
            printf("Error: score must be between %d and %d.\n",
                   MIN_SCORE, MAX_SCORE);
            printf("Enter score for Student %d: ", i + 1);
            scanf("%d", &scores[i]);
        }
    }
}

/*
 * printScores
 * Displays the scores on one line, in the order they were entered.
 */
void printScores(const int scores[], int size)
{
    int i;

    for (i = 0; i < size; i++)
    {
        printf("%d", scores[i]);
        if (i < size - 1)
        {
            printf(" ");
        }
    }
    printf("\n");
}

/*
 * calculateStatistics
 * Finds the minimum, maximum, and average of the scores and returns
 * them to the caller through the pointer parameters. Prints nothing.
 */
void calculateStatistics(const int scores[], int size,
                         int *minimum, int *maximum,
                         double *average)
{
    int i;
    int sum = 0;

    /* Start min and max at the first score, then compare the rest */
    *minimum = scores[0];
    *maximum = scores[0];

    for (i = 0; i < size; i++)
    {
        if (scores[i] < *minimum)
        {
            *minimum = scores[i];
        }
        if (scores[i] > *maximum)
        {
            *maximum = scores[i];
        }
        sum += scores[i];
    }

    /* Cast to double so the division is floating-point, not integer */
    *average = (double) sum / size;
}

/*
 * countAboveAverage
 * Returns how many scores are greater than or equal to the average.
 */
int countAboveAverage(const int scores[], int size, double average)
{
    int i;
    int count = 0;

    for (i = 0; i < size; i++)
    {
        if (scores[i] >= average)
        {
            count++;
        }
    }

    return count;
}

/*
 * findHighestIndex
 * Returns the array index of the highest score. A strict ">" comparison
 * is used, so on a tie the first occurrence is kept.
 */
int findHighestIndex(const int scores[], int size)
{
    int i;
    int highestIndex = 0;

    for (i = 1; i < size; i++)
    {
        if (scores[i] > scores[highestIndex])
        {
            highestIndex = i;
        }
    }

    return highestIndex;
}

/*
 * countInRange (Optional Bonus)
 * Returns how many scores fall within the inclusive range [lower, upper].
 */
int countInRange(const int scores[], int size, int lower, int upper)
{
    int i;
    int count = 0;

    for (i = 0; i < size; i++)
    {
        if (scores[i] >= lower && scores[i] <= upper)
        {
            count++;
        }
    }

    return count;
}

/*/*
 * ICS 212 - Program Structure
 * Homework Assignment 10 - Student Score Analyzer Using Arrays and Pointers
 *
 * Reads student scores, analyzes them using functions (with pointer
 * parameters for returning multiple values), and displays the results.
 */

#include <stdio.h>

#define MAX_STUDENTS 100
#define MIN_SCORE 0
#define MAX_SCORE 100

/* Function prototypes */
void inputScores(int scores[], int size);
void printScores(const int scores[], int size);
void calculateStatistics(const int scores[], int size,
                         int *minimum, int *maximum,
                         double *average);
int countAboveAverage(const int scores[], int size, double average);
int findHighestIndex(const int scores[], int size);
int countInRange(const int scores[], int size, int lower, int upper);

/// @brief 
/// @param  
/// @return 
int main(void)
{
    int scores[MAX_STUDENTS];
    int numStudents;
    int minScore;
    int maxScore;
    double averageScore;
    int aboveAverageCount;
    int highestIndex;
    int lowerBound;
    int upperBound;
    int inRangeCount;

    /* Part I: read and validate the number of students */
    printf("Enter the number of students (max %d): ", MAX_STUDENTS);
    scanf("%d", &numStudents);
    while (numStudents < 1 || numStudents > MAX_STUDENTS)
    {
        printf("Error: number of students must be between 1 and %d.\n",
               MAX_STUDENTS);
        printf("Enter the number of students (max %d): ", MAX_STUDENTS);
        scanf("%d", &numStudents);
    }

    /* Part I: read and display the scores */
    inputScores(scores, numStudents);

    printf("\nOriginal scores:\n");
    printScores(scores, numStudents);

    /* Part II: statistics returned through pointer parameters */
    calculateStatistics(scores, numStudents,
                        &minScore, &maxScore, &averageScore);

    printf("\nScore Statistics:\n");
    printf("Minimum score: %d\n", minScore);
    printf("Maximum score: %d\n", maxScore);
    printf("Average score: %.2f\n", averageScore);

    /* Part III: count scores at or above the average */
    aboveAverageCount = countAboveAverage(scores, numStudents, averageScore);
    printf("\nStudents scoring at or above average: %d\n", aboveAverageCount);

    /* Part IV: highest-scoring student (student numbers start at 1) */
    highestIndex = findHighestIndex(scores, numStudents);
    printf("\nHighest-scoring student:\n");
    printf("Student %d (Score: %d)\n", highestIndex + 1, scores[highestIndex]);

    /* Optional Bonus: count scores within an inclusive range */
    printf("\nEnter the lower bound of the range: ");
    scanf("%d", &lowerBound);
    printf("Enter the upper bound of the range: ");
    scanf("%d", &upperBound);

    inRangeCount = countInRange(scores, numStudents, lowerBound, upperBound);
    printf("Scores in the range [%d, %d]: %d\n",
           lowerBound, upperBound, inRangeCount);

    return 0;
}

/*
 * inputScores
 * Reads one score per student into the array. Any score outside the
 * range 0-100 is rejected and the user is asked for that score again.
 */
void inputScores(int scores[], int size)
{
    int i;

    for (i = 0; i < size; i++)
    {
        printf("Enter score for Student %d: ", i + 1);
        scanf("%d", &scores[i]);

        while (scores[i] < MIN_SCORE || scores[i] > MAX_SCORE)
        {
            printf("Error: score must be between %d and %d.\n",
                   MIN_SCORE, MAX_SCORE);
            printf("Enter score for Student %d: ", i + 1);
            scanf("%d", &scores[i]);
        }
    }
}

/*
 * printScores
 * Displays the scores on one line, in the order they were entered.
 */
void printScores(const int scores[], int size)
{
    int i;

    for (i = 0; i < size; i++)
    {
        printf("%d", scores[i]);
        if (i < size - 1)
        {
            printf(" ");
        }
    }
    printf("\n");
}

/*
 * calculateStatistics
 * Finds the minimum, maximum, and average of the scores and returns
 * them to the caller through the pointer parameters. Prints nothing.
 */
void calculateStatistics(const int scores[], int size,
                         int *minimum, int *maximum,
                         double *average)
{
    int i;
    int sum = 0;

    /* Start min and max at the first score, then compare the rest */
    *minimum = scores[0];
    *maximum = scores[0];

    for (i = 0; i < size; i++)
    {
        if (scores[i] < *minimum)
        {
            *minimum = scores[i];
        }
        if (scores[i] > *maximum)
        {
            *maximum = scores[i];
        }
        sum += scores[i];
    }

    /* Cast to double so the division is floating-point, not integer */
    *average = (double) sum / size;
}

/*
 * countAboveAverage
 * Returns how many scores are greater than or equal to the average.
 */
int countAboveAverage(const int scores[], int size, double average)
{
    int i;
    int count = 0;

    for (i = 0; i < size; i++)
    {
        if (scores[i] >= average)
        {
            count++;
        }
    }

    return count;
}

/*
 * findHighestIndex
 * Returns the array index of the highest score. A strict ">" comparison
 * is used, so on a tie the first occurrence is kept.
 */
int findHighestIndex(const int scores[], int size)
{
    int i;
    int highestIndex = 0;

    for (i = 1; i < size; i++)
    {
        if (scores[i] > scores[highestIndex])
        {
            highestIndex = i;
        }
    }

    return highestIndex;
}

/*
 * countInRange (Optional Bonus)
 * Returns how many scores fall within the inclusive range [lower, upper].
 */
int countInRange(const int scores[], int size, int lower, int upper)
{
    int i;
    int count = 0;

    for (i = 0; i < size; i++)
    {
        if (scores[i] >= lower && scores[i] <= upper)
        {
            count++;
        }
    }

    return count;
}