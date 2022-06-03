#include <iostream>
#include <cstring>

using namespace std;

class ExistingGame{
    char msg[100];
    public:
        ExistingGame(char* msg = ""){
            strcpy(this->msg, msg);
        }

        void message() {
            cout<<msg<<endl;
        }
};

class Game{
protected:
    char imeIgra[100];
    double cenaIgra;
    bool kupenaSale;

    public:
        Game(const char* imeIgra = "", double cenaIgra = 0, bool kupenaSale = false) {
            strcpy(this->imeIgra, imeIgra);
            this->cenaIgra = cenaIgra;
            this->kupenaSale = kupenaSale;
        }

        bool operator== (Game& g) {
            return !strcmp(imeIgra, g.imeIgra);
        }
        friend ostream& operator<<(ostream& out, Game& g);
        friend istream& operator>>(istream& in, Game& g);

        double getCena() {
            return cenaIgra;
        }

        bool getSale() {
            return kupenaSale;
        }
};



class SubscriptionGame : public Game {
    double mesecenNadomestok;
    int mesec;
    int godina;

    public:
        SubscriptionGame(const char* imeIgra = "", double cenaIgra = 0, bool kupenaSale = false,
        double mesecenNadomestok=0, int mesec=0, int godina=0) :Game(imeIgra, cenaIgra, kupenaSale) {
            this->mesecenNadomestok = mesecenNadomestok;
            this->mesec = mesec;
            this->godina = godina;
        }

        friend ostream& operator<<(ostream& out, SubscriptionGame& sg);
        friend istream& operator>>(istream& in, SubscriptionGame& sg);
};

class User {
    char username[100];
    Game ** games;
    int num;

    void copy(const User& u) {
        strcpy(this->username, u.username);
        num = u.num;
        games = new Game* [u.num];
        for(int i = 0 ; i < u.num ; i++) {
            games[i] = u.games[i];
        }
    }

    public:
        User(const char* username ="") {
            strcpy(this->username, username);
            num = 0;
            games = new Game* [0];
        }

        User(const User& u) {
            copy(u);
        }

        User& operator= (const User& u) {
            if(this != &u) {
                delete [] games;
                copy(u);
            }
            return *this;
        }

        User& operator+=(Game * g) {
            for(int i = 0 ; i < num ; i++) {
                if(*games[i] == g)
                    throw ExistingGame("The game is already in the collection");
            }

            Game ** tmp = new Game* [num+1];
            for(int i = 0 ; i < num ; i++)
                tmp[i] = games[i];
            tmp[num++] = g;
            delete [] games;
            games = tmp;
            return *this;
        }

        double total_spent() {
            double total=0;
            for(int i = 0 ; i < num ; i++) {
                if(games[i]->getSale()) {
                    total += games[i]->getCena() * 0.7f;
                } else {
                    total += games[i]->getCena();
                }
            }
        }

};

ostream& operator<<(ostream& out, Game& g) {
    out<<"Game: "<<g.imeIgra<<", regular price: $"<<g.cenaIgra;
        if(g.kupenaSale)
            out<<", bought on sale";
        out<<endl;
    return out;
}

istream& operator>>(istream& in, Game& g) {
    return in>>g.imeIgra>>g.cenaIgra>>g.kupenaSale;
}

ostream& operator<<(ostream& out, SubscriptionGame& sg) {
    out<<"Game: "<<sg.imeIgra<<", regular price: $"<<sg.cenaIgra;
    out<<", monthly fee: $"<<sg.mesecenNadomestok<<", purchased: "<<sg.mesec<<"-"<<sg.godina<<endl;
    return out;
}


istream& operator>>(istream& in, SubscriptionGame& sg) {
    in>>sg.imeIgra>>sg.cenaIgra>>sg.kupenaSale;
    in>>sg.mesecenNadomestok>>sg.mesec>>sg.godina;
    return in;
}

