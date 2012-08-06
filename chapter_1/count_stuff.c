#include <stdio.h>

main()
{
    int c, spaces, tabs, newlines;

    spaces = 0;
    tabs = 0;
    newlines = 0;
    while ((c = getchar()) != EOF)
      if (c == ' ')
        ++spaces;
      else if (c == '\t')
        ++tabs;
      else if (c == '\n')
        ++newlines;
    printf("Spaces:\t%d\n", spaces);
    printf("Tabs:\t%d\n", tabs);
    printf("Newlines:\t%d\n", newlines);

}
