#include <iostream>
#include <cstring>
using namespace std;

class NBAPlayer {
protected:
    char * name;
    char team[40];
    double points;
    double assists;
    double rebounds;

    void copy (const NBAPlayer & other) {
        this->name = new char [strlen(other.name)+1];
        strcpy(this->name, other.name);

        strcpy(this->team, other.team);
        this->points = other.points;
        this->assists = other.assists;
        this->rebounds = other.rebounds;
    }

    public:
        NBAPlayer(char * name= "" ,char * team= "", double points=0, double assists=0, double rebounds=0) {
            this->name = new char [strlen(name)+1];
            strcpy(this->name, name);

            strcpy(this->team, team);
            this->points = points;
            this->assists = assists;
            this->rebounds = rebounds;
        }

        NBAPlayer(const NBAPlayer & p) {
            copy(p);
        }

        NBAPlayer& operator= (const NBAPlayer & p) {
            if (this != &p) {
                delete [] name;
                copy(p);
            }
            return *this;
        }

        ~NBAPlayer() {
            delete [] name;
        }

        double rating() {
            double rating;

            rating = (points*0.45) + (assists * 0.30) + (rebounds * 0.25);

            return rating;
        }

        void print() {
            cout<<name<<" - "<<team<<endl;
            cout<<"Points: "<<points<<endl;
            cout<<"Assists: "<<assists<<endl;
            cout<<"Rebounds: "<<rebounds<<endl;
            cout<<"Rating: "<<rating()<<endl;
        }
};

class AllStarPlayer : public NBAPlayer {
    double allstarPoints;
    double allstarAssists;
    double allstarRebounds;

    public:
        AllStarPlayer() : NBAPlayer() {
            allstarPoints = 0;
            allstarAssists = 0;
            allstarRebounds = 0;
        }

        AllStarPlayer(NBAPlayer & player, double allstarPoints, double allstarAssists, double allstarRebounds) : NBAPlayer(player) {
            this->allstarPoints = allstarPoints;
            this->allstarAssists = allstarAssists;
            this->allstarRebounds = allstarRebounds;
        }

        AllStarPlayer(char * name,char * team, double points, double assists, double rebounds, double allstarPoints, double allstarAssists, double allstarRebounds) : NBAPlayer(name, team, points, assists, rebounds) {
            this->allstarPoints = allstarPoints;
            this->allstarAssists = allstarAssists;
            this->allstarRebounds = allstarRebounds;
        }

        AllStarPlayer(const AllStarPlayer & player) : NBAPlayer(player) {
            allstarPoints = player.allstarPoints;
            allstarAssists = player.allstarAssists;
            allstarRebounds = player.allstarRebounds;
        }

        AllStarPlayer& operator= (const AllStarPlayer & player) {
            if( this!= &player ) {
                name = new char[50];
                strcpy(name, player.name);
                strcpy(team, player.team);
                points = player.points;
                assists = player.assists;
                rebounds = player.rebounds;
                allstarPoints = player.allstarPoints;
                allstarAssists = player.allstarAssists;
                allstarRebounds = player.allstarRebounds;
            }
            return *this;
        }

        ~AllStarPlayer() {}

        double allStarRating() {
            double rating;

            rating = (allstarPoints*0.30) + (allstarAssists*0.40) + (allstarRebounds*0.30);

            return rating;
        }

        double rating() {
            double rating = NBAPlayer::rating();
            double ASR = allStarRating();

            return (rating + ASR) / 2;
        }

        void print() {
            NBAPlayer::print();
            cout<<"All Star Rating: "<<allStarRating()<<endl;
            cout<<"New Rating: "<<rating()<<endl;
        }

};

int main() {
    return 0;
}
