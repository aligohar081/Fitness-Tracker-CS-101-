#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function Prototypes
void getData(int* steps, int* calories, int* workoutTime, int* waterIntake, int* sleepHours, int days);
void displaySummary(int* steps, int* calories, int* workoutTime, int* waterIntake, int* sleepHours, int days);
void calculateBMI(double weight, double height);
void setFitnessGoals(int* goalSteps, int* goalCalories, int* goalWorkoutTime);
void provideFeedback(int* steps, int* calories, int* workoutTime, int* goalSteps, int* goalCalories, int* goalWorkoutTime, int days);
void trackSleep(int* sleepHours, int days);
void compareProgress(int* steps, int* calories, int* workoutTime, int days);
void dailyHealthTips(int* steps, int* calories, int* workoutTime, int* goalSteps, int* goalCalories, int* goalWorkoutTime, int days);
void displayDataForSpecificDay(int* steps, int* calories, int* workoutTime, int* waterIntake, int* sleepHours, int days);
void unlockAchievements(int* steps, int* calories, int* workoutTime, int days);
void motivationalQuotes();
void displayProgressGraph(int* steps, int* calories, int days);
void generateWeeklyReport(int* steps, int* calories, int* workoutTime, int* waterIntake, int* sleepHours, int days);

int main() {
    srand(time(0));  // Initialize random seed for motivational quotes

    const int days = 7; // Track data for a week
    int steps[days], calories[days], workoutTime[days], waterIntake[days], sleepHours[days];
    int goalSteps, goalCalories, goalWorkoutTime;

    // ========== Welcome Message ==========
    cout << "\n******************************************************\n";
    cout << "*****    Welcome to Your Weekly Fitness Tracker  *****\n";
    cout << "******************************************************\n";

    // Get fitness goals from user
    cout << "\n== Set Your Fitness Goals ==\n";
    setFitnessGoals(&goalSteps, &goalCalories, &goalWorkoutTime);

    // Collect data from the user
    cout << "\n== Enter Your Weekly Data ==\n";
    getData(steps, calories, workoutTime, waterIntake, sleepHours, days);

    // Display weekly summary
    cout << "\n== Weekly Summary ==\n";
    displaySummary(steps, calories, workoutTime, waterIntake, sleepHours, days);

    // Provide feedback based on goals
    cout << "\n== Feedback Based on Your Goals ==\n";
    provideFeedback(steps, calories, workoutTime, &goalSteps, &goalCalories, &goalWorkoutTime, days);

    // BMI Calculation
    double weight, height;
    cout << "\n== BMI Calculator ==\n";
    cout << "Enter your weight (in kg): ";
    cin >> weight;
    cout << "Enter your height (in meters): ";
    cin >> height;
    calculateBMI(weight, height);

    // Track sleep data
    cout << "\n== Sleep Tracker ==\n";
    trackSleep(sleepHours, days);

    // Compare progress
    cout << "\n== Weekly Progress Comparison ==\n";
    compareProgress(steps, calories, workoutTime, days);

    // Provide daily health tips
    cout << "\n== Daily Health Tips ==\n";
    dailyHealthTips(steps, calories, workoutTime, &goalSteps, &goalCalories, &goalWorkoutTime, days);

    // Display data for a specific day
    cout << "\n== View Data for a Specific Day ==\n";
    displayDataForSpecificDay(steps, calories, workoutTime, waterIntake, sleepHours, days);

    // Unlock achievements based on user progress
    cout << "\n== Achievements Unlocked ==\n";
    unlockAchievements(steps, calories, workoutTime, days);

    // Display motivational quotes to keep the user engaged
    cout << "\n== Motivational Quotes ==\n";
    motivationalQuotes();

    // Display progress in a simple bar chart format
    cout << "\n== Weekly Progress Graph ==\n";
    displayProgressGraph(steps, calories, days);

    // Generate and display a weekly report
    cout << "\n== Weekly Report ==\n";
    generateWeeklyReport(steps, calories, workoutTime, waterIntake, sleepHours, days);

    cout << "\n******************************************************\n";
    cout << "*****    Thank You for Using Fitness Tracker!    *****\n";
    cout << "******************************************************\n";

    return 0;
}

