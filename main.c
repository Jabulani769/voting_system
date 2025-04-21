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
int main(){
    
}
