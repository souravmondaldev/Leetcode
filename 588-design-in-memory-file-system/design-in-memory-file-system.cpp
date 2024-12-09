class File {
    public:
        bool isFile = false;
        unordered_map<string, File*> files;
        string content = "";
};
class FileSystem {
private:
    File *root;
    const char SLASH_DELIMETER = '/';
    vector<string> split(string &path, char delimeter){
        vector<string> tokens;
        string token;
        stringstream ss(path);
        while(getline(ss, token, delimeter)){
            if(!token.empty())
                tokens.push_back(token);
        }

        return tokens;
    }
public:
    FileSystem() {
        root = new File();
    }
    
    vector<string> ls(string path) {
        File *node = root;
        vector<string> files;
        if(path != "/"){
            vector<string> dirs = split(path, SLASH_DELIMETER);
            for(string dir : dirs){
                node = node->files[dir];
            }
            if(node->isFile){
                return {dirs.back()};
            }
        }
        for(auto file : node->files){
            files.push_back(file.first);
        }
        sort(files.begin(), files.end());
        return files;
    }
    
    void mkdir(string path) {
        File *node = root;
        vector<string> dirs = split(path, SLASH_DELIMETER);
        for(string dir : dirs){
            if(node->files.find(dir) == node->files.end()){
                node->files[dir] = new File;
            }
            node = node->files[dir];
        }
    }
    
    void addContentToFile(string filePath, string content) {
        File *node = root;
        vector<string> dirs = split(filePath, SLASH_DELIMETER);
        for(int i = 0; i < dirs.size() - 1; i ++){
            node = node->files[dirs[i]];
        }
        if(!node->files.count(dirs.back())){
            node->files[dirs.back()] = new File;
        }
        node = node->files[dirs.back()];
        node->isFile = true;
        node->content += content;
    }
    
    string readContentFromFile(string filePath) {
        File *node = root;
        vector<string> dirs = split(filePath, SLASH_DELIMETER);
        for(int i = 0; i < dirs.size() - 1; i ++){
            node = node->files[dirs[i]];
        }
        return node->files[dirs.back()]->content;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */