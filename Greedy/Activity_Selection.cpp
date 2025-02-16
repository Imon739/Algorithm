#include<bits/stdc++.h>

using namespace std;

struct Activity {
    int start;
    int finish;
};

bool compare(const Activity& a, const Activity& b) {
    return a.finish < b.finish;
}

void activitySelection(const vector<Activity>& activities) {
    vector<Activity> selectedActivities;

    vector<Activity> sortedActivities = activities;
    sort(sortedActivities.begin(), sortedActivities.end(), compare);

    selectedActivities.push_back(sortedActivities[0]);

    for (int i = 1; i < sortedActivities.size(); ++i) {
        if (sortedActivities[i].start >= selectedActivities.back().finish) {
            selectedActivities.push_back(sortedActivities[i]);
        }
    }

    cout << "Selected activities are:" << endl;
    for (const Activity& activity : selectedActivities) {
        cout << "Start time: " << activity.start << ", Finish time: " << activity.finish << endl;
    }
}

int main() {
    vector<Activity> activities = {
        {1, 4}, {3, 5}, {0, 6}, {5, 7}, {3, 8}, {5, 9},
        {6, 10}, {8, 11}, {8, 12}, {2, 13}, {12, 14}
    };

    activitySelection(activities);

    return 0;
}

