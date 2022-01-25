#include <stdio.h>
#include <assert.h>


int networkAlert(float celcius);
int networkAlertStub(float celcius);
void alertInCelcius(float farenheit,int (*networkAlertFuncPointer) (float));
    
int alertFailureCount = 0;
bool AlertStubCalled = false;

int networkAlertStub(float celcius) {
    int networkAlertStubResult = 500;
    
    if(celcius == 200)
    {
        networkAlertStubResult = 200;
    }
    AlertStubCalled = true;
    return networkAlertStubResult;

}

int networkAlert(float celcius) {
    
    int networkAlertResult = 500; /*Initialize return value to 500(not-ok) */
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    if(celcius == 200)
    {
        // Update return value to 200 for ok case
        networkAlertResult = 200;
    }
    
    return networkAlertResult;

}

void alertInCelcius(float farenheit,int (*networkAlertFuncPointer) (float)) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlertFuncPointer(celcius);
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 0;
    }
}

int main() {
    int (*networkAlertFuncPointer)(float);
    networkAlertFuncPointer = networkAlert;
    alertInCelcius(400.5,networkAlertFuncPointer);
    assert(alertFailureCount==1);
    alertInCelcius(303.6,networkAlertFuncPointer);
    assert(alertFailureCount==2);
    printf("%d alerts failed.\n", alertFailureCount);
    networkAlertFuncPointer = networkAlertStub;
    alertInCelcius(400.5,networkAlertFuncPointer);
    assert(AlertStubCalled == true); /* Stub is correct so this assert check passes */
    printf("All is well (maybe!)\n");
    return 0;
}