// Function to collect data from the user
void getData(int* steps, int* calories, int* workoutTime, int* waterIntake, int* sleepHours, int days) {
    for (int i = 0; i < days; i++) {
        cout << "\nDay " << i + 1 << " data:\n";
        cout << "Enter steps: ";
        cin >> *(steps + i);
        cout << "Enter calories burned: ";
        cin >> *(calories + i);
        cout << "Enter workout time in minutes: ";
        cin >> *(workoutTime + i);
        cout << "Enter water intake in liters: ";
        cin >> *(waterIntake + i);
        cout << "Enter sleep hours: ";
        cin >> *(sleepHours + i);
    }
}

// Function to display the summary of the week
void displaySummary(int* steps, int* calories, int* workoutTime, int* waterIntake, int* sleepHours, int days) {
    int totalSteps = 0, totalCalories = 0, totalTime = 0, totalWater = 0, totalSleep = 0;
    for (int i = 0; i < days; i++) {
        totalSteps += *(steps + i);
        totalCalories += *(calories + i);
        totalTime += *(workoutTime + i);
        totalWater += *(waterIntake + i);
        totalSleep += *(sleepHours + i);
    }
    
    cout << "\nWeekly Summary:\n";
    cout << "Total steps: " << totalSteps << endl;
    cout << "Total calories burned: " << totalCalories << endl;
    cout << "Total workout time: " << totalTime << " minutes" << endl;
    cout << "Total water intake: " << totalWater << " liters" << endl;
    cout << "Total sleep hours: " << totalSleep << " hours" << endl;
}

// Function to calculate BMI
void calculateBMI(double weight, double height) {
    double bmi = weight / (height * height);
    cout << "Your BMI is: " << bmi << endl;
    
    if (bmi < 18.5) {
        cout << "You are underweight.\n";
    } else if (bmi >= 18.5 && bmi <= 24.9) {
        cout << "You have a normal weight.\n";
    } else if (bmi >= 25 && bmi <= 29.9) {
        cout << "You are overweight.\n";
    } else {
        cout << "You are obese.\n";
    }
}

// Function to set daily fitness goals
void setFitnessGoals(int* goalSteps, int* goalCalories, int* goalWorkoutTime) {
    cout << "Enter your daily fitness goal for steps: ";
    cin >> *goalSteps;
    cout << "Enter your daily fitness goal for calories burned: ";
    cin >> *goalCalories;
    cout << "Enter your daily fitness goal for workout time (minutes): ";
    cin >> *goalWorkoutTime;
}

// Function to provide feedback based on user performance
void provideFeedback(int* steps, int* calories, int* workoutTime, int* goalSteps, int* goalCalories, int* goalWorkoutTime, int days) {
    for (int i = 0; i < days; i++) {
        cout << "Day " << i + 1 << " feedback:\n";
        
        if (*(steps + i) >= *goalSteps) {
            cout << "You met your step goal! Great job!\n";
        } else {
            cout << "You didn't meet your step goal. Try to walk more tomorrow.\n";
        }
        
        if (*(calories + i) >= *goalCalories) {
            cout << "You met your calorie-burning goal! Well done!\n";
        } else {
            cout << "You didn't meet your calorie-burning goal. Try to burn more calories tomorrow.\n";
        }
        
        if (*(workoutTime + i) >= *goalWorkoutTime) {
            cout << "You met your workout time goal! Keep it up!\n";
        } else {
            cout << "You didn't meet your workout time goal. Aim to exercise more next time.\n";
        }
    }
}

// Function to track sleep hours
void trackSleep(int* sleepHours, int days) {
    int totalSleep = 0;
    for (int i = 0; i < days; i++) {
        totalSleep += *(sleepHours + i);
    }
    cout << "\nTotal sleep hours for the week: " << totalSleep << " hours\n";
}

