/* Purpose of the program:
//Author: COMSC420
//File name: XXXProj12.c
//Date: 09/16/24 */
#include <stdio.h>
#define PI 3.1415926
float process(float radius)
    main()
{
    int n, i = 0;
    struct
    {
        char text[20];
        float radius;
        float area;
    } circle[10]; /* structure variable declaration*/

 Printf(“To STOP, enter END for the identifier. \n”);
 Printf(“\n Indentifier : ”);
 Scanf(“% s”, circle[i].text);

 while (circle[i].text[0] != 'E' || circle[i].text[1] != 'N'
}
}
circle[i].text[2] != 'D' )
{
    printf("Radius: ");
    scanf("%f", &circle[i].radius);

    if (circlel[i].radous < 0)
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

printf(\n\n Summary of Results : \n\n);
for (i = 0; i <= n; i++)
{
    printf("%s Radius = %f Area = %f \n ", circle[i].text, circle[i].radius,
           circle[i].area);
}
return 0;
}
float process(float r)
{
    float a;
    a = PI * r * r;
    return (a);
}