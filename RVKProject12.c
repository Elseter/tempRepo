/* Purpose of the program: Read in circles with identifiers and radius
//Author: COMSC420 - Riley King
//File name: RVKProject12.c
//Date: 09/22/24 */

#include <stdio.h>
#define PI 3.1415926

float process(float r)
{
    float a;
    a = PI * r * r;
    return (a);
}

int main(){

    int n = 0;
    int i = 0;

    struct circleType
    {
        char text[20];
        float radius;
        float area;
    };

    struct circleType circle[10]; /* structure variable declaration*/

    printf("To STOP, enter END for the identifier. \n");
    printf("\n Indentifier : ");
    scanf("%s", circle[i].text);

    while (i < 10 && !(circle[i].text[0] == 'E' && circle[i].text[1] == 'N' && circle[i].text[2] == 'D'))
    {
        printf("Radius: ");
        scanf("%f", &circle[i].radius);

        if (circle[i].radius < 0)
        {
            circle[i].area = 0;
        }
        else
            circle[i].area = process(circle[i].radius);

        ++i;
        printf("\n Identifier: ");
        scanf("%s", circle[i].text);
    }

    n = --i;

    printf("\n\n Summary of Results: \n\n");
    for (i = 0; i <= n; i++)
    {
        printf("%s Radius = %f Area = %f \n ", circle[i].text, circle[i].radius, circle[i].area);
    }
    return 0;
}
