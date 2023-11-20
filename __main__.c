#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "colorify.h"
#include "linkedlist.h"



void start()
{
    int c = 0;
    int lineNo;
    char buffer[100];
    char filename[100];
    node* head = initNode("");
    clear_screen();
    do
    {
        printf("%s-------------------%s\n", YELLOW_FG, RESET);
        printf("%s     LuffyEdit     %s\n", RED_FG, RESET);
        printf("%s-------------------%s\n", YELLOW_FG, RESET);
        printf("%s1.%s Insert%s\n", CYAN_FG, GREEN_FG, RESET);
        printf("%s2.%s Delete%s\n", CYAN_FG, GREEN_FG, RESET);
        printf("%s3.%s Replace%s\n", CYAN_FG, GREEN_FG, RESET);
        printf("%s4.%s Clear%s\n", CYAN_FG, GREEN_FG, RESET);
        printf("%s5.%s Display%s\n", CYAN_FG, GREEN_FG, RESET);
        printf("%s6.%s load from file%s\n", CYAN_FG, GREEN_FG, RESET);
        printf("%s7.%s save to file%s\n", CYAN_FG, GREEN_FG, RESET);
        printf("%s0.%s Exit%s\n", CYAN_FG, GREEN_FG, RESET);
        printf("%sEnter your choice: %s", CYAN_FG, MAGENTA_FG);
        scanf("%d", &c);
        printf("%s", RESET);
        switch(c)
        {
            case 1:
                printf("%sInsert at line number %s", CYAN_FG, MAGENTA_FG);
                scanf("%d", &lineNo);
                while (getchar() != '\n');

                printf("%sInsert line %s", CYAN_FG, MAGENTA_FG);
                fgets(buffer, sizeof(buffer), stdin);
                buffer[strcspn(buffer, "\n")] = '\0';

                if(lineNo <= 0)
                    printf("%sInvalid line number.%s\n", RED_FG, RESET);
                else
                {
                    insertNode(&head, lineNo, buffer);
                    clear_screen();
                    printf("%sInserted \"%s\" at line %d.%s\n\n", GREEN_FG, buffer, lineNo, RESET);
                }
                break;

            case 2:
                printf("%sDelete line number %s", CYAN_FG, MAGENTA_FG);
                scanf("%d", &lineNo);
                while (getchar() != '\n');

                if(lineNo <= 0)
                    printf("%sInvalid line number.%s\n", RED_FG, RESET);
                else
                {
                    removeNode(&head, lineNo);
                    clear_screen();
                    printf("%sDeleted line %d.%s\n\n", GREEN_FG, lineNo, RESET);
                }
                break;

            case 3:
                printf("%sReplace line number %s", CYAN_FG, MAGENTA_FG);
                scanf("%d", &lineNo);
                while (getchar() != '\n');
                printf("%sReplace line with %s", CYAN_FG, MAGENTA_FG);
                fgets(buffer, sizeof(buffer), stdin);
                buffer[strcspn(buffer, "\n")] = '\0';

                if(lineNo <= 0)
                    printf("%sInvalid line number.%s\n", RED_FG, RESET);
                else
                {
                    replaceNode(&head, lineNo, buffer);
                    clear_screen();
                    printf("%sReplaced line %d with \"%s\".%s\n\n", GREEN_FG, lineNo, buffer, RESET);
                }
                break;

            case 4:
                printf("%sClear line number %s", CYAN_FG, MAGENTA_FG);
                scanf("%d", &lineNo);
                while (getchar() != '\n');
                
                if(lineNo <= 0)
                    printf("%sInvalid line number.%s\n", RED_FG, RESET);
                else
                {
                    clearNode(&head, lineNo);
                    clear_screen();
                    printf("%sCleared line %d.%s\n\n", GREEN_FG, lineNo, RESET);
                }
                break;

            case 5:
                clear_screen();
                displayNode(head);
                printf("\n\n");
                break;
            case 6:
                printf("%sEnter file name you want to load %s", CYAN_FG, MAGENTA_FG);
                scanf("%s", filename);
                // printf("%s", RESET);
                head = load(filename);
                // clear_screen();
                // displayNode(head);
                printf("\n\n");
                break;
            case 7:
            printf("%senter the file name you want to save %s", CYAN_FG, MAGENTA_FG);
                scanf("%s", filename);
                save(head , filename);
                clear_screen();
                printf("%ssaved to file %s %s\n\n", GREEN_FG, filename, RESET);

                // displayNode(head);
                printf("\n\n");
                break;
            

            case 0:
                printf("%sThanks for using!!%s\n", GREEN_FG, RESET);
                break;

            default:
                clear_screen();
                printf("%sInvalid Option.%s\n\n", RED_FG, RESET);
                break;
        }
    }
    while(c != 0);
}

int main()
{
    start();
}