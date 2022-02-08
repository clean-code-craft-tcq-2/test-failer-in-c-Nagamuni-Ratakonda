#include <stdio.h>
#include <assert.h>


int networkAlert(float celcius);
float ConvertFarenHeitToCelcius(float farenheit);
int networkAlertStub(float celcius);
float ConvertFarenHeitToCelciusStub(float farenheit);
void alertInCelcius(float farenheit, float (*ConvertFarenHeitToCelciusFunPtr)(float), int (*networkAlertFuncPointer) (float));
    
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

float ConvertFarenHeitToCelciusStub(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    return celcius;
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

float ConvertFarenHeitToCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    return celcius;
}

void alertInCelcius(float farenheit, float (*ConvertFarenHeitToCelciusFunPtr)(float), int (*networkAlertFuncPointer) (float)) {
    float celcius = ConvertFarenHeitToCelciusFunPtr(farenheit);
    int returnCode = networkAlertFuncPointer(celcius);
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 1;
    }
}

int main() {
    float (*ConvertFarenHeitToCelciusFunPtr)(float);
    int (*networkAlertFuncPointer)(float);
    ConvertFarenHeitToCelciusFunPtr = ConvertFarenHeitToCelcius;
    networkAlertFuncPointer = networkAlert;
    alertInCelcius(400.5,ConvertFarenHeitToCelciusFunPtr,networkAlertFuncPointer);
    assert(alertFailureCount==1);
    alertInCelcius(303.6,ConvertFarenHeitToCelciusFunPtr,networkAlertFuncPointer);
    assert(alertFailureCount==2);
    printf("%d alerts failed.\n", alertFailureCount);
    ConvertFarenHeitToCelciusFunPtr = ConvertFarenHeitToCelciusStub;
    networkAlertFuncPointer = networkAlertStub;
    alertInCelcius(400.5,ConvertFarenHeitToCelciusFunPtr,networkAlertFuncPointer);
    assert(AlertStubCalled == true); /* Stub is correct so this assert check passes */
    printf("All is well (maybe!)\n");
    return 0;
}
