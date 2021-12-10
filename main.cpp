#include <iostream>
#include <getopt.h>

int main(int argc, char *argv[])
{

    const char *short_options = "V:L:hv";

    const struct option long_options[] = {
        {"Value", required_argument, NULL, 'V'},
        {"List", required_argument, NULL, 'L'},
        {"help", no_argument, NULL, 'h'},
        {"version", no_argument, NULL, 'v'},
        {NULL, 0, NULL, 0}};

    int res, option_index = -1;

    bool V_counter, h_counter, v_counter, L_counter = false;

    while ((res = getopt_long(argc, argv,
                              short_options,
                              long_options,
                              &option_index)) != -1)
    {
        switch (res)
        {
        /* -V or --Value*/
        case 'V':
        {
            if (!V_counter)
            {
                V_counter = true;
                printf("Value = %s\n", optarg);
            }
            break;
        }
        /* -L or --List  */
        case 'L':
        {
            if (!L_counter)
            {
                L_counter = true;
                printf("List = %s\n", optarg);
            }
            break;
        }
        /* -h or --help */
        case 'h':
        {
            if (!h_counter)
            {
                h_counter = true;
                printf("Help\n");
            }
            break;
        }
        /* -v or --version */
        case 'v':
        {
            if (!v_counter)
            {
                v_counter = true;
                printf("Current program version is 1.0 .\n");
            }
            break;
        }
        case '?':
        default:
        {
            printf("Unknown option! Try again.\n");
            break;
        }
        }
        option_index = -1;
    }
    return 0;
}