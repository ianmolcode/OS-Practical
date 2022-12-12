// fifo page replacement algorithm
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, k, p, nframe, npage, page[100], frame[100], flag, count, temp, pos, fault = 0;
    printf("Enter the number of frames: ");
    scanf("%d", &nframe);
    for (i = 0; i < nframe; i++)
        frame[i] = -1;
    printf("Enter the number of pages: ");
    scanf("%d", &npage);
    printf("Enter the page reference string: ");
    for (i = 0; i < npage; i++)
        scanf("%d", &page[i]);
    for (i = 0; i < npage; i++)
    {
        flag = 0;
        for (j = 0; j < nframe; j++)
        { // check if page is already in frame
            if (frame[j] == page[i])
            {
                printf("\n HIT:");
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            frame[pos] = page[i];
            pos++;
            printf("\n MISS:");
            fault++;
            if (pos >= nframe)
                pos = 0;
        }
        for (k = 0; k < nframe; k++)
            printf("\t%d", frame[k]);
    }
    printf("\n\nTotal number of page faults: %d", fault);
}