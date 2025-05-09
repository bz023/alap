#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VER "0.1a"

#define CODE_C "#include <stdio.h>\n#include <stdlib.h>\n\nint main(int argc, char *argv[])\n{\n\tprintf(\"Hello World!\\n\");\n\treturn 0;\n}\n"
#define CODE_CSHARP "public class Program\n{\n\tpublic static void Main(string[] args)\n\t{\n\t\tSystem.Console.WriteLine(\"Hello, World!\");\n\t}\n}\n"
#define CODE_PYTHON "message = \"Hello, Python!\"\nprint(message)\n"
#define CODE_BASH "#!/bin/bash\necho \"Hello World\"\n"


void show_help();
void show_ver();
void create_File(char filename[], char type[]);

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        if(strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)
        {
            show_help();
        }
        else if(strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "--version") == 0)
        {
            show_ver();
        }
        else
        {
            char filename[100];

            if (strcmp(argv[1], "c") == 0)
            {
                strcpy(filename, "main.c");
                create_File(filename, "c");
            }
            else if (strcmp(argv[1], "cs") == 0)
            {
                strcpy(filename, "Program.cs");
                create_File(filename, "cs");
            }
            else if (strcmp(argv[1], "py") == 0)
            {
                strcpy(filename, "main.py");
                create_File(filename, "py");
            }
            else if (strcmp(argv[1], "sh") == 0)
            {
                strcpy(filename, "main.sh");
                create_File(filename, "sh");
            }
            else
            {
                show_help();
            }           
        }
    }
    else if (argc == 3)
    {
        if (strcmp(argv[2], "--stdout") == 0)
        {
            if (strcmp(argv[1], "c") == 0)
            {
                printf(CODE_C);
            }
            else if (strcmp(argv[1], "cs") == 0)
            {
                printf(CODE_CSHARP);
            }
            else if (strcmp(argv[1], "py") == 0)
            {
                printf(CODE_PYTHON);
            }
            else if (strcmp(argv[1], "sh") == 0)
            {
                printf(CODE_BASH);
            }
            else
            {
                show_help();
            }   
        }
        else
        {
            show_help();
        }
    }
    else
    {
        show_help();
    }
    return 0;
}

void show_help()
{
    printf("alap v%s,\n\n",VER);
    printf("Usage: alap <template_type> [option]\n\n");
    printf("Available options: \n\n");

    printf("-h, --help \t show this help\n");
    printf("-v, --version \t version info\n");
    printf("--stdout\t don't create source file, print result to stdout\n\n");

    printf("Available templates: \n\n");

    printf("* c\t - C source code [main.c]\n");
    printf("* cs\t - C# source code [Program.cs]\n");
    printf("* py\t - Python 3 source code [main.py]\n");
    printf("* sh\t - Bash source code [main.sh]\n");
}

void show_ver()
{
    printf("alap v%s\n",VER);
}

void create_File(char filename[], char type[])
{

    FILE *file;
    file = fopen(filename, "r");
    if (file != NULL)
    {
        printf("ERROR: file '%s' already exists!\n", filename);
        fclose(file);
        exit(1);
    }

    file = fopen(filename, "w");

    if (strcmp(type, "c") == 0)
    {
        fprintf(file, "%s", CODE_C);
    }
    else if (strcmp(type, "cs") == 0)
    {
        fprintf(file, "%s", CODE_CSHARP);
    }
    else if (strcmp(type, "py") == 0)
    {
        fprintf(file, "%s", CODE_PYTHON);
    }
    else if (strcmp(type, "sh") == 0)
    {
        fprintf(file, "%s", CODE_BASH);
    }

    fclose(file);

    printf("# '%s' created successfully.\n", filename);
}