int main() {
  int test_case_num;

  cin>>test_case_num;

  // for Game
  char game_name[100];
  float game_price;
  bool game_on_sale;

  // for SubscritionGame
  float sub_game_monthly_fee;
  int sub_game_month, sub_game_year;

  // for User
  char username[100];
  int num_user_games;

  if (test_case_num == 1){
    cout<<"Testing class Game and operator<< for Game"<<std::endl;
    cin.get();
    cin.getline(game_name,100);
    //cin.get();
    cin>>game_price>>game_on_sale;

    Game g(game_name, game_price, game_on_sale);

    cout<<g;
  }
  else if (test_case_num == 2){
    cout<<"Testing class SubscriptionGame and operator<< for SubscritionGame"<<std::endl;
    cin.get();
    cin.getline(game_name, 100);

    cin>>game_price>>game_on_sale;

    cin>>sub_game_monthly_fee;
    cin>>sub_game_month>>sub_game_year;

    SubscriptionGame sg(game_name, game_price, game_on_sale, sub_game_monthly_fee, sub_game_month, sub_game_year);
    cout<<sg;
  }
  else if (test_case_num == 3){
    cout<<"Testing operator>> for Game"<<std::endl;
    Game g;

    cin>>g;

    cout<<g;
  }
  else if (test_case_num == 4){
    cout<<"Testing operator>> for SubscriptionGame"<<std::endl;
    SubscriptionGame sg;

    cin>>sg;

    cout<<sg;
  }
  else if (test_case_num == 5){
    cout<<"Testing class User and operator+= for User"<<std::endl;
    cin.get();
    cin.getline(username,100);
    User u(username);

    int num_user_games;
    int game_type;
    cin >>num_user_games;

    try {

      for (int i=0; i<num_user_games; ++i){

        cin >> game_type;

        Game *g;
        // 1 - Game, 2 - SubscriptionGame
        if (game_type == 1){
          cin.get();
          cin.getline(game_name, 100);

          cin>>game_price>>game_on_sale;
          g = new Game(game_name, game_price, game_on_sale);
        }
        else if (game_type == 2){
          cin.get();
          cin.getline(game_name, 100);

          cin>>game_price>>game_on_sale;

          cin>>sub_game_monthly_fee;
          cin>>sub_game_month>>sub_game_year;
          g = new SubscriptionGame(game_name, game_price, game_on_sale, sub_game_monthly_fee, sub_game_month, sub_game_year);
        }

        //cout<<(*g);


        u+=(*g);
      }
    }catch(ExistingGame &ex){
      ex.message();
    }

    cout<<u;

//    cout<<"\nUser: "<<u.get_username()<<"\n";

//    for (int i=0; i < u.get_games_number(); ++i){
//        Game * g;
//        SubscriptionGame * sg;
//        g = &(u.get_game(i));

//        sg = dynamic_cast<SubscriptionGame *> (g);

//        if (sg){
//          cout<<"- "<<(*sg);
//        }
//        else {
//          cout<<"- "<<(*g);
//        }
//        cout<<"\n";
//    }

  }
  else if (test_case_num == 6){
      cout<<"Testing exception ExistingGame for User"<<std::endl;
      cin.get();
      cin.getline(username,100);
      User u(username);

      int num_user_games;
      int game_type;
      cin >>num_user_games;

      for (int i=0; i<num_user_games; ++i){

          cin >> game_type;

          Game *g;
          // 1 - Game, 2 - SubscriptionGame
          if (game_type == 1){
            cin.get();
            cin.getline(game_name, 100);

            cin>>game_price>>game_on_sale;
            g = new Game(game_name, game_price, game_on_sale);
          }
          else if (game_type == 2){
            cin.get();
            cin.getline(game_name, 100);

            cin>>game_price>>game_on_sale;

            cin>>sub_game_monthly_fee;
            cin>>sub_game_month>>sub_game_year;
            g = new SubscriptionGame(game_name, game_price, game_on_sale, sub_game_monthly_fee, sub_game_month, sub_game_year);
          }

          //cout<<(*g);

          try {
            u+=(*g);
          }
          catch(ExistingGame &ex){
            ex.message();
          }
        }

      cout<<u;

//      for (int i=0; i < u.get_games_number(); ++i){
//          Game * g;
//          SubscriptionGame * sg;
//          g = &(u.get_game(i));

//          sg = dynamic_cast<SubscriptionGame *> (g);

//          if (sg){
//            cout<<"- "<<(*sg);
//          }
//          else {
//            cout<<"- "<<(*g);
//          }
//          cout<<"\n";
//      }
  }
  else if (test_case_num == 7){
      cout<<"Testing total_spent method() for User"<<std::endl;
      cin.get();
      cin.getline(username,100);
      User u(username);

      int num_user_games;
      int game_type;
      cin >>num_user_games;

      for (int i=0; i<num_user_games; ++i){

          cin >> game_type;

          Game *g;
          // 1 - Game, 2 - SubscriptionGame
          if (game_type == 1){
            cin.get();
            cin.getline(game_name, 100);

            cin>>game_price>>game_on_sale;
            g = new Game(game_name, game_price, game_on_sale);
          }
          else if (game_type == 2){
            cin.get();
            cin.getline(game_name, 100);

            cin>>game_price>>game_on_sale;

            cin>>sub_game_monthly_fee;
            cin>>sub_game_month>>sub_game_year;
            g = new SubscriptionGame(game_name, game_price, game_on_sale, sub_game_monthly_fee, sub_game_month, sub_game_year);
          }

          //cout<<(*g);


          u+=(*g);
        }

      cout<<u;

      cout<<"Total money spent: $"<<u.total_spent()<<endl;
  }
}