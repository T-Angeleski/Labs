#include <iostream>
#include <cstring>
using namespace std;

class InvalidPassword {
    public:
        void message() {
            cout<<"Password is too weak.\n";
        }
};

class InvalidEmail {
    public:
        void message() {
            cout<<"Mail is not valid.\n";
        }
};

class MaximumSizeLimit {
    int n;
    public:
        MaximumSizeLimit(int n) {
            this->n = n;
        }

        void message() {
            cout<<"You can't add more than "<<n<<" users";
        }
};

class User {
protected:
    char username[50];
    char password[50];
    char email[50];

    void setPassword(char *password = "")
    {
        bool lowercase = false;
        bool uppercase = false;
        bool number = false;

        for (int i = 0; i < strlen(password); i++)
            if (isupper(password[i]))
                uppercase = true;
            else if (islower(password[i]))
                lowercase = true;
            else if (isdigit(password[i]))
                number = true;

        if (lowercase && uppercase && number)
            strcpy(this->password, password);
        else
            throw InvalidPassword("Password is too weak.");
    }

    void setEmail(char *email = "")
    {
        int counter = 0;

        for (int i = 0; i < strlen(email); i++)
            if (email[i] == '@')
                counter++;

        if (counter == 1)
            strcpy(this->email, email);
        else
            throw InvalidMail("Mail is not valid.");
    }

    public:
        User(char * username = "", char * password = " ", char * email = " ") {
            

            
            strcpy(this->username, username);
            setPassword(password);
            setEmail(email);
        }

        virtual double popularity() =0;
};

class FacebookUser : public User {
    int friends;
    int likes;
    int comments;
    static double LIKE_COEF;
    static double COMMENT_COEF;

    public:
        FacebookUser(char * username = "", char * password = " ", char * email = " ", int friends = 0 , int likes =0, int comments =0) : User(username, password, email) {
            this->friends = friends;
            this->likes = likes;
            this->comments = comments;
        }

        double popularity() {
            return friends + (likes * LIKE_COEF) + (comments * COMMENT_COEF);
        }
};

double FacebookUser::LIKE_COEF = 0.1;
double FacebookUser::COMMENT_COEF = 0.5;

class TwitterUser : public User {
    int followers;
    int tweets;
    static double TWEET_COEF;

    public:
        TwitterUser(char * username = "", char * password = " ", char * email = " ", int followers = 0, int tweets = 0) : User(username, password, email) {
            this->followers = followers;
            this->tweets = tweets;
        }

        double popularity() {
            return followers + tweets*TWEET_COEF;
        }
};

double TwitterUser::TWEET_COEF = 0.5;

class SocialNetwork {
    User ** users;
    int n;
    static int MAX_USERS;

    public:
        SocialNetwork() {
            n = 0;
            users = new User * [0];
        }

        /*SocialNetwork(const SocialNetwork & sn) {
            this->n = sn.n;
            this->users = new User * [sn.n];
            for(int i = 0 ; i < sn.n ; i++) {
                users[i] = sn.users[i];
            }
        }

        SocialNetwork& operator= (const SocialNetwork & sn) {
            if(this != &sn) {
                delete [] users;
                this->n = sn.n;
                this->users = new User * [sn.n];
                for(int i = 0 ; i < sn.n ; i++) {
                    users[i] = sn.users[i];
                }
            }
            return *this;
        }*/

        ~SocialNetwork() {
            delete [] users;
        }

        SocialNetwork& operator+= (User * u) {
            if(n == MAX_USERS) {
                throw MaximumSizeLimit(n);
            }
            
            User ** tmp = new User * [n+1];
            for(int i = 0 ; i < n ; i++) {
                tmp[i] = users[i];
            }
            tmp[n++] = u;
            delete [] users;
            users = tmp;
            return *this;
        }

        double avgPopularity() {
            double avg = 0;
            for(int i = 0 ; i < n ; i++) {
                avg += users[i]->popularity();
            }
            return avg / n;
        }

        static void changeMaximumSize(int number) {
            MAX_USERS = number;
        }
};

int SocialNetwork::MAX_USERS = 5;

int main() {

    SocialNetwork network = SocialNetwork();
    int n;
    cin >> n;
    char username[50];
    char password[50];
    char email[50];
    int userType;
    for (int i=0; i < n; ++i) {
      cin >> username;
      cin >> password;
      cin >> email;
      cin >> userType;
      if (userType == 1) {
        int friends;
        int likes;
        int comments;
        cin >> friends >> likes >> comments;
          
        // TODO: Try-catch
        try {
            User * u = new FacebookUser(username,password,email,friends,likes,comments);
            network += u;  
        }
        catch(InvalidPassword & e) {
            e.message();
        }
        catch (InvalidEmail & e) {
            e.message();
        }
        
        catch (MaximumSizeLimit & e) {
            e.message();
        }
            
    }
    else {
        int followers;
        int tweets;
        cin >> followers >> tweets;

        // TODO: Try-catch
        try {
            User * u= new TwitterUser(username,password,email,followers,tweets);
            network += u;
        } 
        catch(InvalidPassword & e) {
            e.message();
        } 
        catch (InvalidEmail & e) {
            e.message();
        }
        
        catch (MaximumSizeLimit & e) {
            e.message();
        }

    }

    }
    network.changeMaximumSize(6);
    cin >> username;
    cin >> password;
    cin >> email;
    int followers;
    int tweets;
    cin >> followers >> tweets;
    
    // TODO: Try-catch
    try {
        User * u= new TwitterUser(username,password,email,followers,tweets);
        network += u;
    }
    catch(InvalidPassword & e) {
        e.message();
    }
    catch (InvalidEmail & e) {
        e.message();
    }
    
    catch (MaximumSizeLimit & e) {
        e.message();
    }
    
    
    cout << network.avgPopularity();

}
