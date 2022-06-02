#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

class Image{
protected:
    char * picName;
    char * owner;
    int width;
    int height;

    /*void copy(const Image& i) {
        this->picName = new char [strlen(i.picName)+1];
        this->owner = new char [strlen(i.owner)+1];

        strcpy(this->picName, i.picName);
        strcpy(this->owner, i.owner);
        this->width = i.width;
        this->height = i.height;
    }*/

    /*void freeMem() {
        delete [] picName;
        delete [] owner;
    }*/

    public:
        Image(const char* picName = "untitled", const char* owner = "unknown", int width = 800, int height = 800) {
            this->picName = new char [256];
            this->owner = new char [256];

            strcpy(this->picName, picName);
            strcpy(this->owner, owner);
            this->width = width;
            this->height = height;
        }

        /*Image(const Image& i) {
            copy(i);
        }

        Image& operator= (const Image& i) {
            if(this != &i) {
                freeMem();
                copy(i);
            }
            return *this;
        }*/

        ~Image() {
            delete [] picName;
            delete [] owner;
        }

        virtual int fileSize(){
            return height * width * 3;
        }

        bool operator> (Image& i) {
            return fileSize() > i.fileSize();
        }

        friend ostream& operator<<(ostream& out, Image& i) {
            out<<i.picName<<" "<<i.owner<<" "<<i.fileSize()<<endl;
            return out;
        }
};

class TransparentImage : public Image {
protected:
    bool isTransparent;

    public:
        TransparentImage(const char* picName = "untitled", const char* owner = "unknown",
        int width = 800, int height = 800, bool isTransparent = true)
        : Image(picName, owner, width, height) {
            this->isTransparent = isTransparent;
        }

        int fileSize() {
            if (isTransparent)
                return width * height * 4;
            else
                return width * height + (width * height) / 8;
        }

        /*bool operator> (TransparentImage& ti) {
            return this->fileSize() > ti.fileSize();
        }

        friend ostream& operator<<(ostream& out, TransparentImage& i) {
            return out<<i<<endl;
        }*/
};

class Folder {
protected:
    char folderName[256];
    char folderOwner[50];
    Image * images[100];
    int num;

    /*void copy(const Folder& f) {
        strcpy(this->folderName, f.folderName);
        strcpy(this->folderOwner , f.folderOwner);
        num = f.num;
        for (int i = 0; i < f.num; i++){
            images[i] = f.images[i];
        }
        
    }*/

    public:
        Folder(const char* folderName = "",const char* folderOwner = "unknown") {
            strcpy(this->folderName, folderName);
            strcpy(this->folderOwner , folderOwner);
            num = 0;
        }

        /*Folder(const Folder& f) {
            copy(f);
        }

        Folder& operator= (const Folder& f) {
            if(this != &f) {
                delete [] images;
                copy(f);
            }
            return *this;
        }*/

        

        int folderSize() {
            int sum=0;
            for (int i = 0; i < num; i++){
                sum+= images[i]->fileSize();
            }
            return sum;
        }

        Image* getMaxFile() {
            int max=images[0]->fileSize();
            int maxIndex;

            for (int i = 0; i < num; i++){
                if(images[i]->fileSize() > max) {
                    max = images[i]->fileSize();
                    maxIndex = i;
                }
            }

            return images[maxIndex];
        }

        Folder& operator+= (Image & i) {
            images[num] = &i;
            num++;
            return *this;
        }

        friend ostream& operator<<(ostream& out, Folder& f) {
            out<<f.folderName<<" "<<f.folderOwner<<endl<<"--"<<endl;
            for (int i = 0; i < f.num; i++){
                out<<*f.images[i];
            }
            out<<"--"<<endl<<"Folder size: "<<f.folderSize()<<endl;
            return out;
        }

        Image* operator[] (int index) {
            if(index < 0 || index>=num)
                return NULL;
            else
                return images[index];
        }
};

Folder &max_folder_size(Folder *f, int n)
{
    double max = f[0].folderSize();
    int index = 0;

    for (int i = 0; i < n; ++i)
        if (max < f[i].folderSize())
        {
            max = f[i].folderSize();
            index = i;
        }

    return f[index];
}

