#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int numberOfCandidates = 0;
    double totalVotes = 0;
    int winner = 0;
    int winnerIndex = 0;

    cout << "Enter the number of candidates for this election: ";
    cin >> numberOfCandidates;

    string* lastName = new string[numberOfCandidates];
    double* votes = new double[numberOfCandidates]{ 0 };
    double* percentOfTotal = new double[numberOfCandidates]{ 0 };
//---------------------------------------------------------------------------
    //enter candidate name followed by their vote count
    cout << "\nEnter the last name of a candidate and the number of votes they received: \n";
    for(int i = 0; i < numberOfCandidates; ++i) {
        cin >> lastName[i];
        cin >> votes[i];
        totalVotes += votes[i];
    }
    cout << endl;
//---------------------------------------------------------------------------
    //determine who received the most votes
    winner = votes[0];
    for(int i = 1; i < numberOfCandidates; ++i) {
        if(votes[i] > winner) {
            winner = votes[i];
            winnerIndex = i;
        }
    }
//---------------------------------------------------------------------------
    //calculate percentage of votes won by each candidate
    for(int i = 0; i < numberOfCandidates; ++i) {
        percentOfTotal[i] = (votes[i] / totalVotes);
        percentOfTotal[i] *= 100;
    }
//---------------------------------------------------------------------------
    //output name of candidate followed by their vote count and percentage of votes won
    //followed by the winner of the election
    cout << left << setw(15) << "Candidate" << setw(19) << "Votes Received" << "% of Total Votes\n\n";

    for(int i = 0; i < numberOfCandidates; ++i) {
        cout << left << setw(15) << lastName[i] << setw(19) << fixed << setprecision(0) << votes[i];
        cout << fixed << setprecision(2) << percentOfTotal[i] << endl;
    }
    cout << left << setw(15) << fixed << setprecision(0) << "Total " << setw(19) << totalVotes;

    cout << endl << endl;
    cout << "The Winner of the Election is " << lastName[winnerIndex] << endl;
//---------------------------------------------------------------------------
    cout << "\nCode by Jacob Smetana\n";
    return 0;
}
