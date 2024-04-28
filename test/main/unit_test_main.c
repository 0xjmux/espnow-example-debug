

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "unity.h"

// #include "neopixel_display.h"

static void print_banner(const char* text);

void app_main(void)
{
    /* These are the different ways of running registered tests.
     * In practice, only one of them is usually needed.
     *
     * UNITY_BEGIN() and UNITY_END() calls tell Unity to print a summary
     * (number of tests executed/failed/ignored) of tests executed between these calls.
     */
    // print_banner("Executing one test by its name");
    // UNITY_BEGIN();
    // unity_run_test_by_name("test matrix orientation");
    // UNITY_END();
    // print_banner("Running tests with [mean] tag");
    // UNITY_BEGIN();
    // unity_run_tests_by_tag("[mean]", false);
    // UNITY_END();


    print_banner("Running all the registered tests");
    UNITY_BEGIN();
    unity_run_all_tests();
    UNITY_END();

    // print_banner("Starting interactive test menu");
    /* This function will not return, and will be busy waiting for UART input.
     * Make sure that task watchdog is disabled if you use this function.
     */
    // unity_run_menu();


    printf("Finished all tests - not showing interactive menu because it's broken on the ESP32S3\n");
    while (1) {
        vTaskDelay(1000);
    }
    exit(0);
}


static void print_banner(const char* text)
{
    printf("\n#### %s #####\n\n", text);
}