int main() {

    int tc; // Test Case

    char name[255];
    char user_name[51];
    int w, h;
    bool tl;

    cin >> tc;

    if (tc==1){
      // Testing constructor(s) & operator << for class File

      cin >> name;
      cin >> user_name;
      cin >> w;
      cin >> h;


      Image f1;

      cout<< f1;

      Image f2(name);
      cout<< f2;

      Image f3(name, user_name);
      cout<< f3;

      Image f4(name, user_name, w, h);
      cout<< f4;
    }
    else if (tc==2){
      // Testing constructor(s) & operator << for class TextFile
      cin >> name;
      cin >> user_name;
      cin >> w >> h;
      cin >> tl;

      TransparentImage tf1;
      cout<< tf1;

      TransparentImage tf4(name, user_name, w, h, tl);
      cout<< tf4;
    }
    else if (tc==3){
      // Testing constructor(s) & operator << for class Folder
      cin >> name;
      cin >> user_name;

      Folder f3(name, user_name);
      cout<< f3;
    }
    else if (tc==4){
      // Adding files to folder
      cin >> name;
      cin >> user_name;

      Folder dir(name, user_name);

      Image * f;
      TransparentImage *tf;

      int sub, fileType;

      while (1){
        cin >> sub; // Should we add subfiles to this folder
        if (!sub) break;

        cin >>fileType;
        if (fileType == 1){ // Reading File
          cin >> name;
          cin >> user_name;
          cin >> w >> h;
          f = new Image(name,user_name, w, h);
            dir += *f;
        }
        else if (fileType == 2){
          cin >> name;
          cin >> user_name;
          cin >> w >> h;
          cin >> tl;
          tf = new TransparentImage(name,user_name, w, h, tl);
            dir += *tf;
        }
      }
      cout<<dir;
    }
    else if(tc==5){
      // Testing getMaxFile for folder

      cin >> name;
      cin >> user_name;

      Folder dir(name, user_name);

      Image* f;
      TransparentImage* tf;

      int sub, fileType;

      while (1){
        cin >> sub; // Should we add subfiles to this folder
        if (!sub) break;

        cin >>fileType;
        if (fileType == 1){ // Reading File
          cin >> name;
          cin >> user_name;
          cin >> w >> h;
          f = new Image(name,user_name, w, h);
            dir += *f;
        }
        else if (fileType == 2){
          cin >> name;
          cin >> user_name;
          cin >> w >> h;
          cin >> tl;
          tf = new TransparentImage(name,user_name, w, h, tl);
            dir += *tf;
        }
      }
      cout<< *(dir.getMaxFile());
    }
    else if(tc==6){
      // Testing operator [] for folder

      cin >> name;
      cin >> user_name;

      Folder dir(name, user_name);

      Image* f;
      TransparentImage* tf;

      int sub, fileType;

      while (1){
        cin >> sub; // Should we add subfiles to this folder
        if (!sub) break;

        cin >>fileType;
        if (fileType == 1){ // Reading File
          cin >> name;
          cin >> user_name;
          cin >> w >> h;
          f = new Image(name,user_name, w, h);
            dir += *f;
        }
        else if (fileType == 2){
          cin >> name;
          cin >> user_name;
          cin >> w >> h;
          cin >> tl;
          tf = new TransparentImage(name,user_name, w, h, tl);
            dir += *tf;
        }
      }

      cin >> sub; // Reading index of specific file
      cout<< *dir[sub];
    }
    else if(tc==7){
      // Testing function max_folder_size
      int folders_num;

      Folder dir_list[10];

      Folder dir;
      cin >> folders_num;

      for (int i=0; i<folders_num; ++i){
        cin >> name;
        cin >> user_name;
        dir = Folder(name, user_name);


        Image* f;
        TransparentImage *tf;

        int sub, fileType;

        while (1){
          cin >> sub; // Should we add subfiles to this folder
          if (!sub) break;

          cin >>fileType;
          if (fileType == 1){ // Reading File
            cin >> name;
            cin >> user_name;
            cin >> w >> h;
            f = new Image(name,user_name, w, h);
              dir += *f;
          }
          else if (fileType == 2){
            cin >> name;
            cin >> user_name;
            cin >> w >> h;
            cin >> tl;
            tf = new TransparentImage(name,user_name, w, h, tl);
              dir += *tf;
          }
        }
        dir_list[i] = dir;
      }

      cout<<max_folder_size(dir_list, folders_num);
    }
    return 0;
};
