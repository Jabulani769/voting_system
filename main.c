#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VOTER_REG_FILE "voterReg.txt"
#define CANDIDATE_REG_FILE "candidateReg.txt"
#define CANDIDATE VOTES_FILE "candidateVotes.txt"
#define VOTED_ALREADY_FILE "votedAlready.txt"

// Function prototypes
void adminPortal();
void voterPortal();
void registerVoter();
void registerCandidate();
void viewVoteGraph();
int isVoterRegistered(char *voterId);
int hasVoted(char *voterId);
void saveVote(char *voterId, char *candidateId);
void loadCandidates(Candidate candidates[], int *count);
void saveCandidates(Candidate candidates[], int count);
void loadVotes(Candidate candidates[], int count);
void saveVotes(Candidate candidates[], int count);

// struct to hold candidate information
typedef struct {
    char name[50];
    char id[10];
    char position[50];
    int votes;
} Candidate;

// Admin Portal
void adminPortal(){
    char code[10];
    printf("\n===================================================\n");
    printf("Enter admin code: ");
    scanf("%s", code);

    if (strcmp(code, "nname") != 0) {
        printf(">>> Invalid admin code.\n");
        return;
    }

    int choice;
    while (1){
        printf("\n===================================================\n");
        printf(">>> Welcome, Admin Portal <<<");
        printf("\n===================================================\n");
        printf("1. Register Voter\n");
        printf("2. Register Candidate\n");
        printf("3. View Vote Graph\n");;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice == 00){
            printf("\n>>> Exit Granted.\n");
            main();
        }

        switch (choice) {
            case 1:
                registerVoter();
                break;
            case 2:
                registerCandidate();
                break;
            case 3:
                viewVoteGraph();
                break;
            default:
                printf(">>> Invalid choice. Please try again.\n");
        }
    }    
}

// Register Voter
void registerVoter() {
    char voterId[10];
    char voterName[50];

    printf("\n===================================================");
    printf("\n>>>> ENTER VOTER REGISTRATION DETAILS <<<<\n");
    printf("===================================================\n");
    printf("Enter voter name: ");
    scanf(" %[^\n]", voterName); // Read the full name (including spaces)

    printf("Enter voter ID: ");
    scanf("%s", voterId);

    FILE *file = fopen(VOTER_REG_FILE, "a");
    if (file == NULL) {
        printf(">>> ERROR: Failed to open file.\n");
        return;
    }

    // Write voter ID and name to the file
    fprintf(file, "%s\n%s\n\n", voterName, voterId); // Add a blank line after each voter
    fclose(file);

    printf(">>> Voter registered successfully.\n");
}

// Register Candidate
void registerCandidate() {
    Candidate candidate;

    printf("\n===================================================\n");
    printf(">>> Enter Candidate Details <<<\n");
    printf("===================================================\n");
    printf("Enter candidate name: ");
    scanf(" %[^\n]", candidate.name);
    printf("Enter candidate ID: ");
    scanf("%s", candidate.id);
    printf("Enter candidate position: ");
    scanf(" %[^\n]", candidate.position);
    candidate.votes = 0;

    FILE *file = fopen(CANDIDATE_REG_FILE, "a");
    if (file == NULL) {
        printf(">>> ERROR: Failed to open file.\n");
        return;
    }

    fprintf(file, "%s,%s,%s,%d\n", candidate.name, candidate.id, candidate.position, candidate.votes);
    fclose(file);
    printf(">>> Candidate registered successfully.\n");
}

// View Vote Graph
void viewVoteGraph() {
    Candidate candidates[50];
    int candidateCount;
    loadCandidates(candidates, &candidateCount);
    loadVotes(candidates, candidateCount);

    printf("\n===================================================");
    printf("\n>>> Viewing Voting Results <<<\n");
    printf("===================================================\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("%s |", candidates[i].name);
        for (int j = 0; j < candidates[i].votes; j++) {
            printf("#");
        }
        printf(" %d\n", candidates[i].votes);
    }
}

// Voter Portal
void voterPortal() {
    char voterId[10];

    printf("\n===================================================\n");
    printf("Enter your voter ID: ");
    scanf("%s", voterId);

    if (!isVoterRegistered(voterId)) {
        printf(">>> ERROR: You are not registered to vote.\n");
        return;
    }

    if (hasVoted(voterId)) {
        printf(">>> ERROR: You have already voted.\n");
        return;
    }

    Candidate candidates[50];
    int candidateCount;
    loadCandidates(candidates, &candidateCount);
    loadVotes(candidates, candidateCount);

        // Assigning unique position identifiers to candidates according to their positions
        char positions[50][50];
        int positionCount = 0;
        for (int i = 0; i < candidateCount; i++) {
            int isNew = 1;
            for (int j = 0; j < positionCount; j++) {
                if (strcmp(candidates[i].position, positions[j]) == 0) {
                    isNew = 0;
                    break;
                }
            }
            if (isNew) {
                strcpy(positions[positionCount], candidates[i].position);
                positionCount++;
            }
        }

        // Displays Role being voted for loops according to number of positions
        for (int i = 0; i < positionCount; i++) {
        printf("\n===================================================");
        printf("\n>>> Voting for %s\n", positions[i]);
        printf("===================================================\n");
        // Show candidates for the current position
        for (int j = 0; j < candidateCount; j++) {
            if (strcmp(candidates[j].position, positions[i]) == 0) {
                printf("%s - %s (%s)\n", candidates[j].name, candidates[j].id, candidates[j].position);
            }
        }

        // Allow voter to choose a candidate
        char candidateId[10];
        printf("\n>>> Enter the ID of the candidate: ");
        scanf("%s", candidateId);
        
        // Save the vote
        saveVote(voterId, candidateId);
            
        
        printf("\n===================================================");
        printf("\n>>> Thank you for voting!\n");
        printf("==================================================\n");
    }
}

int main(){
    
}
