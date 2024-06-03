#include <stdio.h>
#include <string.h>

void welcomeMessage();
void goodbyeMessage();
void diagnose(const char *symptoms);
void getYesNoInput(char *input, const char *question);

int main() {
    char name[50];
    char symptoms[100];
    char feverAnswer[4], headacheAnswer[4], jointPainAnswer[4], chillsAnswer[4], sweatingAnswer[4];
    char coughAnswer[4], shortnessOfBreathAnswer[4], chestPainAnswer[4], runnyNoseAnswer[4];

    welcomeMessage();

    printf("\nEnter your name: ");
    scanf("%s", name);

    getYesNoInput(feverAnswer, "Do you have fever? (yes/no): ");
    getYesNoInput(headacheAnswer, "Do you have headache? (yes/no): ");
    getYesNoInput(jointPainAnswer, "Do you have joint pain? (yes/no): ");
    getYesNoInput(chillsAnswer, "Do you have chills? (yes/no): ");
    getYesNoInput(sweatingAnswer, "Do you have sweating? (yes/no): ");
    getYesNoInput(coughAnswer, "Do you have cough? (yes/no): ");
    getYesNoInput(shortnessOfBreathAnswer, "Do you have shortness of breath? (yes/no): ");
    getYesNoInput(chestPainAnswer, "Do you have chest pain? (yes/no): ");
    getYesNoInput(runnyNoseAnswer, "Do you have runny nose? (yes/no): ");

    strcpy(symptoms, "");
    if (strcmp(feverAnswer, "yes") == 0) {
        strcat(symptoms, "fever, ");
    }
    if (strcmp(headacheAnswer, "yes") == 0) {
        strcat(symptoms, "headache, ");
    }
    if (strcmp(jointPainAnswer, "yes") == 0) {
        strcat(symptoms, "joint pain, ");
    }
    if (strcmp(chillsAnswer, "yes") == 0) {
        strcat(symptoms, "chills, ");
    }
    if (strcmp(sweatingAnswer, "yes") == 0) {
        strcat(symptoms, "sweating, ");
    }
    if (strcmp(coughAnswer, "yes") == 0) {
        strcat(symptoms, "cough, ");
    }
    if (strcmp(shortnessOfBreathAnswer, "yes") == 0) {
        strcat(symptoms, "shortness of breath, ");
    }
    if (strcmp(chestPainAnswer, "yes") == 0) {
        strcat(symptoms, "chest pain, ");
    }
    if (strcmp(runnyNoseAnswer, "yes") == 0) {
        strcat(symptoms, "runny nose, ");
    }

    int len = strlen(symptoms);
    if (len > 0 && symptoms[len - 2] == ',') {
        symptoms[len - 2] = '\0';
    }

    diagnose(symptoms);

    goodbyeMessage();

    return 0;
}

void welcomeMessage() {
    printf("\n*** Welcome to the Virtual Doctor App where the dr is at your doorstep. ***\n");
    printf("Your health is our priority! Let's get started.\n");
}

void goodbyeMessage() {
    printf("\nThank you for using the Virtual Doctor App! Enjoy a 10 percent discount next time by uploading the benefits of our app on your social media.\n");
    printf("Stay safe and healthy!\n");
}

void diagnose(const char *symptoms) {
    printf("\nBased on the symptoms you provided (%s),\n", symptoms);

    int diagnosed = 0;

    if (strstr(symptoms, "fever") != NULL && strstr(symptoms, "headache") != NULL && strstr(symptoms, "joint pain") != NULL) {
        printf("It seems you might be suffering from Dengue.\n");
        printf("Here are some suggestions:\n");
        printf("- Get plenty of bed rest.\n");
        printf("- Drink fluids to stay hydrated.\n");
        printf("- Take acetaminophen for fever and pain.\n");
        printf("- Avoid mosquito bites to prevent further spread.\n");
        diagnosed = 1;
    }
    if (strstr(symptoms, "fever") != NULL && strstr(symptoms, "chills") != NULL && strstr(symptoms, "sweating") != NULL) {
        printf("It seems you might be suffering from Malaria.\n");
        printf("Here are some suggestions:\n");
        printf("- Take prescribed anti-malarial medication.\n");
        printf("- Rest in a cool, dark room.\n");
        printf("- Drink plenty of fluids.\n");
        diagnosed = 1;
    }
    if (strstr(symptoms, "fever") != NULL && strstr(symptoms, "cough") != NULL && strstr(symptoms, "shortness of breath") != NULL) {
        printf("It seems you might be suffering from COVID-19.\n");
        printf("Here are some suggestions:\n");
        printf("- Self-isolate and monitor your symptoms.\n");
        printf("- Seek medical attention if symptoms worsen.\n");
        printf("- Follow guidelines provided by health authorities.\n");
        diagnosed = 1;
    }
    if (strstr(symptoms, "fever") != NULL && strstr(symptoms, "cough") != NULL && strstr(symptoms, "chest pain") != NULL) {
        printf("It seems you might be suffering from Pneumonia.\n");
        printf("Here are some suggestions:\n");
        printf("- Get plenty of rest.\n");
        printf("- Drink fluids to stay hydrated.\n");
        printf("- Take antibiotics as prescribed by your doctor.\n");
        printf("- Seek immediate medical attention if symptoms worsen.\n");
        diagnosed = 1;
    }
    if (strstr(symptoms, "fever") != NULL && strstr(symptoms, "runny nose") != NULL && strstr(symptoms, "cough") != NULL) {
        printf("It seems you might be suffering from Seasonal Fever (Flu).\n");
        printf("Here are some suggestions:\n");
        printf("- Get plenty of rest.\n");
        printf("- Drink fluids to stay hydrated.\n");
        printf("- Take over-the-counter medications for fever and cough.\n");
        printf("- Avoid contact with others to prevent spreading the flu.\n");
        diagnosed = 1;
    }

    if (!diagnosed) {
        printf("Unfortunately, we couldn't diagnose your condition based on the provided symptoms.\n");
        printf("We recommend consulting a healthcare professional for further evaluation.\n");
    }
}

void getYesNoInput(char *input, const char *question) {
    while (1) {
        printf("%s", question);
        scanf("%s", input);
        if (strcmp(input, "yes") == 0 || strcmp(input, "no") == 0) {
            break;
        } else {
            printf("Invalid input. Please answer 'yes' or 'no'.\n");
        }
    }
}