// Function to compare progress over the week
void compareProgress(int* steps, int* calories, int* workoutTime, int days) {
    for (int i = 1; i < days; i++) {
        cout << "Day " << i + 1 << " vs Day " << i << " progress:\n";
        cout << "Steps: " << *(steps + i) - *(steps + i - 1) << " steps\n";
        cout << "Calories burned: " << *(calories + i) - *(calories + i - 1) << " calories\n";
        cout << "Workout time: " << *(workoutTime + i) - *(workoutTime + i - 1) << " minutes\n";
    }
}

// Function to provide daily health tips
void dailyHealthTips(int* steps, int* calories, int* workoutTime, int* goalSteps, int* goalCalories, int* goalWorkoutTime, int days) {
    for (int i = 0; i < days; i++) {
        cout << "Health tip for Day " << i + 1 << ":\n";
        
        if (*(steps + i) < *goalSteps) {
            cout << "Try to walk more to meet your daily step goal.\n";
        }
        if (*(calories + i) < *goalCalories) {
            cout << "Try burning more calories with some cardio exercises.\n";
        }
        if (*(workoutTime + i) < *goalWorkoutTime) {
            cout << "Aim for a longer workout time today.\n";
        }
    }
}

// Function to display data for a specific day
void displayDataForSpecificDay(int* steps, int* calories, int* workoutTime, int* waterIntake, int* sleepHours, int days) {
    int day;
    cout << "Enter the day number (1-7) to view the data: ";
    cin >> day;
    
    if (day < 1 || day > 7) {
        cout << "Invalid day number.\n";
    } else {
        cout << "\nData for Day " << day << ":\n";
        cout << "Steps: " << *(steps + day - 1) << endl;
        cout << "Calories burned: " << *(calories + day - 1) << endl;
        cout << "Workout time: " << *(workoutTime + day - 1) << " minutes\n";
        cout << "Water intake: " << *(waterIntake + day - 1) << " liters\n";
        cout << "Sleep hours: " << *(sleepHours + day - 1) << " hours\n";
    }
}

// Function to unlock achievements based on user progress
void unlockAchievements(int* steps, int* calories, int* workoutTime, int days) {
    for (int i = 0; i < days; i++) {
        if (*(steps + i) >= 10000) {
            cout << "Achievement unlocked: 10,000 Steps in a Day! Great job!\n";
        }
        if (*(calories + i) >= 500) {
            cout << "Achievement unlocked: 500 Calories Burned in One Workout! Well done!\n";
        }
        if (*(workoutTime + i) >= 60) {
            cout << "Achievement unlocked: 1 Hour Workout! Keep it up!\n";
        }
    }
}

// Function to display motivational quotes
void motivationalQuotes() {
    string quotes[] = {
        "Keep pushing yourself, because no one else is going to do it for you.",
        "The only bad workout is the one that didn't happen.",
        "Your only limit is you.",
        "Don't stop when you're tired, stop when you're done."
    };
    
    int randomIndex = rand() % 4;
    cout << "\nMotivational Quote: " << quotes[randomIndex] << endl;
}

// Function to display progress as a simple bar chart
void displayProgressGraph(int* steps, int* calories, int days) {
    cout << "\nProgress Bar for Steps Taken (Week):\n";
    for (int i = 0; i < days; i++) {
        cout << "Day " << i + 1 << ": ";
        for (int j = 0; j < *(steps + i) / 1000; j++) {
            cout << "#";
        }
        cout << " (" << *(steps + i) << " steps)\n";
    }
}

// Function to generate a weekly report
void generateWeeklyReport(int* steps, int* calories, int* workoutTime, int* waterIntake, int* sleepHours, int days) {
    cout << "\nWeekly Report:\n";
    for (int i = 0; i < days; i++) {
        cout << "Day " << i + 1 << ":\n";
        cout << "Steps: " << *(steps + i) << " | Calories burned: " << *(calories + i) << " | Workout time: " << *(workoutTime + i) << " minutes\n";
        cout << "Water intake: " << *(waterIntake + i) << " liters | Sleep: " << *(sleepHours + i) << " hours\n";
    }
}
