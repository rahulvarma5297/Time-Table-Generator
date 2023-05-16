#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void print();
void print2();

struct course
{
    char name[20];
    char subject[20][15];
    int creditss[20];
    int room;
    int totalsubjects;
    int ctchr[20];
    int allsubjects;
    int breaks;
};

struct course cour[20];
struct teachers
{
    char name[20];
    int sub[11];
    int cors[11];
    int totalsubjects;
    int allsubjects;
    struct
    {
        struct
        {
            bool busy;
        } busy[10];

    } busy[10];
};

struct teachers teach[20];
struct room
{
    char room[10];
    int allsubjects;
    struct
    {
        struct
        {
            bool busy;
        } busy[10];

    } busy[10];

    struct
    {
        struct
        {
            bool lunch;
        } lunch[10];

    } lunch[2];
};
struct room room_arr[20];
struct tempsub
{
    struct
    {
        struct
        {
            char tempsub[20];
        } tempsub[20];

    } tempsub[20];

} tempsub[20];
struct tmptchr
{
    struct
    {
        struct
        {
            char tmptchr[20];
        } tmptchr[20];

    } tmptchr[20];

} tmptchr[20];
struct fisub
{
    struct
    {
        struct
        {
            char fisub[20];
        } fisub[20];

    } fisub[20];

} fisub[20];
struct fitch
{
    struct
    {
        struct
        {
            char fitch[20];
        } fitch[10];

    } fitch[20];

} fitch[20];
long int crs, tch, room, dys, lects, tmptch, tmproom, set, settmp, done;
void getData()
{
    printf("Enter Total Working Days: ");
    scanf("%d", &dys);
    printf("Enter Number of Lectures per day: ");
    scanf("%d", &lects);
    printf("Enter Number of Batches(UG2, UG3, UG4) ie.. 3: ");
    scanf("%d", &crs);
    printf("Enter Number of Total Teachers: ");
    scanf("%d", &tch);
    printf("Enter Number of Rooms: ");
    scanf("%d", &room);
}

void getStudentEnrollment()
{
    int i, j, k;
    for (i = 0; i < room; i++)
    {
        printf("Enter room name %d: ", i + 1);
        scanf("%s", room_arr[i].room);
    }
    for (i = 0; i < tch; i++)
    {
        printf("Enter teacher name %d: ", i + 1);
        scanf("%s", teach[i].name);
    }
    for (i = 0; i < crs; i++)
    {
        printf("\nEnter Batch name (ie.. ug2, ug3, ug4): ");
        scanf("%s", cour[i].name);
        printf("\nEnter Total Subjects: "); // less than m x n
        scanf("%d", &cour[i].totalsubjects);

        for (j = 0; j < cour[i].totalsubjects; j++)
        {
            printf("Enter Subject name: ");
            scanf("%s", cour[i].subject[j]);
            printf("Enter credit for that subject:");
            scanf("%d", &cour[i].creditss[j]);
            printf("Select a Teacher for Subject %d: ", j + 1);

            for (k = 0; k < tch; k++)
                printf("\n%d.%s\t", k, teach[k].name);
            printf("\nEnter Teacher Number\n");
            scanf("%d", &tmptch);
            cour[i].ctchr[j] = tmptch;
            teach[tmptch].sub[teach[tmptch].totalsubjects] = j;  // not used yet
            teach[tmptch].cors[teach[tmptch].totalsubjects] = i; // not used yet
            teach[tmptch].totalsubjects++;                    // less than m x n
            teach[tmptch].allsubjects += cour[i].creditss[j];
            if (teach[tmptch].allsubjects > lects * dys - dys) // check total sub limit for a teacher
            {
                printf("Number of working hours exceeding for the teacher!!");
            }
        }
        printf("Enter a room for this UG (Choose the Number): ");
        for (j = 0; j < room; j++)
        {
            printf("\nRoom %d:%s", j, room_arr[j].room);
        }
        printf("\n");
        scanf("%d", &tmproom);
        cour[i].room = tmproom;
        room_arr[tmproom].allsubjects += cour[i].allsubjects;
        if (room_arr[tmproom].allsubjects > lects * dys - dys)
        {
            printf("Number of classes exceeding for the given room!!");
        }
    }
}

void getCourseOffered()
{
    // already brought in getStudentEnrollment()
    int i, j, k;
    for (i = 0; i < crs; i++)
    {
        printf("\nBatch %d:%s", i, cour[i].name);
        printf("\nTotal Subjects:%d", cour[i].totalsubjects);
        printf("\nRoom:%s", room_arr[cour[i].room].room);
        printf("\nSubjects:");
        for (j = 0; j < cour[i].totalsubjects; j++)
        {
            printf("\n\tSubject %d:%s", j, cour[i].subject[j]);
            printf("\n\t\tTeacher:%s", teach[cour[i].ctchr[j]].name);
            printf("\n\t\tCredit:%d", cour[i].creditss[j]);
        }
    }
}

