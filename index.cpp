#include <iostream>
using namespace std;

const int MAX_CANDIDATES = 100;
const int MAX_USERS = 100;

string candidateNames[MAX_CANDIDATES];
int candidateVotes[MAX_CANDIDATES];
string votedUsers[MAX_USERS];

int candidateCount = 0;
int voterCount = 0;

// Check if user has already voted
bool hasVoted(string username) {
    for (int i = 0; i < voterCount; i++) {
        if (votedUsers[i] == username) return true;
    }
    return false;
}

// Mark user as voted
void markVoted(string username) {
    votedUsers[voterCount++] = username;
}

// Admin Panel
void adminPanel() {
    int choice;
    while (true) {
        cout << "\n--- Admin Panel ---\n";
        cout << "1. Add Candidate\n";
        cout << "2. View Candidates\n";
        cout << "3. Show Results\n";
        cout << "4. Exit Admin Panel\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            if (candidateCount >= MAX_CANDIDATES) {
                cout << "Maximum number of candidates reached.\n";
                continue;
            }
            cout << "Enter candidate name: ";
            getline(cin, candidateNames[candidateCount]);
            candidateVotes[candidateCount] = 0;
            candidateCount++;
            cout << "Candidate added successfully.\n";
        }
        else if (choice == 2) {
            cout << "\n--- Candidate List ---\n";
            for (int i = 0; i < candidateCount; i++) {
                cout << i + 1 << ". " << candidateNames[i] << endl;
            }
        }
        else if (choice == 3) {
            cout << "\n--- Voting Results ---\n";
            for (int i = 0; i < candidateCount; i++) {
                cout << candidateNames[i] << ": " << candidateVotes[i] << " vote(s)\n";
            }
        }
        else if (choice == 4) {
            break;
        }
        else {
            cout << "Invalid choice. Try again.\n";
        }
    }
}

// Voter Panel
void voterPanel() {
    string username;
    cout << "Enter your name: ";
    cin.ignore();
    getline(cin, username);

    if (hasVoted(username)) {
        cout << "You have already voted!\n";
        return;
    }

    if (candidateCount == 0) {
        cout << "No candidates available for voting.\n";
        return;
    }

    cout << "\n--- Candidates ---\n";
    for (int i = 0; i < candidateCount; i++) {
        cout << i + 1 << ". " << candidateNames[i] << endl;
    }

    int vote;
    cout << "Enter the number of the candidate you want to vote for: ";
    cin >> vote;

    if (vote < 1 || vote > candidateCount) {
        cout << "Invalid choice.\n";
        return;
    }

    candidateVotes[vote - 1]++;
    markVoted(username);
    cout << "Thank you for voting!\n";
}

// Main Menu
int main() {
    int choice;
    while (true) {
        cout << "\n===== Online Voting System =====\n";
        cout << "1. Admin Panel\n";
        cout << "2. Voter Panel\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            adminPanel();
        }
        else if (choice == 2) {
            voterPanel();
        }
        else if (choice == 3) {
            cout << "Thank you for using the voting system!\n";
            break;
        }
        else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
