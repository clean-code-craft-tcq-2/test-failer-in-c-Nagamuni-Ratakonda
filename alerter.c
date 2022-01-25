#include <stdio.h>
#include <assert.h>

int alertFailureCount = 0;

int networkAlert(float celcius) {
    
    int networkAlertResult = 500; /*Initialize return value to 500(not-ok) */
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    if((celcius >= 0) && (celcius <= 200))
    {
        // Update return value to 200 for ok case
        networkAlertResult = 200;
    }
    
    return networkAlertResult;

}

void alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlert(celcius);
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 0;
    }
}

int main() {
    alertInCelcius(400.5);
    assert(alertFailureCount==1);
    alertInCelcius(303.6);
    assert(alertFailureCount==2);
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