void getInitialTimeSlot()
{
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    for (i = 0; i < crs; i++)
    {
        for (j = 0; j < cour[i].totalsubjects; j++)
        {
            for (k = 0; k < dys; k++)
            {
                for (l = 0; l < lects; l++)
                {
                    for (m = 0; m < room; m++)
                    {
                        if (cour[i].room == m)
                        {
                            for (n = 0; n < tch; n++)
                            {
                                if (cour[i].ctchr[j] == n)
                                {
                                    for (o = 0; o < dys; o++)
                                    {
                                        for (p = 0; p < lects; p++)
                                        {
                                            if (teach[n].busy[o].busy[p].busy == false && room_arr[m].busy[o].busy[p].busy == false)
                                            {
                                                teach[n].busy[o].busy[p].busy = true;
                                                room_arr[m].busy[o].busy[p].busy = true;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    getInitialTimeSlot();
}

void getAvailableTimeSlot(int x)
{
    int i, j, k;
    for (i = 0; i <= x; i++)
        for (j = 0; j < lects; j++)
            for (k = 0; k < dys; k++)
            {
                strcpy(fitch[i].fitch[j].fitch[k].fitch,
                       tmptchr[i].tmptchr[j].tmptchr[k].tmptchr);
                strcpy(fisub[i].fisub[j].fisub[k].fisub,
                       tempsub[i].tempsub[j].tempsub[k].tempsub);
            }
}

void ColorEdges()
{

    int edge1[4] = {10, 20, 30, 40};
    int edge2[4] = {30, 20, 40, 10};
    int m[12][2];
    for (int i = 0; i < 4; i++)
    {
        m[i][0] = edge1[i];
        m[i][1] = edge2[i];
    }
    for (int i = 0; i < 2; i++)
    {
        int temp = edge1[i];
        edge1[i] = edge1[3 - i];
        edge1[3 - i] = temp;
    }
    for (int i = 0; i < 2; i++)
    {
        int temp = edge2[i];
        edge2[i] = edge2[3 - i];
        edge2[3 - i] = temp;
    }
    for (int i = 4; i < 8; i++)
    {
        m[i][0] = edge1[i - 4];
        m[i][1] = edge2[i - 4];
    }
    for (int i = 0; i < 2; i++)
    {
        int temp = edge1[i];
        edge1[i] = edge1[3 - i];
        edge1[3 - i] = temp;
    }
    for (int i = 0; i < 2; i++)
    {
        int temp = edge2[i];
        edge2[i] = edge2[3 - i];
        edge2[3 - i] = temp;
    }
    for (int i = 8; i < 12; i++)
    {
        m[i][0] = edge1[i - 8];
        m[i][1] = edge2[i - 8];
    }

    int i, j, k;
    for (i = 0; i < crs; i++)
    {
        for (j = 0; j < cour[i].totalsubjects; j++)
        {
            for (k = 0; k < cour[i].totalsubjects; k++)
            {
                if (j != k)
                {
                    if (cour[i].ctchr[j] == cour[i].ctchr[k])
                    {
                        printf("Edge between %s and %s\n", cour[i].subject[j], cour[i].subject[k]);
                    }
                    else
                    {
                        printf("Edge between %s and %s\n", cour[i].subject[j], cour[i].subject[k]);
                    }
                }
            }
        }
    }
}

void generateTimetable(int i, int j, int k)
{
    int x;
    if ((i < crs) && (set != crs))
    {
        if (((j == (lects / 2) - 1 && (room_arr[cour[i].room].busy[j + 1].busy[k].busy == false)) && (room_arr[cour[i].room].lunch[0].lunch[k].lunch == false)) || (j == (lects / 2) && (room_arr[cour[i].room].busy[j - 1].busy[k].busy == true) && (room_arr[cour[i].room].lunch[1].lunch[k].lunch == false)))
        {
            strcpy(tmptchr[i].tmptchr[j].tmptchr[k].tmptchr, " ");
            strcpy(tempsub[i].tempsub[j].tempsub[k].tempsub, "    Break");
            if (j == (lects / 2) - 1)
                room_arr[cour[i].room].lunch[0].lunch[k].lunch = true;
            else
                room_arr[cour[i].room].lunch[1].lunch[k].lunch = true;
            cour[i].breaks++;
            generateTimetable(i + (j + (k + 1) / dys) / lects,
                              (j + (k + 1) / dys) % lects, (k + 1) % dys);
            if (!done)
            {
                if (j == (lects / 2) - 1)
                    room_arr[cour[i].room].lunch[0].lunch[k].lunch = false;
                else
                    room_arr[cour[i].room].lunch[1].lunch[k].lunch = false;

                cour[i].breaks--;
            }
        }

        for (x = 0; x < cour[i].totalsubjects; x++)
        {
            if ((teach[cour[i].ctchr[x]].busy[j].busy[k].busy == false) && (room_arr[cour[i].room].busy[j].busy[k].busy == false) && (cour[i].creditss[x] > 0) && (cour[i].allsubjects <= ((dys * lects) - cour[i].breaks)))
            {
                strcpy(tmptchr[i].tmptchr[j].tmptchr[k].tmptchr,
                       teach[cour[i].ctchr[x]].name);
                strcpy(tempsub[i].tempsub[j].tempsub[k].tempsub,
                       cour[i].subject[x]);
                cour[i].creditss[x]--;
                teach[cour[i].ctchr[x]].busy[j].busy[k].busy = true;
                room_arr[cour[i].room].busy[j].busy[k].busy = true;
                if (j == (lects - 1) && k == (dys - 1))
                    set++;
                if (settmp < set)
                {
                    settmp = set;
                    getAvailableTimeSlot(i);
                }
                generateTimetable(i + (j + (k + 1) / dys) / lects,
                                  (j + (k + 1) / dys) % lects, (k + 1) % dys);
                if (!done)
                {
                    if (j == (lects - 1) && k == (dys - 1)) // backtrack start
                        set--;
                    cour[i].creditss[x]++;
                    teach[cour[i].ctchr[x]].busy[j].busy[k].busy = false;
                    room_arr[cour[i].room].busy[j].busy[k].busy = false;
                    tmptchr[i].tmptchr[j].tmptchr[k].tmptchr[0] = '\0';
                    tempsub[i].tempsub[j].tempsub[k].tempsub[0] = '\0';
                }
            }
        }

        if (cour[i].allsubjects < ((lects * dys) - (cour[i].breaks)))

        {
            cour[i].breaks++;
            strcpy(tmptchr[i].tmptchr[j].tmptchr[k].tmptchr, "--");
            strcpy(tempsub[i].tempsub[j].tempsub[k].tempsub, "--");
            if (j == (lects - 1) && k == (dys - 1))
                set++;
            if (settmp < set)
            {
                settmp = set;
                getAvailableTimeSlot(i);
            }
            generateTimetable(i + (j + (k + 1) / dys) / lects,
                              (j + (k + 1) / dys) % lects, (k + 1) % dys);
            if (!done)
            {
                if (j == (lects - 1) && k == (dys - 1))
                    set--;
                cour[i].breaks--;
            }
        }
    }
    else
    {
        done = 1;
    }
}
void print()
{
    int i, j, k;
    printf("\n");
    printf("-------------------------------------------Time Table-----------------------------------\n\n");
    for (i = 0; i < crs; i++)
    {
        printf("\t");
        for (j = 0; j < dys; j++)

            printf("\t Day %d\t", j + 1);
        printf("\n_____________________________________%s________________________________________________\n\n\n", cour[i].name);
        for (j = 0; j < lects; j++)

        {
            printf("Period %d ", j + 1);
            for (k = 0; k < dys; k++)
            {
                printf("%9s\t", fisub[i].fisub[j].fisub[k].fisub);
            }
            printf("\n ");

            for (k = 0; k < dys; k++)
            {
                printf("\t%9s", fitch[i].fitch[j].fitch[k].fitch);
            }
            printf("\n");

            printf("\n\n");
        }
        printf("-----------------------------------------------------------------------------------\n");
        printf("\n\n");
    }
}

void generateGraph()
{
    int i, j, k;
    // print all subjects and teachers
    printf("Graph of subjects and teachers:\n");
    printf("\n");
    for (i = 0; i < crs; i++)
    {
        printf("%s -->", cour[i].name);
        for (j = 0; j < cour[i].totalsubjects; j++)
        {
            printf(" %s -->", cour[i].subject[j]);
            printf(" %s,", teach[cour[i].ctchr[j]].name);
        }
        printf("\n");
    }

    // print all subjects and rooms
    printf("\n");
    printf("Graph of subjects and rooms:\n");
    printf("\n");
    for (i = 0; i < crs; i++)
    {
        printf("%s -->", cour[i].name);
        for (j = 0; j < cour[i].totalsubjects; j++)
        {
            printf(" %s -->", cour[i].subject[j]);
            printf(" %s,", room_arr[cour[i].room]);
        }
        printf("\n");
    }
    printf("\n");
    // print all subjects and teachers
    printf("Graph of Batches and Teachers:\n");
    printf("\n");
    for (i = 0; i < crs; i++)
    {
        printf("%s -->", cour[i].name);
        for (j = 0; j < cour[i].totalsubjects; j++)
        {
            printf(" %s,", teach[cour[i].ctchr[j]].name);
        }
        printf("\n");
    }
       
}

int main()
{
    getData();
    getStudentEnrollment();
    getCourseOffered();
    ColorEdges();
    generateTimetable(0, 0, 0);
    print();
    generateGraph();
    return 0;
}